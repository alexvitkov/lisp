#pragma once

#include "Object.hpp"
#include <string>

class Atom : public Object {
  virtual Type get_type() override;
  virtual void to_string(std::ostream& o) override;

public:
  virtual Object* evaluate(Context* ctx) override;

  static Atom* get(const std::string& str);
};

