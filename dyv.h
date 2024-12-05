#include <ostream>
#include <vector>
using namespace std;

int BusqBin(int val, vector<int>& arr,int ini,int fin){
    if(ini>fin){//el valor no se encuentra dentro del array
        return -1;
    }
    int mid = ini + (fin-ini)/2;
    if (arr[mid] == val){ //ha encontrado el valor
        return mid;
    }
    else if( arr[mid]> val){ //buscar en la mitad de la izq
        return BusqBin(val,arr,ini,mid-1);
    }
    else{ //buscar en la mitad de la der
        return BusqBin(val,arr,mid+1,fin);
    }
}

int partir(vector<int>& arr, int ini, int fin){
    int x = arr[fin]; // Escogemos el último elemento como pivote
    int i = ini - 1;  // i es el índice del elemento más pequeño

    for (int j = ini; j < fin; j++) {
        if (arr[j] <= x) {
            i++; // Incrementamos el índice del elemento más pequeño
            swap(arr[i], arr[j]); // Intercambiamos los elementos
        }
    }
    swap(arr[i + 1], arr[fin]); // Colocamos el pivote en su posición correcta
    return i + 1; // Retornamos la posición del pivote
}

//usamos un void ya que no tiene que devolve ningún valor
void QuickSort( vector<int>& arr, int ini, int fin){
    if(ini < fin){
        int pivot = partir(arr, ini, fin); // Encuentra el pivote
        QuickSort(arr, ini, pivot - 1);   // Ordena la parte izquierda
        QuickSort(arr, pivot + 1, fin);  // Ordena la parte derecha
    }
}


