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

public:
    ArbolBST() {
        raiz = nullptr;
    }
    void insertarEmpleado(Empleado emp) {
        raiz = insertar(raiz, emp);
    }
};

int main() {
    ArbolBST arbol;
    cout << "Arbol BST creado correctamente." << endl;
    return 0;
}