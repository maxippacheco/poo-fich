// Ejercicio 3 (25pts) Escriba una función que reciba el nombre de un archivo binario
// que contenga un conjunto de registros de un tipo genérico, y elimine del archivo todos
// los registros repetidos. La función debe retornar la cantidad de elementos eliminados.
// Nota: la función podría alterar el orden de los registros si lo considera conveniente
// para su implementación.#include<iostream>
#include<iostream>
#include<fstream>
#include<list>
using namespace std;

template<typename T>
list<T> eliminar_repetidos( string filename ){
	fstream archivo(filename, ios::binary|ios::in|ios::out);

	if(!archivo.is_open()){
		cout << "No se pudo abrir el archivo" << endl;
		return 1;
	}

	list<T> registros;
	T registro;
	while (archivo.read(reinterpret_cast<char*>(&registro), sizeof(registro)))
	{
		registros.push_back(registro);
	}
	archivo.close();

	registros.sort();
	registros.unique();
	int registros_unicos = registros.size();

	fstream archivo_salida( filename, ios::binary|ios::in|ios::out);
	
	if(!archivo_salida.is_open()){
		cout << "No se pudo abrir el archivo" << endl;
		return 1;
	}

	for (T &registro: registros)
	{
		archivo_salida.write(reinterpret_cast<char*>(&registro), sizeof(registro));
	}

	archivo_salida.close();
	
	
	return registros_unicos - registros.size();
}

int main(){

	return 0;
}