#pragma once

#include "Object.hpp"
#include "Atom.hpp"
#include <unordered_map>

class Context {
  std::unordered_map<Atom*, Object*> map;
  Context* parent;

public:
  Context(Context* parent);
  Object* resolve(Atom*);
};
