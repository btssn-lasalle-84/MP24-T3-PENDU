#ifndef INTERFACE_JOUEURS_H
#define INTERFACE_JOUEURS_H

#include <string>
#include <vector>

using namespace std;

class JeuPendu;
class InterfaceJoueurs
{
  private:
    void quitter();

  public:
    vector<char> lettresUtilisees;
    InterfaceJoueurs();
    void   lancerPartie();
    void   afficherScores(const string& nom, int tentativesRestantes);
    void   viderLettreUtilisee();
    void   afficherMenu(JeuPendu& jeuPendu);
    char   demanderLettre();
    void   afficherTentatives(int tentativesRestantes);
    void   dessinerPendu(int tentativesRestantes);
    string saisirNomJoueur();
    void   afficherNomJoueur(const string& nom);
    void   ajouterLettreUtilisee(char lettre);
    void   afficherMotATrouver(const string& motATrouver) const;
    void   afficherRegle();
};

#endif // INTERFACE_JOUEURS_H