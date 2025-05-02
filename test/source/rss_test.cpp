#include "hemplate/rss.hpp"

#include <catch2/catch_test_macros.hpp>

using namespace hemplate;  // NOLINT

TEST_CASE("rss", "[rss/rss]")
{
  SECTION("default")
  {
    const rss::rss rss;

    REQUIRE(std::string(rss) == "<rss version=\"2.0\" xmlns=\"http://www.w3.org/2005/Atom\">\n</rss>\n");
  }

  SECTION("random")
  {
    const rss::rss rss {{{"hello", "world"}}};

    REQUIRE(std::string(rss) == "<rss hello=\"world\">\n</rss>\n");
  }
}

TEST_CASE("atomLink", "[rss/atomLink]")
{
  SECTION("href")
  {
    const rss::atomLink link {"hi"};

    REQUIRE(
        std::string(link)
        == "<atom:link rel=\"self\" type=\"application/rss+xml\" href=\"hi\" />\n"
    );
  }

  SECTION("random")
  {
    const rss::atomLink link {{{"hello", "world"}}};

    REQUIRE(std::string(link) == "<atom:link hello=\"world\" />\n");
  }
}
