#include <gtest/gtest.h>
#include <stdexcept>
#include "sql/Sql.hpp"

namespace bakcyl::sql::test 
{
    class SqlTestFixture : public ::testing::Test
    {
        protected:
            Sql sql;
    };

}