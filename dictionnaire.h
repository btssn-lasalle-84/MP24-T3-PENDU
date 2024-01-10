#ifndef DICTIONNAIRE_H
#define DICTIONNAIRE_H

#include <string>
#include <vector>

class Dictionnaire
{
  public:
    Dictionnaire();

    void        charger(const std::string& nomFichier);
    std::string genererMotSecret() const;

  private:
    std::vector<std::string> listeMots;
};

#endif // DICTIONNAIRE_H