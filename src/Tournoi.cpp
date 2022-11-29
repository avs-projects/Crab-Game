#include "Tournoi.hpp"
#include <iostream>

using namespace std;

Tournoi::Tournoi() {
    this->p = Partie();
    this->j = Joueur();
    this->vainquerTournoi = Joueur();
    this->joueurs = {};
}

// Registration of players in the list of participants
void Tournoi::inscription(Joueur j) {
    joueurs.push_back(j);
}

// Removing players from the participant list
void Tournoi::vide_participants() {
    joueurs.clear();
}

const Joueur Tournoi::getVainqueurTournoi() {
    return this->vainquerTournoi;
}

// Tournament launch
void Tournoi::lance_tournoi() {
    for (int i = 0; i < (int)joueurs.size() - 1; i++) {
        for (int j = i + 1; j < (int)joueurs.size(); j++) {
            Partie p{joueurs.at(i), joueurs.at(j)};
            p.lancement_partie();

            Joueur j1 = p.getVainqueur();

            string identifiantJoueurVainqueur = j1.getIdentifiant();
            string identifiantJoueur1 = joueurs.at(i).getIdentifiant();
            string identifiantJoueur2 = joueurs.at(j).getIdentifiant();

            // Verification of the winner to correctly increment the scores
            if (identifiantJoueurVainqueur == identifiantJoueur1) {
                    std::cout << "--> Bravo Joueur " << j1.getIdentifiant() << "\n";
                joueurs.at(i).setScore(p.getCoups(), joueurs.at(i).getScore());
                joueurs.at(j).setScore(0, joueurs.at(j).getScore());
            } else if (identifiantJoueurVainqueur == identifiantJoueur2) {
                std::cout << "--> Bravo Joueur " << j1.getIdentifiant() << "\n";
                joueurs.at(i).setScore(0, joueurs.at(i).getScore());
                joueurs.at(j).setScore(p.getCoups(), joueurs.at(j).getScore());
            } else {
                joueurs.at(i).setScore(0, joueurs.at(i).getScore());
                joueurs.at(j).setScore(0, joueurs.at(j).getScore());
            }

            std::cout << "scores du joueur " << joueurs.at(i).getIdentifiant() << " : tournoi "
                      << joueurs.at(i).getScore() << ", total " << joueurs.at(i).getScore()
                      << "\n";
            std::cout << "scores du joueur " << joueurs.at(j).getIdentifiant() << " : tournoi "
                      << joueurs.at(j).getScore() << ", total " << joueurs.at(j).getScore()
                      << "\n\n";
        }
    }

    Joueur maxScoreJoueur = joueurs[0];
    for (int i = 1; i < (int)joueurs.size(); i++) {

        if (joueurs[i].getScore() > maxScoreJoueur.getScore()) {
            maxScoreJoueur = joueurs[i];
        }
    }

    std::cout << "Le(s) gagnants du tournoi sont : " << maxScoreJoueur.getIdentifiant() << " avec le score "
              << maxScoreJoueur.getScore() << "\n";
    std::cout << "Scores totaux des participants : \n";

    for (unsigned int i = 0; i < joueurs.size(); i++) {
        std::cout << "scores du joueur " << joueurs.at(i).getIdentifiant() << " : tournoi " << joueurs[i].getScore()
                  << ", total " << joueurs[i].getScore() << "\n";
    }
}

ostream& operator<<(ostream& out, Tournoi &t){
    return out;
}
