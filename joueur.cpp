#include "joueur.h"

using namespace std;

Joueur::Joueur(string nom) : nom(nom)
{
}

string Joueur::getNom() const
{
    return this->nom;
}

void Joueur::enregisterNom(const string& nom)
{
    this->nom = nom;
}
