#include<iostream>
#include<fstream>
using namespace std;

int main(){

	// ios trunc elimina lo que tenia antes
	ofstream archivo("numeros.txt", ios::trunc);
	if(!archivo.is_open()){
		cout << "No se puede abrir el archivo" << endl;
		return 1;
	}

	for (size_t i = 0; i < 10; i++)
	{
		archivo << rand()%100 << endl;
	}
	

	return 0;
}