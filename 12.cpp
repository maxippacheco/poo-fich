// Una fábrica de Tanques los hace de forma de Cilindro o de Esfera, en ambos envases debemos rotular
// el volumen en m3 y el peso en kilogramos.
// Modele una clase base Tanque con los atributos volumen y peso. Un método público AsignarPeso(p),
// un método virtual puro CalcularVolumen() que calcule el volumen de acuerdo a los parámetros de los
// hijos y otros 2 métodos para VerVolumen() y VerPeso().
// Modele la clase hija Cilindro que tendrá los atributos radio y altura, cuya fórmula de volumen es: área
// de la base x altura, donde el area de la base se calcula como PI*radio^2; y otra clase hija Esfera que
// tendrá el atributo radio, cuya fórmula de volumen es: 4/3*PI*radio^3. Los atributos (medidas y peso) los
// debe cargar con un constructor.
// En el programa principal debe usar un único puntero de tipo Tanque para crear primero un Cilindro y
// mostrar su volúmen, y luego una Esfera y también mostrar su volúmen

#include<iostream>
using namespace std;

const int PI = 3.14;

class Tanque{
	protected:
		float volumen, peso;
	public:
		void AsignarPeso(float p){
			this->peso = p;
		}
		virtual void CalcularVolumen() = 0;
		float VerVolumen(){
			return this->volumen;
		}
		float VerPeso(){
			return this->peso;
		}
};

class Cilindro: public Tanque{
	float radio, altura;
	public:
		Cilindro(float radio, float altura, float peso): radio(radio), altura(altura){
			AsignarPeso(peso);
		};
		void CalcularVolumen() override{
			this->volumen = PI * this->radio * this->radio;
		}
};

class Esfera: public Tanque{
	float radio;
	public:
		Esfera(float radio, float peso): radio(radio){
			AsignarPeso(peso);
		};
		void CalcularVolumen() override{
			this->volumen = 4/3*PI*(radio*radio*radio);
		}
};


int main(){

	Cilindro cilindro(2.0, 5.0, 3.0);
	Esfera esfera(3.0, 2.0);

	cilindro.CalcularVolumen();
	cout << cilindro.VerVolumen() << endl;
	cilindro.AsignarPeso(10.0);
	cout << cilindro.VerPeso() << endl;

	esfera.CalcularVolumen();
	cout << esfera.VerVolumen() << endl;
	esfera.AsignarPeso(5.0);
	cout << esfera.VerPeso() << endl;


	return 0;
}