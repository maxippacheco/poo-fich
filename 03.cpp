// 2) Escriba una clase llamada CORREOS con los siguientes atributos: Nombre y mail (ambos string).
// Proponga entre los métodos las siguientes sobrecargas: a) operador == para comparar los objetos de
// tipo CORREOS por sus nombres, b) operador [] para que devuelva el nombre o el email de acuerdo al
// índice 1 o 2 respectivamente, y c) operador << para poder mostrar y mail de una instancia x mediante
// cout<<x

#include<iostream>
using namespace std;

class Correo{
	string nombre, mail;
	public:
		Correo(string nombre, string mail): nombre(nombre), mail(mail){};

		string operator[](int index){
			if( index == 1){
				return this->mail;
			}else if( index == 2){
				return this->nombre;
			}else{
				return "Property not found";
			}
		}

		bool operator<=(const Correo& correo2){
			return this->mail == correo2.mail;
		};
};

ostream& operator<<(std::ostream& os, const Correo& correo) {
	os << "Nombre: " << correo.nombre << " Mail: " << correo.mail << endl; 

	return os;
};


int main(){

	Correo correo1("Maximo", "pachecomaximo11@gmail.com");

	cout << correo1[1] << endl;
	cout << correo1[2] << endl;

	cout << correo1;

	return 0;
}