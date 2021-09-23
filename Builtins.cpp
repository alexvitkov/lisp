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

using ArithmeticFn = double (*) (double,double);

template <ArithmeticFn Op>
class FnArithmetic : public Function {
public:
  virtual Object* execute(Context* ctx, std::vector<Object*> args) override {
    if (args.size() < 1)
      return nullptr;
    
    double acc;

    for (int i = 0; i < args.size(); i++) {
      Number* num = args[i]->as_number();
      if (!num)
	return nullptr;

      if (i == 0)
	acc = num->get_value();
      else
	acc = Op(acc, num->get_value());
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

double Add(double a, double b) { return a + b; }
double Sub(double a, double b) { return a - b; }
double Mul(double a, double b) { return a * b; }
double Div(double a, double b) { return a / b; }
double Mod(double a, double b) { return (long)a % (long)b; }

void init_root_context(Context* root) {
  root->assign(Atom::get("+"), new FnArithmetic<Add>());
  root->assign(Atom::get("-"), new FnArithmetic<Sub>());
  root->assign(Atom::get("*"), new FnArithmetic<Mul>());
  root->assign(Atom::get("/"), new FnArithmetic<Div>());
  root->assign(Atom::get("%"), new FnArithmetic<Mod>());

  root->assign(Atom::get("cons"), new FnCons());
  root->assign(Atom::get("list"), new FnList());
  root->assign(Atom::get("head"), new FnHead());
  root->assign(Atom::get("tail"), new FnTail());

  root->assign(Atom::get("set"), new SetForm());
  root->assign(Atom::get("lambda"), new LambdaForm());
}
