#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <chrono>
#include "solution.hpp"

using namespace std;

int main(int argc, char **argv) {
    std::map<std::string, int> testCases = {
        {"0", 0},
        {"120", 1},
        {"12", 2},
        {"226", 3},
        {"1982738498", 2},
        {"18273847583827384758", 2},
        {"182738485738273847383728193847", 4},
        {"9317949759856497357254398763219839323723136763131916377913495416692666785978758414629119614215967159", 0},
    };

    // RecursiveSolution solution{};
    DPSolution solution{};

    for (const auto& pair: testCases) {
        try {
            auto start = std::chrono::steady_clock::now();

            int ans = solution.numDecodings(pair.first);
            if (ans != pair.second) {
                std::cout << "for case [" << pair.first << "]: " << ans << " is not euqal to " << pair.second << std::endl;
            }

            auto end = std::chrono::steady_clock::now();
            // std::cout << "Elapsed time in ms: " << chrono::duration_cast<chrono::milliseconds>(end - start).count() << " case [" << pair.first << "]" << endl;
        } catch (const std::exception& e) {
            std::cout << "for case [" << pair.first << "]: exception happen " << e.what() << std::endl;
        }
    }

    return 0;
}