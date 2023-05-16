#include <iostream>
using namespace std;
class Banco {
private:
    static float tasainteres;

public:
    static float gettasainteres() {
        return tasainteres;
    }

    static void settasainteres(float nuevaTasa) {
        tasainteres = nuevaTasa;
    }
};

float Banco::tasainteres = 0;

class CuentaBancaria {
private:
    float saldo;

public:
    CuentaBancaria(float saldoinicial = 0) {
        saldo = saldoinicial;
    }

    float getsaldo() {
        return saldo;
    }

    void depositar(float monto) {
        saldo += monto;
    }

    void retirar(float monto) {
        if (monto <= saldo) {
            saldo -= monto;
        }
        else {
            cout << "Fondos insuficientes." <<endl;
        }
    }

    float calcularinteres() {
        return saldo * Banco::gettasainteres();
    }
};

int main() {
    Banco::settasainteres(0.05f);

    CuentaBancaria cuenta(1000);
    cout << "tasa de interes: " << Banco::gettasainteres() <<endl;
    cout << "saldo inicial: " << cuenta.getsaldo() <<endl;

    cuenta.depositar(500);
    cout << "saldo del deposito: " << cuenta.getsaldo() <<endl;

    cuenta.retirar(200);
    cout <<"saldo del retiro: " << cuenta.getsaldo() << endl;

    float interes = cuenta.calcularinteres();
    cout <<"interes ganado: " << interes <<endl;

    return 0;
}
