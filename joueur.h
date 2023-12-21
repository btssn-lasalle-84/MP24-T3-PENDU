#ifndef JOUEUR_H
#define JOUEUR_H

#include <string>

using namespace std;

class Joueur
{
  private:
    string nom;

  public:
    Joueur(string nom = "joueur");
    string getNom() const;
    void   enregisterNom(const string& nom);
};

#endif // JOUEUR_H
