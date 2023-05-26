#include <iostream>
#include <string>
using namespace std;

class Cliente {
protected:
  bool seguro;
  string nombre;
  string direccion;
  int numeroTelefono;
  int numeroCuenta;
// protected:
  // Método para encriptar la información
  // string encriptarInformacion(const string& informacion) {
  //   // Lógica para encriptar la información
  //   // ...
  //   return informacionEncriptada;
  // }
public:
  // Constructor
  Cliente(const bool& seguro, const string& nombre, const string& direccion, const int& numeroTelefono, const int& numeroCuenta)
    : seguro(seguro),nombre(nombre), direccion(direccion), numeroTelefono(numeroTelefono), numeroCuenta(numeroCuenta) {
        cout << "Base constructor" << endl;}

  // Métodos de acceso a los atributos (getters)
  string getNombre() const {
    return nombre;
  }

  string getDireccion() const {
    return direccion;
  }

  int getNumeroTelefono() const {
    return numeroTelefono;
  }

  int getNumeroCuenta() const {
    return numeroCuenta;
  }
    bool getseguro(){
    return seguro;
  }
  void setseguro(bool x){
    seguro = x;
  }  
  // Métodos de modificación de los atributos (setters)
  void setNombre(const string& nuevoNombre) {
    nombre = nuevoNombre;
  }

  void setDireccion(const string& nuevaDireccion) {
    direccion = nuevaDireccion;
  }

  void setNumeroTelefono(const int& nuevoNumeroTelefono) {
    numeroTelefono = nuevoNumeroTelefono;
  }

  void setNumeroCuenta(const int& nuevoNumeroCuenta) {
    numeroCuenta = nuevoNumeroCuenta;
  }


  friend ostream& operator<<(ostream& os, const Cliente& cliente);
  ~Cliente(){cout << "Base destructor" << endl;}
};

ostream& operator<<(ostream& os, Cliente& cliente) {
        os << "Nombre: " << cliente.getNombre() << endl;
        os << "Direccion: " << cliente.getDireccion() << endl;
        os << "Numero de telefono" << cliente.getNumeroTelefono() << endl;
        os << "Numero de cuenta: " << cliente.getNumeroCuenta() << endl;
        return os;
}
class ClienteSeguro : public Cliente {
int pin;
public:
  // Constructor
  ClienteSeguro(const bool& _seguro,const string& _nombre, const string& _direccion, const int& _numeroTelefono, const int& _numeroCuenta, int _pin)
    : Cliente(_seguro,_nombre, _direccion, _numeroTelefono, _numeroCuenta),pin(_pin)  {cout << "Derived constructor" << endl;}
  int getPIN(){
    return pin;
  }
  
  string encriptarInformacion( const string& informacion) {
    // Lógica para encriptar la información
    // ...
    // return informacionEncriptada;
  }

  string desencriptarInformacion(const string& informacionEncriptada) {
    // Lógica para desencriptar la información
    // ...
    // return informaciondesencriptada;
  }

  // Método para verificar la autenticidad del cliente
  void verificarAutenticidad() {
    cout << "Esta asegurado: " << (getseguro() ? "Sí" : "No") << endl;
    cout << "Numero PIN: "<<getPIN()<<endl;
  }
//   ~ClienteSeguro(){cout << "Derived destructor" << endl;}
};
int main() {
  // Creación de objetos Cliente

  // Creación de objetos ClienteSeguro
  ClienteSeguro clienteSeguro1(true, "Carlos", "Calle D", 111111111, 999999999, 1234);
  ClienteSeguro clienteSeguro2(true, "Ana", "Calle E", 222222222, 888888888, 5678);

  // Modificación de atributos
  clienteSeguro1.setNombre("Luis");
  clienteSeguro1.setDireccion("Calle F");
  clienteSeguro1.setNumeroTelefono(777777777);
  clienteSeguro1.setNumeroCuenta(555555555);

  // Obtención de atributos
  cout << clienteSeguro1<<endl;
  clienteSeguro1.verificarAutenticidad();
  cout << clienteSeguro2<<endl;
  clienteSeguro2.verificarAutenticidad();
}
