#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Employee.h"



Employee* employee_new()
{
	Employee* employeeRetorno=NULL;
	employeeRetorno=(Employee*)malloc(sizeof(Employee));
	return employeeRetorno;
}
Employee* employee_newParametros(char* idStr, char* nombreStr, char* horasTrabajadasStr, char* sueldoStr)
{
	Employee* employeeRetorno = NULL;
	employeeRetorno = employee_new();

	if(employeeRetorno != NULL)
	{
		employee_setId(employeeRetorno, atoi(idStr));
		employee_setNombre(employeeRetorno, nombreStr);
		employee_setHorasTrabajadas(employeeRetorno, atoi(horasTrabajadasStr));
		employee_setSueldo(employeeRetorno, atoi(sueldoStr));
	}
	return employeeRetorno;
}
void employee_delete(Employee* this)
{
	if(this != NULL)
	{
		free(this);
		this=NULL;
	}
}
int employee_setId(Employee* this, int id)
{
	int seCargo=0;
	if(this!=NULL)
	{
		this->id=id;
		seCargo=1;
	}
	return seCargo;
}
int employee_getId(Employee* this,int* id)
{
	int retorno=-1;

	if(this != NULL )
	{
		*id=this->id;
		retorno=1;
	}
	return retorno;
}
int employee_setNombre(Employee* this, char* nombre)
{
	int seCargo = 0;
	if(this != NULL && nombre != NULL)
	{
		strcpy(this->nombre, nombre);
		seCargo = 1;
	}
	return seCargo;
}
int employee_getNombre(Employee* this, char* nombre)
{

	int retorno=-1;

	if(this != NULL)
	{
		strcpy(nombre, this->nombre);
		retorno=1;
	}
	return retorno;
}
int employee_setHorasTrabajadas(Employee* this, int horasTrabajadas)
{
	int seCargo = 0;
	if(this != NULL )
	{
		this->horasTrabajadas=horasTrabajadas;
		seCargo = 1;
	}
	return seCargo;
}
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
	int retorno=-1;

	if(this != NULL )
	{
		*horasTrabajadas=this->horasTrabajadas;
		retorno=1;
	}
	return retorno;
}
int employee_setSueldo(Employee* this, int sueldo)
{
	int seCargo = 0;
	if(this != NULL )
	{
		this->sueldo=sueldo;
		seCargo = 1;
	}
	return seCargo;
}
int employee_getSueldo(Employee* this, int* sueldo)
{
	int retorno=-1;

	if(this != NULL )
	{
		*sueldo=this->sueldo;
		retorno=1;
	}
	return retorno;
}
void employee_printData(Employee* this)
{
    int id; //Variable donde se almacena el id utilizando getId();
    char nombre[51]; //Variable donde se almacena el nombre utilizando getNobre();
    int horasTrabajadas; //Variable donde se almacenan las horas trabajadas utilizando getHorasTrabajadas();
    int sueldo; //Variable donde se almacena el sueldo utilizando getId();
    employee_getId(this, &id); //Obtengo el Id del empleado
    employee_getNombre(this, nombre); //Obtengo el nombre del empleado
    employee_getHorasTrabajadas(this, &horasTrabajadas); //Obtengo las horas trabajadas del empelado
    employee_getSueldo(this, &sueldo); //Obtengo el sueldo del empleado
    printf("%d %15s %15d %15d$\n", id, nombre, horasTrabajadas, sueldo); //Muestro los datos del empleado
}
int employee_ordenarPorNombre(void* punteroUno, void* punteroDos)
{
	int retorno=-2;
	    if(punteroUno!=NULL&&punteroDos!=NULL)
	    {
	        retorno=0;
	        char auxNombreUno[128];
	        char auxNombreDos[128];
	        Employee* auxEmpleado = (Employee*)punteroUno;
	        Employee* auxEmpleadoDos = (Employee*)punteroDos;
	        employee_getNombre(auxEmpleado,auxNombreUno);
	        employee_getNombre(auxEmpleadoDos,auxNombreDos);

	        retorno=stricmp(auxNombreUno,auxNombreDos);

	        auxEmpleado =NULL;
	        auxEmpleadoDos=NULL;
	    }

	    return retorno;
}
int employee_ordenarPorHoras(void* punteroUno, void* punteroDos)
{
    int retorno=0;
    int horasUno;
    int horasDos;
    Employee* auxEmpleado = (Employee*)punteroUno;
    Employee* auxEmpleadoDos = (Employee*)punteroDos;
    employee_getHorasTrabajadas(auxEmpleado,&horasUno);
    employee_getHorasTrabajadas(auxEmpleadoDos,&horasDos);

    if(horasUno>horasDos)
    {
        retorno=1;
    }
    else if(horasUno<horasDos)
    {
        retorno=-1;
    }
    auxEmpleado =NULL;
    auxEmpleadoDos=NULL;
    return retorno;
}
int employee_ordenarPorId(void* punteroUno, void* punteroDos)
{
    int retorno=0;
    int idUno;
    int idDos;
    Employee* auxEmpleado = (Employee*)punteroUno;
    Employee* auxEmpleadoDos = (Employee*)punteroDos;
    employee_getId(auxEmpleado,&idUno);
    employee_getId(auxEmpleadoDos,&idDos);

    if(idUno>idDos)
    {
        retorno=1;
    }
    else if(idUno<idDos)
    {
        retorno=-1;
    }
    auxEmpleado =NULL;
    auxEmpleadoDos=NULL;
    return retorno;
}

int employee_ordenarSueldo(void* punteroUno, void* punteroDos)
{
    int retorno=0;
    int sueldoUno;
    int sueldoDos;
    Employee* auxEmpleado = (Employee*)punteroUno;
    Employee* auxEmpleadoDos = (Employee*)punteroDos;
    employee_getSueldo(auxEmpleado,&sueldoUno);
    employee_getSueldo(auxEmpleadoDos,&sueldoDos);

    if(sueldoUno>sueldoDos)
    {
        retorno=1;
    }
    else if(sueldoUno<sueldoDos)
    {
        retorno=-1;
    }
    auxEmpleado =NULL;
    auxEmpleadoDos=NULL;
    return retorno;
}
