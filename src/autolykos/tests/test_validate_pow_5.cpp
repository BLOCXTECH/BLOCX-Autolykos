#include "test.h"

//Create a Header for Test_5 
Header createHeader() {
    //We can pass the different Header for testing 
    Version version = 1;
    ModifierId parentId = {0x0B,0x07,0x00,0x03,0x09,0x08,0x00,0x00,0x0C,0x04,0x0A,0x0F,0x01,0x00,0x0C,0x00,0x08,0x00,0x00,0x00,0x0F,0x0F,0x06,0x06,0x08,0x0A,0x0C,0x03,0x00,0x01,0x08,0x00,0x0E,0x02,0x0F,0x0F,0x05,0x0F,0x08,0x00,0x07,0x0F,0x07,0x0F,0x00,0x00,0x08,0x08,0x0F,0x0F,0x0F,0x0B,0x00,0x00,0x07,0x0F,0x07,0x0F,0x0F,0x0F,0x01,0x04,0x07,0x0F};
    
    Digest32 ADProofsRoot = {0x30,0xFF,0x80,0xD9,0x58,0xFF,0x13,0x8C,0x7F,0x04,0xF1,0x80,0x00,0x7A,0x7F,0x80,0x7F,0xFF,0xA9,0x2B,0x80,0x80,0xEF,0x37,0x00,0x7F,0x01,0x42,0xF7,0x2D,0x7A,0x0F};

    ADDigest stateRoot = {0x00,0x80,0x80,0x7F,0xE8,0x18,0xB9,0x00,0xFF,0xE8,0x80,0x00,0x01,0x01,0x49,0xFC,0x80,0x2A,0x01,0x01,0xC4,0x7F,0x01,0x73,0x8C,0x80,0x01,0xF7,0x01,0x80,0x51,0x39,0x00};

    Digest32 transactionsRoot = {0x93,0xFF,0xFF,0x7F,0x77,0xA8,0x02,0x86,0x46,0xBC,0x4B,0xD1,0x42,0x2C,0xB3,0x3B,0x99,0x3A,0x7A,0x00,0x86,0x67,0x7F,0x01,0x7F,0x80,0xAE,0x00,0x80,0xF6,0x5C,0x1D};
    
    uint64_t timestamp = 3976907453172600086 ;
    uint32_t nBits =140720884  ;
    int height = 662612756;
    Digest32 extensionRoot = {0x7F,0x00,0xC6,0xFF,0x7F,0xC7,0x71,0x7F,0xFF,0xB9,0xC7,0xFF,0x7D,0xD0,0x7F,0xB0,0x01,0x8E,0x0F,0x7F,0x5C,0x7F,0x80,0x5A,0x01,0x42,0x3A,0x85,0x03,0x1F,0x52,0xFF};

    AutolykosSolution powSolution = {
      groupElemFromBytes({0x03,0x6F,0x58,0xC2,0x34,0x1E,0xAE,0x0C,0xCE,0x12,0x0F,0xE1,0x25,0xB1,0x03,0x9C,0x4C,0xD8,0xFA,0x66,0xC4,0x0F,0x4A,0x0E,0xE7,0x71,0x7B,0x35,0x52,0xA0,0x6A,0x0A,0x51}),
      groupElemFromBytes({0x03,0xFC,0x96,0x4A,0x9A,0xF8,0x68,0xA5,0xBA,0xFC,0x0D,0x75,0xF8,0x8F,0x18,0x6F,0x0E,0x12,0x72,0x40,0x80,0xED,0xE8,0xB5,0x4C,0xB4,0x96,0xFC,0xDE,0xFD,0x4A,0xA0,0x1D}),
      {0xED,0xA9,0xC2,0x12,0x33,0x80,0x77,0x80},
      boost::multiprecision::cpp_int("122491760133342738150880690487627492588512780648271126449")
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
    std::cout << "test5 \ntarget difficulty: " << difficulty << ", encodeCompactBits: " << nBits << std::endl;

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
    boost::multiprecision::cpp_int sk("69169605576096490092376220265605805450241319285675917523045521537027050830553");
    boost::multiprecision::cpp_int x("68869787710596719131045493057430891775160256662829194020451624682217966801701");

    test(powScheme, createHeader(), difficulty, ver, sk, x);


    return 0;
}
