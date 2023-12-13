#ifndef INTERFACE_JOUEURS_H
#define INTERFACE_JOUEURS_H

#include <string>
#include <vector>
class InterfaceJoueurs
{
  private:
    std::vector<char> lettresUtilisees;

  public:
    InterfaceJoueurs();

    static void quitter();
    static void afficherMenu();
    void        dessinerPendu();
    char        demanderLettre();
    void        afficherTentatives(int tentativesRestantes) const;
    std::string saisirNomJoueur();
    void        afficherNomJoueur(const std::string& nom);
    void        afficherMotAtrouver(std::string motAtrouver) const;
     void ajouterLettreUtilisee(char lettre);
};

#endif // INTERFACE_JOUEURS_H