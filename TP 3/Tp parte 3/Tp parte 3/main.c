#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "inputs.h"


int main()
{
	setbuf(stdout, NULL);
    int option;
    int banderaPrimerLista=0;

    LinkedList* listaEmpleados=ll_newLinkedList();
    do{

    	pedirEntero(&option,  " _______________________________________________________________________________ \n"
    			              "|                                                                               |\n"
							  "|                                  MENU EMPLEADOS                               |\n"
    						  "|_______________________________________________________________________________|\n"
								"1.Cargar los datos de los empleados desde el archivo data.csv (modo texto).\n"
								"2.Cargar los datos de los empleados desde el archivo data.bin (modo binario).\n"
								"3.Alta de empleado.\n"
								"4.Modificar datos de empleado.\n"
								"5.Baja de empleado-\n"
								"6.Listar empleados.\n"
								"7.Ordenar empleados.\n"
								"8.Guardar los datos de los empleados en el archivo data.csv (modo texto).\n"
								"9.Guardar los datos de los empleados en el archivo data.bin (modo binario).\n"
								"10.Salir.\n"
								"---------------------------------------------------------------------------------\n"
								"Ingrese una opcion: ",

								" _______________________________________________________________________________ \n"
							    "|                                                                               |\n"
							    "|                                  MENU EMPLEADOS                               |\n"
							    "|_______________________________________________________________________________|\n"
								"1.Cargar los datos de los empleados desde el archivo data.csv (modo texto).\n"
								"2.Cargar los datos de los empleados desde el archivo data.bin (modo binario).\n"
								"3.Alta de empleado.\n"
								"4.Modificar datos de empleado.\n"
								"5.Baja de empleado-\n"
								"6.Listar empleados.\n"
								"7.Ordenar empleados.\n"
								"8.Guardar los datos de los empleados en el archivo data.csv (modo texto).\n"
								"9.Guardar los datos de los empleados en el archivo data.bin (modo binario).\n"
								"10.Salir.\n"
								"---------------------------------------------------------------------------------\n"
								"Opcion invalida, reingrese: ",1, 10);



        switch(option)
        {
            case 1:
            	if(!banderaPrimerLista)
            	{
            		controller_loadFromText("data.csv",listaEmpleados);
            		banderaPrimerLista=1;
            	}
            	else
            	{
            		printf("Ya se accedio a la lista...\n");
            	}
                option=0;
                break;
            case 2:
            	if(!banderaPrimerLista)
            	{
            		controller_loadFromBinary("dataBinaria.bin" , listaEmpleados);
            		banderaPrimerLista=1;
            	}
            	else
				{
					printf("Ya se accedio a la lista...\n");
				}
            	option=0;
            	break;
            case 3:
            	if(ll_len(listaEmpleados)!=0)
				{
            		controller_addEmployee(listaEmpleados);
				}
            	else
            	{
            		printf("No se ingreso ningun empleado a la lista...\n");
            	}
            	option=0;
            	break;
            case 4:
            	if(ll_len(listaEmpleados)!=0)
            	{
            		controller_editEmployee(listaEmpleados);
            	}
            	else
            	{
            		printf("No se ingreso ningun empleado a la lista...\n");
            	}
            	option=0;
            	break;
            case 5:
            	if(ll_len(listaEmpleados)!=0)
				{
            	controller_removeEmployee(listaEmpleados);
				}
            	else
				{
					printf("No se ingreso ningun empleado a la lista...\n");
				}
            	option=0;
            	break;
            case 6:
            	if(ll_len(listaEmpleados)!=0)
            	{
            		controller_ListEmployee(listaEmpleados);
            	}
            	else
            	{
            		printf("No se ingreso ningun empleado a la lista...\n");
            	}
            	option=0;
            	break;
            case 7:
            	if(ll_len(listaEmpleados)!=0)
            	{
            	controller_sortEmployee(listaEmpleados);
            	}
            	else
            	{
            		printf("No se ingreso ningun empleado a la lista...\n");
            	}
            	option=0;
            	break;
            case 8:
            	if(ll_len(listaEmpleados)!=0)
            	{
            		controller_saveAsText("data.csv", listaEmpleados);
            	}
            	else
            	{
            		printf("No se accedio a la lista...\n");
            	}
            	option=0;
            	break;
            case 9:
            	if(ll_len(listaEmpleados)!=0)
            	{
            		controller_saveAsBinary("dataBinaria.bin", listaEmpleados);
            	}
            	else
            	{
            		printf("No se accedio a la lista...\n");
            	}
            	option=0;
            	break;
            case 10:
            	ll_deleteLinkedList(listaEmpleados);
            	printf("Saliendo del sistema...");
            	option=0;
            	break;
        }
        system("pause");
    }while(option != 10);
    return 0;
}


