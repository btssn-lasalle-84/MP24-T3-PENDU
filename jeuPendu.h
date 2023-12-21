#ifndef JEU_PENDU_H
#define JEU_PENDU_H

#include <string>

#define NB_ESSAIS_MAX 11

//#define DEBUG_JEU_PENDU

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
    char              lettreProposee;

  public:
    JeuPendu();
    ~JeuPendu();
    JeuPendu(const JeuPendu& autre);
    JeuPendu& operator=(const JeuPendu& autre);

    void        jouer();
    void        choisirMot();
    void        lancerPartie();
    std::string getMot() const;
    bool        estFinPartie() const;
    bool        verifierMot() const;
    bool        verifierLettre(char lettreProposee);
    void        genererMotAtrouver();
    int         getTentativesRestantes();
};

#endif // JEU_PENDU_H