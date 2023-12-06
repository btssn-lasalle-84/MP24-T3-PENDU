#ifndef INTERFACE_JOUEURS_H
#define INTERFACE_JOUEURS_H

#include <string>
#include <vector>

class interfaceJoueurs
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