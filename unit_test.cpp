
#include <gtest/gtest.h>

#include "include/test/moneyclasstests.h"
#include "include/test/itemtests.hpp"

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}