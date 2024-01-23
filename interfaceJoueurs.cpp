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

void InterfaceJoueurs::afficherInformations()
{
    std::cout << "\033[1;31m";
    std::cout << "      _   ______  _    _     _____    _    _     ______   ______  ______   _____ "
                 "   _    _    2.0\n";
    std::cout << "     | | | |     | |  | |   | | \\ \\  | |  | |   | |  | \\ | |     | |  \\ \\ | "
                 "| \\ \\  | |  | |\n";
    std::cout << " _   | | | |---- | |  | |   | |  | | | |  | |   | |__|_/ | |---- | |  | | | |  | "
                 "| | |  | |\n";
    std::cout << "|_|__|_| |_|____ \\_|__|_|   |_|_/ /  \\_|__|_|   |_|      |_|____ |_|  |_| "
                 "|_|_/ /  \\_|__|_|\n";
    std::cout << "\n\n";
    std::cout << "\033[0m";
}

int InterfaceJoueurs::afficherMenu()
{
    cout << "****************************\n";
    cout << "**   1. Nouvelle partie   **\n";
    cout << "**   2. Scores            **\n";
    cout << "**   3. Quitter           **\n";
    cout << "****************************\n";

    int  choix;
    bool choixValide = true;
    do
    {
        cout << "Choisissez une option : ";
        cin >> choix;
        viderBuffer();
        choixValide = true;
        // @todo : utiliser un enum pour les entrées de menu
        if(choix < 1 || choix > 3)
        {
            cout << "choix invalide !\n";
            choixValide = false;
        }
    } while(!choixValide);
    cout << endl;

    return choix;
}

void InterfaceJoueurs::quitter()
{
    cout << "Bye Bye, Merci d'avoir joué.\n";
}

void InterfaceJoueurs::ajouterLettreUtilisee(char lettre)
{
    lettresUtilisees.push_back(lettre);
}

char InterfaceJoueurs::demanderLettre()
{
    char lettreProposee;

    bool lettreValide = true;
    do
    {
        cout << "Entrez une lettre : ";
        cin >> lettreProposee;

        if(find(lettresUtilisees.begin(), lettresUtilisees.end(), lettreProposee) !=
           lettresUtilisees.end())
        {
            cout << "Vous avez déjà proposé cette lettre. Veuillez en choisir une autre." << endl;
            lettreValide = false;
        }
        else
        {
            ajouterLettreUtilisee(lettreProposee);
            lettreValide = true;
        }
    } while(!lettreValide);

    return lettreProposee;
}

void InterfaceJoueurs::afficherTentatives(int tentativesRestantes)
{
    cout << "Tentatives restantes : " << tentativesRestantes << endl;
    cout << "Lettre(s) déjà proposée(s) : ";
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
                  << "Deuxième tentative : Oui mais non"
                  << "\033[0m" << std::endl;
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
        std::cout << "\033[35m"
                  << "C'était la dernière tentative !"
                  << "\033[0m" << std::endl;
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
            viderBuffer();
            nom = "";
        }
    } while(nom.empty());
    std::cout << std::endl;

    return nom;
}

void InterfaceJoueurs::afficherNomJoueur(const std::string& nom)
{
    cout << "Bienvenue " << nom << ", vous avez " << NB_ESSAIS_MAX
         << " tentatives pour deviner un mot !" << endl;
    std::cout << std::endl;
}

void InterfaceJoueurs::afficherMotATrouver(const std::string& motATrouver) const
{
    std::cout << std::endl << "Le mot à trouver : ";
    for(char caractere: motATrouver)
    {
        std::cout << caractere << ' ';
    }

    std::cout << std::endl;
}

void InterfaceJoueurs::afficherRegles()
{
    cout << endl;
    cout << "Le but du jeu est simple : deviner toute les lettres qui doivent composer un "
            "mot,\n éventuellement avec un nombre limité de tentatives et des thèmes fixés à "
            "l'avance.\nA chaque fois que le joueur devine une lettre,\n celle-ci est affichée. "
            "Dans le cas contraire, le dessin d'un pendu se met à apparaître..."
         << endl;
    cout << endl;
}

void InterfaceJoueurs::afficherScores()
{
    if(scores.empty())
    {
        std::cout << "Aucun score disponible pour le moment.\n";
    }
    else
    {
        std::cout << "Scores :\n\n";
        for(const auto& score: scores)
        {
            if(score.score > 1)
            {
                std::cout << " - " << score.nom << " : " << score.score << " points\n";
            }
            else
            {
                std::cout << " - " << score.nom << " : " << score.score << " point\n";
            }
        }
    }
    cout << endl;
}

void InterfaceJoueurs::ajouterScore(const std::string& nom, int tentativesRestantes)
{
    int score = NB_ESSAIS_MAX - tentativesRestantes;

    scores.push_back({ nom, score });
}

void InterfaceJoueurs::viderLettreUtilisee()
{
    lettresUtilisees.clear();
}

void InterfaceJoueurs::afficherMessage(const std::string& message) const
{
    cout << message << endl;
}

int InterfaceJoueurs::choisirTheme(const std::vector<std::string>& themes) const
{
    cout << "****************************\n";
    for(size_t i = 0; i < themes.size(); ++i)
    {
        std::cout << "**   " << i + 1 << " - " << themes[i];
        for(size_t j = themes[i].length(); j < 17; ++j)
        {
            std::cout << " ";
        }
        cout << "**\n";
    }
    cout << "****************************\n";

    int  choix;
    bool choixValide = true;
    do
    {
        cout << "Choisissez le thème : ";
        cin >> choix;
        viderBuffer();
        choixValide = true;
        if(choix < 1 || choix > static_cast<int>(themes.size()))
        {
            cout << "choix invalide !\n";
            choixValide = false;
        }
    } while(!choixValide);
    cout << endl;

    return (choix - 1);
}

void InterfaceJoueurs::viderBuffer() const
{
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}
