#include "Object.hpp"
#include "Cons.hpp"
#include "Number.hpp"
#include "Atom.hpp"
#include "Context.hpp"
#include "BuiltinFunctions.hpp"
#include <iostream>



extern Object* parse(char*&);

int main() {
  Context* root = new Context(nullptr);
  init_root_context(root);

  while (true) {
    std::cout << "> ";

    std::string input;
    std::getline(std::cin, input);

    char* str = (char*)input.c_str();
    Object* o = parse(str);

    std::cout << eval(root, o) << "\n";
  }

  // std::cout << cons->evaluate(root);
  return 0;
}
