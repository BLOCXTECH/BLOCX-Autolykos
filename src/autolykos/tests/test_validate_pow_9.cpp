#include "test.h"

//Create a Header for Test_9 
Header createHeader() {
    //We can pass the different Header for testing 
    Version version = static_cast<uint8_t>(-12);
    ModifierId parentId = { 0x07,0x0F,0x08,0x00,0x0E,0x00,0x03,0x01,0x05,0x0A,0x0D,0x0D,0x0F,0x0F,0x0E,0x0F,0x08,0x0F,0x0C,0x04,0x02,0x0C,0x00,0x01,0x00,0x00,0x00,0x01,0x0B,0x08,0x00,0x01,0x0E,0x04,0x0F,0x0F,0x0C,0x0B,0x0E,0x0B,0x0C,0x0B,0x0F,0x04,0x07,0x0F,0x0C,0x0F,0x05,0x07,0x08,0x00,0x08,0x00,0x0D,0x06,0x08,0x00,0x00,0x00,0x08,0x00,0x01,0x0E };
    
    Digest32 ADProofsRoot = { 0xFF,0xFF,0x7F,0x2B,0x3E,0x05,0x00,0xD2,0x7F,0xF2,0x4A,0x36,0x00,0x31,0xEA,0x88,0x01,0x00,0xAC,0x80,0xE8,0x79,0x01,0x01,0xDE,0x80,0x01,0x45,0x81,0x80,0x7F,0xA5 };

    ADDigest stateRoot = { 0xF2,0xFF,0xFB,0x39,0xF8,0x5F,0xFF,0x01,0xFF,0xFF,0x01,0x27,0x00,0x80,0x01,0xFF,0x80,0x83,0x7B,0x7F,0x53,0x80,0x80,0xD9,0xFF,0x34,0xFD,0xCF,0x19,0xFF,0x7F,0xD4,0x80 };

    Digest32 transactionsRoot = { 0x01,0xA0,0x00,0x00,0xC4,0x01,0x01,0xDA,0x7F,0x00,0x8D,0x80,0x3D,0x7F,0x55,0x7F,0x80,0xBC,0xEE,0x59,0x7F,0x70,0x02,0x4B,0x80,0xFF,0xFF,0x8D,0xB4,0x00,0xFF,0x00 };
    
    uint64_t timestamp = 1659332395337627804;
    uint32_t nBits = 142066332;
    int height = 319005785;
    Digest32 extensionRoot = { 0x85,0xBB,0x1F,0x7F,0xFF,0x01,0x7A,0xFF,0xE6,0x00,0xD5,0x33,0x01,0x50,0xB5,0xDD,0x8B,0x24,0xFF,0x8E,0x29,0xEC,0x01,0x48,0xFF,0xD7,0x78,0x04,0xFF,0xFF,0x01,0xFF };

    AutolykosSolution powSolution = {
      groupElemFromBytes({ 0x02,0x7C,0x56,0xE5,0x46,0xF7,0x8F,0x0E,0x81,0x72,0xD5,0xEF,0x36,0xCD,0x72,0xCD,0x86,0x3F,0xD1,0x15,0x84,0xE4,0xC7,0x2F,0x1C,0xD8,0x1F,0x8E,0x44,0x33,0x0A,0xC1,0x8E }),
      groupElemFromBytes({ 0x03,0xD4,0x1F,0x63,0x96,0x13,0x6A,0x2E,0x85,0x49,0x2A,0x3B,0xBD,0x9B,0x41,0xA0,0xAF,0xDA,0x1C,0xEC,0x39,0xD0,0x7C,0x44,0x02,0x66,0x51,0xD3,0xF6,0x5B,0x02,0x52,0x65 }),
      { 0x01,0x95,0x63,0x7F,0x00,0x0C,0x63,0x00 },
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
    std::cout << "test9 \ntarget difficulty: " << difficulty << ", encodeCompactBits: " << nBits << std::endl;

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
    boost::multiprecision::cpp_int sk("81748199845327347177186448911773130163988103329960965002166773310534464183268");
    boost::multiprecision::cpp_int x("53550379000871868292772208793961928646673255392194226792925912331250050937938");

    test(powScheme, createHeader(), difficulty, ver, sk, x);


    return 0;
}
