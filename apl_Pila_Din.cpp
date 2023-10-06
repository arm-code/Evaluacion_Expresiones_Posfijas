#include <iostream>
#include <string>
#include "Pila_Din.h"
#include <cmath>

using namespace std;

// ESTA ES NUESTRA FUNCION PARA REALIZAR LAS OPERACIONES, RECIBE LOS DOS OPERANDOS Y EL OPERADOR
// SE UTILIZA MAS ADELANTE A LA HORA DE EVALUAR LA CADENA
// ESTA FUNCIONAR RETORNA EL RESULTADO DE LA OPERACION
int realizarOperacion(int operando1, int operando2, char operador) {
    switch (operador) {
        case '+':
            return operando1 + operando2;
        case '-':
            return operando1 - operando2;
        case '*':
            return operando1 * operando2;
        case '^':
        	return pow(operando1, operando2);
        // EL CASO DE LA DIVISION ES ESPECIAL, DADO QUE PUEDE LLEVAR A ERRORES COMO DIVISION POR CERO.
        // PARA PREVENIR UTILIZAMOS UN EXCEPCION.
        case '/':
            if (operando2 != 0)
                return operando1 / operando2;
            else
                throw "Error: DIVISION POR CERO!!!\n";
        default:
            throw "Error: OPERADOR NO VALIDO!!!\n";
    }
}

int main() {
    string expresion;
    cout << "Programa para checar expresiones.\n";
    cout << "Introduce expresion a evaluar: ";
    cin >> expresion;

	// CREAMOS UN OBJETO TIPO PilaDinamica, para poder hacer uso de los diferentes metodos de la pila.
	// Last in, First Out (ultimo en entrar, primero en salir)
    PilaDinamica pila;

	// RECORREMOS LA CADENA QUE VAMOS A EVALUSAR CON UN CICLO FOR
    for (int i = 0; i < expresion.length(); i++) {
    	// GUARDAMOS EN LA VARIABLE c EL VALOR EN LA POSICION i DE NUESTRA CADENA expresion
        char c = expresion[i];
        // PARA SABER EL FINAL DE LA CADENA UTILIZAMOS \0
        if (c == '\0') {
            break; // SI SE DETECTA EL FINAL DE LA CADENA, SALIMOS DEL CICLO FOR
        } else if (c == ' ') {
            // PARA PREVENIR ERRORES, IGNORAMOS LOS ESPACIOS QUE PUEDA INTRODUCIR EL USUARIO
            continue;
        // DEBEMOS DE REVISAR SI ES UN OPERANDO, PARA ELLO USAMOS LA SIGUIENTE CONDICIONAL
        } else if (isdigit(c)) { 		// SI ES OPERANDO
            int operando = c - '0'; 	// CONVERTIMOS EL CARACTER A ENTERO
            pila.push(operando);		// Y LO METEMOS A LA PILA
        } else { 						// SI ES OPERADOR
            try {
                int operando2 = pila.pop();	//SACAMOS EL TOPE DE LA PILA Y LO ASIGNAMOS A LA VARIABLE OPER2
                int operando1 = pila.pop(); // SACAMOS EL SIG ELEMENTO DE LA PILA Y LO ASIGNAMOS A LA VARIABLE OPER1
                int resultado = realizarOperacion(operando1, operando2, c); // MANDAMOS LOS OPERANDO 1 Y 2 A NUESTRA FUNCION Y EL OPERADOR 
                pila.push(resultado); // GUARDAMOS EL RESULTADO QUE NOS RETORNA LA FUNCION relizarOperacion EN LA PILA
            } catch (const char* error) {
                cerr << error << endl;
                return 1;
            }
        }
    } // EN ESTE PUNTO TERMINA LA EJECUCION DEL CICLO FOR, SIGNIFICA QUE SE HA TERMINADO DE PROCESAR LA CADENA INGRESADA
	// UNA VEZ TERMINADO EL PROCESO DE LA CADENA
	// SE PROCEDE SACAR EL ULTIMO VALOR DE LA PILA
	// SI OCURRE UN ERROR, MANEJAREMOS LAS EXCEPCIONES CON UN TRY CATCH
    try {
        int resultadoFinal = pila.pop();
        if (pila.estaVacia()) {
            cout << "RESULTADO FINAL: " << resultadoFinal << endl;
        } else {
            cerr << "Error: EXPRESION NO VALIDA!!!" << endl;
            return 1;
        }
    } catch (const char* error) {
        cerr << error << endl;
        return 1;
    }

    return 0;
}

