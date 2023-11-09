// Ejercicio 3 (30pts) Un archivo binario contiene una base de datos de registros de tipo ficha
// como el que se indica en el recuadro generada por un programa C++. Cuando un usuario borra
// un registro desde el programa, marca el registro como borrado colocando true en el campo
// borrado, pero no lo quita del archivo. El archivo es ahora demasiado extenso. Escriba un
// programa C++ que - abra el archivo y lo „limpie‟ eliminando definitivamente todos los registros
// con miembro borrado en true. Además,los datos deben ordenarse en forma decreciente por
// dni quedando así ordenados en el archivo. struct ficha { bool borrado; int dni, char
// nombre[50], float h;}

#include<iostream>
#include<algorithm>
#include<vector>
#include<fstream>
using namespace std;

struct Ficha { 
	bool borrado; 
	int dni;
	char nombre[50];
	float h;
};


int main(){

	fstream archivo("archivo.dat", ios::binary|ios::in|ios::out);
	vector<Ficha> registros;

	if( !archivo.is_open() ){
		cout << "No se pudo abrir";
		return 1;
	}


	// leer los registros y almacenarlos en un vector
	Ficha registro;
	while (archivo.read(reinterpret_cast<char*>(&registro), sizeof(registro)))
	{
		if(!registro.borrado){
			registros.push_back(registro);
		}
	}

	archivo.close();

	// ordenar por dni
	sort(registros.begin(), registros.end(), [](const Ficha &a, const Ficha &b) {
		return a.dni > b.dni;
	});

	// archivo de salida
	fstream output("archivo.dat", ios::binary|ios::in|ios::out|ios::trunc);

	if( !archivo.is_open() ){
		cout << "No se pudo abrir";
		return 1;
	}

	for(Ficha &ficha: registros){
		output.write(reinterpret_cast<char*>(&ficha), sizeof(ficha));
	}

	output.close();


	return 0;
}