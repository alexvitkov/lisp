#pragma once
#include "Object.hpp"

class Number : public Object {
  double value;
  virtual Type get_type() override;
  virtual void to_string(std::ostream& o) override;

public:
  virtual Object* evaluate(Context*) override;
  Number(double value);
  double get_value();
};
