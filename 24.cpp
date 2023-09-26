// Ejercicio 3 (30 pts) a) Escriba una clase Promocion para representar una promoción de una tienda
// virtual. La clase debe poder guardar una descripción de la promoción, y tener además un método virtual
// Aplicar(...) que reciba un struct de tipo Compra como el del recuadro y retorne un float con el monto que
// el cliente se ahorra gracias a esa promoción, o cero si la promoción no es aplicable a esa compra.
// b) Implemente dos herencias, Promo3x2 y Promo1000. La primera, cuya descripción será "3x2 en todas
// las marcas" aplica cuando un cliente compra 3 o más unidades de un mismo producto; y en ese caso
// por cada 3 unidades, se le descuenta una. La segunda, cuya descripción será "5% en compras
// superiores a $1000" aplica cuando la compra es mayor a $1000, y en ese caso se le descuenta un 5%.
// c) Implemente una función que reciba un vector de Compras y dos Promociones, y retorne un vector de
// Descuentos. La función debe intentar aplicar cada promoción a cada compra, y generar un vector con
// tods los descuentos de aquellas que efectivamente apliquen.


#include<vector>
#include<iostream>
using namespace std;

struct Compra {
	string codigo_producto;
	float precio_unitario;
	int cantidad;
};
struct Descuento {
	string descripcion;
	float monto;
};

class Promocion{
	string descripcion;
	public:
		Promocion(string descripcion): descripcion(descripcion){};
		virtual float Aplicar(Compra& compra) = 0;
		string GetDescripcion(){
			return this->descripcion;
		}
};

class Promo3x2: public Promocion{
	public:
		Promo3x2(): Promocion("Promo 3X2"){};
		float Aplicar(Compra& compra) override{
      if (compra.cantidad >= 3) {
        int unidadesGratis = compra.cantidad / 3;
        return unidadesGratis * compra.precio_unitario;
      }

			return 0.0;
		}

};

class Promo1000: public Promocion{
	public:
		Promo1000(): Promocion("Promo 1000"){};
		float Aplicar(Compra& compra) override{
			float cantidad_total = compra.precio_unitario * compra.cantidad;
			if(cantidad_total > 1000){
				return cantidad_total * 0.05;
			}

			return 0.0;
		};
};

vector<Descuento> AplicarPromociones(vector<Compra>& compras, Promocion& promocion1, Promocion& promocion2){
	vector<Descuento> descuentos;
	for (const Compra& compra : compras) {
    float descuento1 = promocion1.Aplicar(compra);
    float descuento2 = promocion2.Aplicar(compra);

    if (descuento1 > 0.0) {
      descuentos.push_back({promocion1.GetDescripcion(), descuento1});
    }
  	if (descuento2 > 0.0) {
      descuentos.push_back({promocion2.GetDescripcion(), descuento2});
			}
    return descuentos;

	}
};

int main(){


	return 0;
}