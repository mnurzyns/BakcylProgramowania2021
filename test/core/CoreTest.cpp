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
    EXPECT_EQ(DemandIndicator(12,0), 0);
}

}
}
