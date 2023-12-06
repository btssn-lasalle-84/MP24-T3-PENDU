#ifndef INTERFACE_JOUEURS_H
#define INTERFACE_JOUEURS_H

#include <string>

class InterfaceJoueurs
{
  private:
    char lettreProposee;
    int  tentativesRestantes;

  public:
    InterfaceJoueurs();
    void        dessinerPendu();
    int         getTentativeRestantes();
    std::string saisirNomJoueur();
    void        afficherNomJoueur(const std::string& nom);
};

#endif // INTERFACE_JOUEUR_H