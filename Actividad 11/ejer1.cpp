#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Producto{
    private:
        static int Pcontador;
        int codigo;
        string descripcion;
        double precio;
        char tipo;
        int stock;
    public:

    Producto(int codigo, const string& descripcion, double precio, char tipo, int stock)
    : codigo(codigo), descripcion(descripcion), precio(precio), tipo(tipo), stock(stock) {Pcontador++;}
    static int get_Pcontador(){
        return Pcontador;
    }
        // Getters
        int getCodigo() const {
            return codigo;
        }

        string getDescripcion() const {
            return descripcion;
        }

        double getPrecio() const {
            return precio;
        }

        char getTipo() const {
            return tipo;
        }

        int getStock() const {
            return stock;
        }
        void setCodigo(int nuevoCodigo) {
            codigo = nuevoCodigo;
        }

        // Setter para el atributo "descripcion"
        void setDescripcion(const string& nuevaDescripcion) {
            descripcion = nuevaDescripcion;
        }

        // Setter para el atributo "precio"
        void setPrecio(double nuevoPrecio) {
            precio = nuevoPrecio;
        }

        // Setter para el atributo "tipo"
        void setTipo(char nuevoTipo) {
            tipo = nuevoTipo;
        }

        // Setter para el atributo "stock"
        void setStock(int nuevoStock) {
            stock = nuevoStock;
        }
    friend ostream& operator<<(ostream& os, const Producto& _producto);
};
int Producto::Pcontador=0;
void nuevoProducto(){
    Producto* nuevo_producto;
    int contador = Producto::get_Pcontador();
    int codigo = contador + 1;
    string descripcion;
    double precio;
    char tipo;
    int stock;
    if (vendedores.size() >=5 ) { // valida si la agenda de Clientes  esta llena
        cout << "Agenda llena" << endl;
        return;
    }
    cout << "Ingrese la descripción: ";
    cin.ignore(); // Ignore any previous newline character in the input buffer
    getline(cin >> ws, descripcion);

    cout << "Ingrese el precio: ";
    cin >> precio;

    cout << "Ingrese el tipo: ";
    cin >> tipo;

    cout << "Ingrese el stock: ";
    cin >> stock;
    nuevo_producto = new Producto(codigo, descripcion, precio, tipo, stock );
    productos.push_back(nuevo_producto);
}
void backproducto(string descripcion,double precio,char tipo,int stock ){
    Producto* nuevo_producto;
    int contador = Producto::get_Pcontador();
    int codigo = contador + 1;
    nuevo_producto = new Producto(codigo, descripcion, precio, tipo, stock );
    productos.push_back(nuevo_producto);
}
int main (){
    backproducto("Laptop", 1200.0, 'E', 10);
    backproducto("Celular", 500.0, 'E', 20);   
    backproducto("Teclado", 30.0, 'A', 50);
    cout << "Ingrese opcion 1 : ";cin >> opcion;

        switch (opcion) {
            case 1:
                nuevoProducto();
                break;
            case 0:
                cout << "Saliendo..." << endl;
                break;
            default:
                cout << "Opcion invalida" << endl;
                break;
        }

    } while (opcion != 0);
    return 0;
}
