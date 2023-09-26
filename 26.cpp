// a) Escriba una función que reciba tres punteros indicando el comienzo, una posición intermedia y el
// final de un arreglo. La función debe generar y retornar dos nuevos arreglos dinámicos: uno con los
// elementos que en el arreglo de entrada estaban antes de la posición intermedia, y otro con los que
// estaban después (notar que el elemento apuntado por ese puntero intermedio no formará parte de
// ninguno de los dos). Como casos especiales, si se recibe como posición intermedia a la del primer o
// del último elemento la función deberá generar y retornar un solo arreglo (el otro estaría vacío, así que
// mejor no generarlo en ese caso).
// b) Escriba un programa cliente para probar la función que permita al usuario ingresar un arreglo y un
// número de posición para generar el 2do puntero; y luego muestre los resultados.
// Nota: no puede usar std::vector para este ejercicio.

#include<iostream>
#include<vector>
using namespace std;

pair<vector<int>, vector<int>> dividir_arr(int *inicio, int *intermedio, int *fin){
	vector<int> antes;
	vector<int> despues;

	if( intermedio == inicio){
		for (int *i = intermedio + 1; i <= fin; i++)
		{
			despues.push_back(*i);
		}
		
	}else if( intermedio == fin ){
		for (int *i = inicio; i < intermedio; i++)
		{
			antes.push_back(*i);
		}
	}else{
		for (int *i = inicio; i < intermedio; i++)
		{
			antes.push_back(*i);
		}

		for (int *i = intermedio + 1; i <= fin; i++)
		{
			despues.push_back(*i);
		}		
	}

	return make_pair(antes, despues);
}

int main(){
	int n;
	cout << "Ingrese el tamaño del arreglo: ";
	cin >> n;

	int *arreglo = new int[n];

	cout << "Ingrese los elementos del arreglo:" << endl;
	for (int i = 0; i < n; i++) {
			cin >> arreglo[i];
	}

	int posicion;
	cout << "Ingrese la posición intermedia: ";
	cin >> posicion;

	if (posicion < 0 || posicion >= n) {
			cout << "La posición intermedia es inválida." << endl;
	} else {
			pair<vector<int>, vector<int>> resultado = dividir_arr(arreglo, arreglo + posicion, arreglo + n - 1);

			cout << "Elementos antes de la posición intermedia:" << endl;
			for (int elemento : resultado.first) {
					cout << elemento << " ";
			}
			cout << endl;

			cout << "Elementos después de la posición intermedia:" << endl;
			for (int elemento : resultado.second) {
					cout << elemento << " ";
			}
			cout << endl;
	}

	delete[] arreglo; // Liberar la memoria asignada dinámicamente


	return 0;
}