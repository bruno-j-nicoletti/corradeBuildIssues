#include <catch2/catch_all.hpp>

#include "B/bnsB.h"

using namespace std::literals;
using namespace BNS;

TEST_CASE("B")
{
  REQUIRE(B::doB() == "B");
}
