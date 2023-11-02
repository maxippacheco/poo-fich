#include<iostream>
#include<vector>
using namespace std;

struct Poder{
	string color;
	string nombre;
};

class Personaje{
	string nombre, color_inicial;
	vector<Poder> poderes;
	
	public:
		Personaje(string nombre, string color_inicial): nombre(nombre), color_inicial(color_inicial){};
		string VerNombre(){ return this->nombre; };
		string VerColor(){ return this->color_inicial; };

		bool TienePoder( Poder poder ){
			for (int i = 0; i < poderes.size(); i++)
			{
				if( poderes[i].nombre == poder.nombre){
					return true;
				}
			}
			return false;
		}

		bool AgregarPoder(Poder poder){

			for (int i = 0; i < poderes.size(); i++)
			{
				if( poderes[i].nombre == poder.nombre){
					return false;
				}
			}

			poderes.push_back(poder);

			return true;
		}

};

int main(){

	Personaje persona1("Gonza", "Verde");

	cout << persona1.VerColor() << " " << persona1.VerNombre() << endl;

	Poder poder = { "Rasengan", "Azul"};

	cout << persona1.AgregarPoder(poder) << endl;
	cout << persona1.AgregarPoder(poder) << endl;

	return 0;
}