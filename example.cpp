#include "unalias.hpp"
#include <iostream>

using int0 = UNALIAS(int);
using int1 = UNALIAS(int);

struct dummy {};
using dummy0 = UNALIAS(dummy);
using dummy1 = UNALIAS(dummy);

int main()
{
  std::cout << std::is_same_v<int, int0> << std::endl;
  std::cout << std::is_same_v<int0, int1> << std::endl;

  std::cout << std::is_same_v<dummy, dummy0> << std::endl;
  std::cout << std::is_same_v<dummy0, dummy1> << std::endl;

  return 0;
}
