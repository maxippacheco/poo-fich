// Utilice las clases Alumno y Docente del ejercicio anterior para crear una clase
// Curso que modele el cursado de una materia. Cada curso tiene un nombre, un
// profesor a cargo y un número máximo de 50 alumnos. Implemente un método
// AgregarAlumno(...) que permita agregar un alumno al curso y otro método
// MejorPromedio(...) que devuelva el alumno con mejor promedio. Proponga los
// constructores y métodos extra que considere necesarios

#include<iostream>
#include<vector>
using namespace std;

class Persona{
	private:
		string nombre, apellido, estado_civil;
		int dni, nacimiento;
	public:
		Persona(string, string, string, int, int);
		int Edad(int);
		int getDni(){ return this->dni; };

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
		float getPromedio(){ return this->prom; };

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

class Curso{
	string nombre, profesor_cargo;
	vector<Alumno> alumnos;

	public:
		Curso(string nombre, string profesor_cargo, vector<Alumno> alumnos): nombre(nombre), profesor_cargo(profesor_cargo), alumnos(alumnos){};
		void AgregarAlumno( const Alumno& );
		Alumno MejorPromedio();
		Alumno findAlumnoByDni(int);

};

void Curso::AgregarAlumno(const Alumno& alumno){
	if( this->alumnos.size() > 50 ){
		throw out_of_range("Has excedido la capacidad maxima por curso");
	}

	this->alumnos.push_back(alumno);

}

Alumno Curso::findAlumnoByDni(int _dni){
	for (size_t i = 0; i < alumnos.size(); i++)
	{
		if(this->alumnos[i].getDni() == _dni){
			return this->alumnos[i];
		}
	}
	
}


Alumno Curso::MejorPromedio(){
	int dni = 0;
	float mej_prom = 0.0;
	for (size_t i = 0; i < this->alumnos.size(); i++)
	{
		if( this->alumnos[i].getPromedio() > mej_prom ){
			dni = this->alumnos[i].getDni();
			mej_prom = this->alumnos[i].getPromedio();
		}
	}

	return this->findAlumnoByDni(dni);
}

int main(){


	return 0;
}