#include "joueur.h"

Joueur::Joueur(std::string nom) : nom(nom)
{
}

std::string Joueur::getNom() const
{
    return this->nom;
}

void Joueur::enregisterNom(const std::string& nom)
{
    this->nom = nom;
}
