#include "Number.hpp"
#include "Builtins.hpp"
#include "Lambda.hpp"

#include <iostream>



class SetForm : public Form {
public:
  virtual Object* execute(Context* ctx, Cons* args) override {
    Atom* atom = Cons::nth(args, 0)->as_atom();
    Object* value = Cons::nth(args, 1);

    if (!atom)
      return nullptr;

    Object* evaluated = eval(ctx, value);
    ctx->assign(atom, evaluated);

    return evaluated;
  }
};


class FnAdd : public Function {
public:
  virtual Object* execute(Context* ctx, std::vector<Object*> args) override {
    double acc = 0;

    for (Object* arg : args) {
      Number* num = arg->as_number();

      if (!num) {
	// FIXME
	std::cout << "+: Not a number";
	exit(1);
      }

      acc += num->get_value();
    }

    return new Number(acc);
  }
};


void init_root_context(Context* root) {
  root->assign(Atom::get("+"), new FnAdd());
  root->assign(Atom::get("set"), new SetForm());
  root->assign(Atom::get("lambda"), new LambdaForm());
}
