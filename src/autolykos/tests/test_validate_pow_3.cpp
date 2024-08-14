#include "test.h"

//Create a Header for Test_3 
Header createHeader() {
    //We can pass the different Header for testing 
    Version version = static_cast<uint8_t>(-99);
    ModifierId parentId = {0x01,0x0A,0x05,0x0A,0x07,0x0F,0x00,0x01,0x01,0x0F,0x0F,0x0F,0x07,0x0F,0x00,0x00,0x00,0x00,0x07,0x0F,0x0F,0x0F,0x00,0x01,0x0A,0x0D,0x00,0x01,0x07,0x0F,0x00,0x00,0x08,0x00,0x0F,0x0F,0x00,0x00,0x0C,0x08,0x04,0x02,0x07,0x0F,0x05,0x06,0x0F,0x0F,0x0C,0x02,0x00,0x00,0x07,0x0F,0x07,0x0F,0x04,0x0E,0x0F,0x0F,0x02,0x07,0x08,0x07};
    
    Digest32 ADProofsRoot = {0xFF,0x81,0x29,0x15,0x38,0x00,0x01,0x57,0x00,0x1B,0xF6,0x80,0xFF,0x7F,0x80,0xF4,0x33,0xD5,0x23,0x9A,0xFF,0x01,0xAB,0x30,0x1F,0xAB,0x76,0x13,0xFF,0xFF,0xE5,0x7F};

    ADDigest stateRoot = {0x73,0x00,0x99,0x3E,0x80,0x01,0x80,0xB6,0x80,0x80,0x4B,0x7F,0xFF,0xFF,0x01,0xFF,0xAB,0x16,0xA3,0x0E,0x7F,0x80,0x01,0x7F,0x80,0xFA,0x80,0x7F,0x80,0x01,0x35,0x10,0xFF};

    Digest32 transactionsRoot = {0x25,0x01,0x80,0x7A,0x00,0x53,0x2A,0x8E,0x99,0xE5,0x7F,0x5F,0x00,0xF4,0xFE,0x80,0x7F,0xF8,0x7F,0xD5,0x1F,0x01,0x26,0x01,0x01,0xA5,0xDE,0x80,0xA2,0x00,0x9F,0xB8};
    
    uint64_t timestamp = 1512305621506999108;
    uint32_t nBits = 545259519;
    int height = 1495400079;
    Digest32 extensionRoot = {0x01,0xC3,0xFF,0x80,0x08,0x2E,0xA6,0x50,0x7F,0xFF,0xC6,0x97,0x5E,0x01,0x31,0x7D,0x80,0x37,0xF1,0x6A,0x80,0x00,0x1B,0x00,0x80,0x1A,0xBA,0x7F,0xFF,0x86,0x80,0x92};

    AutolykosSolution powSolution = {
      groupElemFromBytes({0x02,0xCF,0x3A,0x01,0xF9,0x35,0x2C,0xDE,0x12,0x3D,0x26,0xA2,0xAE,0x98,0xA7,0x34,0xA4,0x7F,0x0F,0xB4,0x34,0x08,0xAF,0x79,0xFD,0xB4,0xBB,0xCA,0x40,0xBD,0xB4,0x84,0x81}),
      groupElemFromBytes({0x03,0xA6,0xD6,0xAE,0xDD,0x96,0xDB,0x85,0x36,0xD9,0xEA,0xBF,0xDD,0xD0,0x8B,0xCE,0xB8,0xE2,0x95,0xEF,0x59,0x68,0xA9,0x00,0xBE,0x81,0x97,0x3C,0x22,0xA3,0x81,0xE0,0xDE}),
      {0x7F,0xFF,0x01,0x01,0x7F,0x09,0x7F,0x01},
      boost::multiprecision::cpp_int("2")
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
    std::cout << "test3 \ntarget difficulty: " << difficulty << ", encodeCompactBits: " << nBits << std::endl;

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

    boost::multiprecision::cpp_int difficulty("118");  // take Reference value from scala
    int ver = 2;
    boost::multiprecision::cpp_int sk("54652846832870233196171651526556839316339705153573517594148332019884215324577");
    boost::multiprecision::cpp_int x("92311196561450343507994162576617159693467890508440680421775591641041327291243");

    test(powScheme, createHeader(), difficulty, ver, sk, x);


    return 0;
}
