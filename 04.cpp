// 3. Genere una cantidad arbitraria de valores enteros (n>=1) aleatorios y muestre:
// lista de datos
// promedio
// valores minimos y maximos
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

	for(int &element: L)
	{
		cout << element << " ";
	}
	cout << endl;

	float sum = accumulate(L.begin(), L.end(), 0);
	cout << "Promedio: " << sum/L.size() << endl;

	auto it_max = max_element(L.begin(), L.end());
	auto it_min = min_element(L.begin(), L.end());

	cout << "Maximo elemento: " << *it_max << endl;
	cout << "Minimo elemento: " << *it_min << endl;

	return 0;
}
