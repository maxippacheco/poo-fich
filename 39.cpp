// Ejercicio 2 (25 pts) Escriba una función llamada max_element(...) que reciba dos punteros a de tipo
// float, uno indicando el comienzo de un arreglo (dirección del 1er elemento), y otro indicando el final
// (dirección siguiente del último elemento), y retorne un puntero indicando la posición del mayor elemento
// del arreglo. Implemente un programa cliente que genere un arreglo de 10 elementos y muestre a qué
// índice (0...9) corresponde el mayor

#include<iostream>
using namespace std;

float *max_element(float *inicio, float *fin){

	float *mayor = inicio;
	for (float *i = inicio; i < fin; i++)
	{
		if( *i > *mayor ){
			mayor = i;
		}
	}

	return mayor;
	
}

int main(){

  float arr[] = {1.0f, 2.0f, 3.0f, 4.0f, 5.0f, 6.0f};
  float* inicio = arr;
  float* fin = arr + 6; // Utiliza 6, no 6.0f, ya que es el número de elementos

  float* element = max_element(inicio, fin);

  cout << "El elemento mayor: " << *element << " fue encontrado en la posicion " << element - inicio << endl;

	cout << "El elemento mayor: " << *element << " fue encontrado en la posicion " << element << endl; 

	return 0;
}