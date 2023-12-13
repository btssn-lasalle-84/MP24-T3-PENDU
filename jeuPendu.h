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
    char              lettreProposee;

  public:
    JeuPendu();
    ~JeuPendu();
    JeuPendu(const JeuPendu& other);
    JeuPendu& operator=(const JeuPendu& other);

    void        jouer();
    void        choisirMot();
    void        lancerPartie();
    std::string getMot() const;
    bool        estFinPartie() const;
    bool        verifierMot() const;
    bool        verrifierLettre(char lettreProposee);
    void        afficherMotAtrouver();
};

#endif // JEU_PENDU_H