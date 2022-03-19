#include <gtest/gtest.h>
#include "core/Core.hpp"

namespace bakcyl::core::test {
namespace {

TEST(CoreTest, itLives)
{
    Core();
}

TEST(CoreTest, changeProductQuantityShouldReturn2)
{
    Core core;
    EXPECT_EQ(core.changeProductQuantity(0,"",1), 2);
}

TEST(CoreTest, changeProductQuantityShouldReturn1)
{
    Core core;
    EXPECT_EQ(core.changeProductQuantity(0,"increase",1), 1);
    EXPECT_EQ(core.changeProductQuantity(0,"decrease",1), 1);
}

}
}
