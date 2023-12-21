#ifndef INTERFACE_JOUEURS_H
#define INTERFACE_JOUEURS_H

#include <string>
#include <vector>

class JeuPendu;
class InterfaceJoueurs
{
  private:
    std::vector<char> lettresUtilisees;

  public:
    InterfaceJoueurs();
    void        afficherScores(const std::string& nom, int tentativesRestantes);
    void        quitter();
    void        afficherMenu(JeuPendu& jeuPendu);
    char        demanderLettre();
    void        afficherTentatives(int tentativesRestantes);
    void        dessinerPendu(int tentativesRestantes);
    std::string saisirNomJoueur();
    void        afficherNomJoueur(const std::string& nom);
    void        ajouterLettreUtilisee(char lettre);
    void        afficherMotATrouver(const std::string& motATrouver) const;
    void        afficherRegle();
};

#endif // INTERFACE_JOUEURS_H