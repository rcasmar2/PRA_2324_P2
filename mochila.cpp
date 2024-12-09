#include <algorithm>	
#include <vector>
#include <iostream>
using namespace std;


// Los vectores p[i] y b[i] están indexados de 0 a n-1 y el índice i comienza en num_elementos = 3, lo cual genera accesos fuera de rango
// Usar p[i-1] y b[i-1] para no ignonar el primer elemento, que es el del índice 0 del vector (recordar que los vectores van de 0,1,2,..., num_elementos-1)
// Así conseguimos alinear los índices de los vectores (0,1,...,num_elementos-1) con las filas de la matriz(1,2,...,num_elementos)
// Si no hicieramos esto, se comería el primer elemento y en vez de devolvernos 78 nos devolvería 64
int mochila(int i, int j, const std::vector<int>& p, const std::vector<int>& b, int** F){
		
	// Casos base
	if(i == 0 || j == 0)
		return 0;
	
	// Si no hemos visitado esa solución, la visitamos y devolvemos su valor
	if(F[i][j] != -1)
		return F[i][j];

	// Casos recursivos
	// Si el elemento i no cabe, devolvemos la función pero sin ese elemento i
	if(j - p[i-1] < 0){
		F[i][j] = mochila(i-1, j, p, b, F);
	}
	// Sino, buscamos el máximo beneficio entre descartar el objeto o meterlo en la mochila
	else{
		F[i][j] = max(mochila(i-1, j, p, b, F), b[i-1] + mochila(i-1, j-p[i-1], p, b, F));
	}
	// Devolvemos el máximo benedicio situado en la matriz (sería la esquina inferior derecha de la misma)
	return F[i][j];
}

int main(){

	int capacidad = 15;
	int num_elementos = 3;
	std::vector<int> p = {9, 6, 5};
	std::vector<int> b = {38, 40, 24};

	// Matriz de mi función de memoria que sea (capacidad+1) x (num_elementos+1)
	// Mi matriz tiene i filas que van de 0 a num_elementos y j columnas que van de 0 a capacidad
	// Si al compilar da algún problema, cambiar el orden de filas y columnas de la matriz y au
	int** M = new int*[num_elementos+1];
	for(int i = 0; i <= num_elementos; i++){
		M[i] = new int[capacidad+1];
		fill(M[i], M[i] + capacidad+1, -1);
	}
	
	// Llamada a la función e impresión por pantalla de su valor de retorno
	int resultado = mochila(num_elementos, capacidad, p, b, M);

	cout << "El beneficio máximo total que obtendríamos sin sobrepasar la capacidad de la mochila sería de: " << resultado << endl;

	// Liberamos la memoria ocupada por la matriz. Si da problemas, cambiar el orden también aquí de filas y columnas
	// Columnas
	for(int i = 0; i <= num_elementos; i++){
		delete[] M[i];
	}
	
	// Filas
	delete[] M;

	return 0;
}