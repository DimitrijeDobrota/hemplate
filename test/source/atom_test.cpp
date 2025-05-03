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

TEST_CASE("linkHref", "[atom/linkHref]")
{
  const atom::linkHref link {"url"};

  REQUIRE(std::string(link) == "<link href=\"url\" />\n");
}

TEST_CASE("linkSelf", "[atom/linkSelf]")
{
  const atom::linkSelf link {"url"};

  REQUIRE(std::string(link) == "<link rel=\"self\" href=\"url\" />\n");
}

TEST_CASE("linkAlternate", "[atom/linkAlternate]")
{
  const atom::linkAlternate link {"url"};

  REQUIRE(
      std::string(link)
      == "<link rel=\"alternate\" type=\"text/html\" href=\"url\" />\n"
  );
}
