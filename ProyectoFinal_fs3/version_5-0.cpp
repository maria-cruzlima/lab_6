#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Ser{
    public:
    virtual void show_attr()=0;
};
class Personas : public Ser{
    private:
        int clave;
    protected:
        string correo;
    public:
            string dni;
            string nombre, telefono; //validaciones
        Personas(int clave, const string& correo, const string& dni, const string& nombre, const string& telefono) : clave(clave), correo(correo), dni(dni), nombre(nombre), telefono(telefono) {}

        void show_attr() {
            cout << "clave: " << this->clave << endl;
            cout << "correo: " << this->correo << endl;
            cout << "DNI: " <<this->dni << endl;
            cout << "nombre: " << this->nombre << endl;
            cout << "teléfono: " << this->telefono << endl;
        }
        int get_clave(){
            return clave;
        }
};

class Cliente : public Personas {
    private:
        static int contador;
    public:
            int codigo;
            char categoria;
            string ruc,direccion;
        Cliente(int clave, const string& correo,const string& dni, const string& nombre, const string& telefono,int codigo, char categoria, const string& ruc, const string& direccion)
        : Personas(clave, correo, dni, nombre, telefono), codigo(codigo),categoria(categoria), ruc(ruc), direccion(direccion) {contador++;}
        static int get_contador(){
            return contador;
        }
    void show_attr() {

        cout << "clave: " << this->get_clave() << endl;
        cout << "correo: " << this->correo << endl;
        cout << "DNI: " << this->dni << endl;
        cout << "nombre: " << this->nombre << endl;
        cout << "teléfono: " << this->telefono << endl;
        cout << "Código: " << this->codigo << endl;
        cout << "Categoría: " << this->categoria << endl;
        cout << "RUC: " << this->ruc << endl;
        cout << "Dirección: " << this->direccion << endl;
    }
    virtual void descuento(int montoapagar){
        //divides el monto a pagar por el descuento
    }
};
class ClienteIndividuales : public Cliente {
    public:
    ClienteIndividuales(int clave, const string& correo,const string& dni, const string& nombre, const string& telefono,int codigo, char categoria, const string& ruc, const string& direccion)
        : Cliente(clave, correo,dni, nombre, telefono, codigo, categoria, ruc, direccion) {}

};

class ClienteCorporativos : public Cliente {
    public:
    ClienteCorporativos(int clave, const string& correo,const string& dni, const string& nombre, const string& telefono,int codigo, char categoria, const string& ruc, const string& direccion)
        : Cliente(clave, correo,dni, nombre, telefono, codigo,  categoria, ruc, direccion) {}

};

class Vendedores : public Personas {
private:
    static int Vcontador;
public:
        int codigo;
    Vendedores(int clave, const string& correo, const string& dni, const string& nombre, const string& telefono, int codigo)
        : Personas(clave, correo, dni, nombre, telefono), codigo(codigo) {Vcontador++;}

    static int get_contador(){
        return Vcontador;
    }
};
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
class Venta {
    public:
        Cliente* cliente;
        Producto* producto;
        int cantidad;
        Venta(Cliente* cliente, Producto* producto, int cantidad) : cliente(cliente), producto(producto) ,cantidad(cantidad) {}
};

ostream& operator<<(ostream& os, const Producto& _producto)  {
            os << "Código: " << _producto.codigo << endl;
            os << "Descripción: " << _producto.descripcion << endl;
            os << "Precio: " << _producto.precio << endl;
            os << "Tipo: " << _producto.tipo << endl;
            os << "Stock: " << _producto.stock << endl;
            return os;
        }


