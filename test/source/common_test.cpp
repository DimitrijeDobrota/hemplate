#include "hemplate/common.hpp"

#include <catch2/catch_test_macros.hpp>

TEST_CASE("comment", "[common/comment]")
{
  const hemplate::comment comment {"hello world"};

  REQUIRE(std::string(comment) == "<-- hello world -->\n");
}

TEST_CASE("xml", "[common/xml]")
{
  SECTION("default")
  {
    const hemplate::xml xml;

    REQUIRE(
        std::string(xml) == "<? xml version=\"1.0\" encoding=\"UTF-8\"?>\n"
    );
  }

  SECTION("version")
  {
    const hemplate::xml xml {"ver"};

    REQUIRE(
        std::string(xml) == "<? xml version=\"ver\" encoding=\"UTF-8\"?>\n"
    );
  }

  SECTION("version encoding")
  {
    const hemplate::xml xml {"ver", "utf"};

    REQUIRE(std::string(xml) == "<? xml version=\"ver\" encoding=\"utf\"?>\n");
  }
}

TEST_CASE("transform", "[common/transform]")
{
  using tag = hemplate::element_boolean<"t">;
  using child = hemplate::element_boolean<"c">;

  SECTION("direct")
  {
    const std::vector<std::string> vec = {"1", "2"};
    const auto tmp = tag {hemplate::transform(
        vec,
        [](const auto& elem)
        {
          return child {elem};
        }
    )};

    REQUIRE(std::string(tmp) == "<t>\n  <c>1</c>\n  <c>2</c>\n</t>\n");
  }

  SECTION("indirect")
  {
    const std::vector<std::string> vec = {"1", "2"};
    const auto tmp = tag {hemplate::transform(
        vec,
        [](const auto& elem)
        {
          return hemplate::element {elem};
        }
    )};

    REQUIRE(std::string(tmp) == "<t>\n  1\n  2\n</t>\n");
  }
}
