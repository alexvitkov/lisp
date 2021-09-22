#include "Object.hpp"
#include "Cons.hpp"
#include "Number.hpp"
#include "Atom.hpp"
#include <iostream>


bool Object::is_cons() {
  return dynamic_cast<Cons*>(this) != nullptr;
}

bool Object::is_number() {
  return dynamic_cast<Number*>(this) != nullptr;
}

bool Object::is_atom() {
  return dynamic_cast<Atom*>(this) != nullptr;
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

