// Libreria de input y output (para leer y escribir archivos o leer y escribir en consola)
#include <stdio.h>
#include <stdlib.h>

// Importo los archivos .h de las listas
#include "arraylist/arraylist.h"
#include "linkedlist/linkedlist.h"

// Recibe como input los parametros del programa en un arreglo de strings y un numero que indica cuantos argumentos son
int main(int argc, char *argv[])
{
  ArrayList *list = arraylist_init();
  ArrayList *list2 = arraylist_init();

  for (size_t i = 0; i < 50; i++) {
    arraylist_append(list2, -i*2);
  }

  for (size_t i = 0; i < 8; i++) {
    arraylist_append(list, i);
    arraylist_insert(list, -i*16, 0);
    arraylist_delete(list, 0);
  }

  arraylist_concatenate(list, list2);

  arraylist_destroy(list);
  
  return 0;
}
