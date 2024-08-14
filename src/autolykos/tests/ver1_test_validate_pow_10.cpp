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

//Create a Header for Test_10 
Header createHeader() {
    //We can pass the different Header for testing 
    Version version = static_cast<uint8_t>(-76);

    ModifierId parentId = { 0x00, 0x01, 0x03, 0x04, 0x00, 0x01, 0x0E, 0x07, 0x0F, 0x0F, 0x07, 0x0F, 0x06, 0x03, 0x07, 0x0F, 0x04, 0x09, 0x00, 0x01, 0x0A, 0x09, 0x0C, 0x08, 0x08, 0x00, 0x02, 0x07, 0x07, 0x0F, 0x0F, 0x0F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0C, 0x06, 0x09, 0x08, 0x0F, 0x0F, 0x0B, 0x02, 0x00, 0x01, 0x00, 0x01, 0x04, 0x0B, 0x00, 0x00, 0x0F, 0x0F, 0x0F, 0x0F, 0x00, 0x00, 0x07, 0x0F, 0x04, 0x07 };
    
    Digest32 ADProofsRoot = { 0xBE, 0x85, 0x80, 0x76, 0x01, 0x00, 0x44, 0x97, 0x78, 0xC1, 0x7F, 0x00, 0xAD, 0x7F, 0x00, 0xFF, 0x00, 0xBB, 0xFA, 0xFF, 0x00, 0x80, 0x10, 0x7F, 0x80, 0x80, 0x45, 0x00, 0xFF, 0x02, 0xFF, 0x01 };

    ADDigest stateRoot = { 0x1B, 0x01, 0x01, 0x53, 0x01, 0x84, 0xC8, 0xF8, 0x22, 0x7F, 0x4B, 0xD0, 0x96, 0x7F, 0x7F, 0x01, 0xFF, 0x09, 0xB5, 0x80, 0x00, 0x7F, 0x5D, 0x72, 0x51, 0x01, 0x7F, 0xFF, 0xC8, 0x5F, 0x7F, 0x01, 0x58 };

    Digest32 transactionsRoot = { 0x00, 0xF7, 0xDC, 0x7F, 0x7E, 0xFD, 0x00, 0xC4, 0x00, 0x27, 0x84, 0x14, 0x01, 0x01, 0x3B, 0x19, 0xAC, 0xD9, 0x1C, 0x80, 0xFF, 0xD4, 0x00, 0xFF, 0x00, 0x80, 0xFF, 0xDC, 0x01, 0xFF, 0x01, 0x00 };

    uint64_t timestamp = 7653876961975493426;
    uint32_t nBits = 271593346;
    int height = 277360709;

    Digest32 extensionRoot = { 0x60, 0x7E, 0x80, 0xA3, 0x01, 0xFF, 0x05, 0x0E, 0x80, 0x7F, 0xEC, 0x01, 0xBF, 0x7F, 0x88, 0x80, 0x7F, 0x00, 0xC2, 0xE3, 0xAC, 0x01, 0x2A, 0x01, 0xFF, 0x80, 0x3D, 0x9F, 0x75, 0x50, 0x76, 0x80 };

    AutolykosSolution powSolution = {
      groupElemFromBytes({  0x03, 0x90, 0xF0, 0x4C, 0x51, 0xC7, 0xDF, 0x26, 0xD3, 0x9F, 0x70, 0x74, 0x25, 0x9B, 0x7F, 0x49, 0x77, 0x39, 0x12, 0x29, 0x34, 0x23, 0x68, 0xA5, 0x73, 0xDB, 0x84, 0xBE, 0x69, 0xB6, 0x7D, 0x26, 0xCF }),
      groupElemFromBytes({  0x02, 0x89, 0x8E, 0x21, 0x98, 0x1B, 0x24, 0xB2, 0x01, 0x78, 0x0C, 0x2C, 0x3D, 0x3F, 0x57, 0x04, 0x4B, 0xCF, 0x24, 0x4C, 0x0A, 0x7E, 0x28, 0x5B, 0xAA, 0xB3, 0x7E, 0x25, 0x67, 0x0B, 0x9E, 0xF3, 0x7C }),
      {  0x01, 0x97, 0x90, 0xFF, 0x01, 0x8F, 0xEE, 0x5C },
      boost::multiprecision::cpp_int("115792089237316195423570985008687907852801101140289915774856810978213002905037")
    };
    std::array<uint8_t, 3> votes = {0x00, 0x00, 0x00};

    return Header(version, parentId, ADProofsRoot, stateRoot, transactionsRoot, timestamp, nBits, height, extensionRoot, powSolution, votes);
}


//generated solution should be valid
void test(AutolykosPowScheme& pow, const Header& inHeader, const boost::multiprecision::cpp_int& difficulty, uint8_t ver, boost::multiprecision::cpp_int sk, boost::multiprecision::cpp_int x) {
    auto nBits = encodeCompactBits(difficulty);
    std::cout << "ver1_test_validate_pow_10 \ntarget difficulty: " << difficulty << ", encodeCompactBits: " << nBits << std::endl;

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
    boost::multiprecision::cpp_int sk("48749360964100754124112212176577611097409110580285973033171580145521825523864");
    boost::multiprecision::cpp_int x("76334253954892081367022543771455971366284343669602416500909959358950273518168");

    test(powScheme, createHeader(), difficulty, ver, sk, x);

    return 0;
}
