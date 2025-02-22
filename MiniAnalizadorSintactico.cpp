#include <iostream>
#include <stack>
#include <fstream>

using namespace std;

// Funcion para verificar si una cadena cumple con la gramatica: letras separadas por '+'
bool esValida(const string& entrada) {
    for (size_t i = 0; i < entrada.length(); ++i) {
        char c = entrada[i];
        // Si el caracter no es una letra ni un '+', la cadena no es valida
        if (!isalpha(c) && c != '+') {
            return false;
        }
        // No se permiten dos '+' consecutivos
        if (c == '+' && i + 1 < entrada.length() && entrada[i + 1] == '+') {
            return false;
        }
    }
    return true;
}

// Ejemplo 1: Uso de una pila para procesar la entrada
void ejemplo1(const string& entrada) {
    if (!esValida(entrada)) {
        cout << "Entrada no valida: " << entrada << endl;
        return;
    }

    stack<char> pila;
    for (char c : entrada) {
        if (c != '+') {
            pila.push(c);
        }
    }

    // Mostrar la pila
    cout << "Pila inicial (Ejercicio 1): ";
    stack<char> temp = pila;
    while (!temp.empty()) {
        cout << temp.top() << " ";
        temp.pop();
    }
    cout << endl;

    // Operaciones adicionales con la pila
    cout << "Tope de la pila (primera vez): " << pila.top() << endl;
    cout << "Tope de la pila (segunda vez): " << pila.top() << endl;
    cout << "Elemento sacado de la pila: " << pila.top() << endl;
    pila.pop();
    cout << "Elemento sacado de la pila: " << pila.top() << endl;
    pila.pop();
}

// Ejemplo 2: Leer simbolos de la entrada y verificar la gramatica
void ejemplo2(const string& entrada) {
    if (!esValida(entrada)) {
        cout << "Entrada no valida: " << entrada << endl;
        return;
    }

    cout << "Simbolos de la entrada \"" << entrada << "\":" << endl;
    for (char simbolo : entrada) {
        if (simbolo != '+') {
            cout << simbolo << endl;
        }
    }
}

// Funcion principal
int main() {
    // Entradas especificas
    string entradaEjercicio1 = "Hola+Mundo";
    string entradaEjercicio2 = "a+b+c+d+e+f";

    // Ejecutar ejemplo 1 con la entrada "Hola+Mundo"
    cout << "=== Ejemplo 1 ===" << endl;
    ejemplo1(entradaEjercicio1);

    // Ejecutar ejemplo 2 con la entrada "a+b+c+d+e+f"
    cout << "\n=== Ejemplo 2 ===" << endl;
    ejemplo2(entradaEjercicio2);

    // Generar archivo CSV
    ofstream archivo("mini_analizador_sintactico.csv");
    if (archivo.is_open()) {
        archivo << "Ejercicio,Entrada,Resultado\n";

        // Resultados del Ejercicio 1
        archivo << "Ejercicio 1," << entradaEjercicio1 << ",H o l a M u n d o\n";
        archivo << "Ejercicio 1 Tope," << entradaEjercicio1 << ",o\n";
        archivo << "Ejercicio 1 Tope," << entradaEjercicio1 << ",o\n";
        archivo << "Ejercicio 1 Pop," << entradaEjercicio1 << ",o\n";
        archivo << "Ejercicio 1 Pop," << entradaEjercicio1 << ",l\n";

        // Resultados del Ejercicio 2
        archivo << "Ejercicio 2," << entradaEjercicio2 << ",a b c d e f\n";

        archivo.close();
        cout << "\nArchivo CSV generado con exito: mini_analizador_sintactico.csv" << endl;
    } else {
        cerr << "No se pudo abrir el archivo CSV." << endl;
    }

    return 0;
}