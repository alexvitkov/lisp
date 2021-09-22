#include "Data.hpp"
#include <iostream>


bool Object::is_cons() {
  return dynamic_cast<Cons*>(this) != nullptr;
}

bool Object::is_number() {
  return dynamic_cast<Number*>(this) != nullptr;
}


Type Cons::get_type() {
  return TYPE_CONS;
}

Type Number::get_type() {
  return TYPE_NUMBER;
}

Type get_type(Object* expr) {
  if (!expr)
    return TYPE_NIL;
  return expr->get_type();
}




std::ostream& operator<<(std::ostream& o, Object* obj) {
  obj->to_string(o);
  return o;
}

void Number::to_string(std::ostream& o) {
  o << value;
}

void Cons::to_string(std::ostream& o) {
  o << '(' << head << " . " << tail << ')';
}




Cons::Cons(Object* head, Object* tail) : head(head), tail(tail) {
}


Number::Number(double value) : value(value) {
}
