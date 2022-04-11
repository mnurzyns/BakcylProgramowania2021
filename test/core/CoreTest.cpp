#include <gtest/gtest.h>
#include "core/Core.hpp"
#include "common/product.hpp"
#include "common/productInstance.hpp"

namespace bakcyl::core::test {
namespace {

class CoreTest : public ::testing::Test
{
public:
    Core core;
};

class CoreTestProduct : public CoreTest
{
public:
    common::Product product;
};

class CoreTestProductInstance : public CoreTest
{
public:
    common::ProductInstance product;
};

TEST(CoreTest, itLives)
{
    Core();
}

TEST_F(CoreTest, demandIndicatorShouldBeZero)
{
    EXPECT_EQ(core.calculateDemandIndicator(12,0), 0);
}

TEST_F(CoreTest, changeProductQuantityShouldReturnWrongParam)
{
    EXPECT_EQ(core.changeProductQuantity("",1), Core::MethodResult::WRONG_PARAM);
    EXPECT_EQ(core.changeProductQuantity("INCREASE",1), Core::MethodResult::WRONG_PARAM);
    EXPECT_EQ(core.changeProductQuantity("DECREASE",1), Core::MethodResult::WRONG_PARAM);
    EXPECT_EQ(core.changeProductQuantity("add",1), Core::MethodResult::WRONG_PARAM);
}

TEST_F(CoreTest, changeProductQuantityShouldReturnError)
{
    EXPECT_EQ(core.changeProductQuantity("increase",1), Core::MethodResult::ERROR);
    EXPECT_EQ(core.changeProductQuantity("decrease",1), Core::MethodResult::ERROR);
    EXPECT_EQ(core.changeProductQuantity("increase",97), Core::MethodResult::ERROR);
    EXPECT_EQ(core.changeProductQuantity("decrease",1009), Core::MethodResult::ERROR);
}

TEST_F(CoreTest, changeProductQuantityShouldReturnSuccess)
{
    EXPECT_EQ(core.changeProductQuantity("increase",0), Core::MethodResult::SUCCESS);
    EXPECT_EQ(core.changeProductQuantity("decrease",0), Core::MethodResult::SUCCESS);
}

TEST_F(CoreTestProduct, createProductShouldReturnSuccess)
{
    EXPECT_EQ(core.createProduct(product), Core::MethodResult::SUCCESS);
}

TEST_F(CoreTestProduct, updateProductShouldReturnSuccess)
{
    EXPECT_EQ(core.updateProduct(0,product), Core::MethodResult::SUCCESS);
    EXPECT_EQ(core.updateProduct(9755765,product), Core::MethodResult::SUCCESS);
    EXPECT_EQ(core.updateProduct(2147483647,product), Core::MethodResult::SUCCESS);
    EXPECT_EQ(core.updateProduct(4294967295,product), Core::MethodResult::SUCCESS);
}

TEST_F(CoreTestProductInstance, createProductInstanceShouldReturnSuccess)
{
    EXPECT_EQ(core.createProductInstance(product), Core::MethodResult::SUCCESS);
}

TEST_F(CoreTestProductInstance, updateProductInstanceShouldReturnSuccess)
{
    EXPECT_EQ(core.updateProductInstance(0, product), Core::MethodResult::SUCCESS);
    EXPECT_EQ(core.updateProductInstance(9755765, product), Core::MethodResult::SUCCESS);
    EXPECT_EQ(core.updateProductInstance(2147483647, product), Core::MethodResult::SUCCESS);
    EXPECT_EQ(core.updateProductInstance(4294967295, product), Core::MethodResult::SUCCESS);
}

TEST_F(CoreTest, updateLocationShouldReturnSuccess)
{
    EXPECT_EQ(core.updateLocation("", "Wy%fR8/b+K"), Core::MethodResult::SUCCESS);
    EXPECT_EQ(core.updateLocation("MNYYFVH", "Ng^qh9"), Core::MethodResult::SUCCESS);
    EXPECT_EQ(core.updateLocation("ZZZZZZZZZZZZZZZZZZZZ", "zyjCDcmasr"), Core::MethodResult::SUCCESS);
    EXPECT_EQ(core.updateLocation("AAAAAAAAAA", "Uf4w2ZETpCk9Q8MeXk3rZNzcAT89BcfCMSPqjXRXyAqdCdfHstZLCToTjzXAPMEoa9nocc2f"), Core::MethodResult::SUCCESS);
}

struct ProductTestStruct
{
    int id;
    Core::MethodResult operationResult;
};

class CoreTestProductParametrized : public ::testing::WithParamInterface<ProductTestStruct> , public CoreTestProduct
{};

TEST_P(CoreTestProductParametrized, UpdateOperation)
{
    const auto id = GetParam().id;
    const auto result = GetParam().operationResult;

    EXPECT_EQ(core.deleteProduct(id), result);
    EXPECT_EQ(core.deleteProductInstance(id), result);
}

INSTANTIATE_TEST_SUITE_P(
    CoreTestProductParametrizedTest,
    CoreTestProductParametrized,
    ::testing::Values(
        ProductTestStruct{0, Core::MethodResult::SUCCESS},
        ProductTestStruct{9755765, Core::MethodResult::SUCCESS},
        ProductTestStruct{2147483647, Core::MethodResult::SUCCESS}
        ));

struct ProductTestStructWithString
{
    std::string option;
    Core::MethodResult operationResult;
};

class CoreTestProductParametrizedWithString : public ::testing::WithParamInterface<ProductTestStructWithString> , public CoreTestProduct
{};

TEST_P(CoreTestProductParametrizedWithString, updateProductOperations)
{
    const auto option = GetParam().option;
    const auto result = GetParam().operationResult;

    EXPECT_EQ(core.createLocation(option), result);
    EXPECT_EQ(core.deleteLocation(option),result);
}

INSTANTIATE_TEST_SUITE_P(
    CoreTestProductParametrizedTest,
    CoreTestProductParametrizedWithString,
    ::testing::Values(
        ProductTestStructWithString{"", Core::MethodResult::SUCCESS},
        ProductTestStructWithString{"MNYYFVH", Core::MethodResult::SUCCESS},
        ProductTestStructWithString{"ZZZZZZZZZZZZZZZZZZZZ", Core::MethodResult::SUCCESS},
        ProductTestStructWithString{"AAAAAAAAAA", Core::MethodResult::SUCCESS}
        ));

    }
}
