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


Grupo crearGrupoPorTeclado()
{
    char nombre[20];
    int ID;

    printf("\nIngrese nombre para el grupo: ");
    fflush(stdin);
    gets(nombre);

    printf("\nIngrese ID para \"%s\": ", nombre);
    scanf("%d", &ID);

    return crearGrupo(nombre, ID);
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


void modificarElemento(Grupo grupo, int IDElemento)
{
    int encontrado = -1;

    for(int i = 0; i < CANTIDAD_ELEMENTOS; i++)
    {
        if(getIDElemento(grupo->elementos[i]) == IDElemento)
        {

            int IDAuxiliar;
            int cantidadAuxiliar;

            printf("\nIngrese nuevo ID para \"%s\": ", getNombreElemento(grupo->elementos[i]));
            scanf("%d", &IDAuxiliar);

            printf("\nIngrese nueva cantidad para \"%s\": ", getNombreElemento(grupo->elementos[i]));
            scanf("%d", &cantidadAuxiliar);

            setIDElemento(grupo->elementos[i], IDAuxiliar);
            setCantidadElemento(grupo->elementos[i], cantidadAuxiliar);

            encontrado = i;
            i = CANTIDAD_ELEMENTOS;
        }
    }
    if(encontrado == -1)
    {
        printf("\nNo se encontro el elemento que usted quiere modificar");
    }
}

void eliminarElemento(Grupo grupo, int IDElemento)
{
        int encontrado = -1;

    for(int i = 0; i < CANTIDAD_ELEMENTOS; i++)
    {
        if(getIDElemento(grupo->elementos[i]) == IDElemento)
        {

            setNombreElemento(grupo->elementos[i], "");
            setIDElemento(grupo->elementos[i], -1);
            setCantidadElemento(grupo->elementos[i], -1);

            encontrado = i;
            i = CANTIDAD_ELEMENTOS;
        }
    }
    if(encontrado == -1)
    {
        printf("\nNo se encontro el elemento que usted quiere eliminar");
    }
}


void ordenarElementosPorID(Grupo grupo)
{

    Elemento elementoAuxiliar;

    for(int i = 0; i < CANTIDAD_ELEMENTOS; i++)
    {
        for(int j = 0; j < CANTIDAD_ELEMENTOS - 1; j++)
        {
            if(getIDElemento(grupo->elementos[j]) > getIDElemento(grupo->elementos[j+1]))
            {
                elementoAuxiliar = grupo->elementos[j];
                grupo->elementos[j] = grupo->elementos[j+1];
                grupo->elementos[j+1] = elementoAuxiliar;
            }
        }
    }
}


void mostrarGrupo(Grupo grupo)
{
    printf("\nGrupo:");
    printf("\n\t- Nombre: %s", grupo->nombre);
    printf("\n\t- ID: %d", grupo->ID);

    printf("\nElementos:");

    for(int i = 0; i < CANTIDAD_ELEMENTOS; i++)
    {
        mostrarElemento(grupo->elementos[i]);
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


/*---------------------------
 | Procedimientos de archivo
 ---------------------------*/

void guardarGrupoYElementos(Grupo grupo)
{
    FILE * archivoGrupo = fopen("grupo.txt", "w");

    if(grupo->ID != -1)
    {
        fprintf(
            archivoGrupo,
            "%s+%d\n",
            grupo->nombre,
            grupo->ID
        );
    guardarElementos(grupo->elementos);
    }
    fclose(archivoGrupo);
}

