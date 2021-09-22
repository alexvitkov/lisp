#include "Number.hpp"
#include "BuiltinFunctions.hpp"

#include <iostream>



class SetForm : public Function {
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
  virtual Object* execute(Context* ctx, Cons* args) override {
    double acc = 0;

    while (args) {
      Number* num = eval(ctx, args->get_head())->as_number();

      if (!num) {
	// FIXME
	std::cout << "Not a number";
	exit(1);
      }

      acc += num->get_value();

      Object* tail = args->get_tail();
      if (!tail)
	break;

      if (!tail->as_cons()) {
	// FIXME
	std::cout << "Not a cons";
	exit(1);
      }

      args = tail->as_cons();
    }

    return new Number(acc);
  }
};


void init_root_context(Context* root) {
  root->assign(Atom::get("+"), new FnAdd());
  root->assign(Atom::get("set"), new SetForm());
}
