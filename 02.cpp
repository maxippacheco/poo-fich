// Utilizando notación de punteros, generar un arreglo dinámico y lineal de N
// elementos numéricos enteros, con valores aleatorios entre 1000 y 1500, y muestre
// en pantalla la dirección de memoria del mayor elemento. N es un dato ingresado
// por el usuario

#include<iostream>
using namespace std;

int main(){

	int n; cin >> n;
	int *p = new int[n];

	for (size_t i = 0; i < n; i++)
	{
		*(p+i) = rand() % 1000 + 500;
		cout << "Posicion: " << (p+i) << " Numero: " << *(p+i) << endl;
	}

	int *may = p;

	for (size_t i = 0; i < n; i++)
	{
		if( *(p+i) > *may) {
			may = (p+i);
		}
	}

	cout << "Posicion: " << may << " Numero: " << *may << endl;
	

	delete [] p;
	may = nullptr;

	return 0;
}