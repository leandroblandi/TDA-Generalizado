#include <stdio.h>
#include <stdlib.h>
#include "elemento.h"
#include "grupo.h"

int main()
{

    Elemento elemento = crearElementoPorTeclado();
    mostrarElemento(elemento);

    return 0;
}
