#include<iostream>
#include<vector>
using namespace std;
 

struct Evaluacion { string tipo; int nota; };

class Asignatura{
	protected:
		string nombre;
		int nro_cuatrimestre;
		vector<string> unidades;

	public:
		Asignatura(string nombre, int nro_cuatrimestre): nombre(nombre), nro_cuatrimestre(nro_cuatrimestre) {};
		
		string VerNombre() const{ return this->nombre; };
		
		int VerCuatrimestre() const{ return this->nro_cuatrimestre; };

		void AgregarUnidad( string unidad){
			this->unidades.push_back(unidad);
		}

		vector<string> ObtenerUnidades() const{
			return this->unidades;
		}

		virtual string CalcularCondicion() = 0;

};

// b) Implemente, reutilizando la clase Asignatura, las clases FuPro y CompGraf para representar las
// materias “Fundamentos de Programación” y “Computación Gráfica” respectivamente. Estas clases
// deben tener un método CalcularCondicion que reciba un vector de elementos de tipo struct
// Evaluacion { string tipo; int nota; } con los resultados de un alumno. El método debe verificar que los
// tipos de evaluaciones sean los correctos (si no lo son, deberá retornar "error"), y calcular su
// condición final en base a sus notas la condición final del alumno.
//    - Para FuPro, las evaluaciones deben ser de tipos "parcial1" y "parcial2"; y la condición final será
// "promocionado" si el promedio llega a 70 y la nota mínima no es menor de 60, "regular" si la nota
// mínima no baja de 40, o "libre" en caso contrario.
//    - Para CompGraf, las evaluaciones deben ser de tipos "tp1" y "tp2", "tpFinal", y "parcial". La
// condición final será "promocionado" si todos los tps están aprobados (nota 60 o superior) y el parcial
// tiene 65 o más; "regular" si los tps están aprobados pero el parcial no, o "libre" si algún tp está
// desaprobado.s

class FuPro: public Asignatura{
	Evaluacion parcial1, parcial2;

	public:
		FuPro(const Evaluacion& parcial1, const Evaluacion& parcial2): parcial1(parcial1), parcial2(parcial2), Asignatura("Fundamentos de Programacion", 1){};
		string CalcularCondicion() override{
			float condicion = (this->parcial1.nota + this->parcial2.nota)/2;
			if( condicion >= 70){
				return "Promocionado";
			}else if( condicion >= 40) {
				return "Regular";
			}else{
				return "Libre";
			}
		}
};

class CompGrafica: public Asignatura{
	Evaluacion tp1, tp2, tpFinal, parcial;

	public:
		CompGrafica(const Evaluacion& tp1, const Evaluacion& tp2, const Evaluacion& tpFinal, const Evaluacion& parcial): 
		tp1(tp1), tp2(tp2), tpFinal(tpFinal), parcial(parcial), Asignatura("Comp Grafica", 2){};
		
		string CalcularCondicion() override{
			float condicion_tps = (this->tpFinal.nota + this->tp1.nota + this->tp2.nota)/3;
			
			if( condicion_tps >= 60 && this->parcial.nota >= 65){
				return "Promocionado";
			}else if( condicion_tps >= 60 ) {
				return "Regular";
			}else{
				return "Libre";
			}
		}
};


// c) Escriba una función “testCalcularCondicion” para probar el método CalcularCondicion. La función
// debe poder recibir cualquier Materia, permitir al usuario ingresar un vector de Evaluaciones y mostrar
// la condición resultante
void testCalcularCondicion(Asignatura& materia, vector<Evaluacion> evaluaciones) {
    string condicion = materia.CalcularCondicion();
    cout << "Condición final para " << condicion << ": " << condicion << std::endl;
}

int main() {

    vector<Evaluacion> evaluaciones_fupro = {
        {"parcial1", 75},
        {"parcial2", 55}
    };
    FuPro fupro(evaluaciones_fupro[0], evaluaciones_fupro[1]);

  	vector<Evaluacion> evaluaciones_compgraf = {
        {"tp1", 70},
        {"tp2", 75},
        {"tpFinal", 80},
        {"parcial", 70}
    };
    CompGrafica compgraf(evaluaciones_compgraf[0], evaluaciones_compgraf[1], evaluaciones_compgraf[2], evaluaciones_compgraf[3]);

    testCalcularCondicion(fupro, evaluaciones_fupro);
    testCalcularCondicion(compgraf, evaluaciones_compgraf);

    return 0;
}






