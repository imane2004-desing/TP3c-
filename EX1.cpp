#include <iostream>



#include <iostream>
#include <iomanip>

using namespace std;

class Ensemble {
private:
    int *elements;
    int taille;
    int nb_elements;

public:
    Ensemble(int taille = 100) : taille(taille), nb_elements(0) {
        elements = new int[taille];
    }

    ~Ensemble() {
        delete[] elements;
    }

    void empty() {
        nb_elements = 0;
    }

    void add(int element) {
        if (nb_elements < taille) {
            // Vérifier si l'élément existe déjà
            if (!is_member(element)) {
                elements[nb_elements++] = element;
            } else {
                cout << "L'élément " << element << " est déjà présent dans l'ensemble." << endl;
            }
        } else {
            cout << "L'ensemble est plein. Impossible d'ajouter " << element << "." << endl;
        }
    }

    void remove(int element) {
        for (int i = 0; i < nb_elements; ++i) {
            if (elements[i] == element) {
                elements[i] = elements[--nb_elements]; // Remplace l'élément supprimé par le dernier
                return;
            }
        }
        cout << "L'élément " << element << " n'est pas dans l'ensemble." << endl;
    }

    void copy(const Ensemble &other) {
        empty();
        for (int i = 0; i < other.nb_elements; ++i) {
            add(other.elements[i]);
        }
    }

    bool is_member(int element) {
        for (int i = 0; i < nb_elements; ++i) {
            if (elements[i] == element) {
                return true;
            }
        }
        return false;
    }

    bool is_equal(const Ensemble &other) {
        if (nb_elements != other.nb_elements) return false;

        for (int i = 0; i < nb_elements; ++i) {
            if (!other.is_member(elements[i])) {
                return false;
            }
        }
        return true;
    }

    void print() {
        cout << "Ensemble: { ";
        for (int i = 0; i < nb_elements; ++i) {
            cout << elements[i] << (i < nb_elements - 1 ? ", " : " ");
        }
        cout << "}" << endl;
    }
};

int main() {
    Ensemble e;
    e.add(10);
    e.add(20);
    e.add(30);
    e.print();

    e.remove(20);
    e.print();

    e.add(40);
    e.add(50);
    e.print();

    Ensemble e_copy;
    e_copy.copy(e);
    e_copy.print();

    cout << "L'élément 30 est membre: " << (e.is_member(30) ? "Oui" : "Non") << endl;
    cout << "L'élément 20 est membre: " << (e.is_member(20) ? "Oui" : "Non") << endl;

    Ensemble e2;
    e2.add(10);
    e2.add(30);
    e2.add(40);
    cout << "Les ensembles e et e2 sont égaux: " << (e.is_equal(e2) ? "Oui" : "Non") << endl;

    return 0;
}
