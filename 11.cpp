#include<iostream>
#include<vector>
#include<fstream>

using namespace std;

int main(){

	// ouput - ofstream - insterting things in the file
	// cout << "What did you eat?: " << endl;
	// string food; cin >> food;
	// ofstream archivo("food.txt");
	// archivo << food;
	// archivo.close();

	// input - ifstream - when we want to show it
	// string food;
	// ifstream archivo("food.txt");
	// archivo >> food;
	// cout << "You ate: " << food << endl;
	// archivo.close();


	vector<string> comidas;

	ifstream archivo("food.txt", ios::trunc);

	string comida;
	while (archivo >> comida)
	{
		comidas.push_back(comida);
	}


	

	return 0;
}