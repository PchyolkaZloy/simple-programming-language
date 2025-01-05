#include "types.h"

#include <iostream>
#include <variant>
#include <string>
#include <type_traits>
#include <vector>
#include <map>

using namespace std;

int main() {
    Array a(TypeIndex::Int);
    auto x = Int(new int(3));
    a.Append(&x);
    a.Append(&x);
    a.Append(&x);
    cout << a.Size() << '\n';
    cout << a[1].IntCast() << '\n';
    return 0;
}
