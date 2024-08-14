#include "test.h"

//Create a Header for Test_10 
Header createHeader() {
    //We can pass the different Header for testing 
    Version version = 90;
    ModifierId parentId = { 0x00,0x00,0x0E,0x0D,0x0E,0x02,0x03,0x0C,0x0F,0x0F,0x02,0x0E,0x08,0x00,0x00,0x00,0x0E,0x0B,0x07,0x0F,0x08,0x0C,0x09,0x0B,0x0F,0x0F,0x08,0x00,0x04,0x05,0x01,0x02,0x0F,0x0F,0x07,0x0F,0x05,0x06,0x00,0x01,0x00,0x00,0x03,0x06,0x00,0x01,0x0C,0x0F,0x0E,0x0C,0x00,0x01,0x0F,0x07,0x08,0x00,0x00,0x0C,0x0F,0x02,0x0B,0x0E,0x00,0x01 };
    
    Digest32 ADProofsRoot = { 0x01,0x01,0xFF,0x01,0xFF,0x63,0x94,0x00,0x1A,0x7F,0x62,0x8D,0x82,0x7F,0x01,0xDA,0x81,0xFF,0x80,0x7F,0xAE,0x94,0x00,0xFF,0x80,0x54,0x8E,0x0C,0xD9,0x86,0xD7,0x50 };

    ADDigest stateRoot = { 0x00,0xA8,0xF2,0xFF,0xD4,0xBA,0x97,0x94,0xCB,0x7F,0xFF,0x9A,0x70,0x80,0x52,0x00,0x1E,0x1E,0xA0,0xFF,0x01,0x77,0x80,0x01,0xFF,0x04,0x7F,0x80,0xAE,0x2A,0xAD,0x89,0x00 };

    Digest32 transactionsRoot = { 0x80,0x7F,0x56,0x80,0xF5,0x20,0x85,0x00,0xF2,0x3C,0x4A,0x46,0xFF,0x8D,0x7F,0x65,0x7F,0x2D,0x7F,0x80,0x52,0x00,0xF3,0x1C,0x00,0x25,0x00,0x7F,0x80,0x43,0xA8,0x21 };
    
    uint64_t timestamp = 6258372263123561560;
    uint32_t nBits = 271192215;
    int height = 957909109;
    Digest32 extensionRoot = { 0x00,0x80,0xBD,0x01,0x00,0x7F,0x01,0x30,0x74,0x01,0xFF,0xF9,0xFF,0xFF,0x01,0x01,0x58,0x01,0x80,0x1A,0x00,0xDD,0x80,0xFF,0x8F,0x89,0x7F,0x12,0x01,0x68,0x01,0x7F };

    AutolykosSolution powSolution = {
      groupElemFromBytes({ 0x02,0x5F,0x44,0x12,0xE0,0x0D,0xC9,0xB6,0x4F,0xE1,0xC2,0x3D,0x7A,0x69,0x9C,0xA4,0x0A,0x7E,0xC8,0x15,0x14,0x1F,0x9A,0x1B,0xAD,0xD6,0xFC,0x04,0x77,0xFB,0x7A,0xB6,0xD4 }),
      groupElemFromBytes({ 0x03,0x2D,0x1D,0xAD,0xBB,0xE2,0xFE,0xBB,0xE8,0xD3,0x0E,0x0B,0x9B,0xE2,0x07,0xF5,0x1C,0xCE,0x65,0xC1,0x44,0x23,0x21,0x3C,0x6C,0x4A,0x79,0x1A,0x46,0x72,0xB4,0x6F,0xBC }),
      { 0xFF,0x47,0xE5,0xEA,0x7F,0xB1,0xC3,0xA1 },
      boost::multiprecision::cpp_int("132415701511698402216562564534306124040431235455552767681")
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
    std::cout << "test10 \ntarget difficulty: " << difficulty << ", encodeCompactBits: " << nBits << std::endl;

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

    boost::multiprecision::cpp_int difficulty("111");  // take Reference value from scala
    int ver = 2;
    boost::multiprecision::cpp_int sk("73475880220784243833095913234373784353139215996130597469985632026512121041018");
    boost::multiprecision::cpp_int x("88651153778064224764807998926072833969892701576797747811972423943079869531326");

    test(powScheme, createHeader(), difficulty, ver, sk, x);


    return 0;
}
