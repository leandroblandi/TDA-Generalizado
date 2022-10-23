/*-----------------------
 | grupo.c
 | Author: Leandro Blandi
 ------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "grupo.h"
#include "elemento.h"

#define CANTIDAD_ELEMENTOS 10

struct _Grupo
{
    char nombre[20];
    int ID;
    Elemento elementos[CANTIDAD_ELEMENTOS];
};


Grupo crearGrupo(char nombre[20], int ID)
{
    Grupo grupo = malloc(sizeof(struct _Grupo));

    strcpy(grupo->nombre, nombre);
    grupo->ID = ID;

    return grupo;
}


void inicializarElementosEnGrupo(Grupo grupo)
{
    for(int i = 0; i < CANTIDAD_ELEMENTOS; i++)
    {
        grupo->elementos[i] = inicializarElemento();
    }
}


void agregarElementos(Grupo grupo, int cantidadElementos)
{

    for(int i = 0; i < cantidadElementos; i++)
    {
        int posicion = buscarPosicionLibre(grupo);

        if(posicion != -1)
        {
            grupo->elementos[i] = crearElementoPorTeclado();
        }
    }
}


void mostrarGrupo(Grupo grupo)
{
    printf("\nGrupo:");
    printf("\n\t- Nombre: %s", grupo->nombre);
    printf("\n\t- ID: %d", grupo->ID);

    for(int i = 0; i < CANTIDAD_ELEMENTOS; i++)
    {

    }

}


int buscarPosicionLibre(Grupo grupo)
{
    int encontrado = -1;

    for(int i = 0; i < CANTIDAD_ELEMENTOS; i++)
    {
        if(getCantidadElemento(grupo->elementos[i]) == -1)
        {
            encontrado = i;
            i = CANTIDAD_ELEMENTOS;
        }
    }
    return encontrado;
}


