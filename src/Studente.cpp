#include "Studente.hpp"
#include <iostream>
#include <string>

namespace StudenteSpace {

std::string Studente::getInsValue(int &n) {
  switch (n) {
  case 0:
    return "PROGRAMMAZIONE1";
    break;
  case 1:
    return "ANALISI1";
    break;
  case 2:
    return "PROGRAMMAZIONE2";
    break;
  case 3:
    return "ANALISI2";
    break;
  case 4:
    return "LOGICA";
    break;
  default:
    return "";
    break;
  }
}

void Studente::inizializzaLibretto() {
  for (auto ct = 0; ct < 5; ct++) {
    libretto[ct].in = insegnamenti(ct);
    libretto[ct].voto = 0;
    libretto[ct].passato = 0;
  }
}

void Studente::setId(int i) { *id = i; }

void Studente::setStudente(std::string &n, std::string &c, std::string &m) {
  nome = n;
  cognome = c;
  matricola = m;
}

void Studente::setVoto(float &v, int &i) {
  libretto[i].voto = v;
  libretto[i].passato = 1;
}

void Studente::listaInsegnamenti() {
  std::cout << "1.Programmazione1\n2.Analisi2\n3.Programmazione2\n4."
               "Analisi2\n5.logica";
}

template <typename T> T Studente::getMediaGenerica(T &n1, T &n2) {
  return (n1 + n2) / 2;
}

template float Studente::getMediaGenerica<float>(float &, float &);

void Studente::setNome(std::string &s) { nome = s; }

void Studente::setCognome(std::string &s) { cognome = s; }

void Studente::setMatricola(std::string &s) { matricola = s; }

std::string Studente::getNomeCognome() { return nome + " " + cognome; }

std::string Studente::getMatricola() { return matricola; }

void Studente::getLibretto() {
  for (auto ct = 0; ct < 5; ct++) {
    if (libretto[ct].passato == 1)
      std::cout << "\n" << getInsValue(ct) << "\t" << libretto[ct].voto;
    else
      std::cout << "\n"
                << getInsValue(ct) << "\t"
                << "NON ANCORA PASSATO";
  }
  std::cout << "\n\n";
}

void Studente::getMedia() {
  double somma = 0;
  double media = 0;
  for (auto ct = 0; ct < 5; ct++) {
    if (libretto[ct].passato == 1) {
      somma += libretto[ct].voto;
      media++;
    }
  }
  if (media == 0)
    std::cout << "Non è ancora stato inserito alcun voto";
  else {
    media = somma / media;
    std::cout << "Media: " << media;
  }
}

std::string Studente::toString() {
  return nome + "\t" + cognome + "\t" + matricola + "\n";
}

void Studente::free() { delete id; }

} // namespace StudenteSpace
