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

//Create a Header for Test_6 
Header createHeader() {
    //We can pass the different Header for testing 
    Version version = 0;
    ModifierId parentId = { 0x02, 0x08, 0x0F, 0x0F, 0x00, 0x01, 0x00, 0x01, 0x0D, 0x08, 0x08, 0x00, 0x07, 0x02, 0x00, 0x00, 0x06, 0x09, 0x0F, 0x0A, 0x00, 0x01, 0x07, 0x0F, 0x00, 0x0A, 0x0F, 0x0B, 0x07, 0x0F, 0x08, 0x00, 0x0F, 0x07, 0x0F, 0x01, 0x0F, 0x0F, 0x0F, 0x02, 0x07, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x09, 0x0B, 0x07, 0x0F, 0x00, 0x01, 0x06, 0x03, 0x05, 0x0E, 0x0A, 0x02, 0x01, 0x05, 0x04, 0x03, 0x00, 0x00 };
    
    Digest32 ADProofsRoot = { 0xDC, 0x01, 0x80, 0x01, 0x00, 0xB4, 0x00, 0x01, 0x64, 0xFF, 0x7F, 0x36, 0x2E, 0x00, 0x2E, 0xE8, 0x06, 0x80, 0xFF, 0x80, 0x00, 0x7F, 0x01, 0x8F, 0x00, 0x27, 0x01, 0x01, 0x01, 0x01, 0xBE, 0x5C };

    ADDigest stateRoot = { 0x80, 0x65, 0x01, 0x00, 0xDF, 0x86, 0x01, 0x00, 0x00, 0x6D, 0x80, 0xFF, 0x01, 0x80, 0x80, 0x7F, 0x80, 0xFC, 0x00, 0x80, 0x01, 0x27, 0xA3, 0x6F, 0x7F, 0x01, 0x00, 0x81, 0xFF, 0x80, 0x80, 0x92, 0x01 };

    Digest32 transactionsRoot = { 0x80, 0xE9, 0x80, 0xD1, 0x80, 0x00, 0x7F, 0x7F, 0xDB, 0x7F, 0x27, 0xFF, 0x7C, 0xC7, 0x92, 0x00, 0x32, 0x01, 0xFF, 0x7F, 0x43, 0x9F, 0xE0, 0x0E, 0xB9, 0xA3, 0x3E, 0x5E, 0x76, 0x2B, 0xBE, 0x43 };

    uint64_t timestamp = 1368429437220605363;
    uint32_t nBits = 269197888;
    int height = 1135613540;

    Digest32 extensionRoot = { 0xFF, 0xFF, 0x21, 0x80, 0xFF, 0xFF, 0x2E, 0x06, 0xFF, 0x7F, 0xC8, 0x12, 0x40, 0x2D, 0x00, 0x80, 0x66, 0xA5, 0x80, 0x01, 0x01, 0x01, 0xA2, 0x01, 0x77, 0x96, 0xC2, 0x00, 0x01, 0xB7, 0x01, 0xDB };

    AutolykosSolution powSolution = {
      groupElemFromBytes({  0x03, 0xFD, 0x7C, 0xA4, 0xC5, 0xE1, 0x59, 0x01, 0xBB, 0xD0, 0x12, 0xED, 0x4B, 0xAD, 0xBE, 0xEA, 0xE9, 0xFA, 0xE3, 0x84, 0xE7, 0x1B, 0x83, 0xE7, 0x69, 0x63, 0xED, 0x83, 0xC7, 0x2F, 0x09, 0xC9, 0x98 }),
      groupElemFromBytes({  0x03, 0x0F, 0xEA, 0xB5, 0x10, 0xBD, 0xCA, 0xFF, 0x58, 0x8A, 0x4E, 0xEC, 0xBB, 0x00, 0x3E, 0x3D, 0x7B, 0x33, 0x0A, 0x19, 0x6E, 0x81, 0x38, 0x63, 0x0F, 0x8F, 0xF9, 0xEE, 0xAA, 0x96, 0x4B, 0x16, 0x26 }),
      {  0x00, 0x8C, 0xC5, 0x00, 0x00, 0x01, 0x6B, 0x01 },
      boost::multiprecision::cpp_int("2916758703913884152390259868586266162")
    };
    std::array<uint8_t, 3> votes = {0x00, 0x00, 0x00};

    return Header(version, parentId, ADProofsRoot, stateRoot, transactionsRoot, timestamp, nBits, height, extensionRoot, powSolution, votes);
}


//generated solution should be valid
void test(AutolykosPowScheme& pow, const Header& inHeader, const boost::multiprecision::cpp_int& difficulty, uint8_t ver, boost::multiprecision::cpp_int sk, boost::multiprecision::cpp_int x) {
    auto nBits = encodeCompactBits(difficulty);
    std::cout << "ver1_test_validate_pow_6 \ntarget difficulty: " << difficulty << ", encodeCompactBits: " << nBits << std::endl;

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

    boost::multiprecision::cpp_int difficulty("119");  // take Reference value from scala
    int ver = 1;
    boost::multiprecision::cpp_int sk("102132930903235831602020955511238151492729799147145689807899246162053237782799");
    boost::multiprecision::cpp_int x("26065000453446850950879069896314433513651108888543229952129260576220437855157");

    test(powScheme, createHeader(), difficulty, ver, sk, x);

    return 0;
}
