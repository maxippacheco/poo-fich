// Desarrolle una clase templatizada llamada ManejadorArchivo que posea métodos
// y atributos para manipular un archivo binario que contenga registros del tipo de
// dato especificado por el parámetro. La clase debe poseer métodos para:
// a. Abrir un archivo binario y cargar los registros en memoria.
// b. Obtener el registro en una posición especificada por el usuario.
// c. Modificar el registro en una posición determinada.
// d. Actualizar la información del archivo con los cambios.
// e. Utilice la clase desde un programa cliente para leer los registros escritos en
// el archivo binario generado en el ejercicio 6.5.
#include<iostream>
#include<fstream>
#include<vector>
using namespace std;

struct Par{
	int m_int;
	float m_float;
};

template<typename T>
class ManejadorArchivo{
	fstream manejador_file;
	vector<T>	manejador_vector;
	string manejador_txt;

	public:
		ManejadorArchivo(string nombre_archivo): manejador_txt(nombre_archivo){
			manejador_file.open(manejador_txt, ios::binary|ios::in|ios::out|ios::ate);
			
			int size_file = (int)manejador_file.tellg()/sizeof(T);
			manejador_file.seekg(0);

			for (size_t i = 0; i < size_file; i++)
			{
				T aux;
				manejador_file.read(reinterpret_cast<char*>(&aux), sizeof(aux));
				manejador_vector.push_back(aux);
			}
			
			manejador_file.close();
		}

		T ver_registro(int i){
			return manejador_vector[i - 1];
		}

		void modificar_registro(int i, T dato){
			manejador_vector[i - 1] = dato;
		}

		void actualizar(){
			manejador_file.open(manejador_txt, ios::binary|ios::trunc|ios::out);

			for (size_t i = 0; i < manejador_vector.size(); i++)
			{
				manejador_file.write(reinterpret_cast<char*>(&manejador_vector[i]), sizeof(T));
			}

			manejador_file.close();
			
		}
};

int main(int argc, char const *argv[])
{

	ManejadorArchivo<Par> archi1("grupo.dat");
	Par pos = archi1.ver_registro(9);
			cout << pos.m_int << " " << pos.m_float << endl;

	archi1.modificar_registro(10,{777,7.77});
	archi1.actualizar();

	cout << archi1.ver_registro(10).m_int << " " << archi1.ver_registro(10).m_float << endl;

	return 0;
}
