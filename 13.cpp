// Ejercicio 2 (30 pts) Escriba una clase llamada ManejadorDeTexto que contenga: a)
// un constructor que reciba el nombre de un archivo de texto y almacene todo el
// contenido del mismo en un objeto de tipo string que debe ser el único atributo de la
// clase. Ademas debe tener métodos para: b) reemplazar todas las ocurrencias de una
// subcadena por otra (ambas cadenas se reciben como parámetros); c) guardar el texto
// modificado en un archivo con un nombre que el usuario indique como parámetro; d)
// convertir todo el texto a mayuscula o minuscula según el valor de un argumento que
// reciba. Diseñar e implementar solo la clase y sus métodos.

#include<iostream>
#include<fstream>
#include<string>
#include<algorithm>

using namespace std;

class ManejadorDeTexto{
	string almacenador, fname;
	public:
		ManejadorDeTexto(string fname): fname(fname){
			fstream archivo(fname);

			string linea;
			while (getline(archivo, linea))
			{
				almacenador += linea + "\n";
			}
		}

		void reemplazar_ocurrencias(string palabra_a_reemplazar, string palabra_nueva){
			size_t pos = almacenador.find(palabra_a_reemplazar);

			while(pos != string::npos){
				almacenador.replace(pos, palabra_a_reemplazar.length(), palabra_nueva);
				pos = almacenador.find(palabra_a_reemplazar, pos + palabra_nueva.length());
			}
		}

		void guardar_en_archivo(){
			ofstream archivo_salida(fname, ios::trunc);

			archivo_salida << this->almacenador;
		}

		void convertirMayusMin(bool to_min){
        if (to_min) {
          transform(almacenador.begin(), almacenador.end(), almacenador.begin(), ::tolower);
        } else {
          transform(almacenador.begin(), almacenador.end(), almacenador.begin(), ::toupper);
        }
		}

};

int main()
{
	
	return 0;
}
