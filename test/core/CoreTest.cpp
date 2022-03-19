#include <gtest/gtest.h>
#include "core/Core.hpp"

namespace bakcyl::core::test {
namespace {

TEST(CoreTest, itLives)
{
    Core();
}

TEST(CoreTest, demandIndicatorShouldBeZero)
{
    Core core;
    EXPECT_EQ(core.CalculateDemandIndicator(12,0), 0);
}

}
}
