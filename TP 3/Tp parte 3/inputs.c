/*
 * inputs.c
 *
 *  Created on: 10 oct. 2021
 *      Author: Agustin
 */
#include "inputs.h"

int pedirEntero(int* entero, char* mensaje, char* mensajeError, int min, int max)
{
	int retorno = -1;
	int numeroIngresado;

	if(entero != NULL && mensaje != NULL && mensajeError != NULL && min < max)
	{
		printf("%s", mensaje);
		fflush(stdin);
		scanf("%d", &numeroIngresado);

		while(numeroIngresado < min || numeroIngresado > max)
		{
			printf("%s", mensajeError);
			fflush(stdin);
			scanf("%d", &numeroIngresado);
		}

		*entero = numeroIngresado;
		retorno = 0;
	}

	return retorno;
}
int validarEntero(char pEnteroAValidar[])
{
    int retorno=1;

    if(strlen(pEnteroAValidar)>0)
    {
        for(int i=0;i<strlen(pEnteroAValidar);i++)
        {
            if(isdigit(pEnteroAValidar[i])==0)
            {
                if(i==0 && pEnteroAValidar[0]=='-')
                {
                	retorno=1;
                }
                else
                {
                	retorno=0;
                }
            }
        }
    }
    else
    {
    	retorno=0;
    }

    return retorno;
}
int ingresoEntero(int* enteroValidado, char mensaje[], char mensajeError[], int min, int max)
{
    char auxEntero[150];
    int retorno=0;

    if(enteroValidado!=NULL && mensaje!=NULL && mensajeError!=NULL && min<max)
    {
        printf("%s",mensaje);
        fflush(stdin);
        gets(auxEntero);

        while(validarEntero(auxEntero)==0 ||  atoi(auxEntero)>max  || atoi(auxEntero)<min)
        {
           if(validarEntero(auxEntero)==0 || atoi(auxEntero)>max  || atoi(auxEntero)<min)
           {
        	printf("%s", mensajeError);
            fflush(stdin);
            gets(auxEntero);
           }
        }

        *enteroValidado=atoi(auxEntero);
        retorno=1;
    }
    return retorno;
}
int SoloLetras(char* palabra)
{
    int retorno=1;
    int i=0;

    if(palabra!=NULL)
    {
		while(palabra[i]!='\0')

		{
			if((palabra[i]!=' ')&&(palabra[i] < 'a'||  palabra[i] > 'z') && (palabra[i] < 'A' || palabra[i] > 'Z'))
			{
				retorno=-1;
			}
			i++;
		}
    }
			return retorno;
}

int pedirFlotante(float* flotante, char* mensaje, char* mensajeError, float min, float max)
{
	int retorno = -1;
	float numeroIngresado;

	if(flotante != NULL && mensaje != NULL && mensajeError != NULL && min < max)
	{
		printf("%s", mensaje);
		fflush(stdin);
		scanf("%f", &numeroIngresado);

		while(numeroIngresado < min || numeroIngresado > max)
		{
			printf("%s", mensajeError);
			fflush(stdin);
			scanf("%f", &numeroIngresado);
		}

		*flotante = numeroIngresado;
		retorno = 0;
	}

	return retorno;
}

int pedirCadena(char* cadena, char* mensaje, char* mensajeError, int max)
{
	int retorno = -1;
	char buffer[256];
	int tam;

	if(cadena != NULL && mensaje != NULL && mensajeError != NULL && max > 0)
	{
		printf("%s", mensaje);
		fflush(stdin);
		scanf("%[^\n]", buffer);
		tam = strlen(buffer);

		while(tam > max || SoloLetras(buffer)==-1)
		{
			printf("%s", mensajeError);
			fflush(stdin);
			scanf("%[^\n]", buffer);
			tam = strlen(buffer);
		}


		strcpy(cadena, buffer);
		acomodarCadenaIngresada(cadena);
		retorno = 0;
	}

	return retorno;
}
int acomodarCadenaIngresada(char cadena[])
{
    int retorno=-1;
    int i=0;

    if(cadena!=NULL)
    {
        strlwr(cadena);
        cadena[0]=toupper(cadena[0]);

        while(cadena[i]!='\0')
        {
            if(cadena[i]==' ')
            {
                cadena[i+1]=toupper(cadena[i+1]);
            }
            i++;
        }
        retorno=1;
    }

    return retorno;
}
int pedirCaracter(char* caracter, char* mensaje)
{
	int retorno = -1;

	if(caracter != NULL && mensaje != NULL)
	{
		printf("%s", mensaje);
		fflush(stdin);
		*caracter = getchar();
		retorno = 0;
	}

	return retorno;
}





