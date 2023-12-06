#include "joueur.h"
#include <iostream>

using namespace std;

Joueur::Joueur(const std::string& nom) : nom(nom)
{
}

void Joueur::setEnregisterNom(std::string nom)
{
    this->nom = nom;
}
int Joueur::getTentativeRestantes()
{
    return tentativesRestantes;
}
