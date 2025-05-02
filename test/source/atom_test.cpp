#include "hemplate/atom.hpp"

#include <catch2/catch_test_macros.hpp>

using namespace hemplate;  // NOLINT

TEST_CASE("feed", "[atom/feed]")
{
  SECTION("default")
  {
    const atom::feed feed;

    REQUIRE(
        std::string(feed)
        == "<feed xmlns=\"http://www.w3.org/2005/Atom\">\n</feed>\n"
    );
  }

  SECTION("custom")
  {
    const atom::feed feed {{{"hello", "world"}}};

    REQUIRE(std::string(feed) == "<feed hello=\"world\">\n</feed>\n");
  }
}
