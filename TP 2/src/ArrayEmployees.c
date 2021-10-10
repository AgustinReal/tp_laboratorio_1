/*
 * ArrayEmployees.c
 *
 *  Created on: 1 oct. 2021
 *      Author: Agustin
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayEmployees.h"
#include "ingresosAux.h"


int initEmployees(Employee* list, int len)

{
	int retorno=-1;

	if(list!=NULL)
	{
		for(int i=0; i<len; i++)
		{
			list[i].isEmpty=1;
		}
		retorno=1;
	}
  return retorno;
}
int addEmployee(Employee* list, int len, int id, char name[], char lastName[], float salary, int sector)
{
  int valor;
  int index;
  index=seachEmployees(list, len);

	if(index!=-1)
	{
		printf("\nCargando la lista en espacios libres espere unos segundos...\n");
		if(list!=NULL && list[index].isEmpty==1)
		{
			list[index].id=id;
			strcpy(list[index].name, name);
			strcpy(list[index].lastName, lastName);
			list[index].salary=salary;
			list[index].sector=sector;
			list[index].isEmpty=0;
		}
		else
		{
			printf("\nError ya se cargo la lista no hay espacios disponibles...\n");
		}
		valor=0;
	}
	else
	{
		printf("\nNo se pudo cargar...\n");
		valor=-1;
	}

 return valor;
}
int findEmployeeById(Employee* list, int len,int id)
{
	int index=-1;

	if(list!=NULL && id!=NULL)
	{
		for(int i=0; i<len; i++)
		{
			if(list[i].isEmpty==VACIO && list[i].id==id)
			{
				index=i;
				break;
			}
		}
	}

 return index;
}
int walkActiveEmployees(Employee* list, int len, float* acumuladorSalarioAux, int* contadorSueldosAux)
{
	int retorno=-1;
	*acumuladorSalarioAux=0;
	*contadorSueldosAux=0;

	if(list!=NULL )
	{
		for(int i=0; i<len; i++)
		{
			if(list[i].isEmpty==0)
			{
				*acumuladorSalarioAux+=list[i].salary;
				*contadorSueldosAux+=1;
				retorno=1;
			}
		}
	}

	return retorno;
}
int averageAverageSalary(Employee* list, int len, float promedioAux , int* contadorSuperanSalario)
{
	int retorno=-1;
	*contadorSuperanSalario=0;

	if(list!=NULL )
	{
		for(int i=0; i<len; i++)
		{
			if(list[i].salary>promedioAux)
			{
				*contadorSuperanSalario+=1;
			}
			retorno=1;
		}
	}
	return retorno;
}
int removeEmployee(Employee* list, int len, int id)
{
	int retorno=-1;
	int index;
	int idIngresado;

	if(list!=NULL)
	{
		pedirEntero(&idIngresado,"Ingrese el ID del empleado a borrar (0-1000): ", "Reingrese el ID del empleado a borrar (0-1000): ", 0, 1000);
		index=findEmployeeById(list, len, idIngresado);

		if(index!=-1)
		{
			printf("\nEl empleado a eliminar:\n\n %-5d %-20s %-20s %-20.2f %-20d\n", "Id", "Name", "LastName", "Salary", "Sector", "IsEmpty");
			showAnEmployee(list[index]);

			if(!confirmYesOrNoEmployee("\nIngrese 's' para confirmar el despido  del empleado."))
			{
				list[index].isEmpty=VACIO;
				printf("\nEl empleado %s fue despedido correctamente!\n\n", list[index].name);
				retorno=0;
			}
			else
			{
				printf("\nSe cancelo el despido.\n\n");
			}
		}
		else
		{
			printf("\nError. No se encontro ese empleado...");
		}
	}
	return retorno;
}
int sortEmployees(Employee* list, int len)
{
	int order;
	int retorno=-1;
	Employee auxList;

	if(list!=NULL)
	{

	   printf("Ingrese la manera que quiere ordenar los nombres, 1 para ascendente o 2 para de descendente: ");
	   fflush(stdin);
	   scanf("%d", &order);

	   while(order>3)
	   {
		   printf("Ingrese la manera que quiere ordenar los nombres, 1 para ascendente o 2 para de descendente: ");
		   fflush(stdin);
		   scanf("%d", &order);
	   }

	   switch(order)
	   {
		 case 1:
			for(int i=0;i<len;i++)
			{
			  for(int j=i+1;j<len;j++)
			  {
				  if(list[i].isEmpty==1 && list[j].isEmpty==1 && strcmp(list[i].lastName, list[j].lastName)==1)
				  {
					  auxList=list[i];
					  list[i]=list[j];
					  list[j]=auxList;
				  }
				  else if(strcmp(list[i].lastName, list[j].lastName)==0 && list[i].sector>list[j].sector)
				  {
					  auxList=list[i];
					  list[i]=list[j];
				      list[j]=auxList;
				  }
			  }
			}
		 break;
		 case 2:
			 for(int i=0;i<len;i++)
			 {
			   for(int j=i+1;j<len;j++)
			   {
				   if(list[i].isEmpty==1 && list[j].isEmpty==1 && strcmp(list[i].lastName, list[j].lastName)==-1)
				   {
					  auxList=list[i];
					  list[i]=list[j];
					  list[j]=auxList;
				   }
				   else if(strcmp(list[i].lastName, list[j].lastName)==0 && list[i].sector>list[j].sector)
				  {
					  auxList=list[i];
					  list[i]=list[j];
					  list[j]=auxList;
				  }
			   }
			 }
		 break;
		 retorno=1;
	   }

	}

	return retorno;
}
int printEmployees(Employee* list, int length)
{
	int retorno=-1;

	if(list!=NULL)
	{
		printf("\nLista de empleados:\n\n %-5d %-20s %-20s %-20.2f %-20d\n", "Id", "Name", "LastName", "Salary", "Sector", "IsEmpty");

		for(int i=0;i<length;i++)
		{
			if(list[i].isEmpty==VACIO)
			{
				showAnEmployee(list[i]);
			}
		}
		printf("\n");
  	 retorno=0;
	}

	return retorno;

 return 0;
}
void showAnEmployee(Employee empleado)
{
	printf("%-5d %-20s %-20s %-20.2f %-20d\n", empleado.id, empleado.name, empleado.lastName, empleado.salary, empleado.sector, empleado.isEmpty );
}
int confirmYesOrNoEmployee(char* mensaje)
{
	int retorno=-1;
	char respuesta;

	pedirCaracter(&respuesta, mensaje);

	if(respuesta=='s' || respuesta=='S')
	{
		retorno=0;
	}

	return retorno;
}
int seachEmployees(Employee* list, int len)
{
	int i;
	int index=-1;

	if(list!=NULL)
	{
		for(i=0; i<len; i++)
		{
			if(list[i].isEmpty==1)
			{
				index = i;
				break;
			}
		}
	}
	return index;
}
