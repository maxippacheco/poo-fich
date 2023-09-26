// Ejercicio 1 (25 pts) a) Escriba una función que reciba 3 punteros de tipo float, el primero y segundo
// indican el comienzo y final de los elementos que deben ser copiados de un arreglo hacia otro. El
// comienzo del vector destino es apuntado por el tercer puntero recibido. b) Haga uso de la función desde
// un programa cliente.

#include<iostream>
using namespace std;

void copiarArreglo(float *inicio, float *fin, float *arr_destino){
	while (inicio <= fin)
	{
		*arr_destino = *inicio;
		inicio++;
		arr_destino++;
	}
	
}

int main(){
	// Definir dos arreglos de ejemplo
	float arregloOrigen[] = {1.0, 2.0, 3.0, 4.0, 5.0};
	float arregloDestino[5]; // El arreglo de destino debe ser del mismo tamaño

	// Llamar a la función para copiar elementos
	float* inicio = &arregloOrigen[1];  // Puntero al segundo elemento
	float* fin = &arregloOrigen[3];    // Puntero al cuarto elemento
	float* destino = arregloDestino;   // Puntero al inicio del arreglo de destino

	copiarArreglo(inicio, fin, destino);

  printf("Arreglo de destino después de la copia:\n");
  for (int i = 0; i < 5; i++) {
      printf("%.2f ", arregloDestino[i]);
  }
  printf("\n");


	return 0;
}