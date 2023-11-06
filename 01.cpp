// Implemente una función Clamp(...) que reciba como parámetros una variable (por
// referencia) y dos valores indicando los límites superior e inferior para el valor de
// dicha variable. Si el valor de la variable supera su máximo, este debe ajustarse al
// máximo valor permitido. De la misma forma si el valor es inferior al mínimo. Pruebe
// la función templatizada desde un programa cliente.

#include<iostream>
using namespace std;

template<typename T>
T Clamp(T &variable, T superior, T inferior){
	if( variable > superior){
		variable = superior;
	}else if(variable < inferior){
		variable = inferior;
	}
	return variable;
}

int main(){

	int number = 100;

	int number_format = Clamp(number, 200, 80);

	cout << number_format << endl;

	return 0;
}