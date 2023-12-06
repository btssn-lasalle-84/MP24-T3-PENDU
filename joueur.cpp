#include "joueur.h"
#include <iostream>
#include <limits>

using namespace std;

Joueur::Joueur(const std::string& nom) : nom(nom)
{
}

std::string Joueur::getNom() const
{
    return this->nom;
}

void Joueur::setEnregisterNom(std::string nom)
{
    this->nom = nom;
}

void Joueur::saisir()
{
    do
    {
        std::cout << "Nom du client ? ";
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
}
