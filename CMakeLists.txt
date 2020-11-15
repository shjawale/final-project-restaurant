CMAKE_MINIMUM_REQUIRED(VERSION 2.8.12)

#ADD_SUBDIRECTORY(googletest)

#INCLUDE_DIRECTORIES(googletest/include)

SET(CMAKE_CXX_STANDARD 11)

ADD_EXECUTABLE(example
    example.cpp
    include/src/Menu.cpp
)

#TARGET_LINK_LIBRARIES(test gtest)
#TARGET_COMPILE_DEFINITIONS(test PRIVATE gtest_disable_pthreads=ON)