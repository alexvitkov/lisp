#include "Object.hpp"
#include "Cons.hpp"
#include "Number.hpp"
#include "Atom.hpp"
#include "Function.hpp"
#include <iostream>


Cons* Object::as_cons() {
  return dynamic_cast<Cons*>(this);
}

Number* Object::as_number() {
  return dynamic_cast<Number*>(this);
}

Atom* Object::as_atom() {
  return dynamic_cast<Atom*>(this);
}

Form* Object::as_function() {
  return dynamic_cast<Form*>(this);
}

Object* eval(Context* ctx, Object* obj) {
  if (!obj)
    return nullptr;

  return obj->evaluate(ctx);
}

std::ostream& operator<<(std::ostream& o, Object* obj) {
  if (!obj)
    o << "nil";
  else
    obj->to_string(o);
  return o;
}

