// Ejercicio 2 (25pts) Diseñe una clase genérica llamada Calculos que tenga como
// atributos un entero n (tamaño del vector), un vector de n elementos genéricos y 2
// datos de mismo tipo genérico que los elementos del vector. La clase debe tener un
// constructor, un método llamado dosmax(..) que obtenga los 2 datos mayores del
// vector y métodos que considere necesarios. En un programa cliente instancie la clase
// para una lista de flotantes y para una lista de strings que deben leerse como datos.
#include<iostream>
#include<vector>
using namespace std;

template<typename T>
class Calculos{
	int n;
	vector<T> elementos;
	T element1, element2;
	
	public:
		Calculos(int n, vector<T> &elementos, T element1, T element2): n(n), elementos(elementos), element1(element1), element2(element2) {}
		pair<T, T> dosmax(){
			T max1, max2;
			max1 = max2 = elementos[0];

			for (size_t i = 0; i < this->elementos.size(); i++)
			{

				if(elementos[i] > max1)
				{
					max2 = max1;
					max1 = elementos[i];
				}else if(elementos[i] > max2 and elementos[i] != max1){
					max2 = elementos[i];
				}
			}

			pair<T, T> maximo;
			maximo.first = max1;
			maximo.second = max2;

			return maximo;			
		}
};

int main(){
	vector<float> elementosFloat = {3.14, 2.71, 1.618, 4.2};
	Calculos<float> calcFloat(elementosFloat.size(), elementosFloat, 0.0, 0.0);
	pair<float, float> maximosFloat = calcFloat.dosmax();
	cout << "Los dos valores más grandes en la lista de flotantes son: " << maximosFloat.first << " y " << maximosFloat.second << endl;

	vector<string> elementosString = {"apple", "banana", "cherry", "date"};
	Calculos<string> calcString(elementosString.size(), elementosString, "", "");
	pair<string, string> maximosString = calcString.dosmax();
	cout << "Los dos valores más grandes en la lista de strings son: " << maximosString.first << " y " << maximosString.second << endl;

	return 0;
}