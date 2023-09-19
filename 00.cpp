// Programar una clase Animal que tenga un método desplazarse() y otro método tipo(). Programe las
// clases Mamifero, Ave y Pez, que son hijas de la clase Animal. Los atributos de las clases son el tipo y
// la especie del animal, cuyos valores deben ser pasados al constructor de la clase base. Además deberá
// sobreescribir los métodos desplazarse() y tipo(), de tal manera que el primer método devuelve una
// cadena de texto indicando el tipo de desplazamiento según el tipo: “camina” para el tipo “mamífero”,
// “vuela” para el tipo “ave” y “nada” para el tipo “pez”. Escriba un programa cliente que permita modelar un
// Parque y almacene la información de los animales en un único arreglo de 30 elementos y luego emita
// un listado de los mismos describiendo el tipo y la forma de desplazamiento de cada animal. Finalmente
// responda: ¿Hay entre las clases algún método virtual puro?¿Por qué?

#include<iostream>
using namespace std;

class Animal{
	string tipo, especie;
	public:
		Animal(string tipo, string especie): tipo(tipo), especie(especie) {};
		virtual string desplazarse() = 0;
		string verTipo(){
			return this->tipo;
		};
};

class Ave: public Animal{
	public:
    Ave(string especie) : Animal(especie, "ave") {}  // Constructor del ave
		string desplazarse(){
			return "vuela";
		}
};

class Mamifero: public Animal{
	public:
		Mamifero(string especie): Animal(especie, "mamifero"){}
		string desplazarse(){
			return "camina";
		}
};

class Pez: public Animal{
	public:
		Pez(string especie): Animal(especie, "pez"){};
		string desplazarse(){
			return "nada";
		}
};


int main(){

	Animal* animales[5];

	animales[0] = new Mamifero("Leon");
	animales[1] = new Pez("Ballena");
	animales[2] = new Mamifero("Gato");
	animales[3] = new Ave("Golondrina");
	animales[4] = new Mamifero("Tortuga");

	for (int i = 0; i < 5; i++){
 		cout << animales[i]->verTipo() << endl;
 		cout << animales[i]->desplazarse() << endl;
	}

	for (size_t i = 0; i < 5; i++)
	{
		delete animales[i];
	}
	

	return 0;
}