#include "Context.hpp"

Context::Context(Context* parent) : parent(parent) {
}

Object* Context::resolve(Atom* atom) {
  auto it = map.find(atom);

  if (it != map.end())
    return it->second;

  else if (parent)
    return parent->resolve(atom);

  return nullptr;
}

void Context::assign(Atom* atom, Object* value) {
  map[atom] = value;
}
