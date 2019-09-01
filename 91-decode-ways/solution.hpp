#include <string>

class Solution {
public:
    int numDecodings(const std::string &s);
};

class RecursiveSolution : public Solution {
public:
    int numDecodings(const std::string &s);
};

class DPSolution : public Solution {
public:
    int numDecodings(const std::string &s);
private:
    int numOfOneChar(char c);
    int numOfTwoChar(char c1, char c2);
};