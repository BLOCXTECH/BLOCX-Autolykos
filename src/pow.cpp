// Copyright (c) 2009-2010 Satoshi Nakamoto
// Copyright (c) 2009-2015 The Bitcoin Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include <pow.h>

#include <arith_uint256.h>
#include <autolykos/src/AutolykosPowScheme.h>
#include <autolykos/src/ChainSettings.h>
#include <autolykos/src/DifficultyAdjustment.h>
#include <autolykos/src/Header.h>
#include <chain.h>
#include <primitives/block.h>
#include <primitives/block.cpp>
#include <rpc/mining.cpp>
#include <uint256.h>
#include <validation.h>

#include <math.h>

unsigned int cpp_int_to_unsigned_int(const boost::multiprecision::cpp_int& value) {
    if (value < 0) {
        throw std::overflow_error("Cannot convert negative value to unsigned int");
    }
    
    if (value > std::numeric_limits<unsigned int>::max()) {
        throw std::overflow_error("Value too large for unsigned int");
    }
    
    return static_cast<unsigned int>(value.convert_to<unsigned long long>());
}

unsigned int static KimotoGravityWell(const CBlockIndex* pindexLast, const Consensus::Params& params) {
    const CBlockIndex *BlockLastSolved = pindexLast;
    const CBlockIndex *BlockReading = pindexLast;
    uint64_t PastBlocksMass = 0;
    int64_t PastRateActualSeconds = 0;
    int64_t PastRateTargetSeconds = 0;
    double PastRateAdjustmentRatio = double(1);
    arith_uint256 PastDifficultyAverage;
    arith_uint256 PastDifficultyAveragePrev;
    double EventHorizonDeviation;
    double EventHorizonDeviationFast;
    double EventHorizonDeviationSlow;

    uint64_t pastSecondsMin = params.nPowTargetTimespan * 0.025;
    uint64_t pastSecondsMax = params.nPowTargetTimespan * 7;
    uint64_t PastBlocksMin = pastSecondsMin / params.nPowTargetSpacing;
    uint64_t PastBlocksMax = pastSecondsMax / params.nPowTargetSpacing;

    if (BlockLastSolved == nullptr || BlockLastSolved->nHeight == 0 || (uint64_t)BlockLastSolved->nHeight < PastBlocksMin) { return UintToArith256(params.powLimit).GetCompact(); }

    for (unsigned int i = 1; BlockReading && BlockReading->nHeight > 0; i++) {
        if (PastBlocksMax > 0 && i > PastBlocksMax) { break; }
        PastBlocksMass++;

        PastDifficultyAverage.SetCompact(BlockReading->nBits);
        if (i > 1) {
            // handle negative arith_uint256
            if(PastDifficultyAverage >= PastDifficultyAveragePrev)
                PastDifficultyAverage = ((PastDifficultyAverage - PastDifficultyAveragePrev) / i) + PastDifficultyAveragePrev;
            else
                PastDifficultyAverage = PastDifficultyAveragePrev - ((PastDifficultyAveragePrev - PastDifficultyAverage) / i);
        }
        PastDifficultyAveragePrev = PastDifficultyAverage;

        PastRateActualSeconds = BlockLastSolved->GetBlockTime() - BlockReading->GetBlockTime();
        PastRateTargetSeconds = params.nPowTargetSpacing * PastBlocksMass;
        PastRateAdjustmentRatio = double(1);
        if (PastRateActualSeconds < 0) { PastRateActualSeconds = 0; }
        if (PastRateActualSeconds != 0 && PastRateTargetSeconds != 0) {
            PastRateAdjustmentRatio = double(PastRateTargetSeconds) / double(PastRateActualSeconds);
        }
        EventHorizonDeviation = 1 + (0.7084 * pow((double(PastBlocksMass)/double(28.2)), -1.228));
        EventHorizonDeviationFast = EventHorizonDeviation;
        EventHorizonDeviationSlow = 1 / EventHorizonDeviation;

        if (PastBlocksMass >= PastBlocksMin) {
                if ((PastRateAdjustmentRatio <= EventHorizonDeviationSlow) || (PastRateAdjustmentRatio >= EventHorizonDeviationFast))
                { assert(BlockReading); break; }
        }
        if (BlockReading->pprev == nullptr) { assert(BlockReading); break; }
        BlockReading = BlockReading->pprev;
    }

    arith_uint256 bnNew(PastDifficultyAverage);
    if (PastRateActualSeconds != 0 && PastRateTargetSeconds != 0) {
        bnNew *= PastRateActualSeconds;
        bnNew /= PastRateTargetSeconds;
    }

    if (bnNew > UintToArith256(params.powLimit)) {
        bnNew = UintToArith256(params.powLimit);
    }

    return bnNew.GetCompact();
}

