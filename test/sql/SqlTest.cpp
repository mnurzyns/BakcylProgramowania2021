#include <gtest/gtest.h>
#include <stdexcept>
#include "sql/Sql.hpp"

namespace bakcyl::sql::test {
namespace {

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

TEST(SqlTest, tableEmptyGetAllProductsShouldReturnEmptyVector)
{
    Sql sql;
    EXPECT_EQ(sql.getAllProducts().size(), 0);
}

TEST(SqlTest, productDoesntExistGetProductShouldThrowException)
{
    EXPECT_THROW(
    {
        try
        {
            Sql sql;
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
