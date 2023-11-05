#include<iostream>
#include<fstream>

using namespace std;

struct Par{
	int i;
	double d;
};

int main(){

	ofstream archivo("datos.dat", ios::binary);

	for (size_t i = 0; i < 10; i++)
	{
		Par p;
		p.i = rand()%100+1;
		p.d = (rand()%100+1)/1000.0;

		archivo.write(reinterpret_cast<char*>(&p), sizeof(p));
		
	}
	

	return 0;
}