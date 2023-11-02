#include<iostream>

using namespace std;

int main(){

	string frase = "Ser el elegido es como estar enamorado";

	string silaba;
	cout << "Ingrese una palabra: "; cin >> silaba;


	int cant = 0;
	size_t p = frase.find(silaba, 0);
	while (p != string::npos)
	{
		cant++;
		p = frase.find(silaba, p + silaba.size());		
	}

	cout << "La silaba esta " << cant << " veces" << endl;
	

	return 0;
}