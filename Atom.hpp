#pragma once

#include "Object.hpp"
#include <string>

class Atom : public Object {
  virtual Type get_type() override;
  virtual void to_string(std::ostream& o) override;
  virtual Object* evaluate(Context* ctx) override;

public:

  static Atom* get(const std::string& str);
};

