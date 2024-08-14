#include "test.h"

//Create a Header for Test_1 
Header createHeader() {
    //We can pass the different Header for testing 
    Version version = 0x80;
    ModifierId parentId = {0x0f, 0x0f, 0x07, 0x07, 0x0f, 0x03, 0x0f, 0x0f, 0x02, 0x02, 0x00, 0x01, 0x07, 0x02, 0x00, 0x01, 0x07, 0x0f, 0x0f, 0x0f, 0x01, 0x0d, 
                           0x08, 0x07, 0x06, 0x0a, 0x06, 0x02, 0x00, 0x01, 0x08, 0x00, 0x00, 0x00, 0x08, 0x00, 0x08, 0x00, 0x06, 0x0a, 0x06, 0x04, 0x00, 0x01, 
                           0x00, 0x00, 0x08, 0x00, 0x04, 0x0e, 0x09, 0x01, 0x00, 0x01, 0x07, 0x0f, 0x08, 0x0c, 0x0e, 0x03, 0x0a, 0x02, 0x0c, 0x0c};
    
    Digest32 ADProofsRoot = {0x01,0xFF,0xFF,0x7F,0x17,0x00,0x7F,0x7F,0xFF,0x01,0x89,0x01,0x80,0x93,0xFF,0x7C,0xCA,0x7F,0x01,0x80,0x80,0xCD,0x94,0xB5,0x48,0x7F,0xFF,0x66,0x01,0x80,0xA0,0xA0};

    ADDigest stateRoot = {0x76,0x57,0xFF,0x80,0x22,0x44,0x00,0x01,0x00,0xE6,0x80,0x70,0x0A,0x10,0x7F,0xFF,0x00,0xF0,0xE2,0xFF,0x7A,0x80,0x00,0x00,0x00,0xB9,0xDC,0x01,0x80,0x7F,0x95,0x2D,0x80};

    Digest32 transactionsRoot = {0xFF,0x23,0xCB,0x4B,0xA7,0x80,0x7F,0xFF,0x7F,0xF6,0x00,0xAB,0x24,0xF4,0xA8,0x00,0xFF,0x00,0x7F,0x00,0x62,0x80,0x01,0x01,0xE4,0x62,0xFF,0x80,0x01,0xFF,0x1F,0x7F};
    
    uint64_t timestamp = 1318228178615962463 ;
    uint32_t nBits = 545259519 ;
    int height = 972944152;
    Digest32 extensionRoot = {0x01,0x00,0x01,0x80,0xF0,0x00,0x7F,0x7A,0x5F,0xDE,0xD6,0x7F,0x23,0x45,0x01,0xD4,0x80,0xA6,0xFF,0x80,0x6F,0xFE,0x94,0xFF,0x9A,0x49,0x6D,0x00,0xCB,0x80,0xFF,0x00};

    AutolykosSolution powSolution = {
      groupElemFromBytes({0x03,0x8B,0x2B,0x97,0x8E,0xCE,0x56,0xA0,0xAE,0x33,0xE7,0xF8,0xB7,0x13,0xCF,0x45,0xD9,0x46,0x43,0x5C,0x2A,0x2C,0xC0,0xE3,0x9C,0xF6,0x54,0x78,0xFA,0x26,0x69,0x25,0x3E}),
      groupElemFromBytes({0x02,0xC1,0x2F,0xDC,0x82,0x88,0xF0,0x88,0xAD,0xBA,0x0A,0x9D,0xA9,0x1A,0xE2,0x82,0x9F,0xCC,0x2A,0x7F,0x93,0x66,0x6A,0xDA,0x94,0xEB,0xB5,0x95,0xD1,0x1D,0x4B,0xDA,0x9A}),
      {0x7F,0x88,0xD4,0x6C,0x55,0x7F,0x83,0x7F},
      boost::multiprecision::cpp_int("1")
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
    std::cout << "test_validate_pow_randomSecret_1 \ntarget difficulty: " << difficulty << ", encodeCompactBits: " << nBits << std::endl;

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

    boost::multiprecision::cpp_int difficulty("104");  // take Reference value from scala
    int ver = 2;
    boost::multiprecision::cpp_int sk("103798771021325683892929856325529999058072839911537851036538591428488307048886");
    boost::multiprecision::cpp_int x("22945541812055663302057083203737909413611915224801085603911482314770463421299");

    test(powScheme, createHeader(), difficulty, ver, sk, x);


    return 0;
}
