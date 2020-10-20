#ifndef WSJCPP_STATIC_ANALIZING_TEXT_H
#define WSJCPP_STATIC_ANALIZING_TEXT_H

#include <string>
#include <map>

class WsjcppStaticAnalizingText {
    public:
        static std::map<char, double> calc(const std::string &text);
    private:
        static double calcWeightOfOneChar(int strLen); 
};

#endif
