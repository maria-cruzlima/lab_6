#include <iostream>
#include <cstdio>
#include <chrono>
using namespace std;

float func (float x) 
{
    return x*x;
}

int main()
{   
        auto startTime = chrono::high_resolution_clock::now();
        //cout << "Introduzca los limites izquierdos y derechos (a y b): ";

        float left = 1;
        float right = 3;


        //cout << "Introduzca las particiones (n): ";

        int R= 10;//cuantas mas particiones mas es la exactitud

        float width = (right - left) / R;
        float total = 0;
        cout << width;
        for (int i = 0; i < R; i++) {
            total += func(left) * width;
            left += width;
        }  

        cout << "El resultado de la suma de rieman de x*x es: " << total << endl;
        auto endTime = chrono::high_resolution_clock::now();
        auto duration = chrono::duration_cast<chrono::milliseconds>(endTime - startTime).count();

        cout << "Execution Time: " << duration << " ms" << endl;
        return 0;
}
