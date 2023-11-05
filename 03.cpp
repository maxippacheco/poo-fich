// Escriba un programa que genere un archivo binario con una lista de 100 enteros
// ordenados de forma creciente (por ejemplo: 0, 5, 10, 15, 20, 25...). Luego escriba
// otro programa que permita insertar (no reemplazar) un nuevo dato de tipo entero,
// ingresado por el usuario, en el archivo manteniendo el orden creciente. Evite utilizar
// vectores auxiliare
#include<iostream>
#include<fstream>

using namespace std;

int main() {
    ofstream archivo("lista.bin", ios::binary | ios::trunc);

    if (!archivo) {
        cout << "No se puede abrir el archivo para su escritura" << endl;
        return 1;
    }

    for (int i = 0; i < 100; i++) {
        int n = i * 5;
        archivo.write(reinterpret_cast<char*>(&n), sizeof(n));
    }

    archivo.close();

    int dato_user;
    cout << "Ingrese un numero: " << endl;
    cin >> dato_user;

    fstream archivo2("lista.bin", ios::binary | ios::in | ios::out | ios::ate);
    int pos;
    int cant = archivo2.tellg() / sizeof(int);
    archivo2.seekg(0);

    int aux;
    archivo2.read(reinterpret_cast<char*>(&aux), sizeof(aux));

    while (dato_user > aux) {
        archivo2.read(reinterpret_cast<char*>(&aux), sizeof(aux));
    }

    pos = archivo2.tellg() - static_cast<streampos>(sizeof(int));

    cout << "Quedó en posición: " << pos << endl;

    for (int i = cant; i >= pos / sizeof(int); i--) {
        int dato;

        archivo2.seekg(i * sizeof(dato), ios::beg);
        archivo2.read(reinterpret_cast<char*>(&dato), sizeof(dato));

        archivo2.seekp((i + 1) * sizeof(dato), ios::beg);
        archivo2.write(reinterpret_cast<char*>(&dato), sizeof(dato));
    }

    archivo2.seekp(pos);
    archivo2.write(reinterpret_cast<char*>(&dato_user), sizeof(dato_user));

    for (int i = 0; i < cant + 1; i++) {
        int dato;
        archivo2.seekg(i * sizeof(dato));
        archivo2.read(reinterpret_cast<char*>(&dato), sizeof(dato));
        cout << dato << endl;
    }

    archivo2.close();

    return 0;
}