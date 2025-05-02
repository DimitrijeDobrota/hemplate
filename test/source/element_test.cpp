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

    REQUIRE(std::string(t) == "<tag>text</tag>\n");
  }

  SECTION("attribute data")
  {
    const auto t = tag {{{"attr", "val"}}, "text"};

    REQUIRE(std::string(t) == "<tag attr=\"val\">text</tag>\n");
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

    REQUIRE(std::string(t) == "<tag>\n  <child>text</child>\n</tag>\n");
  }

  SECTION("attribute child data")
  {
    const auto t = tag {
        {{"attr", "val"}},
        child {"text"},
    };

    REQUIRE(
        std::string(t) == "<tag attr=\"val\">\n  <child>text</child>\n</tag>\n"
    );
  }

  SECTION("range")
  {
    const std::vector<std::string> vec = {"hello", "world"};
    const auto t = tag {vec};

    REQUIRE(std::string(t) == "<tag>\n  hello\n  world\n</tag>\n");
  }

  SECTION("tag element elemetn tag")
  {
    const auto t = tag {element {element {tag {}}}};
    REQUIRE(std::string(t) == "<tag>\n  <tag>\n  </tag>\n</tag>\n");
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
  using tag = element_boolean<"tag">;
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

  SECTION("tag")
  {
    const auto t = element {
        tag {},
    };

    REQUIRE(std::string(t) == "<tag>\n</tag>\n");
  }

  SECTION("tag element")
  {
    const auto t = tag {
        element {},
    };

    REQUIRE(std::string(t) == "<tag>\n</tag>\n");
  }

  SECTION("element tag")
  {
    const auto t = element {
        tag {},
    };

    REQUIRE(std::string(t) == "<tag>\n</tag>\n");
  }

  SECTION("element tag data")
  {
    const auto t = element {
        tag {"text"},
    };

    REQUIRE(std::string(t) == "<tag>text</tag>\n");
  }

  SECTION("tag element data")
  {
    const auto t = tag {
        element {"text"},
    };

    REQUIRE(std::string(t) == "<tag>text</tag>\n");
  }

  SECTION("tag element data")
  {
    const auto t = tag {
        element {"text"},
    };

    REQUIRE(std::string(t) == "<tag>text</tag>\n");
  }

  SECTION("element tag child data")
  {
    const auto t = element {
        tag {
            child {
                "text",
            },
        },
    };

    REQUIRE(std::string(t) == "<tag>\n  <child>text</child>\n</tag>\n");
  }

  SECTION("element tag element child data")
  {
    const auto t = element {
        tag {
            element {
                child {
                    "text",
                },
            },
        },
    };

    REQUIRE(std::string(t) == "<tag>\n  <child>text</child>\n</tag>\n");
  }

  SECTION("element tag child element data")
  {
    const auto t = element {
        tag {
            child {
                element {
                    "text",
                },
            },
        },
    };

    REQUIRE(std::string(t) == "<tag>\n  <child>text</child>\n</tag>\n");
  }

  SECTION("element tag element child element data")
  {
    const auto t = element {
        tag {
            element {
                child {
                    element {
                        "text",
                    },
                },
            },
        },
    };

    REQUIRE(std::string(t) == "<tag>\n  <child>text</child>\n</tag>\n");
  }

  SECTION("tag element child data")
  {
    const auto t = tag {
        element {
            child {
                "text",
            },
        },
    };

    REQUIRE(std::string(t) == "<tag>\n  <child>text</child>\n</tag>\n");
  }

  SECTION("tag child element data")
  {
    const auto t = tag {
        child {
            element {
                "text",
            },
        },
    };

    REQUIRE(std::string(t) == "<tag>\n  <child>text</child>\n</tag>\n");
  }

  SECTION("tag element child element data")
  {
    const auto t = tag {
        element {
            child {
                element {
                    "text",
                },
            },
        },
    };

    REQUIRE(std::string(t) == "<tag>\n  <child>text</child>\n</tag>\n");
  }
}
