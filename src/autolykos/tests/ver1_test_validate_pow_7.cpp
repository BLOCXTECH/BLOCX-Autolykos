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

//Create a Header for Test_7 
Header createHeader() {
    //We can pass the different Header for testing 
    Version version = 100;
    ModifierId parentId = { 0x0A, 0x00, 0x00, 0x00, 0x0D, 0x0F, 0x00, 0x01, 0x00, 0x09, 0x00, 0x00, 0x06, 0x05, 0x00, 0x00, 0x00, 0x00, 0x01, 0x03, 0x0A, 0x0D, 0x0F, 0x0F, 0x00, 0x00, 0x08, 0x00, 0x08, 0x00, 0x0F, 0x0F, 0x04, 0x0E, 0x01, 0x01, 0x00, 0x01, 0x00, 0x00, 0x0D, 0x06, 0x07, 0x0F, 0x07, 0x0F, 0x08, 0x00, 0x07, 0x08, 0x04, 0x03, 0x0E, 0x0C, 0x07, 0x0F, 0x00, 0x00, 0x09, 0x01, 0x00, 0x00, 0x0C, 0x0E };
    
    Digest32 ADProofsRoot = { 0xFF, 0x8E, 0x7F, 0x65, 0x7F, 0xFF, 0x00, 0x2C, 0x8C, 0x88, 0x80, 0x87, 0x00, 0x00, 0x01, 0x84, 0x7F, 0xA5, 0x16, 0x80, 0x7F, 0x7F, 0x7F, 0x80, 0xF7, 0x00, 0x80, 0x88, 0x80, 0x14, 0x83, 0x7F };

    ADDigest stateRoot = { 0x1D, 0x7F, 0x48, 0xE4, 0xC6, 0x89, 0x08, 0x80, 0x1D, 0x01, 0x64, 0xFB, 0x91, 0x35, 0x00, 0x7F, 0x5E, 0x01, 0x26, 0xFD, 0xFF, 0xAF, 0xB2, 0x53, 0xD2, 0x00, 0xA8, 0xFF, 0x00, 0x8A, 0x80, 0x49, 0x80 };

    Digest32 transactionsRoot = { 0x7F, 0xB7, 0x80, 0xCE, 0x35, 0x00, 0x67, 0xA3, 0x31, 0x3C, 0x08, 0x80, 0x80, 0xE7, 0x83, 0x58, 0xFF, 0x80, 0x7C, 0xEC, 0x62, 0xE9, 0x2C, 0x7F, 0x14, 0x7F, 0xAF, 0xF4, 0xBB, 0xED, 0x01, 0x01 };

    uint64_t timestamp = 3206430652919137913;
    uint32_t nBits = 545259519;
    int height = 620112750;

    Digest32 extensionRoot = { 0x00, 0x00, 0x00, 0x00, 0x19, 0x00, 0x01, 0x66, 0x01, 0x15, 0x70, 0x10, 0x00, 0x7F, 0x00, 0x80, 0xD7, 0xAC, 0x9F, 0xFF, 0x96, 0x72, 0x57, 0x00, 0x00, 0x8C, 0x80, 0x78, 0x64, 0xFF, 0x7F, 0xB2 };

    AutolykosSolution powSolution = {
      groupElemFromBytes({  0x03, 0x54, 0xD2, 0x2A, 0x28, 0xC5, 0xB9, 0xDE, 0xA0, 0xF0, 0x53, 0xE6, 0xF1, 0xDC, 0xC1, 0xC0, 0x34, 0x33, 0x00, 0x36, 0xCD, 0xA4, 0xDC, 0x42, 0xE9, 0x0E, 0xD1, 0x7E, 0x07, 0x4B, 0x6E, 0x07, 0x1D }),
      groupElemFromBytes({  0x03, 0xF6, 0x46, 0x24, 0xE1, 0x72, 0xF9, 0x0B, 0x37, 0xC6, 0xB2, 0xD3, 0x4F, 0xBE, 0xE6, 0x57, 0xB4, 0x12, 0xB0, 0x8C, 0x40, 0xDC, 0x07, 0xF9, 0x04, 0xA5, 0xCB, 0xD3, 0xDF, 0xD8, 0xB5, 0xF2, 0xB3 }),
      {  0xA5, 0xA5, 0x80, 0x3B, 0xE6, 0x00, 0x00, 0xFF },
      boost::multiprecision::cpp_int("115792089237316195423570985008687907852837564279074904382605163141518161494336")
    };
    std::array<uint8_t, 3> votes = {0x00, 0x00, 0x00};

    return Header(version, parentId, ADProofsRoot, stateRoot, transactionsRoot, timestamp, nBits, height, extensionRoot, powSolution, votes);
}


//generated solution should be valid
void test(AutolykosPowScheme& pow, const Header& inHeader, const boost::multiprecision::cpp_int& difficulty, uint8_t ver, boost::multiprecision::cpp_int sk, boost::multiprecision::cpp_int x) {
    auto nBits = encodeCompactBits(difficulty);
    std::cout << "ver1_test_validate_pow_7 \ntarget difficulty: " << difficulty << ", encodeCompactBits: " << nBits << std::endl;

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

    boost::multiprecision::cpp_int difficulty("104");  // take Reference value from scala
    int ver = 1;
    boost::multiprecision::cpp_int sk("26595546301240732557027192172229276914925602675992781284198650120155824660453");
    boost::multiprecision::cpp_int x("57425019631828256221608689269498867365445650580295516173016953127067555810668");

    test(powScheme, createHeader(), difficulty, ver, sk, x);

    return 0;
}
