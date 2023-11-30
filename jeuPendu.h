#ifndef JEU_PENDU_H
#define JEU_PENDU_H
#include <string>
#include <vector>
#include "dictionnaire.h"
#define ESSAI 9

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
    std::string getMot() const;
    void        setMot(std::string mot);
    bool        estFinPartie();
    bool        verifierMot();
    void        jouer();
    void        choisirMot();
    void relationDictionnaire(Dictionnaire* dictionnaire);
    void relationInterfaceJoueurs(interfaceJoueurs* monInterface);

};

#endif // JEU_PENDU_H
