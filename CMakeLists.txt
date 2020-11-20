CMAKE_MINIMUM_REQUIRED(VERSION 2.8.12)

project(main)

ADD_SUBDIRECTORY(googletest)

INCLUDE_DIRECTORIES(googletest/include)

SET(CMAKE_CXX_STANDARD 11)

ADD_EXECUTABLE(example
    example.cpp
    include/src/Menu.cpp
)

ADD_EXECUTABLE(moneytest
    unit_test.cpp
    include/src/moneyclass.cpp
)

TARGET_LINK_LIBRARIES(moneytest gtest)
TARGET_COMPILE_DEFINITIONS(moneytest PRIVATE gtest_disable_pthreads=ON)