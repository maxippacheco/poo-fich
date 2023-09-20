// 3) Escriba una clase llamada Fecha con los atributos necesarios para definir una fecha (día, mes, año).
// Proponga, además de los métodos que considere necesarios, una sobrecarga del operador <= que
// permite comparar 2 fechas y una sobrecarga del operador [] para obtener el día, mes y año con los
// valores 1, 2 y 3 respectivamente. Además, sobrecargue el operador >> para poder leer una fecha desde
// la consola. Finalmente cree un programa cliente que utilice las sobrecargas implementadas.

#include<iostream>
using namespace std;

class Fecha{
	int dia, mes, anio;

	public:
		Fecha(int dia, int mes, int anio): anio(anio), mes(mes), dia(dia){};

		void show_fecha(){
			cout << "Dia: " << this->dia << " Mes: " << this->mes << " Anio " << this->anio << endl;
		};

		Fecha operator<=(const Fecha &fecha2){
			Fecha aux = *this;
			if( aux.anio < fecha2.anio ) {
				cout << fecha2.anio - aux.anio << endl;
			}else{
				cout << aux.anio - fecha2.anio << endl;
			}

			cout << aux.mes - fecha2.mes << endl;
			cout << aux.dia - fecha2.dia << endl;

			return aux;
		};

		Fecha operator[](int index){

		};
};

int main(){

	Fecha f1(4, 3, 20), f2(2, 2, 10), f3(1,1,1);

	f1 <= f2;


	return 0;
}