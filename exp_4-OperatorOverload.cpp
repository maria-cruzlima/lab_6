#include <iostream>
#include <string>
using namespace std;                                                                                                                                                                       // Clase para representar un vector en 2D
class Vector2D {
public:
    // Constructores
    Vector2D() : x(0.0), y(0.0) {}
    Vector2D(double xx, double yy) : x(xx), y(yy) {}


    // Sobrecarga de operadores
    friend Vector2D operator + (const Vector2D& v1, const Vector2D& v2) {
        return Vector2D(v1.x + v2.x, v1.y + v2.y);;
    }

    friend Vector2D operator - (const Vector2D& v1, const Vector2D& v2) {
        double x ;
        x = v1 - v2;
        return Vector2D(v1.x + v2.x, v1.y + v2.y);;
    }

    // Variables miembro
    double x, y;
};

int main() {
    // Crear dos vectores
    Vector2D v1(1.0, 2.0);
    Vector2D v2(3.0, 4.0);

    // Sumar y restar los vectores utilizando los operadores sobrecargados
    Vector2D suma = v1 + v2;
    Vector2D resta = v1 - v2;

    // Imprimir los resultados
    d:cout << "v1 = (" << v1.x << ", " << v1.y << ")" << std::endl;
    cout << "v2 = (" << v2.x << ", " << v2.y << ")" << std::endl;
    cout << "v1 + v2 = (" << suma.x << ", " << suma.y << ")" << std::endl;
    cout << "v1 - v2 = (" << resta.x << ", " << resta.y << ")" << std::endl;

    return 0;
}
