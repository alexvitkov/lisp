#include "Object.hpp"
#include "Cons.hpp"
#include "Number.hpp"
#include <iostream>



int main() {
  Number* num1 = new Number(100);
  Number* num2 = new Number(100);

  Cons* cons = new Cons(num1, num2);

  std::cout << cons;
  return 0;
}
