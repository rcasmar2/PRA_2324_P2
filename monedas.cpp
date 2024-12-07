#include<iostream>
#include<ostream>
#include<vector>
#include<algorithm>
#include <limits> 
using namespace std;

int cambio(const vector<int>& v,int x, int **M){
    //el vector representa los posibles valores de las monedas, la x el valor exacto que estamos buscando y por ende el tamaño de la tabla será de N+1 (del 0 hasta N), M es la matriz donde guardaremos las soluciones.
    // Inicializamos la matriz
    for (int i = 0; i <= x; i++) {
        for (int j = 0; j <= v.size(); j++) {
            if (i == 0) {
                M[i][j] = 0; // Para devolver 0, no necesitamos monedas
            } else if (j == 0) {
                M[i][j] = numeric_limits<int>::max(); // No podemos devolver cantidades sin monedas
            } else {
                // Opción 1: No usar la moneda actual
                int sinUsar = M[i][j - 1];
                // Opción 2: Usar la moneda actual si es posible
                int usando = (i >= v[j - 1] && M[i - v[j - 1]][j] != numeric_limits<int>::max()) 
                             ? M[i - v[j - 1]][j] + 1 
                             : numeric_limits<int>::max();
                // Tomamos el mínimo entre ambas opciones
                M[i][j] = min(sinUsar, usando);
            }
        }
    }

    // El resultado está en la última celda de la matriz
    if ( M[x][v.size()] == numeric_limits<int>::max() ){
        return -1 ; 
    }else{ 
        return M[x][v.size()];
    }
}

int main(){
    // Vector de monedas v y valor a buscar
	vector<int> v = {1, 3, 4};
	int x = 6;

   // Crear la matriz bidimensional
    int** M = new int*[x + 1];
    for (int i = 0; i <= x; i++) {
        M[i] = new int[v.size() + 1];
        fill(M[i], M[i] + v.size() + 1, -1);
    }

    // Calcular el número mínimo de monedas
    int resultado = cambio(v, x, M);

    if (resultado == -1) {
        cout << "No es posible devolver la cantidad " << x << endl;
    } else {
        cout << "El número mínimo de monedas necesarias es: " << resultado << endl;
    }

    // Liberar memoria
    for (int i = 0; i <= x; i++) {
        delete[] M[i];
    }
    delete[] M;

    return 0;
}
