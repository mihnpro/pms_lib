#include "core/Room.h"
#include <cassert>
#include <iostream>

int main() {
    Room room(101, "Single");
    assert(room.getNumber() == 101);
    assert(room.getType() == "Single");
    assert(room.isAvailable());

    room.setAvailable(false);
    assert(!room.isAvailable());

    std::cout << "Room tests passed." << std::endl;
    return 0;
}
