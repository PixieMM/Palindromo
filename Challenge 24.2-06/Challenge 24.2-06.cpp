#include <iostream>
#include <string>
#include <cctype> // Para usar la función std::tolower

using namespace std;

// Función para verificar si una cadena es un palíndromo
bool esPalindrome(const string& str) {
    int izquierda = 0;
    int derecha = str.length() - 1;

    while (izquierda < derecha) {
        // Ignorar los caracteres que no son letras
        while (!isalnum(str[izquierda]) && izquierda < derecha) {
            izquierda++;
        }
        while (!isalnum(str[derecha]) && izquierda < derecha) {
            derecha--;
        }

        // Convertir caracteres a minúsculas para la comparación
        char charIzquierda = tolower(str[izquierda]);
        char charDerecha = tolower(str[derecha]);

        // Comparar caracteres
        if (charIzquierda != charDerecha) {
            return false; // No es un palíndromo
        }

        // Mover los índices hacia el centro
        izquierda++;
        derecha--;
    }

    return true; // Es un palíndromo
}

int main() {
    string cadena;

    // Solicitar al usuario que ingrese una cadena
    cout << "Ingrese una cadena: ";
    getline(cin, cadena);

    // Verificar si la cadena es un palíndromo
    if (esPalindrome(cadena)) {
        cout << "La cadena \"" << cadena << "\" es un palíndromo." << endl;
    } else {
        cout << "La cadena \"" << cadena << "\" no es un palíndromo." << endl;
    }

    return 0;
}
