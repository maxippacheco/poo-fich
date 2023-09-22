// Una fábrica de conservas hace envases de forma cilíndrica (lata) o de prisma recto (caja); en ambos
// envases debemos rotular el volumen en cm3 y el peso en gramos.
// Modele una clase base Envase con los atributos volumen y peso. Un método público AsignarPeso(p), un
// método virtual puro CalcularVolumen() que calcule el volumen de acuerdo a los parámetros de los hijos
// y otros 2 métodos para VerVolumen() y VerPeso().
// Modele la clase hija Lata que tendrá los atributos radio y altura, cuya fórmula de volumen es: área de la
// base x altura, donde el área de la base es PI*radio^2; y otra clase hija Caja que tendrá los atributos
// largo, ancho y alto, cuya fórmula de volumen es: largo x ancho x alto. Los atributos los debe cargar en
// sus respectivos constructores. Estos (los constructores de Caja y Lata) recibirán las medidas
// necesarias, y el peso.
// En el programa principal debe usar un único puntero de tipo Envase para crear primero una Lata y
// mostrar su volúmen, y luego una Caja y también mostrar su volúmen.


#include<iostream>
#include<vector>
using namespace std;

const float PI = 3.14;

class Envase{
	float volumen, peso;
	public:
		// Envase(int volumen, int peso): volumen(volumen), peso(peso){};
		void AsignarPeso(float p){
			this->peso = p;
		};
		virtual float CalcularVolumen() = 0;
		
		float verVolumen(){
			return this->volumen;
		};
		float verPeso(){
			return this->peso;
		}
};

class Lata: public Envase{
	float radio, altura;
	public:
		Lata(float radio, float altura, float peso): radio(radio), altura(altura) {
			this->AsignarPeso(peso);
		};
		float CalcularVolumen() override {
			return (2 * PI * this->radio*(this->radio*this->altura)); 
		}
};

class Caja: public Envase{
	float largo, ancho, alto;
	public:
		Caja(float largo, float ancho, float alto, float peso): largo(largo), ancho(ancho), alto(alto){
			this->AsignarPeso(peso);
		};
		float CalcularVolumen() override{
			return this->largo * this->ancho * this->alto;
		}

};

int main(){

	vector<Envase*> envases;

	float radio_lata, altura_lata, peso_lata;
	cin >> radio_lata >> altura_lata >> peso_lata;

	envases.push_back( new Lata(radio_lata, altura_lata, peso_lata));
	cout << "El volumen de la lata es: " << envases[0]->CalcularVolumen() << endl;

	float largo_caja, ancho_caja, alto_caja, peso_caja;
	cin >> largo_caja >> ancho_caja >> alto_caja >> peso_caja;

	envases.push_back(new Caja(largo_caja, ancho_caja, alto_caja, peso_caja));
	cout << "El volumen de la caja es: " << envases[1]->CalcularVolumen() << endl;

	// liberar memoria
	for (size_t i = 0; i < envases.size(); i++)
	{
		delete [] envases[i];
	}
	

	return 0;
}