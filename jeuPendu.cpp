#include <iostream>
#include <vector>
#include "joueur.h"
#include "jeuPendu.h"
#include "interfaceJoueurs.h"

JeuPendu::JeuPendu(interfaceJoueurs* monInterface,
                   Dictionnaire*     dictionnaire,
                   std::string&      mot,
                   std::string&      motAtrouver) :
    monInterface(monInterface),
    dictionnaire(dictionnaire), mot(mot), motAtrouver(motAtrouver)
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

bool JeuPendu::estFinPartie()
{
    if(ESSAI <= 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}
void JeuPendu::choisirMot()
{
    setMot(dictionnaire->genererMotSecret());
}
bool JeuPendu::verifierMot()
{
    if(mot == motAtrouver)
    {
        return true;
    }
    else
    {
        return false;
    }
}
