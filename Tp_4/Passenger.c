#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "inputs.h"
#include "Passenger.h"

Passenger* Passenger_new()
{
    Passenger* nuevoPassenger=NULL;
    nuevoPassenger=(Passenger*)malloc(sizeof(Passenger));

	if(nuevoPassenger!=NULL)
	{
		Passenger_setId(nuevoPassenger, 0);
		Passenger_setNombre(nuevoPassenger, "sin asignar");
		Passenger_setApellido(nuevoPassenger, "sin asignar");
		Passenger_setPrecio(nuevoPassenger, 0);
		Passenger_setCodigoVuelo(nuevoPassenger, "error");
		Passenger_setTipoPasajero(nuevoPassenger, 2);
		Passenger_setEstadoVuelo(nuevoPassenger, 2);
	}
	return nuevoPassenger;
}
Passenger* Passenger_newParametros(char* idStr, char* nombreStr, char* apellidoStr, char* precioStr,  char* codigoVueloStr, char* tipoPasajeroStr, char* estadoVueloStr)
{
    Passenger* nuevoPassenger=NULL;
    nuevoPassenger = Passenger_new();

	if(nuevoPassenger!=NULL)
	{
		if(!(Passenger_setId(nuevoPassenger, atoi(idStr))
		&& Passenger_setNombre(nuevoPassenger, nombreStr)
		&& Passenger_setApellido(nuevoPassenger, apellidoStr)
		&& Passenger_setPrecio(nuevoPassenger, atoi(precioStr))
		&& Passenger_setCodigoVuelo(nuevoPassenger, codigoVueloStr)
		&& Passenger_setTipoPasajero(nuevoPassenger, atoi(tipoPasajeroStr))
		&& Passenger_setEstadoVuelo(nuevoPassenger, atoi(estadoVueloStr))))
		{
			Passenger_delete(nuevoPassenger);
		}
	}

	return nuevoPassenger;
}
void Passenger_delete(Passenger* this)
{
    if(this!=NULL)
	{
		free(this);
		this=NULL;
	}
}
//setters
int Passenger_setId(Passenger* this, int id)
{
	int todoOk=0;
	if(this!=NULL && id>=0)
	{
		this->id=id;
		todoOk=1;
	}
	return todoOk;
}
int Passenger_setNombre(Passenger* this, char* nombre)
{
	int todoOk=0;
	if(this != NULL && nombre != NULL)
	{
		if(strlen(nombre)<50 && strlen(nombre)>1)
		{
			strcpy(this->nombre, nombre);
			todoOk=1;
		}
	}
	return todoOk;
}
int Passenger_setApellido(Passenger* this, char* apellido)
{
	int todoOk=0;
	if(this != NULL && apellido != NULL)
	{
		if(strlen(apellido)<50 && strlen(apellido)>1)
		{
			strcpy(this->apellido, apellido);
			todoOk=1;
		}
	}
	return todoOk;
}
int Passenger_setPrecio(Passenger* this, float precio)
{
	int todoOK=0;
	if(this!=NULL)
	{
		if((precio>=10000 && precio <=50000) || precio==0)
		{
			this->precio=precio;
			todoOK=1;
		}
	}
	return todoOK;
}
int Passenger_setCodigoVuelo(Passenger* this, char* codigoVuelo)
{
	int todoOK=0;
	if(this!=NULL && codigoVuelo!=NULL)
	{
		if(strlen(codigoVuelo)<10 && strlen(codigoVuelo)>5)
		{
			strcpy(this->codigoVuelo, codigoVuelo);
			todoOK=1;
		}
	}
	return todoOK;
}
int Passenger_setTipoPasajero(Passenger* this, int tipoPasajero)
{
	int todoOk=0;
	if(this!=NULL)
	{
		if(tipoPasajero<=3 && tipoPasajero>=1)
		{
			this->tipoPasajero=tipoPasajero;
			todoOk=1;
		}
	}
	return todoOk;
}
int Passenger_setEstadoVuelo(Passenger* this, int estadoVuelo)
{
	int todoOk=0;
	if(this!=NULL)
	{
		if(estadoVuelo<=4 && estadoVuelo>=1)
		{
			this->estadoVuelo=estadoVuelo;
			todoOk=1;
		}

	}
	return todoOk;
}
//getters
int Passenger_getId(Passenger* this, int* id)
{
	int todoOk=0;

	if(this!=NULL)
	{
		*id=this->id;
		todoOk=1;
	}
	return todoOk;
}
int Passenger_getNombre(Passenger* this, char* nombre)
{
    int todoOk=0;

	if(this != NULL && nombre!=NULL)
	{
		strcpy(nombre, this->nombre);
		todoOk=1;
	}
	return todoOk;
}
int Passenger_getApellido(Passenger* this, char* apellido)
{
	int todoOk=0;
	if(this!=NULL && apellido!=NULL)
	{
		strcpy(apellido, this->apellido);
		todoOk=1;
	}
	return todoOk;
}
int Passenger_getPrecio(Passenger* this, float* precio)
{
	int todoOk=0;
	if(this!=NULL && precio!=NULL)
	{
		*precio=this->precio;
		todoOk=1;
	}
	return todoOk;
}
int Passenger_getCodigoVuelo(Passenger* this, char* codigoVuelo)
{
	int todoOk=0;
	if(this!=NULL && codigoVuelo!=NULL)
	{
		strcpy(codigoVuelo, this->codigoVuelo);
		todoOk=1;
	}
	return todoOk;
}
int Passenger_getTipoPasajero(Passenger* this, int* tipoPasajero)
{
	int todoOk=0;
	if(this!=NULL && tipoPasajero!=NULL)
	{
		*tipoPasajero=this->tipoPasajero;
		todoOk=1;
	}
	return todoOk;
}
int Passenger_getdescripcionTipoPasajero(int tipoPasajero , char* descripcionTipo)
{
	int todoOk=0;

	if(tipoPasajero<=3 &&  tipoPasajero>=1 && descripcionTipo!=NULL)
	{
		if(tipoPasajero==1)
		{
			strcpy(descripcionTipo, "Primera clase");
		}
		else if(tipoPasajero==2)
		{
			strcpy(descripcionTipo, "Clase ejecutiva");
		}
		else
		{
			strcpy(descripcionTipo, "Clase economica");
		}
		todoOk=1;
	}

	return todoOk;
}
int Passenger_getEstadoVuelo(Passenger* this, int* estadoVuelo)
{
	int todoOk=0;
	if(this!=NULL && estadoVuelo!=NULL)
	{
		*estadoVuelo=this->estadoVuelo;
		todoOk=1;
	}
	return todoOk;
}
int Passenger_getdescripcionEstadoVuelo(int estadoVuelo , char* descripcionEstadoVuelo)
{
	int todoOk=0;

		if(estadoVuelo<=4 &&  estadoVuelo>=1 && descripcionEstadoVuelo!=NULL)
		{
			if(estadoVuelo==1)
			{
				strcpy(descripcionEstadoVuelo, "Aterrizado");
			}
			else if(estadoVuelo==2)
			{
				strcpy(descripcionEstadoVuelo, "En Horario");
			}
			else if(estadoVuelo==3)
			{
				strcpy(descripcionEstadoVuelo, "En Vuelo");
			}
			else
			{
				strcpy(descripcionEstadoVuelo, "Demorado");
			}
			todoOk=1;
		}

		return todoOk;
}
Passenger* Passenger_altaPasajero()
{
	Passenger* pasajero=NULL;
	char auxNombre[51];
	char auxApellido[51];
	float auxPrecio;
	char precio[1000];
	char auxCodigoVuelo[10];
	int auxTipoPasajero;
	char tipoPasajero[1000];
	int auxEstadoVuelo;
	char estadoVuelo[1000];

	pasajero=Passenger_new();

	if(pasajero!=NULL)
	{
		ingresoCadena(auxNombre,"Ingrese el nombre del pasajero(letras entre 3-50): ","Error. Ingrese el nombre del pasajero(letras entre 3-50): ",50, 3);
		ingresoCadena(auxApellido,"Ingrese el apellido del pasajero(letras entre 3-50): ","Error. Ingrese el apellido del pasajero(letras entre 3-50): ",50, 3);
		ingresoFlotante(&auxPrecio, "Ingrese el precio del vuelo (10000-50000): ", "Error. Ingrese el precio del vuelo (10000-50000): ", 10000.00, 50000.00);
		ingresoLetrasNumeros(auxCodigoVuelo, "Ingrese el codigo del vuelo (max 10 caracteres): ", "Error. Ingrese el codigo del vuelo (max 10 caracteres): ", 10, 5);
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

		Passenger_setNombre(pasajero, auxNombre);
		Passenger_setApellido(pasajero, auxApellido);
		Passenger_setPrecio(pasajero, auxPrecio);
		Passenger_setCodigoVuelo(pasajero, auxCodigoVuelo);
		Passenger_setTipoPasajero(pasajero, auxTipoPasajero);
		Passenger_setEstadoVuelo(pasajero, auxEstadoVuelo);

		itoa(auxPrecio, precio, 10);
		itoa(auxTipoPasajero, tipoPasajero, 10);
		itoa(auxEstadoVuelo, estadoVuelo, 10);


	}

	return pasajero;
}
void Passenger_mostrarUnPasajero(Passenger* pasajero)
{
	int id;
	char nombre[50];
	char apellido[50];
	float precio;
	char codigoDeVuelo[10];
	int tipoPasajero;
	char descpTipoPasajero[30];
	int estadoVuelo;
	char descripEstadoVuelo[30];

	Passenger_getId(pasajero, &id);
	Passenger_getNombre(pasajero, nombre);
	Passenger_getApellido(pasajero, apellido);
	Passenger_getPrecio(pasajero, &precio);
	Passenger_getCodigoVuelo(pasajero, codigoDeVuelo);
	Passenger_getTipoPasajero(pasajero, &tipoPasajero);
	Passenger_getdescripcionTipoPasajero(tipoPasajero, descpTipoPasajero);
	Passenger_getEstadoVuelo(pasajero, &estadoVuelo);
	Passenger_getdescripcionEstadoVuelo(estadoVuelo, descripEstadoVuelo);

	printf("| %-5d |  %-12s|  %-12s|  $%-8.2f |       %-10s    |    %-15s   |      %-13s  |\n", id, nombre, apellido, precio, codigoDeVuelo, descpTipoPasajero, descripEstadoVuelo);
}
int Passenger_ordenarPorId(void* punteroUno, void* punteroDos)
{
	int retorno;
	int auxIdUno;
	int auxIdDos;
	Passenger* auxPasajeroUno = (Passenger*)punteroUno;
	Passenger* auxPasajeroDos = (Passenger*)punteroDos;

	if(auxPasajeroUno!=NULL && auxPasajeroDos!=NULL)
	{
		Passenger_getId(auxPasajeroUno, &auxIdUno);
		Passenger_getId(auxPasajeroDos, &auxIdDos);

		if(auxIdUno>auxIdDos)
		{
			retorno=1;
		}
		else if(auxIdUno<auxIdDos)
		{
			retorno=-1;
		}

		auxPasajeroUno=NULL;
		auxPasajeroDos=NULL;
	}

	return retorno;
}
int Passenger_ordenarPorNombre(void* punteroUno, void* punteroDos)
{
    int retorno;
    char auxNombreUno[128];
    char auxNombreDos[128];
    Passenger* auxPasajeroUno = (Passenger*)punteroUno;
    Passenger* auxPasajeroDos = (Passenger*)punteroDos;

    if(auxPasajeroUno!=NULL && auxPasajeroDos!=NULL)
    {
    	Passenger_getNombre(auxPasajeroUno,auxNombreUno);
    	Passenger_getNombre(auxPasajeroDos,auxNombreDos);

    	if(strcmp(auxNombreUno,auxNombreDos)<0)
    	{
    		retorno=-1;
    	}
    	else if(strcmp(auxNombreUno,auxNombreDos)>0)
    	{
    		retorno=1;
    	}

        auxPasajeroUno=NULL;
        auxPasajeroDos=NULL;
    }

    return retorno;
}
int Passenger_ordenarPorApellido(void* punteroUno, void* punteroDos)
{
    int retorno;
    char auxApellidoUno[128];
    char auxApellidoDos[128];
    Passenger* auxPasajeroUno = (Passenger*)punteroUno;
    Passenger* auxPasajeroDos = (Passenger*)punteroDos;

    if(auxPasajeroUno!=NULL && auxPasajeroDos!=NULL)
    {
    	Passenger_getApellido(auxPasajeroUno,auxApellidoUno);
    	Passenger_getApellido(auxPasajeroDos,auxApellidoDos);

    	if(strcmpi(auxApellidoUno,auxApellidoDos)<0)
    	{
    		retorno=-1;
    	}
    	else if(strcmpi(auxApellidoUno,auxApellidoDos)>0)
    	{
    		retorno=1;
    	}


        auxPasajeroUno=NULL;
        auxPasajeroDos=NULL;
    }

    return retorno;
}
int Passenger_ordenarPorPrecio(void* punteroUno, void* punteroDos)
{
	int retorno;
	float auxPrecioUno;
	float auxPrecioDos;
	Passenger* auxPasajeroUno = (Passenger*)punteroUno;
	Passenger* auxPasajeroDos = (Passenger*)punteroDos;

	if(auxPasajeroUno!=NULL && auxPasajeroDos!=NULL)
	{
		Passenger_getPrecio(auxPasajeroUno, &auxPrecioUno);
		Passenger_getPrecio(auxPasajeroDos, &auxPrecioDos);

		if(auxPrecioUno>auxPrecioDos)
		{
			retorno=1;
		}
		else if(auxPrecioUno<auxPrecioDos)
		{
			retorno=-1;
		}

		auxPasajeroUno=NULL;
		auxPasajeroDos=NULL;
	}

	return retorno;
}
int Passenger_ordenarPorCodigoDeVuelo(void* punteroUno, void* punteroDos)
{
	int retorno;
	char auxCodigoDeVueloUno[128];
	char auxCodigoDeVueloDos[128];
	Passenger* auxPasajeroUno = (Passenger*)punteroUno;
	Passenger* auxPasajeroDos = (Passenger*)punteroDos;

	if(auxPasajeroUno!=NULL && auxPasajeroDos!=NULL)
	{
		Passenger_getCodigoVuelo(auxPasajeroUno,auxCodigoDeVueloUno);
		Passenger_getCodigoVuelo(auxPasajeroDos,auxCodigoDeVueloDos);

		if(strcmp(auxCodigoDeVueloUno,auxCodigoDeVueloDos)<0)
		{
			retorno=-1;
		}
		else if(strcmp(auxCodigoDeVueloUno,auxCodigoDeVueloDos)>0)
		{
			retorno=1;
		}

		auxPasajeroUno=NULL;
		auxPasajeroDos=NULL;
	}

	return retorno;
}
int Passenger_ordenarPorTipoPasajero(void* punteroUno, void* punteroDos)
{
	int retorno;
	int tipoPasajeroUno;
	int tipoPasajeroDos;
	char auxTipoPasajeroUno[128];
	char auxTipoPasajeroDos[128];
	Passenger* auxPasajeroUno = (Passenger*)punteroUno;
	Passenger* auxPasajeroDos = (Passenger*)punteroDos;

	if(auxPasajeroUno!=NULL && auxPasajeroDos!=NULL)
	{

		Passenger_getTipoPasajero(auxPasajeroUno, &tipoPasajeroUno);
		Passenger_getdescripcionTipoPasajero(tipoPasajeroUno, auxTipoPasajeroUno);
		Passenger_getTipoPasajero(auxPasajeroDos, &tipoPasajeroDos);
		Passenger_getdescripcionTipoPasajero(tipoPasajeroDos, auxTipoPasajeroDos);

		if(strcmp(auxTipoPasajeroUno,auxTipoPasajeroDos)<0)
		{
			retorno=-1;
		}
		else if(strcmp(auxTipoPasajeroUno,auxTipoPasajeroDos)>0)
		{
			retorno=1;
		}

		auxPasajeroUno=NULL;
		auxPasajeroDos=NULL;
	}

	return retorno;
}
int Passenger_ordenarPorEstadoVuelo(void* punteroUno, void* punteroDos)
{
	int retorno;
	int estadoVueloUno;
	int estadoVueloDos;
	char auxEstadoVueloUno[128];
	char auxEstadoVueloDos[128];
	Passenger* auxPasajeroUno = (Passenger*)punteroUno;
	Passenger* auxPasajeroDos = (Passenger*)punteroDos;

	if(auxPasajeroUno!=NULL && auxPasajeroDos!=NULL)
	{

		Passenger_getEstadoVuelo(auxPasajeroUno, &estadoVueloUno);
		Passenger_getdescripcionEstadoVuelo(estadoVueloUno, auxEstadoVueloUno);
		Passenger_getEstadoVuelo(auxPasajeroDos, &estadoVueloDos);
		Passenger_getdescripcionEstadoVuelo(estadoVueloDos, auxEstadoVueloDos);

		if(strcmp(auxEstadoVueloUno,auxEstadoVueloDos)<0)
		{
			retorno=-1;
		}
		else if(strcmp(auxEstadoVueloUno,auxEstadoVueloDos)>0)
		{
			retorno=1;
		}

		auxPasajeroUno=NULL;
		auxPasajeroDos=NULL;
	}

	return retorno;
}
int Passenger_actualizarUltimoId(int idViejo)
{
	int todoOk=0;

	FILE* pFile=fopen("ultimoId.txt", "w");

	if(pFile!=NULL)
	{
		fprintf(pFile, "%d\n", idViejo+1);
		todoOk = 1;
	}
	fclose(pFile);

	return todoOk;
}
