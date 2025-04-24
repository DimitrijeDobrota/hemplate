#include "hemplate/attribute.hpp"

#include <catch2/catch_test_macros.hpp>

// NOLINTBEGIN readability-container-size-empty

TEST_CASE("set class", "[attribute_list]")
{
  hemplate::attribute_list attrs = hemplate::attribute {"class", "first"};

  REQUIRE(std::string(attrs) == R"(class="first")");

  SECTION("second")
  {
    attrs.set({"class", "second"});

    REQUIRE(std::string(attrs) == R"(class="first second")");
  }

  SECTION("random")
  {
    attrs.set({"test"});

    REQUIRE(std::string(attrs) == R"(class="first" test)");
  }
}

TEST_CASE("set style", "[attribute_list]")
{
  hemplate::attribute_list attrs = hemplate::attribute {"style", "first"};

  REQUIRE(std::string(attrs) == R"(style="first")");

  SECTION("second")
  {
    attrs.set({"style", "second"});

    REQUIRE(std::string(attrs) == R"(style="first; second")");
  }

  SECTION("random")
  {
    attrs.set({"test"});

    REQUIRE(std::string(attrs) == R"(style="first" test)");
  }
}

TEST_CASE("set list", "[attribute_list]")
{
  hemplate::attribute_list attrs {
      {"class", "first"},
      {"style", "first"},
      {"test_first"},
      {"class", "second"},
      {"style", "second"},
      {"test_second"},
  };

  REQUIRE(
      std::string(attrs)
      == R"(class="first second" style="first; second" test_first test_second)");

  SECTION("set")
  {
    attrs.set({
        {"class", "third"},
        {"style", "third"},
        {"test_third"},
    });

    REQUIRE(
        std::string(attrs)
        == R"(class="first second third" style="first; second; third" test_first test_second test_third)");
  }
}

TEST_CASE("add", "[attribute_list]")
{
  using namespace std::literals::string_view_literals;

  const auto tmp = hemplate::attribute_list {{"class", "first"}};
  const auto attrs = hemplate::attribute_list {
      tmp, {{"class"sv, "second"sv}, {"class"sv, "third"sv}}};

  REQUIRE(std::string(attrs) == R"(class="first second third")");
}

// NOLINTEND readability-container-size-empty
