#include "Function.hpp"
#include <ostream>

Type Function::get_type() {
  return TYPE_FUNCTION;
}

void Function::to_string(std::ostream& o) {
  o << "FUNCTION";
}

Object* Function::evaluate(Context*) {
  return this;
}
