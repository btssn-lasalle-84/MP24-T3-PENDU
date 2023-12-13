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

    void        dessinerPendu();
    char        demanderLettre() const;
    void        afficherTentatives(int tentativesRestantes) const;
    std::string saisirNomJoueur();
    void        afficherNomJoueur(const std::string& nom);
    void        afficherMotAtrouver(std::string motAtrouver) const;
};

#endif // INTERFACE_JOUEURS_H