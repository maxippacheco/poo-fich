// Ejercicio 1
// Diseñe una clase Cilindro que modele un cilindro con el objetivo de calcular el
// volumen del cuerpo conociendo el radio de su base y la altura del mismo.
	// a. Cree los métodos AsignarDatos(...) y ObtenerVolumen(...) para asignar los
	// datos del problema y obtener el volumen del cuerpo.
	// b. Escriba un programa cliente que utilice dicha clase. Defina 2 instancias de
	// Cilindro llamadas c1 y c2. El objeto c1 debe utilizar datos ingresados por el
	// usuario, mientras que para c2 utilice 5.3 cm y 10.2 cm para el radio y la
	// altura respectivamente.

#include<iostream>
using namespace std;


class Cilindro{
	private:
		int radio, volumen;
	public:
		void AsignarDatos(int, int);
		float ObtenerVolumen();
};

void Cilindro::AsignarDatos(int _radio, int _volumen){
	this->radio = _radio;
	this->volumen = _volumen;
}

float Cilindro::ObtenerVolumen(){	return 3.14*(radio*radio); }


int main(){

	Cilindro c1, c2;
	int radio, volumen;

	cout << "Ingrese el radio: " << endl; cin >> radio;
	cout << "Ingrese el volumen: " << endl; cin >> volumen;

	c1.AsignarDatos(radio, volumen);
	c2.AsignarDatos(5.3, 10.2);

	// c2.ObtenerVolumen();

	cout << "El volumen del cilindro(1) es: " << 	c1.ObtenerVolumen() << endl;
	cout << "El volumen del cilindro(2) es: " << 	c2.ObtenerVolumen() << endl;

	return 0;
};