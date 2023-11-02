#include<iostream>
#include<vector>
using namespace std;

struct QA{
	string pregunta;
	string respuesta;
};

class IA{
	string nombre;
	public:
		IA( string nombre): nombre(nombre){};
		virtual string ObtenerRespuesta(QA preg_resp) = 0;
};

class Memory: public IA{
	vector<QA> Qa;
	public:
		Memory(): IA("Memory"){};

		bool AgregarQa(QA preg_resp){
			for (size_t i = 0; i < Qa.size(); i++)
			{
				if( Qa[i].pregunta == preg_resp.pregunta){
					return false;
					break;
				}
			}

			Qa.push_back(preg_resp);
			return true;
			
		}

		string ObtenerRespuesta(QA preg_resp) override{
			for (size_t i = 0; i < Qa.size(); i++)
			{
				if( Qa[i].pregunta == preg_resp.pregunta){
					return preg_resp.respuesta;
					break;
				}
			}

			return "";
		};
};

class Multivac: public IA{
	public:
		Multivac(): IA("Multivac"){};

		string ObtenerRespuesta(QA preg_resp) override{
			return "Datos insuficientes para una respuesta esclarecedora";
		}
};

void PreguntasyRespuestas(IA& ia, QA){
	string pregunta, respuesta;


	cout << "Ingrese una pregunta: " << endl;
	getline(cin, pregunta);
	cin.ignore();

	while (pregunta != "Salir")
	{
		cout << ia.ObtenerRespuesta({pregunta, respuesta}) << endl;
		
		cout << "Ingrese una pregunta: " << endl;
		getline(cin, pregunta);
		cin.ignore();

	}
	
}

int main(){

	Memory mem;

	QA preg_resp = { "Como estas?", "Muy bien" };

	mem.AgregarQa(preg_resp);

	// cout << mem.ObtenerRespuesta(preg_resp) << endl;

	// Multivac multi;
	// cout << multi.ObtenerRespuesta(preg_resp) << endl;

	PreguntasyRespuestas(mem, preg_resp);


	return 0;
}