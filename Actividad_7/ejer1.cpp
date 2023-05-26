#include <iostream>
#include <string>

using namespace std;

class Vehiculo {
    private:
        string marca;
        string modelo;
        int anio_fabricacion;
        double precio;
    public:
        Vehiculo(string m, string mo, int af, double p){
            this -> marca = m;
            this -> modelo = mo;
            this -> anio_fabricacion = af;
            this -> precio = p;
        }
        
        virtual void mostrarDatos() {
            cout << "marca: " << marca << endl;
            cout << "modelo: " << modelo << endl;
            cout << "Anno de fabricacion: " << anio_fabricacion << endl;
            cout << "precio: " << precio << endl;
        }
};

class Automovil : public Vehiculo {
    private:
        int numpuertas;
        string tipocombustible;
    public:
        Automovil(string m, string mo, int af, double p,int nump, string tipoc) : Vehiculo(m, mo, af, p), numpuertas(nump), tipocombustible(tipoc) {}
        
    void mostrarDatos() {
        Vehiculo::mostrarDatos();
        cout << "numero de puertas: " << numpuertas << endl;
        cout << "tipo de combustible: " << tipocombustible << endl;
    }
};

class Motocicleta : public Vehiculo {
    private:
        int cilindrada;
    public:
        Motocicleta(string m, string mo, int af, double p,int cilindrada) :Vehiculo(m, mo, af, p), cilindrada(cilindrada) {}
        
        void mostrarDatos() {
            Vehiculo::mostrarDatos();
            cout << "cilindrada: " << cilindrada << endl;
        }
};

int main() {
  Vehiculo* vehiculo1 = new Automovil("hyunday", "leon", 2019, 23000.0, 4, "gasolina");
  Vehiculo* vehiculo2 = new Automovil("Honda", "Civic", 2020, 6700.0, 5, "gasolina");
  Vehiculo* vehiculo3 = new Motocicleta("toyota", "YZFA-45", 2021, 56000.0, 600);

  vehiculo1->mostrarDatos();
  cout << endl;
  vehiculo2->mostrarDatos();
  cout << endl;
  vehiculo3->mostrarDatos();
  cout << endl;

  return 0;
}