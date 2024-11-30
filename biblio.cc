#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Souris {
private:
    double poids;
    string couleur;
    unsigned int age;
    unsigned int esperance_vie;
    bool clonee;

public:
    // Constructeur avec paramètres
    Souris(double p, string c, unsigned int a = 0, unsigned int e_v = 36)
        : poids(p), couleur(c), age(a), esperance_vie(e_v), clonee(false) {
        cout << "Une nouvelle souris !" << endl;
    }

    // Constructeur de copie
    Souris(const Souris& other)
        : poids(other.poids), couleur(other.couleur), age(other.age),
          esperance_vie(other.esperance_vie * 0.8), clonee(true) {
        cout << "Clonage d’une souris !" << endl;
    }

    // Destructeur
    ~Souris() {
        cout << "Fin d’une souris..." << endl;
    }

    // Méthode d'affichage
    void afficher() const {
        cout << "Une souris " << couleur;
        if (clonee) {
            cout << ", clonee";
        }
        cout << " de " << age << " mois et pesant " << poids << " grammes" << endl;
    }

    // Méthode pour vieillir la souris
    void vieillir() {
        age++;
        if (clonee && age > esperance_vie / 2) {
            couleur = "verte";  // La souris devient verte si elle a plus de la moitié de son espérance de vie.
        }
    }

    // Méthode pour faire évoluer la souris
    void evolue() {
        while (age < esperance_vie) {
            vieillir();
        }
    }

    // Méthode pour vérifier si la souris est encore en vie
    bool estVive() const {
        return age < esperance_vie;
    }

    // Méthode pour obtenir l'âge de la souris
    unsigned int getAge() const {
        return age;
    }

    // Méthode pour obtenir le poids de la souris
    double getPoids() const {
        return poids;
    }

    // Méthode pour obtenir la couleur de la souris
    string getCouleur() const {
        return couleur;
    }

    // Méthode pour obtenir l'espérance de vie de la souris
    unsigned int getEsperanceVie() const {
        return esperance_vie;
    }
};

class PopulationSouris {
private:
    vector<Souris> souris;
    unsigned int taille_population;

public:
    // Constructeur
    PopulationSouris(unsigned int taille) : taille_population(taille) {
        for (unsigned int i = 0; i < taille_population; i++) {
            souris.push_back(Souris(45.0, "blanche"));
        }
    }

    // Méthode pour faire évoluer toute la population
    void evoluerPopulation() {
        for (auto& souris_individuelle : souris) {
            souris_individuelle.evolue();
        }
    }

    // Méthode pour afficher la population
    void afficherPopulation() const {
        for (const auto& souris_individuelle : souris) {
            souris_individuelle.afficher();
        }
    }

    // Méthode pour cloner une souris de la population
    void clonerSouris(unsigned int index) {
        if (index < souris.size()) {
            Souris souris_clone(souris[index]);
            souris.push_back(souris_clone);
        }
    }

    // Méthode pour éliminer les souris mortes
    void nettoyerPopulation() {
        vector<Souris> nouvelles_souris;
        for (const auto& souris_individuelle : souris) {
            if (souris_individuelle.estVive()) {
                nouvelles_souris.push_back(souris_individuelle);
            }
        }
        souris = nouvelles_souris;
    }

    // Méthode pour obtenir la taille de la population
    unsigned int getTaillePopulation() const {
        return souris.size();
    }
};

int main() {
    PopulationSouris population(10);  // Création d'une population de 10 souris
    population.afficherPopulation();

    cout << "\nEvolution de la population...\n";
    population.evoluerPopulation();  // Faire évoluer toute la population

    population.afficherPopulation();

    cout << "\nClonage d'une souris (index 0)...\n";
    population.clonerSouris(0);  // Clonage de la souris d'index 0
    population.afficherPopulation();

    cout << "\nNettoyage de la population (élimination des souris mortes)...\n";
    population.nettoyerPopulation();  // Éliminer les souris mortes
    population.afficherPopulation();

    return 0;
}
