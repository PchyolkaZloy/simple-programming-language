#include "types.h"

#include <iostream>
#include <variant>
#include <string>
#include <type_traits>
#include <vector>
#include <map>

#include "boost/multiprecision/cpp_int.hpp"

using namespace std;

int main() {
    cpp_int xyz = -1;
    for (int i = 1; i <= 100; ++i) {
        xyz *= i;
    }
    cout << xyz << "\n\n";
    std::basic_string<char> v;
    boost::multiprecision::export_bits(xyz, std::back_inserter(v), 7);
    cpp_int res;
    boost::multiprecision::import_bits(res, v.begin(), v.end());
    cout << res << "\n\n";
    return 0;
}
