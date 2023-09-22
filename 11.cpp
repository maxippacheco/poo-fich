// a) Diseñe una clase para representar un rectángulo con sus atributos base y altura, un constructor que
// inicialice ambos, y un método para obtener su área. Agregue sobrecargas de: 
// b) el operador [ ] para acceder a base (cuando recibe 0) y altura (cuando recibe 1)
// c) el operador < para comparar dos
// rectángulos por área (un rectángulo será menor que otro si su área es menor); 
// d) el operador * para multiplicar un rectángulo por un escalar (float) y obtener un nuevo rectángulo cuya base y altura sean las
// del rectángulo original multiplicadas por dicho escalar.

#include<iostream>
using namespace std;

class Rectangulo{
	float base, altura;
	
	public:
		Rectangulo(float base, float altura): base(base), altura(altura) {};
		float CalcularArea() const{
			return base * altura;
		};

		float operator[](int index){
			if( index == 0){
				return this->base;
			}else if( index == 1){
				return this->altura;
			}else{
				return 0.0;
			}
		};

		bool operator<(const Rectangulo& rect2){
			return this->CalcularArea() < rect2.CalcularArea();
		}

		Rectangulo operator*(int escalar){
			Rectangulo aux = *this;

			aux.altura = aux.altura * escalar;
			aux.base = aux.base * escalar;

			return aux;
		}

};


int main(){

	Rectangulo rect(3, 9), rect2(2, 3);

	cout << "Area: " << rect.CalcularArea() << endl;

	cout << "Base: " << rect[0] << endl;
	cout << "Altura: " << rect[1] << endl;

	if( rect < rect2){
		cout << "El rectangulo (1) es mas grande " << endl;
	}else{
		cout << "El rectangulo (2) es mas grande " << endl;
	}

	rect2*2;

	cout << "Area(2): " << rect2.CalcularArea() << endl;
	
	return 0;
}