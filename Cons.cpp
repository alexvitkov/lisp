#include "Cons.hpp"
#include "Function.hpp"
#include <iostream>

Cons::Cons(Object* head, Object* tail) : head(head), tail(tail) {
}

void Cons::print(std::ostream& o, bool brackets) {
  if (brackets)
    o << '(';

  o << head;

  if (tail->as_cons()) {
    o << ' ';
    tail->as_cons()->print(o, false);
  } else if (tail) {
    o << " . " << tail;
  }

  if (brackets)
    o << ')';
}

void Cons::to_string(std::ostream& o) {
  print(o, true);
}

Object* Cons::evaluate(Context* ctx) {
  Form* fn = eval(ctx, head)->as_function();

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


Cons* Cons::from_vector(std::vector<Object*> objects, int offset) {
  if (offset == objects.size())
    return nullptr;
  else
    return new Cons(objects[offset], Cons::from_vector(objects, offset + 1));
}
