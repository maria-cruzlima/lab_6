#include <iostream>
using namespace std;
void funcion(float);

class Circuferencia{
    private://atributos 
    int radio; 
    float diametro;
    
    public:
    Circuferencia(int,float);//constructor y metodos 
    float pi=3.1416;
    float area=0;
    friend void calculaArea(Circuferencia&);
    void mostrar();//[1]
    
};


Circuferencia::Circuferencia(int _Radio, float _Diametro){
    radio=_Radio;
    diametro=_Diametro;
}

//nos ayuda a mostras datos [1]
void Circuferencia::mostrar(){
    cout<<"los datos son: "<<endl;
    cout<<"radio= "<<radio<<endl;
    cout<<"diametro= "<<diametro<<endl;
}

void calculaArea(Circuferencia& circulo){
    circulo.area = circulo.pi * (circulo.radio ^ 2);
    cout<<"el area es: "<<circulo.area;

}

int main(){
    
    Circuferencia total(5,10);
    total.mostrar();//metodo para mostrar datos [1]
    calculaArea(total);

}
