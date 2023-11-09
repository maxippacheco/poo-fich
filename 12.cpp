// Ejercicio 1 (30 pts) Escriba una función genérica eliminaObjetos() que reciba como
// argumentos un objeto llamado nombre de tipo string y un arreglo de la clase vector
// (STL) llamado posiciones con enteros. La cadena nombre contiene el nombre de un
// archivo binario que almacena datos del tipo genérico. La función deberá modificar el
// archivo de manera que únicamente queden en el mismo los valores que se encuentren
// en las posiciones indicadas por el vector posiciones
#include<iostream>
#include<vector>
#include<fstream>
using namespace std;

template<typename T>
void eliminaObjetos(string nombre, vector<int> &posiciones){
	fstream archivo(nombre, ios::binary|ios::in|ios::out);

	T element;
	vector<T>vector_archivo;
	while (archivo.read(reinterpret_cast<char*>(&element), sizeof(element)))
	{
		vector_archivo.push_back(element);
	}

	archivo.close();

	vector<T> posiciones_indicadas;
	for (int i : posiciones) {
		if (i >= 0 && static_cast<size_t>(i) < vector_archivo.size()) {
			posiciones_indicadas.push_back(vector_archivo[i]);
		}
	}

	fstream archivo_salida(nombre, ios::binary|ios::out);

	for(T element: posiciones_indicadas)
	{
		archivo_salida.write(reinterpret_cast<char*>(&element), sizeof(element));
	}
	
	archivo_salida.close();
		

}

int main()
{
	
	return 0;
}
