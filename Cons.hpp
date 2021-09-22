#pragma once

#include "Object.hpp"

class Cons : public Object {
  Object *head;
  Object *tail;

  virtual Type get_type() override;
  virtual void to_string(std::ostream& o) override;
  virtual Object* evaluate(Context*) override;

public:
  Cons(Object* head, Object* tail);

  Object* get_head();
  Object* get_tail();

  static Object* nth(Cons* cons, int n);
};
