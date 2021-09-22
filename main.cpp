#include "Object.hpp"
#include "Cons.hpp"
#include "Number.hpp"
#include "Atom.hpp"
#include "Context.hpp"
#include "BuiltinFunctions.hpp"
#include <iostream>



int main() {
  Context* root = new Context(nullptr);
  init_root_context(root);

  Number* num1 = new Number(100);
  Number* num2 = new Number(200);
  Number* num3 = new Number(300);

  Cons* cons = new Cons(Atom::get("+"), new Cons(num1, new Cons(num2, new Cons(num3, nullptr))));

  std::cout << cons->evaluate(root);
  return 0;
}
