#include "StudenteErasmus.hpp"
#include <iostream>
#include <string>

namespace StudenteSpace {

void StudenteErasmus::setStudente(std::string &n, std::string &c,
                                  std::string &m) {
  nome = n;
  cognome = c;
  matricola = m;
}

void StudenteErasmus::setPaeseOrigine(std::string &paese) {
  paeseOrigine = paese;
}
std::string StudenteErasmus::getPaeseOrigine() { return paeseOrigine; }

std::string StudenteErasmus::toString() {
  return nome + "\t" + cognome + "\t" + matricola + "\t" + paeseOrigine + "\n";
}

} // namespace StudenteSpace
