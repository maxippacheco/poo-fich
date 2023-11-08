// Ejercicio 1 [25 pts] Escriba una función genérica para cualquier tipo de elemento llamada
// vector_a_lista(...) que reciba un std::vector y retorne una std::list que contenga los elementos del vector
// de entrada, sin repetidos. Debe mantener el orden del vector. Escriba un programa cliente que genere
// un vector con 40 enteros aleatorios, utilice la función para pasarlos a una lista, y muestre la lista en
// pantalla.
#include<algorithm>
#include<iostream>
#include<list>
#include<vector>

using namespace std;

template<typename T>
list<T> vector_a_lista( vector<T> &vector_to_transform){
	list<T> list_from(vector_to_transform.begin(), vector_to_transform.end());

	// delete duplicates
	list_from.sort();
	list_from.unique();

	return list_from;
} 

int main(){

	vector<int> numbers = {1, 3, 3, 4, 5, 6, 6, 7, 9, 2};
	list<int> L = vector_a_lista(numbers);

	for (int element : L) {
		cout << element << " ";
	}
	return 0;
}