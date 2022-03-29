#include <gtest/gtest.h>
#include <stdexcept>
#include "sql/Sql.hpp"
#include "sql/SqlTestFixture.hpp"

namespace bakcyl::sql::test {
namespace {

//Tests for connection

TEST(SqlTest, itLives)
{
    Sql();
}

TEST(SqlTest, wrongCredentialsShouldThrowException)
{
    EXPECT_THROW(
    {
        try
        {
            Sql();
        }
        catch(const std::runtime_error& e)
        {
            EXPECT_STREQ("Database connection failed!", e.what());
            throw;
        }
        
    }, std::runtime_error);
}

//Tests for queries

TEST_F(SqlTestFixture, tableEmptyGetAllProductsShouldReturnEmptyVector)
{
    EXPECT_TRUE(sql.getAllProducts().empty());
}

TEST_F(SqlTestFixture, productsDontExistGetProductsBeginningWithShouldReturnEmptyVector)
{
    EXPECT_TRUE(sql.getProductsBeginningWith("test").empty());
}

TEST_F(SqlTestFixture, productsDontExistGetProductsEndingWithShouldReturnEmptyVector)
{
    EXPECT_TRUE(sql.getProductsEndingWith("test").empty());
}

TEST_F(SqlTestFixture, productsDontExistGetProductsContainingShouldReturnEmptyVector)
{
    EXPECT_TRUE(sql.getProductsContaining("test").empty());
}

TEST_F(SqlTestFixture, productDoesntExistGetProductShouldThrowException)
{
    EXPECT_THROW(
    {
        try
        {
            sql.getProduct(1000000);
        }
        catch(const std::runtime_error& e)
        {
            EXPECT_STREQ("Product doesn't exist!", e.what());
            throw;
        }
        
    }, std::runtime_error);
}

}
}
