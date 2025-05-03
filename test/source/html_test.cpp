#include "hemplate/html.hpp"

#include <catch2/catch_test_macros.hpp>

using namespace hemplate;  // NOLINT

TEST_CASE("doctype", "[html/doctype]")
{
  const html::doctype doctype;

  REQUIRE(std::string(doctype) == "<!DOCTYPE html>\n");
}

TEST_CASE("aHref", "[html/aHref]")
{
  SECTION("empty")
  {
    const html::aHref a {"url"};

    REQUIRE(std::string(a) == "<a href=\"url\">\n</a>\n");
  }

  SECTION("child")
  {
    const html::aHref a {"url", html::br{}};

    REQUIRE(std::string(a) == "<a href=\"url\"><br /></a>\n");
  }
}

TEST_CASE("metaUTF8", "[html/metaUTF8]")
{
  const html::metaUTF8 meta;

  REQUIRE(std::string(meta) == "<meta charset=\"UTF8\" />\n");
}

TEST_CASE("metaName", "[html/metaName]")
{
  const html::metaName meta {"author", "Kenobi"};

  REQUIRE(std::string(meta) == "<meta name=\"author\" content=\"Kenobi\" />\n");
}

TEST_CASE("linkStylesheet", "[html/linkStylesheet]")
{
  const html::linkStylesheet link {"url"};

  REQUIRE(
      std::string(link)
      == "<link rel=\"stylesheet\" type=\"text/css\" href=\"url\" />\n"
  );
}

TEST_CASE("linkRss", "[html/linkRss]")
{
  const html::linkRss link {"hi", "url"};

  REQUIRE(
      std::string(link)
      == "<link rel=\"alternate\" type=\"application/atom+xml\" title=\"hi\" href=\"url\" />\n"
  );
}

TEST_CASE("linkAtom", "[html/linkAtom]")
{
  const html::linkAtom link {"hi", "url"};

  REQUIRE(
      std::string(link)
      == "<link rel=\"alternate\" type=\"application/atom+xml\" title=\"hi\" href=\"url\" />\n"
  );
}

TEST_CASE("linkIcon", "[html/linkIcon]")
{
  const html::linkIcon link {"16x16", "url"};

  REQUIRE(
      std::string(link)
      == "<link rel=\"icon\" type=\"image/png\" sizes=\"16x16\" href=\"url\" />\n"
  );
}
