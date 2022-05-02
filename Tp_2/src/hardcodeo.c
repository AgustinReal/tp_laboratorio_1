
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "arrayPassenger.h"
#include "hardcodeo.h"

int ids[10]={1,2,3,4,11,16,17,18,20,23};

char names[10][20]={
    "Juan",
    "Pedro",
    "Sofia",
    "Miguel",
    "Valentina",
    "Camila",
    "Andrea",
    "Luis",
    "Diego",
    "Analia"
};

char lastNames[10][20]={
    "Lopez",
    "Sancho",
    "Armani",
    "Bianchi",
    "Rossi",
    "Kroos",
    "Zabaleta",
    "Campos",
    "Armani",
    "Kloop"
};

float prices[10]={120000.00, 75000.00, 111000.00, 105000.00, 85000.00, 110000.00, 150000.00, 92000.00, 141000.00, 72211.00};

char flyCodes[10][20]={
    "tdsad12342",
    "lo123234",
    "yuds21131",
    "mnb124589",
    "lpssi12",
    "ldjs68212",
    "zcxv1232",
    "pqqw99999",
    "cvbs12765",
    "tkhsa48958"
};

int typePassengers[10]={2, 3, 1, 1, 2, 2, 3, 1, 3, 2};

int statusFlighs[10]={3, 1, 1, 2, 2, 1, 3, 1, 3, 1};

int cargarDatosListaPassenger(ePassenger lista[], int tam , int cant, int* pId)
{
    int contador=-1;
    int indexPasajero;

    if(lista!=NULL && tam>0 && cant>=0 && cant<=tam && pId!=NULL)
    {
    	contador=1;
        for(int i=0;i<cant;i++)
        {
        	indexPasajero=findPassengerById(lista, tam, ids[i]);

        	if(indexPasajero==-1)
            {
        		indexPasajero=seachPassenger(lista, tam);
            }
        	lista[indexPasajero].id=ids[i];
			strcpy(lista[indexPasajero].name, names[i]);
			strcpy(lista[indexPasajero].lastName, lastNames[i]);
			lista[indexPasajero].price=prices[i];
			strcpy(lista[indexPasajero].flyCode, flyCodes[i]);
			lista[indexPasajero].typePassenger=typePassengers[i];
			lista[indexPasajero].statusFlight=statusFlighs[i];
			lista[indexPasajero].isEmpty=0;
			contador++;
        }
        *pId=idController( lista,  tam, lista->id)-1;

    }

    return contador;
}
