cmake_minimum_required(VERSION 3.10)
project(pms_library)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)

add_library(core
    src/core/DateTime.cpp
    src/core/Room.cpp
    src/core/Guest.cpp
    src/core/Booking.cpp
    src/core/Billing.cpp
    src/core/Resource.cpp
    src/core/Housekeeping.cpp
)

add_library(utils
    src/utils/Logger.cpp
    src/utils/ConfigParser.cpp
)

add_executable(pms_app src/main.cpp)

target_link_libraries(pms_app core utils)

