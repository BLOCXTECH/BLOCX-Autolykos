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

//Create a Header for Test_3 
Header createHeader() {
    //We can pass the different Header for testing 
    Version version = 88;
    ModifierId parentId = { 0x05, 0x00, 0x09, 0x09, 0x07, 0x08, 0x03, 0x05, 0x07, 0x0F, 0x07, 0x0F, 0x06, 0x09, 0x0F, 0x0F, 0x03, 0x0C, 0x0F, 0x0F, 0x0F, 0x02, 0x00, 0x01, 0x08, 0x00, 0x08, 0x00, 0x08, 0x00, 0x0D, 0x0B, 0x0F, 0x0F, 0x09, 0x0E, 0x05, 0x08, 0x00, 0x00, 0x01, 0x03, 0x09, 0x00, 0x0F, 0x0F, 0x09, 0x0F, 0x0C, 0x0B, 0x0F, 0x09, 0x00, 0x01, 0x08, 0x00, 0x0F, 0x00, 0x01, 0x0C, 0x00, 0x00, 0x03, 0x0F };
    
    Digest32 ADProofsRoot = { 0xFF, 0x91, 0xFF, 0x14, 0x3A, 0xAC, 0x00, 0xCC, 0x00, 0x80, 0x01, 0xFF, 0x6C, 0xAF, 0x87, 0x83, 0xF8, 0x77, 0x3F, 0xB6, 0x7F, 0x00, 0xFF, 0xFF, 0x7F, 0x49, 0x7F, 0x30, 0x79, 0x25, 0x90, 0x00 };

    ADDigest stateRoot = { 0xB2, 0x02, 0x01, 0xEA, 0x3C, 0x1A, 0xFF, 0x4B, 0x00, 0x5E, 0x47, 0x00, 0x15, 0xA0, 0x6F, 0x80, 0x3E, 0xFF, 0xA7, 0x80, 0x52, 0xCC, 0xFF, 0x00, 0x73, 0xAD, 0x01, 0x7F, 0x7C, 0x85, 0x00, 0x00, 0x00 };

    Digest32 transactionsRoot = { 0x7F, 0x3D, 0x01, 0xBC, 0x2F, 0xFF, 0x90, 0x65, 0x00, 0x34, 0xFF, 0x7F, 0x7F, 0x4E, 0x80, 0xCF, 0x7F, 0x01, 0x7F, 0x60, 0x96, 0xF1, 0x7F, 0x7F, 0xBB, 0x00, 0x9A, 0xBC, 0x01, 0xFF, 0x01, 0x03 };
    
    uint64_t timestamp = 1878058897369628844;
    uint32_t nBits = 553680896;
    int height = 103598508;
    Digest32 extensionRoot = { 0x7F, 0x26, 0x01, 0x42, 0x00, 0x80, 0x75, 0xAD, 0xE1, 0x00, 0x00, 0xFF, 0x01, 0x5D, 0x5C, 0x00, 0xC1, 0x00, 0xFF, 0x8D, 0xEB, 0xFF, 0x80, 0xD8, 0xF5, 0x00, 0x82, 0x85, 0x5B, 0x9D, 0x77, 0x4C };

    AutolykosSolution powSolution = {
      groupElemFromBytes({ 0x02, 0xE7, 0x30, 0xF2, 0x2A, 0xBD, 0xD9, 0xF0, 0xF9, 0xFF, 0x50, 0x9E, 0x12, 0x64, 0x2F, 0xCC, 0x34, 0xCA, 0xEF, 0x97, 0xCC, 0xE6, 0x98, 0x27, 0xFE, 0xE8, 0xF9, 0x83, 0x0E, 0xA2, 0x6A, 0x78, 0x44 }),
      groupElemFromBytes({  0x03, 0x09, 0xB2, 0xCD, 0x51, 0xD2, 0x02, 0xA0, 0xD3, 0x2C, 0xE0, 0x0E, 0xDB, 0x71, 0xF3, 0x5C, 0x38, 0x16, 0x59, 0xB8, 0xFE, 0x4E, 0xC4, 0x90, 0x76, 0xAE, 0x5D, 0xBD, 0xF3, 0x13, 0x72, 0x64, 0x6D }),
      {  0x7F, 0x01, 0x9C, 0x00, 0x01, 0xFF, 0x01, 0x01 },
      boost::multiprecision::cpp_int("9223372036854775809")
    };
    std::array<uint8_t, 3> votes = {0x00, 0x00, 0x00};

    return Header(version, parentId, ADProofsRoot, stateRoot, transactionsRoot, timestamp, nBits, height, extensionRoot, powSolution, votes);
}

//generated solution should be valid
void test(AutolykosPowScheme& pow, const Header& inHeader, const boost::multiprecision::cpp_int& difficulty, uint8_t ver, boost::multiprecision::cpp_int sk, boost::multiprecision::cpp_int x) {
    auto nBits = encodeCompactBits(difficulty);
    std::cout << "ver1_test_validate_pow_3 \ntarget difficulty: " << difficulty << ", encodeCompactBits: " << nBits << std::endl;

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

    boost::multiprecision::cpp_int difficulty("110");  // take Reference value from scala
    int ver = 1;
    boost::multiprecision::cpp_int sk("6087003227820495343661544496775664633517938279065489767985598905063921750940");
    boost::multiprecision::cpp_int x("48190676666174562007691266381632859024808818976821134071020159966969940717741");

    test(powScheme, createHeader(), difficulty, ver, sk, x);

    return 0;
}
