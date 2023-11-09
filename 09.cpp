// Ejercicio 3) Mediante un programa C++: a) defina un vector (STL) de strings,
// incorporando sus datos desde un archivo de textos LISTASTR.TXT.; b) elimine los
// strings repetidos; c) si un string tiene 2 o más blancos debe eliminar el 2do blanco y la
// subcadena que se encuentra entre el primer blanco y el segundo; d) ordene
// alfabéticamente la lista, pero a partir del 3er elemento; e) reescriba el archivo
// LISTASTR.TXT con la lista modificada.
#include<iostream>
#include<algorithm>
#include<list>
#include<fstream>
using namespace std;

int main(){

	ifstream archivo("listastr.txt");

	list<string> lista;

	string linea;
	while (getline(archivo, linea))
	{
		lista.push_back(linea);
	}
	
	lista.sort();
	lista.unique();


	for (string &str: lista)
	{
		size_t primer_espacio = str.find(" ");

		// si no es una posicion invalida
		if( primer_espacio != string::npos)
		{
			// que arranque despues del primer espacio
			size_t segundo_espacio = str.find(" ", primer_espacio + 1);

			if(segundo_espacio != string::npos)
			{
				str.erase(primer_espacio + 1, segundo_espacio - primer_espacio);
			}
		}
	}

	if( distance( lista.begin(), lista.end() ) > 2){
		auto list_it = lista.begin();
		// avanza dos posiciones
		advance(list_it, 2);
		sort(list_it, lista.end());
	}

	// escribir el archivo
	ofstream archivo_salida("listastr.txt");

	if(!archivo_salida.is_open()){
		cout << "No se pudo abrir el archivo";
		return 1;
	}

	for(string &str: lista){
		archivo_salida << str << "\n";
	}
	

	return 0;
}