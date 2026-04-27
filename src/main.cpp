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
    void mostrarEmpleado(Nodo* nodo) {
        cout << "Codigo: " << nodo->dato.codigo
             << " | Nombre: " << nodo->dato.nombre
             << " | Cargo: " << nodo->dato.cargo << endl;
    }
    void inorden(Nodo* nodo) {
        if (nodo != nullptr) {
            inorden(nodo->izquierdo);
            mostrarEmpleado(nodo);
            inorden(nodo->derecho);
        }
    }

    void preorden(Nodo* nodo) {
        if (nodo != nullptr) {
            mostrarEmpleado(nodo);
            preorden(nodo->izquierdo);
            preorden(nodo->derecho);
        }
    }

    void postorden(Nodo* nodo) {
        if (nodo != nullptr) {
            postorden(nodo->izquierdo);
            postorden(nodo->derecho);
            mostrarEmpleado(nodo);
        }
    }
    int altura(Nodo* nodo) {
        if (nodo == nullptr) {
            return 0;
        }

        int alturaIzq = altura(nodo->izquierdo);
        int alturaDer = altura(nodo->derecho);

        return 1 + max(alturaIzq, alturaDer);
    }

    void mostrarHojas(Nodo* nodo) {
        if (nodo != nullptr) {
            if (nodo->izquierdo == nullptr && nodo->derecho == nullptr) {
                mostrarEmpleado(nodo);
            }
            mostrarHojas(nodo->izquierdo);
            mostrarHojas(nodo->derecho);
        }
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
            mostrarEmpleado(resultado);
        } else {
            cout << "\nEmpleado no encontrado.\n";
        }
    }
    void mostrarRaiz() {
        if (raiz != nullptr) {
            cout << "\nRaiz del arbol:\n";
            mostrarEmpleado(raiz);
        } else {
            cout << "El arbol esta vacio.\n";
        }
    }
    void mostrarInorden() {
        cout << "\nRecorrido Inorden:\n";
        inorden(raiz);
    }

    void mostrarPreorden() {
        cout << "\nRecorrido Preorden:\n";
        preorden(raiz);
    }

    void mostrarPostorden() {
        cout << "\nRecorrido Postorden:\n";
        postorden(raiz);
    }
    void mostrarAltura() {
        cout << "\nAltura del arbol: " << altura(raiz) << endl;
    }

    void mostrarNodosHoja() {
        cout << "\nNodos hoja:\n";
        mostrarHojas(raiz);
    }
};

int main() {
    ArbolBST arbol;
    arbol.insertarEmpleado({50, "Empresa UTA", "Raiz"});
    arbol.insertarEmpleado({30, "Gerente Ventas", "Gerente"});
    arbol.insertarEmpleado({70, "Gerente Finanzas", "Gerente"});
    arbol.insertarEmpleado({20, "Empleado 1", "Hoja"});
    arbol.insertarEmpleado({40, "Empleado 2", "Hoja"});
    arbol.insertarEmpleado({60, "Empleado 3", "Hoja"});
    arbol.insertarEmpleado({80, "Empleado 4", "Hoja"});

    arbol.mostrarRaiz();
    arbol.mostrarInorden();
    arbol.mostrarAltura();
    arbol.mostrarNodosHoja();
    return 0;
}