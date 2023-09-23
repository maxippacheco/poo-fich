// Ejercicio 1 (pts) Implemente una clase Complejo para representar un número complejo. La clase debe
// tener: 
//  a) un constructor que no reciba nada y la inicialice como 0+0i, 
//  b) un constructor que reciba las partes real e imaginaria, 
//  c) métodos para consultar cada parte, 
//  d) sobrecargas para los operadores + y -, 
//  e) sobrecargas para los operadores == y !=, y 
//  f) una sobrecarga para poder mostrar una instancia “c” de la clase mediate “cout << c”.

class Complejo{
	int real, compleja;
	public:
		Complejo(){
			this->real = 0;
			this->compleja = 0;
		};
		Complejo(int real, int compleja): real(real), compleja(compleja){};

		Complejo operator+( const Complejo& comp){
			return Complejo(this->real + comp.real, this->compleja + comp.compleja);
		}
};


int main(){

	return 0;
}