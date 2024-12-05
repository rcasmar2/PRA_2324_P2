#include <iostream>
#include <vector>
#include "dyv.h"
using namespace std;

int main() {
    vector<int> arr = {10, 7, 8, 9, 1, 5};
    int n = arr.size();
    int x = 5;

    cout << "Array original: "; // Mostrar el array original
        for (int val : arr)
            cout << val << " ";
        cout << endl;

        QuickSort(arr, 0, n - 1); // Ordenar el array

        cout << "Array ordenado: "; // Mostrar el array ordenado
        for (int val : arr)
            cout << val << " ";
        cout << endl;

    int resultado = BusqBin(x, arr, 0, n - 1); // Buscar el elemento en el array ordenado



    if (resultado != -1)
        cout << "Elemento encontrado en el vector despues de ordenarlo en posición: " << resultado << endl;
    else
        cout << "Elemento no encontrado" << endl;

    return 0;
}