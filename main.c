#include <stdio.h>
#include <stdlib.h>
#include "animal.h"
#include "AnimalTree.h"
#include "arrayOfTrees.h"
#define archAnimales "animales.dat"

int main()
{
    int validos=0;
    int dim=20;
    celdaEspecie Especies[dim];
    validos=arch2Ada(Especies,validos,dim);

    return 0;
}
