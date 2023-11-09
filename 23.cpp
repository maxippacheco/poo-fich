// Se dispone de una archivo de texto INFORME.TXT con un reporte técnico de una empresa. Diseñe una
// clase que acceda al archivo y tenga método para realizar lo siguiente: a) reemplazar la palabra "la
// aplicación" en el texto por la palabra "el software"; b) Determinar si el informe se excedió en la cantidad de
// palabras (debe tener menos de 700 palabras); c) Verificar si después de cada punto se inicia la nueva
// frase con mayúsculas, si eso no ocurre corregirlo.
#include<iostream>
#include<fstream>
#include<vector>
using namespace std;

class InformeManager{
	string nombre_archivo;
	public:
		InformeManager(string nombre_archivo): nombre_archivo(nombre_archivo){};
		void reemplazar_palabra(){
			fstream informe(nombre_archivo);

			string archivo_completo, linea;
			while (getline(informe, linea))
			{
				archivo_completo += linea + "\n";
			}

			size_t posicion_palabra = archivo_completo.find("la aplicacion");

			string palabra_replace = "el software";
			while (posicion_palabra != string::npos)
			{
				archivo_completo.replace(posicion_palabra, 13, palabra_replace);
				archivo_completo.find("el software", palabra_replace.length() + posicion_palabra);
			}

			informe.close();
      informe.open(nombre_archivo, fstream::out | fstream::trunc);
			informe << archivo_completo;
		}

		// cuenta caracteres no palabras
		bool isValido(){
			fstream informe(nombre_archivo);

			string archivo_completo, linea;
			while (getline(informe, linea))
			{
				archivo_completo += linea + "\n";
			}

			if( archivo_completo.length() > 700){
				return false;
			}

			return true;
		}
};

int main()
{
	return 0;
}