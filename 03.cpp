#include<iostream>
using namespace std;

// NO PONER COUT O CIN EN METODOS
class Perro{
	private:
		string nombre, raza;
	public:
		Perro(string,string); //constructor
		~Perro(); //destructor
		string retornarNombre();
};

Perro::Perro(string _nombre, string _raza){
	nombre = _nombre;
	raza = _raza;
}

// Destructor
Perro::~Perro(){}

string Perro::retornarNombre(){
	return nombre;
}


int main(){

	Perro perro1("Fido", "Doberman");
	string fido_nombre = perro1.retornarNombre();
	cout << "Hola soy " << fido_nombre << endl;

	perro1.~Perro(); // destruyendo el objeto

	return 0;
};