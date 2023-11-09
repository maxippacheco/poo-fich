// Ejercicio 1 (25 pts) Un archivo de textos INFORME.TXT contiene un reporte de
// funcionamiento de un paquete de software y se desea modificar el texto de forma de
// reemplazar la palabra “paquete” por la palabra “aplicación”. Es posible que en una
// línea aparezca más de una vez la palabra “paquete”. No hay palabras cortadas en el
// texto
#include<iostream>
#include<fstream>
using namespace std;

int main(){

	fstream archivo("INFORME.TXT");

	if(!archivo.is_open())
	{
		cout << "No se pudo abrir el archivo" << endl;
		return 1;
	}

	string palabra = "paquete";

	string paquete;
	while (getline(archivo, paquete))
	{
		size_t pos = paquete.find(palabra);
		if( pos != -1){
			paquete.replace(pos, paquete.size(), "aplicacion");
		}
	}
	


	return 0;
}