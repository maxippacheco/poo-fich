#include<iostream>
#include<fstream>

using namespace std;

struct Par{
	int i;
	double d;
};

int main(){

	fstream archivo("datos.dat", ios::binary|ios::in|ios::out|ios::ate);
	int n = archivo.tellg()/sizeof(Par);

	archivo.seekg(0);
	Par mayor = {0, 0};

	int pos_mayor;
	for (size_t i = 0; i < n; i++)
	{
		Par p;
		archivo.read(reinterpret_cast<char*>(&p), sizeof(p));

		if( p.d > mayor.d){
			mayor = p;
			pos_mayor = i;
		}
	}

	archivo.seekp(pos_mayor*sizeof(Par));
	mayor.i;
	// Par p; p.i = 0; p.d = 0.992;
	archivo.write(reinterpret_cast<char*>(&mayor), sizeof(mayor));



	return 0;
}