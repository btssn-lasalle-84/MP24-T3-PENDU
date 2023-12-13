#ifndef JEU_PENDU_H
#define JEU_PENDU_H

#include <string>

#define NB_ESSAIS_MAX 9

class InterfaceJoueurs;
class Dictionnaire;
class Joueur;

class JeuPendu
{
  private:
    InterfaceJoueurs* monInterface;
    Dictionnaire*     dictionnaire;
    Joueur*           monJoueur;
    std::string       mot;
    std::string       motAtrouver;
    int               tentativeRestantes;

  public:
    JeuPendu();

    void jouer();

    void        choisirMot();
    std::string getMot() const;
    bool        estFinPartie() const;
    bool        verrifierLettre(char lettreProposee) const;
    bool        verifierMot() const;
};

#endif // JEU_PENDU_H