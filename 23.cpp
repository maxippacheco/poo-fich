// Ejercicio 2 (25 pts) Escriba una función find_if_even(...) que reciba dos punteros a int, uno indicando el
// comienzo de un arreglo (dirección del 1er elemento), y otro indicando el final (dirección siguiente del
// último elemento), y retorne un puntero indicando la posición del primer número par que encuentre. Si no
// encuentra ninguno debe retornar null. Implemente un programa cliente que genere un arreglo de 10
// elementos y muestre a qué índice (0...9) corresponde el encontrado (o algún mensaje alusivo si no
// encuentra ninguno).

#include<iostream>
#include<vector>
using namespace std;

int* find_if_even(int *begin, int *end){
	if(begin == end){
		return nullptr;
	}

	int *nro_par = nullptr;
	for (int *current = begin; current != end; *current++)
	{
		if(*current % 2 == 0){
			nro_par = current;
			break;
		}
	}
	
	return nro_par;

}

int main(){

	vector<int> numeros = {1, 3, 3, 4, 5, 6, 7, 8};

	int* nro_par = find_if_even(&numeros[0], &numeros[7]);

	if( nro_par == nullptr ){
		cout << "Ningun numero par encontrado." << endl;
	}else{
		cout << "El primer numero par encontrado fue el: " << *nro_par << endl;
	}
	
	return 0;
}