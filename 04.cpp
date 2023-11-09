// Ejercicio 2 (25pts) a) Escriba una función genérica mediana3 que reciba 3 valores de
// un mismo tipo genérico y retorne la mediana (la mediana es uno de los 3, el que no es
// ni el mínimo ni el máximo). b) Escriba un programa cliente que muestre la mediana
// entre 3 flotantes que ingrese el usuario; y entre 3 fracciones. Las fracciones deben ser
// del tipo: struct Fraccion { int num, den; };.

#include<iostream>
using namespace std;

template<typename T>
T mediana(T &valor1, T &valor2, T &valor3)
{
	if(valor1 > valor2 and valor1 > valor3)
	{
		return valor1;
	}else if( valor2 > valor3 )
	{
		return valor2;
	}

	return valor3;
}

int main(){

	float f1 = 4.7, f2 = 4.5, f3 = 4.3;

	float median = mediana(f1, f2, f3);
	cout << median << endl;


	return 0;
}