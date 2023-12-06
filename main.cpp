#include "interfaceJoueurs.h"
#include <iostream>
#include "jeuPendu.h"
#include "dictionnaire.h"

int main()
{
    // Créer une instance de l'interface des joueurs
    InterfaceJoueurs interface;

    // Créer une instance du dictionnaire
    Dictionnaire dictionnaire;
    // Charger les mots du dictionnaire
    dictionnaire.charger();

    // Demander au joueur de saisir son nom
    Joueur joueur("Joueur1");
    joueur.saisir();

    // Créer une instance du jeu du pendu avec l'interface, le dictionnaire et un mot choisi
    // aléatoirement
    JeuPendu jeu(&interface, &dictionnaire, dictionnaire.genererMotSecret());

    // Associer le dictionnaire à jeu
    jeu.relationDictionnaire(&dictionnaire);

    // Associer l'interface à jeu
    jeu.relationInterfaceJoueurs(&interface);

    // Jouer la partie
    jeu.jouer();

    return 0;
}