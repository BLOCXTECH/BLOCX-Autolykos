#include "test.h"

//calcN test vectors
void testCalcN(AutolykosPowScheme& pow) {
    int exp_result, result;

    // Test 1
    exp_result = pow.NBase;
    result = pow.calcN(1, 700000);
    std::cout << "testCalcN \n1st Result : " << result << ", " << exp_result << std::endl;
    assert(result == exp_result);

    // Test 2
    exp_result = pow.NBase;
    result = pow.calcN(1, 100000);
    std::cout << "2nd Result : " << result << ", " << exp_result << std::endl;
    assert(result == exp_result);

    // Test 3
    exp_result = pow.NBase;
    result = pow.calcN(1, 70000000);
    std::cout << "3rd Result : " << result << ", " << exp_result << std::endl;
    assert(result == exp_result);

    // Test 4
    exp_result = pow.NBase;
    result = pow.calcN(2, 500000);
    std::cout << "4th Result : " << result << ", " << exp_result << std::endl;
    assert(result == exp_result);

    // Test 5
    exp_result = pow.NBase;
    result = pow.calcN(2, 600000);
    std::cout << "5th Result : " << result << ", " << exp_result << std::endl;
    assert(result == exp_result);

    // Test 6
    exp_result = 70464240;
    result = pow.calcN(2, 600 * 1024);
    std::cout << "6th Result : " << result << ", " << exp_result << std::endl;
    assert(result == exp_result);

    // Test 7
    exp_result = 73987410;
    result = pow.calcN(2, 650 * 1024);
    std::cout << "7th Result : " << result << ", " << exp_result << std::endl;
    assert(result == exp_result);

    // Test 8
    exp_result = 73987410;
    result = pow.calcN(2, 700000);
    std::cout << "8th Result : " << result << ", " << exp_result << std::endl;
    assert(result == exp_result);

    // Test 9
    exp_result = 81571035;
    result = pow.calcN(2, 788400);
    std::cout << "9th Result : " << result << ", " << exp_result << std::endl;
    assert(result == exp_result);

    // Test 10
    exp_result = 104107290;
    result = pow.calcN(2, 1051200);
    std::cout << "10th Result : " << result << ", " << exp_result << std::endl;
    assert(result == exp_result);

    // Test 11
    exp_result = 2143944600;
    result = pow.calcN(2, 4198400);
    std::cout << "11th Result : " << result << ", " << exp_result << std::endl;
    assert(result == exp_result);

    // Test 12
    exp_result = 2143944600;
    result = pow.calcN(2, 41984000);
    std::cout << "12th Result : " << result << ", " << exp_result << std::endl;
    assert(result == exp_result);
}

int main() {
    int k = 32;
    int n = 26; // Example values, adjust as needed
                
    // Create an instance of AutolykosPowScheme
    AutolykosPowScheme powScheme(k, n);

    testCalcN(powScheme );

    return 0;
}


