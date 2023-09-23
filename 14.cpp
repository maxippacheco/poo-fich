// Ejercicio 1 (25 pts) Escriba una clase Vector3D para representar un vector de 3 componentes {x;y;z}.
// Implemente sobrecargas para los operadores [ ], +, == y *. El operador [ ] debe permitir además
// modificar las componentes. Nota: dados dos vectores {x1;y1;z1} y {x2;y2;z2}, la suma es un vector
// {x1+x2 ; y1+y2 ; z1+z2}, y el producto, un escalar x1*x2+y1*y2+z1*z2.

#include<iostream>
using namespace std;

class Vector3D{
	float x, y, z;

	public:
		Vector3D(float x, float y, float z): x(x), y(y), z(z){};

		Vector3D operator+(const Vector3D& vector2){
			return Vector3D(this->x + vector2.x, this->y + vector2.y, this->z + vector2.z);
		};

		Vector3D operator*(const Vector3D& vector2) const {
			return Vector3D(this->x * vector2.x, this->y * vector2.y, this->z *  vector2.z);
		};

		// El problema en este caso es que la función operator[] de la clase Vector3D está declarada como retornando un 
		// float en lugar de una referencia a float. 
		// Para permitir la modificación de los elementos, debe retornar una referencia.
		float& operator[](int index) {
        if (index == 0) return this->x;
        if (index == 1) return this->y;
        if (index == 2) return this->z;
        throw out_of_range("Índice fuera de rango");
		};

		void getVector(){
			cout << "X: " << this->x << " Y: " << this->y << " Z: " << this->z << endl;
		}
};

int main(){

	Vector3D v1(3,3,3), v2(5,5,5);

	Vector3D suma = v1 + v2;

	suma.getVector();

	v1[0] = 30;

	v1.getVector();


	return 0;
}