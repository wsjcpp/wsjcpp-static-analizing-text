
#include "wsjcpp_core.h"
#include "wsjcpp_unit_tests.h"
#include "wsjcpp_static_analizing_text.h"

// ---------------------------------------------------------------------
// UnitTestStaticAnalizingText

class UnitTestStaticAnalizingText : public WsjcppUnitTestBase {
    public:
        UnitTestStaticAnalizingText();
        virtual bool doBeforeTest() override;
        virtual void executeTest() override;
        virtual bool doAfterTest() override;
};

REGISTRY_WSJCPP_UNIT_TEST(UnitTestStaticAnalizingText)

UnitTestStaticAnalizingText::UnitTestStaticAnalizingText()
    : WsjcppUnitTestBase("UnitTestStaticAnalizingText") {
}

// ---------------------------------------------------------------------

bool UnitTestStaticAnalizingText::doBeforeTest() {
    // do something before test
    return true;
}

// ---------------------------------------------------------------------

void UnitTestStaticAnalizingText::executeTest() {
    struct LTest {
        LTest(std::string s1, std::map<char, double> n) : s1(s1), n(n) {}
        std::string s1;
        std::map<char, double> n;
    };

    std::vector<LTest *> tests;
    std::map<char, double> firstCase;
    firstCase['t'] = 50.0;
    firstCase['e'] = 25.0;
    firstCase['s'] = 25.0;
    tests.push_back(new LTest("test", firstCase));

    std::map<char, double> secondCase;
    secondCase['1'] = 50.0;
    secondCase['2'] = 50.0;
    tests.push_back(new LTest("12", secondCase));

    std::map<char, double> thirdCase;
    thirdCase['.'] = 50.0;
    thirdCase['-'] = 50.0;
    tests.push_back(new LTest(".--.", thirdCase));

    unsigned int nSuccess = 0;
    for (unsigned int i = 0; i < tests.size(); i++) {
        std::string s1 = tests[i]->s1;
        std::map<char, double> n = tests[i]->n;
        std::map<char, double> n1 = WsjcppStaticAnalizingText::calc(s1);
        compare("test #" + std::to_string(i), n1 == n, true);
    }
}

// ---------------------------------------------------------------------

bool UnitTestStaticAnalizingText::doAfterTest() {
    // do somethig after test
    return true;
}


