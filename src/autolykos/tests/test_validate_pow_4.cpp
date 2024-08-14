#include "test.h"

//Create a Header for Test_4 
Header createHeader() {
    //We can pass the different Header for testing 
    Version version = 30;
    ModifierId parentId = {0x08,0x00,0x06,0x0F,0x00,0x03,0x01,0x04,0x0F,0x0F,0x0F,0x0F,0x08,0x00,0x07,0x09,0x0E,0x05,0x00,0x01,0x06,0x01,0x04,0x04,0x09,0x00,0x00,0x01,0x00,0x08,0x07,0x0F,0x00,0x01,0x0F,0x0F,0x02,0x0D,0x0F,0x0F,0x05,0x06,0x0F,0x0F,0x06,0x05,0x07,0x0F,0x08,0x00,0x0F,0x00,0x08,0x00,0x0C,0x03,0x00,0x00,0x07,0x0F,0x05,0x0C,0x00,0x00};
    
    Digest32 ADProofsRoot = {0xA1,0x8F,0x10,0x80,0x80,0x16,0x2C,0xFF,0xC9,0x01,0xE5,0x86,0xFF,0x93,0x01,0x77,0x80,0x7F,0x7F,0x01,0x9E,0xD9,0x7F,0x80,0x80,0x00,0x80,0x01,0xDD,0x1A,0xFF,0x23};

    ADDigest stateRoot = {0x00,0x00,0x92,0x7F,0xFF,0x06,0x1D,0xA7,0xFF,0x00,0x80,0xFF,0x01,0x01,0x4B,0x45,0xCD,0xFF,0x7F,0xC3,0x4E,0x20,0x24,0x7F,0x7F,0xCD,0x6E,0x00,0x00,0x6E,0x17,0xEC,0x7F};

    Digest32 transactionsRoot = {0x22,0x06,0x7F,0x7F,0x9A,0x2B,0xCE,0x9D,0x8E,0x80,0x7F,0x1F,0xF3,0x7F,0xB9,0x43,0x7F,0xFF,0x74,0x7F,0x4D,0x7F,0x9C,0x00,0x7F,0x00,0xD8,0xA4,0xEF,0xF0,0x00,0x4E};
    
    uint64_t timestamp = 6811212221348836977;
    uint32_t nBits = 545259519 ;
    int height = 2106553061;
    Digest32 extensionRoot = {0x01,0x7F,0x88,0x57,0x00,0x00,0x7E,0x80,0x75,0xC5,0x80,0xB8,0x01,0x7F,0x00,0x01,0x49,0xFF,0x8A,0x70,0x79,0x00,0xFF,0x7F,0xA8,0x35,0xFF,0xDC,0x33,0x75,0x7F,0x7F};

    AutolykosSolution powSolution = {
      groupElemFromBytes({0x02,0x11,0x78,0x46,0x24,0x05,0x70,0xCE,0x47,0x4C,0x1E,0x5E,0x04,0xEC,0x92,0xEC,0x26,0x9D,0x08,0x70,0x40,0xEE,0x5F,0x69,0x07,0xD6,0x9D,0x25,0x18,0x9A,0xD3,0x11,0xD0}),
      groupElemFromBytes({0x02,0xDE,0x1F,0xA8,0x4E,0xE7,0x8C,0x9E,0xB3,0xBC,0x68,0x62,0xAF,0x6F,0x6B,0x4B,0x65,0x83,0x8F,0x7A,0x26,0x4F,0x7B,0xDF,0xA6,0x03,0x22,0x7F,0xEC,0x69,0xC5,0x06,0x11}),
      {0x7F,0x10,0x80,0x01,0xBE,0x7F,0xAF,0x10},
      boost::multiprecision::cpp_int("181009498125408153491458133869581410991675440928163530961")
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
    std::cout << "test4 \ntarget difficulty: " << difficulty << ", encodeCompactBits: " << nBits << std::endl;

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

    boost::multiprecision::cpp_int difficulty("112");  // take Reference value from scala
    int ver = 2;
    boost::multiprecision::cpp_int sk("92261559769691867607149944528944052858294197821669536215580147782920618162971");
    boost::multiprecision::cpp_int x("49249938705938129775522981228039493013251974593850829476057460460148883720368");

    test(powScheme, createHeader(), difficulty, ver, sk, x);


    return 0;
}
