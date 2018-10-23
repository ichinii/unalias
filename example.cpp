#include "include/unalias.hpp"
#include <type_traits>
#include <iostream>

using new_int = UNALIAS(int);
using newer_int = UNALIAS(int);

struct Foo {};
using new_Foo = UNALIAS(Foo);
using newer_Foo = UNALIAS(Foo);

int main()
{
  std::cout << std::is_same_v<int, new_int> << std::endl;
  std::cout << std::is_same_v<new_int, newer_int> << std::endl;

  std::cout << std::is_same_v<Foo, new_Foo> << std::endl;
  std::cout << std::is_same_v<new_Foo, newer_Foo> << std::endl;

  return 0;
}
