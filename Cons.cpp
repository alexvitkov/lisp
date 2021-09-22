#include "Cons.hpp"
#include <ostream>

Cons::Cons(Object* head, Object* tail) : head(head), tail(tail) {
}

Type Cons::get_type() {
  return TYPE_CONS;
}

void Cons::to_string(std::ostream& o) {
  o << '(' << head << " . " << tail << ')';
}

Object* Cons::evaluate() {
  // TODO
  return nullptr;
}
