// Un archivo binario registra información sobre exámenes en una facultad. El archivo se escribió utilizando
// un struct Entrada { int nro_acta, fecha, turno, cod_materia, dni_alumno, nota; }; En el
// archivo hay información de todos los alumnos y de todas las materias. Hay una entrada en el archivo para
// cada alumno que se inscribe a cada examen final (si un alumno no se presenta, el campo nota queda en
// -1 para indicar el ausente). Además hay entradas adicionales, porque como las actas no se pueden
// modificar luego de cerradas; cuando un docente se equivoca al pasar una nota, lo que se hace es generar
// una nueva acta "rectificativa". De este modo, si hubo una equivocación, el archivo tendrá dos entradas
// para el mismo alumno, misma materia, y mismo turno, pero con diferente nota (la 2da es la que vale).
// Por otro lado, un archivo de texto tiene los nombres de las materias. En cada línea hay un número entero
// (el código), luego un espacio, y luego el nombre de una materia. Se pretende armar la historia académica
// de un alumno (lista de exámenes en los que sí se presentó):
// 1. Escriba una función que dado un dni, abra el archivo binario y retorne todas las entradas de ese
// alumno.
// 2. Escriba otra función que recorra la lista de entradas y elimine de la misma las entradas
// correspondientes a "ausentes" (nota==-1) y las entradas correspondientes a equivocaciones (que
// luego fueron rectificadas).
// 3. Escriba una función que cargue los datos de las materias (códigos y nombres) y los retorne en algún
// contenedor stl.
// 4. Escriba un programa cliente que haciendo uso de las 3 funciones anteriores, muestre la historia
// académica. Por cada examen del alumno debe mostrar la fecha, el turno, el nombre de la materia y
// la nota.

#include<iostream>
using namespace std;

struct Entrada { int nro_acta, fecha, turno, cod_materia, dni_alumno, nota; };

int main()
{
	
	return 0;
}
