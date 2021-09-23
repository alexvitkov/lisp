#include "Number.hpp"
#include <ostream>

Number::Number(double value) : value(value) {
}

void Number::to_string(std::ostream& o) {
  o << value;
}

Object* Number::evaluate(Context*) {
  return this;
}

double Number::get_value() {
  return value;
}
