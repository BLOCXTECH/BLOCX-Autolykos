#include "test.h"

//Create a Header for Test_8 
Header createHeader() {
    //We can pass the different Header for testing 
    Version version = 107;
    ModifierId parentId = { 0x07,0x0F,0x09,0x0A,0x00,0x01,0x08,0x00,0x06,0x01,0x0D,0x05,0x00,0x01,0x00,0x01,0x00,0x00,0x09,0x00,0x07,0x0F,0x00,0x01,0x00,0x01,0x06,0x04,0x08,0x00,0x03,0x03,0x0F,0x0A,0x07,0x0F,0x00,0x01,0x03,0x0D,0x07,0x0D,0x00,0x00,0x04,0x0F,0x07,0x0F,0x0F,0x0F,0x0E,0x0D,0x06,0x06,0x02,0x00,0x00,0x00,0x01,0x0F,0x08,0x00,0x07,0x0F };
    
    Digest32 ADProofsRoot = { 0x04,0x01,0x04,0xED,0x26,0x57,0xE9,0xFF,0x80,0xB9,0x01,0x05,0x01,0x00,0x00,0xC8,0x80,0xD5,0x3C,0x01,0x5B,0x13,0x01,0x7F,0xFF,0xE1,0x80,0x00,0x1F,0x30,0x01,0x4A };

    ADDigest stateRoot = { 0x32,0x73,0x01,0x80,0x53,0x36,0xBD,0x26,0x57,0xFF,0x89,0x00,0x10,0xE6,0xBC,0x80,0x80,0xDB,0x0A,0x7F,0xBB,0x80,0x3F,0x01,0x7A,0x7F,0x7F,0x2A,0xAA,0x1A,0x3B,0x03,0xD5 };

    Digest32 transactionsRoot = { 0x48,0x7F,0x00,0x83,0x9E,0x7F,0xD6,0x04,0x7F,0x15,0xD0,0x00,0x80,0x64,0x80,0xA0,0xFF,0x7F,0x7F,0xB3,0xBC,0x31,0x15,0x57,0x13,0x80,0x01,0x01,0xE7,0x57,0x80,0x7F };
    
    uint64_t timestamp = 3563464404046197395;
    uint32_t nBits = 545259519;
    int height = 273373955;
    Digest32 extensionRoot = { 0x4F,0xB6,0xFF,0x4E,0x80,0xFF,0x00,0x00,0x01,0xDD,0xFF,0x09,0x80,0x5A,0x33,0x80,0x96,0x01,0xFF,0x72,0x00,0x7F,0x85,0x80,0x11,0x1F,0x01,0x6F,0x3B,0x7F,0x80,0xE5 };

    AutolykosSolution powSolution = {
      groupElemFromBytes({ 0x03,0x93,0x4A,0xC3,0x51,0x9F,0xEF,0xDB,0xE5,0x01,0x21,0xD7,0x60,0x30,0x15,0x32,0x47,0xC9,0x77,0xDE,0x6F,0xBB,0xEA,0x28,0x9F,0x7C,0x3F,0x01,0x9F,0x54,0x87,0xE7,0xCE }),
      groupElemFromBytes({ 0x02,0xAD,0x40,0xBC,0x62,0x74,0x63,0x39,0xA3,0xFC,0x20,0xB3,0xDF,0x02,0xD5,0xE6,0xEE,0x43,0xB1,0x36,0xBE,0xA8,0xE4,0x0E,0x9C,0xE2,0x82,0x34,0xC0,0x28,0x6D,0x6D,0x28 }),
      { 0x07,0xB5,0x80,0x34,0x00,0xEF,0x4D,0x52 },
      boost::multiprecision::cpp_int("1426499366220467016")
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
    std::cout << "test8 \ntarget difficulty: " << difficulty << ", encodeCompactBits: " << nBits << std::endl;

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

    boost::multiprecision::cpp_int difficulty("112");  // take Reference value from scala
    int ver = 2;
    boost::multiprecision::cpp_int sk("67172891721809277525659496971208822326434122625645530932948118536945061296184");
    boost::multiprecision::cpp_int x("96071207200598303854005299364786876483372829963074712288432785000850512712500");

    test(powScheme, createHeader(), difficulty, ver, sk, x);


    return 0;
}
