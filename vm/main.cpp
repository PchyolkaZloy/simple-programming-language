#include "vm.h"

#include <iostream>
#include <fstream>

int main() {
    std::ifstream f("/Users/mick3l/Itmo/cpp/simple-programming-language/vm/basic_test.spl");
    if (!f.is_open()) {
        std::cerr << "File doesn't exist\n";
        return 1;
    }
    VirtualMachine vm;
    vm.Run(f);
    return 0;
}