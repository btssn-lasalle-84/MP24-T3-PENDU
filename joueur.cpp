#include "joueur.h"
#include <iostream>

Joueur::Joueur(string nom, int tentativeRestantes)
    : nom(nom), tentativeRestantes(tentativeRestantes) {}

void Joueur::enregisterNom() {
  cout << "saisir votre nom : " << endl;
  cin >> nom;
}

