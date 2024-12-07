#include <iostream>
#include <vector>
#include <limits> // Para representar valores altos como infinito
using namespace std;

const int infinito = numeric_limits<int>::max(); // Valor alto para representar infinito

// Función recursiva para calcular el número mínimo de monedas necesarias
int cambioRecursivo(const vector<int>& monedas, int cantidad, int monedaActual, vector<vector<int>>& memo) {
    // Caso base 1: Si la cantidad es 0, no necesitamos monedas
    if (cantidad == 0) {
        return 0;
    }

    // Caso base 2: Si la cantidad es negativa o no quedan monedas, devolvemos infinito
    if (cantidad < 0 || monedaActual < 0) {
        return infinito;
    }

    // Caso base 3: Si ya calculamos esta solución, devolvemos el valor guardado
    if (memo[cantidad][monedaActual] != -1) {
        return memo[cantidad][monedaActual];
    }

    // Caso recursivo: Calcular el mínimo entre no usar la moneda actual o usarla
    // Opción 1: No usar la moneda actual
    int sinUsar = cambioRecursivo(monedas, cantidad, monedaActual - 1, memo);

    // Opción 2: Usar la moneda actual si es posible
    int usando;
    if (cantidad >= monedas[monedaActual]) {
        // Si la moneda actual cabe en la cantidad, calculamos usando esta moneda
        usando = cambioRecursivo(monedas, cantidad - monedas[monedaActual], monedaActual, memo) + 1;
    } else {
        // Si no cabe, el resultado es infinito (no se puede usar esta moneda)
        usando = infinito;
    }
    // Guardar el resultado en la tabla de memorización
    memo[cantidad][monedaActual] = min(sinUsar, usando);

    return memo[cantidad][monedaActual];
}

int main() {
    // Vector de monedas y cantidad a devolver
    vector<int> monedas = {1, 4, 6};
    int cantidad = 9;

    // Crear una tabla de memorización inicializada en -1
    vector<vector<int>> memo(cantidad + 1, vector<int>(monedas.size(), -1));

    // Calcular el número mínimo de monedas necesarias
    int resultado = cambioRecursivo(monedas, cantidad, monedas.size() - 1, memo);

    if (resultado == infinito) {
        cout << "No es posible devolver la cantidad con las monedas dadas" << endl;
    } else {
        cout << "El número mínimo de monedas necesarias es: " << resultado << endl;
    }

    return 0;
}
