// En un archivo de texto llamado lista.txt, como el que se
// muestra a la derecha, se encuentran los nombres y notas
// de los alumnos de una comisión de Programación
// Orientada a Objetos.
// TODO a) Escriba una función modificar que reciba el nombre
// de un alumno y dos notas, y modifique el archivo
// reemplazando las dos notas de ese alumno.
// TODO b) Escriba una función que lea la lista del archivo y genere otro archivo de texto
// promedios.txt con una tabla donde cada línea posea el nombre, el promedio,
// y la condición final de cada uno de los alumnos.
// *Ayuda: utilice manipuladores de flujo (setw, right, left, fixed, setprecision) para dar
// *formato a la tabla del archivo que se genera en b).

#include<iostream>
#include<fstream>

using namespace std;

void modificar(string nombre, int nuevaNota1, int nuevaNota2) {
    ifstream entrada("lista.txt");
    ofstream temp("temp.txt");

    string nombreAlumno;
    int nota1, nota2;

    while (entrada >> nombreAlumno) {
			temp << nombreAlumno << endl;
			entrada >> nota1 >> nota2;
			if (nombreAlumno == nombre) {
				temp << nuevaNota1 << " " << nuevaNota2 << endl;
			} else {
				temp << nota1 << " " << nota2 << endl;
			}
    }

  entrada.close();
  temp.close();

  remove("lista.txt");
  rename("temp.txt", "lista.txt");
}

int main(){

	ifstream archivo("lista.txt");

	if(!archivo.is_open()){
		cout << "El archivo no se ha podido abrir correctamente" << endl;
		return 1;
	}

	modificar("Lopez", 95.0, 20.0);



	return 0;
}