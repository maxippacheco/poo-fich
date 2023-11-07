// 3. Genere una cantidad arbitraria de valores enteros (n>=1) aleatorios y muestre:
// la cantidad de ceros
// la posición del valor 7
// *cantidad de primos
// bool es_primo(int x) { ... }
// cout<<count_if(L.begin(),L.end(),es_primo);
#include<algorithm>
#include<iostream>
#include<list>
#include <numeric>
using namespace std;

int rand_20() {
	return rand()%20;
}

int main(int argc, char const *argv[])
{
	int n; cin >> n;
	list<int> L(n);
	generate(L.begin(), L.end(), rand_20);

	for( int element: L ) cout << element << " ";
	cout << endl;

	// cantidad de ceros 		
	cout << count(L.begin(), L.end(), 0) << endl;

	// la posicion del valor 7
	auto it_7 = find(L.begin(), L.end(), 7);
	
	if( it_7 == L.end()) 
		cout << "No esta" << endl;
	else 
		cout << "Esta en la pos: " << distance(L.begin(), it_7);

	return 0;
}
