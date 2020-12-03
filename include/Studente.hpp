/**
@file Studente.hpp

@author Mantovanelli Riccardo, VR402249

Classe che permette la creazione di uno studente e la sua carriera
*/

#pragma once
#include <iostream>
#include <string>

namespace StudenteSpace {
class Studente {
public:
  /**
  @name ENUM INSEGNAMENTI
  @brief nomi di insegnamenti accettati
  */
  enum insegnamenti {
    PROGRAMMAZIONE1 = 0,
    ANALISI1 = 1,
    PROGRAMMAZIONE2 = 2,
    ANALISI2 = 3,
    LOGICA = 4
  };

  /**
  @name STRUTTURA INSEGNAMENTO
  @brief struttura che identifica un insegnamento
  */
  struct insegnamento {
    insegnamenti in;
    float voto = 0;
    int passato;
  };

  /**
  @name FUNZIONE STAMPA
  @fn ggetInsValue(int &n);
  @param codice dell'insegnamento
  @brief restituisce l'insegnamento corrispondente dell'enum
  */
  static std::string getInsValue(int &n);

  insegnamento libretto[5];

  int *id = new int;
  std::string nome;
  std::string cognome;
  std::string matricola;

  /**
  @name FUNZIONE IMPOSTAZIONE ID
  @fn setId(int i);
  @param id
  @brief setta l'id passato
  */
  void setId(int i);

  /**
  @name FUNZIONE PER RICHIEDERE LISTA INSEGNAMENTI
  @fn listaInsegnamenti();
  @brief stampa a video una lista di isnegnamenti
  */
  static void listaInsegnamenti();

  template <typename T>
  /**
  @name FUNZIONE PER RICHIEDERE MEDIA DI 2 VOTI GENERICI
  @fn getMediaGenerica(T &n1, T &n2);
  @param n1
  @param n2
  @return media di n1 e n2
  @brief ritorna la media di 2 numeri
  */
  static T getMediaGenerica(T &n1, T &n2);

  /**
  @name FUNZIONE IMPOSTAZIONE DATI STUDENTE
  @fn setStudente(std::string &n, std::string &c, std::string &m)
  @param n
  @param c
  @param m
  @brief setta i dati passati
  */
  virtual void setStudente(std::string &n, std::string &c, std::string &m);

  /**
  @name FUNZIONE IMPOSTAZIONE NOME
  @fn setNome(std::string &s)
  @param s
  @brief setta il nome passato
  */
  void setNome(std::string &s);

  /**
  @name FUNZIONE IMPOSTAZIONE COGNOME
  @fn setCognome(std::string &s);
  @param s
  @brief setta il cognome passato
  */
  void setCognome(std::string &s);

  /**
  @name FUNZIONE IMPOSTAZIONE MATRICOLA
  @fn setMatricola(std::string &s);
  @param s
  @brief setta la matricola passata
  */
  void setMatricola(std::string &s);

  /**
  @name FUNZIONE PER RICAVARE IL COGNOME E IL NOME
  @fn getNomeCognome();
  @return stringa con nome e cognome
  @brief restituisce nome e cognome
  */
  std::string getNomeCognome();
  /**
  @name FUNZIONE PER RICAVARE LA MATRICOLA
  @fn getMatricola();
  @return stringa con la matricola
  @brief restituisce la matricola
  */
  std::string getMatricola();

  /**
  @name FUNZIONE PER INIZIALIZZARE IL LIBRETTO
  @fn inizializzaLibretto();
  @brief inizializza il voto a 0, non passato e i nomi degli insegnamenti
  */
  void inizializzaLibretto();

  /**
  @name FUNZIONE IMPOSTAZIONE VOTO
  @fn setVoto(float &v, int &i);
  @param v voto da impostare
  @param i insegnamento da impostare
  @brief setta il voto all'insegnamento passato
  */
  void setVoto(float &v, int &i);

  /**
  @name FUNZIONE PER RICAVARE LIBRETTO
  @fn getLibretto();
  @brief stamp il libretto dello studente
  */
  void getLibretto();

  /**
  @name FUNZIONE PER RICAVARE LA MEDIA
  @fn getMedia();
  @brief stampa la media dello studente
  */
  void getMedia();

  /**
  @name FUNZIONE PER RICAVARE NOME, COGNOME E MATRICOLA
  @fn toString();
  @return stringa contenente nome, cognome e matricola
  @brief restituisce una stringa con nome, cognome e matricola
  */
  virtual std::string toString();

  /**
  @name FUNZIONE PER RICAVARE IL NUMERO DI ESAMI PASSATI
  @fn int numeroPassati()
  @return numero esami passati
  @brief ritorna il numero esami passati
  */
  constexpr int numeroPassati() {
    int contatore = 0;
    for (auto ct = 0; ct < 5; ct++) {
      if (libretto[ct].passato == 1) {
        contatore++;
      }
    }
    return contatore;
  }

  /**
@name FUNZIONE PER ELIMINARE I DATI DALL'HEAP
@fn void free();
*/
  void free();
};
} // namespace StudenteSpace
