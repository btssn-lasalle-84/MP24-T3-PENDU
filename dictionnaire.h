#ifndef DICTIONNAIRE_H
#define DICTIONNAIRE_H

#include <vector>
class Dictionnaire
{
  private:
    std::vector<char> listeMots;

  public:
    Dictionnaire(std::vector<char> listeMots);
    void genererMot();
};
#endif // DICTIONNAIRE_H