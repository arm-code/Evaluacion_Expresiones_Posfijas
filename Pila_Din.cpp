#include "Pila_Din.h"
#include <cstddef>
// Constructor: Inicializa una pila vac�a
PilaDinamica::PilaDinamica() : tope(NULL) {}

// Destructor: Libera la memoria de todos los nodos de la pila
PilaDinamica::~PilaDinamica() {
    while (!estaVacia()) {
        pop();
    }
}

// Inserta un elemento en la cima de la pila,
void PilaDinamica::push(int valor) {
    Nodo* nuevoNodo = new Nodo(valor);
    nuevoNodo->siguiente = tope;
    tope = nuevoNodo;
}

// Hace pop en la pila, es decir quita (elimina) el elemento que esta en el tope de la pila
int PilaDinamica::pop() {
    if (estaVacia()) {
        throw "La pila esta vacia!!!";
    }
    int valor = tope->valor;
    Nodo* nodoAEliminar = tope;
    tope = tope->siguiente;
    delete nodoAEliminar;
    return valor;
}

// Se debe revisar si la pila esta vacia
bool PilaDinamica::estaVacia() const {
    return tope == NULL;
}

