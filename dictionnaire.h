#ifndef DICTIONNAIRE_H
#define DICTIONNAIRE_H

#include <string>
#include <vector>

class Dictionnaire
{
  private:
    std::vector<std::string> listeMots;

  public:
    Dictionnaire();
    void        charger();
    std::string genererMotSecret() const;
};

#endif // DICTIONNAIRE_H