#pragma once

#include "Object.hpp"
#include "Form.hpp"
#include "Cons.hpp"
#include <vector>



class Function : public Form {
public:
  virtual Object* execute(Context* context, Cons* args) override;
  virtual Object* execute(Context* context, const std::vector<Object*> args) = 0;
};
