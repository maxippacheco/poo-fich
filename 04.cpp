// 3) Programar una clase Alumno y otra Docente, que son hijas de una clase Persona, que tiene el
// método Saludar. Los atributos de un alumno son el nombre y la carrera a la que está inscripto. Los
// atributos del docente son el nombre y la materia que dicta. En las clases hijas se debe sobreescribir el
// método Saludar, de tal manera que si cuando un docente saluda, debe devolver “Mi nombre es XXXXXX
// y dicto WWWWWW” (donde XXXXXX es el nombre y WWWWW la materia), mientras que si saluda un
// alumno, deberá devolver “soy ZZZZZZ y pertenezco a la carrera TTTTTT”. Escriba un programa cliente
// que tenga en un único vector un docente y 24 alumnos, y un método para que todos saluden.
// Finalmente responda: ¿Hay en esta jerarquía de clases alguna clase abstracta?¿Por qué?



#include<iostream>
#include<vector>

using namespace std;

class Persona{
	public:
		virtual void saludar() = 0;	
};

class Alumno: public Persona {
	string nombre, carrera;

	public:
		Alumno(string nombre, string carrera): nombre(nombre), carrera(carrera){};
		void saludar() override{
			cout << "Mi nombre es " << this->nombre << " y pertenezco a la carrera " << this->carrera << endl;
		};
};

class Docente: public Persona{
	string nombre, materia_dictada;
	public: 
		Docente(string nombre, string materia_dictada): nombre(nombre), materia_dictada(materia_dictada){};
		void saludar() override{
			cout << "Mi nombre es " << this->nombre << " y dicto la clase " << this->materia_dictada << endl;
		};
};

int main(){

	Alumno alumn1("Maximo", "Ing informatica");
	Docente docent("Manuel Vallejos", "Programacion orientada a objetos");

	alumn1.saludar();
	docent.saludar();

	// 24 alumnos y un profesor
	vector<Persona*> personas;

	personas.push_back( new Docente("Jorge Podelliet", "Programacion orientada a objetos"));

	for (size_t i = 0; i < 23; i++)
	{
		cout << "Ingrese un nuevo alumno: " << endl;
		string nombre, carrera;
		cin >> nombre >> carrera;
	
		personas.push_back( new Alumno(nombre, carrera));
	}

	for( Persona* persona: personas){
		persona->saludar();
	}
	
	for (size_t i = 0; i < 24; i++)
	{
		delete [] personas[i];
	}
	


	return 0;
}