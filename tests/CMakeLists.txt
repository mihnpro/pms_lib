add_executable(test_DateTime unit/test_DateTime.cpp)
target_link_libraries(test_DateTime core utils)
add_test(NAME test_DateTime COMMAND test_DateTime)

add_executable(test_Room unit/test_Room.cpp)
target_link_libraries(test_Room core utils)
add_test(NAME test_Room COMMAND test_Room)

add_executable(test_BookingFlow integration/test_BookingFlow.cpp)
target_link_libraries(test_BookingFlow core utils)
add_test(NAME test_BookingFlow COMMAND test_BookingFlow)
