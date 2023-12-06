#ifndef JEU_PENDU_H

#define JEU_PENDU_H
#define ESSAI 9

#include <string>
#include <vector>
#include "dictionnaire.h"

class Joueur;
class Dictionnaire;
class interfaceJoueurs;

class JeuPendu
{
  private:
    interfaceJoueurs* monInterface;
    Dictionnaire*     dictionnaire;
    std::string&      mot;

  public:
    JeuPendu(interfaceJoueurs* monInterface, Dictionnaire* dictionnaire, std::string& mot);
    std::string getMot();
    void        setMot(std::string mot);
    bool        estFinPartie() const;
    bool        verifierMot() const;
    void        jouer();
    void        choisirMot();
    void        relationDictionnaire(Dictionnaire* dictionnaire);
    void        relationInterfaceJoueurs(interfaceJoueurs* monInterface);
};

#endif // JEU_PENDU_H