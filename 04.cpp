// getters and setters
#include<iostream>
using namespace std;

class Punto{
	private:
		int x, y;
	public:
		Punto();
		void setPunto(int,int);
		int getPuntoX();
		int getPuntoY();
};

Punto::Punto(){};

void Punto::setPunto(int _x, int _y){
	x = _x;
	y = _y;
};

int Punto::getPuntoX(){ return x; }
int Punto::getPuntoY(){ return y; }

int main(){

	Punto p1;
	p1.setPunto(1,2);

	cout << p1.getPuntoX() << "," << p1.getPuntoY() << endl;

	return 0;
}