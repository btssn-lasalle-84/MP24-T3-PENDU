#include <iostream>
#include <limits>
#include "jeuPendu.h"
#include "interfaceJoueurs.h"
#include "dictionnaire.h"
#include "joueur.h"

JeuPendu::JeuPendu() :
    monInterface(new InterfaceJoueurs), dictionnaire(new Dictionnaire), monJoueur(new Joueur),
    mot(""), motAtrouver(""), tentativeRestantes(NB_ESSAIS_MAX)
{
}

JeuPendu::~JeuPendu()
{
    delete monInterface;
    delete dictionnaire;
    delete monJoueur;
}

JeuPendu::JeuPendu(const JeuPendu& jeuPendu) :
    monInterface(new InterfaceJoueurs(*(jeuPendu.monInterface))),
    dictionnaire(new Dictionnaire(*(jeuPendu.dictionnaire))),
    monJoueur(new Joueur(*(jeuPendu.monJoueur))), mot(jeuPendu.mot),
    motAtrouver(jeuPendu.motAtrouver), tentativeRestantes(jeuPendu.tentativeRestantes)
{
}

JeuPendu& JeuPendu::operator=(const JeuPendu& jeuPendu)
{
    if(this != &jeuPendu)
    {
        delete monInterface;
        delete dictionnaire;
        delete monJoueur;

        monInterface       = new InterfaceJoueurs(*(jeuPendu.monInterface));
        dictionnaire       = new Dictionnaire(*(jeuPendu.dictionnaire));
        monJoueur          = new Joueur(*(jeuPendu.monJoueur));
        mot                = jeuPendu.mot;
        motAtrouver        = jeuPendu.motAtrouver;
        tentativeRestantes = jeuPendu.tentativeRestantes;
    }
    return *this;
}

void JeuPendu::jouer()
{
    monInterface->afficherMenu(*this);
}

void JeuPendu::choisirMot()
{
    mot = dictionnaire->genererMotSecret();
}

void JeuPendu::lancerPartie()
{
    choisirMot();

    monJoueur->enregisterNom(monInterface->saisirNomJoueur());
    monInterface->afficherNomJoueur(monJoueur->getNom());

    // TODO déroulement partie
}

std::string JeuPendu::getMot() const
{
    return mot;
}

bool JeuPendu::estFinPartie() const
{
    return (NB_ESSAIS_MAX <= 0);
}

bool JeuPendu::verifierMot() const
{
    return (mot == motAtrouver);
}