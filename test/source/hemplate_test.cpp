#include <iostream>

#include "hemplate/classes.hpp"

int main()
{
  using namespace hemplate;  // NOLINT

  const attributeList li_attrs({"class", "home_li"});
  const attributeList ul_attrs({{"id", "main_ul"},
                                {"class", "home_ul"},
                                {"style", "margin-bottom: 1em"}});

  std::cout << html() << std::endl;
  std::cout << ul("Won't see", ul_attrs)
                   .set("style", "margin-top: 1em")
                   .set("class", "center")
                   .add(li("Item 1", li_attrs).set("class", "item1"))
                   .add(li("Item 2", li_attrs).set("class", "item2"))
            << std::endl;
  std::cout << meta() << std::endl;
  std::cout << html() << std::endl;

  return 0;
}
