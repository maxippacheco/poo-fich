// Escriba una función que utilice punteros para buscar y retornar la dirección de un
// entero dentro de un arreglo. Se pasan como parámetros el arreglo, su tamaño y el
// entero a buscar. Si el dato no se encuentra, debe retornar la dirección de memoria
// nula (nullptr). ¿Desde un programa cliente, cómo se obtiene el índice del elemento
// encontrado cuando la función no devuelve nullptr?
#include<iostream>
#include<vector>
#include<ctime>

using namespace std;

int *buscar(int p_size, int *p, int to_search){
	for (size_t i = 0; i < p_size; i++){
		if( *(p+i) == to_search){
			return (p+i);
		}
	}
	return nullptr;
}

int main(){
	int n; cin >> n;
	int *p = new int[n];

	srand(time(0));

	for (size_t i = 0; i < n; i++)
	{
		*(p+i) = rand()%500 + 1000;
		cout << (p+i) << "  " << *(p+i) << endl;
	}

	int to_search; cin >> to_search;

	int *num = buscar(n, p, to_search);

	if (num != nullptr)
	{
		cout << "Encontrado! " << num << endl;
	}else{
		cout << "No encontrado :(" << endl; 
	}
	
	

	return 0;
}