int Vendedores::Vcontador = 0;
int Cliente::contador = 0;
int Producto::Pcontador=0;
vector<Venta*> ventas;
vector<Producto*> productos;
vector<Cliente*> clientes;
vector<Vendedores*> vendedores;
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
void nuevoCliente() {
    int clave;
    string correo;
    string dni;
    string nombre;
    string telefono;
    string ruc;
    string direccion;
    char categoria;
    int contador = Cliente::get_contador();
    int codigo = contador + 1;
    bool notregconfir(string dni, string nombre, char _opcion);
    string validation(string _hilo, char _opcion);

    if (clientes.size() >= 6) { // valida si la agenda de Clientes  esta llena
        cout << "Agenda llena" << endl;
        return;
    }

    cout << "Ingrese clave: "; cin >> clave;
    cout << "Ingrese correo: ";cin >>  correo;
    cout << "Ingrese DNI: ";cin >> dni;validation(dni, '1' );
    cout << "Ingrese nombre: ";cin.ignore();getline(cin >> ws, nombre);
    bool rptafunc=notregconfir(dni, nombre, '1');
    if ( rptafunc== true){ //valida si ya se registro el usuario
        return;
    }

    cout << "Ingrese telefono: ";cin >> telefono;validation(telefono, '2');
    cout << "Ingrese categoria A,B o C de otro modo se pondra la categoria por default: "; cin >> categoria;
    cout << "Ingrese RUC: ";cin >> ruc;validation(ruc, '3');
    cout << "Ingrese direccion: ";cin.ignore();getline(cin >> ws, direccion);

    Cliente* nuevo_cliente;
    if (categoria == 'A' || categoria == 'B' || categoria  == 'C' ) {
        nuevo_cliente = new ClienteIndividuales(clave, correo,dni, nombre, telefono, codigo, categoria, ruc, direccion);
    } else {

        categoria = 'D';
        nuevo_cliente = new ClienteCorporativos(clave, correo,dni, nombre, telefono, codigo ,categoria, ruc, direccion);
    }

    clientes.push_back(nuevo_cliente);
}
string validation(string _hilo, char _opcion){
    switch (_opcion)
    {
        case '1':
            while (_hilo.length() != 8) {
                cout << "DNI debe tener 8 digitos. Ingrese de nuevo: ";cin >> _hilo;
            }
            return _hilo;

        case '2':
            while (_hilo.length() != 9) {
                cout << "TELEFONO debe tener 9 digitos. Ingrese de nuevo: ";cin >> _hilo;
            }
            return _hilo;

        case '3':
            while (_hilo.length() != 11) {
                cout << "RUC debe tener 11 digitos. Ingrese de nuevo: ";cin >> _hilo;
            }
            return _hilo;

        default:
            return _hilo;
    }
};
void buscarCliente() {
    string dni;
    cout << "Ingrese DNI: ";cin >> dni;

    for (int i = 0; i <= clientes.size(); i++) {
        cout<<"inicio el bucle"<<endl;
        if (clientes[i]->dni == dni) {
            cout << "Codigo: " << i+1 << endl;
            cout << "Nombre: " << clientes[i]->nombre << endl;
            cout << "Direccion: " << clientes[i]->direccion << endl;
            cout << "Categoria: " << clientes[i]->categoria << endl;
            return;
        }
    }
    cout << "Cliente no encontrado" << endl;
}
void backclients(int clave, string correo, string dni,string nombre,string telefono,int codigo, char categoria, string ruc, string direccion){
    int contador = Cliente::get_contador();
    codigo = contador + 1;
    Cliente* nuevo_cliente;
    if (categoria == 'A' || categoria == 'B' || categoria  == 'C' ) {
        nuevo_cliente = new ClienteIndividuales(clave, correo,dni, nombre, telefono, codigo, categoria, ruc, direccion);
    } else {

        categoria = 'D';
        nuevo_cliente = new ClienteCorporativos(clave, correo,dni, nombre, telefono, codigo ,categoria, ruc, direccion);
    }

    clientes.push_back(nuevo_cliente);
}
void backproducto(string descripcion,double precio,char tipo,int stock ){
    Producto* nuevo_producto;
    int contador = Producto::get_Pcontador();
    int codigo = contador + 1;
    nuevo_producto = new Producto(codigo, descripcion, precio, tipo, stock );
    productos.push_back(nuevo_producto);
}
void nuevoVendedor() {
        int clave;
        string correo;
        string dni;
        string nombre,telefono;
        int contador = Vendedores::get_contador();
        int codigo = contador + 1;
        bool notregconfir(string dni, string nombre, char _opcion);
        string validation(string _hilo, char _opcion);
    if (vendedores.size() >= 13) { // valida si la agenda de Clientes  esta llena
        cout << "Agenda llena" << endl;
        return;
    }
    cout << "Ingrese clave: "; cin >> clave;
    cout << "Ingrese correo: ";cin >> correo;
    cout << "Ingrese DNI: "; cin >> dni;validation(dni,'1');
    cout << "Ingrese nombre: ";cin.ignore();getline(cin >> ws, nombre);
    bool rptafunc=notregconfir(dni, nombre, '2');
    if(rptafunc==true){
        return;
    }

    cout << "Ingrese telefono: ";cin >> telefono;validation(telefono,2);
    Vendedores* nuevo_vendedor = new Vendedores(clave, correo,dni, nombre, telefono,codigo);
    vendedores.push_back(nuevo_vendedor);
}
void backsellers(int clave, string correo, string dni,string nombre,string telefono,int codigo){
    int contador = Vendedores::get_contador();
    codigo = contador + 1;
    Vendedores* nuevo_vendedor = new Vendedores(clave, correo,dni, nombre, telefono,codigo);
    vendedores.push_back(nuevo_vendedor);
}
bool notregconfir(string dni, string nombre, char _opcion){

    switch (_opcion)
    {
    case '1':
        cout<<"caso 1"<<endl;
        for (int i = 0; i < clientes.size(); i++) {
            if (clientes[i]->dni == dni || clientes[i]->nombre == nombre) {
                cout << "Cliente ya registrado" << endl;
                return true;
            }
            else{
                return false;
            }
        }

    case '2':
        cout<<"caso 2"<<endl;
        for (int i = 0; i < vendedores.size(); i++) {
            if (vendedores[i]->dni == dni || vendedores[i]->nombre == nombre) {
                cout << "Vendedor ya registrado" << endl;
                return true;
            }
            else {
                return false;
            }
        }
    default:
        return false;
    }
};
void listClients() {

    cout << "                                      CLIENTE "<< endl;
    cout << "    º  DNI   |   NOMBRE   |   TELEFONO   |   CATEGORIA   |     RUC     |   DIRECCION º  "<< endl;
    cout << "--------------------------------------------------------------------------------------"<< endl;
    for (int i = 0; i < clientes.size(); i++) {
        cout <<i+1 <<"       "<< endl;
        cout <<"   "<<clientes[i]->dni<<"   ";
        cout <<"   "<<clientes[i]->nombre<<"   ";
        cout <<"   "<<clientes[i]->telefono<<"   ";
        cout <<"   "<<clientes[i]->categoria<<"   ";
        cout <<"   "<<clientes[i]->ruc<<"   ";
        cout <<"   "<<clientes[i]->direccion<<"   ";
        cout <<"   "<<clientes[i]->codigo<<endl;
    cout << "-------------------------------------------------------------------------------------" << endl;
    }
}
void listsellers() {

    cout << "             VENDEDOR "<< endl;
    cout << "  º DNI   |   NOMBRE   |   TELEFONO º   "<< endl;
    cout << "--------------------------------------------------------------------------------------"<< endl;
    for (int i = 0; i < vendedores.size(); i++) {
        cout <<i+1 <<"       "<< endl;
        cout <<"   "<<vendedores[i]->dni<<"   ";
        cout <<"   "<<vendedores[i]->nombre<<"   ";
        cout <<"   "<<vendedores[i]->telefono<<"  ";
        cout <<"   "<<vendedores[i]->codigo<<endl;
    cout << "-------------------------------------------------------------------------------------" << endl;
    }
}
void compras() {
    int codigo_cliente, codigo_producto, cantidad, nuevo_stock;
    cout << "Ingrese el codigo del cliente: ";cin >> codigo_cliente;

    if (codigo_cliente < 1 || codigo_cliente > clientes.size()) {
        cout << "Usuario no registrado, operación invalida" << endl;
        return;
    }

    cout << "ingrese el codigo del producto: ";cin >> codigo_producto;

    if (codigo_producto < 1 || codigo_producto > productos.size()) {
        cout << "Producto no registrado, operación invalida" << endl;
        return;
    }

    cout <<"Ingrese la cantidad a comprar";cin>> cantidad;

    if (productos[codigo_producto - 1]->getStock()>=cantidad){
        nuevo_stock = productos[codigo_producto - 1]->getStock() - cantidad;
        productos[codigo_producto - 1]->setStock(nuevo_stock);
    }
    else{
        cout<<"La cantidad que se quiere comprar supera a el stock almacenado del producto que se pide"<<endl;
    }
    Venta* nueva_venta = new Venta(clientes[codigo_cliente - 1], productos[codigo_producto - 1], cantidad);
    ventas.push_back(nueva_venta);

    cout << "Venta realizada con éxito" << endl;
}
void listarVentasCliente() {
    int codigo_cliente;
    int monto;
    cout << "Ingrese el codigo del cliente ";cin >> codigo_cliente;

    if (codigo_cliente < 1 || codigo_cliente > clientes.size()) {
        cout << "Usuario no registrado, operación invalida" << endl;
        return;
    }

    cout << "ventas del cliente " << clientes[codigo_cliente - 1]->nombre << ":" << endl;
    for (Venta* venta : ventas) {
        if (venta->cliente == clientes[codigo_cliente - 1]) {
            monto = venta->producto->getPrecio() * venta->cantidad;
            cout << "Producto: " << venta->producto->getDescripcion()<< ", Precio: " << venta->producto->getPrecio() <<", Cantidad:"<< venta->cantidad<<", Monto final:"<<monto<<endl;
        }
    }
}
int main() {
    int opcion;
    backsellers(1, "correo1@example.com", "11111111-1", "Vendedor 1", "123456789", 0);
    backsellers(2, "correo2@example.com", "22222222-2", "Vendedor 2", "987654321", 0);
    backsellers(3, "correo3@example.com", "33333333-3", "Vendedor 3", "456789123", 0);
    backsellers(4, "correo4@example.com", "44444444-4", "Vendedor 4", "321654987", 0);
    backsellers(5, "correo5@example.com", "55555555-5", "Vendedor 5", "789123456", 0);
    backsellers(6, "correo6@example.com", "66666666-6", "Vendedor 6", "654987321", 0);
    backsellers(7, "correo7@example.com", "77777777-7", "Vendedor 7", "321456789", 0);
    backsellers(8, "correo8@example.com", "88888888-8", "Vendedor 8", "987321654", 0);
    backsellers(9, "correo9@example.com", "99999999-9", "Vendedor 9", "123789456", 0);
    backsellers(10, "correo10@example.com", "10101010-0", "Vendedor 10", "456123789", 0);
    backclients(123, "correo1@example.com", "12345678", "Cliente 1", "987654321", 1, 'A', "1234567890", "Dirección 1");
    backclients(456, "correo2@example.com", "98765432", "Cliente 2", "123456789", 2, 'B', "0987654321", "Dirección 2");
    backclients(789, "correo3@example.com", "54321678", "Cliente 3", "123456789", 3, 'C', "9876543210", "Dirección 3");
    backproducto("Laptop", 1200.0, 'E', 10);
    backproducto("Celular", 500.0, 'E', 20);   
    backproducto("Teclado", 30.0, 'A', 50);

    do {
        cout << "---------------------------------"<<endl;
        cout << "        SISTEMA COMERCIAL        "<<endl;
        cout << "---------------------------------"<<endl;
        cout << "1 .- Nuevo Cliente" << endl;
        cout << "2 .- Buscar Cliente" << endl;
        cout << "3 .- Nuevo Vendedor" << endl;
        cout << "4 .- Nuevo Producto" << endl;
        cout << "5 .- Lista de clientes" << endl;
        cout << "6 .- Lista de vendedores" << endl;
        cout << "7 .- Ventas    " << endl;
        cout << "8 .- Lista de ventas"<<endl;
        cout << "0 .- Salir" << endl;
        cout << "Ingrese opcion: ";cin >> opcion;

        switch (opcion) {
            case 1:
                nuevoCliente();
                break;
            case 2:
                buscarCliente();
                break;
            case 3:
                nuevoVendedor();
                break;
            case 4:
                nuevoProducto();
                break;
            case 5:
                listClients();
                break;
            case 6:
                listsellers();
                break;
            case 7:
                compras();
                break;
            case 8: 
                listarVentasCliente();
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
