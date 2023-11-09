// Ejercicio 3 (30pts) Un archivo binario guarda datos de usuarios de un sistema. Por
// cada usuario se guarda código (entero), nombre (cadena) y contraseña (cadena). Se
// quiere encontrar contraseñas comunes para sugerirle a esos usuarios que las
// modifiquen. Escriba un programa que: a) lea los datos y genere una lista de todas las
// contraseñas que estén repetidas más de 10 veces (que más de 10 usuarios tengan la
// misma). La lista debe estar ordenada por cantidad de repeticiones (primero las que
// más se repiten); y b) modifique el archivo estableciendo la cadena vacía como
// contraseña para todos los usuarios que tengan alguna de las contraseñas de la lista.
#include<iostream>
#include<list>
#include<fstream>

using namespace std;

int main(){

	fstream archivo("usuarios.bin", ios::binary|ios::in|ios::out);

	int cant_int = archivo.tellg() / sizeof(archivo);
	archivo.seekg(0);

	list<string> L;
	for (size_t i = 0; i < cant_int; i++)
	{
		
	}
	


	return 0;
}