// Ejercicio 2 (30 pts) Escriba una función listaBibliotecas que reciba un string con el
// nombre de un archivo de código fuente (texto). La función debe retornar un
// vector<string> con los nombres de todas las bibliotecas que el fuente incluye. Es decir,
// debe buscar todas las líneas que comiencen con #include y de cada una obtener el
// nombre de la biblioteca, que puede encontrarse entre signos < y > (ej: #include
// <iostream>), o entre comillas (ej: #include “MiClase.h”).

#include<iostream>
#include<fstream>
#include<vector>
using namespace std;

vector<string> listaBibliotecas(string nombre_archivo)
{
	vector<string> lista_bibliotecas;

	fstream archivo(nombre_archivo);

	string linea;
	while (getline(archivo, linea))
	{
		size_t pos = linea.find("#include");
		if(pos != string::npos){
			lista_bibliotecas.push_back(linea);
		}
	}

	archivo.close();

	return lista_bibliotecas;
	

}

int main()
{
	
	return 0;
}
