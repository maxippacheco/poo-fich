// Ejercicio 2 [25 pts] Se dispone de un archivo de textos USUARIOS.TXT donde cada línea contiene el
// código, sector, el apellido y el nombre . El código es un número entero y el sector es una sola palabra, y
// cada usuario tiene un solo nombre y apellido separado por un espacio en blanco. Escriba una clase que
// posea entre sus métodos: a) la función GeneraPassword(), encargada de crear un password
// concatenando el sector con la primer letra del nombre y el apellido completo de cada usuario y otra
// función CreaBinario( ) que genere un archivo binario que contenga los datos referentes al código,
// nombre, apellido y password generado de cada usuario. Programa los métodos adicionales que
// considere necesarios.

#include<iostream>
#include<fstream>
#include<vector>
using namespace std;

class Usuario{
	int codigo;
	string apellido, sector, nombre;
	public:
		Usuario(int codigo, string nombre, string apellido, string sector): codigo(codigo), nombre(nombre), apellido(apellido), sector(sector){};

		string GeneraPassword() const{
			return this->sector + this->nombre.at(0) + this->apellido;
		}

		int getCodigo(){ return this->codigo; }
		string getNombre(){ return this->nombre; }
		string getApellido(){ return this->apellido; }
		string getSector(){ return this->sector; }
};

class UsuarioManager{
	vector<Usuario> usuarios;

	public:
		UsuarioManager(){
			ifstream archivo("usuarios.txt");

			if( archivo.is_open() ){
				int codigo; string nombre, apellido, sector;

				while(archivo >> nombre >> apellido >> sector >> codigo)
				{
					Usuario usuario(codigo, nombre, apellido, sector);
					usuarios.push_back(usuario);
				}
				archivo.close();
			} else{
				cout << "Error: no se puede abrir el archivo";
			}

		}

		void CreaBinario(){
			ofstream archivo_binario("usuarios.bin", ios::binary);

			if( archivo_binario.is_open() ){
				for( Usuario &usuario: usuarios){
					int codigo = usuario.getCodigo();
					string nombre = usuario.getNombre();
					string apellido = usuario.getApellido();
					string sector = usuario.getSector();

          archivo_binario.write(reinterpret_cast<char*>(&codigo), sizeof(codigo));
          archivo_binario.write(reinterpret_cast<char*>(&apellido), sizeof(apellido));
          archivo_binario.write(reinterpret_cast<char*>(&nombre), sizeof(nombre));
          archivo_binario.write(reinterpret_cast<char*>(&sector), sizeof(sector));
				}
				archivo_binario.close();
			}else{
				cout << "No se pudo abrir el archivo" << endl;
			}

		}
};

int main(){

  UsuarioManager manager;
  manager.CreaBinario();


	return 0;
}