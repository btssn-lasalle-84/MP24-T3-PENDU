#ifndef JOUEUR_H
#define JOUEUR_H

#include <string>

class Joueur {
private:
  std::string nom;
  int tentativeRestantes;

public:
  Joueur(std::string nom, int tentativeRestantes);
  void enregisterNom();
  int getTentative();
};

#endif // JOUEUR_H
