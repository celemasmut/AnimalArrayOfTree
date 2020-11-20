#include "arrayOfTrees.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
char archAnimales[]="animales.dat";


int arch2Ada(celdaEspecie ada[],int valid,int dim)
{
    FILE*arch=fopen(archAnimales,"rb");
    if(arch)
    {
        registroArchivo aux;
        while((fread(&aux,sizeof(registroArchivo),1,arch))>0 && valid<dim)
        {
            valid=agregarArray(ada,aux,valid);
        }
        fclose(arch);
    }
    return valid;
}
int agregarArray(celdaEspecie ada[], registroArchivo ra, int valid)
{
    nodoArbol*aux=inicArbol();
    aux=creaNodoArbol(ra.dato);
    int pos = buscarPosArray(ada,ra.especie,valid);
    if(pos == -1)
    {
        valid=agregarEspecie(ada,ra.especie,ra.idEspecie,valid);
        pos=valid-1;
    }
   ada[pos].arbolDeAnimales=insertArbol(ada[pos].arbolDeAnimales,aux);
   return valid;
}
int buscarPosArray(celdaEspecie ada[],char especie[],int valid)
{
    int pos =-1;
    int indice=0;
    while(indice < valid && pos == -1)
    {
        if(strcmp(ada[indice].especie,especie) ==0)
        {
            pos=indice;
        }
        indice++;
    }
    return pos;
}

int agregarEspecie(celdaEspecie ada[], char especie[], int idEspecie,int valid)
{
    strcpy(ada[valid].especie,especie);
    ada[valid].idEspecie=idEspecie;
    ada[valid].arbolDeAnimales=inicArbol();
    valid++;
    return valid;
}

void mostrarArrayAnimales(celdaEspecie especie[],int validos)
{
    printf("\nMuestro arreglo de especie\n");
    int indice;
    for(indice=0; indice<validos;indice++)
    {
        printf("\n---------------------------");
        printf("\nEspecie: %s",especie[indice].especie);
        inOrder(especie[indice].arbolDeAnimales);
        printf("\n---------------------------");
    }
}

void crearArchivoPorEspecie(celdaEspecie especie[],int validos)
{
    char nombreArchEspecie[20];
    int indice;
    for(indice=0; indice<validos;indice++)
    {
        nombreArchEspecie[0]='\0';
        strcpy(nombreArchEspecie,especie[indice].especie);
        strcat(nombreArchEspecie,".dat");//concateno
        FILE*especiArch=fopen(nombreArchEspecie,"ab");
        if(especiArch)
        {
            guardarArbolDeEspecie(especiArch,especie[indice].arbolDeAnimales);
            fclose(especiArch);
        }
    }
}

void guardarArbolDeEspecie(char archEspecies,nodoArbol*arbolEspecie)
{
    if(arbolEspecie)
    {
        guardarArbolDeEspecie(archEspecies,arbolEspecie->izq);
        fwrite(&arbolEspecie->dato,sizeof(animal),1,archEspecies);
        guardarArbolDeEspecie(archEspecies,arbolEspecie->der);
    }
}
