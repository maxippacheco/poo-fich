// Escriba un programa que cargue en un vector de strings una lista de palabras
// desde un archivo de texto (que contendrá una palabra por línea), muestre en
// pantalla la cantidad de palabras leídas, las ordene en el vector alfabéticamente, y
// reescriba el archivo original con la lista ordenada.
// Ayuda: para ordenar un vector v de principio a fin puede utilizar la sentencia
// “sort(v.begin(),v.end());”.
#include<iostream>
#include<fstream>
#include <algorithm>
#include<vector>
using namespace std;

int main(){

	ifstream archivo("palabras.txt");

	if(!archivo.is_open()){
		cout << "Error al abrir el archivo" << endl;
		return 1;
	}

	vector<string> palabras;
	string palabra;

	// Leer palabras del archivo y almacenarlas en un vector
	while (getline(archivo, palabra))
	{
		palabras.push_back(palabra);
	}
	
	archivo.close();

	// Mostrar la cantidad de palabras leídas
	cout << "Cantidad de palabras leídas: " << palabras.size() << endl;

	// ordenar el vector alfabeticamente
	sort(palabras.begin(), palabras.end());

	// Reescribir el archivo original con la lista ordenada
	ofstream archivo_salida("palabras.txt");

	if(!archivo_salida.is_open()){
		cout << "Error al abrir el archivo" << endl;
		return 1;
	}

	for(string& palabra: palabras) archivo_salida << palabra << endl;

	archivo_salida.close();

	cout << "La lista de palabras ha sido ordenada y el archivo ha sido actualizado." << endl;


	return 0;
}