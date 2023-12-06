#ifndef JEU_PENDU_H
#define JEU_PENDU_H
#define ESSAI 9

#include <string>
#include <vector>
#include "dictionnaire.h"
#include "joueur.h"

class Joueur;
class Dictionnaire;
class interfaceJoueurs;
class JeuPendu
{
  private:
    interfaceJoueurs* monInterface;
    Dictionnaire*     dictionnaire;
    std::string&      mot;
    std::string&      motAtrouver;
    int               tentativeRestantes = ESSAI;
    Joueur*           monJoueur;

  public:
    JeuPendu(interfaceJoueurs* monInterface,
             Dictionnaire*     dictionnaire,
             std::string&      mot,
             std::string&      motAtrouver);
    std::string getMot() const;
    void        setMot(std::string mot);
    bool        estFinPartie();
    bool        verifierMot();
    void        choisirMot();
    void        jouer();
    void        relationDictionnaire(Dictionnaire* dictionnaire);
    void        relationInterfaceJoueurs(interfaceJoueurs* monInterface);
    void        relationJoueur(Joueur* monJoueur);
};

#endif // JEU_PENDU_H