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

//Create a Header for Test_1 
Header createHeader() {
    //We can pass the different Header for testing 
    Version version = 124;
    ModifierId parentId = { 0x08, 0x0B, 0x08, 0x00, 0x07, 0x0C, 0x07, 0x0F, 0x0A, 0x05, 0x0F, 0x07, 0x00, 0x01, 0x07, 0x0F, 0x0F, 0x0A, 0x00, 0x00, 0x07, 0x0F, 0x0D, 0x04, 0x00, 0x01, 0x0B, 0x05, 0x07, 0x0F, 0x0A, 0x0C, 0x07, 0x0F, 0x00, 0x00, 0x08, 0x00, 0x07, 0x0B, 0x0F, 0x03, 0x00, 0x01, 0x03, 0x03, 0x00, 0x01, 0x07, 0x0F, 0x07, 0x0F, 0x08, 0x00, 0x00, 0x00, 0x00, 0x07, 0x06, 0x03, 0x07, 0x0F, 0x00, 0x00 };
    
    Digest32 ADProofsRoot = {  0x76, 0x80, 0x00, 0x72, 0x91, 0x77, 0x04, 0x80, 0x01, 0x1E, 0x00, 0x7F, 0xAD, 0x66, 0xFF, 0x7E, 0x10, 0x48, 0xC8, 0x01, 0xE1, 0xFF, 0x1F, 0xFF, 0xCC, 0x80, 0x60, 0xE4, 0x0D, 0xAF, 0x68, 0x7A };

    ADDigest stateRoot = {  0x00, 0x3B, 0x80, 0xDE, 0x80, 0xFF, 0x08, 0x66, 0xFF, 0x01, 0x30, 0x00, 0x85, 0x80, 0xD2, 0xC9, 0x00, 0x01, 0x67, 0x80, 0x01, 0xFF, 0xE5, 0x80, 0x00, 0xBA, 0x19, 0x04, 0x01, 0xAF, 0xFF, 0x80, 0xFF };

    Digest32 transactionsRoot = { 0xFA, 0x80, 0x68, 0x01, 0xB4, 0x70, 0x01, 0x3B, 0x80, 0x12, 0x6E, 0x7F, 0x00, 0x01, 0x91, 0x2B, 0xD9, 0x4B, 0x01, 0xF4, 0x00, 0xF9, 0x60, 0x01, 0x80, 0x69, 0x96, 0x7F, 0x01, 0x00, 0x7F, 0xFF };
    
    uint64_t timestamp = 8487956500612830582;
    uint32_t nBits = 139117612;
    int height = 482839614;

    Digest32 extensionRoot = { 0x54, 0x7F, 0xC3, 0xB8, 0x80, 0x80, 0x9A, 0xD8, 0x01, 0x00, 0xA6, 0x01, 0x7F, 0x01, 0x88, 0xF3, 0x00, 0x0F, 0xCF, 0xC5, 0x7B, 0x14, 0xFF, 0xD0, 0x05, 0xFF, 0xD4, 0xA6, 0x2F, 0x01, 0x48, 0x1B };

    AutolykosSolution powSolution = {
      groupElemFromBytes({ 0x03, 0x67, 0x3D, 0x30, 0x84, 0x6D, 0xFC, 0x02, 0xA2, 0x56, 0x28, 0x63, 0xE3, 0x06, 0x00, 0x5A, 0x6E, 0x40, 0x1F, 0xAB, 0xB7, 0xD8, 0x11, 0x17, 0xDB, 0xB2, 0xF3, 0x02, 0xA9, 0x18, 0x52, 0xE7, 0x6F }),
      groupElemFromBytes({ 0x02, 0xDF, 0xE7, 0x5D, 0xE4, 0x63, 0x26, 0x3D, 0x8D, 0x98, 0xC0, 0x7F, 0x76, 0xFB, 0x56, 0x68, 0x79, 0x9E, 0xA2, 0xAE, 0x89, 0xA5, 0x6E, 0xB6, 0xEB, 0xF5, 0x8C, 0x9D, 0xBB, 0x97, 0x14, 0xE5, 0x83 }),
      { 0xFF, 0x7F, 0x80, 0xF4, 0x51, 0x18, 0xB8, 0x7F },
      boost::multiprecision::cpp_int("115792089237316195423570985008687907852837564279074904382596277580756921012439")
    };
    std::array<uint8_t, 3> votes = {0x00, 0x00, 0x00};

    return Header(version, parentId, ADProofsRoot, stateRoot, transactionsRoot, timestamp, nBits, height, extensionRoot, powSolution, votes);
}

//generated solution should be valid
void test(AutolykosPowScheme& pow, const Header& inHeader, const boost::multiprecision::cpp_int& difficulty, uint8_t ver) {
    auto nBits = encodeCompactBits(difficulty);
    std::cout << "ver1_randomSecret \ntarget difficulty: " << difficulty << ", encodeCompactBits: " << nBits << std::endl;

    printHeader(inHeader); 
    Header h = inHeader;
    h.nBits = nBits;
    h.version = ver;

    auto sk = randomSecret();
    auto x = randomSecret();

    std::cout << "sk: " << sk << ", x: " << x << std::endl;

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

    boost::multiprecision::cpp_int difficulty("100");  // take Reference value from scala
    int ver = 1;

    test(powScheme, createHeader(), difficulty, ver);

    return 0;
}
