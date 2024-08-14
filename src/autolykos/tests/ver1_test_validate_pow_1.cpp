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
    Version version = static_cast<uint8_t>(-16);
    ModifierId parentId = { 0x00, 0x01, 0x00, 0x01, 0x08, 0x00, 0x03, 0x07, 0x07, 0x05, 0x0d, 0x03, 0x08, 0x00, 0x00, 0x0e, 0x07, 0x0f, 0x05, 0x0d, 0x07, 0x01, 0x02, 0x06, 0x0c, 0x01, 0x0f, 0x0f, 0x0c, 0x03, 0x07, 0x0f, 0x0b, 0x0b, 0x00, 0x00, 0x08, 0x00, 0x00, 0x01, 0x00, 0x01, 0x00, 0x00, 0x09, 0x05, 0x07, 0x0f, 0x07, 0x0f, 0x08, 0x00, 0x0b, 0x05, 0x0d, 0x0d, 0x0f, 0x0f, 0x0f, 0x0f, 0x00, 0x01, 0x0f, 0x0f };
    
    Digest32 ADProofsRoot = { 0x01, 0x01, 0xcd, 0xff, 0x80, 0x80, 0x5a, 0x49, 0xdb, 0x29, 0xbd, 0xf4, 0x80, 0x01, 0x7f, 0xbf, 0xc7, 0x8c, 0x01, 0x31, 0xc8, 0x01, 0x00, 0xd9, 0x7f, 0x4d, 0xd2, 0x01, 0x62, 0xff, 0x6f, 0xff };

    ADDigest stateRoot = { 0x7f, 0x03, 0x80, 0x80, 0x80, 0xff, 0x80, 0x80, 0xff, 0xb6, 0x7f, 0xe8, 0x00, 0xff, 0x4c, 0x01, 0x7f, 0xea, 0x80, 0x01, 0xd7, 0x01, 0x80, 0xff, 0x90, 0x86, 0x50, 0x7f, 0xfc, 0x01, 0x80, 0x9d, 0xff };

    Digest32 transactionsRoot = { 0x01, 0x40, 0xff, 0x39, 0xff, 0x80, 0x7f, 0xdb, 0x82, 0x01, 0xaf, 0x00, 0x80, 0x01, 0x01, 0x58, 0x95, 0x7f, 0x11, 0xa6, 0x7f, 0xb9, 0x63, 0x7f, 0x6e, 0x7f, 0x7f, 0x00, 0x55, 0x01, 0xcf, 0x0f };
    
    uint64_t timestamp = 8912503165165954297;
    uint32_t nBits = 545259519;
    int height = 1471637252;
    Digest32 extensionRoot = { 0xb1, 0x65, 0x24, 0x42, 0x01, 0x6d, 0x31, 0x80, 0x80, 0x7f, 0x9c, 0x7f, 0xff, 0xd4, 0x80, 0xff, 0x45, 0xbd, 0xef, 0xff, 0xd5, 0x25, 0x7f, 0x21, 0xa4, 0x01, 0x00, 0x7f, 0xff, 0x36, 0x01, 0x8b };

    AutolykosSolution powSolution = {
      groupElemFromBytes({ 0x03, 0x6d, 0x32, 0x6d, 0x33, 0xf9, 0x1c, 0x48, 0xbe, 0xc4, 0xe6, 0x9c, 0x14, 0x78, 0xd7, 0x62, 0x9b, 0x4c, 0x21, 0x18, 0x2a, 0xf8, 0xcd, 0x24, 0xf9, 0x5c, 0xa3, 0x10, 0x05, 0x78, 0x82, 0x98, 0x9c }),
      groupElemFromBytes({ 0x03, 0xec, 0x0d, 0xfd, 0x9a, 0xe7, 0x88, 0xbe, 0xc3, 0x2e, 0xfb, 0xb8, 0xd2, 0x9d, 0xb4, 0xe3, 0x07, 0xd9, 0x92, 0x30, 0x51, 0x66, 0x23, 0xe4, 0x3b, 0x6f, 0xed, 0x3d, 0x92, 0x7e, 0xc4, 0x46, 0x51 }),
      { 0xed, 0x07, 0xff, 0x97, 0xfc, 0x98, 0xc4, 0x9d },
      boost::multiprecision::cpp_int("115792089237316195423570985008687907852837564279074904382605163141518161494336")
    };
    std::array<uint8_t, 3> votes = {0x00, 0x00, 0x00};

    return Header(version, parentId, ADProofsRoot, stateRoot, transactionsRoot, timestamp, nBits, height, extensionRoot, powSolution, votes);
}

//generated solution should be valid
void test(AutolykosPowScheme& pow, const Header& inHeader, const boost::multiprecision::cpp_int& difficulty, uint8_t ver, boost::multiprecision::cpp_int sk, boost::multiprecision::cpp_int x) {
    auto nBits = encodeCompactBits(difficulty);
    std::cout << "ver1_test_validate_pow_1 \ntarget difficulty: " << difficulty << ", encodeCompactBits: " << nBits << std::endl;

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

    boost::multiprecision::cpp_int difficulty("114");  // take Reference value from scala
    int ver = 1;
    boost::multiprecision::cpp_int sk("131501327086623406411282142950211450572612984518373211495810952523819885272");
    boost::multiprecision::cpp_int x("114243761898474617129884868038637246324183763405304096763015578343680308830210");

    test(powScheme, createHeader(), difficulty, ver, sk, x);

    return 0;
}
