#include <iostream>

#include "hemplate/classes.hpp"

int main()
{
  std::cout << hemplate::a() << std::endl;
  std::cout << hemplate::meta() << std::endl;

  return 0;
}
