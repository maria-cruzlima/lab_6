#include <iostream>
#include <string>
using namespace std;

// Clase para representar un vector en 2D
class Vector2D {
public:
    // Constructores
    Vector2D() : x(0.0), y(0.0) {}
    Vector2D(double xx, double yy) : x(xx), y(yy) {}

    // Operaciones de vectores
    Vector2D operator+(const Vector2D& v) const {
        return Vector2D(x + v.x, y + v.y);
    }

    Vector2D operator-(const Vector2D& v) const {
        return Vector2D(x - v.x, y - v.y);
    }

    // Variables miembro
    double x, y;
};

// Sobrecarga de operadores fuera de la clase
Vector2D operator+(const Vector2D& v1, const Vector2D& v2) {
    return Vector2D(v1.x + v2.x, v1.y + v2.y);
}

Vector2D operator-(const Vector2D& v1, const Vector2D& v2) {
    return Vector2D(v1.x - v2.x, v1.y - v2.y);
}

int main() {
    // Crear dos vectores
    Vector2D v1(1.0, 2.0);
    Vector2D v2(3.0, 4.0);

    // Sumar y restar los vectores utilizando los operadores sobrecargados
    Vector2D suma = v1 + v2;
    Vector2D resta = v1 - v2;

    // Imprimir los resultados
    cout << "v1 = (" << v1.x << ", " << v1.y << ")" << endl;
    cout << "v2 = (" << v2.x << ", " << v2.y << ")" << endl;
    cout << "v1 + v2 = (" << suma.x << ", " << suma.y << ")" << endl;
    cout << "v1 - v2 = (" << resta.x << ", " << resta.y << ")" << endl;

    return 0;
}
