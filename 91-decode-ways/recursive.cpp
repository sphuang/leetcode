#include <string>
#include <iostream>
#include "solution.hpp"

// 232 / 258 test cases passed.
int RecursiveSolution::numDecodings(const std::string &s) {
    int count = 0;
    int decode = 0;
    switch (s.size()) {
    case 0:
        throw std::runtime_error{"empty string"};
        break;
    case 1:
        if (s[0] == '0') {
            return 0;
        } else {
            return 1;
        }
        break;
    case 2:
        decode = (s[0] - '0') * 10 + (s[1] - '0');
        if (10 <= decode && decode <= 26) {
            count++;
        }
        if (s[0] != '0' && s[1] != '0') {
            count++;
        }
        break;
    default:
        if (s[0] != '0') {
            count += numDecodings(s.substr(1));
        }
        
        decode = (s[0] - '0') * 10 + (s[1] - '0');
        if (10 <= decode && decode <= 26) {
            count += numDecodings(s.substr(2));
        }
    }
    return count;
}