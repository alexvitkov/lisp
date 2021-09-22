#pragma once
#include "Object.hpp"

class Number : public Object {
  double value;
  virtual Type get_type() override;
  virtual void to_string(std::ostream& o) override;
  virtual Object* evaluate(Context*) override;

public:
  Number(double value);
};
