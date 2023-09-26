// a) Diseñe una clase para representar un cilindro con sus atributos radio y altura, un constructor que
// inicialice ambos, y un método para obtener su volúmen. Agregue sobrecargas de: 
// b) el operador [ ] para acceder a radio (cuando recibe 0) y altura (cuando recibe 1), 
// c) el operador > para comparar dos cilindro por volumen (un cilindro será menor que otro si su área es menor); 
// d) el operador >> para que “cin>>c” lea el radio y la altura del cilindro c.

#include<iostream>
using namespace std;

const int M_PI = 3.14;

class Cilindro{
	float radio, altura;
	public:
		Cilindro(float radio, float altura): radio(radio), altura(altura){};
		
		float operator[](int index){
			if(index == 0){
				return this->radio;
			}else if( index == 1){
				return this->altura;
			}else{
				return 0.0;
			}
		}

		// Añadiendo la palabra clave const al final de la función obtenerVolumen(), 
		// indicas que esta función no modificará ningún miembro de la clase y, por lo tanto, 
		// puede ser llamada desde objetos constantes. Esto solucionará el error que estás experimentando.
		float obtenerVolumen() const {
			return M_PI *radio* radio*altura ;
		}

		bool operator>(const Cilindro& c2) {
			return this->obtenerVolumen() > c2.obtenerVolumen();
		}

		friend ostream& operator>>(ostream& os, Cilindro& c2){
			os >> c2.radio;
			return os;
		}
};

int main(){

	Cilindro c1(3, 9), c2(4, 8);

	cout << c1[0] << " - " << c1[1] << endl;

	if( c1 > c2 ){
		cout << " El cilindro 1 es mas grande" << endl;
	} else{
		cout << " El cilindro 2 es mas grade" << endl;
	}
	
	cin >> c1;

	cout << c1[0] << endl;

	return 0;
}