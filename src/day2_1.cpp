#include <cmath>
#include <fstream>
#include <iostream>
#include <sstream>
#include <stdio.h>
#include <string>
#include <vector>

bool report_is_safe(const std::vector<int>& vec) {
    if (vec.size() == 1) {
        return true;
    }

    // determine if report is supposed to be increasing or decreasing
    bool is_increasing = vec[1] > vec[0];

    for (int i = 1; i < vec.size(); ++i) {
        int a = vec[i-1];
        int b = vec[i];

        // check diff is safe
        int diff = std::abs(b-a);
        if (diff < 1 || diff > 3) {
            return false;
        }

        // check established trend continues
        if (b > a && !is_increasing) {
            return false;
        }
        if (b < a && is_increasing) {
            return false;
        }
    }
    return true;
}

int main(int argc, char* argv[]) {
    // validate args
    if (argc != 2) {
        printf("USAGE: ./a.out path/to/input.txt\n");
        return 1;
    }

    // read input file
    std::string filename = argv[1];
    std::ifstream file(filename);
    if (!file.is_open()) {
        printf("ERROR: could not open %s\n", filename.c_str());
        return 1;
    }

    // parse input file
    int ans = 0;
    std::string line;
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::vector<int> vec;
        int val;
        while (ss >> val) {
            vec.push_back(val);
        }
        if (report_is_safe(vec)) {
            ans++;
        }
    }
    file.close();

    printf("ANSWER: %d\n", ans);
    return 0;
}