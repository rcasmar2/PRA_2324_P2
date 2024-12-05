#include <iostream>
#include <vector>
#include "dyv.h"
using namespace std;

int main() {
    vector<int> arrInt = {10, 7, 8, 9, 1, 5};
    vector<char> arrChar = {'d', 'a', 'c', 'b', 'e'};
    vector<float> arrFloat = {1.5, 3.2, 0.9, 4.8, 2.1};

    int x = 5;
    char y = 'b';
    float z = 3.2;

    // Ordenar y buscar en vector de enteros
    cout << "Array original (int): ";
    for (int val : arrInt)
        cout << val << " ";
    cout << endl;

    QuickSort(arrInt, 0, arrInt.size() - 1);

    cout << "Array ordenado (int): ";
    for (int val : arrInt)
        cout << val << " ";
    cout << endl;

    cout << "Posición de x en array ordenado: " << BusqBin(x, arrInt, 0, arrInt.size() - 1) << endl;

    // Ordenar y buscar en vector de caracteres
    cout << "\nArray original (char): ";
    for (char val : arrChar)
        cout << val << " ";
    cout << endl;

    QuickSort(arrChar, 0, arrChar.size() - 1);

    cout << "Array ordenado (char): ";
    for (char val : arrChar)
        cout << val << " ";
    cout << endl;

    cout << "Posición de y en array ordenado: " << BusqBin(y, arrChar, 0, arrChar.size() - 1) << endl;

    // Ordenar y buscar en vector de floats
    cout << "\nArray original (float): ";
    for (float val : arrFloat)
        cout << val << " ";
    cout << endl;

    QuickSort(arrFloat, 0, arrFloat.size() - 1);

    cout << "Array ordenado (float): ";
    for (float val : arrFloat)
        cout << val << " ";
    cout << endl;

    cout << "Posición de z en array ordenado: " << BusqBin(z, arrFloat, 0, arrFloat.size() - 1) << endl;

    return 0;
}
