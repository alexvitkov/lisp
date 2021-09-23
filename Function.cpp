#include "Function.hpp"
#include <ostream>

void Form::to_string(std::ostream& o) {
  o << "form";
}

Object* Form::evaluate(Context*) {
  return this;
}

Object* Function::execute(Context* context, Cons* args) {
  std::vector<Object*> evaluated_args;

  while (args) {
    evaluated_args.push_back(eval(context, args->get_head()));
    args = args->get_tail()->as_cons();
  }

  return execute(context, evaluated_args);
}
