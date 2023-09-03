// Ejercicio 3
// Diseñe una clase Polinomio que contenga:
// a. un constructor que reciba el grado el polinomio e inicialice sus coeficientes en 0.
// b. un método que permita cambiar un coeficiente.
// c. un método evaluar que permita evaluar el polinomio para un valor dado de la variable x.
// d. el/los métodos que considere necesarios para poder mostrar un polinomio desde un programa cliente.
// e. una función que permita sumar dos polinomios retornando un tercer
// polinomio con el resultado (ej. p_res=Sumar(p1,p2);). ¿Cómo variaría si en
// lugar de ser una función libre fuera un método de la clase?
// Verifique el funcionamiento de la función Sumar(...) mediante un programa cliente

#include<iostream>
#include<cmath>
#include<vector>
using namespace std;

// para todo polinomio tal que grado pertenezca a los numeros enteros
class Polinomio{
	int grado;
	vector<int> coeficientes;

	public:
		Polinomio(int);
		void CambiarCoeficiente(int, float);
		float Evaluar(float);
		int GetGrado();
};

Polinomio::Polinomio(int _grado){
  if (grado < 0) {
    throw invalid_argument("El grado del polinomio debe ser no negativo.");
  }
	this->grado = _grado;
	coeficientes.resize(grado + 1, 0);
};

void Polinomio::CambiarCoeficiente(int _grado, float _valor){
	if( _grado < 0 || _grado >= coeficientes.size()){
		throw out_of_range("Grado de coeficiente fuera de rango.");
	}

	this->coeficientes[_grado] = _valor;
};

float Polinomio::Evaluar(float _x){
	if( this->grado < 0 || this->grado >= coeficientes.size()){
		throw out_of_range("Grado de coeficiente fuera de rango.");
	}
	// coeficientes.resize(this->grado, _x);

	float result = 0.0;

	for (size_t i = this->grado; i <= 0; i--)
	{	
		result += this->coeficientes[i]*pow(_x, i);
	}

	return result;
	
}

int Polinomio::GetGrado(){
	return this->grado;
}

int main(){

	Polinomio pol1(3);
	pol1.CambiarCoeficiente(0, 1);
	cout << pol1.GetGrado() << endl;
	cout << pol1.Evaluar(1) << endl;


	return 0;
}