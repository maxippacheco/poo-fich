
#include<iostream>
using namespace std;

class Rectangulo{
	private: // atributos
		float largo, ancho;
	public:
		Rectangulo(float, float);
		float perimetro(){
			return ((2*largo) + (2*ancho));
		};
		float area(){
			return largo*ancho;
		};
};

Rectangulo::Rectangulo(float _largo, float _ancho){
	largo = _largo;
	ancho = _ancho;
}

int main(){

	Rectangulo r(11, 7);

	float perimetro = r.perimetro();
	float area = r.area();

	cout << "Perimetro: " << perimetro << endl;
	cout << "Area: " << area << endl;

	return 0;
}
