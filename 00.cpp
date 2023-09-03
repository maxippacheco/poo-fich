
// Herencia
#include<iostream>
using namespace std;

class Persona{
	private:
		string nombre; int edad;
	public:
		Persona(string, int);
		string GetNombre();
};

string Persona::GetNombre(){ return this->nombre; };

// Constructor de la clase Persona
Persona::Persona(string _nombre, int _edad){
	nombre = _nombre;
	edad = _edad;
}

class Alumno: public Persona{
	private:
		string codigoAlumno;
		float notaFinal;
	public:
		Alumno(string, int, string, float); // Constructor de Alumno
};

Alumno::Alumno(
	string _nombre, 
	int _edad, 
	string _codigoAlumno, 
	float _notaFinal
): Persona(_nombre, _edad){
		codigoAlumno = _codigoAlumno;
		notaFinal = _notaFinal;
};

int main(){
	Alumno a("Juan", 17, "021ABC", 8.0);

	cout << a.GetNombre() << endl;

	return 0;
}