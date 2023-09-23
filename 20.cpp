// Ejercicio 3 (30 pts) a) Escriba una clase Jugador para representar un jugador en un juego de PiedraPapel-Tijeras. 
// La clase debe poder guardar el nombre del jugador, y tener además un método virtual
// Jugar() que retorne un entero. El número que retorna puede ser 1 (piedra), 2 (papel) o 3 (tijeras), e
// indica la jugada que realiza el jugador en una partida.
// b) Implemente dos herencias, JugadorIA y JugadorHumano. La primera debe elegir su jugada al azar, y
// tener siempre por nombre de jugador "HAL 9000". La segunda debe solicitar al usuario que elija la
// jugada que quiera (nota: deberá utilizar cin/cout dentro de esta segunda clase), y recibir el nombre del
// humano como argumento en su constructor.
// c) Implemente una función que reciba dos Jugadores, simule una partida, y retorne el nombre del
// ganador, o la palabra "empate".

// El error que estás viendo indica que aún tienes la función Jugar() en la clase JugadorIA como una función virtual pura (marcada con = 0). 
// Esto hace que la clase JugadorIA sea abstracta y no se puedan crear objetos de ella directamente.

// Para corregirlo, debes eliminar la declaración virtual y = 0 de la función Jugar() en la clase JugadorIA, 
// ya que en JugadorIA estás proporcionando una implementación concreta de esta función. 
// La función Jugar() en JugadorIA ya no debe ser virtual. Aquí tienes la corrección:

#include<iostream>
using namespace std;

enum Jugadas: int {
	Piedra = 1,
	Papel = 2,
	Tijera = 3,
};

class Jugador{
	protected:
		string nombre;
	public:
		Jugador(string nombre): nombre(nombre){};
		// virtual Jugadas Jugar() {
		// 	return Piedra;
		// };
		string VerNombre() const {
			return this->nombre;
		}
};

class JugadorIA: public Jugador{
	public:
		JugadorIA(): Jugador("HAL 9000"){};
    Jugadas Jugar() const {
			  // Genera un número aleatorio entre 1 y 3 (inclusive)
        int numeroAleatorio = rand() % 3 + 1;

        // Asigna el número aleatorio a una jugada
        Jugadas jugada;
        if (numeroAleatorio == 1) {
            jugada = Piedra;
        } else if (numeroAleatorio == 2) {
            jugada = Papel;
        } else {
            jugada = Tijera;
        }

        return jugada;
    };
};

class JugadorHumano: public Jugador{
	public:
		JugadorHumano(string nombre): Jugador(nombre){};
    Jugadas Jugar() const {
        int eleccion;
        cout << "Elige tu jugada (1: Piedra, 2: Papel, 3: Tijera): ";
        cin >> eleccion;
        return static_cast<Jugadas>(eleccion);
    }

};

string partida(const JugadorHumano& jugador, const JugadorIA& jugadorIa){
	Jugadas jugada1 = jugador.Jugar();
	Jugadas jugada2 = jugadorIa.Jugar();

	if (jugada1 == jugada2) {
		return "empate";
	} else if ((jugada1 == Piedra && jugada2 == Tijera) ||
		(jugada1 == Papel && jugada2 == Piedra) ||
		(jugada1 == Tijera && jugada2 == Papel)) {
		return "El jugador " + jugador.VerNombre() + " ha ganado";
	} else {
		return "El jugador " + jugadorIa.VerNombre() + " ha ganado";
	}
}

int main(){

	JugadorIA ia;
	JugadorHumano jugador("Maxi");
	cout << partida(jugador, ia) << endl;

	
	return 0;
}
