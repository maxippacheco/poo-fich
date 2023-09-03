// Ejercicio 2
// Proponga una clase EcuacionCuadratica para modelar ecuaciones cuadráticas de
// la forma ax2+bx+c=0. La clase debe incluir:
// a. Un constructor que reciba los valores de los coeficientes a, b y c.
// b. Un método TieneRaicesReales(...) que devuelva verdadero si las raíces de
// la ecuación son reales.
// c. Dos métodos VerRaiz1(...) y VerRaiz2(...) que permitan obtener las raíces
// reales (en caso de que lo sean).
// TODO: d. Dos métodos VerParteReal(...) y VerParteImag(...) que permitan obtener las
// partes real e imaginaria de las raíces complejas (en caso de que lo sean).
// e. Cree un programa cliente que utilice un objeto de la clase
// EcuaciónCuadratica para determinar las raíces de una ecuación
// cuadrática cuyos coeficientes sean ingresados por el usuario, y las muestre
// en el formato que corresponda (según sean reales o complejas).

#include<iostream>
#include<cmath>
using namespace std;

class EcuacionCuadratica{
	float a, b, c;
	public:
		EcuacionCuadratica(float,float,float);
		bool TieneRaicesReales();
		float VerRaiz1();
		float VerRaiz2();
};

EcuacionCuadratica::EcuacionCuadratica(float _a, float _b, float _c){
		this->a = _a;
		this->b = _b;
		this->c = _c;
};

bool EcuacionCuadratica::TieneRaicesReales(){
	float disc =  (b*b)-(4*a*c);

	if( disc < 0 ){ return false; }

	return true;
};

float EcuacionCuadratica::VerRaiz1(){
	return -b+sqrt((b*b)-4*a*c)/( 2*a );
}

float EcuacionCuadratica::VerRaiz2(){
	return ( -b-sqrt( (b*b)-(4*a*c) ) )/( 2*a );
}


int main(){
	return 0;
};