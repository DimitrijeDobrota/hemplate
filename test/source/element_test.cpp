#include "hemplate/element.hpp"

#include <catch2/catch_test_macros.hpp>

using namespace hemplate;  // NOLINT

TEST_CASE("boolean", "[element]")
{
  using tag = element_boolean<"tag">;
  using child = element_boolean<"child">;

  SECTION("empty")
  {
    const auto tmp = tag {};

    REQUIRE(std::string(tmp) == "<tag>\n</tag>\n");
  }

  SECTION("attribute")
  {
    const auto tmp = tag {{{"attr", "val"}}};

    REQUIRE(std::string(tmp) == "<tag attr=\"val\">\n</tag>\n");
  }

  SECTION("data")
  {
    const auto tmp = tag {"text"};

    REQUIRE(std::string(tmp) == "<tag>text</tag>\n");
  }

  SECTION("attribute data")
  {
    const auto tmp = tag {{{"attr", "val"}}, "text"};

    REQUIRE(std::string(tmp) == "<tag attr=\"val\">text</tag>\n");
  }

  SECTION("child")
  {
    const auto tmp = tag {
        child {},
    };

    REQUIRE(std::string(tmp) == "<tag>\n  <child>\n  </child>\n</tag>\n");
  }

  SECTION("attribute child")
  {
    const auto tmp = tag {
        {{"attr", "val"}},
        child {},
    };

    REQUIRE(
        std::string(tmp)
        == "<tag attr=\"val\">\n  <child>\n  </child>\n</tag>\n"
    );
  }

  SECTION("child data")
  {
    const auto tmp = tag {
        child {"text"},
    };

    REQUIRE(std::string(tmp) == "<tag>\n  <child>text</child>\n</tag>\n");
  }

  SECTION("attribute child data")
  {
    const auto tmp = tag {
        {{"attr", "val"}},
        child {"text"},
    };

    REQUIRE(
        std::string(tmp)
        == "<tag attr=\"val\">\n  <child>text</child>\n</tag>\n"
    );
  }

  SECTION("range")
  {
    const std::vector<std::string> vec = {"hello", "world"};
    const auto tmp = tag {vec};

    REQUIRE(std::string(tmp) == "<tag>\n  hello\n  world\n</tag>\n");
  }

  SECTION("tag element elemetn tag")
  {
    const auto tmp = tag {element {element {tag {}}}};
    REQUIRE(std::string(tmp) == "<tag>\n  <tag>\n  </tag>\n</tag>\n");
  }
}

TEST_CASE("atomic", "[element]")
{
  using tag = element_atomic<"tag">;

  SECTION("empty")
  {
    const auto tmp = tag {};

    REQUIRE(std::string(tmp) == "<tag />\n");
  }

  SECTION("attribute")
  {
    const auto tmp = tag {{{"attr", "val"}}};

    REQUIRE(std::string(tmp) == "<tag attr=\"val\" />\n");
  }
}

TEST_CASE("element", "[element]")
{
  using tag = element_boolean<"tag">;
  using child = element_boolean<"child">;

  SECTION("empty")
  {
    const auto tmp = element {};

    REQUIRE(std::string(tmp) == "");  // NOLINT
  }

  SECTION("data")
  {
    const auto tmp = element {"text"};

    REQUIRE(std::string(tmp) == "text\n");
  }

  SECTION("tag")
  {
    const auto tmp = element {
        tag {},
    };

    REQUIRE(std::string(tmp) == "<tag>\n</tag>\n");
  }

  SECTION("tag element")
  {
    const auto tmp = tag {
        element {},
    };

    REQUIRE(std::string(tmp) == "<tag>\n</tag>\n");
  }

  SECTION("element tag")
  {
    const auto tmp = element {
        tag {},
    };

    REQUIRE(std::string(tmp) == "<tag>\n</tag>\n");
  }

  SECTION("element tag data")
  {
    const auto tmp = element {
        tag {"text"},
    };

    REQUIRE(std::string(tmp) == "<tag>text</tag>\n");
  }

  SECTION("tag element data")
  {
    const auto tmp = tag {
        element {"text"},
    };

    REQUIRE(std::string(tmp) == "<tag>text</tag>\n");
  }

  SECTION("tag element data")
  {
    const auto tmp = tag {
        element {"text"},
    };

    REQUIRE(std::string(tmp) == "<tag>text</tag>\n");
  }

  SECTION("element tag child data")
  {
    const auto tmp = element {
        tag {
            child {
                "text",
            },
        },
    };

    REQUIRE(std::string(tmp) == "<tag>\n  <child>text</child>\n</tag>\n");
  }

  SECTION("element tag element child data")
  {
    const auto tmp = element {
        tag {
            element {
                child {
                    "text",
                },
            },
        },
    };

    REQUIRE(std::string(tmp) == "<tag>\n  <child>text</child>\n</tag>\n");
  }

  SECTION("element tag child element data")
  {
    const auto tmp = element {
        tag {
            child {
                element {
                    "text",
                },
            },
        },
    };

    REQUIRE(std::string(tmp) == "<tag>\n  <child>text</child>\n</tag>\n");
  }

  SECTION("element tag element child element data")
  {
    const auto tmp = element {
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

    REQUIRE(std::string(tmp) == "<tag>\n  <child>text</child>\n</tag>\n");
  }

  SECTION("tag element child data")
  {
    const auto tmp = tag {
        element {
            child {
                "text",
            },
        },
    };

    REQUIRE(std::string(tmp) == "<tag>\n  <child>text</child>\n</tag>\n");
  }

  SECTION("tag child element data")
  {
    const auto tmp = tag {
        child {
            element {
                "text",
            },
        },
    };

    REQUIRE(std::string(tmp) == "<tag>\n  <child>text</child>\n</tag>\n");
  }

  SECTION("tag element child element data")
  {
    const auto tmp = tag {
        element {
            child {
                element {
                    "text",
                },
            },
        },
    };

    REQUIRE(std::string(tmp) == "<tag>\n  <child>text</child>\n</tag>\n");
  }
}
