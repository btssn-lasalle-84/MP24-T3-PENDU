#ifndef JEU_PENDU_H
#define JEU_PENDU_H
#include <string>
#include <vector>

class Joueur;

class jeuPendu
{
  private:
    std::vector<int> pendu();
    Joueur*          monJoueur;
    int              essai = 9;

  public:
    jeuPendu(Joueur* monJoueur = nullptr, int essai);
    bool estFinPartie();
    bool verifierMot();
    void jouer();
    void choisirMot();
};

#endif // JEU_PENDU_H
