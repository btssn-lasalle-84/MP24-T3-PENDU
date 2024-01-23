#include "dictionnaire.h"
#include <fstream>
#include <random>
#include <algorithm>

using namespace std;

Dictionnaire::Dictionnaire() : listeThemes{ "ecole", "plage", "numerique", "dictionnaire" }
{
}

void Dictionnaire::charger(int choixTheme)
{
    if(choixTheme < 0 || choixTheme >= static_cast<int>(listeThemes.size()))
    {
        return;
    }
    std::string nomFichier = listeThemes[choixTheme] + string(".txt");
    ifstream    fichier(nomFichier);

    if(fichier.is_open())
    {
        listeMots.clear();

        string mot;
        while(getline(fichier, mot))
        {
            std::transform(mot.begin(), mot.end(), mot.begin(), ::toupper);
            listeMots.push_back(mot);
        }

        fichier.close();
    }
}

std::string Dictionnaire::genererMotSecret() const
{
    std::random_device            generateur;
    std::mt19937                  gen(generateur());
    uniform_int_distribution<int> distribution(0, listeMots.size() - 1);
    int                           numeroMot = distribution(generateur);

    return listeMots[numeroMot];
}

std::vector<std::string> Dictionnaire::getListeThemes() const
{
    return listeThemes;
}