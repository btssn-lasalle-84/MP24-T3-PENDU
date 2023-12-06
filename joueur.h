#ifndef JOUEUR_H
#define JOUEUR_H

#include <string>

class Joueur
{
  private:
    std::string nom;

  public:
    Joueur(std::string nom = "joueur");
    std::string getNom() const;
    void        enregisterNom(const std::string& nom);
};

#endif // JOUEUR_H
