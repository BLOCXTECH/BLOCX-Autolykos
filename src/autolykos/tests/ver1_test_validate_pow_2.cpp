#include "test.h"

void printInt(const std::vector<uint8_t>& hash) {
    for (size_t i = 0; i < hash.size(); ++i) {
        int8_t signedByte = static_cast<int8_t>(hash[i]);
        std::cout << static_cast<int>(signedByte);
        if (i != hash.size() - 1) {
            std::cout << ", ";
        }
    }
    std::cout << std::endl;
}

void printHeader(const Header& header) {
    std::cout << "Version: " << static_cast<int>(header.version) << std::endl;

    std::cout << "Parent ID: ";
    printInt(header.parentId);

    std::cout << "ADProofsRoot: ";
    for (const auto& byte : header.ADProofsRoot) {
        std::cout << static_cast<int>(static_cast<int8_t>(byte)) << ", ";
    }
    std::cout << std::endl;

    std::cout << "StateRoot: ";
    for (const auto& byte : header.stateRoot) {
        std::cout << static_cast<int>(static_cast<int8_t>(byte)) << ", ";
    }
    std::cout << std::endl;

    std::cout << "TransactionsRoot: ";
    for (const auto& byte : header.transactionsRoot) {
        std::cout << static_cast<int>(static_cast<int8_t>(byte)) << ", ";
    }
    std::cout << std::endl;

    std::cout << "Timestamp: " << header.timestamp << std::endl;
    std::cout << "nBits: " << header.nBits << std::endl;
    std::cout << "Height: " << header.height << std::endl;

    std::cout << "ExtensionRoot: ";
    for (const auto& byte : header.extensionRoot) {
        std::cout << static_cast<int>(static_cast<int8_t>(byte)) << ", ";
    }
    std::cout << std::endl;
}

//Create a Header for Test_2 
Header createHeader() {
    //We can pass the different Header for testing 
    Version version = 72;
    ModifierId parentId = { 0x00, 0x00, 0x0F, 0x09, 0x02, 0x01, 0x0F, 0x0F, 0x00, 0x01, 0x0C, 0x08, 0x0F, 0x02, 0x02, 0x0F, 0x00, 0x01, 0x07, 0x05, 0x00, 0x01, 0x08, 0x00, 0x02, 0x0C, 0x05, 0x01, 0x00, 0x01, 0x08, 0x01, 0x02, 0x08, 0x07, 0x0F, 0x08, 0x00, 0x08, 0x00, 0x08, 0x00, 0x0A, 0x0B, 0x00, 0x08, 0x02, 0x0A, 0x09, 0x03, 0x0F, 0x0F, 0x07, 0x0F, 0x0F, 0x0F, 0x0A, 0x05, 0x04, 0x08, 0x00, 0x01, 0x07, 0x0F };
    
    Digest32 ADProofsRoot = { 0xFF, 0xD0, 0x80, 0x45, 0x69, 0x57, 0x80, 0x44, 0x00, 0xA9, 0x01, 0xA2, 0x01, 0x01, 0x01, 0x00, 0xA0, 0x46, 0x00, 0x38, 0x00, 0x10, 0x38, 0xFF, 0xB0, 0x58, 0xC4, 0x7F, 0x80, 0x9D, 0x7F, 0x7F };

    ADDigest stateRoot = { 0x09, 0xB4, 0x53, 0x30, 0x24, 0xFF, 0x80, 0x52, 0xC6, 0x01, 0x4C, 0x00, 0x6C, 0x01, 0x00, 0x59, 0xFF, 0xE5, 0x5F, 0x31, 0x36, 0xFF, 0x09, 0x68, 0x3C, 0xFF, 0x00, 0x7A, 0xEA, 0xCF, 0x80, 0x72, 0x66 };

    Digest32 transactionsRoot = { 0xCD, 0xCD, 0x80, 0x00, 0xFF, 0x95, 0x1A, 0x06, 0x7F, 0xF2, 0xB5, 0xD2, 0x80, 0xC8, 0x22, 0x58, 0x00, 0xD0, 0x00, 0x1F, 0xFF, 0x00, 0x01, 0x80, 0x00, 0x80, 0x7F, 0x22, 0xFA, 0x83, 0xF1, 0xB8 };
    
    uint64_t timestamp = 543264893969512998;
    uint32_t nBits = 545259519;
    int height = 1340686236;
    Digest32 extensionRoot = { 0x00, 0x93, 0x48, 0x80, 0xFF, 0x7F, 0x01, 0xA9, 0x80, 0x7A, 0x80, 0x2F, 0x04, 0x54, 0x00, 0x7F, 0x3E, 0x80, 0xD1, 0x80, 0x00, 0x80, 0xB7, 0x00, 0x00, 0x00, 0x7F, 0x3F, 0x48, 0x7F, 0x83, 0x01 };

    AutolykosSolution powSolution = {
      groupElemFromBytes({ 0x03, 0xB7, 0x30, 0x8E, 0xAD, 0xF9, 0x90, 0x2B, 0x83, 0x07, 0x17, 0x0B, 0xAC, 0x0B, 0x46, 0xB9, 0xB5, 0x5D, 0xE4, 0xBD, 0xC3, 0xC9, 0xF0, 0xED, 0x19, 0x22, 0x41, 0x28, 0x46, 0x2E, 0x7F, 0x75, 0x81 }),
      groupElemFromBytes({ 0x02, 0xDF, 0x2A, 0x64, 0x4B, 0x5E, 0x73, 0x4E, 0x79, 0x1F, 0xAF, 0x7F, 0x91, 0x49, 0x0E, 0x2D, 0x17, 0x0C, 0xC4, 0x4A, 0x9A, 0x77, 0x71, 0x86, 0x2B, 0x34, 0x0A, 0x70, 0x21, 0x0B, 0x50, 0xF1, 0x34 }),
      { 0x27, 0x7F, 0xAC, 0x3B, 0x91, 0x80, 0x80, 0xB2 },
      boost::multiprecision::cpp_int("295507168895360040275132840396664595852777560925735198201")
    };
    std::array<uint8_t, 3> votes = {0x00, 0x00, 0x00};

    return Header(version, parentId, ADProofsRoot, stateRoot, transactionsRoot, timestamp, nBits, height, extensionRoot, powSolution, votes);
}

