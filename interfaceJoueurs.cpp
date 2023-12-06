#include "interfaceJoueurs.h"
#include <iostream>
#include <limits>
<<<<<<< HEAD

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
=======
>>>>>>> Finalisation du main.cpp et fabrication pendu.out

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

<<<<<<< HEAD
std::string InterfaceJoueurs::saisirNomJoueur()
{
=======
void InterfaceJoueurs::dessinerPendu()
{
}

int InterfaceJoueurs::getTentativeRestantes()
{
    return tentativesRestantes;
}

std::string InterfaceJoueurs::saisirNomJoueur()
{
>>>>>>> Finalisation du main.cpp et fabrication pendu.out
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
