#include "Partie.hpp"

Partie::Partie() {
    // Grid initialization
    this->vectorGrilleJeu = {
            {0, 0, 0},
            {0, 0, 0},
            {0, 0, 0}
    };
}

Partie::Partie(vector<vector<int>> vectorNouveau) {
    this->vectorGrilleJeu = vectorNouveau;
}

Partie::Partie(Joueur j1, Joueur j2) {
    this->joueur1 = std::move(j1);
    this->joueur2 = std::move(j2);
}

const Joueur Partie::getVainqueur() {
    return this->vainqueur;
}

const int Partie::getCoups() {
    return this->nombreCoups;
}

// Modification of the game grid at each turn
void Partie::grille_jeu() {
    std::cout << '\n';
    for (int i = 0; i < (int)vectorGrilleJeu.size(); i++) {
        for (int j = 0; j < (int)vectorGrilleJeu[i].size(); j++) {
            std::cout << vectorGrilleJeu[i][j] << " ";
        }
        std::cout << '\n';
    }
}

// Reset of the grid at the end of a meeting
void Partie::grille_jeu_Vide() {
    vectorGrilleJeu = {
            {0, 0, 0},
            {0, 0, 0},
            {0, 0, 0}
    };
    Partie p(vectorGrilleJeu);
}

// Test if a player has won
bool Partie::victoire(Joueur j1, Joueur j2, int nb) {
    // Check diagonal
    if ((vectorGrilleJeu[0][0] == 1 && vectorGrilleJeu[1][1] == 1 && vectorGrilleJeu[2][2] == 1)
        || (vectorGrilleJeu[0][2] == 1 && vectorGrilleJeu[1][1] == 1 && vectorGrilleJeu[2][0] == 1)) {
        nombreCoups = nb;
        vainqueur = j1;
        return true;
    } else if ((vectorGrilleJeu[0][0] == 2 && vectorGrilleJeu[1][1] == 2 && vectorGrilleJeu[2][2] == 2)
               || (vectorGrilleJeu[0][2] == 2 && vectorGrilleJeu[1][1] == 2 && vectorGrilleJeu[2][0] == 2)) {
        nombreCoups = nb;
        vainqueur = j2;
        return true;
    }

    // Check horizontally and vertically
    for (int i = 0; i < (int)vectorGrilleJeu.size(); i++) {
        if ((vectorGrilleJeu[i][0] == 1 && vectorGrilleJeu[i][1] == 1 && vectorGrilleJeu[i][2] == 1)
            || (vectorGrilleJeu[0][i] == 1 && vectorGrilleJeu[1][i] == 1 && vectorGrilleJeu[2][i] == 1)) {
            nombreCoups = nb;
            vainqueur = j1;
            return true;
        } else if ((vectorGrilleJeu[i][0] == 2 && vectorGrilleJeu[i][1] == 2 && vectorGrilleJeu[i][2] == 2)
                   || (vectorGrilleJeu[0][i] == 2 && vectorGrilleJeu[1][i] == 2 && vectorGrilleJeu[2][i] == 2)) {
            nombreCoups = nb;
            vainqueur = j2;
            return true;
        }
    }
    return false;
}

// Launching the game with error handling
void Partie::lancement_partie() {
    unsigned int i, j;
    int resultat{0};
    int signeJoueur;

    Joueur p1 = joueur1;
    Joueur p2 = joueur2;

    grille_jeu_Vide();

    cout << "Partie entre " << p1.getIdentifiant() << " et " << p2.getIdentifiant() << "\n";

    for (int tour = 0; tour < 9;) {
        if (tour == 0 || tour % 2 == 0) {
            signeJoueur = 1;
        } else {
            signeJoueur = 2;
        }

        cout << "Entrez une case i j : ";
        scanf("%d %d", &i, &j);

        if (i < 3 && j < 3) {
            if (vectorGrilleJeu[i][j] == 0) {
                vectorGrilleJeu[i][j] = signeJoueur;
                grille_jeu();
                tour++;
                resultat = victoire(p1, p2, tour);
                if (resultat == 1) {
                    break;
                }
            } else {
                std::cerr << "Vous ne pouvez pas remplacer les marques de votre adversaire.\n";
            }
        } else {
            std::cerr << "Veuillez entrer une ligne et une colonne comprise entre 0 et 2\n";
        }
    }
    if (resultat == 0) {
        std::cout << "Match Nul\n";
    }
}

ostream& operator<<(ostream& out, Partie &p){
    out<< p.getCoups();
    return out;
}





