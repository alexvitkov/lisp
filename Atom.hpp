#pragma once

#include "Object.hpp"
#include <string>

class Atom : public Object {
  virtual Type get_type() override;
  virtual void to_string(std::ostream& o) override;
  virtual Object* evaluate() override;

  friend Atom* get_atom(const std::string& str);
};

Atom* get_atom(const std::string& str);
