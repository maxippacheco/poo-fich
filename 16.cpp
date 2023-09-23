// a. Defina una clase Tecla para representar una tecla de un piano. Cada tecla puede estar o no apretada,
// y tiene además una nota asociada (cuyo nombre se representará con un string). Su interfaz debe tener
// tener entonces:
// - un constructor que reciba el nombre de la nota
// - un método VerNota que retorne el nombre de la nota
// - un método Apretar que cambie el estado de la tecla a apretada.
// - un método Soltar que cambie el estado de la tecla a no apretada.
// - un método EstaApretada que retorne true si la tecla está apretada, false en caso contrario

#include<iostream>
using namespace std;

class Tecla{
	bool es_apretada;
	string nombre_nota;
	public:
		Tecla(string nombre_nota): nombre_nota(nombre_nota){
			this->es_apretada = false;
		};
		string VerNota(){
			return this->nombre_nota;
		}
		void Apretar(){
			this->es_apretada = true;
		}
		void Soltar(){
			this->es_apretada = false;
		}
		string EstaApretada(){
			if(this->es_apretada){
				return "apretada";
			}else{
				return "no apretada";
			}
		}

};

// b. Defina una clase Pedal para representar el pedal de un piano. El pedal debe almacenar un valor
// (float) que indica la presión que el músico ejerce sobre el pedal. El constructor debe inicializar la presión
// en 0, y la clase debe tener métodos para modificarla y consultarla.

class Pedal{
	float presion;
	public:
		Pedal(){
			this->presion = 0;
		};
		void Soltar(){
			this->presion = 0;
		}
		float getPresion(){
			return this->presion;
		}
		void setPresion( float _presion ){
			this->presion = _presion;
		}
};

// c. Reutilizando las clases Tecla, Pedal e Instrumento:
//  class Instrumento{
//  virtual string VerTipo() { return "sin_nombre"; }
//  };
// defina una clase Piano que modele un instrumento de tipo "piano" con solo 7 teclas (“do”, “re”, “mi”, “fa”,
// “sol”, “la” y “si”) y 1 pedal. La clase piano debe tener métodos para:
//  - apretar una tecla, indicando el número de tecla, y que retorne la nota que debería sonar.
//  - soltar una tecla, indicando el número de tecla
//  - presionar el pedal, indicando la presión que se aplica

class Instrumento{
	public:
		virtual string VerTipo() { return "sin_nombre"; }
};

class Piano: public Instrumento{
	Tecla teclas[7];
	Pedal pedal;
	public:
		Piano() : teclas{Tecla("do"), Tecla("re"), Tecla("mi"), Tecla("fa"), Tecla("sol"), Tecla("la"), Tecla("si")} {}

		string ApretarTecla(int num_tecla){
			if(num_tecla >= 1 && num_tecla <= 7){
				return this->teclas[num_tecla - 1].Apretar();
			}else{
				return "Tecla no encontrada";
			}
		}

		string SoltarTecla(int num_tecla){
			if(num_tecla >= 1 && num_tecla <= 7){
				return this->teclas[num_tecla - 1].Soltar();
			}else{
				return "Tecla no encontrada";
			}
		}

		void PresionarPedal(int presion){
			return pedal.setPresion(presion);
		}

};


int main(){

	Tecla tecl("k");

	cout << tecl.VerNota() << endl;
	cout << tecl.EstaApretada() << endl;
	tecl.Apretar();
	cout << tecl.EstaApretada() << endl;
	tecl.Soltar();
	cout << tecl.EstaApretada() << endl;

	return 0;
}