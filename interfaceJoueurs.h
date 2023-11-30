#ifndef INTERFACE_JOUEURS_H
#define INTERFACE_JOUEURS_H

#include <string>

class interfaceJoueurs
{
    private :
    char lettreProposee;

    public :
    interfaceJoueurs (char lettreProposee);
    void dessinerPendu();
};

#endif //INTERFACE_JOUEUR_H