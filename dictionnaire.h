#ifndef DICTIONNAIRE_H
#define DICTIONNAIRE_H

#include <string>
#include <vector>

class Dictionnaire
{
  private:
  public:
    Dictionnaire();
    void                     charger();
    std::string              genererMotSecret() const;
    std::vector<std::string> listeMots;
};

#endif // DICTIONNAIRE_H