// Ejercicio 1 (25pts) Un archivo de texto “medallas.txt” contiene una línea por cada país
// que participa en los juegos olímpicos. Cada línea incluye, separados por espacios
// primero 3 valores enteros y luego el nombre completo del país. Los tres enteros se
// corresponden con las cantidades de medallas de oro, plata y bronce respectivamente
// que ha obtenido hasta el momento dicho país. Cada vez que una competencia finaliza,
// el archivo debe actualizarse. Escriba una función que reciba los nombre de los países
// que representan los tres ganadores de medallas de una competencia y actualice el
// archivo.
#include<iostream>
#include<string>
#include<fstream>
using namespace std;

struct Pais{
	int oro, plata, bronce;
	string nombre;
};


void actualizar_medallas(string nombre_archivo, Pais oro, Pais plata, Pais bronce){
	fstream archivo(nombre_archivo);

	string linea;
	string archivo_completo;
	while (getline(archivo, linea))
	{
		archivo_completo += linea + "\n";
	}
	
	archivo.close();

	size_t pos_oro = archivo_completo.find(oro.nombre);
	size_t pos_plata = archivo_completo.find(plata.nombre);
	size_t pos_bronce = archivo_completo.find(bronce.nombre);

	archivo_completo.replace(pos_oro, oro.nombre.length(), to_string(oro.oro));
	archivo_completo.replace(pos_plata, plata.nombre.length(), to_string(plata.plata));
	archivo_completo.replace(pos_bronce, bronce.nombre.length(), to_string(bronce.bronce));

	// reescribir archivo
	fstream archivo_salida(nombre_archivo, ios::trunc);

	archivo_salida << archivo_completo;
	archivo_salida.close();

}

int main(){

	Pais ganadorOro = {10, 5, 3, "PaísOro"};
  Pais ganadorPlata = {6, 8, 2, "PaísPlata"};
  Pais ganadorBronce = {3, 4, 9, "PaísBronce"};

  actualizar_medallas("medallas.txt", ganadorOro, ganadorPlata, ganadorBronce);


	return 0;
}