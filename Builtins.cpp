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

class FnCons : public Function {
public:
  virtual Object* execute(Context* ctx, std::vector<Object*> args) override {
    if (args.size() != 2)
      return nullptr;
    return new Cons(args[0], args[1]);
  }
};

class FnList : public Function {
public:
  virtual Object* execute(Context* ctx, std::vector<Object*> args) override {
    return Cons::from_vector(args, 0);
  }
};

class FnHead : public Function {
public:
  virtual Object* execute(Context* ctx, std::vector<Object*> args) override {
    if (args.size() != 1)
      return nullptr;

    Cons* cons = args[0]->as_cons();
    return cons ? cons->get_head() : nullptr;
  }
};

class FnTail : public Function {
public:
  virtual Object* execute(Context* ctx, std::vector<Object*> args) override {
    if (args.size() != 1)
      return nullptr;

    Cons* cons = args[0]->as_cons();
    return cons ? cons->get_tail() : nullptr;
  }
};

void init_root_context(Context* root) {
  root->assign(Atom::get("+"), new FnAdd());
  root->assign(Atom::get("cons"), new FnCons());
  root->assign(Atom::get("list"), new FnList());
  root->assign(Atom::get("head"), new FnHead());
  root->assign(Atom::get("tail"), new FnTail());

  root->assign(Atom::get("set"), new SetForm());
  root->assign(Atom::get("lambda"), new LambdaForm());
}
