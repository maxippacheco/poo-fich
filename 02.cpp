// Sobrecarga de constructores

#include<iostream>
using namespace std;

class Fecha{
	private:
		int dia, mes, anio;
	public:
		Fecha(int,int,int);
		Fecha(long);
		void mostrarFecha();
};

Fecha::Fecha(int _dia, int _mes, int _anio){
	dia = _dia;
	mes = _mes;
	anio = _anio;
}

Fecha::Fecha(long fecha){
	anio = int(fecha/10000);
	mes = int((fecha-anio*10000)/100);
	dia = int((fecha-anio*10000-mes*100));
}

void Fecha::mostrarFecha(){
	cout << dia << "/" << mes << "/" << anio << endl;
}

int main(){

	Fecha hoy(27, 8, 2023);
	Fecha ayer(20230811);

	hoy.mostrarFecha();
	ayer.mostrarFecha();

	return 0;
}