#include<iostream>
using namespace std;


int main(){


	// * reemplazar un fragmento por otro
	string s1 = "Hola a todos, yo soy el leon!";
	s1.replace(5,7, "mundo");
	cout << s1 << endl;

	// * borrar desde un punto hasta el final
	string s2 = "Vengo remando de larga distancia";
	s2.erase(13);
	cout << s2 << endl;
	
	// * borrar todo
	string s3 = "Andaras bien por la 66";

	


	return 0;
}