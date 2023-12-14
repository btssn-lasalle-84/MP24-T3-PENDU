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

        if(estFinPartie())
        {
            std::cout << "La partie est terminée.\n";
            break;
        }

    } while(choix != 3);
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
            monInterface->dessinerPendu();
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
