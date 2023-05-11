#include <iostream>
using namespace std;

class MayorMenor{
    public:
       int a, b;
    
    MayorMenor(const int a, const int b){
        this -> a = a;
        this -> b = b;
    }
};

ostream& operator >> (ostream &x,const MayorMenor &p){
    if ( p.b < p.a ){
        x <<p.a<<" Es mayor";
        return x;
    }
    else{
        x<<p.b<<" Es mayor";
        return x;
    }
}

int main(){
    MayorMenor A (10,3);
    cout>>A;
    return 0;
}
