#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"

int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{

	int todoOk = 0;
	Employee* auxEmployee;
	char buffer[4][30];
	int aux;

	if(pFile != NULL && pArrayListEmployee != NULL)
	{
		fscanf(pFile,"%[^,], %[^,], %[^,],%[^\n]\n",buffer[0], buffer[1], buffer[2], buffer[3]);

		while(!feof(pFile))
		{
			aux = fscanf(pFile,"%[^,], %[^,], %[^,],%[^\n]\n",buffer[0], buffer[1], buffer[2], buffer[3]);
			if(aux == 4)
			{
				auxEmployee = employee_newParametros(buffer[0], buffer[1], buffer[2], buffer[3]);

				if(auxEmployee != NULL)
				{
					aux = ll_add(pArrayListEmployee, auxEmployee);
					if(aux != 0)
					{
						employee_delete(auxEmployee);
						break;
					}
					else
					{
						todoOk = 1;
					}
				}
			}
			else
			{
				break;
			}
		}
	}
	return todoOk;
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
