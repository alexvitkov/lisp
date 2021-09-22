#include "Object.hpp"
#include "Cons.hpp"
#include "Number.hpp"
#include "Atom.hpp"
#include <iostream>



int main() {
  Number* num1 = new Number(100);
  Number* num2 = new Number(100);

  Cons* cons = new Cons(get_atom("haha"), num2);

  std::cout << cons;
  return 0;
}
