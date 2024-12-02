#include <algorithm>
#include <cmath>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

int main(int argc, char* argv[]) {
    // validate args
    if (argc != 2) {
        std::cout << "USAGE: ./a.out path/to/input.txt" << std::endl;
        return 1;
    }

    // read input file
    std::string filename = argv[1];
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cout << "ERROR: could not open " << filename << std::endl;
        return 1;
    }

    // parse input file
    std::vector<int> left_list;
    std::vector<int> right_list;
    std::string line;
    while (std::getline(file, line)) {
        int l, r;
        std::stringstream ss(line);
        ss >> l;
        ss >> r;
        left_list.push_back(l);
        right_list.push_back(r);
    }
    file.close();
    
    // sort the lists
    std::sort(left_list.begin(), left_list.end());
    std::sort(right_list.begin(), right_list.end());

    // calculate total diff
    int ans = 0;
    for (int i = 0; i < left_list.size(); i++) {
        ans += std::abs(left_list[i] - right_list[i]);
    }


    // print result and exit
    std::cout << "ANSWER: " << ans << std::endl;
    return 0;
}
