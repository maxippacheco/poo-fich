// Ejercicio 2 (25 pts) Escriba una función que reciba un puntero indicando el comienzo de un arreglo de
// enteros, un entero indicando la cantidad de elementos en el arreglo, y un tercer parámetro con un valor
// entero adicional x. La función debe buscar dicho elemento (x) dentro del arreglo y retornar un puntero al
// mismo (si aparece varias veces, a una cualquiera de ellas). Si el valor no está en el arreglo debe
// retornar el puntero nulo. Escriba un programa cliente para probar la función que, en caso de encontrar al
// elemento informe además en qué posición (índice) del arreglo se encontró.

#include<iostream>
using namespace std;

int *buscar_elemento(int *inicio, int *fin, int x){
	for (int *i = inicio; i < fin ;i++)
	{
		if( *i == x){
			return i;
			break;
		}
	}
	

	return nullptr;
}

int main(){

	int arr[] = { 0, 1, 2, 3, 4 };


	int *element = buscar_elemento(arr, arr + 5, 2);

	cout << 	element << endl;

	return 0;
}