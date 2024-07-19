# CPS
Critical Path Solver (CPS) es un programa para resolver los ejercicios de CPM. Lo vimos en análisis de sistemas en la UTN en 2do año de la carrera de ingeniería en sistemas de la información. ¿Por qué? Para practicar para sistemas operativos, por aburrimiento, por el placer de hacerlo, porque sí.

## Uso
El programa (por ahora) no grafica el diagrama, es simplemente demasiado. Pero le podes pasar la tabla de dependencias y recibir la forma correcta de dibujar el diagrama. Dejemosle a las máquinas hacer lo que saben hacer bien y a los seres humanos, dibujar.
```bash
cps [-i input.cpm] [-o output.cpm]
```

## Instalación
```bash
git clone https://github.com/elicapo133/CPS.git
cd CPS
make
```

## Dependencias
Ninguna! Por ahora... puro C y librerias standard _de *nix_, como Kernighan y Ritchie lo pretendían!.

## Formato (input)
El archivo que recibe el programa como input tiene que ser de esta forma
```bash
# Comentario!, el '#' tiene que ir en el primer caracter de la linea sí o sí.
Tarea 1 | 3 | -
Tarea 2 | 2 | -
Tarea 3 | 1 | Tarea 1, Tarea 2
```

## Output


