#include<iostream>
#include<map>
using namespace std;

int main(int argc, char const *argv[])
{
	map<string, int> agenda;
	agenda["Fulano"] = 15647352;
	agenda["Mengano"] = 15473673;
	agenda["Sultano"] = 15543455;
	agenda["Juan Perez"] = 15536632;

	// consultar dato si se que no existe
	auto it = agenda.find("Wally");
	if (it==agenda.end()){
		cout << "No encuentro a Wally!";
	}else{
		cout << "Nro de Wally: " << it->second;
	}

	// Recorrer todo el contenido de un map:
	for (auto it = agenda.begin(); it != agenda.end(); it++)
	{
		cout << it->first << " esta asociado a " << it->second << endl;
	}

	for( auto &element: agenda)
	{
		cout << element.first << " esta asociado a " << element.second << endl;
	}
	

	return 0;
}
