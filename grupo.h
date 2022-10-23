/*-----------------------
 | grupo.h
 | Author: Leandro Blandi
 ------------------------*/

#ifndef GRUPO_H_INCLUDED
#define GRUPO_H_INCLUDED

struct _Grupo;

typedef struct _Grupo * Grupo;

Grupo crearGrupo(char nombre[20], int ID);

void inicializarElementosEnGrupo(Grupo grupo);

void agregarElementos(Grupo grupo, int cantidadElementos);

void mostrarGrupo(Grupo grupo);

int buscarPosicionLibre(Grupo grupo);

#endif // GRUPO_H_INCLUDED
