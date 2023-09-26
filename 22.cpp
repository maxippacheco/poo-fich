// Ejercicio 1 (pts) Implemente una clase Complejo para representar un número complejo. La clase debe
// tener: 
//  a) un constructor que no reciba nada y la inicialice como 0+0i, 
//  b) un constructor que reciba las partes real e imaginaria, 
//  c) métodos para consultar cada parte, 
//  d) sobrecargas para los operadores + y -, 
//  e) sobrecargas para los operadores == y !=, y 
//  f) una sobrecarga para poder mostrar una instancia “c” de la clase mediate “cout << c”.

#include<iostream>
using namespace std;

class Complejo{
	int real, compleja;
	public:
		Complejo(){
			this->real = 0;
			this->compleja = 0;
		};
		Complejo(int real, int compleja): real(real), compleja(compleja){};

		int ShowRealPart() const{
			return this->real;
		}

		int ShowComplexPart() const {
			return this->compleja;
		}

		Complejo operator+( const Complejo& comp){
			return Complejo(this->real + comp.real, this->compleja + comp.compleja);
		}

		Complejo operator-( const Complejo& comp){
			return Complejo(this->real - comp.real, this->compleja - comp.compleja);
		}

		bool operator==( const Complejo& comp ){
			if( this->compleja == comp.compleja && this->real == comp.real ){
				return true;
			}

			return false;
		}

		bool operator!=( const Complejo& comp ){
			if( this->compleja != comp.compleja && this->real != comp.real ){
				return true;
			}

			return false;
		}
};


ostream& operator<<( ostream& os, const Complejo& comp){
	os << "El numero es: " << comp.ShowRealPart() << " + " << comp.ShowComplexPart() << "i." << endl;
	return os;
}


int main(){

	Complejo comp(1,2);

	cout << comp;

	return 0;
}