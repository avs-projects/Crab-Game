#ifndef PARTIE_HPP
#define PARTIE_HPP

#include <iostream>
#include <vector>
#include "Joueur.hpp"

using namespace std;

class Partie {
private:
    Joueur joueur1;
    Joueur joueur2;
    Joueur vainqueur;
    int nombreCoups;
    std::vector<vector<int>> vectorGrilleJeu;
public:
    Partie();

    Partie(vector<vector<int>> vec);

    Partie(Joueur j1, Joueur j2);

    void grille_jeu();

    void grille_jeu_Vide();

    bool victoire(Joueur basicString, Joueur string1, int tour);

    void lancement_partie();

    const Joueur getVainqueur();

    const int getCoups();
};


ostream &operator<<(ostream &out, Partie &p);

#endif // JOUEUR_HPP
