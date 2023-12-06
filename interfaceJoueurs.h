#ifndef INTERFACE_JOUEURS_H
#define INTERFACE_JOUEURS_H

#include <string>
#include <vector>

class InterfaceJoueurs
{
  private:
  public:
    InterfaceJoueurs();
<<<<<<< HEAD

    void        dessinerPendu();
    char        demanderLettre() const;
    void        afficherTentatives(int                      tentativesRestantes,
                                   const std::vector<char>& lettresUtilisees) const;
=======
    void        dessinerPendu();
    int         getTentativeRestantes();
>>>>>>> Finalisation du main.cpp et fabrication pendu.out
    std::string saisirNomJoueur();
    void        afficherNomJoueur(const std::string& nom);
};

#endif // INTERFACE_JOUEURS_H