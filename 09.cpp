// Se tiene un archivo “inscriptos.txt” con una lista de nombres de alumnos inscriptos
// al cursado de Fundamentos de Programación. Se desea distribuir los estudiantes
// en comisiones de práctica de no más de 30 alumnos. Escriba un programa que
// determine cuantas comisiones deberían formarse de acuerdo a la cantidad de
// inscriptos y reparta los alumnos en comisiones de igual tamaño, guardando la lista
// de alumnos de cada comisión en archivo de texto “comision1.txt”, “comision2.txt”, …
// “comisionN.txt”.
// Ayuda: puede utilizar la clase stringstream como auxiliar para concatenar en un
// string texto y números para formar los nombres de los archivos.

#include<iostream>
#include<fstream>
#include<sstream>
#include<vector>

using namespace std;

int main(){
	ifstream archivo("inscriptos.txt");

	if(!archivo.is_open()){
		cout << "El archivo no se pudo abrir" << endl;
		return 1;
	}

	vector<string> alumnos;
	string nombre;

	// leemos los inscriptos
	while (getline(archivo, nombre))
	{
		alumnos.push_back(nombre);
	}
	archivo.close();

	int cantidad_alumnos = alumnos.size();
	int alumnos_por_comision = 30;
	int cantidad_comisiones = (cantidad_alumnos + alumnos_por_comision) / alumnos_por_comision;

	for (size_t i = 0; i < cantidad_comisiones; i++)
	{
		stringstream nombre_archivo_comision;
		nombre_archivo_comision << "comision" << (i + 1) << ".txt";

		ofstream archivo_salida(nombre_archivo_comision.str());

		int inicio = i * alumnos_por_comision;
		int fin = (i + 1) * alumnos_por_comision;

		for (size_t j = inicio; j < fin; j++)
		{
			archivo_salida << alumnos[j] << endl;
		}

		archivo_salida.close();
	}
	



	

	return 0;
}