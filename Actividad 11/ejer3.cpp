#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
struct Agenda {
 string name = "";
 int number = 0;
 string correo = "";
};
void agregarContacto(vector<Agenda>& person){
 Agenda newContacto;
 string nombre;
 int numero;
 cout << "\nIngrese el nombre: ";
 cin >> newContacto.name;
 cout << "Ingrese su numero telefonico: ";
 cin >> newContacto.number;
 cout << "Ingrese su correo electronico: ";
cin >> newContacto.correo;
 person.push_back(newContacto);
 cout << "Contacto agregado correctamente..." << endl;
}
void buscarContacto(vector<Agenda>& person){
 string nombre;
 cout << "Ingrese el nombre del contacto: ";
 cin >> nombre;
 cout << '\n';
 auto iter = find_if(person.begin(), person.end(), [&](const 
Agenda& contact){ return contact.name == nombre; });
 if (iter != person.end()){
 cout << "Nombre: " << iter->name << endl;
 cout << "Numero: " << iter->number << endl;
 cout << "Correo: " << iter->correo << endl;
 } else {
 cout << "El contacto indicado no existe..." << endl;
 }
}
void actualizarContacto(vector<Agenda>& person){
 string nombre;
 cout << "Ingrese el nombre del contacto: ";
 cin >> nombre;
 auto iter = find_if(person.begin(), person.end(), [&](Agenda& 
contact){ return contact.name == nombre; });
 if (iter != person.end()){
 cout << '\n';
 cout << "Ingrese su nuevo numero: ";
 cin >> iter->number;
 cout << "Ingrese su nuevo correo: ";
 cin >> iter->correo;
 } else {
 cout << "El contacto indicado no existe..." << endl;
 }
}
void mostrarContactos(vector<Agenda>& person){
 cout << "**************" << endl;
 cout << " CONTACTOS " << endl;
 cout << "**************" << endl;
 cout << '\n';
 sort(person.begin(), person.end(), [](const Agenda& i, const 
Agenda& j){ return i.name < j.name;});
 for (const auto& iter : person){
 cout << "Nombre: " <<iter.name << endl;
 cout << "Numero: " << iter.number << endl;
 cout << "Correo " << iter.correo << endl;
 cout << "-----------------------------------" << endl;
 }
}
int main(){
 vector<Agenda>contacts;
 int opc;
while (true){
 cout << "**************" << endl;
 cout << " AGENDA PERSONAL " << endl;
 cout << "**************" << endl;
 cout << "1. Agregar un nuevo contacto \n2. Buscar un contacto 
por su nombre \n3. Actualizar la información de un contacto \n";
 cout << "4. Mostrar lista de contactos \n5. Salir " << endl;
 cout << "Ingrese una opcion: ";
 try {
 cin >> opc;
 if (opc == 1){
 agregarContacto(contacts);
 }
 if (opc == 2){
 buscarContacto(contacts);
 }
 if (opc == 3){
 actualizarContacto(contacts);
 }
 if (opc == 4){
 mostrarContactos(contacts);
 }
 if (opc == 5){
 break;
 }
 if (cin.fail()){
 throw "ERROR DE INGRESO";
 }
 } catch (const char* error) {
 cout << error << endl;
 cin.clear();
 cin.ignore(1);
 }
 }
}
