#include <iostream>
#include <limits>
#include "jeuPendu.h"
#include "interfaceJoueurs.h"
#include "dictionnaire.h"
#include "joueur.h"
#include <ctime>
#include <cstdlib>

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
    monInterface->afficherRegle();
    choisirMot();
    genererMotAtrouver();

    monJoueur->enregisterNom(monInterface->saisirNomJoueur());
    monInterface->afficherNomJoueur(monJoueur->getNom());

    while(!estFinPartie())
    {
        monInterface->afficherMotATrouver(motAtrouver);
        char lettreProposee = monInterface->demanderLettre();

        if(verifierLettre(lettreProposee))
        {
            std::cout << std::endl;
            std::cout << "Bien joué la lettre est dans le mot" << std::endl;

            if(verifierMot())
            {
                std::cout << "Félicitations! Vous avez trouvé le mot : " << mot << std::endl;
                monInterface->quitter();
                break;
            }
        }
        else
        {
            std::cout << "Lettre incorrect !" << std::endl;
            tentativeRestantes--;
            std::cout << std::endl;
            monInterface->afficherTentatives(tentativeRestantes);
            monInterface->dessinerPendu(tentativeRestantes);
        }
    }
    std::cout << "Vous avez perdue ! la partie est finie" << std::endl;
    monInterface->quitter();
}

void JeuPendu::choisirMot()
{
    std::srand(std::time(0));

    int indiceAleatoire = std::rand() % dictionnaire->listeMots.size();

    mot = dictionnaire->listeMots[indiceAleatoire];
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

bool JeuPendu::verifierLettre(char lettreProposee)
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

void JeuPendu::genererMotAtrouver()
{
    motAtrouver = mot[0] + std::string(mot.length() - 2, '_' ) + mot[mot.length() - 1];
#ifdef DEBUG_JEU_PENDU
    std::cout << "[" << __PRETTY_FUNCTION__ << ":" << __LINE__ << "] ";
    std::cout << " - motAtrouver : " << motAtrouver << std::endl;
#endif
}
