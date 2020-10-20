#include "wsjcpp_static_analizing_text.h"
#include "wsjcpp_core.h"

double WsjcppStaticAnalizingText::calcWeightOfOneChar(int strLen) {
  return 100.0/static_cast<double>(strLen);
}

std::map<char, double> WsjcppStaticAnalizingText::calc(const std::string &text) {
    std::map<char, double> map;
    std::string str = text;
    str = WsjcppCore::toLower(str);

    int strLen = str.length();
    double weightOfOneChar = calcWeightOfOneChar(strLen);
    for (int i = 0; i < strLen; i++) {
        map[str[i]] = 0.0;
    }
    for (int i = 0; i < strLen; i++) {
        map[str[i]] += weightOfOneChar;
    }
    return map;
}