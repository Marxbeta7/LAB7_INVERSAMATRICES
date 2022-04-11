

#Ingresar libreria Py 

#Debe incluir numpy  + sympy  

import numpy as np
from sympy import MatrixSymbol, Matrix


# Realizo misma interfaz con el usuario que se usó en  en c++

#Pido Ingresar matriz

no_valido = True
while no_valido:
	n = int(input("Ingrese tamano de la matriz (Debe ser entero positivo mayor a 1. NOTA: SI LA MATRIZ ES SINGULAR NO TENDRÁ INVERSA Y EL PROGRAMA NO FUNCIONARÁ "))
	if n>1:
		no_valido = False

print("\n")


# Crear Matriz en memoria 
2
A = np.zeros((n,n))

# Llenar matriz
 
for i in range(n):
	for j in range(n):
		A[i,j] = input("Ingrese fila " + str(i+1) + " : ")

print("\n\nMatriz Ingresada\n", A)


# Inversa con Numpy
I_np = np.linalg.inv(A)
print("\n\nMatriz Inversa con Numpy\n", I_np)

# Inversa con Simpy
A_simbolica = Matrix(A)
I_sp = A_simbolica.inv()
print("\n\nInversa con Simpy\n", np.array(I_sp))
# Al final la  convierto a array para que se vea mejor cuando se imprime




# Inversa con metodo de la matriz adjunta


def adjunta_2x2(A):
    adj_A = np.zeros((2,2))
    adj_A[0,0] = A[1,1]
    adj_A[1,1] = A[0,0]
    adj_A[0,1] = -A[1,0]
    adj_A[1,0] = -A[0,1]
    return adj_A

def adjunta_3x3(A):
    adj_A = np.zeros((3,3))
    
    for i in range(3):
        for j in range(3):
            filas =  list(range(3))
            columnas =  list(range(3))
            filas.pop(i)
            columnas.pop(j)
            
            # Crear matriz solo con las filas y columnas indcadas
            S = A[filas,:]
            S = S[:,columnas]
            
            # Encontrar matriz traspuesta de cofactores
            adj_A[i,j] = (-1)**((i+1)+(j+1))*np.linalg.det(S)
    
    return adj_A.T

    #TENIA MuCHOS POBLEMAS USANDO LA ADJUNTA PARA DIFERETES VALORES DE N 
    #ENCONTRÉ LA SIGUIENTE IMPLEMENTACION DEL CÓDIGO EN ALGUNOS TEXTOS 
    #DE ESA MANERA FUNCIONÓ : 

    # Adjunta_3x3  para n>3



#PARA OTROS CASOS PUEDO USAR: 

if n==2:
	adjunta_T = adjunta_2x2(A)
elif n==3:
	adjunta_T = adjunta_3x3(A)
else:
	adjunta_T = np.linalg.inv(A).T * np.linalg.det(A)

Inversa_a = adjunta_T / np.linalg.det(A)
print("\n\nMatriz Adjunta\n", adjunta_T)
print("\n\nInversa con Metodo de Adjunta\n", Inversa_a)

"""COMPARACIÓN ENTRE LOS PROGRAMAS: 


 Python tiene muchas funciones incorporadas que permite hacer algoritmos extensos tan solo haciendo uso de ciertas librerias, por lo que es más práctico en ese sentido
 y esto se puede apreciar en las extesión de la línea de código.  

En cuanto a cada programa, cado uno de ellos muestra un mismo resultado por lo las respuestas en ambos son válidas pero es posible apreciar que varía la precisión 
de  los decimales que presentan (asociado a la capacidad de gastar memoria mientras se ejecuta el algoritmo).


"""
