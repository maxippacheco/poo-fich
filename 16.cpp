// Ejercicio 3 (25 pts) En un programa C++ se definen las 2 instancias que siguen:
// OperaVector <int> x; OperaVector <string> s. Escriba la clase llamada OperaVector
// que posea como atributo un vector dinámico (STL vector) y su longitud. La clase debe
// poseer los siguientes métodos para: a) construir el vector; b) incorporar datos al
// vector desde un archivo binario; c) buscar y eliminar un elemento del vector (dato a
// eliminar como parámetro), d) ordenar el vector en forma creciente a partir de la
// posición (entero) de un elemento que se pasa como parámetro, e) informar los
// elementos del vector dentro de un rango (parámetros: 2 enteros que definen el rango).

#include<iostream>
#include<vector>
#include<fstream>
using namespace std;

template<typename T>
class OperaVector{
	int n;
	vector<T> arreglo;
	public:
		OperaVector(int n): n(n){
		}

		void construirVector(){
			arreglo.resize(n);
		}

		void toBinaryFile(string nombre_archivo){
			fstream archivo(nombre_archivo, ios::binary|ios::in|ios::out);

			archivo.read(reinterpret_cast<char*>(&vectorDinamico[0]), n * sizeof(T));
			
		}

		void eliminarDelArreglo(T datoEliminar){
			auto it = find(arreglo.begin(), arreglo.end(), datoEliminar);
			arreglo.erase(it);
		}

		void ordenarDesdePosicion(int posicion){
			sort(arreglo.begin() + posicion, arreglo.end());
		}

		void informarRango(int inicio, int fin){
			for (size_t i = inicio; i < fin; i++)
			{
				cout << arreglo[i] << endl;
			}
			
		}
};

int main(int argc, char const *argv[])
{
    OperaVector<int> x(10);
    x.construirVector();  // Crear un vector de longitud 10

    // Eliminar un elemento del vector
    x.eliminarDelArreglo(5);  // Eliminar el elemento 5

    // Ordenar el vector desde una posición
    x.ordenarDesdePosicion(2);  // Ordenar desde la posición 2

    // Informar elementos en un rango
    x.informarRango(0, 7);  // Informar elementos en el rango [0, 7]


	return 0;
}
