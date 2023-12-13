#include <iostream>
#include <limits>
#include "jeuPendu.h"
#include "interfaceJoueurs.h"
#include "dictionnaire.h"
#include "joueur.h"
#include <string>

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

JeuPendu::JeuPendu(const JeuPendu& other) :
    monInterface(new InterfaceJoueurs(*(other.monInterface))),
    dictionnaire(new Dictionnaire(*(other.dictionnaire))),
    monJoueur(new Joueur(*(other.monJoueur))), mot(other.mot), motAtrouver(other.motAtrouver),
    tentativeRestantes(other.tentativeRestantes)
{
}

JeuPendu& JeuPendu::operator=(const JeuPendu& other)
{
    if(this != &other)
    {
        delete monInterface;
        delete dictionnaire;
        delete monJoueur;

        monInterface       = new InterfaceJoueurs(*(other.monInterface));
        dictionnaire       = new Dictionnaire(*(other.dictionnaire));
        monJoueur          = new Joueur(*(other.monJoueur));
        mot                = other.mot;
        motAtrouver        = other.motAtrouver;
        tentativeRestantes = other.tentativeRestantes;
    }
    return *this;
}

void JeuPendu::jouer()
{
    std::cout << "\033[1;31m";

    std::cout << "_________ _______             ______   _______    _______  _______  _        "
                 "______           \n";
    std::cout << "\\__    _/(  ____ \\|\\     /|  (  __  \\ (  ____ \\  (  ____ )(  ____ )( (    "
                 "/|(  __  \\ |\\     /|\n";
    std::cout << "   )  (  | (    \\/| )   ( |  | (  \\  )| (    \\/  | (    )|| (    \\/|  \\  ( "
                 "|| (  \\  )| )   ( |\n";
    std::cout << "   |  |  | (__    | |   | |  | |   ) || (__      | (____)|| (__    |   \\ | || | "
                 "  ) || |   | |\n";
    std::cout << "   |  |  |  __)   | |   | |  | |   | ||  __)     |  _____)|  __)   | (\\ \\) || "
                 "|   | || |   | |\n";
    std::cout << "   |  |  | (      | |   | |  | |   ) || (        | (      | (      | | \\   || | "
                 "  ) || |   | |\n";
    std::cout << "|\\_)  )  | (____/\\| (___) |  | (__/  )| (____/\\  | )      | (____/\\| )  \\  "
                 "|| (__/  )| (___) |\n";
    std::cout << "(____/   (_______/(_______)  (______/ (_______/  |/       (_______/|/    "
                 ")_)(______/ (_______)\n";
    std::cout << "\n\n" << std::endl;

    std::cout << "\033[0m";

    int choix;

    // TODO verifierLettre puis verifierMot
    if(verrifierLettre(lettreProposee))
    {
        verifierMot();
    }
    else
    {
        monInterface->afficherTentatives(tentativeRestantes);
        monInterface->dessinerPendu();
    }
    do
    {
        InterfaceJoueurs::afficherMenu();
        std::cin >> choix;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        switch(choix)

        {
            case 1:

                std::cout << "Lancement d'une nouvelle partie...\n";
                lancerPartie();
                break;
            case 2:

                std::cout << "Afficher les scores...\n";
                break;
            case 3:

                InterfaceJoueurs::quitter();
                break;
            default:

                std::cout << "Option invalide. Veuillez choisir à nouveau.\n";
        }

    } while(choix != 3);
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

}
