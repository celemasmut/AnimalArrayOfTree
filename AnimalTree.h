#ifndef ANIMALTREE_H_INCLUDED
#define ANIMALTREE_H_INCLUDED
#include "animal.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct
{
   animal dato;
   struct nodoArbol * izq;
   struct nodoArbol * der;
} nodoArbol;

nodoArbol*inicArbol();
nodoArbol*creaNodoArbol(animal dato);
nodoArbol*insertArbol(nodoArbol* Arbol, nodoArbol*nuevo);
void mostrarArbolAnimal(nodoArbol*Arbol);
void inOrder(nodoArbol*Arbol);

#endif // ANIMALTREE_H_INCLUDED
