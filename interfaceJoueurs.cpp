#include "interfaceJoueurs.h"
#include <iostream>
#include <limits>

InterfaceJoueurs::InterfaceJoueurs()
{
}

void InterfaceJoueurs::dessinerPendu()
{
}

char InterfaceJoueurs::demanderLettre() const
{
    char lettreProposee;
    std::cout << "Entrez une lettre : ";
    std::cin >> lettreProposee;
    return lettreProposee;
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
