#include <iostream>
#include <string>
using namespace std;

class alumno{
    private:
        string nombre;
        string direccion;
        float notafinal;
    public:
        alumno(string n, string d, float nf){
            this -> nombre = n;
            this -> direccion = d;
            this -> notafinal=nf;
        }
    
    float getnotafinal() const{
        return notafinal;
    }

    string getnombre() const{
        return nombre;
    }

    friend alumno operator *(const alumno& a1, const alumno& a2){
        float promedio;
        promedio=(a1.notafinal+ a2.notafinal)/2;
        alumno pa(" "," ", promedio);
        return pa;
    }
};

int main(){
    alumno a1("luis","cercado",16);
    alumno a2("mateo","cayma",14);
    alumno promedio = a1*a2;
    cout<<"la nota del primer alumno  "<<a1.getnombre()<<"  ,la nota del 2do alumno "<<a2.getnombre()<<" es : "<<promedio.getnotafinal();
    return 0;
}