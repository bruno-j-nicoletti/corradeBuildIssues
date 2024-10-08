#include <catch2/catch_all.hpp>

#include "A/bnsA.h"

using namespace std::literals;
using namespace BNS;

TEST_CASE("A")
{
  REQUIRE(A::doA() == "A");
}
