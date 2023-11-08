// Ejercicio 1 (25 pts) Un archivo “discurso.txt” contiene la transcripción de un discurso
// de un político importante. El político en cuestión tiene la mala costumbre de usar
// palabrotas en su discurso. Sus asesores han decidido modificar la transcripción para
// no molestar a los votantes más susceptibles. Para ello han generado un archivo
// “palabrotas.txt”, con la lista de las que usa con más frecuencia. Escriba un programa
// c++ que modifique el archivo del discurso reemplazando todas las palabrotas por
// “***beep***”. No hay palabras cortadas en el texto y puede haber 2 o mas palabrotas
// en una línea..
#include<iostream>
#include<vector>
#include<fstream>
using namespace std;

int main(){

	string palabrota;
	vector<string> palabrotas;
	ifstream palabrotas_file("palabrotas.txt");

	if(!palabrotas_file.is_open())
	{	
		cout << "No se pudo abrir el archivo " << endl;
		return 1;
	}

	while (palabrotas_file >> palabrota)
	{
		palabrotas.push_back(palabrota);
	}

	palabrotas_file.close();

	ifstream discurso("discurso.txt");
	ofstream discurso_modificado("discurso_mod.txt");
	string line;

	while (getline(discurso, line))
	{
			
	}
	

	

	return 0;
}