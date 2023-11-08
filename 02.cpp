// Ejercicio 2 (25 pts) Escriba una función genérica para buscar y reemplazar un dato dentro de
// un archivo binario. La función debe recibir el nombre del archivo y dos datos (A y B) del tipo
// genérico. Suponiendo que el archivo contiene elementos de dicho tipo, buscar todas las
// ocurrencias de A, y reemplazarlas por B. No utilice arreglos, vectores ni otros contenedores
// auxiliares (trabaje directamente sobre el archivo)

#include<iostream>
#include<fstream>
using namespace std;


template<typename T>
T buscar_y_reemplazar(string file_name, T &valueA, T &valueB){
	fstream archivo(file_name, ios::in, ios::out, ios::binary);

	T dato_leido;
	streampos posicion_inicial = archivo.tellg();

	while (archivo.read(reinterpret_cast<char*>(&dato_leido), sizeof(dato_leido)))
	{
		if( dato_leido == valueA )
		{
			archivo.seekp(archivo.tellg() sizeof(dato_leido));
			archivo.write(reinterpret_cast<char*>(&dato_leido), sizeof(dato_leido));
		}
	}
	
	archivo.close();
}

int main(){

	string nombre_archivo = "usuarios.bin";	
  int datoA = 42;
  int datoB = 99;

  buscar_y_reemplazar(nombre_archivo, datoA, datoB);

	return 0;
}