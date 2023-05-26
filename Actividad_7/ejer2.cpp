#include <iostream>
#include <string>
using namespace std;
class Persona {
protected:
  string direccionCorreo;


private:
  string nombre;
  int edad;
  double salario;


public:
  // Constructor
  Persona(const string& nombre, int edad, double salario, const string& direccionCorreo)
    : nombre(nombre), edad(edad), salario(salario), direccionCorreo(direccionCorreo) {
  }


  // Métodos de acceso a los atributos (getters)
  string getNombre() const {
    return nombre;
  }


  int getEdad() const {
    return edad;
  }


  double getSalario() const {
    return salario;
  }


  string getDireccionCorreo() const {
    return direccionCorreo;
  }


  // Métodos de modificación de los atributos (setters)
  void setNombre(const string& nuevoNombre) {
    nombre = nuevoNombre;
  }


  void setEdad(int nuevaEdad) {
    edad = nuevaEdad;
  }


  void setSalario(double nuevoSalario) {
    salario = nuevoSalario;
  }


  void setDireccionCorreo(const string& nuevaDireccionCorreo) {
    direccionCorreo = nuevaDireccionCorreo;
  }
};


class Empleado : public Persona {
public:
  // Constructor
  Empleado(const string& nombre, int edad, double salario, const string& direccionCorreo)
    : Persona(nombre, edad, salario, direccionCorreo) {
  }
};


class Cliente : public Persona {
public:
  // Constructor
  Cliente(const string& nombre, int edad, double salario, const string& direccionCorreo)
    : Persona(nombre, edad, salario, direccionCorreo) {
  }
};
int main() {
  Empleado empleado("Juan", 30, 2500.0, "juan@example.com");
  Cliente cliente("María", 25, 0.0, "maria@example.com");

  // Acceso a los atributos y métodos de los objetos
  cout << "Empleado:" << endl;
  cout << "Nombre: " << empleado.getNombre() << endl;
  cout << "Edad: " << empleado.getEdad() << endl;
  cout << "Salario: " << empleado.getSalario() << endl;
  cout << "Dirección de correo: " << empleado.getDireccionCorreo() << endl;

  cout << endl;

  cout << "Cliente:" << endl;
  cout << "Nombre: " << cliente.getNombre() << endl;
  cout << "Edad: " << cliente.getEdad() << endl;
  cout << "Salario: " << cliente.getSalario() << endl;
  cout << "Dirección de correo: " << cliente.getDireccionCorreo() << endl;

  return 0;
}

