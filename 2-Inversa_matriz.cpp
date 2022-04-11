#include<stdio.h>
#include <iostream>
#include <math.h>

//Incluimos libreria propias de C++

using namespace std;

//PROGRAMA PARA ENCONTRAR MATRIZ INVERSA POR ELIMINACION Gaussiana

//SE IMPRIME EN CONSOLA CADA PASO PARA MOSTRAR EL PROCESO 

int main(void)
{
	cout<<"Encontrar Matriz Inversa por eliminacion Gaussiana"<<endl;

	// OJO : Solo las matrices cuadradas tienen inversa
	
	//DEFINIR NUMERO DE FILAS Y COLUMNAS
	
	int m; // filas 
	
	cout<<"Ingrese el tamano de la matriz: "; cin>>m;
	
	int n=m; //columnas
	cout<<"Ingresar matriz cuadrada" << endl;
	
	// Crear Matriz
	
	double A[m][n];
	
 	// Llenar Matriz
 	
 	for (int i = 0; i < m; ++i)
 	{
 		cout << "Ingrese la Fila " << i + 1 << endl;
 		for (int j = 0; j < n; ++j)
 		{
 			cin>>A[i][j]; 
 			// Cada valor queda almacenado en A 
 		}
 	}
 	
 	// Crear matriz Identidad EN  B 
 	
 	double B[m][n];
	for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (i==j)
			{
				B[i][j] = 1;
			}
			else
			{
				B[i][j] = 0;
			}
		}
	}

	// Imprimir Matrices
	
 	cout << endl << "Matriz Aumentada "<<endl;
	for (int i = 0; i < m; ++i)
	{
		// Imprimir Matriz 1
		for (int j = 0; j < n; ++j)
		{
			cout << A[i][j] << "\t"; //  Fila
		}

		// Imprimir Matriz 2
		
		cout << "|\t";
		for (int j = 0; j < n; ++j)
		{
			cout << B[i][j] << "\t"; 
		}
		cout << endl; // Terminar la linea
	}

	// APLICNDO REDUCCON DE GAUSS 
	//Definir variable par hacer  opeciones 
	
	double coeficiente; 
	
	cout << endl << "Implementando reduccion por Gauss" << endl;
	
	for (int i = 0; i < m; ++i)
	{ 
		// Volver 1 el elemento de la diagonal
		
		coeficiente = 1.0/A[i][i];
		for (int j = 0; j < n; ++j)
		{
			// Dividir toda la fila por el numero de la diagonal
			A[i][j] = A[i][j] * coeficiente;
			
			// Repetir la operacion en la matriz Identidad
			B[i][j] = B[i][j] * coeficiente;
		}

		// Volver 0 los elementos de la columna i en las demas filas
		for (int i_otras_filas = 0; i_otras_filas < m; ++i_otras_filas)
		{
			// Operar las filas diferentes a i
			if (i != i_otras_filas)
			{
				// Limpiar las columnas
				coeficiente = A[i_otras_filas][i];
				// Operar la fila
				for (int j = 0; j < n; ++j)
				{	
					// Llevar a cero el elemento
					A[i_otras_filas][j] = A[i_otras_filas][j] - coeficiente*A[i][j];
					
					// Repetir la operacion en la matriz identidad
					B[i_otras_filas][j] = B[i_otras_filas][j] - coeficiente*B[i][j];
				}
			}
		}
	}


	// pAA Imprimir Matrices
	for (int i = 0; i < m; ++i)
	{
		// Imprimir Matriz 1
		
		for (int j = 0; j < n; ++j)
		{
			cout << A[i][j] << "\t"; 
		}

		// Imprimir Matriz 2
		
		cout << "|\t";
		for (int j = 0; j < n; ++j)
		{
			cout << B[i][j] << "\t"; 
		}
		cout << endl; 
	}

	cout << endl << "La Matriz Inversa es" << endl;
	
	// Imprimir Matriz
	
	for (int i = 0; i < m; ++i)
	{
		// Imprimir Matriz de solucion
		for (int j = 0; j < n; ++j)
		{
			cout << B[i][j] << "\t"; // Imprimir Fila
		}
		cout << endl; // Terminar la linea
	}

 return 0;
}