#include<iostream>

using namespace std;

int main(){

	string frase = "Ser el elegido es como estar enamorado";

	string palabra;
	cout << "Ingrese una palabra: "; cin >> palabra;

	size_t p = frase.find(palabra);
	if( p == string::npos )
		cout << "La palabra no esta en la frase" << endl;
	else
		cout << "La palabra comienza en la posicion " << p;

	return 0;
}