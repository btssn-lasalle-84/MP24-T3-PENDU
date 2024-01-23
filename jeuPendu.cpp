#include "jeuPendu.h"
#include "interfaceJoueurs.h"
#include "dictionnaire.h"
#include "joueur.h"
#include <iostream>
#include <limits>
#include <ctime>
#include <cstdlib>

using namespace std;

JeuPendu::JeuPendu() :
    monInterface(new InterfaceJoueurs), dictionnaire(new Dictionnaire), monJoueur(new Joueur),
    mot(""), motATrouver(""), tentativesRestantes(NB_ESSAIS_MAX), lettreProposee()
{
}

JeuPendu::~JeuPendu()
{
    delete monInterface;
    delete dictionnaire;
    delete monJoueur;
}

JeuPendu::JeuPendu(const JeuPendu& jeuPendu) :
    monInterface(new InterfaceJoueurs), dictionnaire(new Dictionnaire),
    monJoueur(new Joueur(jeuPendu.monJoueur->getNom())), mot(jeuPendu.mot),
    motATrouver(jeuPendu.motATrouver), tentativesRestantes(jeuPendu.tentativesRestantes),
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

        monInterface        = new InterfaceJoueurs;
        dictionnaire        = new Dictionnaire;
        monJoueur           = new Joueur(jeuPendu.monJoueur->getNom());
        mot                 = jeuPendu.mot;
        motATrouver         = jeuPendu.motATrouver;
        tentativesRestantes = jeuPendu.tentativesRestantes;
        lettreProposee      = jeuPendu.lettreProposee;
    }
    return *this;
}

void JeuPendu::demarrer()
{
    monInterface->afficherInformations();
    monInterface->afficherRegles();
    monJoueur->enregisterNom(monInterface->saisirNomJoueur());
    monInterface->afficherNomJoueur(monJoueur->getNom());

    int choix = 0;
    do
    {
        choix = monInterface->afficherMenu();
        // @todo : utiliser un enum pour les choix de menu
        switch(choix)
        {
            case 1:
                lancerPartie();
                break;
            case 2:
                monInterface->afficherScores();
                break;
            case 3:
                monInterface->quitter();
                break;
        }
    } while(choix != 3);
}

void JeuPendu::lancerPartie()
{
    int choixTheme = monInterface->choisirTheme(dictionnaire->getListeThemes());
    dictionnaire->charger(choixTheme);

    choisirMot();
    genererMotATrouver();

    do
    {
        monInterface->afficherMotATrouver(motATrouver);
        char lettreProposee = monInterface->demanderLettre();

        if(verifierLettre(lettreProposee))
        {
            monInterface->afficherMessage("\nBien joué ! La lettre est dans le mot.\n");
            monInterface->afficherTentatives(tentativesRestantes);

            if(verifierMot())
            {
                monInterface->afficherMessage("\nFélicitations " + monJoueur->getNom() +
                                              " !\nVous avez trouvé le mot : " + mot + " avec " +
                                              to_string(NB_ESSAIS_MAX - tentativesRestantes) +
                                              " erreur(s)\n");
            }
        }

        else if(!verifierLettre(lettreProposee))
        {
            monInterface->afficherMessage("\nOups ! La lettre n'est pas dans ce mot.\n");
            tentativesRestantes--;
            monInterface->afficherTentatives(tentativesRestantes);
            monInterface->dessinerPendu(tentativesRestantes);
        }
    } while(!estFinPartie());

    if(tentativesRestantes == 0)
    {
        monInterface->afficherMessage("\nDésolé ! Vous avez perdu.\n");
    }

    monInterface->ajouterScore(monJoueur->getNom(), tentativesRestantes);
    tentativesRestantes = NB_ESSAIS_MAX;
    monInterface->viderLettreUtilisee();
}

string JeuPendu::getMot() const
{
    return mot;
}

bool JeuPendu::estFinPartie() const
{
    return (tentativesRestantes <= 0 || verifierMot());
}

bool JeuPendu::verifierMot() const
{
    return (mot == motATrouver);
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
            motATrouver[i] = lettreProposeeMajuscule;
        }
    }

    return trouvee;
}

void JeuPendu::genererMotATrouver()
{
    motATrouver = mot[0] + string(mot.length() - 2, '_') + mot[mot.length() - 1];
#ifdef DEBUG_JEU_PENDU
    cout << "[" << __PRETTY_FUNCTION__ << ":" << __LINE__ << "] ";
    cout << " - motATrouver : " << motATrouver << endl;
#endif
}

int JeuPendu::getTentativesRestantes()
{
    return tentativesRestantes;
}

void JeuPendu::choisirMot()
{
    mot = dictionnaire->genererMotSecret();
}

/*void JeuPendu::choisirTheme()
{
    int choix;
    cout << "****************************\n";
    cout << "**   1. École             **\n";
    cout << "**   2. Plage             **\n";
    cout << "**   3. Numérique         **\n";
    cout << "**   4. Retour            **\n";
    cout << "****************************\n";
    cout << "Choisissez le thème : ";
    cin >> choix;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << endl;
    do
    {
        switch(choix)
        {
            case 1:
                lancerPartie();
                jeuPendu.lancerPartie();
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                monInterface->afficherMenu(*this);
                break;
            default:
                cout << "Option invalide. Veuillez choisir à nouveau.\n";
        }

    } while(choix != 3);
}
*/