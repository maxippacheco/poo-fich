// 3. Genere una cantidad arbitraria de valores enteros (n>=1) aleatorios y muestre:
// la lista de valores sin elementos repetidos
// la lista de valores sin ceros
// la lista de valores sin primos
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
	
	// la lista de valores sin elementos repetidos
	L.sort();

	auto it_rep = unique(L.begin(), L.end());
	L.erase(it_rep, L.end()); // unique no puede eliminar

	for( int element: L ) cout << element << " ";
	cout << endl;

	// la lista de valores sin ceros
	auto it_0 = remove(L.begin(), L.end(), 0);
	L.erase(it_0, L.end());

	for( int element: L ) cout << element << " ";
	cout << endl;

	// la lista de valores sin primos
	// auto it_pr = remove_if(L.begin(),L.end(),es_primo);
	// L.erase(it_pr,L.end());

	return 0;
}
