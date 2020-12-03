
#define CATCH_CONFIG_MAIN
#include "Progressivo.hpp"
#include "Studente.hpp"
#include "StudenteErasmus.hpp"
#define CATCH_CONFIG_MAIN
#   include <catch.hpp>
#undef CATCH_CONFIG_MAIN

#include <iostream>
#include <string>

TEST_CASE("Get Prog", "[getProg]") {
  REQUIRE(ProgSpace::Progressivo::getProg() == 0);
  REQUIRE(ProgSpace::Progressivo::getProg() == 1);
  REQUIRE(ProgSpace::Progressivo::getProg() == 2);
}


TEST_CASE("To String", "[toString]") {
  StudenteSpace::Studente st;
  std::string stringa="Mario";
  st.setNome(stringa);
  stringa="Rossi";
  st.setCognome(stringa);
  stringa="VR1234";
  st.setMatricola(stringa);
  REQUIRE(st.toString() == "Mario\tRossi\tVR1234\n");
}

TEST_CASE("To StringErasmus", "[toStringErasmus]") {
  StudenteSpace::StudenteErasmus st;
  std::string stringa="Mario";
  st.setNome(stringa);
  stringa="Rossi";
  st.setCognome(stringa);
  stringa="VR1234";
  st.setMatricola(stringa);
  stringa="Germania";
  st.setPaeseOrigine(stringa);
  REQUIRE(st.toString() == "Mario\tRossi\tVR1234\tGermania\n");
}
