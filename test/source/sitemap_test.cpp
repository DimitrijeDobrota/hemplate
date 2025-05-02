#include "hemplate/sitemap.hpp"

#include <catch2/catch_test_macros.hpp>

using namespace hemplate;  // NOLINT

TEST_CASE("urlset", "[sitemap/urlset]")
{
  SECTION("default")
  {
    const sitemap::urlset urlset;

    REQUIRE(std::string(urlset) == "<urlset xmlns=\"http://www.sitemaps.org/schemas/sitemap/0.9\">\n</urlset>\n");
  }

  SECTION("random")
  {
    const sitemap::urlset urlset {{{"hello", "world"}}};

    REQUIRE(std::string(urlset) == "<urlset hello=\"world\">\n</urlset>\n");
  }
}
