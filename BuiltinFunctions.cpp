#include "Number.hpp"
#include "BuiltinFunctions.hpp"

#include <iostream>

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
}
