#pragma once

#include "Object.hpp"
#include <vector>

class Cons : public Object {
  Object *head;
  Object *tail;

  void print(std::ostream& o, bool brackets);

  virtual void to_string(std::ostream& o) override;
  virtual Object* evaluate(Context*) override;

public:
  Cons(Object* head, Object* tail);

  Object* get_head();
  Object* get_tail();

  static Object* nth(Cons* cons, int n);
  static Cons* from_vector(std::vector<Object*> vtr, int offset);
};
