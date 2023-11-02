#include<iostream>
using namespace std;


int main(){

	// * substr cortar cadenas de texto
	// string s1 = "Al infinito y mas alla!";
	// string s2 = s1.substr(3,8);
	
	// muestra "infinito"
	// cout << s2 << endl;
	
	// string s3 = s1.substr(14);
	
	// muestra "más allá!"
	// cout << s3 << endl;
	// muestra "Al infinito y más allá!"	
	// cout << s1 << endl;

	// * borrar una parte intermedia
	string s1 = "Es menester que sea rock!";
	s1.erase(3,17);
	cout << s1 << endl;

	// * borrar desde un punto hasta el final
	string s2 = "Vengo remando de larga distancia";
	s2.erase(13);
	cout << s2 << endl;
	
	// * borrar todo
	string s3 = "Andaras bien por la 66";


	return 0;
}