#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "hardcode.h"

char nombres[11][20]={
    "Agustin luca",
    "Luis Pedro",
    "Carlos luis",
    "Miguel",
    "Valentina",
    "Camila",
    "Andrea",
    "Luis",
    "Diego",
    "Analia",
    "Alexander"

};

char Apellidos[11][20]={
    "Rossi",
    "Advinvula",
    "Izquierdoz",
    "Rojo",
    "Valentini",
    "Varela",
    "Almendra",
    "Molinas",
    "Zeballos",
    "Vazquez",
    "Moreno"

};


float salario[11]= {97000.200, 149000.350, 37000.500, 17000.950, 7000.400, 77000.830, 130000.000, 87000.670, 1000.200, 37000.700, 55000.840};

int sectores[11]={2, 5, 7, 3, 2, 4, 5, 6, 4, 7,5};

int id[11]={1, 2, 3, 4, 5, 6, 7, 8, 9, 10,11};


int harcodearPersonas(Employee lista [], int tam, int cantidadACargar, int *pId)
{
    int contador=-1;

    if(lista!=NULL && tam>0 && cantidadACargar>=0 && cantidadACargar<=tam && pId!=NULL)
    {
        contador=0;
        for(int i=0; i<cantidadACargar; i++)
        {
            lista[i].id= *pId;
            (*pId)++;
            strcpy(lista[i].name, nombres[i]);
            strcpy(lista[i].lastName, Apellidos[i]);
            lista[i].salary=salario[i];
            lista[i].sector=sectores[i];
            lista[i].id=id[i];
            lista[i].isEmpty=0;

            contador++;
        }
    }
    return contador;
}
