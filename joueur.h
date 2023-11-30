#ifndef JOUEUR_H
#define JOUEUR_H
#include <string>
class Joueur
{
  private:
    std::string nom;
    int         tentativesRestantes;

  public:
    Joueur(const std::string& nom);
    void setEnregisterNom(std::string nom);
    int  getTentativeRestantes();
};

#endif // JOUEUR_H
