#include<iostream>
using namespace std;

int* copiar_arr(int *begin, int *end, int m){
	int *new_arr = new int[(end - begin) * m];

  int *ptr_nuevo = new_arr;

    for (int *ptr = begin; ptr != end; ++ptr) {
      for (int i = 0; i < m; ++i) {
        *ptr_nuevo = *ptr;
       	++ptr_nuevo;
      }
    }


	return new_arr;
}

int main(){
    int arr[] = {1, 2, 3, 4, 5};
    int m = 3;

    int *inicio = arr;
    int *fin = arr + sizeof(arr) / sizeof(int);

    int *new_arr = copiar_arr(inicio, fin, m);

    // Imprimir el nuevo arreglo
    for (int i = 0; i < m * (fin - inicio); ++i) {
      cout << new_arr[i] << " ";
    }
    cout << endl;

    // Liberar la memoria del nuevo arreglo
    delete[] new_arr;


	return 0;
}