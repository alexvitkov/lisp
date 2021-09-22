#include "Number.hpp"
#include "BuiltinFunctions.hpp"

#include <iostream>

class FnAdd : public Function {
public:
  virtual Object* execute(Context* ctx, Cons* args) override {
    double acc = 0;


    while (1) {
      Number* num = args->evaluate_head(ctx)->as_number();

      if (!num) {
	// FIXME
	std::cout << "Not a number";
	exit(1);
      }

      acc += num->get_value();

      Object* tail = args->get_tail();
      if (!tail)
	return new Number(acc);

      if (!tail->as_cons()) {
	// FIXME
	std::cout << "Not a cons";
	exit(1);
      }

      args = tail->as_cons();
    }

  }
};


void init_root_context(Context* root) {
  root->assign(Atom::get("+"), new FnAdd());
}
