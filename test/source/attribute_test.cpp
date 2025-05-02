#include "hemplate/attribute.hpp"

#include <catch2/catch_test_macros.hpp>

TEST_CASE("constructor", "[attribute]")
{
  SECTION("name")
  {
    const hemplate::attribute attr {"class"};

    REQUIRE(attr.name() == "class");
    REQUIRE(attr.empty());
    REQUIRE(std::string(attr) == "class");
  }

  SECTION("name, value")
  {
    const hemplate::attribute attr {"class", "test"};

    REQUIRE(attr.name() == "class");
    REQUIRE(attr.value() == "test");
    REQUIRE(!attr.empty());
    REQUIRE(std::string(attr) == R"(class="test")");
  }
}

TEST_CASE("append", "[attribute]")
{
  hemplate::attribute attr {"class"};

  SECTION("empty")
  {
    attr.append(" ", "");

    REQUIRE(attr.name() == "class");
    REQUIRE(attr.empty());
    REQUIRE(std::string(attr) == R"(class)");
  }

  SECTION("first")
  {
    attr.append(" ", "first");

    REQUIRE(attr.name() == "class");
    REQUIRE(attr.value() == "first");
    REQUIRE(!attr.empty());
    REQUIRE(std::string(attr) == R"(class="first")");

    SECTION("second")
    {
      attr.append(" ", "second");

      REQUIRE(attr.name() == "class");
      REQUIRE(attr.value() == "first second");
      REQUIRE(!attr.empty());
      REQUIRE(std::string(attr) == R"(class="first second")");
    }
  }
}
