/*-----------------------
 | elemento.c
 | Author: Leandro Blandi
 ------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "elemento.h"

struct _Elemento
{
    char nombre[20];
    int ID;
    int cantidad;
};


/*------------
 | Constructor
 -------------*/

Elemento crearElemento(char nombre[20], int ID, int cantidad)
{
    Elemento elemento = malloc(sizeof(struct _Elemento));

    strcpy(elemento->nombre, nombre);

    elemento->ID = ID;
    elemento->cantidad = cantidad;

    return elemento;
}


Elemento crearElementoPorTeclado()
{
    char nombre[20];
    int ID;
    int cantidad;

    printf("\nIngrese nombre del elemento: ");
    fflush(stdin);
    gets(nombre);

    printf("\nIngrese ID para \"%s\": ", nombre);
    scanf("%d", &ID);

    printf("\nIngrese cantidad para \"%s\": ", nombre);
    scanf("%d", &cantidad);

    return crearElemento(nombre, ID, cantidad);
}

/*------------
 | Setters
 -------------*/

void setNombreElemento(Elemento elemento, char nuevoNombre[20])
{
    strcpy(elemento->nombre, nuevoNombre);
}


void setIDElemento(Elemento elemento, int nuevoID)
{
    elemento->ID = nuevoID;
}


void setCantidadElemento(Elemento elemento, int nuevaCantidad)
{
    elemento->cantidad = nuevaCantidad;
}


/*------------
 | Getters
 -------------*/

char * getNombreElemento(Elemento elemento)
{
    return elemento->nombre;
}


int getIDElemento(Elemento elemento)
{
    return elemento->ID;
}


int getCantidadElemento(Elemento elemento)
{
    return elemento->cantidad;
}


void mostrarElemento(Elemento elemento)
{
    printf("\nElemento:");
    printf("\n\t- Nombre: %s", elemento->nombre);
    printf("\n\t- ID: %d", elemento->ID);
    printf("\n\t- Cantidad: %d", elemento->cantidad);
}

