// Ejercicio 2 (25 pts) Escriba una función llamada max_element(...) que reciba dos punteros a de tipo
// float, uno indicando el comienzo de un arreglo (dirección del 1er elemento), y otro indicando el final
// (dirección siguiente del último elemento), y retorne un puntero indicando la posición del mayor elemento
// del arreglo. Implemente un programa cliente que genere un arreglo de 10 elementos y muestre a qué
// índice (0...9) corresponde el mayor
#include<iostream>
using namespace std;

float max_element(float *begin, float *end){
	if( begin == end){
		return 0;
	}

	float *max_el = begin;

	for (float *current = begin + 1; current != end; current++)
	{
		if(*current > *max_el ){
			max_el = current;
		}
	}
	
	return *max_el;	

};


int main(){

	// int *p = new int;
	// *p = 10;

	// cout << *p << endl;

  float arreglo[10] = {3.4, 1.2, 9.8, 4.5, 6.7, 2.3, 8.1, 5.5, 7.2, 0.9};

  float max_ptr = max_element(arreglo, arreglo + 10);

	cout << max_ptr << endl;

	return 0;
}

// El bucle for que mencionaste se utiliza para encontrar el elemento máximo en un arreglo de números flotantes. Aquí está una explicación paso a paso de cómo funciona:

// Se inicializa un puntero llamado current apuntando al segundo elemento del arreglo (es decir, begin + 1). Esto se hace para comenzar la comparación desde el segundo elemento del arreglo.

// El bucle for comienza y se ejecuta mientras current no sea igual a end, es decir, mientras current no llegue al final del arreglo.

// En cada iteración del bucle, se compara el valor apuntado por current (*current) con el valor apuntado por max_ptr (*max_ptr). max_ptr es un puntero que rastrea la posición del elemento máximo encontrado hasta ese momento.

// Si el valor apuntado por current es mayor que el valor apuntado por max_ptr, se actualiza max_ptr para que apunte a la posición de current. Esto se hace asignando max_ptr = current.

// El puntero current se incrementa para que apunte al siguiente elemento del arreglo (++current).

// El bucle continúa con la siguiente iteración, repitiendo los pasos 3 a 5.

// Este bucle itera a través del arreglo desde el segundo elemento hasta el último, comparando cada elemento con el valor máximo encontrado hasta ese momento (*max_ptr). Si current apunta a un elemento que es mayor que el elemento máximo actual, se actualiza max_ptr para que apunte al nuevo elemento máximo. Al final del bucle, max_ptr contendrá un puntero que apunta al elemento máximo en el arreglo.




