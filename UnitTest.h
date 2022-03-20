#include <iostream>
#include <iomanip>

class UnitTest {
private:
// Foreground Colors
// Bold Text
    static const std::string B_W;
    static const std::string B_R;
    static const std::string B_G;
    static const std::string B_BL;
    static const std::string B_BG;

// Background Colors
    static const std::string BG_BL;
    static const std::string BG_R;
    static const std::string BG_G;
    static const std::string BG_BG;

// Resets all styling attributes
    static const std::string R_T;

// Labels
    static const std::string TESTING;
    static const std::string PASSED;
    static const std::string FAILED;

// Formatting Symbols
    char borderChar = '|',
        loadingChar = '\040';

    std::string 
        testTextColor = B_W,
        passedTextColor = B_BG,
        passedBackgroundColor = BG_BG,
        failedTextColor = B_R,
        failedBackgroundColor = B_R;

// Fomatting sizing
    size_t padding,
        screenSize;
    
public:

    UnitTest();
    
    void setScreensize(size_t ss);
    size_t getScreensize();

    void setPadding(size_t p);
    size_t getPadding();

    void componentUnitTest();
    template<typename T>
    void testComponent(const T test, const T expected);
};

// Count is optional | Defaults: count = 1 
void newLine(size_t count = 1);

template<typename T>
void print(T msg, bool endLine = false, size_t count = 1);