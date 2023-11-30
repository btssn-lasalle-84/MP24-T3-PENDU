#include "jeuPendu.h"
#include <iostream>
#include <vector>
#include "joueur.h"
#include "jeuPendu.h"


JeuPendu::JeuPendu(Joueur* monJoueur, Dictionnaire* dictionnaire) :
    monJoueur(monJoueur), dictionnaire(dictionnaire)
{
}

std::string JeuPendu::getMot() const

{
    return mot;
}

void JeuPendu::setMot(std::string mot)
{
    this->mot = mot;
}

