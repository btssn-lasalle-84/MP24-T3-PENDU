#include "joueur.h"
#include <iostream>

using namespace std;

Joueur::Joueur(string nom, int tentativesRestantes) :
    nom(nom), tentativesRestantes(tentativesRestantes)
{
}

void Joueur::enregisterNom()
{
    cout << "saisir votre nom : " << endl;
    cin >> nom;
}

int Joueur::getTentative()
{
    return tentativesRestantes;
}