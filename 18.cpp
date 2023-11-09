// a) Considere el struct Legajo { bool borrado; char, ape[64], nom[64]; unsigned int dni,
// antigüedad; float salario;} que se ha utilizado para organizar los datos de los empleados de una
// empresa. La empresa dispone de un archivo binario que contiene una base de datos de registros de tipo
// Legajo generada por un programa C++. Cuando un usuario borra un registro, el programa marca el
// registro como borrado colocando true en el campo borrado, pero no lo quita del archivo. El archivo es
// ahora demasiado extenso. Escriba un programa C++ que abra el archivo y lo limpie eliminando
// definitivamente todos los registros con miembro borrado en true . La función también debe guardar en
// un archivo de texto la lista de dnis eliminados.
// b) Escriba una segunda función que dado un número de dni, retorne true si éste se encuentra en la lista
// de eliminados (en el archivo de texto).

#include<iostream>
#include<fstream>
#include<algorithm>
using namespace std;

struct Legajo { 
	bool borrado; 
	char ape[64], nom[64]; 
	unsigned int dni, antigüedad;
	float salario;
};

void limpiarRegistros(string nombreArchivo){
	fstream archivo(nombreArchivo, ios::binary|ios::in|ios::out);
	if(!archivo)
	{
		cout << "Error al abrir el archivo";
		return;
	}

	fstream archivo_salida("temp.bin", ios::binary|ios::in|ios::out);
	if(!archivo_salida)
	{
		cout << "Error al abrir el archivo";
		return;
	}
	
	fstream archivo_eliminados("eliminados.bin", ios::binary|ios::in|ios::out);
	if(!archivo_eliminados)
	{
		cout << "Error al abrir el archivo";
		return;
	}

	Legajo legajo;
	while (archivo.read(reinterpret_cast<char*>(&legajo), sizeof(legajo)))
	{
		if(!legajo.borrado)
		{
			archivo_salida.write(reinterpret_cast<char*>(&legajo), sizeof(legajo));
		}else{
			archivo_eliminados.write(reinterpret_cast<char*>(&legajo.dni), sizeof(legajo.dni));
		}
	}

	archivo.close();
	archivo_salida.close();
	archivo_eliminados.close();

	remove(nombreArchivo.c_str());
	rename("rename.bin",nombreArchivo.c_str());

}

bool isDniInFile(unsigned int dni, string nombreArchivo)
{
	ifstream archivo(nombreArchivo);

	unsigned int dni_leido;
	while (archivo >> dni)
	{
		if(dni == dni_leido)
		{
			archivo.close();

			return true;
		}
	}

	return false;
	
}

int main(int argc, char const *argv[])
{
	
	return 0;
}
