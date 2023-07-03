#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

struct Evento {
    string nombre, fecha;
    vector<string> asistentes;
};

vector<Evento> listaEventos;

void agregarEvento() {
    Evento evento;
    cout << "ingrese el nombre del evento: ";cin >> evento.nombre;
    cout << "Ingrese la fecha del evento: ";cin >> evento.fecha;
    listaEventos.push_back(evento);
    cout << "Evento agregado exitosamente." <<endl;
}

void agregarAsistente() {
    string nombreEvento;
    cout << "Ingrese el nombre del evento al que desea agregar asistentes: ";
    cin >> nombreEvento;
    
    auto it = find_if(listaEventos.begin(), listaEventos.end(), [&](const Evento& evento) {
        return evento.nombre == nombreEvento;
    });
    
    if (it != listaEventos.end()) {
        cout << "Ingrese el nombre del asistente: ";
        string nombreAsistente;
        cin >> nombreAsistente;
        it->asistentes.push_back(nombreAsistente);
        cout << "Asistente agregado exitosamente." << endl;
    } else {
        cout << "El evento especificado no existe." << endl;
    }
}

void mostrarAsistentes() {
    string nombreEvento;
    cout << "Ingrese el nombre del evento para mostrar la lista de asistentes: ";
    cin >> nombreEvento;
    
    auto it = std::find_if(listaEventos.begin(), listaEventos.end(), [&](const Evento& evento) {
        return evento.nombre == nombreEvento;
    });
    
    if (it != listaEventos.end()) {
        cout << "Lista de asistentes para el evento " << it->nombre << ":" <<endl;
        sort(it->asistentes.begin(), it->asistentes.end());
        for (const auto& asistente : it->asistentes) {
            cout << asistente << std::endl;
        }
    } else {
        cout << "El evento especificado no existe." << endl;
    }
}

void buscarEventosPorFecha() {
    string fecha;
    cout << "Ingrese la fecha para buscar eventos: ";cin >> fecha;
    
    cout << "Eventos encontrados para la fecha " << fecha << ":" <<endl;
    for (const auto& evento : listaEventos) {
        if (evento.fecha == fecha) {
            cout << evento.nombre << endl;
        }
    }
}

int main() {
    char opcion;
    do {
        cout << "---------- Menú de opciones ----------" <<endl;
        cout << "a) Agregar un nuevo evento" <<endl;
        cout << "b) Agregar asistentes a un evento específico" <<endl;
        cout << "c) Mostrar la lista de asistentes de un evento en orden alfabético" << endl;
        cout << "d) Buscar eventos por fecha" << endl;
        cout << "e) Salir" << endl;
        cout << "Ingrese la opción deseada: ";cin >> opcion;
        
        switch (opcion) {
            case 'a':
                agregarEvento();
                break;
            case 'b':
                agregarAsistente();
                break;
            case 'c':
                mostrarAsistentes();
                break;
            case 'd':
                buscarEventosPorFecha();
                break;
            case 'e':
                cout << "¡Hasta luego!" << endl;
                break;
            default:
                cout << "Opción inválida. Intente nuevamente." << endl;
                break;
        }
        
        cout << endl;
    } while (opcion != 'e');
    
    return 0;
}
