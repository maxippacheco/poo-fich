// Programe una clase templatizada llamada VectorDinamico (similar a la de la guía
// 2). La clase debe poseer:
// a. Un constructor que reciba el tamaño inicial del vector, y reserve la memoria
// necesaria.
// b. Un destructor que se encargue de liberar la memoria reservada.
// c. Una sobrecarga del operador[] que reciba el número de elemento, devuelva
// su valor, y permita modificarlo.
// d. Modifique o sobrecargue el constructor para que permita generar valores
// aleatorios con los cuales inicializar las posiciones del arreglo que reserva.
// e. Utilice la clase desde un programa cliente creando vectores aleatorios con
// diversos tipos de datos (int,double,string, etc).
#include<iostream>

using namespace std;

template<typename T>
class VectorDinamico
{
	T* array;
	size_t inicial_size;

	public:
		VectorDinamico(size_t initial_size): inicial_size(initial_size){
			array = new T[initial_size];
		}
		~VectorDinamico(){
			delete [] array;
		}

		T& operator[](size_t index){
			if( index < size ){
				return array[index];
			}else{
				throw out_of_range("Indice fuera de rango");
			}
		}

		VectorDinamico(size_t initial_size, bool randomize): inicial_size(inicial_size){
			array = new T[inicial_size];
			if(randomize){
        srand(static_cast<unsigned>(time(nullptr)));
        for (size_t i = 0; i < initial_size; i++) {
          array[i] = static_cast<T>(rand());  // Genera valores aleatorios
        }

			}
		}

		int getSize(){
			return this->inicial_size();
		}
};

int main()
{
	VectorDinamico<int> intVector(5, true);
	VectorDinamico<double> doubleVector(3, true);
	VectorDinamico<string> stringVector(4, false);

	cout << "Vector de enteros aleatorios:" << endl;
	for (size_t i = 0; i < intVector.getSize(); i++) {
			cout << intVector[i] << " ";
	}
	cout << endl;

	cout << "Vector de números de punto flotante aleatorios:" << endl;
	for (size_t i = 0; i < doubleVector.getSize(); i++) {
			cout << doubleVector[i] << " ";
	}
	cout << endl;

	cout << "Vector de cadenas (sin inicialización aleatoria):" << endl;
	for (size_t i = 0; i < stringVector.getSize(); i++) {
			cout << stringVector[i] << " ";
	}
	cout << endl;
	return 0;
}
