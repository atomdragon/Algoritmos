#include "Header.h"

using namespace std;

void generar_datos(int a, int b, int rep)
{
	for (int i = 0; i < rep; i++)
	{
		std::cout << rand() % (a - b) << std::endl;
	}
}

void lecturaDatosDeArchivo()
{
	//ofstream arch_text("Archivo.txt", ios::in);
	string nombre_archivo = "Archivo.txt"; //Se coloca el nombre del archivo
	ifstream archIN; //Declaracion de una variable ifstream
	archIN.open(nombre_archivo, ios::in); //Apertura

	if (!archIN.is_open())
	{
		std::cout << "Error: No se pudo abrir el archivo !!!" << std::endl;
		exit(1);
	}

	string linea;
	char delimitador = '|';

	// Encabezado: Leemos la primer linea para descartarla, pues es el encabezado
	//getline(archIN, linea);

	// Contenido: Leemos todas las l neas
	while (getline(archIN, linea))
	{
		stringstream stream(linea); // Convertir la cadena a un stream

		string col1, col2, col3;

		// Extraer todos los valores de esa fila [considerando 3 columans]
		getline(stream, col1, delimitador);
		getline(stream, col2, delimitador);
		getline(stream, col3, delimitador);





		// Imprimir
		cout << "==================" << endl;
		cout << "Columna 1: " << col1 << endl;
		cout << "Columna 2: " << col2 << endl;
		cout << "Columna 3: " << col3 << endl;
		cout << endl;


	}

	archIN.close();
}

void escrituraDatosEnArchivo()
{
	/*
	* 1_ Escribe Archivo .csv
	*/
	string arch_txt = "Archivo.txt"; //Nombre del archivo
	ofstream archOUT;
	archOUT.open(arch_txt, ios::out); //Apertura

	if (!archOUT.is_open())
	{
		cout << "Error: No se pudo abrir el archivo !!!" << endl;
		exit(1);
	}

	// Escribimos en el Archivo
	archOUT << "Codigo|ApePat|ApeMat|Nombre" << endl;
	archOUT << "00001|Ramirez|Castro|Juan" << endl;
	archOUT << "00002|Campos|Romero|Luis" << endl;
	archOUT << "00003|Salazar|Bejar|Melba" << endl;

	// Cerramos Archivo
	archOUT.close();
}

