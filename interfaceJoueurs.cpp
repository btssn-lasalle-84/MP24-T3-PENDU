#include "interfaceJoueurs.h"

#include <iostream>

InterfaceJoueurs::InterfaceJoueurs()
{
}

char InterfaceJoueurs::demanderLettre() const
{
    char lettreProposee;
    std::cout << "Entrez une lettre : ";
    std::cin >> lettreProposee;
    return lettreProposee;
}

void InterfaceJoueurs::dessinerPendu()
{
}

void InterfaceJoueurs::afficherTentatives(int                      tentativesRestantes,
                                          const std::vector<char>& lettresUtilisees) const
{
    std::cout << "Tentatives restantes : " << tentativesRestantes << std::endl;
    std::cout << "Lettres utilisées : ";
    for(char lettre: lettresUtilisees)
    {
        std::cout << lettre << " ";
    }
    std::cout << std::endl;
}