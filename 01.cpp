#include<iostream>
#include<fstream>

using namespace std;

struct Par{
	int i;
	double d;
};

int main(){

	ifstream archivo("datos.dat", ios::binary|ios::ate);
	
	// deducir el tamanio del archivo con la bandera ate y pregunto en que posicion estoy y vuelvo al principio
	// archivo.tellg() me dice a donde estoy en ese momento del archivo
	int n = archivo.tellg() / sizeof(Par);
	// que bisque en pos 0
	archivo.seekg(0);

	for (size_t i = 0; i < n; i++)
	{
		Par p;
		archivo.read(reinterpret_cast<char*>(&p), sizeof(p));
		cout << p.i << " " << p.d << endl;
	}
	
	archivo.close();

	

	return 0;
}