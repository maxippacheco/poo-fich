// Ejercicio 2 (25 pts) Escriba una función que reciba un puntero indicando el comienzo de un arreglo de
// enteros, un entero indicando la cantidad de elementos en el arreglo, y un tercer parámetro con un valor
// entero adicional x. La función debe buscar dicho elemento (x) dentro del arreglo y retornar un puntero al
// mismo (si aparece varias veces, a una cualquiera de ellas). Si el valor no está en el arreglo debe
// retornar el puntero nulo. Escriba un programa cliente para probar la función que, en caso de encontrar al
// elemento informe además en qué posición (índice) del arreglo se encontró.
#include<iostream>
using namespace std;

int* BuscarElemento(int* arreglo, int cantidad, int x) {
  for (int i = 0; i < cantidad; i++) {
    if (arreglo[i] == x) {
      return &arreglo[i]; // Se encontró el elemento, se devuelve un puntero a él
    }
  }
  return nullptr; // El elemento no se encontró en el arreglo, se devuelve un puntero nulo
}


int main(){

	int arreglo[] = {10, 20, 30, 40, 50};
	int cantidad = sizeof(arreglo) / sizeof(arreglo[0]);
	int x = 30;

	int* resultado = BuscarElemento(arreglo, cantidad, x);

	if (resultado != nullptr) {
		cout << "El elemento " << x << " se encontró en la posición " << (resultado - arreglo) << " del arreglo." << endl;
	} else {
		cout << "El elemento " << x << " no se encontró en el arreglo." << endl;
	}


	return 0;
}
