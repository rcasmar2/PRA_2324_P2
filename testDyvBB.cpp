#include <iostream>
#include <vector>
#include "dyv.h"
using namespace std;

int main() {
    vector<int> arr = {1, 3, 5, 7, 9, 11};
    int x = 5;

    int resultado = BusqBin(x, arr, 0, arr.size() - 1);

    if (resultado != -1)
        cout << "Elemento encontrado en el índice: " << resultado << endl;
    else
        cout << "Elemento no encontrado" << endl;

    return 0;
}