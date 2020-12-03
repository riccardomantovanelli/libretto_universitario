/**
@file Studente.hpp

@author Mantovanelli Riccardo, VR402249

Classe che permette la creazione di uno studente erasmus e la sua carriera
*/

#pragma once
#include "Studente.hpp"
#include <iostream>
#include <string>

namespace StudenteSpace {
class StudenteErasmus : public Studente {
public:
  std::string paeseOrigine;

  /**
  @name FUNZIONE IMPOSTAZIONE DATI STUDENTE
  @fn setStudente(std::string &n, std::string &c, std::string &m) override;
  @param n
  @param c
  @param m
  @param p
  @brief setta i dati passati
  */
  void setStudente(std::string &n, std::string &c, std::string &m) override;

  /**
  @name IMPOSTAZIONE PAESE DI ORIGINE
  @fn setPaeseOrigine(std::string &paese);
  @param paese
  @brief setta il paese di origjne passato
  */
  void setPaeseOrigine(std::string &paese);

  /**
  @name RESTITUISCE IL PAESE DI ORIGINE
  @fn getPaeseOrigine(std::string paese);
  @return restituiscie il paese di origine
  @brief restituiscie il paese di origine
  */
  std::string getPaeseOrigine();

  /**
  @name FUNZIONE PER RICAVARE NOME, COGNOME E MATRICOLA
  @fn toString();
  @return stringa contenente nome, cognome e matricola
  @brief restituisce una stringa con nome, cognome e matricola
  */
  std::string toString() override;
};
} // namespace StudenteSpace
