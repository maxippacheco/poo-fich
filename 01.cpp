#include<iostream>
#include<fstream>
#include<vector>
using namespace std;

struct Alumno{
	string nombre;
	int n1,n2,n3;
};

// OFSTREAM ESCRIBIR ISTREAM LEER
int main(){
	
	ifstream archi("numeros.txt");
	vector<Alumno> alumnos;

	Alumno a;

	while (
		getline( archi, a.nombre ) &&
		archi >> a.n1 >> a.n2 >> a.n3
	)
	{
		cout << a.nombre << endl;
		cout << a.n1 << endl;
		cout << a.n2 << endl;
		cout << a.n3 << endl;

		alumnos.push_back(a);
		archi.ignore();
	}

	archi.close();

	ofstream archi2("numeros.txt");

	for (size_t i = 0; i < alumnos.size(); i++)
	{
		cout << alumnos[i].nombre << endl;
		float prom = (alumnos[i].n1 + alumnos[i].n2 + alumnos[i].n3)/3.0;

		cout << prom << endl;
	}
	
	


	return 0;
}