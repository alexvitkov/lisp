#pragma once
#include "Object.hpp"

class Number : public Object {
  double value;
  virtual void to_string(std::ostream& o) override;
  virtual Object* evaluate(Context*) override;

public:
  Number(double value);
  double get_value();
};
