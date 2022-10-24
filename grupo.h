/*-----------------------------
 | grupo.h
 | Authors: LB, DG, JB, MC, LC
 -----------------------------*/

#ifndef GRUPO_H_INCLUDED
#define GRUPO_H_INCLUDED
#include "elemento.h"

struct _Grupo;

typedef struct _Grupo * Grupo;


/*------------
 | Constructor
 -------------*/

/// @pre: Nada
/// @post: Devuelve un struct _Grupo con los atributos pasados por parametro
Grupo crearGrupo(char nombre[20], int ID);

/// @pre: Se carga por teclado cada atributo
/// @post: Devuelve un struct _Grupo personalizado
Grupo crearGrupoPorTeclado();

/*------------
 | Destructor
 -------------*/

/// @pre: Grupo grupo debe existir
/// @post: Libera el espacio de memoria reservado por Grupo grupo
void destruirGrupo(Grupo grupo);


/*------------------------
 | Funciones de elementos
 ------------------------*/

/// @pre: Grupo grupo debe existir
/// @post: Setea como filtrables todos los indices del arreglo Elemento elementos[CANTIDAD_ELEMENTOS]
void inicializarElementosEnGrupo(Grupo grupo);

/// @pre: Grupo grupo debe existir, se debe cumplir que { -1 < cantidadElementos < CANTIDAD_ELEMENTOS } y debe haber indice libre en el arreglo
/// @post: Inserta una cantidad 'cantidadElementos' de struct _Elementos en posiciones libres del arreglo Elemento elementos[]
void agregarElementos(Grupo grupo, int cantidadElementos);

/// @pre: Grupo grupo debe existir, el elemento a buscar tambien
/// @post: Modifica ID y cantidad del struct _Elemento en cuestion
void modificarElemento(Grupo grupo, int IDElemento);

/// @pre: Grupo grupo debe existir, el elemento a buscar tambien
/// @post: Setea como filtrable el struct _Elemento en cuestion
void eliminarElemento(Grupo grupo, int IDElemento);

/// @pre: Grupo grupo debe existir, y Elemento elementos[] debe contener struct _Elemento no-filtrables en sus indices
/// @post: No hace falta explicar
void ordenarElementosPorID(Grupo grupo);


/*----------------------
 | Funciones de grupo
 ----------------------*/

/// @pre: Debe existir Grupo grupo, ademas debe ser no-filtrable
/// @post: Muestra todos los atributos (incluso los struct _Elementos) del struct _Grupo
void mostrarGrupo(Grupo grupo);

/// @pre: Grupo grupo debe existir y al menos tener una posicion libre
/// @post: Retorna -1 si no hay mas lugar; n > -1 si hay lugar
int buscarPosicionLibre(Grupo grupo);


/*---------------------------
 | Procedimientos de archivo
 ---------------------------*/

/// @pre: Grupo grupo debe existir, tambien Elemento elementos[] debe contener indices no-filtrables (Grupo grupo tambien)
/// @post: Crea un archivo o sobreescribe un archivo 'grupo.txt' con todos los atributos del mismo, ademas tambien guarda
///        en 'elemento.txt' cada struct _Elemento que posea el struct _Grupo y que no sean filtrables
void guardarGrupoYElementos(Grupo grupo);


#endif // GRUPO_H_INCLUDED
