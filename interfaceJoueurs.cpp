#include "interfaceJoueurs.h"
#include <iostream>
#include <limits>

InterfaceJoueurs::InterfaceJoueurs() : lettreProposee('\0'), tentativesRestantes(0)
{
}

void InterfaceJoueurs::dessinerPendu()
{
}

int InterfaceJoueurs::getTentativeRestantes()
{
    return tentativesRestantes;
}

std::string InterfaceJoueurs::saisirNomJoueur()
{
    std::string nom;

    do
    {
        std::cout << "Nom du joueur ? ";
        std::cin >> std::ws; // Ignorer les espaces blancs avant la saisie
        getline(std::cin, nom);

        if(!std::cin.good())
        {
            std::cerr << "Saisie invalide ! Veuillez saisir à nouveau.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            nom = ""; // Réinitialiser la variable
        }
    } while(nom.empty());

    return nom;
}

void InterfaceJoueurs::afficherNomJoueur(const std::string& nom)
{
    std::cout << "Bienvenue " << nom << std::endl;
}
