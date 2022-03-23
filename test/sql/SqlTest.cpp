#include <gtest/gtest.h>
#include <stdexcept>
#include "sql/Sql.hpp"

namespace bakcyl::sql::test {
namespace {

TEST(SqlTest, itLives)
{
    Sql();
}

TEST(SqlTest, connectionErrorShouldThrowException)
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

}
}
