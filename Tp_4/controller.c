#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include "LinkedList.h"
#include "Passenger.h"
#include "parser.h"
#include "controller.h"
#include "inputs.h"
#include "menu.h"

/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListPassenger)
{
	int retorno=-1;
	FILE* pFile=fopen(path, "r");

	if(pArrayListPassenger!=NULL && path!=NULL)
	{
		printf("Invoco al controller texto\n");
		parser_PassengerFromText(pFile, pArrayListPassenger);
		retorno=1;
	}
	return retorno;
}

/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListPassenger)
{
	int retorno=-1;

	if(pArrayListPassenger!=NULL && path!=NULL)
	{
		printf("Invoco al controller binario\n");
		FILE* pFile = fopen(path, "rb");
		if(pFile!=NULL)
		{
			parser_PassengerFromBinary(pFile , pArrayListPassenger);
			retorno=1;
		}
	}

	return retorno;
}

/** \brief Alta de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_addPassenger(LinkedList* pArrayListPassenger)
{
	int todoOk=-1;
	int idPassengerActual;
	char afirmacion;
	Passenger* pasajeroNuevoAlta=NULL;


	if(pArrayListPassenger!=NULL && ll_isEmpty(pArrayListPassenger)>=0)
	{
		printf(" ___________________________________________________________________________________ \n");
		printf("|                                                                                   |\n");
		printf("|                                ***ALTA PASAJERO***                                |\n");
		printf("|___________________________________________________________________________________|\n\n");

		pasajeroNuevoAlta=Passenger_altaPasajero();

		idPassengerActual=controller_getUltimoId();

		Passenger_setId(pasajeroNuevoAlta, idPassengerActual);

		if(pasajeroNuevoAlta!=NULL)
		{

			printf(" _____________________________________________________________________________________________________________________ \n");
			printf("|       |              |              |            |                     |                      |                     |\n");
			printf("| *ID*  |   *NOMBRE*   |  *APELLIDO*  |  *PRECIO*  |  *CODIGO DE VUELO*  |  *TIPO DE PASAJERO*  |  *ESTADO DE VUELO*  |\n");
			printf("|_______|______________|______________|____________|_____________________|______________________|_____________________|\n");
			Passenger_mostrarUnPasajero(pasajeroNuevoAlta);
			printf("|_______|______________|______________|____________|_____________________|______________________|_____________________|\n");

			ingresoChar(&afirmacion, "\n Ingrese s para comfirmar el Pasajero y guardar los datos... ");

			if(afirmacion=='s' || afirmacion=='S')
			{

				ll_add(pArrayListPassenger, pasajeroNuevoAlta);
				Passenger_actualizarUltimoId(idPassengerActual);
				printf("Pasajero dado de alto correctamente...\n");
				todoOk=1;
			}
			else
			{
				Passenger_delete(pasajeroNuevoAlta);
				printf("Se cancelo el dada de alta del pasajero...\n");
			}
		}

	}


    return todoOk;
}

/** \brief Modificar datos de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_editPassenger(LinkedList* pArrayListPassenger)
{
	int todoOK=-1;
	int idIngresado;
	int indiceEncontradoModificar;
	char afirmacion;
	int opcion;
	char nombre[50];
	char apellido[50];
	float auxPrecio;
	char precio[1000];
	char auxCodigoVuelo[10];
	int auxTipoPasajero;
	char tipoPasajero[1000];
	int auxEstadoVuelo;
	char estadoVuelo[1000];
	Passenger* empleadoModificar=NULL;


	if(pArrayListPassenger!=NULL && ll_isEmpty(pArrayListPassenger)>=0)
	{
		printf(" ___________________________________________________________________________________ \n");
		printf("|                                                                                   |\n");
		printf("|                             ***MODIFICAR PASAJERO***                              |\n");
		printf("|___________________________________________________________________________________|\n\n");

		controller_ListPassenger(pArrayListPassenger);

		ingresoEnteroPro(&idIngresado, "Ingrese el id que desea modificar: ", "Error. Ingrese el id que desea modificar: ", 1, 2000);

		indiceEncontradoModificar=controller_buscarIdPasajero( pArrayListPassenger, idIngresado);

		empleadoModificar=ll_get(pArrayListPassenger, indiceEncontradoModificar);

		if(empleadoModificar!=NULL && indiceEncontradoModificar>=0 && indiceEncontradoModificar<ll_len(pArrayListPassenger))
		{
			printf(" _____________________________________________________________________________________________________________________ \n");
			printf("|       |              |              |            |                     |                      |                     |\n");
			printf("| *ID*  |   *NOMBRE*   |  *APELLIDO*  |  *PRECIO*  |  *CODIGO DE VUELO*  |  *TIPO DE PASAJERO*  |  *ESTADO DE VUELO*  |\n");
			printf("|_______|______________|______________|____________|_____________________|______________________|_____________________|\n");
			Passenger_mostrarUnPasajero(empleadoModificar);
			printf("|_______|______________|______________|____________|_____________________|______________________|_____________________|\n");

			ingresoChar(&afirmacion, "\n Ingrese s/n para confirmar la mofidicacion...");

			if(afirmacion=='s' || afirmacion=='S')
			{
				do
				{
					opcion=menuModificaciones();

					switch(opcion)
					{
						case 1:
							ingresoCadena(nombre,"Ingrese el nombre del pasajero(letras entre 3-50): ","Error. Ingrese el nombre del pasajero(letras entre 3-50): ",50, 3);
							Passenger_setNombre(empleadoModificar, nombre);
							break;
						case 2:
							ingresoCadena(apellido,"Ingrese el apellido del pasajero(letras entre 3-50): ","Error. Ingrese el apellido del pasajero(letras entre 3-50): ",50, 3);
							Passenger_setApellido(empleadoModificar, apellido);
							break;
						case 3:
							ingresoFlotante(&auxPrecio, "Ingrese el precio del vuelo (10000-50000): ", "Error. Ingrese el precio del vuelo (10000-50000): ", 10000.00, 50000.00);
							Passenger_setPrecio(empleadoModificar, auxPrecio);
							itoa(auxPrecio, precio, 10);
							break;
						case 4:
							ingresoLetrasNumeros(auxCodigoVuelo, "Ingrese el codigo del vuelo (max 10 caracteres): ", "Error. Ingrese el codigo del vuelo (max 10 caracteres): ", 10, 6);
							Passenger_setCodigoVuelo(empleadoModificar, auxCodigoVuelo);
							break;
						case 5:
							printf(" ________________________ \n");
							printf("|                        |\n");
							printf("|   *TIPO DE PASAJERO*   |\n");
							printf("|________________________|\n");
							printf("|                        |\n");
							printf("|  1 - Primera clase     |\n");
							printf("|  2 - Clase ejecutiva   |\n");
							printf("|  3 - Clase economica   |\n");
							printf("|________________________|\n");
							ingresoEntero(&auxTipoPasajero, "Ingrese el tipo de pasajero: ", "Error. Ingrese el tipo de pasajero: ", 1, 3);
							Passenger_setTipoPasajero(empleadoModificar, auxTipoPasajero);
							itoa(auxTipoPasajero, tipoPasajero, 10);
							break;
						case 6:
							printf(" _______________________ \n");
							printf("|                       |\n");
							printf("|   *ESTADO DE VUELO*   |\n");
							printf("|_______________________|\n");
							printf("|                       |\n");
							printf("|  1 - Aterrizado       |\n");
							printf("|  2 - En Horario       |\n");
							printf("|  3 - En Vuelo         |\n");
							printf("|  4 - Demorado         |\n");
							printf("|_______________________|\n");
							ingresoEntero(&auxEstadoVuelo, "Ingrese el estado de vuelo: ", "Error. Ingrese el estado de vuelo: ", 1, 4);
							Passenger_setEstadoVuelo(empleadoModificar, auxEstadoVuelo);
							itoa(auxEstadoVuelo, estadoVuelo, 10);
							break;
						case 7:
							printf("\nSaliendo del menu de modificaciones\n\n");
							break;
						default:
							printf("Error. Ingrese una opcion (1-7): \n");
							break;
					}

				}while(opcion!=7);
				if(opcion<1 || opcion>6)
				{
					printf(" _____________________________________________________________________________________________________________________ \n");
					printf("|       |              |              |            |                     |                      |                     |\n");
					printf("| *ID*  |   *NOMBRE*   |  *APELLIDO*  |  *PRECIO*  |  *CODIGO DE VUELO*  |  *TIPO DE PASAJERO*  |  *ESTADO DE VUELO*  |\n");
					printf("|_______|______________|______________|____________|_____________________|______________________|_____________________|\n");
					Passenger_mostrarUnPasajero(empleadoModificar);
					printf("|_______|______________|______________|____________|_____________________|______________________|_____________________|\n");

					printf("\nEl Id del pasejero %d fue modificado...\n\n", idIngresado);
				}
				todoOK=1;
			}
			else
			{
				printf("\nSe cancelo la modificacion del pasajero con el id %d\n", idIngresado);
			}
		}
		else
		{
			printf("\nNo se encontro ningun pasajero con el id %d\n", idIngresado);
		}

	}
	return todoOK;
}

/** \brief Baja de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_removePassenger(LinkedList* pArrayListPassenger)
{
	int todoOK=-1;
	int idIngresado;
	int indiceEncontradoEliminar;
	char afirmacion;
	Passenger* empleadoEliminar=NULL;

	if(pArrayListPassenger!=NULL && ll_isEmpty(pArrayListPassenger)>=0)
	{
		printf(" ___________________________________________________________________________________ \n");
		printf("|                                                                                   |\n");
		printf("|                              ***ELIMINAR PASAJERO***                              |\n");
		printf("|___________________________________________________________________________________|\n\n");

		controller_ListPassenger(pArrayListPassenger);

		ingresoEnteroPro(&idIngresado, "Ingrese el id que desea modificar: ", "Error. Ingrese el id que desea modificar: ", 1, 2000);

		indiceEncontradoEliminar=controller_buscarIdPasajero( pArrayListPassenger, idIngresado);

		empleadoEliminar=ll_get(pArrayListPassenger, indiceEncontradoEliminar);

		if(empleadoEliminar!=NULL && indiceEncontradoEliminar>=0 && indiceEncontradoEliminar<ll_len(pArrayListPassenger))
		{
			printf(" _____________________________________________________________________________________________________________________ \n");
			printf("|       |              |              |            |                     |                      |                     |\n");
			printf("| *ID*  |   *NOMBRE*   |  *APELLIDO*  |  *PRECIO*  |  *CODIGO DE VUELO*  |  *TIPO DE PASAJERO*  |  *ESTADO DE VUELO*  |\n");
			printf("|_______|______________|______________|____________|_____________________|______________________|_____________________|\n");
			Passenger_mostrarUnPasajero(empleadoEliminar);
			printf("|_______|______________|______________|____________|_____________________|______________________|_____________________|\n");

			ingresoChar(&afirmacion, "\n Ingrese s/n para confirmar la eliminacion...");

			if(afirmacion=='s' || afirmacion=='S')
			{
				ll_remove(pArrayListPassenger, indiceEncontradoEliminar);
				Passenger_delete(empleadoEliminar);
				printf("\nEl Id del pasejero %d fue eliminado...\n\n", idIngresado);
			}
			else
			{
				printf("\nSe cancelo la eliminacion del pasajero con el id %d\n", idIngresado);
			}
			todoOK=1;
		}
		else
		{
			printf("\nNo se encontro ningun pasajero con el id %d\n", idIngresado);
		}

	}
	return todoOK;
}

/** \brief Listar pasajeros
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_ListPassenger(LinkedList* pArrayListPassenger)
{
	int todoOk=-1;

	if(pArrayListPassenger!=NULL)
	{
		int lenList = ll_len(pArrayListPassenger);


		printf(" _____________________________________________________________________________________________________________________ \n");
		printf("|                                                                                                                     |\n");
		printf("|                                           ***LISTADO DE PASAJEROS***                                                |\n");
		printf("|                                            **UTN TRAVEL ARGENTINA**                                                 |\n");
		printf("|                                                                                                                     |\n");
		printf("|_____________________________________________________________________________________________________________________|\n");
		printf("|       |              |              |            |                     |                      |                     |\n");
		printf("| *ID*  |   *NOMBRE*   |  *APELLIDO*  |  *PRECIO*  |  *CODIGO DE VUELO*  |  *TIPO DE PASAJERO*  |  *ESTADO DE VUELO*  |\n");
		printf("|_______|______________|______________|____________|_____________________|______________________|_____________________|\n");

		for (int i=0; i < lenList; ++i)
		{
			Passenger* pPassenger = ll_get(pArrayListPassenger, i);
			Passenger_mostrarUnPasajero(pPassenger);
		}

		printf("|_______|______________|______________|____________|_____________________|______________________|_____________________|\n");

		todoOk=1;
	}
	return todoOk;
}

/** \brief Ordenar pasajeros
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_sortPassenger(LinkedList* pArrayListPassenger)
{
	int todoOk=-1;
	char salir;
	int opcion;
	int tipo;
    LinkedList* listaAuxliar;

	if(pArrayListPassenger!=NULL)
	{
	    int(*pFuncionOrdenar)(void*,void*);
	    listaAuxliar=ll_clone(pArrayListPassenger);

        if(ll_isEmpty(listaAuxliar)>=0 && ll_containsAll(pArrayListPassenger, listaAuxliar))
        {
           do
            {
                opcion=menuPrincipalOrdenamiento();

                switch(opcion)
                {
                    case 1:
                        menuCriterioOrdenamiento(&tipo);
                        switch(tipo)
                        {
                            case 1:
                                pFuncionOrdenar=Passenger_ordenarPorId;
                                ll_sort(listaAuxliar, pFuncionOrdenar, 1);
                                break;
                            case 2:
                                pFuncionOrdenar=Passenger_ordenarPorId;
                                ll_sort(listaAuxliar, pFuncionOrdenar, 0);
                                break;
                        }
                        break;
                    case 2:
                        menuCriterioOrdenamiento(&tipo);
                        switch(tipo)
                        {
                            case 1:
                                pFuncionOrdenar=Passenger_ordenarPorNombre;
                                ll_sort(listaAuxliar, pFuncionOrdenar, 1);
                                break;
                            case 2:
                                pFuncionOrdenar=Passenger_ordenarPorNombre;
                                ll_sort(listaAuxliar, pFuncionOrdenar, 0);
                                break;
                        }
                        break;
                    case 3:
                        menuCriterioOrdenamiento(&tipo);
                        switch(tipo)
                        {
                            case 1:
                                pFuncionOrdenar=Passenger_ordenarPorApellido;
                                ll_sort(listaAuxliar, pFuncionOrdenar, 1);
                                break;
                            case 2:
                                pFuncionOrdenar=Passenger_ordenarPorApellido;
                                ll_sort(listaAuxliar, pFuncionOrdenar, 0);
                                break;
                        }
                        break;
                    case 4:
                        menuCriterioOrdenamiento(&tipo);
                        switch(tipo)
                        {
                            case 1:
                                pFuncionOrdenar=Passenger_ordenarPorPrecio;
                                ll_sort(listaAuxliar, pFuncionOrdenar, 1);
                                break;
                            case 2:
                                pFuncionOrdenar=Passenger_ordenarPorPrecio;
                                ll_sort(listaAuxliar, pFuncionOrdenar, 0);
                                break;
                        }
                        break;
                    case 5:
                        menuCriterioOrdenamiento(&tipo);
                        switch(tipo)
                        {
                            case 1:
                                pFuncionOrdenar=Passenger_ordenarPorCodigoDeVuelo;
                                ll_sort(listaAuxliar, pFuncionOrdenar, 1);
                                break;
                            case 2:
                                pFuncionOrdenar=Passenger_ordenarPorCodigoDeVuelo;
                                ll_sort(listaAuxliar, pFuncionOrdenar, 0);
                                break;
                        }
                        break;
                    case 6:
                        menuCriterioOrdenamiento(&tipo);
                        switch(tipo)
                        {
                            case 1:
                                pFuncionOrdenar=Passenger_ordenarPorTipoPasajero;
                                ll_sort(listaAuxliar, pFuncionOrdenar, 1);
                                break;
                            case 2:
                                pFuncionOrdenar=Passenger_ordenarPorTipoPasajero;
                                ll_sort(listaAuxliar, pFuncionOrdenar, 0);
                                break;
                        }
                        break;
                    case 7:
                        menuCriterioOrdenamiento(&tipo);
                        switch(tipo)
                        {
                            case 1:
                                pFuncionOrdenar=Passenger_ordenarPorEstadoVuelo;
                                ll_sort(listaAuxliar, pFuncionOrdenar, 1);
                                break;
                            case 2:
                                pFuncionOrdenar=Passenger_ordenarPorEstadoVuelo;
                                ll_sort(listaAuxliar, pFuncionOrdenar, 0);
                                break;
                        }
                        break;
                    case 8:
                        ingresoChar(&salir, "Ingrese  S para salir del menu de ordenamiento (s/n): ");
                        break;
                    default:
                        printf("ERROR. INGRESE UNA OPCION (1-8)\n");
                        break;
                }

            }while(salir!='s');
            if(opcion<1 || opcion>7)
            {
                controller_ListPassenger(listaAuxliar);
            }
            ll_deleteLinkedList(listaAuxliar);
            todoOk=0;
        }
		else
        {
           printf("\nNo se han ingresado ningun elemento a la lista pasajeros\n");
		}
	}

    return todoOk;
}

/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListPassenger)
{
	int todoOk=-1;
	int id;
	char nombre[50];
	char apellido[50];
	float precio;
	char codigoDeVuelo[10];
	int tipoPasajero;
	int estadoVuelo;

	Passenger* pasajero=NULL;
	FILE* pFile;

	if(path!=NULL && pArrayListPassenger!=NULL)
	{
		pFile=fopen(path, "w");

		pasajero=Passenger_new();

		if(pasajero!=NULL)
		{
			fprintf(pFile, "id,nombre,apellido,precio,codigoVuelo,tipoPasajero,estadoVuelo\n");
			for(int i=0; i<ll_len(pArrayListPassenger); i++)
			{
				pasajero=(Passenger*) ll_get(pArrayListPassenger, i);
				if(pasajero!=NULL)
				{
					Passenger_getId(pasajero, &id);
					Passenger_getNombre(pasajero, nombre);
					Passenger_getApellido(pasajero, apellido);
					Passenger_getPrecio(pasajero, &precio);
					Passenger_getCodigoVuelo(pasajero, codigoDeVuelo);
					Passenger_getTipoPasajero(pasajero, &tipoPasajero);
					Passenger_getEstadoVuelo(pasajero, &estadoVuelo);

					fprintf(pFile,"%d,%s,%s,%.2f,%s,%d,%d\n", id, nombre, apellido, precio, codigoDeVuelo, tipoPasajero, estadoVuelo);
					todoOk=1;
				}
				else
				{
					todoOk=0;
					break;
				}
			}
		}
		fclose(pFile);

		if(todoOk)
		{
			printf("Se ha guardado correctamente el listado!\n");
		}
	}

	return todoOk;
}

/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListPassenger)
{
	printf("Guardando... archivo binario\n");
	int todoOK=0;
	int tamArray;

	tamArray= ll_len(pArrayListPassenger);

	FILE* pFile;
	pFile = fopen(path, "wb");

	if(pFile!=NULL&& path!=NULL)
	{
		for (int var=0;var<tamArray;++var)
		{
			Passenger* auxPassenger= ll_get(pArrayListPassenger,var);
			fwrite(auxPassenger, sizeof(Passenger), 1, pFile);
		}
		printf("Archivo escrito con exito!\n");
		todoOK=1;
	}
	fclose(pFile);
	return todoOK;
}
int controller_getUltimoId()
{
	int ultimoId=1;
	char ultimoIdStr[100];

	FILE* pFile = fopen("ultimoId.txt", "r");

	if(pFile != NULL)
	{
		fscanf(pFile, "%[^\n]", ultimoIdStr);

		ultimoId=atoi(ultimoIdStr);
	}
	else
	{
	    pFile=fopen("ultimoId.txt", "w");
	    fprintf(pFile, "%d\n", ultimoId);
	}
	fclose(pFile);

	return ultimoId;
}
int controller_buscarIdPasajero(LinkedList* pArrayListPassenger, int idPasajero)
{
	int indiceEncontrado=-1;
	int idEncontrado;
	int tam;
	Passenger* pasajero;

	if(pArrayListPassenger!=NULL && idPasajero>=0)
	{
		tam=ll_len(pArrayListPassenger);// tam Passenger

		for(int i=0;i<tam;i++)
		{
			pasajero=ll_get(pArrayListPassenger, i);

			if(pasajero!=NULL)
			{
				Passenger_getId(pasajero, &idEncontrado);

				if(idEncontrado==idPasajero)// comparo el id con lo q imgreso el usuario
				{
					indiceEncontrado=i;//retorno el indice encontrado por parametro
				}
			}
		}
	}

	return indiceEncontrado;
}
int controller_ListPassengerInforme(LinkedList* pArrayListPassenger)
{
	int todoOk=-1;

	if(pArrayListPassenger!=NULL)
	{
		int lenList = ll_len(pArrayListPassenger);


            printf(" _____________________________________________________________________________________________________________________ \n");
            printf("|                                                                                                                     |\n");
            printf("|                                   SUD LISTADO DE PASAJEROS SELECIONADO UTN TRAVEL                                   |\n");
            printf("|_____________________________________________________________________________________________________________________|\n");
            printf("|       |              |              |            |                     |                      |                     |\n");
            printf("| *ID*  |   *NOMBRE*   |  *APELLIDO*  |  *PRECIO*  |  *CODIGO DE VUELO*  |  *TIPO DE PASAJERO*  |  *ESTADO DE VUELO*  |\n");
            printf("|_______|______________|______________|____________|_____________________|______________________|_____________________|\n");

		for (int i=0; i < lenList; ++i)
		{
			Passenger* pPassenger = ll_get(pArrayListPassenger, i);
			Passenger_mostrarUnPasajero(pPassenger);
		}

		printf("|_______|______________|______________|____________|_____________________|______________________|_____________________|\n");
        todoOk=0;
	}
	return todoOk;
}
int controller_InformeSudListadoPorRangoSelecionado(LinkedList* pArrayListPassenger)
{
    int todoOk=-1;
    int indiceIdSwapPrimero;
    int idSwapIngresadoPrimero;
    int indiceIdSwapSegundo;
    int idSwapIngresadoSegundo;
    LinkedList* listaPasajerosAux=NULL;

    if(pArrayListPassenger!=NULL && ll_isEmpty(pArrayListPassenger)>=0)
    {
        printf(" ______________________________________________________________________________________ \n");
        printf("|                                                                                      |\n");
        printf("|             UTN TRAVEL INFORME CAMBIAR DE LUGAR ID DE LA LISTA PRINCIPAL             |\n");
        printf("|______________________________________________________________________________________|\n");

        controller_ListPassenger(pArrayListPassenger);

        ingresoEnteroPro(&idSwapIngresadoPrimero, "Ingrese el id que desea cambiar de ubicacion a la 1era: ", "Error. Ingrese el id que desea cambiar de ubicacion a la 1era: ", 1, 2000);
        indiceIdSwapPrimero=controller_buscarIdPasajero(pArrayListPassenger, idSwapIngresadoPrimero);

        while(indiceIdSwapPrimero==-1)
        {
            ingresoEnteroPro(&idSwapIngresadoPrimero, "Ingrese el id que desea cambiar de ubicacion a la 1era: ", "Error. Ingrese el id que desea cambiar de ubicacion a la 1era: ", 1, 2000);
            indiceIdSwapPrimero=controller_buscarIdPasajero(pArrayListPassenger, idSwapIngresadoPrimero);
        }

        ingresoEnteroPro(&idSwapIngresadoSegundo, "Ingrese el id que desea cambiar a la ultima ubicacion: ", "Error. Ingrese el id que desea cambiar a la ultima ubicacion: ", 1, 2000);
        indiceIdSwapSegundo=controller_buscarIdPasajero(pArrayListPassenger, idSwapIngresadoSegundo);

        while(indiceIdSwapSegundo==-1)
        {
            ingresoEnteroPro(&idSwapIngresadoSegundo, "Ingrese el id que desea cambiar a la ultima ubicacion: ", "Error. Ingrese el id que desea cambiar a la ultima ubicacion: ", 1, 2000);
            indiceIdSwapSegundo=controller_buscarIdPasajero(pArrayListPassenger, idSwapIngresadoSegundo);
        }

        listaPasajerosAux=ll_subList(pArrayListPassenger, indiceIdSwapPrimero, indiceIdSwapSegundo+1);

        if(listaPasajerosAux!=NULL)
        {
            controller_ListPassengerInforme(listaPasajerosAux);
            todoOk=0;
            ll_deleteLinkedList(listaPasajerosAux);
        }
        else
        {
            printf("Error no se pudo hacer la sub lista...\n");
        }
    }
    else
	{
		printf("\nNo han ingresado elementos a la lista...\n");
	}

    return todoOk;
}
int controller_InformeEliminarPasajeroMenorPrecio(LinkedList* pArrayListPassenger)
{
    int todoOk=-1;
    int tam;
    Passenger* auxPasajero=NULL;
    int flagMenorPrecio=0;
    float menorPrecio;
    int indicePasajeroMenorPrecio;

    if(pArrayListPassenger!=NULL && ll_isEmpty(pArrayListPassenger)>=0)
    {
        printf(" ______________________________________________________________________________________ \n");
        printf("|                                                                                      |\n");
        printf("|             UTN TRAVEL INFORME ELIMINAR PASAJERO CON MENOR PRECIO DE VUELO           |\n");
        printf("|______________________________________________________________________________________|\n");

        if(ll_len(pArrayListPassenger)>0)
        {
            tam=ll_len(pArrayListPassenger);

            for(int i=0;i<tam;i++)
            {
                auxPasajero=ll_get(pArrayListPassenger, i);

                if(auxPasajero!=NULL)
                {
                    if(flagMenorPrecio==0 || auxPasajero->precio<menorPrecio)
                    {
                        menorPrecio=auxPasajero->precio;
                        flagMenorPrecio=1;
                    }
                }
            }

            for(int i=0;i<tam;i++)
            {
                auxPasajero=ll_get(pArrayListPassenger, i);

                if(auxPasajero!=NULL)
                {
                    if(menorPrecio==auxPasajero->precio)
                    {
                        indicePasajeroMenorPrecio=ll_indexOf(pArrayListPassenger, auxPasajero);
                        break;
                    }
                }
            }

            auxPasajero=ll_pop(pArrayListPassenger, indicePasajeroMenorPrecio);

            if(auxPasajero!=NULL)
            {
                printf("El pasajero fue eliminado correctamente y el menor precio fue $%.2f\n", menorPrecio);

                printf(" _____________________________________________________________________________________________________________________ \n");
                printf("|                                                                                                                     |\n");
                printf("|                                       El PASAJERO ELIMINADO UTN TRAVEL                                              |\n");
                printf("|_____________________________________________________________________________________________________________________|\n");
                printf("|       |              |              |            |                     |                      |                     |\n");
                printf("| *ID*  |   *NOMBRE*   |  *APELLIDO*  |  *PRECIO*  |  *CODIGO DE VUELO*  |  *TIPO DE PASAJERO*  |  *ESTADO DE VUELO*  |\n");
                printf("|_______|______________|______________|____________|_____________________|______________________|_____________________|\n");
                Passenger_mostrarUnPasajero(auxPasajero);
                printf("|_______|______________|______________|____________|_____________________|______________________|_____________________|\n");

                Passenger_delete(auxPasajero);
                todoOk=0;
            }
        }
        else
        {
            printf("\nNo se han ingresado pasajeros...\n");
        }
    }

    return todoOk;
}
int controller_InformeAltaEnPosicionSelecionada(LinkedList* pArrayListPassenger)
{
    int todoOk=-1;
	int idPassengerActual;
	char afirmacion;
	Passenger* pasajeroNuevoAlta=NULL;
    int idSelecionadoPorElUsuario;
    int indiceEncontradoSlecionado;

	if(pArrayListPassenger!=NULL && ll_isEmpty(pArrayListPassenger)>=0)
	{
		printf(" ______________________________________________________________________________________ \n");
        printf("|                                                                                      |\n");
        printf("|             UTN TRAVEL INFORME ALTA PASAJERO EN UNA UBICACION SELECIONADA            |\n");
        printf("|______________________________________________________________________________________|\n");

		pasajeroNuevoAlta=Passenger_altaPasajero();

		idPassengerActual=controller_getUltimoId();

		Passenger_setId(pasajeroNuevoAlta, idPassengerActual);

		if(pasajeroNuevoAlta!=NULL)
		{

			printf(" _____________________________________________________________________________________________________________________ \n");
			printf("|       |              |              |            |                     |                      |                     |\n");
			printf("| *ID*  |   *NOMBRE*   |  *APELLIDO*  |  *PRECIO*  |  *CODIGO DE VUELO*  |  *TIPO DE PASAJERO*  |  *ESTADO DE VUELO*  |\n");
			printf("|_______|______________|______________|____________|_____________________|______________________|_____________________|\n");
			Passenger_mostrarUnPasajero(pasajeroNuevoAlta);
			printf("|_______|______________|______________|____________|_____________________|______________________|_____________________|\n");

			ingresoChar(&afirmacion, "\n Ingrese s para comfirmar el Pasajero y guardar los datos (s/n): ");

			if(afirmacion=='s' || afirmacion=='S')
			{
			    if(ll_contains(pArrayListPassenger, pasajeroNuevoAlta)==0)
                {
                    controller_ListPassenger(pArrayListPassenger);

                    ingresoEnteroPro(&idSelecionadoPorElUsuario, "Ingrese el pasajero en su posicion: ", "Error. Ingrese el pasajero en su posicion: ", 1, ll_len(pArrayListPassenger));

                    indiceEncontradoSlecionado=controller_buscarIdPasajero(pArrayListPassenger, idSelecionadoPorElUsuario);

                    if(!ll_push(pArrayListPassenger, indiceEncontradoSlecionado+1, pasajeroNuevoAlta))
                    {
                        printf("Se dio de alta correctamente el pasajero en el lugar selecionado por el usuario...\n");
                        todoOk=1;
                    }

                    todoOk=1;
                }
                else
                {
                    printf("\nSe ha producido un error con el pasajero ingresado...\n");
                }
			}
			else
			{
				Passenger_delete(pasajeroNuevoAlta);
				printf("Se cancelo el dada de alta del pasajero...\n");
			}
		}

	}

    return todoOk;
}

int controller_Informes(LinkedList* pArrayListPassenger)
{
    int todoOk=-1;
    int opcion;
    char afirmacion;

    if(pArrayListPassenger!=NULL)
    {
        do
        {
            opcion=menuInformes();

            switch(opcion)
            {
                case 1:
                    controller_InformeSudListadoPorRangoSelecionado(pArrayListPassenger);
                    break;
                case 2:
                    controller_InformeEliminarPasajeroMenorPrecio(pArrayListPassenger);
                    break;
                case 3:
                    controller_InformeAltaEnPosicionSelecionada(pArrayListPassenger);
                    break;
                case 4:
                    ingresoChar(&afirmacion,"\nDesea salir del menu de informes (s/n): ");
                    break;
                default:
                    break;
            }

        }while(afirmacion!='s');

        todoOk=0;
    }

    return todoOk;
}
