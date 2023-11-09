// a) Defina una clase genérica para representar un rango. El rango se define mediante 2 valores de un
// mismo tipo genérico: un mínimo y un máximo. La clase debe tener un constructor para asignar los
// valores, un método validar() que retorne false si el mínimo es mayor al máximo; y métodos
// adicionales para consultar ambos valores
// b) Defina una función genérica que reciba un rango y una variable del mismo tipo genérico, y retorne
// true si el valor de esa variable se encuentra dentro del rango (es decir, el valor de la variable es mayor al
// mínimo y menor al máximo del rango).

#include<iostream>
using namespace std;

template<typename T>
class Rango{
	T minimo, maximo;
	public:
		Rango(T minimo, T maximo): minimo(minimo), maximo(maximo){}
		bool Validar(){
			if(this->minimo > this->maximo) return false;
			return true;
		}
		T getMin(){ return this->minimo; };
		T getMax(){ return this->maximo; };

};

template<typename T>
bool isInRango(T &valor, Rango<T> &rango){
	if(valor <= rango.getMax() and valor >= rango.getMin()){
		return true;
	}

	return false;
}

int main()
{
	return 0;
}
