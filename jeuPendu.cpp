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

void JeuPendu::lancerPartie()
{
    choisirMot();

    monJoueur->enregisterNom(monInterface->saisirNomJoueur());
    monInterface->afficherNomJoueur(monJoueur->getNom());
    afficherMotAtrouver();

    while(!estFinPartie())
    {
        char lettreProposee = monInterface->demanderLettre();

        if(verrifierLettre(lettreProposee))
        {
            if(verifierMot())
            {
                std::cout << "Félicitations! Vous avez trouvé le mot : " << mot << std::endl;
                break;
            }
        }
        else
        {
            tentativeRestantes--;
            monInterface->afficherTentatives(tentativeRestantes);
            monInterface->dessinerPendu(tentativeRestantes);
        }
    }
}

void JeuPendu::choisirMot()
{
    mot = dictionnaire->genererMotSecret();
}
std::string JeuPendu::getMot() const
{
    return mot;
}

bool JeuPendu::estFinPartie() const
{
    return (tentativeRestantes <= 0 || verifierMot());
}

bool JeuPendu::verifierMot() const
{
    return (mot == motAtrouver);
}

bool JeuPendu::verrifierLettre(char lettreProposee)
{
    bool trouvee = false;
    for(unsigned int i = 1; i < mot.length() - 1; i++)
    {
        if(lettreProposee == mot[i])
        {
            trouvee        = true;
            motAtrouver[i] = lettreProposee;
        }
    }
    return trouvee;
}
void JeuPendu::afficherMotAtrouver()
{
    motAtrouver = mot[0] + std::string(mot.length() - 2, '-') + mot[mot.length() - 1];
    std::cout << "Le mot à trouver est : " << motAtrouver << std::endl;
}
