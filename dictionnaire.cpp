#include "dictionnaire.h"
#include <random>

using namespace std;

Dictionnaire::Dictionnaire() : listeMots({ "letu", "poil", "maman", "bonnet" })
{
}

void Dictionnaire::charger()
{
    // @todo remplir le vector listeMots à partir d'un fichier
}

std::string Dictionnaire::genererMotSecret() const
{
    std::default_random_engine         generateur;
    std::uniform_int_distribution<int> distribution(0, listeMots.size() - 1);
    int                                numeroMot = distribution(generateur);

    return listeMots[numeroMot];
}
