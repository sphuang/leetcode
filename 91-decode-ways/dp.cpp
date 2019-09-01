#include <string>
#include <iostream>
#include <vector>
#include "solution.hpp"

using namespace std;

int DPSolution::numOfOneChar(const char c) {
    if (c == '0') {
        return 0;
    } else {
        return 1;
    }
}

int DPSolution::numOfTwoChar(char c1, char c2) {
    int count = 0;
    int decode = (c1 - '0') * 10 + (c2 - '0');
    if (10 <= decode && decode <= 26) {
        count++;
    }
    if (c1 != '0' && c2 != '0') {
        count++;
    }
    return count;
}

// 232 / 258 test cases passed.
int DPSolution::numDecodings(const std::string &s) {
    int len = (int)s.size();
    switch (len) {
    case 0:
        return 0;
    case 1:
        return numOfOneChar(s[0]);
    case 2:
        return numOfTwoChar(s[0], s[1]);
    }

    vector<int> counts(len);
    counts[len - 1] = numOfOneChar(s[len - 1]);
    counts[len - 2] = numOfTwoChar(s[len - 2], s[len - 1]);
    for (int idx = len - 3; idx >= 0; idx--) {
        int count = 0;

        char c1 = s[idx], c2 = s[idx + 1];
        if (c1 != '0') {
            count += counts[idx + 1];
        }

        int decode = (c1 - '0') * 10 + (c2 - '0');
        if (10 <= decode && decode <= 26) {
            count += counts[idx + 2];
        }

        counts[idx] = count;
    }
    
    return counts[0];
}