// Implemente una función templatizada llamada Mayor(...) que reciba dos valores y
// devuelva el mayor. Compruebe el correcto funcionamiento de la rutina probándola
// desde un programa cliente con valores de tipo int, float y string.
// TODO: a. Programe una sobrecarga de la función Mayor(...) que reciba un vector y
// retorne el mayor elemento del mismo. Pruebe la función sobrecargada
// desde un programa cliente con diversos tipos de datos.
// TODO: b. Responda: ¿Servirán las funciones anteriores con datos del tipo mostrado
// en el recuadro? Justifique su respuesta

#include<iostream>
#include<vector>
using namespace std;

struct Persona{
	string nombre, apellido;
	int dni;
};

bool compare_dni(Persona p1, Persona p2) { //funciones comparadoras que voy a usar en la template mas abajo
    return p1.dni > p2.dni;
}

bool compare_apellido(Persona p1, Persona p2) {
    return p1.apellido > p2.apellido;
}

template<typename T>
T mayor(T value1, T value2){
	T mayor;
	if(value1 > value2){
		mayor = value1;

		return mayor;
	}
	mayor = value2;

	return mayor;
}

template<typename T>
T mayor(const vector<T> &vector1){
	T mayor = vector1[0];
	
	for (size_t i = 0; i < vector1.size(); i++)
	{
		if( vector1[i] > mayor ){
			mayor = vector1[i];
		}
	}

	return mayor;
}

template<typename T, typename P>
T Mayor(T persona1, T persona2, P comparador){

	if(comparador(persona1, persona2)){
		return persona1; // ya me retorna un struct completamente cargado para despues mostrarlo
	}

	return persona2;
}

int main(){

	int n1 = 10, n2 = 20;
	int n3 = mayor(n1, n2);
	cout << n3 << endl;

	float f1 = 20.3, f2 = 20.4;
	float f3 = mayor(f1, f2);
	cout << f3 << endl;

	string str1 = "C", str2 = "B";
	string str3 = mayor(str1, str2);
	cout << str3 << endl;

	vector<int> vector_num = { 1, 5, 2 };
	vector<float> vector_floa = { 1.0, 3.0, 5.0, 2.0 };
	vector<string> vector_str = { "A", "B", "D", "C" };

	int vect_num_may = mayor(vector_num);
	float vect_floa_may = mayor(vector_floa);
	string vect_str_may = mayor(vector_str);

	cout << vect_num_may << endl;
	cout << vect_floa_may << endl;
	cout << vect_str_may << endl;

	Persona p1, p2;
  p1.apellido = "Menendez";
  p1.nombre = "Juan";
  p1.dni = 46371805;

  p2.apellido = "Novara";
  p2.nombre = "Pablo";
  p2.dni = 35555786;

  cout << Mayor<Persona>(p1,p2,compare_apellido).nombre << endl;
		 
	//el nombre de la funcion comparadora funciona como puntero por lo que no se le coloca los argumentos en la instancia,
	// si luego dentro de la funcion Mayor


	return 0;
}