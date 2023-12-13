#include "jeuPendu.h"
#include "interfaceJoueurs.h"
#include "dictionnaire.h"
#include "joueur.h"

JeuPendu::JeuPendu() :
    monInterface(new InterfaceJoueurs), dictionnaire(new Dictionnaire), monJoueur(new Joueur),
    mot(""), motAtrouver(""), tentativeRestantes(NB_ESSAIS_MAX)
{
}

void JeuPendu::jouer()
{
    choisirMot();

    monJoueur->enregisterNom(monInterface->saisirNomJoueur());
    monInterface->afficherNomJoueur(monJoueur->getNom());

    char lettreProposee = monInterface->demanderLettre();

    // TODO verifierLettre puis verifierMot

    monInterface->dessinerPendu();

    monInterface->afficherTentatives(tentativeRestantes);
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
    return (NB_ESSAIS_MAX <= 0);
}

bool JeuPendu::verifierMot() const
{
    return (mot == motAtrouver);
}

bool JeuPendu::verrifierLettre(char lettreProposee) const
{
    for(int i = 0; motAtrouver[i] != '\0'; i++)
    {
        if(lettreProposee == motAtrouver[i])
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    return 0;
}
