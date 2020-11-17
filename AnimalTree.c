#include "AnimalTree.h"

nodoArbol*inicArbol()
{
    return NULL;
}
nodoArbol*creaNodoArbol(animal dato)
{
    nodoArbol*nuevo=(nodoArbol*)malloc(sizeof(nodoArbol));
    nuevo->dato=dato;
    nuevo->izq=NULL;
    nuevo->der=NULL;
    return nuevo;
}
//cambiar por cantidad.
nodoArbol*insertArbol(nodoArbol* Arbol, nodoArbol*nuevo)
{
    if(!Arbol)
    {
        Arbol=nuevo;
    }
    else //This instance compares which dni is bigger. using atoi to transform a string into int.
    {
        if(nuevo->dato.cantidad > Arbol->dato.cantidad)
        {
            Arbol->der=insertArbol(Arbol->der,nuevo);
        }
        else
        {
            Arbol->izq=insertArbol(Arbol->izq,nuevo);
        }
    }
    return Arbol;
}
void mostrarArbolAnimal(nodoArbol*Arbol)
{
    mostrarAnimal(Arbol->dato);
}


void inOrder(nodoArbol*Arbol)
{
    if(Arbol)
    {
        inOrder(Arbol->izq);
        mostrarArbolAnimal(Arbol);
        inOrder(Arbol->der);
    }
}
