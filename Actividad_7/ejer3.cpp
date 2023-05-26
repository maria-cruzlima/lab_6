#include <iostream>
#include <string>
using namespace std;


class movil{
    private:
        string marca;
        string modelo;
        string so;
    public:
        movil(string marca, string modelo, string so){
            this -> marca= marca;
            this -> modelo = modelo;
            this -> so = so;
        }
        ~movil(){
            cout<< "eliminando el objeto movil"<<endl;
        }
};


class telefono: public movil{
    public:
       telefono (string marca, string modelo, string so): movil(marca , modelo, so){}
       ~telefono(){
            cout<<"eliminando el objeto telefono"<<endl;
        }
};


class tablet : public movil{
    public:
    tablet(string marca , string modelo, string so): movil(marca , modelo , so){}
    ~tablet(){
        cout<<"eliminando el objeto tablet"<<endl;
    }
};


int main(){
    movil* cel= new movil("huawei", "y7 pro", "android");
    telefono* cel1= new telefono("apple","phone","ios");
    tablet* tab=new tablet("redmi","redmi pro 7","android");


    delete cel;
    delete cel1;
    delete tab;


    return 0;
}
