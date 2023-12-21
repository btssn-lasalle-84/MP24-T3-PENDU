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

    cout << "\033[1;31m";

    cout << "_________ _______             ______              _______  _______  _        "
            "______           "
         << endl;
    cout << "\\__    _/(  ____ \\|\\     /|  (  __  \\ |\\     /|  (  ____ )(  ____ \\( (    "
            "/|(  __  \\ |\\     /|"
         << endl;
    cout << "   )  (  | (    \\/| )   ( |  | (  \\  )| )   ( |  | (    )|| (    \\/|  \\  ( "
            "|| (  \\  )| )   ( |"
         << endl;
    cout << "   |  |  | (__    | |   | |  | |   ) || |   | |  | (____)|| (__    |   \\ | || | "
            "  ) || |   | |"
         << endl;
    cout << "   |  |  |  __)   | |   | |  | |   | || |   | |  |  _____)|  __)   | (\\ \\) || "
            "|   | || |   | |"
         << endl;
    cout << "   |  |  | (      | |   | |  | |   ) || |   | |  | (      | (      | | \\   || | "
            "  ) || |   | |"
         << endl;
    cout << "|\\_)  )  | (____/\\| (___) |  | (__/  )| (___) |  | )      | (____/\\| )  \\  "
            "|| (__/  )| (___) |"
         << endl;
    cout << "(____/   (_______/(_______)  (______/ (_______)  |/       (_______/|/    "
            ")_)(______/ (_______)"
         << endl;
    cout << "\n\n" << endl;

    cout << "\033[0m";

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
        cout << setfill('\n') << setw(6) << '\n';
        cout << setfill('-') << setw(11) << '\n';
    }
    if(tentativesRestantes == 9)
    {
        cout << '\n';
        cout << setfill(' ') << setw(5) << "|" << '\n';
        cout << setfill(' ') << setw(5) << "|" << '\n';
        cout << setfill(' ') << setw(5) << "|" << '\n';
        cout << setfill(' ') << setw(5) << "|" << '\n';
        cout << setfill(' ') << setw(5) << "|" << '\n';
        cout << setfill('-') << setw(11) << '\n';
    }
    if(tentativesRestantes == 8)
    {
        cout << setfill(' ') << setw(13) << "_________" << '\n';
        cout << setfill(' ') << setw(5) << "|" << '\n';
        cout << setfill(' ') << setw(5) << "|" << '\n';
        cout << setfill(' ') << setw(5) << "|" << '\n';
        cout << setfill(' ') << setw(5) << "|" << '\n';
        cout << setfill(' ') << setw(5) << "|" << '\n';
        cout << setfill('-') << setw(11) << '\n';
    }
    if(tentativesRestantes == 7)
    {
        cout << setfill(' ') << setw(13) << "_________" << '\n';
        cout << setfill(' ') << setw(5) << "|"
             << "/" << '\n';
        cout << setfill(' ') << setw(5) << "|" << '\n';
        cout << setfill(' ') << setw(5) << "|" << '\n';
        cout << setfill(' ') << setw(5) << "|" << '\n';
        cout << setfill(' ') << setw(5) << "|" << '\n';
        cout << setfill('-') << setw(11) << '\n';
    }
    if(tentativesRestantes == 6)
    {
        cout << setfill(' ') << setw(13) << "_________" << '\n';
        cout << setfill(' ') << setw(5) << "|"
             << "/" << setfill(' ') << setw(6) << '|' << '\n';
        cout << setfill(' ') << setw(5) << "|" << '\n';
        cout << setfill(' ') << setw(5) << "|" << '\n';
        cout << setfill(' ') << setw(5) << "|" << '\n';
        cout << setfill(' ') << setw(5) << "|" << '\n';
        cout << setfill('-') << setw(11) << '\n';
    }
    if(tentativesRestantes == 5)
    {
        cout << setfill(' ') << setw(13) << "_________" << '\n';
        cout << setfill(' ') << setw(5) << "|"
             << "/" << setfill(' ') << setw(6) << '|' << '\n';
        cout << setfill(' ') << setw(5) << "|" << setw(7) << 'O' << '\n';
        cout << setfill(' ') << setw(5) << "|" << '\n';
        cout << setfill(' ') << setw(5) << "|" << '\n';
        cout << setfill(' ') << setw(5) << "|" << '\n';
        cout << setfill('-') << setw(11) << '\n';
    }
    if(tentativesRestantes == 4)
    {
        cout << setfill(' ') << setw(13) << "_________" << '\n';
        cout << setfill(' ') << setw(5) << "|"
             << "/" << setfill(' ') << setw(6) << '|' << '\n';
        cout << setfill(' ') << setw(5) << "|" << setw(7) << 'O' << '\n';
        cout << setfill(' ') << setw(5) << "|" << setfill(' ') << setw(7) << '|' << '\n';
        cout << setfill(' ') << setw(5) << "|" << '\n';
        cout << setfill(' ') << setw(5) << "|" << '\n';
        cout << setfill('-') << setw(11) << '\n';
    }
    if(tentativesRestantes == 3)
    {
        cout << setfill(' ') << setw(13) << "_________" << '\n';
        cout << setfill(' ') << setw(5) << "|"
             << "/" << setfill(' ') << setw(6) << '|' << '\n';
        cout << setfill(' ') << setw(5) << "|" << setw(7) << 'O' << '\n';
        cout << setfill(' ') << setw(5) << "|" << setfill(' ') << setw(7) << '|' << '\n';
        cout << setfill(' ') << setw(5) << "|" << setw(6) << '/' << '\n';
        cout << setfill(' ') << setw(5) << "|" << '\n';
        cout << setfill('-') << setw(11) << '\n';
    }
    if(tentativesRestantes == 2)
    {
        cout << setfill(' ') << setw(13) << "_________" << '\n';
        cout << setfill(' ') << setw(5) << "|"
             << "/" << setfill(' ') << setw(6) << '|' << '\n';
        cout << setfill(' ') << setw(5) << "|" << setw(7) << 'O' << '\n';
        cout << setfill(' ') << setw(5) << "|" << setfill(' ') << setw(7) << '|' << '\n';
        cout << setfill(' ') << setw(5) << "|" << setw(6) << '/' << ' ' << '\\' << '\n';
        cout << setfill(' ') << setw(5) << "|" << '\n';
        cout << setfill('-') << setw(11) << '\n';
    }
    if(tentativesRestantes == 1)
    {
        cout << setfill(' ') << setw(13) << "_________" << '\n';
        cout << setfill(' ') << setw(5) << "|" << '/' << setfill(' ') << setw(6) << '|' << '\n';
        cout << setfill(' ') << setw(5) << "|" << setfill(' ') << setw(6) << '\\' << 'O' << '\n';
        cout << setfill(' ') << setw(5) << "|" << setfill(' ') << setw(7) << '|' << '\n';
        cout << setfill(' ') << setw(5) << "|" << setfill(' ') << setw(6) << '/' << ' ' << '\\'
             << '\n';
        cout << setfill(' ') << setw(5) << "|" << '\n';
        cout << setfill('-') << setw(11) << '\n';
    }
    if(tentativesRestantes == 0)
    {
        cout << setfill(' ') << setw(13) << "_________" << '\n';
        cout << setfill(' ') << setw(5) << "|" << '/' << setfill(' ') << setw(6) << '|' << '\n';
        cout << setfill(' ') << setw(5) << "|" << setfill(' ') << setw(6) << '\\' << 'O' << '/'
             << '\n';
        cout << setfill(' ') << setw(5) << "|" << setfill(' ') << setw(7) << '|' << '\n';
        cout << setfill(' ') << setw(5) << "|" << setfill(' ') << setw(6) << '/' << ' ' << '\\'
             << '\n';
        cout << setfill(' ') << setw(5) << "|" << '\n';
        cout << setfill('-') << setw(11) << '\n';
    }
}

string InterfaceJoueurs::saisirNomJoueur()
{
    string nom;

    do
    {
        cout << "Nom du joueur : ";
        cin >> ws; // Ignorer les espaces blancs avant la saisie
        getline(cin, nom);

        if(!cin.good())
        {
            cerr << "Saisie invalide ! Veuillez saisir à nouveau.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            nom = ""; // Réinitialiser la variable
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