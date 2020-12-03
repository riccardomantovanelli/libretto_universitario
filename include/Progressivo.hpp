/**
@file Progressivo.hpp

@author Mantovanelli Riccardo, VR402249

Classe che permette la generazione di un id univoco
*/
#pragma once
#include <iostream>
#include <string>

namespace ProgSpace {

class Progressivo {
public:
  /**
  @name FUNZIONE CHE GENERA UN PROGRESSIVO
  @fn static int getProg();
  @return progressivo
  @brief una volta chiamata restituisce un id univoco
  */
  static int getProg();
};

} // namespace ProgSpace
