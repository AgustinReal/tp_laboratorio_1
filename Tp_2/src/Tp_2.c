#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "inputs.h"
#include "arrayPassenger.h"
#include "hardcodeo.h"

#define LENPASSENGER 2000

int main()
{
	setbuf(stdout, NULL);
    int opcionMenu;
    char salir;
    int contadorId=0;
    int elegirInforme;
    int hayPassenger=0;
    int altaForzadaIngresada=0;

    ePassenger listPassenger[LENPASSENGER];
    ePassenger onePassenger;

    initPassengers(listPassenger, LENPASSENGER);



    do
    {
        ingresoEntero(&opcionMenu," _____________________________________________ \n"
                                  "|                                             |\n"
                                  "|               **IRLINE MENU**               |\n"
                                  "|           **TRAVEL UTN ARGENTINA**          |\n"
                                  "|_____________________________________________|\n"
                                  "|                                             |\n"
                                  "|1-ALTA                                       |\n"
                                  "|2-MODIFICAR                                  |\n"
                                  "|3-BAJA                                       |\n"
                                  "|4-INFORMAR                                   |\n"
        						  "|5-ALTA FORZADA                               |\n"
                                  "|6-SALIR                                      |\n"
                                  "|_____________________________________________|\n"
                                  "option: ",
                                  " _____________________________________________ \n"
                                  "|                                             |\n"
                                  "|            REINGRESE OPTION (1-6)           |\n"
                                  "|_____________________________________________|\n"
                                  " _____________________________________________ \n"
                                  "|                                             |\n"
                                  "|               **IRLINE MENU**               |\n"
                                  "|           **TRAVEL UTN ARGENTINA**          |\n"
                                  "|_____________________________________________|\n"
                                  "|                                             |\n"
                                  "|1-ALTA                                       |\n"
                                  "|2-MODIFICAR                                  |\n"
                                  "|3-BAJA                                       |\n"
                                  "|4-INFORMAR                                   |\n"
								  "|5-ALTA FORZADA                               |\n"
								  "|6-SALIR                                      |\n"
                                  "|_____________________________________________|\n"
                                  "option: ", 1,6);




        switch(opcionMenu)
        {
            case 1:
                if(addPassenger(listPassenger, LENPASSENGER, contadorId, onePassenger.name, onePassenger.lastName, onePassenger.price, onePassenger.flyCode, onePassenger.typePassenger, onePassenger.statusFlight)==0)
                {
                    contadorId++;
                    hayPassenger=1;
                }
                else
                {
                    printf("Error. No se pudo realizar el alta.\n");
                }
                break;
            case 2:
                if(!hayPassenger)
                {
                    printf("La lista de passager esta vacia..\n");
                }
                else
                {
                    modifyPassenger(listPassenger, LENPASSENGER);
                }
                break;
            case 3:
                if(!hayPassenger)
                {
                    printf("La lista de passager esta vacia..\n");
                }
                else
                {
                    removePassenger(listPassenger, LENPASSENGER, onePassenger.id);
                }
                break;
            case 4:
                if(!hayPassenger)
                {
                    printf("La lista de passager esta vacia..\n");
                }
                else
                {
                    pedirListado(&elegirInforme);
                    mostrarListadoInforme(listPassenger, LENPASSENGER, elegirInforme);
                }
                break;
            case 5:
            	if(altaForzadaIngresada==1)
            	{
            		printf("\nYa se dio la alta forzada..\n\n");
            	}
            	else
            	{
            		printf("\n  *alta forzada*  \n\n");
            		cargarDatosListaPassenger(listPassenger, LENPASSENGER , 10, &contadorId);
					if(contadorId>=0)
					{
						hayPassenger=1;
					}
					altaForzadaIngresada=1;
            	}
				break;
            case 6:
            	ingresoChar(&salir, "Presione S para salir del menu s/n: ");
                break;
        }
    }while(salir!='s');
    return 0;
}




