#include "test.h"

//Create a Header for Test_2 
Header createHeader() {
    //We can pass the different Header for testing 
    Version version = 0;
    ModifierId parentId = {0x0F,0x0F,0x05,0x08,0x08,0x00,0x00,0x00,0x08,0x03,0x02,0x04,0x00,0x00,0x0F,0x05,0x07,0x0F,0x05,0x00,0x00,0x00,0x08,0x03,0x00,0x01,0x0F,0x0F,0x07,0x0F,0x08,0x00,0x0E,0x03,0x00,0x00,0x0F,0x0F,0x08,0x00,0x00,0x01,0x06,0x05,0x00,0x00,0x08,0x00,0x03,0x07,0x03,0x06,0x00,0x00,0x08,0x0F,0x06,0x0F,0x00,0x01,0x01,0x07,0x07,0x0F};
    
    Digest32 ADProofsRoot = {0x7F,0x7E,0x7F,0x1E,0x7F,0x01,0x7E,0xD0,0x3D,0xFF,0x53,0x7F,0x00,0xF7,0xFF,0x80,0x8B,0x34,0x00,0x05,0xFF,0x7F,0x80,0x0E,0x9A,0x32,0xFA,0xFF,0x86,0x7F,0x6C,0xFF};

    ADDigest stateRoot = {0x50,0xCC,0x86,0x80,0x00,0x6A,0x7F,0x90,0x00,0x7F,0xD7,0xFF,0x00,0x0C,0x7F,0x01,0xD4,0x80,0x86,0x80,0xE5,0x80,0x4B,0x7F,0x15,0x00,0x71,0xFF,0x00,0x00,0x26,0x80,0xFF};

    Digest32 transactionsRoot = {0x99,0x01,0xF4,0x7F,0x47,0x7F,0x01,0x28,0x6F,0xFF,0x80,0xA7,0x7F,0xA3,0x00,0x24,0x01,0x00,0x80,0x01,0x97,0xFF,0x00,0x36,0x01,0x00,0xFF,0x80,0x00,0xFF,0x7F,0xE4};
    
    uint64_t timestamp = 2676450233257120514;
    uint32_t nBits = 545259519;
    int height =1581898302;
    Digest32 extensionRoot = {0x80,0xFF,0xF5,0x00,0xB4,0xFF,0x88,0x01,0x01,0x8B,0x4B,0x00,0x7F,0x3C,0xD7,0xD5,0xFF,0x29,0x48,0x34,0xFF,0x32,0xFF,0x01,0x70,0x9E,0xFF,0xC2,0x80,0x7F,0x73,0x68};

    AutolykosSolution powSolution = {
      groupElemFromBytes({0x02,0x2A,0xA4,0x15,0x4A,0x76,0xC6,0x98,0x2A,0x88,0x02,0x56,0xCE,0x28,0x7A,0xD4,0xC1,0x0E,0x60,0xE0,0xE6,0x9D,0x4F,0xEA,0x1A,0x26,0x4D,0x5A,0xC2,0x24,0xD4,0x08,0x60}),
      groupElemFromBytes({0x02,0x1A,0x0D,0x0D,0xF1,0x41,0x51,0xD2,0x2D,0xA3,0xE5,0xF1,0x98,0x8D,0xB1,0x37,0xA7,0x3E,0x22,0x14,0x60,0x8E,0x49,0x90,0x16,0x3E,0xBC,0x38,0x03,0xA3,0x1B,0xA3,0xF3}),
      {0xFE,0x0E,0x98,0x7F,0xFF,0x7F,0x28,0x29},
      boost::multiprecision::cpp_int("115792089237316195423570985008687907852837564279074904382595939769481306718529")
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
    std::cout << "test2 \ntarget difficulty: " << difficulty << ", encodeCompactBits: " << nBits << std::endl;

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
    boost::multiprecision::cpp_int sk("98642030513803851904932498566066081315336617879984965822499994243251884184336");
    boost::multiprecision::cpp_int x("113033790729352489485451777002644075326687615206669451620584204770230547834289");

    test(powScheme, createHeader(), difficulty, ver, sk, x);


    return 0;
}
