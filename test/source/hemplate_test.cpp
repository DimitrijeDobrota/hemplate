#include <iostream>

#include "hemplate/classes.hpp"

int main()
{
  using namespace hemplate;  // NOLINT

  attributeList li_attrs;
  li_attrs.set("class", "main_li");

  std::cout << html() << std::endl;
  std::cout << ul("Won't see")
                   .set("id", "main_ul")
                   .add(li("Item 1", li_attrs))
                   .add(li("Item 2", li_attrs))
            << std::endl;
  std::cout << meta() << std::endl;
  std::cout << html() << std::endl;

  return 0;
}
