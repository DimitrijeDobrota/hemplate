#include <iostream>

#include "hemplate/classes.hpp"

int main()
{
  using namespace hemplate;  // NOLINT

  const attributeList li_attrs({"class", "home_li"});
  const attributeList ul_attrs({{"id", "main_ul"},
                                {"class", "home_ul"},
                                {"style", "margin-bottom: 1em"}});

  std::cout << comment("Hello this is a commen");
  std::cout << html::html() << std::endl;
  std::cout << html::ul("Won't see", ul_attrs)
                   .set("style", "margin-top: 1em")
                   .set("class", "center")
                   .add(html::li("Item 1", li_attrs).set("class", "item1"))
                   .add(html::li("Item 2", li_attrs).set("class", "item2"))
            << std::endl;
  std::cout << html::meta() << std::endl;
  std::cout << html::html() << std::endl;

  std::cout << comment();
  std::cout << "split ";
  std::cout << "comment ";
  std::cout << comment() << std::endl;

  return 0;
}
