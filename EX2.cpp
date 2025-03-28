#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

class Point {
public:
    float x, y;

    Point(float x = 0, float y = 0) : x(x), y(y) {}
};

class Cercle {
private:
    Point centre;
    float rayon;

public:
    Cercle(float r, float x, float y) : rayon(r), centre(x, y) {}

    float getRayon() {
        return rayon;
    }

    void setRayon(float r) {
        rayon = r;
    }

    Point getCentre() {
        return centre;
    }

    void translater(float dx, float dy) {
        centre.x += dx;
        centre.y += dy;
    }

    float surface() {
        return M_PI * rayon * rayon;
    }

    float perimetre() {
        return 2 * M_PI * rayon;
    }

    bool estEgal(Cercle &c) {
        return (rayon == c.rayon && centre.x == c.centre.x && centre.y == c.centre.y);
    }

    bool appartient(Point p) {
        float distance = sqrt(pow(p.x - centre.x, 2) + pow(p.y - centre.y, 2));
        return distance <= rayon;
    }

    void affiche() {
        cout << "Cercle: Centre(" << centre.x << ", " << centre.y << "), Rayon: " << rayon << endl;
    }
};

int main() {
    Cercle c(1, 10, 10);
    c.affiche();
    cout << "Périmètre: " << c.perimetre() << endl;
    cout << "Surface: " << c.surface() << endl;

    // Doubler le rayon
    c.setRayon(c.getRayon() * 2);
    cout << "Après doublement du rayon:" << endl;
    c.affiche();
    cout << "Périmètre: " << c.perimetre() << endl;
    cout << "Surface: " << c.surface() << endl;

    // Déplacer le cercle à l'origine
    c.translater(-c.getCentre().x, -c.getCentre().y);
    cout << "Après translation à l'origine:" << endl;
    c.affiche();

    // Vérification des points
    Point p1(1, 1);
    Point p2(3, 3);
    cout << "Le point (1, 1) est à l'intérieur du cercle: " << (c.appartient(p1) ? "Oui" : "Non") << endl;
    cout << "Le point (3, 3) est à l'extérieur du cercle: " << (c.appartient(p2) ? "Oui" : "Non") << endl;

    // Test d'égalité avec un autre cercle
    Cercle c2(2, 0, 0);
    cout << "Le cercle c est égal au cercle c2: " << (c.estEgal(c2) ? "Oui" : "Non") << endl;

    return 0;
}
