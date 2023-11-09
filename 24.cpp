// Escriba una función genérica (template) llamada agregar_bin(..) que reciba como argumentos: un
// objeto llamado nombrearch de tipo string y un arreglo de la clase vector (STL) llamado x . El arreglo x
// está formado por elementos de tipo par , siendo par un struct de 2 miembros llamados valor (tipo
// genérico) y extremo (tipo char ). El string nombrearch corresponde al nombre de un archivo binario.
// La función debe agregar al archivo el dato (miembro valor ) de cada elemento del arreglo x al principio
// o al final del archivo. Los agregados se hacen al principio del archivo si extremo contiene ‘p’ y al final
// del archivo si extremo contiene ‘f’
#include<iostream>
#include<fstream>
#include<vector>
using namespace std;

template<typename T>
struct Par{
	T valor;
	char extremo;
};

template<typename T>
void agregar_bin(string nombre_archivo, vector<Par<T>> x){

}

int main(int argc, char const *argv[])
{
	return 0;
}
