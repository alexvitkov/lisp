#pragma once

#include <iosfwd>

enum Type {
  TYPE_NIL,
  TYPE_NUMBER,
  TYPE_CONS,
};



class Object {
  // the member function get_type is private, we expose a public get_type(SExpr*) instead,
  // because that one works with nullptr as well
  virtual Type get_type() = 0;
  friend Type get_type(Object* expr);

  virtual void to_string(std::ostream& o) = 0;
  friend std::ostream& operator<<(std::ostream&, Object*);

  bool is_cons();
  bool is_number();
};


class Cons : public Object {
  Object *head;
  Object *tail;
  virtual Type get_type() override;
  virtual void to_string(std::ostream& o) override;

public:
  Cons(Object* head, Object* tail);
};


class Number : public Object {
  double value;
  virtual Type get_type() override;
  virtual void to_string(std::ostream& o) override;

public:
  Number(double value);
};



Type get_type(Object* expr);
std::ostream& operator<<(std::ostream&, Object*);
