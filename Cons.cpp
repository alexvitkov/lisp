#include "Cons.hpp"
#include "Function.hpp"
#include <iostream>

Cons::Cons(Object* head, Object* tail) : head(head), tail(tail) {
}

Type Cons::get_type() {
  return TYPE_CONS;
}

void Cons::to_string(std::ostream& o) {
  o << '(' << head << " . " << tail << ')';
}

Object* Cons::evaluate(Context* ctx) {
  Function* fn = eval(ctx, head)->as_function();

  if (!fn)
    return nullptr;

  if (!tail)
    return fn->execute(ctx, nullptr);

  if (!tail->as_cons()) {
    // TODO
    std::cout << "Cons.cpp: tail is not a cons list\n";
    exit(1);
  }

  return fn->execute(ctx, tail->as_cons());
}

Object* Cons::get_head() {
  return head;
}

Object* Cons::get_tail() {
  return tail;
}


Object* Cons::nth(Cons* cons, int n) {
  if (!cons)
    return nullptr;

  if (n == 0)
    return cons->head;

  return nth(cons->tail->as_cons(), n - 1);
}
