#pragma once

#include "Object.hpp"
#include "Cons.hpp"

class Function : public Object {

  virtual Type get_type() override;
  virtual void to_string(std::ostream& o) override;

public:
  virtual Object* evaluate(Context*) override;
  virtual Object* execute(Context* context, Cons* args) = 0;
};
