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
