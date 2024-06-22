#include <iostream>

#include "hemplate/classes.hpp"

int main()
{
  using namespace hemplate; // NOLINT

  std::cout << ul("Won't see").add(li("Item 1")).add(li("Item 2")) << std::endl;
  std::cout << meta() << std::endl;

  return 0;
}
