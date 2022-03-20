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
    EXPECT_EQ(core.calculateDemandIndicator(12,0), 0);
}

}
}
