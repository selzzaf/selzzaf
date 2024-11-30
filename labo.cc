#include <iostream>
#include <string>
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
};

int main() {
    Souris s1(50.0, "blanche", 2);
    Souris s2(45.0, "grise");
    Souris s3(s2);

    s1.afficher();
    s2.afficher();
    s3.afficher();

    s1.evolue();
    s2.evolue();
    s3.evolue();

    s1.afficher();
    s2.afficher();
    s3.afficher();

    return 0;
}
