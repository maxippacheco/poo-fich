// Escriba una función genérica eliminaElementosArchivo() que reciba como argumentos el nombre de
// un archivo binario, y un vector de enteros llamado posiciones. La función debe ser genérica, es decir:
// poder utilizarse con cualquier archivo binario que contenga un conjunto de datos de un mismo tipo, y
// tiene por objetivo modificar el archivo, conservando en él solo los valores que se encuentren en las
// posiciones almacenadas en el vector posiciones.

#include<iostream>
#include<vector>
#include<fstream>
#include<algorithm>

using namespace std;

template<typename T>
void eliminaElementosArchivo(string nombreArchivo, vector<int> posiciones){
	fstream archivo(nombreArchivo, ios::binary|ios::in|ios::out);
	fstream archivo_salida("temp.bin", ios::binary|ios::in|ios::out);

	int pos_actual = 0;
	T element;
	while (archivo.read(reinterpret_cast<char*>(&element), sizeof(element)))
	{
		if(find(posiciones.begin(), posiciones.end(), pos_actual)){
			archivo_salida.write(reinterpret_cast<char*>(&element), sizeof(element));
		}

		pos_actual++;
	}

	archivo.close();
	archivo_salida.close();

	remove(nombreArchivo.c_str());
	rename("temp.bin", archivo_salida.c_str());
	
}

int main(int argc, char const *argv[])
{	
	return 0;
}
