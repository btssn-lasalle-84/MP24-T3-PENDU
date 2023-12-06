#include <iostream>
#include <vector>
#include "joueur.h"
#include "jeuPendu.h"
#include "interfaceJoueurs.h"

JeuPendu::JeuPendu(interfaceJoueurs* monInterface, Dictionnaire* dictionnaire, std::string& mot) :
    monInterface(monInterface), dictionnaire(dictionnaire), mot(mot)
{
}

std::string JeuPendu::getMot()
{
    return mot;
}

void JeuPendu::setMot(std::string mot)
{
    this->mot = mot;
}

bool JeuPendu::estFinPartie() const
{
    // Implémentez conditions de fin de partie
    return false;
}

bool JeuPendu::verifierMot() const
{
    // Implémentez conditions de vérifications
    return false;
}

void JeuPendu::choisirMot()
{
    setMot(dictionnaire->genererMotSecret());
}

void JeuPendu::relationDictionnaire(Dictionnaire* dictionnaire)
{
    this->dictionnaire = dictionnaire;
}
void JeuPendu::relationInterfaceJoueurs(interfaceJoueurs* monInterface)
{
    this->monInterface = monInterface;
}