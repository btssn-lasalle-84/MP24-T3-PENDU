#include "dictionnaire.h"
#include <random>

using namespace std;

Dictionnaire::Dictionnaire() :

    listeMots({ "chaussette",
                "poil",
                "maman",
                "bonnet",
                "hache",
                "trompette",
                "banane",
                "vilebrequin",
                "anticonstitutionnellement" })

{
}

void Dictionnaire::charger()
{
    // @todo remplir le vector listeMots à partir d'un fichier
}

std::string Dictionnaire::genererMotSecret() const
{
    default_random_engine         generateur;
    uniform_int_distribution<int> distribution(0, listeMots.size() - 1);
    int                           numeroMot = distribution(generateur);

    return listeMots[numeroMot];
}
