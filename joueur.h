#ifndef JOUEUR_H
#define JOUEUR_H
#include <string>
class Joueur
{
  private:
    std::string nom;

  public:
    Joueur(const std::string& nom);
    std::string getNom() const;
    void        setEnregisterNom(std::string nom);
    void        saisir();
};

#endif // JOUEUR_H
