#include<iostream>
#include <fstream>
#include <vector>
using namespace std;

int main(){
	
	ifstream intxt("INFORME.txt");
	vector <string> v;
	string linea, palabra;
	while (getline(intxt, linea)){
		while(getline(intxt, palabra,' ')){
			if (palabra=="paquete"){
				palabra ="APLICACION";
			}
			v.push_back(palabra);
		}
		v.push_back("/n");
	}
	intxt.close();
	ofstream outtxt("INFORME.txt");
	for(int i = 0; i<v.size(); i++){
		if (v[i] == "/n"){
			outtxt<<endl;
		}
		else{
			outtxt<<v[i]<<" ";
		}
	}
	
	
	return 0;
}
