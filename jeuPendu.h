#ifndef JEU_PENDU_H
#define JEU_PENDU_H
#include <string>
#include <vector>
#include "dictionnaire.h"

class Joueur;
class Dictionnaire;

class JeuPendu
{
  private:
    std::vector<int> pendu();
    Joueur *monJoueur;
    Dictionnaire*    dictionnaire;
    int              essai = 9;
    std::string      mot;

  public:
    JeuPendu(Joueur* monJoueur = nullptr, Dictionnaire* dictionaire = nullptr);
    std::string getMot() const;
    void        setMot(std::string mot);
    bool        estFinPartie();
    bool        verifierMot();
    void        jouer();
    void        choisirMot();
};

#endif // JEU_PENDU_H