unsigned int GetDecodedValue(uint32_t nBits) {
    auto b = encodeCompactBits(nBits);
    boost::multiprecision::cpp_int values = decodeCompactBits(b);
    unsigned int abc = cpp_int_to_unsigned_int(values);
    return abc;
}

unsigned int static DarkGravityWave(const CBlockIndex* pindexLast, const Consensus::Params& params) {
    /* current difficulty formula, blocx_testnet - DarkGravity v3, written by Evan Duffield - evan@blocx_testnet.org */
    const arith_uint256 bnPowLimit = UintToArith256(params.powLimit);
    int64_t nPastBlocks = 24;

    if(pindexLast->nHeight == 264782) {
        return bnPowLimit.GetCompact();
    }

    if (pindexLast->nHeight <= params.AutolykosForkHeight + 5) {
        return encodeCompactBits(0xa);
    }

    // make sure we have at least (nPastBlocks + 1) blocks, otherwise just return powLimit
    if (!pindexLast || pindexLast->nHeight < nPastBlocks) {
        return bnPowLimit.GetCompact();
    }

    const CBlockIndex *pindex = pindexLast;
    arith_uint256 bnPastTargetAvg;

    for (unsigned int nCountBlocks = 1; nCountBlocks <= nPastBlocks; nCountBlocks++) {
        arith_uint256 bnTarget = arith_uint256().SetCompact(pindex->nBits);
        if (nCountBlocks == 1) {
            bnPastTargetAvg = bnTarget;
        } else {
            // NOTE: that's not an average really...
            bnPastTargetAvg = (bnPastTargetAvg * nCountBlocks + bnTarget) / (nCountBlocks + 1);
        }

        if(nCountBlocks != nPastBlocks) {
            assert(pindex->pprev); // should never fail
            pindex = pindex->pprev;
        }
    }

    arith_uint256 bnNew(bnPastTargetAvg);

    int64_t nActualTimespan = pindexLast->GetBlockTime() - pindex->GetBlockTime();
    // NOTE: is this accurate? nActualTimespan counts it for (nPastBlocks - 1) blocks only...
    int64_t blockTime = params.GetCurrentPowTargetSpacing(pindexLast->nHeight + 1);

    int64_t nTargetTimespan = nPastBlocks * blockTime;

    if (nActualTimespan < nTargetTimespan/3)
        nActualTimespan = nTargetTimespan/3;
    if (nActualTimespan > nTargetTimespan*3)
        nActualTimespan = nTargetTimespan*3;

    // Retarget
    // LogPrintf("................. nActualTimespan=%d,  nTargetTimespan=%d................\n", nActualTimespan, nTargetTimespan);
    bnNew *= nActualTimespan;
    bnNew /= nTargetTimespan;

    if (bnNew > bnPowLimit) {
        bnNew = bnPowLimit;
    }

    if (pindexLast->nVersion >= 5 || pindexLast->nHeight + 1 >= params.AutolykosForkHeight) {
        boost::multiprecision::cpp_int values = decodeCompactBits(
            encodeCompactBits(bnNew.GetCompact())
        );
        unsigned int abc = cpp_int_to_unsigned_int(values);
        return abc;
    }

    return bnNew.GetCompact();
}

