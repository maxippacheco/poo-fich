// 3. Genere una cantidad arbitraria de valores enteros (n>=1) aleatorios y muestre:
// la lista ordenada de menor a mayor
// la mediana
// la lista ordenada de mayor a menor
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

	// menor a mayor
	L.sort();	
	for(int &element: L)
	{
		cout << element << " ";
	}
	cout << endl;

	// mediana
	auto it_mediana = next(L.begin(), L.size()/2);
	cout << *it_mediana << endl;

	// ordenada de mayor a menor
	L.reverse();
	for(int element: L) cout << element << " ";


	

	return 0;
}
