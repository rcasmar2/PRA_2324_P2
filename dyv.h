#ifndef DYV_H
#define DYV_H

#include <iostream>
#include <ostream>
#include <vector>
#include <algorithm> 
#include <chrono>
using namespace std;

// Búsqueda binaria recursiva
template <typename T>
int BusqBin(const T& val, vector<T>& arr, int ini, int fin) {
    if (ini > fin) { // El valor no se encuentra dentro del array
        return -1;
    }
    int mid = ini + (fin - ini) / 2;
    if (arr[mid] == val) { // Ha encontrado el valor
        return mid;
    } else if (arr[mid] > val) { // Buscar en la mitad izquierda
        return BusqBin(val, arr, ini, mid - 1);
    } else { // Buscar en la mitad derecha
        return BusqBin(val, arr, mid + 1, fin);
    }
}

// Función para particionar el array y encontrar el pivote
template <typename T>
int partir(vector<T>& arr, int ini, int fin) {
    T x = arr[fin]; // Último elemento como pivote
    int i = ini - 1;  // Índice del elemento más pequeño

    for (int j = ini; j < fin; j++) {
        if (arr[j] <= x) {
            i++;
            swap(arr[i], arr[j]); // Intercambiamos los elementos
        }
    }
    swap(arr[i + 1], arr[fin]); // Colocamos el pivote en su posición correcta
    return i + 1; // Retornamos la posición del pivote
}

// Implementación de QuickSort
template <typename T>
void QuickSort(vector<T>& arr, int ini, int fin) {
    if (ini < fin) {
        int pivot = partir(arr, ini, fin); // Encuentra el pivote
        QuickSort(arr, ini, pivot - 1);   // Ordena la parte izquierda
        QuickSort(arr, pivot + 1, fin);  // Ordena la parte derecha
    }
}

template <typename T>
void medirTiempoQuickSort(vector<T> arr, const string& nombre) {
    auto start = chrono::high_resolution_clock::now(); // Tiempo inicial

    QuickSort(arr, 0, arr.size() - 1); // Ejecuta QuickSort

    auto end = chrono::high_resolution_clock::now(); // Tiempo final
    chrono::duration<float, std::milli> duration = end - start;

    // Muestra el tiempo de ejecución
    cout << "Tiempo de ejecución (" << nombre << "): " << duration.count() << " ms" << endl;
}

#endif
