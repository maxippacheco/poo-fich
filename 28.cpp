// a) Escriba una función que reciba dos punteros indicando el comienzo y el final de un arreglo de
// enteros, y un tercer argumento de tipo entero. La función debe retornar verdadero si el valor que
// indica ese tercer parámetro se encuentra dentro del arreglo.
// b) Escriba una función que reciba dos punteros indicando el comienzo y el final de un arreglo de
// enteros, y genere un nuevo arreglo sin elementos repetidos. c) Escriba un programa cliente que
// utilice esta función.
// Nota: para este ejercicio no puede utilizar la clase std::vector (debe gestionar los arreglos con
// new/delete), ni el operador [ ] (debe utilizar solo notación de punteros).

#include<iostream>
using namespace std;

bool isin_array(int *inicio, int *fin, int element){

	while (inicio != fin)
	{
		if( *inicio == element){
			return true;
		}
		inicio++;
	}
	

	return false;
};

int* remove_duplicates(int *inicio, int *fin, int arr_size){	
	int *new_arr = new int[arr_size];

	while (inicio != fin)
	{
		if()

		inicio++;
	}
	
}

int main(){

	return 0; 
}