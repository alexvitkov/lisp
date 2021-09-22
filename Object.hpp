#pragma once

#include <iosfwd>

enum Type {
  TYPE_NIL,
  TYPE_NUMBER,
  TYPE_CONS,
  TYPE_ATOM,
  TYPE_FUNCTION,
};

class Context;

class Object {
  // the virtual fucntions are private, and there's a corresponding set
  // of public functions. that's because the public friend functions work with nullptr
  virtual Type get_type() = 0;
  friend Type get_type(Object* expr);

  virtual void to_string(std::ostream& o) = 0;
  friend std::ostream& operator<<(std::ostream&, Object*);

  virtual Object* evaluate(Context*) = 0;
  friend Object* eval(Context*, Object*);

public:

  bool is_cons();
  bool is_number();
  bool is_atom();

  class Cons* as_cons();
  class Number* as_number();
  class Atom* as_atom();
  class Function* as_function();
};


Type get_type(Object* expr);
Object* eval(Context*, Object*);
std::ostream& operator<<(std::ostream&, Object*);
