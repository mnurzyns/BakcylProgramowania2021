#include <gtest/gtest.h>
#include "proxy/Proxy.hpp"

namespace bakcyl::proxy::test {
namespace {

TEST(ProxyTest, itLives)
{
    Proxy<sql::Sql> proxy;
    proxy.getAllProducts();
}

}
}
