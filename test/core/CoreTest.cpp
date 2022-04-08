#include <gtest/gtest.h>
#include "core/Core.hpp"

namespace bakcyl::core::test {
namespace {

class CoreTest : public ::testing::Test
{
public:
    Core core;
};

TEST(CoreTest, itLives)
{
    Core();
}

TEST_F(CoreTest, demandIndicatorShouldReturnValue)
{
    EXPECT_EQ(core.calculateDemandIndicator(1,0,0), 19090);
    EXPECT_EQ(core.calculateDemandIndicator(12,0,0),1590);
    EXPECT_EQ(core.calculateDemandIndicator(65535,0,0),0);
    EXPECT_EQ(core.calculateDemandIndicator(65535,1649411285,0),0);
}

TEST_F(CoreTest, changeProductQuantityShouldReturnWrongParam)
{
    EXPECT_EQ(core.changeProductQuantity("",1,0), Core::MethodResult::WRONG_PARAM);
    EXPECT_EQ(core.changeProductQuantity("INCREASE",1,0), Core::MethodResult::WRONG_PARAM);
    EXPECT_EQ(core.changeProductQuantity("DECREASE",1,0), Core::MethodResult::WRONG_PARAM);
    EXPECT_EQ(core.changeProductQuantity("add",1,0), Core::MethodResult::WRONG_PARAM);
}

TEST_F(CoreTest, changeProductQuantityShouldReturnError)
{
    EXPECT_EQ(core.changeProductQuantity("increase",1,0), Core::MethodResult::ERROR);
    EXPECT_EQ(core.changeProductQuantity("decrease",1,0), Core::MethodResult::ERROR);
    EXPECT_EQ(core.changeProductQuantity("increase",97,0), Core::MethodResult::ERROR);
    EXPECT_EQ(core.changeProductQuantity("decrease",1009,0), Core::MethodResult::ERROR);
}

TEST_F(CoreTest, changeProductQuantityShouldReturnSuccess)
{
    EXPECT_EQ(core.changeProductQuantity("increase",0,0), Core::MethodResult::SUCCESS);
    EXPECT_EQ(core.changeProductQuantity("decrease",0,0), Core::MethodResult::SUCCESS);
}

}
}
