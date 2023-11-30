#ifndef JOUEUR_H
#define JOUEUR_H

#include <string>

class Joueur {
private:
  std::string nom;
  int tentativesRestantes;

public:
  Joueur(std::string nom, int tentativesRestantes);
  void enregisterNom();
  int getTentative();
};

#endif // JOUEUR_H