unsigned int GetNextWorkRequiredBTC(const CBlockIndex* pindexLast, const CBlockHeader *pblock, const Consensus::Params& params)
{
    assert(pindexLast != nullptr);
    unsigned int nProofOfWorkLimit = UintToArith256(params.powLimit).GetCompact();

    // Only change once per interval
    if ((pindexLast->nHeight+1) % params.DifficultyAdjustmentInterval() != 0)
    {
        if (params.fPowAllowMinDifficultyBlocks)
        {
            // Special difficulty rule for testnet:
            // If the new block's timestamp is more than 2* 2.5 minutes
            // then allow mining of a min-difficulty block.
            if (pblock->GetBlockTime() > pindexLast->GetBlockTime() + params.nPowTargetSpacing*2)
                return nProofOfWorkLimit;
            else
            {
                // Return the last non-special-min-difficulty-rules-block
                const CBlockIndex* pindex = pindexLast;
                while (pindex->pprev && pindex->nHeight % params.DifficultyAdjustmentInterval() != 0 && pindex->nBits == nProofOfWorkLimit)
                    pindex = pindex->pprev;
                return pindex->nBits;
            }
        }
        return pindexLast->nBits;
    }

    // Go back by what we want to be 1 day worth of blocks
    int nHeightFirst = pindexLast->nHeight - (params.DifficultyAdjustmentInterval()-1);
    assert(nHeightFirst >= 0);
    const CBlockIndex* pindexFirst = pindexLast->GetAncestor(nHeightFirst);
    assert(pindexFirst);

   return CalculateNextWorkRequired(pindexLast, pindexFirst->GetBlockTime(), params);
}

unsigned int GetNextWorkRequired(const CBlockIndex* pindexLast, const CBlockHeader *pblock, const Consensus::Params& params)
{
    assert(pindexLast != nullptr);
    assert(pblock != nullptr);
    const arith_uint256 bnPowLimit = UintToArith256(params.powLimit);

    // this is only active on devnets
    if (pindexLast->nHeight < params.nMinimumDifficultyBlocks) {
        return bnPowLimit.GetCompact();
    }

    if (pindexLast->nHeight + 1 < params.nPowKGWHeight) {
        return GetNextWorkRequiredBTC(pindexLast, pblock, params);
    }

    // Note: GetNextWorkRequiredBTC has it's own special difficulty rule,
    // so we only apply this to post-BTC algos.
    if (params.fPowNoRetargeting) {
        return bnPowLimit.GetCompact();
    }

    if (params.fPowAllowMinDifficultyBlocks) {
        // recent block is more than 2 hours old
        if (pblock->GetBlockTime() > pindexLast->GetBlockTime() + 2 * 60 * 60) {
            return bnPowLimit.GetCompact();
        }
        // recent block is more than 10 minutes old
        int64_t blockTime = params.GetCurrentPowTargetSpacing(pindexLast->nHeight + 1);
        if (pblock->GetBlockTime() > pindexLast->GetBlockTime() + blockTime * 4) {
            arith_uint256 bnNew = arith_uint256().SetCompact(pindexLast->nBits) * 10;
            if (bnNew > bnPowLimit) {
                return bnPowLimit.GetCompact();
            }
            return bnNew.GetCompact();
        }
    }

    // if (pindexLast->nVersion >= 5 || pindexLast->nHeight > params.AutolykosForkHeight) {
    //     return DarkGravityWave(pindexLast, params);
    // }

    if (pindexLast->nHeight + 1 < params.nPowDGWHeight) {
        return KimotoGravityWell(pindexLast, params);
    }

    return DarkGravityWave(pindexLast, params);
}

