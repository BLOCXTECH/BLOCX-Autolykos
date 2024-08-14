#include "test.h"

//Create a Header for Test_6 
Header createHeader() {
    //We can pass the different Header for testing 
    Version version = static_cast<uint8_t>(-1);
    ModifierId parentId = { 0x00,0x01,0x08,0x0E,0x03,0x02,0x09,0x09,0x08,0x00,0x00,0x01,0x07,0x0F,0x0C,0x00,0x03,0x08,0x08,0x00,0x0E,0x0B,0x08,0x00,0x07,0x0F,0x0B,0x0A,0x08,0x00,0x01,0x0B,0x07,0x0F,0x0D,0x0B,0x08,0x00,0x0E,0x09,0x00,0x01,0x0D,0x06,0x07,0x0F,0x07,0x0F,0x0D,0x02,0x08,0x00,0x07,0x0F,0x0F,0x07,0x0F,0x0F,0x08,0x01,0x00,0x00,0x00,0x01 };
    
    Digest32 ADProofsRoot = { 0x01,0xFF,0x63,0x3D,0xC2,0x7F,0xCA,0x0C,0xED,0xC8,0x00,0xAF,0x80,0x80,0xA1,0x00,0xF9,0x8B,0xFF,0x00,0x7F,0xEA,0xFF,0xFF,0x7F,0x37,0x4F,0x01,0xB9,0x7F,0x80,0x01 };

    ADDigest stateRoot = { 0x01,0x7F,0x1E,0x2B,0x00,0xE1,0x01,0xB1,0x1B,0x01,0x91,0xD3,0x00,0xBF,0x7F,0xFF,0x6C,0xF7,0x10,0x7F,0x56,0x80,0xAD,0xD8,0x70,0x16,0xCC,0xFF,0x8E,0xE9,0x80,0xEA,0x1C };

    Digest32 transactionsRoot = { 0x74,0x3C,0xC1,0x25,0xFF,0x80,0xDA,0xC4,0xE1,0x7F,0x00,0xFC,0x37,0xFF,0xF9,0x01,0xFF,0xBD,0x2A,0xFF,0x83,0x7F,0x00,0x01,0x74,0xD3,0x01,0xFF,0x80,0xFF,0xFF,0x00 };
    
    uint64_t timestamp = 6615069633578902460;
    uint32_t nBits = 16908288;
    int height = 1899037625;
    Digest32 extensionRoot = { 0x80,0x95,0x88,0xFF,0xAC,0x80,0x80,0x7F,0x7F,0xC9,0x01,0xFF,0x4F,0x4F,0x7F,0x80,0xFF,0x6B,0x51,0x7F,0xFF,0x7F,0x80,0x1A,0x8E,0x80,0x00,0xA0,0x7F,0x04,0x37,0x80 };

    AutolykosSolution powSolution = {
      groupElemFromBytes({ 0x02,0x72,0x96,0xA1,0x6B,0x8F,0xE7,0x77,0x15,0x32,0x6D,0x1B,0xDB,0xF4,0xA3,0x37,0xE5,0x04,0xBC,0x4B,0xC8,0x13,0xF0,0xB2,0xC1,0x22,0x13,0xEF,0x78,0x5A,0xC5,0x27,0x62 }),
      groupElemFromBytes({ 0x02,0x15,0xE2,0x3A,0x6B,0x89,0xFF,0x27,0xE8,0x9C,0x1C,0x92,0x24,0xE8,0xD7,0x5E,0x9A,0x62,0x0E,0x79,0xA9,0xC9,0xAB,0x37,0x50,0x1A,0xDC,0xA3,0x0C,0xF7,0x34,0xF4,0x13 }),
      { 0x75,0x6C,0xE9,0xEF,0xFF,0x80,0x80,0x0F },
      boost::multiprecision::cpp_int("362889864603259163181657880556937593")
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
    std::cout << "test6 \ntarget difficulty: " << difficulty << ", encodeCompactBits: " << nBits << std::endl;

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

    boost::multiprecision::cpp_int difficulty("106");  // take Reference value from scala
    int ver = 2;
    boost::multiprecision::cpp_int sk("58097206524998761541236164275592732806772762515925945613132009922709959972610");
    boost::multiprecision::cpp_int x("21837634604700052925311000745081602556849285518196339369235841323253519011864");

    test(powScheme, createHeader(), difficulty, ver, sk, x);


    return 0;
}
