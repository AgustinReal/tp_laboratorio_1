/*
 ============================================================================
 Name        : Tp_1.c
 Author      :
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"


int main()
{
	setbuf(stdout, NULL);

    int kilometrosIngresados;
    float precioVueloArolineas;
    float precioVueloLatam;
    int flagIngresoKilometros=0;
    int flagPrecioIngresados=0;
    int flagIngresoTerceraOpcion=0;
    int opcionMenuPrincipal;
    char continuar=' ';

    while(continuar!='s')
    {
        do
        {
            imprimirCartel("|                     MENU PRINCIPAL                      |\n|                    AGENCIA DE VIAJE                     |\n");
            imprimirMenu(&flagIngresoKilometros, &flagPrecioIngresados, kilometrosIngresados, precioVueloLatam, precioVueloArolineas);
            ingresoEntero(&opcionMenuPrincipal, "\nOpcion: ");

            if(opcionMenuPrincipal>6 || opcionMenuPrincipal<1)
            {
                imprimirCartel("|    Error. Ingrese las opciones validas del 1 al 6.      |\n");
            }
        }
        while(opcionMenuPrincipal<1 || opcionMenuPrincipal>6);

        switch(opcionMenuPrincipal)
        {
        case 1:
            if(flagIngresoKilometros==0)
            {
                ingresoEntero(&kilometrosIngresados, "\nIngrese los kilometros: ");
                flagIngresoKilometros=1;
            }
            else
            {
                imprimirCartel("|                Ya se ingresaron los KM                  |\n");
            }
            break;
        case 2:
            if(flagIngresoKilometros==0)
            {
                imprimirCartel("|                 No se ingresaron los KM                 |\n");
            }
            else
            {
                if(flagPrecioIngresados==0)
                {
                    ingresoFlotante(&precioVueloArolineas, "Ingrese el precio de Arolinea: ");
                    ingresoFlotante(&precioVueloLatam, "Ingrese el precio de Latam: ");
                    flagPrecioIngresados=1;
                }
                else
                {
                    imprimirCartel("|              Ya se ingresaron los vuelos                |\n");
                }
            }
            break;
        case 3:
            if(flagIngresoKilometros==0)
            {
                imprimirCartel("|                 No se ingresaron los KM                 |\n");
            }
            else
            {
                if(flagPrecioIngresados==0)
                {
                    imprimirCartel("|              No se ingresaron los vuelos                |\n");
                }
                else
                {
                    if(flagIngresoTerceraOpcion==0)
                    {
                        imprimirCartel("|                  Calculos aplicados                     |\n");
                        calcularCalculosDeCostos(precioVueloArolineas, kilometrosIngresados);
                        calcularCalculosDeCostos(precioVueloLatam, kilometrosIngresados);
                        aplicarDiferenciaPrecio(precioVueloArolineas, precioVueloLatam);
                        flagIngresoTerceraOpcion=1;
                    }
                }
            }
            break;
        case 4:
            mostrarOpcionCuatro(&flagIngresoKilometros, &flagPrecioIngresados, &flagIngresoTerceraOpcion, precioVueloLatam, precioVueloArolineas, kilometrosIngresados);
            break;
        case 5:
            kilometrosIngresados=7090;
            precioVueloArolineas=162965.00;
            precioVueloLatam=159339.00;

            calcularCalculosDeCostos(precioVueloArolineas, kilometrosIngresados);
            calcularCalculosDeCostos(precioVueloLatam, kilometrosIngresados);
            aplicarDiferenciaPrecio(precioVueloArolineas, precioVueloLatam);
            mostarResultados(precioVueloLatam, precioVueloArolineas, kilometrosIngresados);
            break;
        case 6:
            pedirUnCaracter(&continuar, "Desea salir de la agencia de viaje? s/n: ");
            break;
        }
        if(continuar!='s')
        {
            system("pause");
            printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
        }
    }
    return 0;
}


