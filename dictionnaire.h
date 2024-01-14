#ifndef DICTIONNAIRE_H
#define DICTIONNAIRE_H

#include <string>
#include <vector>

class Dictionnaire
{
  public:
    Dictionnaire();

    void                     charger();
    std::string              genererMotSecret() const;
    std::vector<std::string> listeMots;

  private:
};

#endif // DICTIONNAIRE_H