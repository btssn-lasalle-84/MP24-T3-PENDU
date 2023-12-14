#include "interfaceJoueurs.h"
#include "jeuPendu.h"
#include <iostream>
#include <limits>
#include <iomanip>

InterfaceJoueurs::InterfaceJoueurs() : lettresUtilisees()
{
}

void InterfaceJoueurs::afficherMenu(JeuPendu& jeuPendu)
{
    int choix;

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

    std::cout << "****************************\n";
    std::cout << "**   1. Nouvelle partie   **\n";
    std::cout << "**   2. Scores            **\n";
    std::cout << "**   3. Quitter           **\n";
    std::cout << "****************************\n";
    std::cout << "Choisissez une option : ";

    std::cin >> choix;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  
    do
    {
      switch (choix)
        {
            case 1:
                std::cout << "Lancement d'une nouvelle partie...\n";
                jeuPendu.lancerPartie();
                break;
            case 2:
                std::cout << "Afficher les scores...\n";
                break;
            case 3:
                quitter();
                break;
            default:
                std::cout << "Option invalide. Veuillez choisir à nouveau.\n";
        }

    } while (choix != 3);
}

void InterfaceJoueurs::quitter()
{
    std::cout << "Bye Bye, Merci d'avoir joué.\n";
    exit(0);
}
 
void InterfaceJoueurs::ajouterLettreUtilisee(char lettre) 
{
    lettresUtilisees.push_back(lettre);
}

char InterfaceJoueurs::demanderLettre() 
{
    char lettreProposee;
    std::cout << "Entrez une lettre : ";
    std::cin >> lettreProposee;
    ajouterLettreUtilisee(lettreProposee);
    return lettreProposee;
}

void InterfaceJoueurs::afficherTentatives(int tentativesRestantes)
{
    std::cout << "Tentatives restantes : " << tentativesRestantes << std::endl;
    std::cout << "Lettres utilisées : ";
    for(char lettre: lettresUtilisees)
    {
        std::cout << lettre << " ";
    }
    std::cout << std::endl;
}

void InterfaceJoueurs::dessinerPendu(int tentativesRestantes)
{
    if(tentativesRestantes == 10)
    {
        std::cout << std::setfill('\n') << std::setw(6) << '\n';
        std::cout << std::setfill('-') << std::setw(11) << '\n';
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
    }
}

std::string InterfaceJoueurs::saisirNomJoueur()
{
    std::string nom;

    do
    {
        std::cout << "Nom du joueur : ";
        std::cin >> std::ws; // Ignorer les espaces blancs avant la saisie
        getline(std::cin, nom);

        if(!std::cin.good())
        {
            std::cerr << "Saisie invalide ! Veuillez saisir à nouveau.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            nom = ""; // Réinitialiser la variable
        }
    } while(nom.empty());

    return nom;
}

void InterfaceJoueurs::afficherNomJoueur(const std::string& nom)
{
    std::cout << "Bienvenue " << nom << std::endl;
}