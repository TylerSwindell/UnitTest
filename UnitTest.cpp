#include "UnitTest.h"

const std::string 
// Foreground Colors
// Bold Text
    UnitTest::B_W = "\033[1;97m",   // Bold White
    UnitTest::B_R = "\033[1;31m",   // Bold Red
    UnitTest::B_G = "\033[1;32m",   // Bold Green
    UnitTest::B_BL = "\033[1;30m",  // Bold Black
    UnitTest::B_BG = "\033[1;92m",  // Bold Bright Green

// Background Colors
    UnitTest::BG_BL = "\033[0;40m", // Black BG
    UnitTest::BG_R = "\033[0;41m",  // Red BG
    UnitTest::BG_G = "\033[0;42m",  // Green BG
    UnitTest::BG_BG = "\033[0;102m",// Bright Green BG

// Resets all styling attributes
    UnitTest::R_T = "\033[0m",

// Labels
    UnitTest::TESTING = "Testing",
    UnitTest::PASSED = "Passed",
    UnitTest::FAILED = "Failed";

UnitTest::UnitTest() { 
    screenSize = 50;
    padding = 1; 
}

void UnitTest::setScreensize(size_t ss) { UnitTest::screenSize = ss; }
size_t UnitTest::getScreensize() { return UnitTest::screenSize; }

void UnitTest::setPadding(size_t p) { padding = p; }
size_t UnitTest::getPadding() { return padding; }

/****************************************************************************************
 * const std::string test => value to be tested
 * const std::string expected => expected result
 ***************************************************************************************/
template<typename T>
void UnitTest::testComponent(const T test, const T expected) {
    int perimeterPadding = (padding * 2) + 2;

    bool result = (test == expected);
    std::string status = result ? PASSED : FAILED;
    std::string outputText = " || Output:";

    // Sets status color
    std::string statusTextColor = result ?  B_BG : B_R;
    std::string statusBGColor = result ?  BG_BG : BG_R;

    int textLengths = status.length() + TESTING.length() - outputText.length();
    int loadingLength = screenSize - perimeterPadding - textLengths;

    print(B_W + TESTING + statusTextColor + borderChar);
    for (size_t i = 0; i < padding; i++) print(R_T + loadingChar);

    print(statusBGColor);
    for (int i = 0; i < loadingLength; i++) {
        std::string loadingMsg = statusTextColor + loadingChar;
                
        print(loadingMsg);
    }
    for (size_t i = 0; i < padding; i++) print(R_T + loadingChar);
    std::cout << statusTextColor << borderChar << status;
    std::cout << " => Input:" << expected;
    std::cout << " => Output:" << test << R_T + '\n';
}

// Testing Entry Point
void UnitTest::componentUnitTest() { 
    
    std::string testValueStr;
    int testValueNum;

    testValueStr = "tyler";
    testComponent<std::string>(testValueStr, "tyler");

    testValueStr = "testing";
    testComponent<std::string>(testValueStr, "testing");

    testValueNum = 50;
    testComponent<size_t>(getScreensize(), testValueNum);

    testValueStr = "50";
    testComponent<std::string>(std::to_string(getScreensize()), testValueStr);

}

void newLine(size_t count) {
    // If count is manually set to 0 return out of function
    if (count < 1) return;

    // Will be skipped if no parameters set or user inputs 1 as param
    if (count > 1)
        for (size_t i = 1; i < count; i++) std::cout << 'n';

    // Will run a single cout
    std::cout << '\n';
}

template<typename T>
void print(T msg, bool endLine, size_t count) {
    std::cout << msg;
    if (endLine) newLine(count);
}