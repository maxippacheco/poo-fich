// Ejercicio 1 (20 pts) Escriba una función genérica intercambia que reciba como
// argumentos un string nombre y dos enteros pos1 y pos2. Asumiendo que el string
// nombre contiene el nombre de un archivo binario que guarda un arreglo de datos de
// un mismo tipo, la función debe modificar el archivo intercambiando los datos que este
// guarda en las posiciones (en base 0) pos1 y pos2. Por ejemplo: si el archivo
// “ejemplo.dat” guarda enteros, la llamada intercambia<int>(“ejemplo.dat”,3,4) debe
// intercambiar el cuarto con el quinto entero del archivo.

#include<iostream>
#include<fstream>
using namespace std;

template<typename T>
void intercambiar_str(string nombre, int pos1, int pos2){
	fstream archivo(nombre, ios::binary|ios::out|ios::in);

  // Calcular el tamaño de un elemento del arreglo (tipo T)
	size_t tamanio_elemento = sizeof(T);

  // Mover el puntero de lectura/escritura a las posiciones pos1 y pos2
	archivo.seekg(pos1 * tamanio_elemento);
	archivo.seekp(pos2 * tamanio_elemento);

	// Leer los datos en pos1 y pos2
	T dato1, dato2;
	archivo.read(reinterpret_cast<char*>(&dato1), tamano_elemento);
	archivo.read(reinterpret_cast<char*>(&dato2), tamano_elemento);

  // Mover el puntero de escritura nuevamente a las posiciones pos1 y pos2
	archivo.seekg(pos1 * tamanio_elemento);
	archivo.seekp(pos2 * tamanio_elemento);

  // Escribir los datos intercambiados
	archivo.write(reinterpret_cast<char*>(&dato2), tamanio_elemento);
	archivo.write(reinterpret_cast<char*>(&dato1), tamanio_elemento);

	archivo.close();
}

int main()
{
	
	return 0;
}
