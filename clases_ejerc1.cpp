#include <iostream>
using namespace std;

class Numero {
    int valor;
    public:
        Numero(int v) {
            valor = v;
        }

        float operator > (const Numero&num) {
// si el 'valor' del objeto que llama es mayor que el 'valor' del objeto parámetro 'num'
            return valor > num.valor;
        }

        float mostrarvalor() const{
            return valor ;
        }
};

int main() {
    Numero num1(6);
    Numero num2(2);

    if(num1 > num2) {
        cout << "el numero " << num1.mostrarvalor() << " es mayor que el numero " << num2.mostrarvalor() << endl;
    } else {
        cout << "el numero " << num2.mostrarvalor() << " es mayor que el numero " << num1.mostrarvalor() << endl;
    }
    return 0;
}
