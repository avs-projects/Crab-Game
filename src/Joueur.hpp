#ifndef JOUEUR_HPP
#define JOUEUR_HPP

#include <iostream>

using namespace std;

class Joueur {
private:
    string identifiant;
    double score;
public:
    Joueur();

    Joueur(string id);

    Joueur(string id, double sc);

    const string getIdentifiant();

    const double getScore();

    void setScore(int coupsPartie, double scoreAvantPartie);

};


ostream &operator<<(ostream &out, Joueur &j);

#endif // JOUEUR_HPP
