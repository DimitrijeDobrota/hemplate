#include <iostream>

#include "hemplate/classes.hpp"

int main()
{
  using namespace hemplate;  // NOLINT

  const attributeList ul_attrs({{"id", "main_ul"}, {"class", "home_ul"}});
  const attributeList li_attrs({"class", "home_li"});

  std::cout << html() << std::endl;
  std::cout << ul("Won't see", ul_attrs)
                   .set("style", "margin-top: 1em;")
                   .add(li("Item 1", li_attrs))
                   .add(li("Item 2", li_attrs))
            << std::endl;
  std::cout << meta() << std::endl;
  std::cout << html() << std::endl;

  return 0;
}
