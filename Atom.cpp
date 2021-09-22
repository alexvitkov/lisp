#include "Atom.hpp"

#include <unordered_map>


static std::unordered_map<std::string, Atom*> atom_map;
static std::unordered_map<Atom*, std::string> atom_reverse_map;

Type Atom::get_type() {
  return TYPE_ATOM;
}

void Atom::to_string(std::ostream& o) {
  o << atom_reverse_map[this];
}

Object* Atom::evaluate() {
  // TODO
  return nullptr;
}

Atom* get_atom(const std::string& str) {
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
