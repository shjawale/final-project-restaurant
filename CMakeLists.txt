CMAKE_MINIMUM_REQUIRED(VERSION 2.8.12)

project(main)

ADD_SUBDIRECTORY(googletest)

INCLUDE_DIRECTORIES(googletest/include)

SET(CMAKE_CXX_STANDARD 11)

ADD_EXECUTABLE(example
    example.cpp
    include/components/src/Menu.cpp
    # New classes added
    include/components/src/item.cpp
    include/components/src/SingleItem.cpp
    include/components/src/plate.cpp
    include/components/src/order.cpp
    include/components/src/SingleItemDisplay.cpp
    include/components/src/MultiItemDisplay.cpp
    include/components/src/OrderDisplay.cpp
    include/components/src/moneyclass.cpp
    include/windows/src/OrderWindow.cpp
    include/windows/src/ExtraOrderWindow.cpp
    include/src/SingleItemCreator.cpp
)

ADD_EXECUTABLE(restaurant
    restaurant.cpp
    include/components/src/Menu.cpp
    include/components/src/Utilities.cpp
    include/windows/src/LoginWindow.cpp
)

ADD_EXECUTABLE(unit_tests
    unit_test.cpp
    include/components/src/moneyclass.cpp
    include/components/src/item.cpp
    include/components/src/Singleitem.cpp
    include/components/src/SingleItemDisplay.cpp
    include/components/src/plate.cpp
)

ADD_EXECUTABLE( displayTestTwo
    tests/testDisplay.cpp
    include/components/src/item.cpp
    include/components/src/Singleitem.cpp
    include/components/src/SingleItemDisplay.cpp
    include/components/src/moneyclass.cpp
    include/components/src/MultiItemDisplay.cpp
    include/components/src/plate.cpp
    include/components/src/order.cpp
    include/components/src/OrderDisplay.cpp
    include/components/src/HelperFunctions.cpp
)


TARGET_LINK_LIBRARIES(unit_tests gtest)
TARGET_COMPILE_DEFINITIONS(unit_tests PRIVATE gtest_disable_pthreads=ON)
