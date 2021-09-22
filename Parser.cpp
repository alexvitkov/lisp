#include "Object.hpp"
#include "Cons.hpp"
#include "Number.hpp"
#include "Atom.hpp"
#include <assert.h>
#include <iostream>
#include <vector>
#include <stdlib.h>


Object* parse(char*& input);

bool is_atom_character(char ch) {
  if (ch >= 'a' && ch <= 'z')
    return true;

  if (ch >= '0' && ch <= '9')
    return true;

  if (ch == '-' || ch == '+' || ch == '*' || ch == '/' || ch == '%')
    return true;

  return false;
}

bool is_ws(char ch) {
  return ch == ' ' || ch == '\t' || ch == '\n';
}

void skip_ws(char*& input) {
  while (is_ws(*input))
    input++;
}

Cons* vector_to_cons(std::vector<Object*>& objects, int offset) {
  if (offset == objects.size())
    return nullptr;
  else
    return new Cons(objects[offset], vector_to_cons(objects, offset + 1));
}

Object* parse_list(char*& input) {
  // skip the opening bracket
  assert(*input == '(');
  input++;

  skip_ws(input);

  std::vector<Object*> elements;

  while (*input != ')') {
    elements.push_back(parse(input));
    skip_ws(input);
  }

  input++;
  return vector_to_cons(elements, 0);
}

Object* parse_number(char*& input) {

  if (input[0] == '+' || input[0] == '-') {
    char c = input[0];
    char n = input[1];
    if (!(n >= '0' && n <= '9') && n != '.') {
      input ++;

      switch (c) {
      case '-': return Atom::get("-");
      case '+': return Atom::get("+");
      }
    }
  }

  char* end;
  double d = strtod(input, &end);

  char nextChar = *end;
  if (!is_ws(nextChar) && nextChar != ')' && nextChar != '\0') {
    std::cout << "Parse error after number\n";
    exit(1);
  }

  input = end;

  return new Number(d);
}

Atom* parse_atom(char*& input) {
  const char* start = input;

  while (is_atom_character(*input))
    input++;

  char old = *input;
  *input = '\0';

  Atom* atom = Atom::get(start);

  *input = old;
  return atom;
}

Object* parse(char*& input) {

  char c = input[0];

  if (c == '(')
    return parse_list(input);

  else if ((c >= '0' && c <= '9') || (c == '.' || c == '-' || c == '+'))
    return parse_number(input);

  else if (is_atom_character(c))
    return parse_atom(input);

  std::cout << "Parse error, invalid character";
  exit(1);
}
