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

//Create a Header for Test_8 
Header createHeader() {
    //We can pass the different Header for testing 
    Version version = 35;
    ModifierId parentId = { 0x00, 0x01, 0x00, 0x01, 0x07, 0x0F, 0x0A, 0x05, 0x0D, 0x0E, 0x07, 0x00, 0x06, 0x06, 0x07, 0x0F, 0x0D, 0x05, 0x0F, 0x0F, 0x0F, 0x0F, 0x00, 0x01, 0x08, 0x00, 0x07, 0x0F, 0x0F, 0x0F, 0x00, 0x00, 0x08, 0x00, 0x03, 0x0F, 0x00, 0x00, 0x00, 0x00, 0x07, 0x0F, 0x00, 0x08, 0x06, 0x08, 0x0C, 0x05, 0x0F, 0x0F, 0x02, 0x09, 0x0A, 0x0F, 0x0D, 0x0E, 0x0D, 0x0D, 0x08, 0x00, 0x0B, 0x0C, 0x09, 0x09 };
    
    Digest32 ADProofsRoot = { 0x80, 0x80, 0x7F, 0x6F, 0x00, 0x45, 0x7F, 0x80, 0x01, 0x7F, 0x5E, 0x01, 0x80, 0xFF, 0xF0, 0x80, 0x47, 0x00, 0x89, 0x80, 0x00, 0x00, 0x2C, 0x88, 0xBE, 0xFF, 0xE5, 0x80, 0xFF, 0x7F, 0x9F, 0xE5 };

    ADDigest stateRoot = { 0xF2, 0xB3, 0x80, 0x01, 0x63, 0x10, 0x3D, 0x01, 0x80, 0x00, 0xCE, 0x68, 0x01, 0x80, 0x00, 0x01, 0x01, 0xD5, 0xFF, 0x00, 0xC5, 0xFF, 0x00, 0x82, 0x59, 0x7F, 0x9E, 0x3B, 0x61, 0xF7, 0x79, 0x80, 0x80 };

    Digest32 transactionsRoot = { 0x87, 0x7F, 0x36, 0x00, 0x80, 0x18, 0x7F, 0x98, 0x21, 0x30, 0x80, 0x50, 0x34, 0x7F, 0x7F, 0x3C, 0x9F, 0x00, 0x01, 0x80, 0xFF, 0xD0, 0x8B, 0x80, 0x5F, 0x80, 0xE4, 0x7F, 0x15, 0x2F, 0x7F, 0x7F };

    uint64_t timestamp = 4260542754824615315;
    uint32_t nBits = 545259519;
    int height = 239422548;

    Digest32 extensionRoot = { 0x64, 0x05, 0x0F, 0x3D, 0x7A, 0x00, 0xFF, 0xC0, 0x80, 0x80, 0x80, 0x46, 0x21, 0xFF, 0xFF, 0x3A, 0x09, 0x8F, 0xFF, 0x00, 0x05, 0x37, 0xFF, 0x2A, 0x58, 0xFF, 0x23, 0xD0, 0x12, 0x01, 0x2E, 0x7F };

    AutolykosSolution powSolution = {
      groupElemFromBytes({  0x02, 0x41, 0x40, 0x36, 0xAA, 0xEE, 0xDA, 0xD7, 0xF7, 0x79, 0x88, 0x6F, 0x03, 0x35, 0x4B, 0x48, 0x0A, 0xAD, 0x49, 0xF5, 0x48, 0xF7, 0x59, 0xC2, 0x49, 0xBC, 0xBF, 0xF5, 0x77, 0xCC, 0xC6, 0xA0, 0xD9 }),
      groupElemFromBytes({  0x02, 0x8B, 0xFA, 0x2D, 0xA8, 0x35, 0x3A, 0x6E, 0x67, 0x34, 0xA0, 0x0E, 0x90, 0xD2, 0x85, 0x65, 0x78, 0xC5, 0x83, 0xBD, 0x29, 0x91, 0xCE, 0xED, 0xEB, 0x8F, 0xAE, 0xA9, 0xB4, 0xB1, 0x46, 0xE2, 0x6A }),
      {  0x13, 0x97, 0x01, 0x00, 0x64, 0xB6, 0x2E, 0x08 },
      boost::multiprecision::cpp_int("115792089237316195423570985008687907852826476447774053856303849527058510563837")
    };
    std::array<uint8_t, 3> votes = {0x00, 0x00, 0x00};

    return Header(version, parentId, ADProofsRoot, stateRoot, transactionsRoot, timestamp, nBits, height, extensionRoot, powSolution, votes);
}


//generated solution should be valid
void test(AutolykosPowScheme& pow, const Header& inHeader, const boost::multiprecision::cpp_int& difficulty, uint8_t ver, boost::multiprecision::cpp_int sk, boost::multiprecision::cpp_int x) {
    auto nBits = encodeCompactBits(difficulty);
    std::cout << "ver1_test_validate_pow_8 \ntarget difficulty: " << difficulty << ", encodeCompactBits: " << nBits << std::endl;

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

    boost::multiprecision::cpp_int difficulty("100");  // take Reference value from scala
    int ver = 1;
    boost::multiprecision::cpp_int sk("88054573508983527710700293561857814629606126545344898069088665932514234881704");
    boost::multiprecision::cpp_int x("38436916569976093198975499038192967540553129112813125263725902353170994275577");

    test(powScheme, createHeader(), difficulty, ver, sk, x);

    return 0;
}
