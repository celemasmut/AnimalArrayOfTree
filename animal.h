#ifndef ANIMAL_H_INCLUDED
#define ANIMAL_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
typedef struct {
      char nombreAnimal [30];
	int cantidad;
	int habitat;
// 1 - selva, 2- savana, 3-bosque, 4-mar
} animal;

animal miAnimal();
void mostrarAnimal(animal aux);
#endif // ANIMAL_H_INCLUDED
