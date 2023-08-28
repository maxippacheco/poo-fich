// Declare una variable entera estática y otra variable entera dinámica almacenando
// su dirección de memoria en un puntero. Asigne a la primera variable el valor 10 y a
// la segunda variable un valor ingresado por el usuario. Muestre luego las posiciones
// de memoria de ambas variables. IMPORTANTE: No olvide liberar la memoria de la
// segunda variable antes de salir

#include<iostream>
using namespace std;

int main(){

	int stat = 10, *dinam;

	cin >> *dinam;
	cout << "Static: " << &stat << endl;
	cout << "Dinamic: " << &dinam << endl;

	dinam = nullptr;

	return 0;
}