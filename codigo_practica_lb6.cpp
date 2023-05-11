#include <iostream>
#include <vector>
#include <string>
using namespace  std;
 
 
// primer compañero
class Alumno {
	private:
    	string nombre;
    	int edad;
    	float Promedio;
	public:
    	Alumno(string nombre, int edad, float promedio) {
            this->nombre = nombre;
            this->edad = edad;
            this->Promedio = promedio;
    	}
 
 
    	void mostrarDatos(){
            cout<<"nombre= "<<nombre<<endl;
            cout<<"edad= "<<edad<<endl;
            cout<<"promedio= "<<Promedio<<endl;
    	}
    	string getNombre() {return this->nombre;}
    	int getEdad() {return this->edad;}
    	float getPromedio(){return this->Promedio;}
 
 
    	bool comparar(float promedioOtro){
        	if (Promedio < promedioOtro){
            	return true;
        	}
    	}
};
//segundo compañero
class Grupo {
	private:
   	int cantidad;
       vector<Alumno> alumnos;
 
 
	public:
    	Grupo(int cantidad) {
            this->cantidad = cantidad;
    	}
 
 
    	void agregar_alumno(string nombre, int edad, float promedio) {
        	Alumno nuevo_alumno(nombre, edad, promedio);
            alumnos.push_back(nuevo_alumno);
    	}
 
 
    	void ordenar_por_promedio() {
        	bool intercambio;
        	do {
                intercambio = false;
            	for (int i = 0; i < alumnos.size() - 1; i++) {
                	if (alumnos[i].getPromedio() > alumnos[i + 1].getPromedio()) {
                        swap(alumnos[i], alumnos[i + 1]);
                        intercambio = true;
    	            }
            	}
        	} while (intercambio);
    	}
 
 
    	float promedio_grupo() {
        	float suma_promedios = 0.0;
        	for (Alumno& alumno : alumnos) {
                suma_promedios += alumno.getPromedio();
            }
        	return suma_promedios / alumnos.size();
    	}
 
 
    	Alumno mejor_promedio() {
        	Alumno mejor_alumno("", 0, 0.0);
        	for (Alumno& alumno : alumnos) {
            	if (alumno.getPromedio() > mejor_alumno.getPromedio()) {
                    mejor_alumno = alumno;
            	}
        	}
        	return mejor_alumno;
    	}
 
 
    	string toString() {
        	string lista_alumnos = "";
        	for (Alumno& alumno : alumnos) {
                lista_alumnos += "Nombre: " + alumno.getNombre() + " Edad: " + to_string(alumno.getEdad()) + " Promedio: " + to_string(alumno.getPromedio()) + "\n";
        	}
        	return lista_alumnos;
    	}
};
int main() {
	Grupo grupo(5);
    grupo.agregar_alumno("Juan Perez", 20, 8.5);
    grupo.agregar_alumno("Maria Gomez", 18, 7.5);
    grupo.agregar_alumno("Pedro Rodriguez", 22, 9.0);
    grupo.agregar_alumno("Ana Martinez", 19, 6.5);
	grupo.agregar_alumno("Carlos Chavez", 21, 8.0);
 
 
	cout << "Lista de alumnos: " << endl;
	cout << grupo.toString() << endl;
 
 
	float promedio_promedios = grupo.promedio_grupo();
	cout <<"Promedio de los promedios del grupo: " << promedio_promedios << endl;
 
 
	Alumno alumno_mejor_promedio = grupo.mejor_promedio();
	cout <<"Alumno con mejor promedio: " << endl;
    alumno_mejor_promedio.mostrarDatos();
	return 0;
}
