#pragma once
#include "Object.hpp"

class Form : public Object {

  virtual Type get_type() override;
  virtual void to_string(std::ostream& o) override;
  virtual Object* evaluate(Context*) override;

public:
  virtual Object* execute(Context* context, Cons* args) = 0;
};
