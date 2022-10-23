/*-----------------------
 | elemento.h
 | Author: Leandro Blandi
 ------------------------*/

#ifndef ELEMENTO_H_INCLUDED
#define ELEMENTO_H_INCLUDED

struct _Elemento;

typedef struct _Elemento * Elemento;


/*------------
 | Constructor
 -------------*/

Elemento crearElemento(char nombre[20], int ID, int cantidad);
Elemento crearElementoPorTeclado();

/*------------
 | Setters
 -------------*/

void setNombreElemento(Elemento elemento, char nuevoNombre[20]);
void setIDElemento(Elemento Elemento, int nuevoID);
void setCantidadElemento(Elemento elemento, int nuevaCantidad);


/*------------
 | Getters
 -------------*/

char * getNombreElemento(Elemento elemento);
int getIDElemento(Elemento Elemento);
int getCantidadElemento(Elemento elemento);


void mostrarElemento(Elemento elemento);

#endif // ELEMENTO_H_INCLUDED