//generated solution should be valid
void test(AutolykosPowScheme& pow, const Header& inHeader, const boost::multiprecision::cpp_int& difficulty, uint8_t ver, boost::multiprecision::cpp_int sk, boost::multiprecision::cpp_int x) {
    auto nBits = encodeCompactBits(difficulty);
    std::cout << "ver1_test_validate_pow_2 \ntarget difficulty: " << difficulty << ", encodeCompactBits: " << nBits << std::endl;

    printHeader(inHeader); 
    Header h = inHeader;
    h.nBits = nBits;
    h.version = ver;

   // auto sk = randomSecret();
   // auto x = randomSecret();
    HeaderWithoutPow headerWithoutPow = pow.toHeaderWithoutPow(h);
    //We need to pass headerWithoutPow as the input type for the msgByHeader and calcN method as it's input type is HeaderWithoutPow
    auto msg = pow.msgByHeader(headerWithoutPow);

    std::cout << "msg: ";
    printInt(msg);

    auto b = pow.getB(h.nBits);
    std::cout << "target b: " << b << ", nBits: " << h.nBits << std::endl;

    std::vector<uint8_t> hbs(4); // used in AL v.2 only
    hbs[0] = (h.height >> 24) & 0xFF;
    hbs[1] = (h.height >> 16) & 0xFF;
    hbs[2] = (h.height >> 8) & 0xFF;
    hbs[3] = h.height & 0xFF;

    int N = pow.calcN(headerWithoutPow);

    Header newHeader = h;
    auto optionalSolution = pow.checkNonces(ver, hbs, msg, sk, x, b, N, 0, 1000);
    if (optionalSolution) {
        newHeader.copy(optionalSolution.value());
        pow.validate(newHeader);
    } else {
        std::cerr << "No valid solution found" << std::endl;
    }
    
    // Additional Validation for Version > InitialVersion
    if (ver > Header::InitialVersion) {
        // We remove last byte of "msg", perform PoW and check that it fails validation
        std::vector<uint8_t> bytesWithoutPow = HeaderSerializer::bytesWithoutPow(headerWithoutPow);
        if (bytesWithoutPow.back() != 0) {
            throw std::runtime_error("Last byte of bytesWithoutPow is not 0.");
        }
        std::vector<uint8_t> msg2 = Blake2b256({bytesWithoutPow.begin(), bytesWithoutPow.end() - 1});

        Header newHeader2 = h;
        optionalSolution = pow.checkNonces(ver, hbs, msg2, sk, x, b, N, 0, 1000);
        if (optionalSolution) {
            newHeader2.copy(optionalSolution.value());
            pow.validate(newHeader2);
        } else {
            std::cerr << "No valid solution found" << std::endl;
        }
    }
}

int main() {
    int k = 32;
    int n = 26; // Example values, adjust as needed
                
    // Create an instance of AutolykosPowScheme
    AutolykosPowScheme powScheme(k, n);

    boost::multiprecision::cpp_int difficulty("116");  // take Reference value from scala
    int ver = 1;
    boost::multiprecision::cpp_int sk("7693679114588093338884251640589183989639821248971614068541128445244315754593");
    boost::multiprecision::cpp_int x("32809740327163090185533781579502753406264004620230784907113235850316330834398");

    test(powScheme, createHeader(), difficulty, ver, sk, x);

    return 0;
}
