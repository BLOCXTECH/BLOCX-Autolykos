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

//Create a Header for Test_9
Header createHeader() {
    //We can pass the different Header for testing 
    Version version = 45;
    ModifierId parentId = { 0x00, 0x00, 0x00, 0x01, 0x07, 0x0F, 0x0D, 0x0B, 0x01, 0x01, 0x0F, 0x0F, 0x07, 0x02, 0x05, 0x08, 0x01, 0x0A, 0x0A, 0x02, 0x09, 0x02, 0x01, 0x03, 0x07, 0x0D, 0x00, 0x09, 0x0F, 0x0F, 0x01, 0x0A, 0x00, 0x00, 0x0B, 0x0E, 0x00, 0x01, 0x0A, 0x07, 0x0C, 0x09, 0x0E, 0x0E, 0x07, 0x04, 0x0A, 0x0A, 0x08, 0x00, 0x07, 0x02, 0x0C, 0x0D, 0x09, 0x06, 0x00, 0x00, 0x09, 0x03, 0x0E, 0x0A, 0x00, 0x01 };
    
    Digest32 ADProofsRoot = { 0x1A, 0x80, 0xD7, 0x4C, 0x01, 0x7F, 0xD3, 0x57, 0x9D, 0x69, 0x01, 0x00, 0x01, 0x80, 0x01, 0x7F, 0x00, 0x82, 0x3D, 0x53, 0xA9, 0x80, 0x80, 0x7A, 0x84, 0x1C, 0x9A, 0x67, 0x80, 0xFF, 0x6D, 0x06 };

    ADDigest stateRoot = { 0xEE, 0x80, 0x00, 0xF9, 0x7F, 0x40, 0x00, 0xFF, 0x7F, 0x70, 0xDE, 0x01, 0x00, 0x4A, 0xFE, 0xFF, 0x7F, 0x80, 0xE3, 0x00, 0x80, 0xB7, 0x01, 0x00, 0x01, 0xFF, 0x5A, 0x26, 0xC3, 0x69, 0xE2, 0x80, 0x37 };

    Digest32 transactionsRoot = { 0xFA, 0x58, 0x8E, 0x9A, 0x01, 0x01, 0x1C, 0x3C, 0xC2, 0x21, 0x69, 0x7F, 0x00, 0x01, 0xA4, 0x7F, 0x01, 0x91, 0x73, 0x01, 0xFF, 0x6E, 0x80, 0x4A, 0xB9, 0x80, 0x7F, 0x00, 0xE6, 0xFF, 0x40, 0x00 };

    uint64_t timestamp = 7861521261107479627;
    uint32_t nBits = 545256847;
    int height = 434927215;

    Digest32 extensionRoot = { 0x01, 0xA8, 0x23, 0x02, 0xFF, 0x00, 0x80, 0xFF, 0x01, 0x8A, 0x00, 0x80, 0xFF, 0x80, 0x1E, 0x70, 0x00, 0x00, 0xB6, 0x01, 0x80, 0xBE, 0x26, 0x01, 0x8F, 0x51, 0xDD, 0x34, 0x1B, 0x7F, 0x7F, 0x6D };

    AutolykosSolution powSolution = {
      groupElemFromBytes({  0x02, 0x47, 0x22, 0xAD, 0x00, 0x0B, 0x77, 0x77, 0x57, 0x55, 0xC1, 0xB2, 0xF9, 0xC9, 0x8D, 0xB9, 0x65, 0xAB, 0xEA, 0x93, 0xCE, 0x91, 0x50, 0x39, 0x61, 0x3F, 0xFE, 0xEF, 0x7F, 0x32, 0xEB, 0x60, 0xC4 }),
      groupElemFromBytes({  0x02, 0xB9, 0xCA, 0x90, 0xBC, 0xCF, 0x29, 0x49, 0x3C, 0xBB, 0xF8, 0xA7, 0x25, 0xE4, 0x6E, 0xFD, 0x43, 0xA8, 0x5B, 0xBB, 0xCD, 0x9C, 0x0A, 0x78, 0x02, 0x2A, 0x7C, 0xB7, 0x11, 0xA1, 0x25, 0x5A, 0x53 }),
      {  0x80, 0xB0, 0xBE, 0x00, 0x00, 0x00, 0x7F, 0xA1 },
      boost::multiprecision::cpp_int("745282638220159050899023312030265894769432039268987360604284252959914867089")
    };
    std::array<uint8_t, 3> votes = {0x00, 0x00, 0x00};

    return Header(version, parentId, ADProofsRoot, stateRoot, transactionsRoot, timestamp, nBits, height, extensionRoot, powSolution, votes);
}


//generated solution should be valid
void test(AutolykosPowScheme& pow, const Header& inHeader, const boost::multiprecision::cpp_int& difficulty, uint8_t ver, boost::multiprecision::cpp_int sk, boost::multiprecision::cpp_int x) {
    auto nBits = encodeCompactBits(difficulty);
    std::cout << "ver1_test_validate_pow_9 \ntarget difficulty: " << difficulty << ", encodeCompactBits: " << nBits << std::endl;

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

    boost::multiprecision::cpp_int difficulty("102");  // take Reference value from scala
    int ver = 1;
    boost::multiprecision::cpp_int sk("47681113441105064129816611021071677070429157927167545643570692368494932919740");
    boost::multiprecision::cpp_int x("106629433318755726920393467150035696380326218729968030360533232932393833683991");

    test(powScheme, createHeader(), difficulty, ver, sk, x);

    return 0;
}
