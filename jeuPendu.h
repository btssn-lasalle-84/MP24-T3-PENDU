#ifndef JEU_PENDU_H
#define JEU_PENDU_H
#include <string>
#include <vector>

using namespace std;
class Joueur;

class jeuPendu
{
  private:
    vector<int> pendu();
    Joueur*     monJoueur;
    int         essai = 9;

  public:
    jeuPendu(Joueur* monJoueur = nullptr);
    bool estFinPartie();
    bool verifierMot();
    void jouer();
    void choisirMot();
};

#endif // JEU_PENDU_H
