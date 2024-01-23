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

    void viderBuffer() const;

  public:
    InterfaceJoueurs();

    void        afficherInformations();
    int         afficherMenu();
    void        quitter();
    void        ajouterLettreUtilisee(char lettre);
    char        demanderLettre();
    void        afficherTentatives(int tentativesRestantes);
    void        dessinerPendu(int tentativesRestantes);
    std::string saisirNomJoueur();
    void        afficherNomJoueur(const std::string& nom);
    void        afficherMotATrouver(const std::string& motATrouver) const;
    void        afficherRegles();
    void        afficherScores();
    void        ajouterScore(const std::string& nom, int tentativesRestantes);
    void        viderLettreUtilisee();
    void        afficherMessage(const std::string& message) const;
    int         choisirTheme(const std::vector<std::string>& themes) const;
};

#endif // INTERFACE_JOUEURS_H