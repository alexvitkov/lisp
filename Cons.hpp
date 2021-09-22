#pragma once
#include "Object.hpp"

class Cons : public Object {
  Object *head;
  Object *tail;

  virtual Type get_type() override;
  virtual void to_string(std::ostream& o) override;
  virtual Object* evaluate() override;

public:
  Cons(Object* head, Object* tail);
};
