#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Passenger.h"
#include "inputs.h"
#include "parser.h"
#include "menus.h"




int main()
{
	setbuf(stdout, NULL);
    int idUtltimo;
    char salir;
    //FLAGS
    int flagLoadText=0;
    int flagLoadBinary=0;
    int flagSeCargoPasajero=0;
    int flagSeGuardo=0;

    idUtltimo=controller_getUltimoId();

    printf("%d",idUtltimo);

    LinkedList* listaPasajeros = ll_newLinkedList();

    if(listaPasajeros==NULL)
    {
    	printf("No se consiguio memoria...\n");
    	exit(1);
    }

    do{


        switch(menuPrincipal())
        {
        	case 1:
        		if(flagLoadText==1)
        		{
        			printf("\nYa se cargo la lista del archivo de modo texto...\n\n");
        		}
        		else if(flagLoadBinary==1)
        		{
        			printf("\nError. Ya se cargo la lista del archivo de modo binario...\n\n");
        		}
        		else
        		{
        			controller_loadFromText("data.csv", listaPasajeros);
					flagLoadText=1;
					flagSeCargoPasajero=1;
        		}
        		break;
            case 2:
            	if(flagLoadBinary==1)
            	{
            		printf("\nYa se cargo la lista del archivo de modo binario...\n\n");
            	}
            	else if(flagLoadText==1)
            	{
            		printf("\nError. Ya se cargo la lista del archivo de modo texto...\n\n");
            	}
            	else
            	{
            		controller_loadFromBinary("dataBinaria.bin", listaPasajeros);
            		flagLoadBinary=1;
            		flagSeCargoPasajero=1;
            	}
                break;
            case 3:
            	if(controller_addPassenger(listaPasajeros)==1)
            	{
            		flagSeCargoPasajero=1;
            	}
            	break;
            case 4:
            	if(flagSeCargoPasajero==1)
            	{
            		controller_editPassenger(listaPasajeros);
            	}
            	else
            	{
            		printf("\nNo hay pasajeros en el sistema...\n");
            	}
				break;
            case 5:
            	if(flagSeCargoPasajero==1)
            	{
            		controller_removePassenger(listaPasajeros);
            	}
            	else
            	{
            		printf("\nNo hay pasajeros en el sistema...\n");
            	}
            	break;
            case 6:
            	if(flagSeCargoPasajero==1)
            	{
            		controller_ListPassenger(listaPasajeros);
            	}
            	else
            	{
            		printf("\nNo hay pasajeros en el sistema...\n");
            	}
            	break;
            case 7:
            	if(flagSeCargoPasajero==1)
            	{
            		controller_sortPassenger(listaPasajeros);
            	}
            	else
            	{
            		printf("\nNo hay pasajeros en el sistema...\n");
            	}
            	break;
            case 8:
            	if(flagLoadText==0)
            	{
            		printf("\nError. Ya se cargo la lista del archivo de modo binario...\n\n");
            	}
            	else
            	{
            		controller_saveAsText("data.csv", listaPasajeros);
            		flagSeGuardo=1;
            	}
            	break;
            case 9:
            	if(flagLoadBinary==0)
            	{
            		printf("\nError. Ya se cargo la lista del archivo de modo texto...\n\n");
            	}
            	else
            	{
            		controller_saveAsBinary("dataBinaria.bin", listaPasajeros);
            		flagSeGuardo=1;
            	}
            	break;
            case 10:
            	if(flagSeGuardo==0)
            	{
            		printf("\nError. Antes de salir del menu tiene que guardar los cambios...\n\n");
            	}
            	else
            	{
            		ingresoChar(&salir, "Ingrese  S para salir del menu principal (s/n): ");
            		ll_deleteLinkedList(listaPasajeros);
            	}
            	break;
            default:
            	printf("ERROR. INGRESE UNA OPCION (1-10)\n");
            	break;
        }
    }while(salir!='s');
    return 0;
}

