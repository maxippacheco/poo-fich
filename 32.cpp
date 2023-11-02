
#include<iostream>
using namespace std;

class Color{
	float rojo, azul, verde;

	public:
		Color(float rojo, float azul, float verde): rojo(rojo), azul(azul), verde(verde){
			this->Normalizar();
		}

		float VerRojo() const{
			return this->rojo;
		}

		float VerAzul() const{
			return this->azul;
		}

		float VerVerde() const{
			return this->verde;
		}

		Color operator+( const Color& color){
			this->azul = this->azul + color.azul;
			this->rojo = this->rojo + color.rojo;
			this->verde = this->verde + color.verde;

			this->Normalizar();

			return *this;
		}

		void Normalizar(){
			if(this->azul > 1.0f){
				this->azul = 1.0f;
			}else if( this->rojo > 1.0f){
				this->rojo = 1.0f;
			}else if(this->verde > 1.0f){
				this->verde = 1.0f;
			}
		}
};

ostream& operator<<(ostream& os, const Color& color) {
    os << "R: " << color.VerRojo() << " G: " << color.VerVerde() << " B: " << color.VerAzul() << endl;
	return os;
};

int main(){
	Color color1(1.0f, 1.2f, 3.0f), color2(1.0f, 0.8f, 0.1f);

	color1.Normalizar();

	cout << color1;
	return 0;
}