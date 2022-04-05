# Creador de AFD's

El objetivo de este programa es recibir un archivo de texto que incluya la tabla
de transición de estados de un autómata finito determinista para después crear
un autómata que reciba una entrada y evalue si la cadena es aceptada por el mismo.

## Uso

Se espera que el programa reciba en los argumentos el nombre del archivo de donde se va a leer la tabla

```
<!-- python3 main.py <nombrearchivo.txt> -->
///
```

## Ingreso de datos al leer el archivo

En la primera línea se leen las diferentes entradas(abecedario) que puede recibir el autómata determinista.
En la segunda línea se leen los estados donde el autómata se encuentra en un estado de aceptación, siempre
dado por valores numéricos.
En las siguientes líneas se leen las transiciones que se realizarían para cada estado, es importante destacar
que no es necesario incluir en que estado se encuentran (ej. q0), ya que el programa le asigna el valor al estado
por defecto, imaginemos el AFD que recibe todas las cadenas que contienen un 1 o un 0,
la tabla de transición sería la siguiente:

| Estado | 1   | 0   |
| ------ | --- | --- |
| q0     | q1  | q1  |
| q1     | q1  | q1  |

Para este AFD, el archivo que define la tabla de transición debería de ser como el de este ejemplo:

```
  1 0 // Abecedario del AFD
  1 // Numero de el/los estados de aceptacion
  1 1 // Estado inicial // Transición // Transición
  1 1 // Estado inicial // Transición // Transición
```

### Ejemplos

Dentro del proyecto se anexan las tablas de transición correspondientes a los siguientes autómatas

- AFD que acepta las cadenas que inician en ab o terminan en ac (automata1.txt)
- AFD que acepta todas las cadenas cuyo tercer símbolo desde el extremo derecho sea 1 (automata2.txt)
