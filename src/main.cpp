#include <iostream>
#include <string>
using namespace std;

struct Empleado {
    int codigo;
    string nombre;
    string cargo;
};

struct Nodo {
    Empleado dato;
    Nodo* izquierdo;
    Nodo* derecho;

    Nodo(Empleado emp) {
        dato = emp;
        izquierdo = nullptr;
        derecho = nullptr;
    }
};
class ArbolBST {
private:
    Nodo* raiz;
    Nodo* insertar(Nodo* nodo, Empleado emp) {
        if (nodo == nullptr) {
            return new Nodo(emp);
        }

        if (emp.codigo < nodo->dato.codigo) {
            nodo->izquierdo = insertar(nodo->izquierdo, emp);
        } else if (emp.codigo > nodo->dato.codigo) {
            nodo->derecho = insertar(nodo->derecho, emp);
        }

        return nodo;
    }
    Nodo* buscar(Nodo* nodo, int codigo) {
        if (nodo == nullptr || nodo->dato.codigo == codigo)
            return nodo;

        if (codigo < nodo->dato.codigo)
            return buscar(nodo->izquierdo, codigo);
        else
            return buscar(nodo->derecho, codigo);
    }

public:
    ArbolBST() {
        raiz = nullptr;
    }
    void insertarEmpleado(Empleado emp) {
        raiz = insertar(raiz, emp);
    }
    void buscarEmpleado(int codigo) {
        Nodo* resultado = buscar(raiz, codigo);

        if (resultado != nullptr) {
            cout << "\nEmpleado encontrado:\n";
            cout << "Codigo: " << resultado->dato.codigo << endl;
            cout << "Nombre: " << resultado->dato.nombre << endl;
            cout << "Cargo : " << resultado->dato.cargo << endl;
        } else {
            cout << "\nEmpleado no encontrado.\n";
        }
    }
};

int main() {
    ArbolBST arbol;
    arbol.insertarEmpleado({50, "Empresa UTA", "Raiz"});
    arbol.insertarEmpleado({30, "Gerente Ventas", "Gerente"});
    arbol.insertarEmpleado({70, "Gerente Finanzas", "Gerente"});

    arbol.buscarEmpleado(30);
    return 0;
}