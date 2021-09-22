#include "Function.hpp"
#include <ostream>

Type Form::get_type() {
  return TYPE_FUNCTION;
}

void Form::to_string(std::ostream& o) {
  o << "FUNCTION";
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
