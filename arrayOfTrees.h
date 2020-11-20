#ifndef ARRAYOFTREES_H_INCLUDED
#define ARRAYOFTREES_H_INCLUDED
#include "AnimalTree.h"
#include "animal.h"
#include <strings.h>
#include <stdio.h>
#include <stdlib.h>


typedef struct
{
    animal dato;
    int idEspecie;
    char especie[20];
} registroArchivo;

typedef struct
{
    int idEspecie;
    char especie [20];
    // "Mamiferos", "Aves"
    // "Reptiles", "Peces"
    nodoArbol * arbolDeAnimales;
} celdaEspecie;

int arch2Ada(celdaEspecie ada[],int valid,int dim);
int agregarArray(celdaEspecie ada[], registroArchivo ra, int valid);
int buscarPosArray(celdaEspecie ada[],char especie[],int valid);
int agregarEspecie(celdaEspecie ada[], char especie[], int idEspecie,int valid);
void mostrarArrayAnimales(celdaEspecie especie[],int validos);
void crearArchivoPorEspecie(celdaEspecie especie[],int validos);
void guardarArbolDeEspecie(char archEspecies,nodoArbol*arbolEspecie);


#endif // ARRAYOFTREES_H_INCLUDED
