#ifndef DICTIONNAIRE_H
#define DICTIONNAIRE_H
#include <string>
#include <vector>
class Dictionnaire
{
  private:
    std::string listeMots;

  public:
    Dictionnaire(std::string listeMots);
    void genererMot();
};
#endif // DICTIONNAIRE_H