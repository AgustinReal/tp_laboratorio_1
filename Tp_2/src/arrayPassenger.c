#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "inputs.h"
#include "arrayPassenger.h"

int idController(ePassenger* list, int len, int id)
{
	int idMaximo=-1;

	if(list!=NULL && len>0)
	{
		idMaximo=id;
		for(int i=0;i<len;i++)
		{
			if(list[i].id>idMaximo && list[i].isEmpty==0)
			{
				idMaximo=list[i].id;
			}
		}
		idMaximo=idMaximo+1;
	}

	return idMaximo;
}
int initPassengers(ePassenger* list, int len)
{
    int todoOk=1;

    if(list!=NULL && len>0)
    {
        for(int i=0;i<len;i++)
        {
           list[i].isEmpty=1;
        }
        todoOk=0;
    }

    return todoOk;
}
int findPassengerById(ePassenger* list, int len, int id)
{
    int index=-1;

    if(list!=NULL && len>0)
    {
        for(int i=0;i<len;i++)
        {
            if(list[i].isEmpty==0 && list[i].id==id)// Esto busca si pasajero esta activo y
            {
                index=i;
                break;
            }
        }
    }
    return index;
}
int seachPassenger(ePassenger* list, int len)
{
    int index=-1;

    if(list!=NULL && len>0)
    {
        for(int i=0;i<len;i++)
        {
            if(list[i].isEmpty==1)
            {
                index=i;
                break;
            }
        }
    }

    return index;
}
int addPassenger(ePassenger* list, int len, int id, char name[],char lastName[],float price, char flyCode[],int typePassenger, int statusFlight)
{
    int todoOk=1;
    int index;
    char afirmacion;

    if(list!=NULL && name!=NULL && lastName!=NULL && flyCode!=NULL)
    {
        index=seachPassenger(list, len);
        if(index!=-1)
        {

            if(idController(list,  len,  id)!=-1)
            {

            	printf(" ___________________________________________________________ \n");
            	printf("|                                                           |\n");
            	printf("|                 *** Alta de Passenger ***                 |\n");
            	printf("|___________________________________________________________|\n");

            	list[index].id=idController(list,  len,  id);

            	ingresoCadena(name, "Ingrese el nombre del pasajero: ", "Error.Ingrese el nombre del pasajero: ", 21);
            	strcpy(list[index].name, name);

            	ingresoCadena(lastName, "Ingrese el apellido del pasajero: ", "Error.Ingrese el apellido del pasajero: ", 21);
            	strcpy(list[index].lastName, lastName);

            	ingresoFlotante(&price, "Ingrese el precio del vuelo entre(70000-150000): ", "Error.Ingrese el precio del vuelo entre(70000-150000): ", 70000, 150000);
            	list[index].price=price;

            	ingresoLetrasNumeros(flyCode, "Ingrese el codigo del vuelo del pasajero: ", "Error.Ingrese el codigo del vuelo del pasajero: ", 10);
            	strcpy(list[index].flyCode, flyCode);

            	ingresoEntero(&typePassenger, "Ingrese el tipo de pasajero (1-PRIMERA CLASE, 2-COMERCIAL, 3-TURISTA): ", "Ingrese el tipo de pasajero (1-PRIMERA CLASE, 2-COMERCIAL, 3-TURISTA): ", 1, 3);
            	list[index].typePassenger=typePassenger;

            	ingresoEntero(&statusFlight, "Ingrese el estado del vuelvo (1-ACTIVO, 2-DEMORADO, 3-CANCELADO): ", "Error.Ingrese el estado del vuelvo (1-ACTIVO, 2-DEMORADO, 3-CANCELADO): ", 1, 3);
            	list[index].statusFlight=statusFlight;

            	list[index].isEmpty=0;

            	printf("\n\n");

            	printf(" ________________________________________________________________________________________________\n");
            	printf("|                                                                                                |\n");
            	printf("|                                  **TRAVEL UTN ARGENTINA**                                      |\n");
            	printf("|                                        **PASSENGER**                                           |\n");
            	printf("|________________________________________________________________________________________________|\n");
            	printf("|   ID   |     NAME    |   LASTNAME  |   PRICE   | FLY CODE     | TYPE PASSENGER | STATUS FLIGHT |\n");
            	printf("|--------|-------------|-------------|-----------|--------------|----------------|---------------|\n");
            	printPassenger(list[index]);

            	ingresoChar(&afirmacion, "\n\nIngrese S para agregar al pasajero ingresado: ");
            	if(afirmacion=='s' || afirmacion=='S')
            	{
            		printf("El nuevo el cliente fue agregado....\n");
            		id++;
            		todoOk=0;
            	}
            	else
            	{
            		list[index].isEmpty=1;
            		printf("Se ha producido un error...\n");
            	}
            }
            else
            {
            	printf("Se ha producido un error...\n");
            }
        }
        else
        {
            printf("***no se pudo cargar***\n");
            todoOk=1;
        }

    }
    return todoOk;
}
int modifyPassenger(ePassenger* list, int len)
{
    int todoOk=1;
    int buscarEstadoPassenger;
    int indexEncontrado;
    char confirmar;
    int opcion;

    if(list!=NULL && len>0)
    {
       printListPassenger(list, len);
       ingresoEntero(&buscarEstadoPassenger, "Ingrese el id que desea modificar (1-2000): ", "Error. Ingrese el id que desea modificar (1-2000):", 1, 2000);
       indexEncontrado=findPassengerById(list, len, buscarEstadoPassenger);

       if(indexEncontrado>=0 && indexEncontrado<len && list[indexEncontrado].isEmpty==0)
       {
           ingresoChar(&confirmar, "Presione S para confirmar el passenger: ");
           if(confirmar=='s' || confirmar=='S')
           {
               do
               {
                   ingresoEntero(&opcion, " _____________________________________________ \n"
                                          "|                                             |\n"
                                          "|               **MENU MODIFY**               |\n"
                                          "|_____________________________________________|\n"
                                          "|                                             |\n"
                                          "|1-MODIFY NAME                                |\n"
                                          "|2-MODIFY LASTNAME                            |\n"
                                          "|3-MODIFY PRICE                               |\n"
                                          "|4-MODIFY FLY CODE                            |\n"
                                          "|5-MODIFY TYPE PASSENGER                      |\n"
                                          "|6-MODIFY STATUS FLIGHT                       |\n"
                                          "|7-SALIR                                      |\n"
                                          "|_____________________________________________|\n"
                                          "option: ",
                                          " _____________________________________________ \n"
                                          "|                                             |\n"
                                          "|            REINGRESE OPTION (1-7)           |\n"
                                          "|_____________________________________________|\n"
                                          " _____________________________________________ \n"
                                          "|                                             |\n"
                                          "|               **MENU MODIFY**               |\n"
                                          "|_____________________________________________|\n"
                                          "|                                             |\n"
                                          "|1-MODIFY NAME                                |\n"
                                          "|2-MODIFY LASTNAME                            |\n"
                                          "|3-MODIFY PRICE                               |\n"
                                          "|4-MODIFY FLY CODE                            |\n"
                                          "|5-MODIFY TYPE PASSENGER                      |\n"
                                          "|6-MODIFY STATUS FLIGHT                       |\n"
                                          "|7-SALIR                                      |\n"
                                          "|_____________________________________________|\n"
                                          "option: ", 1,7);

                      switch(opcion)
                      {
                          case 1:
                              ingresoCadena(list[indexEncontrado].name ,"Ingrese el nombre del pasajero: ", "Error.Ingrese el nombre del pasajero: ", 21);
                                break;
                          case 2:
                              ingresoCadena(list[indexEncontrado].lastName, "Ingrese el apellido del pasajero: ", "Error.Ingrese el apellido del pasajero: ", 21);
                                break;
                          case 3:
                              ingresoFlotante(&list[indexEncontrado].price, "Ingrese el precio del vuelo entre(70000-150000): ", "Error.Ingrese el precio del vuelo entre(70000-150000): ", 70000, 150000);
                                break;
                          case 4:
                              ingresoCadena(list[indexEncontrado].flyCode, "Ingrese el codigo del vuelo del pasajero: ", "Error.Ingrese el codigo del vuelo del pasajero: ", 21);
                                break;
                          case 5:
                              ingresoEntero(&list[indexEncontrado].typePassenger, "Ingrese el tipo de pasajero (1-PRIMERA CLASE, 2-COMERCIAL, 3-TURISTA): ", "Ingrese el tipo de pasajero (1-PRIMERA CLASE, 2-COMERCIAL, 3-TURISTA): ", 1, 3);
                                break;
                          case 6:
                              ingresoEntero(&list[indexEncontrado].statusFlight, "Ingrese el estado del vuelvo (1-ACTIVO, 2-ATRASADO, 3-CANCELADO, 4-REPROGRAMADO): ", "Error.Ingrese el estado del vuelvo (1-ACTIVO, 2-ATRASADO, 3-CANCELADO, 4-REPROGRAMADO): ", 1, 4);
                                break;
                      }
                    if(opcion<1 || opcion>6)
                    {
                        printf(" ________________________________________________________________________________________________\n");
                        printf("|                                                                                                |\n");
                        printf("|                                  **TRAVEL UTN ARGENTINA**                                      |\n");
                        printf("|                                        **PASSENGER**                                           |\n");
                        printf("|________________________________________________________________________________________________|\n");
                        printf("|   ID   |     NAME    |   LASTNAME  |   PRICE   | FLY CODE     | TYPE PASSENGER | STATUS FLIGHT |\n");
                        printf("|--------|-------------|-------------|-----------|--------------|----------------|---------------|\n");
                        printPassenger(list[indexEncontrado]);
                    }

               }while(opcion!=7);
               todoOk=0;
           }
           else
           {
                printf("\n\nNo se encontro ese ID en el sistema...\n");
           }
       }
       else
       {
           printf("\n\nNo se encontro ese ID en el sistema...\n");
       }
    }

    return todoOk;
}
int removePassenger(ePassenger* list, int len, int id)
{
    int todoOk=1;
    int indexEncontrado;
    char confirmar;

    if(list!=NULL && len>0)
    {
        printListPassenger(list, len);
        ingresoEntero(&id, "Ingrese el id que desea eliminar (1-2000): ", "Error. Ingrese el id que desea eliminar (1-2000):", 1, 2000);
        indexEncontrado=findPassengerById(list, len, id);
        if(indexEncontrado>=0 && indexEncontrado<len && list[indexEncontrado].isEmpty==0)
        {
            ingresoChar(&confirmar, "Desea eliminar esa Id del sistema s/n?: ");
            if(confirmar=='s' || confirmar=='S')
            {
                printf("\nSe ha dado de baja el Id:%d del sistema...\n", id);
                list[indexEncontrado].isEmpty=1;
                todoOk=0;
            }
            else
            {
                printf("\nSe ha cancelado la eliminacion...\n");
            }
        }
        else
        {
            printf("\nNo se encontro ese Id en el sistema...\n");
        }
    }

    return todoOk;
}
void printPassenger(ePassenger auxPassenger)
{
    printf("|  %4d  |  %-10s |  %-10s | %-9.2f |  %-10s  |       %-5d    |      %-4d     |\n", auxPassenger.id, auxPassenger.name, auxPassenger.lastName, auxPassenger.price, auxPassenger.flyCode, auxPassenger.typePassenger, auxPassenger.statusFlight);
}
int printListPassenger(ePassenger* list, int len)
{
    int todoOk=1;

    if(list!=NULL && len>0)
    {
        printf(" ________________________________________________________________________________________________\n");
        printf("|                                                                                                |\n");
        printf("|                                  **TRAVEL UTN ARGENTINA**                                      |\n");
        printf("|                                        **PASSENGER**                                           |\n");
        printf("|________________________________________________________________________________________________|\n");
        printf("|   ID   |     NAME    |   LASTNAME  |   PRICE   | FLY CODE     | TYPE PASSENGER | STATUS FLIGHT |\n");
        printf("|--------|-------------|-------------|-----------|--------------|----------------|---------------|\n");
      for(int i=0;i<len;i++)
      {
          if(list[i].isEmpty==0)
          {
             printPassenger(list[i]);
          }
      }
        printf("|________|_____________|_____________|___________|______________|________________|_______________|\n");
      todoOk=0;
    }

    return todoOk;
}
int pedirListado(int* campo)
{
    int todoOk=1;
    int elegirOpcion;

    if(campo!=NULL)
    {
        ingresoEntero(&elegirOpcion,    " ___________________________________________________________________________________________________ \n"
                                  "|                                                                                                   |\n"
                                  "|                                         **MENU IMFORN**                                           |\n"
                                  "|___________________________________________________________________________________________________|\n"
                                  "|                                                                                                   |\n"
                                  "|1-Listado de los pasajeros ordenados alfabeticamente por Apellido y Tipo de pasajero.              |\n"
                                  "|2-Total y promedio de los precios de los pasajes, y cuantos pasajeros superan el precio promedio.  |\n"
                                  "|3-Listado de los pasajeros por Codigo de vuelo y estados de vuelos ACTIVO                          |\n"
                                  "|4-Salir                                                                                            |\n"
                                  "|___________________________________________________________________________________________________|\n"
                                  "option: ",
                                  " ___________________________________________________________________________________________________ \n"
                                  "|                                                                                                   |\n"
                                  "|                                      REINGRESE OPTION (1-4)                                       |\n"
                                  "|___________________________________________________________________________________________________|\n"
                                  " ___________________________________________________________________________________________________ \n"
                                  "|                                                                                                   |\n"
                                  "|                                         **MENU IMFORN**                                           |\n"
                                  "|___________________________________________________________________________________________________|\n"
                                  "|                                                                                                   |\n"
                                  "|1-Listado de los pasajeros ordenados alfabeticamente por Apellido y Tipo de pasajero.              |\n"
                                  "|2-Total y promedio de los precios de los pasajes, y cuantos pasajeros superan el precio promedio.  |\n"
                                  "|3-Listado de los pasajeros por Codigo de vuelo y estados de vuelos ACTIVO                          |\n"
                                  "|4-Salir                                                                                            |\n"
                                  "|___________________________________________________________________________________________________|\n"
                                  "option: ", 1,4);
            *campo=elegirOpcion;
            todoOk=0;
    }

    return todoOk;
}
int mostrarListadoInforme(ePassenger* list, int len, int campo)
{
    int todoOk=1;
    float acumuladorPreciosVuelos=0.00;
    int cantidadPasajerosIngresados=0;
    float promedioFinalInforme;
    int contadorPasajerosSuperanElPromedio=0;

    if(list!=NULL && len>0)
    {

        switch(campo)
        {
            case 1:
            		ordenamientoPorApellidoTipoPasajero(list, len);
            		printListPassenger(list, len);
                break;
            case 2:
                promedioPrecioPasajes(list, len, &acumuladorPreciosVuelos, &cantidadPasajerosIngresados, &promedioFinalInforme);
                cantidadPasajerosConGastosSuperiorA(list, len, &contadorPasajerosSuperanElPromedio, promedioFinalInforme);
                printf("El total precios ingresados por los vuelos es: %.2f\n", acumuladorPreciosVuelos);
                printf("El promedio de los vuelos es: %.2f\n", promedioFinalInforme);
                printf("La cantidad de pasajeros que superan precio promedio de los vuelos es: %d\n", contadorPasajerosSuperanElPromedio);
                break;
            case 3:
                ordenamientoCodigoVueloEstadoActivo(list, len);
                break;
        }
        todoOk=0;
    }

    return todoOk;
}
int ordenamientoPorApellidoTipoPasajero(ePassenger* list, int len)
{
    int todoOk=1;
    ePassenger auxPassenger;

    if(list!=NULL && len>0)
    {
       for(int i=0;i<len;i++)
       {
           for(int j=i+1;j<len;j++)
           {
               if(strcmp(list[i].lastName, list[j].lastName)>0)
               {
                  auxPassenger=list[i];
                  list[i]=list[j];
                  list[j]=auxPassenger;
               }
               else if(strcmp(list[i].lastName, list[j].lastName)==0 && list[i].typePassenger>list[j].typePassenger)
               {
                  auxPassenger=list[i];
                  list[i]=list[j];
                  list[j]=auxPassenger;
               }
           }
       }
       todoOk=0;
    }

    return todoOk;
}
int ordenamientoCodigoVueloEstadoActivo(ePassenger* list, int len)
{
    int todoOk=1;
    ePassenger swapPasseger;

    if(list!=NULL && len>0)
    {
        for(int i=0;i<len;i++)
        {
            for(int j=i+1;j<len;j++)
            {
                  if(strcmp(list[i].flyCode, list[j].flyCode)>0)
                  {
                    swapPasseger=list[i];
                    list[i]=list[j];
                    list[j]=swapPasseger;
                  }
            }
        }
        printf(" ________________________________________________________________________________________________\n");
        printf("|                                                                                                |\n");
        printf("|                                  **TRAVEL UTN ARGENTINA**                                      |\n");
        printf("|                                        **PASSENGER**                                           |\n");
        printf("|________________________________________________________________________________________________|\n");
        printf("|   ID   |     NAME    |   LASTNAME  |   PRICE   | FLY CODE     | TYPE PASSENGER | STATUS FLIGHT |\n");
        printf("|--------|-------------|-------------|-----------|--------------|----------------|---------------|\n");
        for(int i=0;i<len;i++)
        {
            if(list[i].statusFlight==1 && list[i].isEmpty==0)
            {

                printPassenger(list[i]);
            }
        }
        printf("|________|_____________|_____________|___________|______________|________________|_______________|\n");
    }

    return todoOk;
}
int promedioPrecioPasajes(ePassenger* list, int len, float* acumuladorPrecioPasajes, int* cantidadPasajes, float* promedioPrecioPasajes)
{
    int todoOk=1;
    float acumuladorPrecio=0.00;
    int cantidadPasajesIngresados=0;
    float promedioFinal;

    if(list!=NULL && len>0 && acumuladorPrecioPasajes!=NULL && cantidadPasajes!=NULL && promedioPrecioPasajes!=NULL)
    {
        for(int i=0;i<len;i++)
        {
            if(list[i].price>0 && list[i].isEmpty==0)
            {
                cantidadPasajesIngresados++;
                acumuladorPrecio=acumuladorPrecio+list[i].price;
            }
        }
        promedioFinal=(float)(acumuladorPrecio/cantidadPasajesIngresados);
        *cantidadPasajes=cantidadPasajesIngresados;
        *acumuladorPrecioPasajes=acumuladorPrecio;
        *promedioPrecioPasajes=promedioFinal;
        todoOk=0;
    }

    return todoOk;
}
int cantidadPasajerosConGastosSuperiorA(ePassenger* list, int len, int* contadorPasajeros, float valor)
{
    int todoOk=1;
    int contador=0;

    if(list!=NULL && len>0 && contadorPasajeros!=NULL && valor>0)
    {
        for(int i=0;i<len;i++)
        {
            if(list[i].price>valor && list[i].isEmpty==0)
            {
                contador++;
                todoOk=1;
            }
        }
        *contadorPasajeros=contador;
    }

    return todoOk;
}





