#ifndef INTERFACE_JOUEURS_H
#define INTERFACE_JOUEURS_H

#include <string>
#include <vector>

class JeuPendu;
class InterfaceJoueurs
{
  private:
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
};

#endif // INTERFACE_JOUEURS_H