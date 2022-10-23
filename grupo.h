/*-----------------------
 | grupo.h
 | Author: Leandro Blandi
 ------------------------*/

#ifndef GRUPO_H_INCLUDED
#define GRUPO_H_INCLUDED
#include "elemento.h"

struct _Grupo;

typedef struct _Grupo * Grupo;


/*------------
 | Constructor
 -------------*/

Grupo crearGrupo(char nombre[20], int ID);
Grupo crearGrupoPorTeclado();

/*------------
 | Destructor
 -------------*/

void destruirGrupo(Grupo grupo);


/*------------------------
 | Funciones de elementos
 ------------------------*/

void inicializarElementosEnGrupo(Grupo grupo);
void agregarElementos(Grupo grupo, int cantidadElementos);
void modificarElemento(Grupo grupo, int IDElemento);
void eliminarElemento(Grupo grupo, int IDElemento);
void ordenarElementosPorID(Grupo grupo);


/*----------------------
 | Funciones de grupo
 ----------------------*/

void mostrarGrupo(Grupo grupo);
int buscarPosicionLibre(Grupo grupo);


/*---------------------------
 | Procedimientos de archivo
 ---------------------------*/

void guardarGrupoYElementos(Grupo grupo);


#endif // GRUPO_H_INCLUDED
