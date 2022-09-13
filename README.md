# Actividad 1.1 Implementación de la técnica de programación "divide y vencerás"
## Carlo Lujan A01639847 y Carlos Rodriguez A00344666
En esta actividad se implementa un algoritmo de merge sort para permitir ordenar de forma descendente una lista que contiene un numero n de numeros reales en su interior. A su vez se hace uso del redireccionamiento de entrada en un ambiente linux para poder autopoblar los datos y ejecutar el ordenamiento sin la necesidad de escribir o teclear los valores esperados por el programa para su funcionamiento. 

## Complejidad
Para poder explicar la complejidad de manera sencilla sobre el algoritmo presente tenemos que tener en cuenta que se hace uso de la tecnica divide y vencerás, que se basa en ir dividiendo el problema en partes cada vez mas pequeñas, esto provoca que division tras division el comportamiento cobre forma de un logaritmo, que a su vez se verá influenciado por el factor del número de numeros. Asi que podemos observar que el arreglo/vector se divide recursivamente en mitades hasta que el tamaño se convierte en 1. Una vez que el tamaño se convierte en 1, el proceso de fusión entra en acción y comienza a fusionar las matrices de nuevo hasta el la matriz completa se fusiona.

Por lo que podemos decir que la complejidad de este algoritmo es **O(n log n)**.

## Ejecución del programa (Linux)

Para ejecutar el programa e ingresar al numero de elementos a insertar en la lista y escribir cada uno de ellos a mano es necesario ejecutar el codigo siguiente:
```
$ g++ main.cpp -o main.out
$ ./main
```

Para ejecutar el programa usando el redireccionamiento de entrada haciendo uso de un texto se puede acceder a los datos precargados dentro de los archivos de texto de la carpeta tests, es necesario escribir el siguiente codigo, en donde estos archivos contienen el nombre tX.txt donde X es el numero de prueba en los casos de prueba descritos abajo:
```
$ g++ main.cpp -o main.out
$ ./main.out < ./tests/tX.txt
```

## Casos de prueba

1- Caso de prueba en donde el numero de enteros "n" a ingresar es igual o menor a 0, es decir un numero invalido.

**Entrada**
- n <= 0 
- []

**Salida**
```
Please enter a value greater than 0
```

2- Caso de prueba en donde el numero de enteros es igual a 1, es decir que la lista solo tendra que retornar el numero 1, este es el caso con menor numero de iteraciones recursivas.

**Entrada**
- n = 1
- [10]

**Salida**
```
-----------------------------------------
Numbers before ordering
-----------------------------------------
10

-----------------------------------------
Numbers after ordering (descending order)
-----------------------------------------
10
```

3- Caso de prueba en donde la lista ingresada esta completamente ordenada (mejor caso)
**Entrada**
- n = 5
- [5,4,3,2,1]

**Salida**
```
-----------------------------------------
Numbers before ordering
-----------------------------------------
5 4 3 2 1 

-----------------------------------------
Numbers after ordering (descending order)
-----------------------------------------
5 4 3 2 1
```

4- Caso de prueba en donde la lista ingresada esta mezclada en un caso de uso común (caso promedio)
**Entrada**
- n = 5
- [3,2,5,4,1]

**Salida**
```
-----------------------------------------
Numbers before ordering
-----------------------------------------
3 2 5 4 1

-----------------------------------------
Numbers after ordering (descending order)
-----------------------------------------
5 4 3 2 1
```

5- Caso de prueba en donde la lista ingresada esta completamente inversa (peor caso)
**Entrada**
- n = 5
- [1,2,3,4,5]

**Salida**
```
-----------------------------------------
Numbers before ordering
-----------------------------------------
1 2 3 4 5 

-----------------------------------------
Numbers after ordering (descending order)
-----------------------------------------
5 4 3 2 1
```

6- Caso de prueba en donde la lista contiene numeros decimales muy cercanos
**Entrada**
- n = 10
- [9.9,9.91,9.92,9.93,9.94,9.95,9.96,9.97,9.98,9.99]

**Salida**
```
-----------------------------------------
Numbers before ordering
-----------------------------------------
9.9 9.91 9.92 9.93 9.94 9.95 9.96 9.97 9.98 9.99

-----------------------------------------
Numbers after ordering (descending order)
-----------------------------------------
9.99 9.98 9.97 9.96 9.95 9.94 9.93 9.92 9.91 9.9
```

7- Caso de prueba en donde la lista contiene numeros repetidos, enteros y numeros decimales
**Entrada**
- n = 7
- [5,6,6,7.7,8.1,8,6]

**Salida**
```
-----------------------------------------
Numbers before ordering
-----------------------------------------
5 6 6 7.7 8.1 8 6

-----------------------------------------
Numbers after ordering (descending order)
-----------------------------------------
8.1 8 7.7 6 6 6 5
```
