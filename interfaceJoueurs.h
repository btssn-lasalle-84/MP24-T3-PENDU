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


    void        quitter();
    void        afficherMenu(JeuPendu& jeuPendu);
    void        dessinerPendu();
    char        demanderLettre() const;
    void        afficherTentatives(int                      tentativesRestantes,
                                   const std::vector<char>& lettresUtilisees) const;
    std::string saisirNomJoueur();
    void        afficherNomJoueur(const std::string& nom);
    void        afficherMotAtrouver(std::string motAtrouver) const;
    void        ajouterLettreUtilisee(char lettre);
};

#endif // INTERFACE_JOUEURS_H