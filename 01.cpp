// 2. Escriba un programa que permita ingresar una
// lista de valores flotantes por teclado, y luego
// inserte en medio de cada par de elementos
// consecutivos el promedio del par.
#include<iostream>
#include<list>
using namespace std;

int main(int argc, char const *argv[])
{
	list<float> L;
	
	for (size_t i = 0; i < 15; i++)
	{
		L.push_back(10.0);
	}

	for( auto it = next(L.begin()); it!=L.end(); advance(it,2) )
	{
		int prom = (*prev(it)+*it)/2;
		it = L.insert(it,prom);
	}


	return 0;
}
