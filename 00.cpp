
#include<iostream>
using namespace std;

class Persona{
	private: // atributos
		int edad;
		string nombre;
	public: //metodos
		Persona(int, string); // constructor
		void leer();
		void correr();
};

// Constructor => inicializar los atributos de la clase
Persona::Persona(int _edad, string _nombre){
	edad = _edad;
	nombre = _nombre;
}

void Persona::leer(){
	cout << "Soy " << nombre << " y estoy leyendo" << endl;
}

void Persona::correr(){
	cout << "Soy " << nombre << " y estoy corriendo" << endl;
}



int main(){

	Persona p1 = Persona(20, "Juan");
	p1.leer();
	p1.correr();


	return 0;
}