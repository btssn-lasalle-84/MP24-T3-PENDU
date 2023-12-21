#include "interfaceJoueurs.h"
#include "jeuPendu.h"
#include <iostream>
#include <limits>
#include <iomanip>
#include <algorithm>

using namespace std;

InterfaceJoueurs::InterfaceJoueurs() : lettresUtilisees()
{
}

void InterfaceJoueurs::afficherMenu(JeuPendu& jeuPendu)
{
    int choix;

    std::cout << "\033[1;31m";

    std::cout << "      _   ______  _    _     _____    _    _     ______   ______  ______   _____ "
                 "   _    _    1.1\n";
    std::cout << "     | | | |     | |  | |   | | \\ \\  | |  | |   | |  | \\ | |     | |  \\ \\ | "
                 "| \\ \\  | |  | |\n";
    std::cout << " _   | | | |---- | |  | |   | |  | | | |  | |   | |__|_/ | |---- | |  | | | |  | "
                 "| | |  | |\n";
    std::cout << "|_|__|_| |_|____ \\_|__|_|   |_|_/ /  \\_|__|_|   |_|      |_|____ |_|  |_| "
                 "|_|_/ /  \\_|__|_|\n";
    std::cout << "\n\n";

    std::cout << "\033[0m";

    cout << "****************************\n";
    cout << "**   1. Nouvelle partie   **\n";
    cout << "**   2. Scores            **\n";
    cout << "**   3. Quitter           **\n";
    cout << "****************************\n";
    cout << "Choisissez une option : ";
    cin >> choix;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << endl;
    do
    {
        switch(choix)
        {
            case 1:
                cout << "Lancement d'une nouvelle partie...\n";
                jeuPendu.lancerPartie();
                break;
            case 2:
                afficherScores("nom", jeuPendu.getTentativesRestantes());
                afficherMenu(jeuPendu);
                break;
            case 3:
                quitter();
                break;
            default:
                cout << "Option invalide. Veuillez choisir à nouveau.\n";
        }

    } while(choix != 3);
}
void InterfaceJoueurs::afficherScores(const string& nom, int tentativesRestantes)
{
    cout << "Le joueur " << nom << " a réussi en " << 11 - tentativesRestantes << " essais\n";
}

void InterfaceJoueurs::quitter()
{
    cout << "Bye Bye, Merci d'avoir joué.\n";
    exit(0);
}

void InterfaceJoueurs::ajouterLettreUtilisee(char lettre)
{
    lettresUtilisees.push_back(lettre);
}

char InterfaceJoueurs::demanderLettre()
{
    char lettreProposee;

    do
    {
        cout << "Entrez une lettre : ";
        cin >> lettreProposee;

        if(find(lettresUtilisees.begin(), lettresUtilisees.end(), lettreProposee) !=
           lettresUtilisees.end())
        {
            cout << "Vous avez déjà proposé cette lettre. Veuillez en choisir une autre." << endl;
        }
        else
        {
            ajouterLettreUtilisee(lettreProposee);
            break;
        }
    } while(true);

    return lettreProposee;
}

void InterfaceJoueurs::afficherTentatives(int tentativesRestantes)
{
    cout << "Tentatives restantes : " << tentativesRestantes << endl;
    cout << "Lettres utilisées : ";
    for(char lettre: lettresUtilisees)
    {
        cout << lettre << " ";
    }
    cout << endl;
}

