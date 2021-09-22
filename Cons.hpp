#pragma once

#include "Object.hpp"

class Cons : public Object {
  Object *head;
  Object *tail;

  virtual Type get_type() override;
  virtual void to_string(std::ostream& o) override;

public:
  virtual Object* evaluate(Context*) override;
  Cons(Object* head, Object* tail);

  Object* get_head();
  Object* get_tail();
};
