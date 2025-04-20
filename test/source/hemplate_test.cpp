#include <iostream>

#include "hemplate/attribute.hpp"
#include "hemplate/classes.hpp"

int main()
{
  using namespace hemplate;  // NOLINT

  const attributeList li_attrs {{"class", "home_li"}};
  const attributeList ul_attrs {
      {"id", "main_ul"},
      {"class", "home_ul"},
      {"style", "margin-bottom: 1em"},
  };

  std::cout << html::html {
      comment("Hello this is a comment"),
      html::ul {
          ul_attrs,
          html::li {
              li_attrs.add("class", "item1"),
              "Item 1",
          },
          html::li {
              li_attrs.add("class", "item2"),
              "Item 2",
          },
      },
      html::meta(),
  };

  return 0;
}
