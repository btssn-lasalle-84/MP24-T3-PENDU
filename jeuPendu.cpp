#include "jeuPendu.h"
#include <iostream>
#include <vector>
#include "joueur.h"
#include "jeuPendu.h"
#include "interfaceJoueurs.h"

JeuPendu::JeuPendu(interfaceJoueurs* monInterface, Dictionnaire* dictionnaire, std::string& mot) :
    mot(mot)
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

void JeuPendu::relationDictionnaire(Dictionnaire* dictionnaire) 
{
    this->dictionnaire = dictionnaire;
}
void JeuPendu::relationInterfaceJoueurs(interfaceJoueurs* monInterface)
{
    this->monInterface = monInterface;
}