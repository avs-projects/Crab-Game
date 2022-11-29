#include "Joueur.hpp"

Joueur::Joueur() {
    this->identifiant = "Joueur";
    this->score = 0.0;
}

Joueur::Joueur(string id) {
    this->identifiant = id;
    this->score = 0.0;
}

Joueur::Joueur(string id, double sc) {
    this->identifiant = id;
    this->score = sc;
}

const string Joueur::getIdentifiant() {
    return this->identifiant;
}

const double Joueur::getScore() {
    return this->score;
}


void Joueur::setScore(int coupsJeu, double scoreAvantPartie) {
    if(coupsJeu == 0){
        score = scoreAvantPartie;
    }else{
        double formuleScore =  9.0 / (coupsJeu + (coupsJeu % 2));
        score = formuleScore + scoreAvantPartie;
    }
}

ostream& operator<<(ostream& out, Joueur &j){
    out<< j.getIdentifiant() << j.getScore();
    return out;
}
