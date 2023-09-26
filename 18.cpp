// Ejercicio 1 (25 pts) Implemente una clase Fraccion para representar una fracción. La clase debe tener:
// a) un constructor que no reciba nada y la inicialice como 0/1, 
// b) un constructor que reciba numerador y denominador 
// c) métodos para consultar numerador y denominador 
// d) sobrecargas para los operadores + y -, 
// e) sobrecargas para los operadores == y !=, y 
// f) una sobrecarga para poder mostrar una instancia “f” de la clase mediante “cout << f”.
#include<iostream>
using namespace std;

class Fraccion{
	int num, denom;
	public:
		Fraccion(){
			this->num = 0;
			this->denom = 1;
		}
    Fraccion(int _numerador, int _denominador) {
      this->num = _numerador;
      this->denom = _denominador;
    }

		int getNumerador() const{
			return this->num;
		}

		int getDenominador() const{
			return this->denom;
		}

		void setNumerador(int _numerador){
			this->num = _numerador;
		}

		void setDenominador(int _denom){
			this->denom = _denom;
		}

		Fraccion operator+(const Fraccion& fraccion2) const{
			return Fraccion(this->num + fraccion2.num, this->denom + fraccion2.denom);
		}

		Fraccion operator-(const Fraccion& fraccion2) const{
			return Fraccion(this->num - fraccion2.num, this->denom - fraccion2.denom);
		}

		bool operator==(const Fraccion& fraccion2){
			if ((this->num/this->denom) == (fraccion2.num/fraccion2.denom))
			{
				return true;
			}else{
				return false;
			}
		}

		bool operator!=(const Fraccion& fraccion2){
			if ((this->num/this->denom) != (fraccion2.num/fraccion2.denom))
			{
				return true;
			}else{
				return false;
			}
			
		}

};

ostream& operator<<(ostream& os, const Fraccion& fraccion) {
    os << "Numerador: " << fraccion.getNumerador() << " Denominador: " << fraccion.getDenominador();
    return os;
}


int main(){

	Fraccion f1, f2;

	f1.setNumerador(5);
	f1.setDenominador(2);

	f2.setDenominador(3);
	f2.setNumerador(2);

	cout << f1 - f2;

	return 0;
}