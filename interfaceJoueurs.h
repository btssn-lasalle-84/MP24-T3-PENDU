#ifndef INTERFACE_JOUEURS_H
#define INTERFACE_JOUEURS_H

#include <string>
#include <vector>

class InterfaceJoueurs
{
  private:

  public:
    interfaceJoueurs();

    char demanderLettre() const;
    void dessinerPendu();
    void afficherTentatives(int                      tentativesRestantes,
                            const std::vector<char>& lettresUtilisees) const;
};

#endif // INTERFACE_JOUEURS_H

    char lettreProposee;
    int  tentativesRestantes;

  public:
    InterfaceJoueurs();
    void dessinerPendu();
    int  getTentativeRestantes();
};

#endif // INTERFACE_JOUEUR_H