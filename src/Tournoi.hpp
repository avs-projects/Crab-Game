#ifndef TOURNOI_HPP
#define TOURNOI_HPP

#include <iostream>
#include "Partie.hpp"
#include "Joueur.hpp"

using namespace std;

class Tournoi {
private:
    Partie p;
    Joueur j;
    Joueur vainquerTournoi;
    vector<Joueur> joueurs;
public:
    Tournoi();

    void lance_tournoi();

    void inscription(Joueur j);

    void vide_participants();

    const Joueur getVainqueurTournoi();
};

ostream &operator<<(ostream &out, Tournoi &t);

#endif // TOURNOI_HPP
