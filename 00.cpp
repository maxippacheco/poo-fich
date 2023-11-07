// 2. Escriba un programa para generar una std::list de
// enteros con 15 elementos aleatorios entre 1 y 100.
// Luego debe mostrar los elementos y pedir al
// usuario que ingrese una posición para eliminarlo
// ese elemento de la misma.
#include<iostream>
#include<list>
using namespace std;

int main(){
	list<int> L;

	// crear el contenedor vacio y agregarle contenido
	for (size_t i = 0; i < 15; i++)
	{
		L.push_back(1+rand()%100);
	}

	// recorrer elementos y mostrarlos
	for (int num: L)
	{
		cout << num << " ";
	}

	int pos; cin >> pos;
	
	auto it = L.begin(); // * equivale a := list<int>::iterator
	advance(it, pos); // * equivale a for(size_t = 0; i < pos; i++) ++it
	L.erase(it);

	for(int &num: L){
		cout << num << endl;
	}
		
}