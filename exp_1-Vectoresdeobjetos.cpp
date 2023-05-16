#include <iostream>
#include <vector>

using namespace std;

class Estudiante {
public:
    Estudiante(string nombre, int edad,int cod, float n1, float n2, float n3) {
        this->nombre = nombre;
        this->edad = edad;
        this->cod = cod;
        this->n1 = n1;
        this->n2 = n2;
        this->n3 = n3;
    }
    
    float getPromedio() const {
        return (n1 + n2 + n3) / 3.0;
    }
    
    string getEstado_Prom() const {
        float prom = getPromedio();
        if (prom < 12.0) {
            return "Desaprobado";
        } else {
            return "Aprobado";
        }
    }
    
    friend ostream& operator<<(ostream& os, const Estudiante& student);
    
private:
    string nombre;
    int edad;
    int cod;
    float n1, n2, n3;
};

ostream& operator<<(ostream& os, const Estudiante& student) {
    os << "Nombre: " << student.nombre << endl;
    os << "Edad: " << student.edad << endl;
    os << "Codigo: "<< student.cod <<endl;
    os << "Notas: " << student.n1 << ", " << student.n2 << ", " << student.n3 << endl;
    os << "Promedio: " << student.getPromedio() << endl;
    os << "Estado: " << student.getEstado_Prom() << endl;
    
    return os;
}

void ordenarPorPromedio(vector<Estudiante>& orden_student) {
    bool intercambio;
    do {
        intercambio = false;
        for (int i = 0; i < orden_student.size() - 1; i++) {
            if (orden_student[i].getPromedio() < orden_student[i + 1].getPromedio()) {
                swap(orden_student[i], orden_student[i + 1]); //intercambia el valor de dos variables
                intercambio = true;
            }
        }
    } while (intercambio);
}

int main() {
    // Crear el vector de estudiantes
    vector<Estudiante> estudiantes;
    estudiantes.push_back(Estudiante("Flor", 18, 20213012,17.0, 16.0, 18.0));
    estudiantes.push_back(Estudiante("Paul", 19, 20221214,19.0, 8.0, 11.0));
    estudiantes.push_back(Estudiante("Eliel", 19, 20221824,0, 7.0, 8.0));
    estudiantes.push_back(Estudiante("Alexander", 18, 20231517,14.0, 12.0, 6.0));
    
    // Ordenar el vector por promedio
    ordenarPorPromedio(estudiantes);
    
    // Imprimir los estudiantes aprobados
    float promedioMinimo = 01.0;
    for (const Estudiante& student : estudiantes) {
        if (student.getPromedio() >= promedioMinimo) {
            cout << student<< endl;
        }
    }
    
    for (const Estudiante& estudiante : estudiantes) {
        if (estudiante.getPromedio() < 1.0 || estudiante.getPromedio() > 20.0) {
            cout << "Error: Las notas de " << estudiante << "están fuera del rango permitido";
        }
    }
    return 0;
}
