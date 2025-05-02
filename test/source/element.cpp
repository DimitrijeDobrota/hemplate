#include "hemplate/element.hpp"

#include <catch2/catch_test_macros.hpp>

using namespace hemplate;  // NOLINT

TEST_CASE("boolean", "[element]")
{
  using tag = element_boolean<"tag">;
  using child = element_boolean<"child">;

  SECTION("empty")
  {
    const auto t = tag {};

    REQUIRE(std::string(t) == "<tag>\n</tag>\n");
  }

  SECTION("attribute")
  {
    const auto t = tag {{{"attr", "val"}}};

    REQUIRE(std::string(t) == "<tag attr=\"val\">\n</tag>\n");
  }

  SECTION("data")
  {
    const auto t = tag {"text"};

    REQUIRE(std::string(t) == "<tag>\n  text\n</tag>\n");
  }

  SECTION("attribute data")
  {
    const auto t = tag {{{"attr", "val"}}, "text"};

    REQUIRE(std::string(t) == "<tag attr=\"val\">\n  text\n</tag>\n");
  }

  SECTION("child")
  {
    const auto t = tag {
        child {},
    };

    REQUIRE(std::string(t) == "<tag>\n  <child>\n  </child>\n</tag>\n");
  }

  SECTION("attribute child")
  {
    const auto t = tag {
        {{"attr", "val"}},
        child {},
    };

    REQUIRE(
        std::string(t) == "<tag attr=\"val\">\n  <child>\n  </child>\n</tag>\n"
    );
  }

  SECTION("child data")
  {
    const auto t = tag {
        child {"text"},
    };

    REQUIRE(
        std::string(t) == "<tag>\n  <child>\n    text\n  </child>\n</tag>\n"
    );
  }

  SECTION("attribute child data")
  {
    const auto t = tag {
        {{"attr", "val"}},
        child {"text"},
    };

    REQUIRE(
        std::string(t)
        == "<tag attr=\"val\">\n  <child>\n    text\n  </child>\n</tag>\n"
    );
  }
}

TEST_CASE("atomic", "[element]")
{
  using tag = element_atomic<"tag">;

  SECTION("empty")
  {
    const auto t = tag {};

    REQUIRE(std::string(t) == "<tag />\n");
  }

  SECTION("attribute")
  {
    const auto t = tag {{{"attr", "val"}}};

    REQUIRE(std::string(t) == "<tag attr=\"val\" />\n");
  }
}

TEST_CASE("element", "[element]")
{
  using child = element_boolean<"child">;

  SECTION("empty")
  {
    const auto t = element {};

    REQUIRE(std::string(t) == "");  // NOLINT
  }

  SECTION("data")
  {
    const auto t = element {"text"};

    REQUIRE(std::string(t) == "text\n");
  }

  SECTION("child")
  {
    const auto t = element {
        child {},
    };

    REQUIRE(std::string(t) == "<child>\n</child>\n");
  }

  SECTION("child element")
  {
    const auto t = child {
        element {},
    };

    REQUIRE(std::string(t) == "<child>\n</child>\n");
  }

  SECTION("element child data")
  {
    const auto t = element {
        child {"text"},
    };

    REQUIRE(std::string(t) == "<child>\n  text\n</child>\n");
  }

  SECTION("child element data")
  {
    const auto t = child {
        element {"text"},
    };

    REQUIRE(std::string(t) == "<child>\n  text\n</child>\n");
  }
}
