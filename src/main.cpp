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

public:
    ArbolBST() {
        raiz = nullptr;
    }
};

int main() {
    ArbolBST arbol;
    cout << "Arbol BST creado correctamente." << endl;
    return 0;
}