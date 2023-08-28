#include<iostream>
using namespace std;

int main(){

	int num = 20, *dir_num;

	dir_num = &num;

	cout << "Numero: " << num << endl;
	cout << "Posicion de memoria numero: " << &num << endl;
	cout << "Numero puntero: " << *dir_num << endl;
	cout << "Posicion de memoria numero puntero: " << dir_num << endl;


	return 0;
}