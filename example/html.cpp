#include <iostream>

#include "hemplate/html.hpp"

#include "hemplate/attribute.hpp"

int main()
{
  using namespace hemplate;  // NOLINT

  const attribute_list li_attrs {{"class", "home_li"}};
  const attribute_list ul_attrs {
      {"id", "main_ul"},
      {"class", "home_ul"},
      {"style", "margin-bottom: 1em"},
  };

  std::cout << html::html {
      comment {"Hello this is a comment"},
      html::ul {
          ul_attrs,
          html::li {
              {li_attrs, {{"class", "item1"}}},
              "Item 1",
              "some text",
          },
          html::li {
              {li_attrs, {{"class", "item2"}}},
              "Item 2",
              "some text",
          },
      },
      html::hr {},
  };

  return 0;
}
