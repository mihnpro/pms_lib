#include "core/DateTime.h"
#include <cassert>
#include <iostream>

int main() {
    DateTime d1(2025, 5, 12);
    DateTime d2(2025, 5, 13);

    assert(d1 < d2);
    std::cout << "DateTime tests passed." << std::endl;
    return 0;
}
