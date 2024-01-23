#ifndef DICTIONNAIRE_H
#define DICTIONNAIRE_H

#include <string>
#include <vector>

class Dictionnaire
{
  private:
    std::vector<std::string> listeMots;
    std::vector<std::string> listeThemes;

  public:
    Dictionnaire();

    void                     charger(int choixTheme);
    std::string              genererMotSecret() const;
    std::vector<std::string> getListeThemes() const;

  private:
};

#endif // DICTIONNAIRE_H