#ifndef INTERFACE_JOUEURS_H
#define INTERFACE_JOUEURS_H

#include <string>
#include <vector>
#include "score.h"

class JeuPendu;

class InterfaceJoueurs
{
  private:
    std::vector<char>  lettresUtilisees;
    std::vector<Score> scores;

    void quitter();
    void viderBuffer();

  public:
    InterfaceJoueurs();
    void        lancerPartie();
    void        afficherScores();
    void        viderLettreUtilisee();
    void        afficherMenu(JeuPendu& jeuPendu);
    char        demanderLettre();
    void        afficherTentatives(int tentativesRestantes);
    void        dessinerPendu(int tentativesRestantes);
    std::string saisirNomJoueur();
    void        afficherNomJoueur(const std::string& nom);
    void        ajouterLettreUtilisee(char lettre);
    void        afficherMotATrouver(const std::string& motATrouver) const;
    void        afficherRegle();
    void        ajouterScore(const std::string& nom, int tentativesRestantes);
};

#endif // INTERFACE_JOUEURS_H