#include "Number.hpp"
#include <ostream>

Number::Number(double value) : value(value) {
}

Type Number::get_type() {
  return TYPE_NUMBER;
}

void Number::to_string(std::ostream& o) {
  o << value;
}

Object* Number::evaluate(Context*) {
  return this;
}
