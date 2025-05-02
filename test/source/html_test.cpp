#include "hemplate/html.hpp"

#include <catch2/catch_test_macros.hpp>

using namespace hemplate;  // NOLINT

TEST_CASE("doctype", "[html/doctype]")
{
  const html::doctype doctype;

  REQUIRE(std::string(doctype) == "<!DOCTYPE html>\n");
}
