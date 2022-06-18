#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include "inputs.h"

int menuPrincipal()
{
	int opcion;

	printf( " ________________________________________________________________________________ \n"
			"|                                                                                |\n"
			"|                                **MENU PRINCIPAL**                              |\n"
			"|                             **UTN TRAVEL ARGENTINA**                           |\n"
			"|________________________________________________________________________________|\n"
			"|                                                                                |\n"
			"|1-CARGAR LOS DATOS DE LOS PASAJEROS DESDE EL ARCHIVO data.csv (modo texto).     |\n"
			"|2-CARGAR LOS DATOS DE LOS PASAJEROS DESDE EL ARCHIVO data.bin (modo binario).   |\n"
			"|3-ALTA DE PASAJERO.                                                             |\n"
			"|4-MODIFICAR DATOS DEL PASAJERO.                                                 |\n"
			"|5-BAJA DEL PASAJERO.                                                            |\n"
			"|6-LISTAR PASAJEROS.                                                             |\n"
			"|7-ORDENAR PASAJEROS.                                                            |\n"
			"|8-REINICIAR LISTA (borra todos los elementos de la lista).                      |\n"
			"|9-INFORMES TRAVEL UTN ARG (Aplico los linkedlist que faltan).                   |\n"
			"|10-GUARDAR LOS DATOS DE LOS EMPLEADOS EN EL ARCHIVO data.csv (modo texto).      |\n"
			"|11-GUARDAR LOS DATOS DE LOS EMPLEADOS EN EL ARCHIVO data.bin (modo binario).    |\n"
			"|12-SALIR.                                                                       |\n"
			"|________________________________________________________________________________|\n");

	printf("Usted eligio: ");
	scanf("%d", &opcion);

	return opcion;
}
int menuModificaciones()
{
	int opcion;

	printf(" _______________________________________________ \n"
			"|                                               |\n"
			"|          **MENU DE MODIFICACIONES**           |\n"
			"|           **UTN TRAVEL ARGENTINA**            |\n"
			"|_______________________________________________|\n"
			"|                                               |\n"
			"|1-MODIFICAR NOMBRE.                            |\n"
			"|2-MODIFICAR APELLIDO.                          |\n"
			"|3-MODIFICAR PRECIO.                            |\n"
			"|4-MODIFICAR CODIGO DE VUELO.                   |\n"
			"|5-MODIFICAR TIPO DE PASAJERO.                  |\n"
			"|6-MODIFICAR ESTADO DE VUELO.                   |\n"
			"|7-SALIR.                                       |\n"
			"|_______________________________________________|\n");

	printf("Usted eligio: ");
	scanf("%d", &opcion);

	return opcion;
}
int menuPrincipalOrdenamiento()
{
	int opcion;

	printf(" _______________________________________________ \n"
			"|                                               |\n"
			"|           **MENU DE ORDENAMIENTO**            |\n"
			"|           **UTN TRAVEL ARGENTINA**            |\n"
			"|_______________________________________________|\n"
			"|                                               |\n"
			"|1-ORDENAMIENTO POR ID.                         |\n"
			"|2-ORDENAMIENTO POR NOMBRE.                     |\n"
			"|3-ORDENAMIENTO POR APELLIDO.                   |\n"
			"|4-ORDENAMIENTO POR PRECIO.                     |\n"
			"|5-ORDENAMIENTO POR CODIGO DE VUELO.            |\n"
			"|6-ORDENAMIENTO POR TIPO DE PASAJERO.           |\n"
			"|7-ORDENAMIENTO POR ESTADO DE VUELO.            |\n"
			"|8-SALIR.                                       |\n"
			"|_______________________________________________|\n");

	printf("Usted eligio: ");
	scanf("%d", &opcion);

	return opcion;
}
int menuCriterioOrdenamiento(int* tipo)
{
	int todoOk=1;
	int elegirOpcion;

	if(tipo!=NULL)
	{
		ingresoEntero(&elegirOpcion,      " _____________________________________________ \n"
				"|                                             |\n"
				"|         **MENU TIPO ORDENAMIENTO**          |\n"
				"|_____________________________________________|\n"
				"|                                             |\n"
				"|1-ASCENDENTE                                 |\n"
				"|2-DESCENDENTE                                |\n"
				"|3-Salir                                      |\n"
				"|_____________________________________________|\n"
				"option: ",
				" _____________________________________________ \n"
				"|                                             |\n"
				"|            REINGRESE OPTION (1-3)           |\n"
				"|_____________________________________________|\n"
				" _____________________________________________ \n"
				"|                                             |\n"
				"|         **MENU TIPO ORDENAMIENTO**          |\n"
				"|_____________________________________________|\n"
				"|                                             |\n"
				"|1-ASCENDENTE                                 |\n"
				"|2-DESCENDENTE                                |\n"
				"|3-Salir                                      |\n"
				"|_____________________________________________|\n"
				"option: ", 1,3);
		*tipo=elegirOpcion;
		todoOk=0;
	}

	return todoOk;
}
int menuInformes()
{

	int opcion;

	printf(" ________________________________________________________________________________ \n"
			"|                                                                                |\n"
			"|                                   **INFORMES**                                 |\n"
			"|                             **UTN TRAVEL ARGENTINA**                           |\n"
			"|________________________________________________________________________________|\n"
			"|                                                                                |\n"
			"|1-INFORME SUD LISTADO SELECCIONADO POR EL USUARIO.                              |\n"
			"|2-INFORME ELIMINA UN PASAJERO CON MENOR PRECIO.                                 |\n"
			"|3-INFORME ALTA EN POSICION ELEGIDA                                              |\n"
			"|4-SALIR.                                                                        |\n"
			"|________________________________________________________________________________|\n");

	printf("Usted eligio: ");
	scanf("%d", &opcion);

	return opcion;
}
