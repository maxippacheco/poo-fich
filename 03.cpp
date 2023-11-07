// 3. Genere una cantidad arbitraria de valores enteros (n>=1) aleatorios
#include<algorithm>
#include<iostream>
#include<list>
using namespace std;

int rand_20() {
	return rand()%20;
}


int main(int argc, char const *argv[])
{
	int n;
	cout << "Ingrese la cantidad de elementos de la lista: " << endl; cin >> n;	

	list<int> L(n);

	generate(L.begin(), L.end(), rand_20);

	for(int &element: L)
	{
		cout << element << " ";
	}

	return 0;
}
