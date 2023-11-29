#ifndef JEU_PENDU_H
#define JEU_PENDU_H
#include <string>
#include <vector>

using namespace std;

class jeuPendu {
private:
  vector<int> pendu();

public:
  jeuPendu(vector<int> pendu);
  bool estFinPartie();
  bool verifierMot();
  void jouer();
  void choisirMot();
};

#endif // JEU_PENDU_H
