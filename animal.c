#include "animal.h"

animal miAnimal()
{
    animal aux;
    printf("\nNombre de Animal: ");
    gets(aux.nombreAnimal);
    fflush(stdin);
    printf("\nCantidad : ");
    scanf("%d",&aux.cantidad);
    printf("\nHabitat 1 - selva, 2- savana, 3-bosque, 4-mar : ");
    scanf("%d",&aux.habitat);
    fflush(stdin);
    return aux;
}

void mostrarAnimal(animal aux)
{
    printf("\nAnimal: %s",aux.nombreAnimal);
    printf("\nCantidad: %d",aux.cantidad);
    printf("\nHabitat: %d",aux.habitat);
}
