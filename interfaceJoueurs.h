#ifndef INTERFACE_JOUEUR_H
#define INTERFACE_JOUEUR_H

#include <string>

class interfaceJoueur 
{
    private :
    char lettreProposee;

    public :
    interfaceJoueur (char lettreProposee);
    void dessinerPendu();
};

#endif //INTERFACE_JOUEUR_H