#include <stdio.h>
#include <stdlib.h>
#include "../src/LinkedList.h"
#include "Employee.h"

int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
	char id[10];
	char nombre[31];
	char horasTrabajadas[10];
	char sueldo[10];
	Employee* auxEmployee;
	int retorno=-1;

	if(pFile!=NULL && pArrayListEmployee!=NULL)
	{
		fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]", id, nombre, horasTrabajadas, sueldo);
		while(!feof(pFile))
		{

			fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]", id, nombre, horasTrabajadas, sueldo);

			if(feof(pFile))
			{
				break;
			}
			auxEmployee=employee_newParametros(id, nombre, horasTrabajadas, sueldo);
			ll_add(pArrayListEmployee, auxEmployee);
			retorno=1;
		}
		fclose(pFile);

	}
	return retorno;
}
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
	printf("Cargando datos del archivo binario\n");
	int retorno=0;

	if(pFile!=NULL && pArrayListEmployee!=NULL)
	{

		int fin =1;
		Employee* auxEmpleado=employee_new();
		do
		{
			fin =fread(auxEmpleado, sizeof(Employee), 1, pFile);
			if(fin)
			{
				ll_add(pArrayListEmployee, auxEmpleado);
				auxEmpleado=employee_new();
			}
		}while(fin);
		free(auxEmpleado);

		fclose(pFile);
		retorno=1;
	}

	return retorno;
}
