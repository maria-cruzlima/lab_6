#include <iostream>
#include <string>

using namespace std;

class notas{
    public:
       string nom;
       string direc;
       float nspf;
    
    notas(const string nom, const string direc, float nspf){
        this -> nom = nom;
        this -> direc = direc;
        this -> nspf = nspf;
 
    }
};

int operator * (const notas& a, const notas& b){
    int promedio = (a.nspf + b.nspf)/2;
    return promedio;
}


int main(){
    notas A ("Paul", "Los angles", 17);
    notas B ("Rum", "rumrum", 10);

    int p = A*B;

    cout<<"El promedio de "<<A.nom<<" y "<<B.nom<<"es: "<<p;
    return 0;
}