void InterfaceJoueurs::dessinerPendu(int tentativesRestantes)
{
    if(tentativesRestantes == 10)
    {
        std::cout << std::setfill('\n') << std::setw(6) << '\n';
        std::cout << std::setfill('-') << std::setw(11) << '\n';
        std::cout << "\033[94m"
                  << "Première tentative : Nan"
                  << "\033[0m" << std::endl;
        std::cout << '\n';
    }
    if(tentativesRestantes == 9)
    {
        std::cout << '\n';
        std::cout << std::setfill(' ') << std::setw(5) << "|" << '\n';
        std::cout << std::setfill(' ') << std::setw(5) << "|" << '\n';
        std::cout << std::setfill(' ') << std::setw(5) << "|" << '\n';
        std::cout << std::setfill(' ') << std::setw(5) << "|" << '\n';
        std::cout << std::setfill(' ') << std::setw(5) << "|" << '\n';
        std::cout << std::setfill('-') << std::setw(11) << '\n';
        std::cout << "\033[94m"
                  << "Deuxième tentative : Toujours pas"
                  << "\033[0m" << std::endl;
        std::cout << '\n';
    }
    if(tentativesRestantes == 8)
    {
        std::cout << std::setfill(' ') << std::setw(13) << "_________" << '\n';
        std::cout << std::setfill(' ') << std::setw(5) << "|" << '\n';
        std::cout << std::setfill(' ') << std::setw(5) << "|" << '\n';
        std::cout << std::setfill(' ') << std::setw(5) << "|" << '\n';
        std::cout << std::setfill(' ') << std::setw(5) << "|" << '\n';
        std::cout << std::setfill(' ') << std::setw(5) << "|" << '\n';
        std::cout << std::setfill('-') << std::setw(11) << '\n';
        std::cout << "\033[34m"
                  << "Deuxième tentative : Oui main non"
                  << "\033[0m" << std::endl;
        std::cout << '\n';
    }
    if(tentativesRestantes == 7)
    {
        std::cout << std::setfill(' ') << std::setw(13) << "_________" << '\n';
        std::cout << std::setfill(' ') << std::setw(5) << "|"
                  << "/" << '\n';
        std::cout << std::setfill(' ') << std::setw(5) << "|" << '\n';
        std::cout << std::setfill(' ') << std::setw(5) << "|" << '\n';
        std::cout << std::setfill(' ') << std::setw(5) << "|" << '\n';
        std::cout << std::setfill(' ') << std::setw(5) << "|" << '\n';
        std::cout << std::setfill('-') << std::setw(11) << '\n';
        std::cout << "\033[34m"
                  << "Troisième tentative : C'est pas encore ça"
                  << "\033[0m" << std::endl;
        std::cout << '\n';
    }
    if(tentativesRestantes == 6)
    {
        std::cout << std::setfill(' ') << std::setw(13) << "_________" << '\n';
        std::cout << std::setfill(' ') << std::setw(5) << "|"
                  << "/" << std::setfill(' ') << std::setw(6) << '|' << '\n';
        std::cout << std::setfill(' ') << std::setw(5) << "|" << '\n';
        std::cout << std::setfill(' ') << std::setw(5) << "|" << '\n';
        std::cout << std::setfill(' ') << std::setw(5) << "|" << '\n';
        std::cout << std::setfill(' ') << std::setw(5) << "|" << '\n';
        std::cout << std::setfill('-') << std::setw(11) << '\n';
        std::cout << "\033[36m"
                  << "Quatrième tentative : Sérieusement ?"
                  << "\033[0m" << std::endl;
        std::cout << '\n';
    }
    if(tentativesRestantes == 5)
    {
        std::cout << std::setfill(' ') << std::setw(13) << "_________" << '\n';
        std::cout << std::setfill(' ') << std::setw(5) << "|"
                  << "/" << std::setfill(' ') << std::setw(6) << '|' << '\n';
        std::cout << std::setfill(' ') << std::setw(5) << "|" << std::setw(7) << 'O' << '\n';
        std::cout << std::setfill(' ') << std::setw(5) << "|" << '\n';
        std::cout << std::setfill(' ') << std::setw(5) << "|" << '\n';
        std::cout << std::setfill(' ') << std::setw(5) << "|" << '\n';
        std::cout << std::setfill('-') << std::setw(11) << '\n';
        std::cout << "\033[96m"
                  << "Cinquième tentative : Nuh uh"
                  << "\033[0m" << std::endl;
        std::cout << '\n';
    }
    if(tentativesRestantes == 4)
    {
        std::cout << std::setfill(' ') << std::setw(13) << "_________" << '\n';
        std::cout << std::setfill(' ') << std::setw(5) << "|"
                  << "/" << std::setfill(' ') << std::setw(6) << '|' << '\n';
        std::cout << std::setfill(' ') << std::setw(5) << "|" << std::setw(7) << 'O' << '\n';
        std::cout << std::setfill(' ') << std::setw(5) << "|" << std::setfill(' ') << std::setw(7)
                  << '|' << '\n';
        std::cout << std::setfill(' ') << std::setw(5) << "|" << '\n';
        std::cout << std::setfill(' ') << std::setw(5) << "|" << '\n';
        std::cout << std::setfill('-') << std::setw(11) << '\n';
        std::cout << "\033[92m"
                  << "Sixième tentative : Nope, nope et nope"
                  << "\033[0m" << std::endl;
        std::cout << '\n';
    }
    if(tentativesRestantes == 3)
    {
        std::cout << std::setfill(' ') << std::setw(13) << "_________" << '\n';
        std::cout << std::setfill(' ') << std::setw(5) << "|"
                  << "/" << std::setfill(' ') << std::setw(6) << '|' << '\n';
        std::cout << std::setfill(' ') << std::setw(5) << "|" << std::setw(7) << 'O' << '\n';
        std::cout << std::setfill(' ') << std::setw(5) << "|" << std::setfill(' ') << std::setw(7)
                  << '|' << '\n';
        std::cout << std::setfill(' ') << std::setw(5) << "|" << std::setw(6) << '/' << '\n';
        std::cout << std::setfill(' ') << std::setw(5) << "|" << '\n';
        std::cout << std::setfill('-') << std::setw(11) << '\n';
        std::cout << "\033[32m"
                  << "Septième tentative : Bon faut pas le faire exprès non plus"
                  << "\033[0m" << std::endl;
        std::cout << '\n';
    }
    if(tentativesRestantes == 2)
    {
        std::cout << std::setfill(' ') << std::setw(13) << "_________" << '\n';
        std::cout << std::setfill(' ') << std::setw(5) << "|"
                  << "/" << std::setfill(' ') << std::setw(6) << '|' << '\n';
        std::cout << std::setfill(' ') << std::setw(5) << "|" << std::setw(7) << 'O' << '\n';
        std::cout << std::setfill(' ') << std::setw(5) << "|" << std::setfill(' ') << std::setw(7)
                  << '|' << '\n';
        std::cout << std::setfill(' ') << std::setw(5) << "|" << std::setw(6) << '/' << ' ' << '\\'
                  << '\n';
        std::cout << std::setfill(' ') << std::setw(5) << "|" << '\n';
        std::cout << std::setfill('-') << std::setw(11) << '\n';
        std::cout << "\033[93m"
                  << "Huitième tentative : C'est pas loin...(c'est faux, c'est pas ça du tout)"
                  << "\033[0m" << std::endl;
        std::cout << '\n';
    }
    if(tentativesRestantes == 1)
    {
        std::cout << std::setfill(' ') << std::setw(13) << "_________" << '\n';
        std::cout << std::setfill(' ') << std::setw(5) << "|" << '/' << std::setfill(' ')
                  << std::setw(6) << '|' << '\n';
        std::cout << std::setfill(' ') << std::setw(5) << "|" << std::setfill(' ') << std::setw(6)
                  << '\\' << 'O' << '\n';
        std::cout << std::setfill(' ') << std::setw(5) << "|" << std::setfill(' ') << std::setw(7)
                  << '|' << '\n';
        std::cout << std::setfill(' ') << std::setw(5) << "|" << std::setfill(' ') << std::setw(6)
                  << '/' << ' ' << '\\' << '\n';
        std::cout << std::setfill(' ') << std::setw(5) << "|" << '\n';
        std::cout << std::setfill('-') << std::setw(11) << '\n';
        std::cout << "\033[31m"
                  << "Neuvième tentative : Dernière chance"
                  << "\033[0m" << std::endl;
        std::cout << '\n';
    }
    if(tentativesRestantes == 0)
    {
        std::cout << std::setfill(' ') << std::setw(13) << "_________" << '\n';
        std::cout << std::setfill(' ') << std::setw(5) << "|" << '/' << std::setfill(' ')
                  << std::setw(6) << '|' << '\n';
        std::cout << std::setfill(' ') << std::setw(5) << "|" << std::setfill(' ') << std::setw(6)
                  << '\\' << 'O' << '/' << '\n';
        std::cout << std::setfill(' ') << std::setw(5) << "|" << std::setfill(' ') << std::setw(7)
                  << '|' << '\n';
        std::cout << std::setfill(' ') << std::setw(5) << "|" << std::setfill(' ') << std::setw(6)
                  << '/' << ' ' << '\\' << '\n';
        std::cout << std::setfill(' ') << std::setw(5) << "|" << '\n';
        std::cout << std::setfill('-') << std::setw(11) << '\n';
        std::cout
          << "\033[35m"
          << "Dernière tentative : En fait non c'était celle là la dernière (c'est fini, il "
             "est mort le bonhomme)"
          << "\033[0m" << std::endl;
        std::cout << '\n';
    }
}

string InterfaceJoueurs::saisirNomJoueur()
{
    string nom;

    do
    {
        std::cout << "Nom du joueur : ";
        std::cin >> std::ws;
        getline(std::cin, nom);
        if(!cin.good())
        {
            std::cerr << "Saisie invalide ! Veuillez saisir à nouveau.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            nom = "";
        }
    } while(nom.empty());

    return nom;
}

void InterfaceJoueurs::afficherNomJoueur(const string& nom)
{
    cout << "Bienvenue " << nom << endl;
}

void InterfaceJoueurs::afficherMotATrouver(const string& motATrouver) const
{
    cout << endl;
    cout << "Le mot à trouver : " << motATrouver << endl;
}

void InterfaceJoueurs::afficherRegle()
{
    cout << endl;
    cout << "-Le but du jeu est simple : deviner toute les lettres qui doivent composer un "
            "mot,\n -éventuellement avec un nombre limité de tentatives et des thèmes fixés à "
            "l'avance.\n -A chaque fois que le joueur devine une lettre,\n -celle-ci est affichée. "
            "Dans le cas contraire, le dessin d'un pendu se met à apparaître…"
         << endl;
    cout << endl;
}