CMAKE_MINIMUM_REQUIRED(VERSION 2.8.12)

ADD_SUBDIRECTORY(googletest)

INCLUDE_DIRECTORIES(googletest/include)

SET(CMAKE_CXX_STANDARD 11)

ADD_EXECUTABLE(example
    example.cpp
    include/components/src/Menu.cpp
)

ADD_EXECUTABLE(restaurant
    restaurant.cpp
    include/components/src/Menu.cpp
    include/components/src/Utilities.cpp
    include/windows/src/LoginWindow.cpp
)

ADD_EXECUTABLE(unit_tests
    tests/unit_tests.cpp
)


TARGET_LINK_LIBRARIES(unit_tests gtest)
TARGET_COMPILE_DEFINITIONS(unit_tests PRIVATE gtest_disable_pthreads=ON)