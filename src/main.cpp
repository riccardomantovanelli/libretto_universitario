/**
@file main.c
@author Riccardo Mantovaelli, VR402249
@mainpage

@author Riccardo Mantovaelli, VR402249
@section Spiegazione progetto

Il programma permette la gestione della carriera universitaria di studenti. Si
possono inserire più studenti e per ciascuno inserire i voti nel libretto. E'
possibile visualizzare il libretto di ogni studente e calcolarne la media
*/

#include "Progressivo.hpp"
#include "Studente.hpp"
#include "StudenteErasmus.hpp"
#include <iostream>
#include <string>
#include <vector>

int main() {

  std::vector<StudenteSpace::Studente> studenti;
  int scelta = -1;
  unsigned int n = 0;
  int z;
  float voto = 0;

  while (scelta != 0) {
    std::cout << "\n\nMENU\n1. Inserire un nuovo studente\n2. Lista "
                 "studenti\n3. Inserisci voto\n4. Libretto studente\n5. Media "
                 "studente\n6. Media di 2 voti generici\n0. Uscire\nScelta:";
    std::cin >> scelta;
    switch (scelta) {
    case 1: {
      std::cout << "Vuoi inserire:\n1.Studente\n2.StudenteErasmus\nScelta:";
      std::cin >> scelta;
      if (scelta < 1 || scelta > 2) {
        std::cout << "Scelta errata";
        break;
      }

      std::string str;
      if (scelta == 1) {
        StudenteSpace::Studente st;
        st.inizializzaLibretto();
        std::cout << "Inserisci il nome:";
        std::cin >> str;
        if (str.size() == 0) {
          std::cout << "Inserire una stringa non vuota";
          break;
        }
        st.setNome(str);
        std::cout << "Inserisci il cognome:";
        std::cin >> str;
        if (str.size() == 0) {
          std::cout << "Inserire una stringa non vuota";
          break;
        }
        st.setCognome(str);
        std::cout << "Inserisci il matricola:";
        std::cin >> str;
        if (str.size() == 0) {
          std::cout << "Inserire una stringa non vuota";
          break;
        }
        st.setMatricola(str);

        n = ProgSpace::Progressivo::getProg();
        st.setId(n);
        studenti.push_back(st);
      } else {
        StudenteSpace::StudenteErasmus st;
        st.inizializzaLibretto();
        std::cout << "Inserisci il nome:";
        std::cin >> str;
        if (str.size() == 0) {
          std::cout << "Inserire una stringa non vuota";
          break;
        }
        st.setNome(str);
        std::cout << "Inserisci il cognome:";
        std::cin >> str;
        if (str.size() == 0) {
          std::cout << "Inserire una stringa non vuota";
          break;
        }
        st.setCognome(str);
        std::cout << "Inserisci il matricola:";
        std::cin >> str;
        if (str.size() == 0) {
          std::cout << "Inserire una stringa non vuota";
          break;
        }
        st.setMatricola(str);
        std::cout << "Inserisci il paese di origine:";
        std::cin >> str;
        if (str.size() == 0) {
          std::cout << "Inserire una stringa non vuota";
          break;
        }
        st.setPaeseOrigine(str);
        n = ProgSpace::Progressivo::getProg();
        st.setId(n);
        studenti.push_back(st);
      }
      break;
    }
    case 2: {
      if (studenti.size() == 0) {
        std::cout << "Non e' ancora stato inserito nessun studente";
        break;
      }
      std::cout << "\nLista studenti:\n";
      for (unsigned int i = 0; i < studenti.size(); i++) {
        std::cout << studenti[i].toString();
      }
      break;
    }
    case 3: {
      if (studenti.size() == 0) {
        std::cout << "Non e' ancora stato inserito nessun studente";
        break;
      }
      std::cout << "\nLista studenti:\n";
      for (unsigned int i = 0; i < studenti.size(); i++) {
        std::cout << i + 1 << " " << studenti[i].getNomeCognome()
                  << studenti[i].getMatricola() << "\n";
      }
      std::cout
          << "\nDi quale studente vuoi inserire il voto? (inserisci numero):";
      std::cin >> n;
      if (n <= 0 || n > studenti.size()) {
        std::cout << "Selezione sbagliata";
        break;
      } else
        std::cout << "\nQuale insegnamento? (inserisci numero):\n";
      StudenteSpace::Studente::listaInsegnamenti();
      std::cout << "\nScelta:";
      std::cin >> z;
      if (z <= 0 || z > 5) {
        std::cout << "Selezione sbagliata";
        break;
      }
      z--;
      std::cout << "\nQual'e' il voto?";
      std::cin >> voto;
      if (voto < 18 || voto > 30) {
        std::cout << "Il voto deve essere compreso tra 18 e 30";
        break;
      }
      studenti[n].setVoto(voto, z);
      voto = 0;
      break;
    }
    case 4: {
      if (studenti.size() == 0) {
        std::cout << "Non e' ancora stato inserito nessun studente";
        break;
      }
      std::cout << "\nLista studenti:\n";
      for (unsigned int i = 0; i < studenti.size(); i++) {
        std::cout << i + 1 << " " << studenti[i].getNomeCognome() << " "
                  << studenti[i].getMatricola() << "\n";
      }
      std::cout << "\nQuale studente vuoi vedere? (inserisci numero):";
      std::cin >> n;
      if (n <= 0 || n > studenti.size()) {
        std::cout << "Selezione sbagliata";
        break;
      } else
        studenti[n].getLibretto();
      break;
    }
    case 5: {
      if (studenti.size() == 0) {
        std::cout << "Non e' ancora stato inserito nessun studente";
        break;
      }
      std::cout << "\nLista studenti:\n";
      for (unsigned int i = 0; i < studenti.size(); i++) {
        std::cout << i + 1 << " " << studenti[i].getNomeCognome()
                  << studenti[i].getMatricola() << "\n";
      }
      std::cout
          << "\nDi quale studente vuoi vedere la media? (inserisci numero):";
      std::cin >> n;
      if (n <= 0 || n > studenti.size()) {
        std::cout << "Selezione sbagliata";
        break;
      } else {
        studenti[n].getMedia();
      }
      break;
    }
    case 6: {
      float n1, n2, media = 0;
      std::cout << "\nMedia di 2 voti.\nQual'e' il primo voto?";
      std::cin >> n1;
      if (n1 < 18 || n1 > 30) {
        std::cout << "Il voto deve essere compreso tra 18 e 30";
        break;
      }
      std::cout << "Qual'e' il secondo voto?";
      std::cin >> n2;
      if (n2 < 18 || n2 > 30) {
        std::cout << "Il voto deve essere compreso tra 18 e 30";
        break;
      }
      media = StudenteSpace::Studente::getMediaGenerica(n1, n2);
      std::cout << "\nLa media dei 2 voti è " << media;
      break;
    }
    case 0: {
      for (unsigned int i = 0; i < studenti.size(); i++) {
        studenti[i].free();
      }
      std::cout << "\nUscita\n";
      break;
    }
    default: {
      std::cout << "Errore!";
      break;
    }
    }
  }
}
