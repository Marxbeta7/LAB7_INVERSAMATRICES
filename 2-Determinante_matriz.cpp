
#include<stdio.h>
#include <iostream>
#include <math.h>

//Incluimos librerias propias de C++

using namespace std;


//PROGRAMA PARA CALCULAR DETERMINANTE POR ELIMINACION GAUSSIANA 

//EN CONSOLA SE MUESTRAN TODOS LOS PASOS 

int main(void)
{
	cout<<"Encontrar Determinante por eliminacion Gaussiana"<<endl;

	
	
	//DEFINIR NUMERO DE FILAS Y  COLUMNAS 
	
	int m; // filas
	cout<<"Ingrese el tamano de la matriz: "; cin>>m;
	
	int n=m; // columnas
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
 		}
 	}
 	
 	// Crear matriz Identidad en B 
 	
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
	
	//
 	cout << endl << "Matriz Aumentada "<<endl;
	for (int i = 0; i < m; ++i)
	{
		// Imprimir Matriz 1
		for (int j = 0; j < n; ++j)
		{
			cout << A[i][j] << "\t"; // Imprimir Fila
		}

		// Imprimir Matriz 2
		cout << "|\t";
		for (int j = 0; j < n; ++j)
		{
			cout << B[i][j] << "\t"; // Imprimir Fila
		}
		cout << endl; // Terminar la linea
	}

	// Reduccion de Gauss
	
	double coeficiente; 
	cout << endl << "Implementando reduccion por Gauss" << endl;
	for (int i = 0; i < m; ++i)
	{ 
            //PASOS ESPECIALES PARA CUMPIR ENUNCIADO: 
            
		// Volver 0 los elementos de la columna i en las demas filas
		// El elemento de la diagonal no se ha modificado
		
		for (int i_otras_filas = 0; i_otras_filas < m; ++i_otras_filas)
		{
			// Operar las filas diferentes que esten debajo de i
			//  crear la matriz triangular superior
			
			if (i_otras_filas > i )
			{
				// Limpiar las columnas
				coeficiente = A[i_otras_filas][i] / A[i][i];
				
				
				// Operar la fila
				for (int j = 0; j < n; ++j)
				{	
					// Llevar a cero el elemento A[i_otras_filas][i]
					A[i_otras_filas][j] = A[i_otras_filas][j] - coeficiente*A[i][j];
					
					// Repetir la operacion en la matriz identidad
					B[i_otras_filas][j] = B[i_otras_filas][j] - coeficiente*B[i][j];
				}
			}
		}
	}


	// Imprimir Matrices
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

	cout << endl << "La Matriz Triangular Superior es" << endl;
	
	
	// Imprimir Matriz
	for (int i = 0; i < m; ++i)
	{
		// Imprimir Matriz solucion
		for (int j = 0; j < n; ++j)
		{
			cout << A[i][j] << "\t"; 
		}
		cout << endl; 
	}

	// Multiplicar valores de la diagonal para encontrar el determinante
	double determinante=1;
	
	for (int i = 0; i < m; ++i)
	{
		determinante = determinante*A[i][i];
	}

	cout << endl << "Multiplicando los valores de la diagonal" << endl;
	cout << "El Determinante de la Matriz es " << determinante << endl;

 return 0;
}
