/*----------------------------
 | elemento.h
 | Author: LB, DG, JB, MC, LC
 ----------------------------*/

#ifndef ELEMENTO_H_INCLUDED
#define ELEMENTO_H_INCLUDED

struct _Elemento;

typedef struct _Elemento * Elemento;


/*------------
 | Constructor
 -------------*/

/// @pre: Nada
/// @post: Devuelve un struct _Elemento con los atributos que se pasen por parametro
Elemento crearElemento(char nombre[20], int ID, int cantidad);

/// @pre: Se ingresa cada atributo por teclado
/// @post: Devuelve un struct _Elemento personalizado
Elemento crearElementoPorTeclado();

/// @pre: Nada
/// @post: Devuelve un struct _Elemento filtrable
Elemento inicializarElemento();


/*------------
 | Destructor
 -------------*/

/// @pre: Debe existir Elemento elemento
/// @post: Libera el espacio de memoria reservado por Elemento elemento
void destruirElemento(Elemento elemento);

/*------------
 | Setters
 -------------*/

/// @pre: Elemento elemento debe existir
/// @post: Cambia el atributo nombre del struct _Elemento
void setNombreElemento(Elemento elemento, char nuevoNombre[20]);

/// @pre: Elemento elemento debe existir
/// @post: Cambia el atributo id del struct _Elemento
void setIDElemento(Elemento Elemento, int nuevoID);

/// @pre: Elemento elemento debe existir
/// @post: Cambia el atributo cantidad del struct _Elemento
void setCantidadElemento(Elemento elemento, int nuevaCantidad);


/*------------
 | Getters
 -------------*/

/// @pre: Elemento elemento debe existir
/// @post: Devuelve el atributo nombre del struct _Elemento
char * getNombreElemento(Elemento elemento);

/// @pre: Elemento elemento debe existir
/// @post: Devuelve el atributo nombre del struct _Elemento
int getIDElemento(Elemento Elemento);

/// @pre: Elemento elemento debe existir
/// @post: Devuelve el atributo nombre del struct _Elemento
int getCantidadElemento(Elemento elemento);


/*------------------------
 | Funciones de elementos
 ------------------------*/

/// @pre: Elemento elemento debe ser no-filtrable
/// @post: Muestra por consola todos los atributos del Elemento elemento
void mostrarElemento(Elemento elemento);

/*---------------------------
 | Procedimientos de archivo
 ---------------------------*/

/// @pre: Elemento elementos[] debe contener struct _Elemento no-filtrables
/// @post: Crea un archivo o sobreescribe un archivo 'elementos.txt' con todos los struct _Elemento del arreglo
void guardarElementos(Elemento elementos[]);

#endif // ELEMENTO_H_INCLUDED
