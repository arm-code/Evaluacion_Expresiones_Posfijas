#ifndef PILA_DIN_H
#define PILA_DIN_H
#include <cstddef>

// Definici�n de la clase PilaDinamica
class PilaDinamica {
private:
    struct Nodo {
        int valor;
        Nodo* siguiente;
        Nodo(int val) : valor(val), siguiente(NULL) {}
    };

    Nodo* tope; // Puntero al nodo en la cima de la pila

public:
    PilaDinamica(); // Constructor
    ~PilaDinamica(); // Destructor
    void push(int valor); // Inserta un elemento en la cima de la pila
    int pop(); // Elimina y devuelve el elemento en la cima de la pila
    bool estaVacia() const; // Comprueba si la pila est� vac�a
};

#endif // PILA_DIN_H