// for DIFF_BTC only!
unsigned int CalculateNextWorkRequired(const CBlockIndex* pindexLast, int64_t nFirstBlockTime, const Consensus::Params& params)
{
    if (params.fPowNoRetargeting)
        return pindexLast->nBits;

    // Limit adjustment step
    int64_t nActualTimespan = pindexLast->GetBlockTime() - nFirstBlockTime;
    if (nActualTimespan < params.nPowTargetTimespan/4)
        nActualTimespan = params.nPowTargetTimespan/4;
    if (nActualTimespan > params.nPowTargetTimespan*4)
        nActualTimespan = params.nPowTargetTimespan*4;

    // Retarget
    const arith_uint256 bnPowLimit = UintToArith256(params.powLimit);
    arith_uint256 bnNew;
    bnNew.SetCompact(pindexLast->nBits);
    bnNew *= nActualTimespan;
    bnNew /= params.nPowTargetTimespan;

    if (bnNew > bnPowLimit)
        bnNew = bnPowLimit;

    return bnNew.GetCompact();
}

bool CheckProofOfWork(const CBlockHeader& b_h, uint256 hash, unsigned int nBits, const Consensus::Params& params)
{
    // currently just returning HashX11 here
    if (b_h.nVersion != 0x05) {
        bool fNegative;
        bool fOverflow;
        arith_uint256 bnTarget;

        bnTarget.SetCompact(nBits, &fNegative, &fOverflow);

        // Check range
        if (fNegative || bnTarget == 0 || fOverflow || bnTarget > UintToArith256(params.powLimit))
            return false;

        // Check proof of work matches claimed amount
        if (UintToArith256(hash) > bnTarget)
            return false;

        return true;
    }

    int k = 32;
    int n = 26;
    AutolykosPowScheme powScheme(k, n);

    Version version = 0x05;
    //Version version = b_h.nVersion;

    std::string prevHash = b_h.hashPrevBlock.ToString();
    std::string merkleRoot = b_h.hashMerkleRoot.ToString();

    Timestamp timestamp = b_h.nTime;
    std::vector<uint8_t> nonce = powScheme.uint32ToBytes(b_h.nNonce);
    ModifierId parentId = powScheme.hexToBytesModifierId(prevHash);
    Digest32 transactionsRoot = powScheme.hexToArrayDigest32(merkleRoot);

    Digest32 ADProofsRoot = {};
    ADDigest stateRoot = {};
    Digest32 extensionRoot = {};

    AutolykosSolution powSolution = {
        groupElemFromBytes({0x02, 0xf5, 0x92, 0x4b, 0x14, 0x32, 0x5a, 0x1f, 0xfa, 0x8f, 0x95, 0xf8, 0xc0, 0x00, 0x06, 0x11, 0x87, 0x28, 0xce, 0x37, 0x85, 0xa6, 0x48, 0xe8, 0xb2, 0x69, 0x82, 0x0a, 0x3d, 0x3b, 0xdf, 0xd4, 0x0d}),
        groupElemFromBytes({0x02, 0xf5, 0x92, 0x4b, 0x14, 0x32, 0x5a, 0x1f, 0xfa, 0x8f, 0x95, 0xf8, 0xc0, 0x00, 0x06, 0x11, 0x87, 0x28, 0xce, 0x37, 0x85, 0xa6, 0x48, 0xe8, 0xb2, 0x69, 0x82, 0x0a, 0x3d, 0x3b, 0xdf, 0xd4, 0x0d}),
        nonce,
        boost::multiprecision::cpp_int("0")};

    std::array<uint8_t, 3> votes = {0x00, 0x00, 0x00};

    Header h(
        version,
        parentId,
        ADProofsRoot,
        stateRoot,
        transactionsRoot,
        timestamp,
        nBits,
        9999999,
        extensionRoot,
        powSolution,
        votes
    );

    // ErgoNodeViewModifier HeaderToBytes;
    // auto hash_Header = HeaderToBytes.serializedId(h);
    // uint256 headers = uint256(hash_Header);

    bool valid = powScheme.validate(h);
    LogPrintf("pow valid: ----------- %s\n", valid ? "true" : "false");
    return valid;
}
