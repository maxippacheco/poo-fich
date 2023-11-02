// Ejercicio 2 (25 pts) Escriba una función find_if_even(...) que reciba dos punteros a int, uno indicando el
// comienzo de un arreglo (dirección del 1er elemento), y otro indicando el final (dirección siguiente del
// último elemento), y retorne un puntero indicando la posición del primer número par que encuentre. Si no
// encuentra ninguno debe retornar null. Implemente un programa cliente que genere un arreglo de 10
// elementos y muestre a qué índice (0...9) corresponde el encontrado (o algún mensaje alusivo si no
// encuentra ninguno).

#include<iostream>
using namespace std;

int *find_even(int *inicio, int *final){
	for (int *i = inicio; i < final; i++)
	{
		if( *i % 2 == 0) {
			return i;
			break;
		}
	}
	
	return nullptr;
}

int main(){

	int arr[] = {1,2,3,4,5,6};
	int* inicio = arr;
	int* fin = arr + 6;

	int *element = find_even(inicio, fin);

	cout << "El elemento: " << *element << " fue encontrado en la posicion " << element << endl; 

	return 0;
}