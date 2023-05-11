#include <iostream>
#include <cmath> //contiene las definiciones de las funciones matematicas (sqrt)

using namespace std;
class Punto {
public:
    // Constructor
    Punto(double x = 0, double y = 0) : x(x), y(y) {}

    // Sobrecarga del operador ->*
    double operator ->*(const Punto* p) {
        double dx = x - p->x;
        double dy = y - p->y;
        return sqrt(dx*dx + dy*dy);
    }

private:
    double x, y;
};

int main() {
    Punto p1(1.0, 1.0);
    Punto p2(4.0, 5.0);

    double distancia = p1 ->* &p2;
    cout << "La distancia entre p1 y p2 es: " << distancia << endl;

    return 0;
}
