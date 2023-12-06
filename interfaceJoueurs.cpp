#include <iostream>
#include "interfaceJoueurs.h"

InterfaceJoueurs::InterfaceJoueurs() : lettreProposee('\0'), tentativesRestantes(0)
{
}

int InterfaceJoueurs::getTentativeRestantes()
{
    return tentativesRestantes;
}