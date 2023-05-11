#include <iostream>
#include <cmath>
using namespace std;

class punto {
    private:
        double x, y;
    public:
        punto(double x, double y) {
            this-> x = x;
            this-> y = y;
        }

        double distancia(punto p) {
            double dx = this-> x - p.x;
            double dy = this-> y - p.y;
            return sqrt(dx*dx + dy*dy);
        } 

        double distanciaor() {
            punto origen(0,0);
            return this->distancia(origen);
        }

        double distanciaop(const punto& op){
            return sqrt(pow(x - op.x, 2) + pow(y - op.y, 2));
        }
};

int main(){
    punto p1(4, 7);
    punto p2(1, 2);
    
    cout << "distancia entre los puntos: " << p1.distancia(p2) << std::endl;
    cout << "distancia desde el punto de origen (" << p1.distanciaor() << ")" << std::endl;
    cout << "distancia desde el punto de origen (" << p2.distanciaor() << ")" << std::endl;
    
    punto p3(2, 3);
    cout << "distancia entre los puntos: " << p1.distancia(p3) <<endl;
    cout << "distancia entre los puntos: " << p2.distanciaop(p3) <<endl;
    return 0;
}

