/*---------------------------
 | main.c
 | Authors: LB, DG, JB, MC, LC
 ----------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include "elemento.h"
#include "grupo.h"

int main()
{

    Grupo grupo = crearGrupoPorTeclado();

    inicializarElementosEnGrupo(grupo);
    agregarElementos(grupo, 2);
    mostrarGrupo(grupo);
    ordenarElementosPorID(grupo);
    mostrarGrupo(grupo);
    guardarGrupoYElementos(grupo);

    return 0;
}
