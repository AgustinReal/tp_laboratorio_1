#include <stdio.h>
#include <stdlib.h>
#include "../src/LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "inputs.h"


int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
	int retorno=-1;
	FILE* pFile=fopen(path, "r");

	if(pArrayListEmployee!=NULL && path!=NULL)
	{
		parser_EmployeeFromText(pFile, pArrayListEmployee);
		retorno=1;
	}
    return retorno;
}
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
	int retorno=-1;

	if(pArrayListEmployee!=NULL && path!=NULL)
	{
		printf("Invoco al controller binario\n");
		FILE* pFile = fopen(path, "rb");
		if(pFile!=NULL)
		{
			parser_EmployeeFromBinary(pFile , pArrayListEmployee);
			retorno=1;
		}
	}

    return retorno;
}
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
	int retorno=-1;
	int idMayor=1001;
	int idEmpleadoActual;
	char auxNombre[31];
	int auxHorasTrabajadas;
	int auxSueldo;
	char id[2000];
	char horasTrabajadas[1000];
	char sueldo[1000];
	char afirmacion;
	int listaLargo;
	Employee* pEmploy;
	Employee* empleado;



	if(pArrayListEmployee!=NULL)
	{
		listaLargo = ll_len(pArrayListEmployee);
		pEmploy=(Employee*) ll_get(pArrayListEmployee, 0);
		employee_getId(pEmploy, &idMayor);
		for (int i=0; i < listaLargo; i++)
		{
			pEmploy=(Employee*) ll_get(pArrayListEmployee, i);
			employee_getId(pEmploy, &idEmpleadoActual);
			if(idMayor<idEmpleadoActual)
			{
				employee_getId(pEmploy, &idMayor);
			}
		}
		idMayor+=1;
		itoa(idMayor,id,10);
		pedirCadena(auxNombre,"Ingrese el nombre del empleado: ","Error.Ingrese el nombre del empleado: ",31);
		ingresoEntero(&auxHorasTrabajadas, "Ingrese las horas trabajadas para el empleado: ", "Error.Ingrese las horas trabajadas para el empleado: ", 1, 360);
		ingresoEntero(&auxSueldo, "Ingrese el sueldo para el empleado(10000-50000): ", "Error.Ingrese el sueldo para el empleadoIngrese el sueldo para el empleado: : ", 10000, 50000);


		itoa(auxHorasTrabajadas, horasTrabajadas, 10);
		itoa(auxSueldo, sueldo, 10);

		empleado=employee_newParametros(id, auxNombre, horasTrabajadas, sueldo);
		printf("%s %15s %15s %15s \n","ID","NOMBRE","HORAS","Sueldo");
		employee_printData(empleado);

		pedirCaracter(&afirmacion, "Ingrese s para comfirmar el empleado y guardar los datos... ");

		if(afirmacion=='s' || afirmacion=='S')
		{

			ll_add(pArrayListEmployee, empleado);
			printf("Empleado dado de alto correctamente...\n");
			retorno=1;
		}
		else
		{
			printf("El empleado no fue dado de alto correctamente...\n");
		}
	}
		return retorno;
}
int controller_editEmployee(LinkedList* pArrayListEmployee)
{

	int retorno=-1;
	int option;
	int idEmpleadoActual;
	int IdEncontrado=-1;
	char antesNombre[31];
	char nuevoNombre[31];
	int antesHorasTrabajadas;
	int nuevaHorasTrabajadas;
	int nuevoSueldo;
	int antesSueldo;
	char afirmacion;
	int listaLargo;
	int almacenarAuxIdModificar;
	Employee* pEmploy;

	ingresoEntero(&almacenarAuxIdModificar, "Cual es id que desea modifcar: ", "Error. Cual es id que desea modifcar: ", 1, 2000);
	if(pArrayListEmployee!=NULL)
	{
		listaLargo = ll_len(pArrayListEmployee);
		for (int i=0; i < listaLargo; i++)
		{
			pEmploy=(Employee*) ll_get(pArrayListEmployee, i);
			employee_getId(pEmploy, &idEmpleadoActual);
			if(almacenarAuxIdModificar==idEmpleadoActual)
			{
				IdEncontrado=i;
				break;
			}
			else
			{
				printf("No se encontro ese empleado...\n");
			}
		}
		if(IdEncontrado>0)
		{
			printf("%s %15s %15s %15s \n","ID","NOMBRE","HORAS","Sueldo");
			pEmploy=(Employee*) ll_get(pArrayListEmployee, IdEncontrado);
			employee_printData(pEmploy);
			pedirCaracter(&afirmacion, "Ingrese s para comfirmar el empleado y guardar los datos... ");

			if(afirmacion=='s' || afirmacion=='S')
			{
				do
				{

					ingresoEntero(&option,"--------------------------------------------------------------------------------\n"
							"1-MODIFICAR El NOMBRE.\n"
							"2-MODIFICAR El HORAS TRABAJADAS.\n"
							"3-MODIFICAR El SUELDO.\n"
							"4-SALIR.\n"
							"--------------------------------------------------------------------------------\n"
							"Ingrese una opcion: ",

							"1-MODIFICAR El NOMBRE.\n"
							"2-MODIFICAR El HORAS TRABAJADAS.\n"
							"3-MODIFICAR El SUELDO.\n"
							"4-SALIR.\n"
							"--------------------------------------------------------------------------------\n"
							"Opcion invalida, reingrese: ", 1, 4);
					switch(option)
					{
					case 1:
						pedirCadena(nuevoNombre, "Ingrese el nuevo nombre del empleado: ", "Error.Ingrese el nuevo nombre del empleado: ", 31);

						employee_getNombre(pEmploy, antesNombre);
						employee_setNombre(pEmploy, nuevoNombre);

						printf("%s %15s %15s %15s \n","ID","NOMBRE","HORAS","Sueldo");
						pEmploy=(Employee*) ll_get(pArrayListEmployee, IdEncontrado);

						printf("Sea realizado la modificacion del nombre...\n");

						break;
					case 2:
						ingresoEntero(&nuevaHorasTrabajadas, "Ingrese las nuevas horas trabajadas del empleado: ", "Error.Ingrese las nuevas horas trabajadas del empleado: ", 1, 360);

						employee_getHorasTrabajadas(pEmploy, &antesHorasTrabajadas);
						employee_setHorasTrabajadas(pEmploy, nuevaHorasTrabajadas);

						printf("%s %15s %15s %15s \n","ID","NOMBRE","HORAS","Sueldo");
						pEmploy=(Employee*) ll_get(pArrayListEmployee, IdEncontrado);

						printf("Sea realizado la modificacion de la horas trabajadas...\n");
						break;
					case 3:
						ingresoEntero(&nuevoSueldo, "Ingrese el nuevo sueldo del empleado: ", "Error.Ingrese el nuevo sueldo del empleado: ", 10000, 50000);

						employee_getSueldo(pEmploy, &antesSueldo);
						employee_setSueldo(pEmploy, nuevoSueldo);

						printf("%s %15s %15s %15s \n","ID","NOMBRE","HORAS","Sueldo");
						pEmploy=(Employee*) ll_get(pArrayListEmployee, IdEncontrado);

						printf("Sea realizado la modificacion del sueldo...\n");
						break;
					case 4:
						printf("Saliendo de las modificaciones...\n");
						break;
					}
					printf("%s %15s %15s %15s \n","ID","NOMBRE","HORAS","Sueldo");
					pEmploy=(Employee*) ll_get(pArrayListEmployee, IdEncontrado);
					employee_printData(pEmploy);

				}while(option!=4);
				option=0;
				retorno=1;
			}
			else
			{
				printf("El empleado no fue modificado correctamente...\n\n");
			}
		}
	}

    return retorno;
}
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
	int retorno=-1;
	char afirmacion;
	int idEmpleadoActual;
	int IdEncontrado;
	int listaLargo;
	int almacenarAuxIdModificar;
	Employee* pEmploy;

	ingresoEntero(&almacenarAuxIdModificar, "Cual es id que desea del empleado que desea dar de baja: ", "Error. Cual es id que desea del empleado que desea dar de baja: ", 1, 2000);
	if(pArrayListEmployee!=NULL)
	{
		listaLargo = ll_len(pArrayListEmployee);
		for (int i=0;i<listaLargo;i++)
		{
			pEmploy=(Employee*) ll_get(pArrayListEmployee, i);
			employee_getId(pEmploy, &idEmpleadoActual);
			if(almacenarAuxIdModificar==idEmpleadoActual)
			{
				IdEncontrado=i;
				break;
			}
		}
		if(IdEncontrado>0)
		{
			printf("%s %15s %15s %15s \n","ID","NOMBRE","HORAS","Sueldo");
			pEmploy=(Employee*) ll_get(pArrayListEmployee, IdEncontrado);
			employee_printData(pEmploy);
			pedirCaracter(&afirmacion, "Ingrese s para comfirmar el empleado y darlo de baja...");

			if(afirmacion=='s' || afirmacion=='S')
			{
				ll_remove(pArrayListEmployee, IdEncontrado);
				printf("\nEl empleado %d fue eliminado correctamente!\n\n", IdEncontrado);
				retorno=1;
			}
			else
			{
				printf("\nSe cancelo la eliminacion...\n\n");
			}
		}
		else
		{
			printf("No se encontro esa Id del empleado...\n\n");
		}
	}
    return retorno;
}
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
	int i=0;
	int lenList = ll_len(pArrayListEmployee);
	printf(" %-10s %-15s %-15s %-15s \n","Id","Nombre","Horas","Sueldo");
	for (i = 0; i < lenList; ++i)
	{
		Employee* pEmpleado = ll_get(pArrayListEmployee, i);
		printf(" %-10d %-15s %-15d %-15d \n",pEmpleado->id,pEmpleado->nombre,pEmpleado->horasTrabajadas,pEmpleado->sueldo);
	}

	return 1;
}
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
	int retorno=-1;
	int option;


	if(pArrayListEmployee!=NULL)
	{
		int(*pFuncionOrdenar)(void*,void*);

			ingresoEntero(&option,"--------------------------------------------------------------------------------\n"
					"1-ORDENAR POR El ID ASCENDENTE.\n"
					"2-ORDENAR POR El ID DESCENDENTE.\n"
					"3-ORDENAR POR El NOMBRE ASCENDENTE.\n"
					"4-ORDENAR POR El NOMBRE DESCENDENTE.\n"
					"5-ORDENAR POR LAS HORAS TRABAJADAS ASCENDENTE.\n"
					"6-ORDENAR POR LAS HORAS TRABAJADAS DESCENDENTE.\n"
					"7-ORDENAR POR El SUELDO ASCENDENTE.\n"
					"8-ORDENAR POR El SUELDO DESCENDENTE.\n"
					"9-SALIR.\n"
					"--------------------------------------------------------------------------------\n"
					"Ingrese una opcion: ",

					"1-ORDENAR POR El ID ASCENDENTE.\n"
					"2-ORDENAR POR El ID DESCENDENTE.\n"
					"3-ORDENAR POR El NOMBRE ASCENDENTE.\n"
					"4-ORDENAR POR El NOMBRE DESCENDENTE.\n"
					"5-ORDENAR POR LAS HORAS TRABAJADAS ASCENDENTE.\n"
					"6-ORDENAR POR LAS HORAS TRABAJADAS DESCENDENTE.\n"
					"7-ORDENAR POR El SUELDO ASCENDENTE.\n"
					"8-ORDENAR POR El SUELDO DESCENDENTE.\n"
					"9-SALIR.\n"
					"--------------------------------------------------------------------------------\n"
					"Opcion invalida, reingrese: ", 1, 9);


			switch(option)
			{
				case 1:
					pFuncionOrdenar=employee_ordenarPorId;
					ll_sort(pArrayListEmployee, pFuncionOrdenar, 1);
					break;
				case 2:
					pFuncionOrdenar=employee_ordenarPorId;
					ll_sort(pArrayListEmployee, pFuncionOrdenar, 0);
					break;
				case 3:
					pFuncionOrdenar=employee_ordenarPorNombre;
					ll_sort(pArrayListEmployee, pFuncionOrdenar, 1);
					break;
				case 4:
					pFuncionOrdenar=employee_ordenarPorNombre;
					ll_sort(pArrayListEmployee, pFuncionOrdenar, 0);
					break;
				case 5:
					pFuncionOrdenar=employee_ordenarPorHoras;
					ll_sort(pArrayListEmployee, pFuncionOrdenar, 1);
					break;
				case 6:
					pFuncionOrdenar=employee_ordenarPorHoras;
					ll_sort(pArrayListEmployee, pFuncionOrdenar, 0);
					break;
				case 7:
					pFuncionOrdenar=employee_ordenarSueldo;
					ll_sort(pArrayListEmployee, pFuncionOrdenar, 1);
					break;
				case 8:
					pFuncionOrdenar=employee_ordenarSueldo;
					ll_sort(pArrayListEmployee, pFuncionOrdenar, 0);
					break;
				case 9:
					printf("Volviendo al menu...\n");
					break;
			}
			retorno=1;
	}

    return retorno;
}
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
	int retorno=-1;
	int id;
	char nombre[31];
	int horasTrabajadas;
	int sueldo;
	Employee* pEmpleado;
	int largo=ll_len(pArrayListEmployee);

	FILE* pFile;
	pFile=fopen(path, "w");

	if(pArrayListEmployee!=NULL && path!=NULL)
	{
		fprintf(pFile, "id, nombre, horasTrabajadas, sueldo\n");

		for(int i=0;i<largo;i++)
		{
			pEmpleado=(Employee*)ll_get(pArrayListEmployee, i);

			employee_getId(pEmpleado, &id);
			employee_getNombre(pEmpleado, nombre);
			employee_getSueldo(pEmpleado, &sueldo);
			employee_getHorasTrabajadas(pEmpleado, &horasTrabajadas);

			fprintf(pFile, "%d,%s,%d,%d\n", id, nombre, horasTrabajadas, sueldo);

		}
		retorno=1;
	}
	fclose(pFile);
    return retorno;
}
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
	printf("Guardando... archivo binario\n");
	int retorno=0;
	int tamArray;

	tamArray= ll_len(pArrayListEmployee);

	FILE* pFile;
	pFile = fopen(path, "wb");

	if(pFile!=NULL&& path!=NULL)
	{
		for (int var=0;var<tamArray;++var)
		{
			Employee* pAuxEmpleado = ll_get(pArrayListEmployee,var);
			fwrite(pAuxEmpleado, sizeof(Employee), 1, pFile);
		}
		printf("Archivo escrito con exito!\n");
		retorno=1;
	}
	fclose(pFile);
	return retorno;
}
