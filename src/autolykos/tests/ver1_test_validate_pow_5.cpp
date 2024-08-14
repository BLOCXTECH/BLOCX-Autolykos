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

//Create a Header for Test_5 
Header createHeader() {
    //We can pass the different Header for testing 
    Version version = static_cast<uint8_t>(-12);
    ModifierId parentId = { 0x0F, 0x0F, 0x00, 0x01, 0x02, 0x0E, 0x00, 0x01, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x06, 0x00, 0x00, 0x0F, 0x07, 0x08, 0x00, 0x09, 0x07, 0x03, 0x0D, 0x03, 0x06, 0x00, 0x01, 0x00, 0x01, 0x03, 0x0C, 0x05, 0x08, 0x07, 0x0F, 0x00, 0x00, 0x00, 0x01, 0x0C, 0x01, 0x07, 0x0F, 0x0C, 0x09, 0x00, 0x00, 0x0A, 0x01, 0x0F, 0x0F, 0x07, 0x0F, 0x08, 0x00, 0x08, 0x00, 0x0C, 0x05, 0x07, 0x0F, 0x0E, 0x04 };
    
    Digest32 ADProofsRoot = { 0x87, 0x0E, 0x74, 0xFF, 0x00, 0x00, 0x80, 0x55, 0x7F, 0x47, 0x7F, 0x80, 0x00, 0x80, 0x7F, 0x01, 0x01, 0x69, 0xDF, 0x65, 0x7F, 0x6F, 0xFF, 0x01, 0x01, 0xFF, 0x90, 0xB4, 0x7F, 0x01, 0x2D, 0x2C };

    ADDigest stateRoot = { 0x1A, 0x01, 0xA2, 0x00, 0x01, 0xFF, 0x08, 0x80, 0xA5, 0xFF, 0x7F, 0xDB, 0xFF, 0x00, 0x7F, 0xE2, 0x7F, 0x00, 0x42, 0x0E, 0x00, 0x92, 0xB4, 0x7F, 0x7F, 0xFA, 0xFF, 0x00, 0x54, 0x60, 0xFF, 0xD7, 0xFF };

    Digest32 transactionsRoot = { 0x01, 0xC3, 0xB5, 0x70, 0xFF, 0x80, 0xBA, 0xFF, 0xFF, 0xA3, 0x01, 0x58, 0x00, 0x01, 0x3F, 0xE3, 0xB4, 0x00, 0x80, 0x80, 0x7F, 0x7F, 0x7F, 0x80, 0xFF, 0x01, 0xD5, 0x7F, 0xBD, 0x01, 0x3A, 0xFF };

    uint64_t timestamp = 9055013785192981470;
    uint32_t nBits = 137755049;
    int height = 2006251456;

    Digest32 extensionRoot = { 0x68, 0x24, 0x40, 0x88, 0x7F, 0xFF, 0xFF, 0xEA, 0x01, 0x0E, 0x80, 0x01, 0x00, 0xB5, 0x0C, 0x97, 0x80, 0x5C, 0x80, 0x00, 0x0F, 0xC7, 0xE4, 0x14, 0x80, 0x7F, 0x00, 0x00, 0x7F, 0x53, 0x80, 0x01 };

    AutolykosSolution powSolution = {
      groupElemFromBytes({  0x02, 0xAE, 0x12, 0x51, 0x2D, 0x59, 0x71, 0x58, 0x8D, 0x57, 0x1C, 0x06, 0xAD, 0x7A, 0x0D, 0x58, 0x16, 0xB6, 0x30, 0xCE, 0x6C, 0x65, 0x6F, 0x7E, 0x72, 0xD0, 0x7F, 0xBE, 0xE0, 0xBD, 0x50, 0x2A, 0x72 }),
      groupElemFromBytes({  0x03, 0x54, 0xE3, 0xD9, 0xEC, 0xC7, 0xC6, 0xA8, 0x8C, 0x6E, 0x2F, 0xB9, 0xED, 0xAB, 0xDE, 0xB8, 0x57, 0x0D, 0xF2, 0xCA, 0xA9, 0x8F, 0xB8, 0x68, 0xEB, 0xF2, 0x89, 0xFF, 0x37, 0xFE, 0x49, 0x26, 0xFF }),
      {  0x7F, 0x6E, 0xBB, 0x46, 0x01, 0xFB, 0x42, 0x7F },
      boost::multiprecision::cpp_int("115792089237316195423570985008687907852836105863100829100874297326221021636233")
    };
    std::array<uint8_t, 3> votes = {0x00, 0x00, 0x00};

    return Header(version, parentId, ADProofsRoot, stateRoot, transactionsRoot, timestamp, nBits, height, extensionRoot, powSolution, votes);
}

//generated solution should be valid
void test(AutolykosPowScheme& pow, const Header& inHeader, const boost::multiprecision::cpp_int& difficulty, uint8_t ver, boost::multiprecision::cpp_int sk, boost::multiprecision::cpp_int x) {
    auto nBits = encodeCompactBits(difficulty);
    std::cout << "ver1_test_validate_pow_5 \ntarget difficulty: " << difficulty << ", encodeCompactBits: " << nBits << std::endl;

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

    boost::multiprecision::cpp_int difficulty("109");  // take Reference value from scala
    int ver = 1;
    boost::multiprecision::cpp_int sk("14515019908231370188601243451192918149279448748425141886035264241817283415436");
    boost::multiprecision::cpp_int x("48822680901938932985022086430166125902030883897030628313547306306275831502180");

    test(powScheme, createHeader(), difficulty, ver, sk, x);

    return 0;
}
