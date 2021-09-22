#include "Lambda.hpp"
#include "Context.hpp"
#include <iostream>

Lambda::Lambda(std::vector<Atom *> &&argNames, Object *body)
    : argNames(argNames), body(body) {}

Object* LambdaForm::execute(Context* context, Cons* args) {
  Cons* argList = Cons::nth(args, 0)->as_cons();
  Object* body = Cons::nth(args, 1);

  std::cout << args << "\n";

  if (!argList || !body)
    return nullptr;

  std::vector<Atom*> argNames;

  while (argList) {
    Atom* atom = argList->get_head()->as_atom();
    if (!atom)
      return nullptr;

    argNames.push_back(atom);
    argList = argList->get_tail()->as_cons();
  }

  return new Lambda(std::move(argNames), body);
}


Object* Lambda::execute(Context* context, std::vector<Object*> args) {
  if (args.size() != argNames.size())
    return nullptr;

  Context tmp(context);

  for (int i = 0; i < args.size(); i++)
    tmp.assign(argNames[i], args[i]);

  return eval(&tmp, body);
}
