#include "dictionnaire.h"
#include <fstream>
#include <random>

using namespace std;

Dictionnaire::Dictionnaire()
{
    charger("gateau.txt");
}

void Dictionnaire::charger(const std::string& nomFichier)
{
    ifstream fichier(nomFichier);

    if(fichier.is_open())
    {
        listeMots.clear();

        string mot;
        while(getline(fichier, mot))
        {
            listeMots.push_back(mot);
        }

        fichier.close();
    }
}

std::string Dictionnaire::genererMotSecret() const
{
    default_random_engine         generateur;
    uniform_int_distribution<int> distribution(0, listeMots.size() - 1);
    int                           numeroMot = distribution(generateur);

    return listeMots[numeroMot];
}