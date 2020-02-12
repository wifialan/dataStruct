#include <iostream>
#include "solution.h"
#include <string>

int main() {

    Solution solu;
    string a = "(){}";
    std::cout << (solu.isValid(a) ? "true": "false") << std::endl;
    a = "({)}";
    std::cout << (solu.isValid(a) ? "true": "false") << std::endl;

    return 0;
}
