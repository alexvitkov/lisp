#include "Atom.hpp"
#include "Context.hpp"

#include <unordered_map>


static std::unordered_map<std::string, Atom*> atom_map;
static std::unordered_map<Atom*, std::string> atom_reverse_map;

void Atom::to_string(std::ostream& o) {
  o << atom_reverse_map[this];
}

Object* Atom::evaluate(Context* ctx) {
  // TODO
  return ctx->resolve(this);
}

Atom* Atom::get(const std::string& str) {
  auto it = atom_map.find(str);
  if (it == atom_map.end()) {
    Atom* atom = new Atom();
    atom_map[str] = atom;
    atom_reverse_map[atom] = str;
    return atom;
  } else {
    return it->second;
  }
}
