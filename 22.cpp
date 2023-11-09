// Proponga una función genérica invierte(...) que recibe como parámetro un string correspondiente al
// nombre de un archivo binario. Dicha función, debe invertir el contenido del archivo, es decir que el
// primer dato se intercambie con el último, el 2do con el ante-último, etc. Además codifique un programa
// cliente para invocar dicha función suponiendo que hay tres archivos con datos de tipo int , float y
// struct par {int x,int y} .
// Nota: no debe usar ningún arreglo, contenedor o archivo auxiliar.
#include<iostream>
#include<fstream>
using namespace std;

template<typename T>
void invierte(string nombre_archivo){
	fstream archivo(nombre_archivo, ios::binary|ios::in|ios::out);

	// me paro al final y saco el size
	archivo.seekg(0, ios::end);
	size_t tamanio_archivo = archivo.tellg()/sizeof(T);

	// creo un arreglo dinamico con el file size
	T* datos = new T[tamanio_archivo];

	archivo.read(reinterpret_cast<char*>(&datos), tamanio_archivo);
	archivo.close();

	fstream archivo_salida(nombre_archivo, ios::binary|ios::in|ios::out);
	
	for (size_t i = tamanio_archivo; i > 0; i--)
	{
		archivo_salida.write(reinterpret_cast<char*>(&datos[i - 1]), sizeof(T));
	}

	archivo_salida.close();
	

}


int main(int argc, char const *argv[])
{
	
	return 0;
}
