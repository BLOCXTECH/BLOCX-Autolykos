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

//Create a Header for Test_4 
Header createHeader() {
    //We can pass the different Header for testing 
    Version version = static_cast<uint8_t>(-128);
    ModifierId parentId = {  0x08, 0x00, 0x01, 0x07, 0x0F, 0x0F, 0x08, 0x0E, 0x03, 0x06, 0x08, 0x00, 0x04, 0x05, 0x08, 0x00, 0x00, 0x00, 0x00, 0x01, 0x07, 0x0F, 0x01, 0x0F, 0x08, 0x00, 0x05, 0x01, 0x00, 0x01, 0x0A, 0x08, 0x07, 0x0F, 0x08, 0x00, 0x00, 0x0D, 0x0F, 0x0F, 0x0F, 0x05, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x07, 0x0F, 0x04, 0x06, 0x0C, 0x0F, 0x02, 0x08, 0x0F, 0x0F, 0x00, 0x01, 0x08, 0x00, 0x08, 0x00 };
    
    Digest32 ADProofsRoot = { 0x9E, 0x7F, 0xFF, 0xD6, 0xA5, 0xFF, 0xB1, 0x93, 0x25, 0x96, 0x04, 0x37, 0xFC, 0xF2, 0xC1, 0x9C, 0x71, 0x00, 0x3B, 0x01, 0x01, 0x7F, 0x91, 0x80, 0xAB, 0xCF, 0x9F, 0x3C, 0x55, 0x0B, 0x41, 0xEB };

    ADDigest stateRoot = { 0x01, 0xFF, 0xCD, 0xDF, 0xCD, 0x95, 0x80, 0x1A, 0x01, 0x5D, 0x7F, 0xEC, 0x52, 0xFB, 0xFF, 0x01, 0x00, 0x3B, 0x82, 0xFF, 0x01, 0xDC, 0xFF, 0xFF, 0x0F, 0x6C, 0x15, 0x7F, 0x86, 0x00, 0x80, 0x8A, 0xF4 };

    Digest32 transactionsRoot = { 0x23, 0x7F, 0x80, 0xFC, 0xA0, 0xE1, 0x7E, 0x49, 0xB1, 0x25, 0xA2, 0xFF, 0x80, 0x7F, 0xC8, 0x01, 0x68, 0x65, 0xFF, 0xFF, 0x7F, 0x5C, 0xFF, 0x70, 0x3C, 0xFF, 0x00, 0xFF, 0x12, 0x25, 0x36, 0x7F };

    uint64_t timestamp = 809047729808474326;
    uint32_t nBits = 139541278;
    int height = 1658165167;

    Digest32 extensionRoot = { 0x00, 0x7F, 0x7C, 0x7F, 0xC0, 0xFF, 0x7F, 0xD9, 0x91, 0x0C, 0xFF, 0x05, 0xB5, 0x01, 0xFE, 0xFF, 0x12, 0x7D, 0xFF, 0x7F, 0x63, 0xFF, 0xBA, 0xA9, 0x7F, 0x47, 0x80, 0xC0, 0x51, 0x7F, 0x01, 0x80 };

    AutolykosSolution powSolution = {
      groupElemFromBytes({ 0x02, 0xCE, 0xAE, 0x71, 0x4D, 0xDA, 0xB7, 0x2C, 0x7F, 0x04, 0x45, 0x99, 0xCA, 0x0E, 0xD4, 0x8D, 0x50, 0x57, 0x73, 0x3D, 0xB8, 0x34, 0x07, 0x03, 0x9D, 0x9D, 0x43, 0xD6, 0xD7, 0x2A, 0x08, 0xB8, 0xF7 }),
      groupElemFromBytes({ 0x02, 0xE5, 0x54, 0xF6, 0xE6, 0x6E, 0xAD, 0x39, 0x6B, 0x01, 0x66, 0x16, 0x46, 0xAE, 0x4E, 0xE6, 0x32, 0xE8, 0x6D, 0x19, 0x01, 0xD6, 0x0C, 0x9A, 0x57, 0x2B, 0x40, 0x4D, 0x66, 0xDA, 0xBF, 0x5D, 0xFE }),
      {  0x00, 0x7F, 0x80, 0x75, 0x8E, 0xF0, 0x7F, 0x00 },
      boost::multiprecision::cpp_int("115792089237316195423570985008687907852831138607262265786752770800058947135813")
    };
    std::array<uint8_t, 3> votes = {0x00, 0x00, 0x00};

    return Header(version, parentId, ADProofsRoot, stateRoot, transactionsRoot, timestamp, nBits, height, extensionRoot, powSolution, votes);
}

//generated solution should be valid
void test(AutolykosPowScheme& pow, const Header& inHeader, const boost::multiprecision::cpp_int& difficulty, uint8_t ver, boost::multiprecision::cpp_int sk, boost::multiprecision::cpp_int x) {
    auto nBits = encodeCompactBits(difficulty);
    std::cout << "ver1_test_validate_pow_4 \ntarget difficulty: " << difficulty << ", encodeCompactBits: " << nBits << std::endl;

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

    boost::multiprecision::cpp_int difficulty("115");  // take Reference value from scala
    int ver = 1;
    boost::multiprecision::cpp_int sk("104558771979517035913738200697608188017911680954129247988155216520040331596800");
    boost::multiprecision::cpp_int x("5252627376997713177989569926754314569878248635255268188944453464706364492191");

    test(powScheme, createHeader(), difficulty, ver, sk, x);

    return 0;
}
