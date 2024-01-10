#include <iostream>
#include <limits>
#include "jeuPendu.h"
#include "interfaceJoueurs.h"
#include "dictionnaire.h"
#include "joueur.h"
#include <ctime>
#include <cstdlib>
using namespace std;

JeuPendu::JeuPendu() :
    monInterface(new InterfaceJoueurs), dictionnaire(new Dictionnaire), monJoueur(new Joueur),
    mot(""), motAtrouver(""), tentativeRestantes(NB_ESSAIS_MAX), lettreProposee()
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
    motAtrouver(jeuPendu.motAtrouver), tentativeRestantes(jeuPendu.tentativeRestantes),
    lettreProposee(jeuPendu.lettreProposee)
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
        lettreProposee     = jeuPendu.lettreProposee;
    }
    return *this;
}

void JeuPendu::lancerPartie()
{
    while(true)
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
                cout << endl;
                cout << "Bien joué la lettre est dans le mot" << endl;
                monInterface->afficherTentatives(tentativeRestantes);

                if(verifierMot())
                {
                    cout << endl;
                    cout << "Félicitations! " << monJoueur->getNom()
                         << "Vous avez trouvé le mot : " << mot << endl;
                    break;
                }
            }
            else if(tentativeRestantes == 0)
            {
                cout << "Il vous reste " << tentativeRestantes
                     << " tentative ! vous avez perdu : " << endl;
                break;
            }
            else if(!verifierLettre(lettreProposee))
            {
                cout << "Lettre incorrecte !" << endl;
                tentativeRestantes--;
                cout << endl;
                monInterface->afficherTentatives(tentativeRestantes);
                monInterface->dessinerPendu(tentativeRestantes);
            }
        }
        tentativeRestantes = NB_ESSAIS_MAX;
        monInterface->viderLettreUtilisee();
        monInterface->afficherMenu(*this);
    }
}

string JeuPendu::getMot() const
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
    bool trouvee                 = false;
    char lettreProposeeMajuscule = std::toupper(lettreProposee);

    for(unsigned int i = 1; i < mot.length() - 1; i++)
    {
        char lettreMotMajuscule = std::toupper(mot[i]);

        if(lettreProposeeMajuscule == lettreMotMajuscule)
        {
            trouvee        = true;
            motAtrouver[i] = lettreProposeeMajuscule;
        }
    }

    return trouvee;
}

void JeuPendu::genererMotAtrouver()
{
    motAtrouver = mot[0] + string(mot.length() - 2, '_') + mot[mot.length() - 1];
#ifdef DEBUG_JEU_PENDU
    cout << "[" << __PRETTY_FUNCTION__ << ":" << __LINE__ << "] ";
    cout << " - motAtrouver : " << motAtrouver << endl;
#endif
}

int JeuPendu::getTentativesRestantes()
{
    return tentativeRestantes;
}
void JeuPendu::choisirMot()
{
    srand(time(0));
    int indiceAleatoire = rand() % dictionnaire->listeMots.size();
    mot                 = dictionnaire->listeMots[indiceAleatoire];
    dictionnaire->genererMotSecret();
}
