#pragma once
#include "Function.hpp"
#include <vector>



class LambdaForm : public Form {
public:
  virtual Object* execute(Context* context, Cons* args) override;
};


class Lambda : public Function {
  std::vector<Atom*> argNames;
  Object* body;
public:
  Lambda(std::vector<Atom*>&& argNames, Object* body);
  virtual Object* execute(Context* context, std::vector<Object*> args) override;
};
