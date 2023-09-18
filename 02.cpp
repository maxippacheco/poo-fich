// Ejercicio 1
// Diseñe una clase Persona que contenga los siguientes atributos: apellido y
// nombre, DNI, fecha de nacimiento y estado civil. La clase debe poseer, además, un
// método Edad(...) que calcule la edad actual de la persona en base a la fecha de
// nacimiento y la fecha actual (que recibe como argumento).

// Implemente una clase Alumno para contener la siguiente información de un
// alumno: apellido y nombre, DNI, año de nacimiento, estado civil, promedio y
// cantidad de materias aprobadas. La clase debe poseer, además, un método
// MeritoAcademico() que devuelve el mérito académico del alumno (éste se calcula
// como el producto entre el promedio y la cantidad de materias aprobadas).

// Cree, también, una clase Docente para modelar un docente a partir de la siguiente
// información: apellido y nombre, DNI, año de nacimiento, estado civil y fecha de
// ingreso. La clase debe poseer, además, un método Antiguedad() que calcule la
// antigüedad del docente en base a su fecha de ingreso y la fecha actual.

// Proponga una jerarquía de clases adecuada para evitar repetir atributos.

// Implemente constructores y métodos extra que considere adecuados. Codifique un
// programa cliente que cree instancias de Alumno y Docente y utilice sus funciones.

#include<iostream>
using namespace std;


class Persona{
	private:
		string nombre, apellido, estado_civil;
		int dni, nacimiento;
	public:
		Persona(string, string, string, int, int);
		int Edad(int);

};

// constructor
Persona::Persona(string _nombre, string _apellido, string _estado_civil, int _dni, int _nacimiento){
	nombre = _nombre;
	apellido = _apellido;
	estado_civil = _estado_civil;
	dni = _dni;
	nacimiento = _nacimiento;
};

// calcular edad
int Persona::Edad(int fecha_actual){	
	return ((fecha_actual/10000) - (this->nacimiento/10000));
}

class Alumno: public Persona{
	private:
		int anio_nacimiento, cant_aprobadas;
		float prom;
	public:
		Alumno(string, string, string, int, int, float, int);
		float MeritoAcademico();
};

Alumno::Alumno(string _nombre, string _apellido, string _estado_civil, int _dni, int _nacimiento, float _prom, int _cant_aprobadas ): 
Persona(_nombre, _apellido, _estado_civil, _dni, _nacimiento){
	this->anio_nacimiento = (_nacimiento/10000);
	this->prom = _prom;
	this->cant_aprobadas = _cant_aprobadas;
}

float Alumno::MeritoAcademico(){
	return (this->cant_aprobadas * this->prom);
}

class Docente: public Persona{
	int fecha_ingreso;
	public:
		Docente(string, string, string, int, int, int);
		// en anios
		int Antiguedad(int);
};

Docente::Docente(string _nombre, string _apellido, string _estado_civil, int _dni, int _nacimiento, int _fecha_ingreso): 
Persona(_nombre, _apellido, _estado_civil, _dni, _nacimiento){
	fecha_ingreso = _fecha_ingreso;
}

int Docente::Antiguedad(int fecha_actual){
	return ((fecha_actual/10000) - (this->fecha_ingreso/10000));
}

int main(){

	Persona p1("Juan", "Perez", "Casado", 46449741, 20050211);


	cout << p1.Edad(20230917) << endl;
	
	return 0;
}