#include "test.h"

//Create a Header for Test_7 
Header createHeader() {
    //We can pass the different Header for testing 
    Version version = 127;
    ModifierId parentId = { 0x00,0x00,0x00,0x00,0x08,0x00,0x0D,0x00,0x08,0x00,0x0F,0x03,0x0F,0x0F,0x0F,0x0F,0x0C,0x06,0x08,0x00,0x06,0x09,0x0B,0x0B,0x07,0x0F,0x04,0x0D,0x0E,0x0C,0x07,0x0F,0x0E,0x0F,0x01,0x0F,0x0F,0x0F,0x00,0x00,0x07,0x0D,0x08,0x00,0x0F,0x0C,0x07,0x0F,0x00,0x00,0x06,0x05,0x0F,0x0F,0x04,0x0F,0x0F,0x0F,0x0F,0x0F,0x06,0x0E,0x09,0x00 };
    
    Digest32 ADProofsRoot = { 0x00,0xEE,0x00,0x1D,0x6E,0x00,0x80,0x80,0x2A,0x01,0xFC,0x9F,0x78,0x00,0x6F,0x7F,0x80,0xFF,0x80,0x63,0x01,0x80,0x7F,0x7A,0x70,0x35,0x00,0xFF,0xFF,0xFF,0x21,0x44 };

    ADDigest stateRoot = { 0xFF,0x80,0x7F,0x7F,0x99,0xC9,0xFF,0x8C,0x7F,0x7F,0x7F,0x01,0x01,0x7F,0x7F,0xDE,0x7F,0x01,0xDD,0xD1,0xFF,0xB8,0xFF,0x7F,0x01,0x80,0xFF,0x13,0x01,0x01,0x50,0x01,0xA5 };

    Digest32 transactionsRoot = { 0x11,0x7F,0x8D,0x01,0xFF,0x73,0xFF,0x7F,0x7F,0xB8,0x01,0x77,0x01,0x4E,0x00,0x80,0xED,0xAD,0x23,0x27,0x98,0x01,0x8B,0xFF,0x6D,0x01,0x05,0x01,0xE3,0x01,0xEC,0xFF };
    
    uint64_t timestamp =1309379280955247909 ;
    uint32_t nBits =269225590 ;
    int height =1972384178 ;
    Digest32 extensionRoot = { 0x6B,0x4E,0xCD,0x5B,0x52,0x97,0x9F,0x80,0xFF,0x7F,0x80,0x89,0x00,0x36,0xF0,0xE1,0x01,0x00,0x0E,0x8C,0xBB,0xEF,0xFF,0x80,0x08,0x00,0x11,0x7F,0x7F,0xA7,0x0B,0xFF };

    AutolykosSolution powSolution = {
      groupElemFromBytes({ 0x03,0xFB,0x1A,0xE3,0xBA,0xE8,0xB9,0x74,0x42,0x7E,0x3F,0x0B,0x82,0xC1,0xA8,0x2E,0x33,0xC3,0x25,0xDF,0x5F,0xB4,0xC5,0x67,0xF9,0x07,0x82,0x4D,0xC6,0xF3,0xD8,0xE5,0x7A }),
      groupElemFromBytes({ 0x03,0xEE,0xC3,0xAA,0x45,0x44,0x58,0xF6,0x52,0x48,0xF8,0x19,0x13,0x9B,0x95,0x4F,0x5A,0x76,0x3C,0x28,0xAF,0xC4,0xAA,0x6C,0xDB,0x2A,0xE5,0x46,0x34,0x53,0x07,0x0E,0x04 }),
      { 0x3C,0x2A,0x97,0x2F,0x01,0x7C,0xAB,0xA6 },
      boost::multiprecision::cpp_int("115792089237316195423570985008687907852837564279074904382595939769481306718528")
    };
    std::array<uint8_t, 3> votes = {0x00, 0x00, 0x00};

    return Header(version, parentId, ADProofsRoot, stateRoot, transactionsRoot, timestamp, nBits, height, extensionRoot, powSolution, votes);
}

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
        std::cout << static_cast<int>(static_cast<int8_t>(byte)) << " ";
    }
    std::cout << std::endl;

    std::cout << "StateRoot: ";
    for (const auto& byte : header.stateRoot) {
        std::cout << static_cast<int>(static_cast<int8_t>(byte)) << " ";
    }
    std::cout << std::endl;

    std::cout << "TransactionsRoot: ";
    for (const auto& byte : header.transactionsRoot) {
        std::cout << static_cast<int>(static_cast<int8_t>(byte)) << " ";
    }
    std::cout << std::endl;

    std::cout << "Timestamp: " << header.timestamp << std::endl;
    std::cout << "nBits: " << header.nBits << std::endl;
    std::cout << "Height: " << header.height << std::endl;

    std::cout << "ExtensionRoot: ";
    for (const auto& byte : header.extensionRoot) {
        std::cout << static_cast<int>(static_cast<int8_t>(byte)) << " ";
    }
    std::cout << std::endl;
}

//generated solution should be valid
void test(AutolykosPowScheme& pow, const Header& inHeader, const boost::multiprecision::cpp_int& difficulty, uint8_t ver, boost::multiprecision::cpp_int sk, boost::multiprecision::cpp_int x) {
    auto nBits = encodeCompactBits(difficulty);
    std::cout << "test7 \ntarget difficulty: " << difficulty << ", encodeCompactBits: " << nBits << std::endl;

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

    boost::multiprecision::cpp_int difficulty("107");  // take Reference value from scala
    int ver = 2;
    boost::multiprecision::cpp_int sk("26008315417613134577204817443459070338559310059855770370701716407625301048294");
    boost::multiprecision::cpp_int x("64723111648247860390519864607267933631895339155493791025949618529846266372636");

    test(powScheme, createHeader(), difficulty, ver, sk, x);


    return 0;
}
