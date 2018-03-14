// importo el archivo linkedlist.h
#include "linkedlist.h"
// Libreria estandar de C
#include <stdlib.h>
#include <stdio.h>

//////////////////////////////////////////////////////////////////////////
//                             Funciones                                //
//////////////////////////////////////////////////////////////////////////

// TODO: debes completar las funciones que estan a continuacion
// Puedes crear otras funciones aca para el
// funcionamiento interno del arreglo dinamico

/** Crea una lista inicialmente vacia y retorna el puntero */
LinkedList* linkedlist_init()
{
  LinkedList* list = malloc(sizeof(LinkedList));
  list->root = NULL;
  return list;
}

void linkedlist_push(LinkedList *list, int element) {
  Node *curr = list->root;
  Node *node = malloc(sizeof(Node));
  node->val = element;
  node->next = curr;
  list->root = node;
}

void printList(LinkedList *list) {
  Node *root = list->root;

  while (root) {
    printf("-> %i ", root->val);
    root = root->next;
  }
  printf("\n");
}


/** Inserta un elemento al final de la lista */
void linkedlist_append(LinkedList* list, int element)
{
  printf("adding %i\n", element);

  if (!list->root) {
    Node *temp = malloc(sizeof(Node));
    temp->val = element;
    list->root = temp;
    list->root->next = NULL;
  } else {
    Node* root = list->root;
    while (root->next) {
      root = root->next;
    }

    Node *temp = malloc(sizeof(Node));
    temp->val = element;
    root->next = temp;
    root->next->next = NULL;
  }

  printList(list);

}

/** Inserta el elemento dado en la posicion indicada */
void linkedlist_insert(LinkedList* list, int element, int position)
{

  if (position == 0) { linkedlist_push(list, element); }
  else {
    Node *root = list->root;
    for (size_t i = 0; i < position; i++) {
      root = root->next;
    }

    Node *node = malloc(sizeof(Node));
    node->val = element;

    Node *next = root->next;
    root->next = node;
    node->next = next;
  }

  printList(list);
}

int linkedlist_pop(LinkedList *list) {
  Node *root = list->root;
  int res = root->val;
  Node *next = root->next;
  free(root);
  list->root = next;

  return res;
}

/** Elimina el elemento de la posicion indicada y lo retorna */
int linkedlist_delete(LinkedList* list, int position)
{
  if (position == 0) { return linkedlist_pop(list); }

  Node *curr = list->root;
  for (size_t i = 0; i < position - 1; i++) {
    curr = curr->next;
  }

  Node *temp = curr->next;
  int ret = temp->val;
  curr->next = temp->next;

  free(temp);
  printList(list);
  return ret;
}

/** Retorna el valor del elemento en la posicion dada */
int linkedlist_get(LinkedList* list, int position)
{
  Node *curr = list->root;
  for (size_t i = 0; i < position; i++) {
    curr = curr->next;
  }

  return curr->val;

}

/** Concatena a la lista una segunda lista */
void linkedlist_concatenate(LinkedList* list, LinkedList* list2)
{
  Node *root = list->root;

  while (root->next) {
    root = root->next;
  }

  root->next = list2->root;
  free(list2);
  printList(list);

}

/** Libera todos los recursos asociados a la lista */
void linkedlist_destroy(LinkedList* list)
{
  Node * it = list->root;
  while( NULL != it ) {
    Node * tmp = it;
    it = it->next;
    free(tmp);
  }

  free(list);
}
