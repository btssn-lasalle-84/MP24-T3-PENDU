#ifndef JOUEUR_H
#define JOUEUR_H

#include <string>
using namespace std;

class Joueur {
private:
  string nom;
  int tentativeRestantes;

public:
  Joueur(string nom, int tentativeRestantes);
  void enregisterNom();
  int getTentative();
};

#endif // JOUEUR_H
