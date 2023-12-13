#ifndef INTERFACE_JOUEURS_H
#define INTERFACE_JOUEURS_H

#include <string>
#include <vector>
class InterfaceJoueurs
{
  private:
  public:
    InterfaceJoueurs();

    static void quitter();
    static void afficherMenu();
    void        dessinerPendu();
    char        demanderLettre() const;
    void        afficherTentatives(int                      tentativesRestantes,
                                   const std::vector<char>& lettresUtilisees) const;
    std::string saisirNomJoueur();
    void        afficherNomJoueur(const std::string& nom);
};

#endif // INTERFACE_JOUEURS_H