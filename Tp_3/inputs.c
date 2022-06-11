/*
 * inputs.c
 *
 *  Created on: 4 jun. 2022
 *      Author: Usuario
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "inputs.h"


int validarCaracter(char* charAValidar, char mensaje[], char mensajeError[], char opcionUno, char opcionDos)
{
    int todoOk=0;
    char respuesta;

    if(mensaje!=NULL && mensajeError!=NULL)
    {
        printf("%s", mensaje);
        fflush(stdin);
        scanf("%c",&respuesta);

        while(respuesta != opcionUno && respuesta != opcionDos)
        {
                printf("%s", mensajeError);
                fflush(stdin);
                scanf("%c",&respuesta);
        }

        *charAValidar=respuesta;
        todoOk=1;
    }
    return todoOk;
}

int ingresoEntero(int* entero, char* mensaje, char* mensajeError, int min, int max)
{
    int todoOK=-1;
    int numeroIngresado;

    if(entero!=NULL && mensaje!=NULL && mensajeError!=NULL && min<max)
    {
       printf("%s", mensaje);
       fflush(stdin);
       scanf("%d", &numeroIngresado);

       while(numeroIngresado<min || numeroIngresado>max)
       {
          printf("%s", mensajeError);
          fflush(stdin);
          scanf("%d", &numeroIngresado);
       }

       *entero=numeroIngresado;
       todoOK=1;
    }

    return todoOK;
}
int ingresoFlotante(float* flotante, char* mensaje, char* mensajeError, float min, float max)
{
    int todoOk=-1;
    float flotanteIngresado;

    if(flotante!=NULL && mensaje!=NULL && mensajeError!=NULL && min<max)
    {
       printf("%s", mensaje);
       fflush(stdin);
       scanf("%f", &flotanteIngresado);

       while(flotanteIngresado<min || flotanteIngresado>max)
       {
           printf("%s", mensajeError);
           fflush(stdin);
           scanf("%f", &flotanteIngresado);
       }

       *flotante=flotanteIngresado;
       todoOk=1;
    }

    return todoOk;
}
int ingresoChar(char* letra, char* mensaje)
{
    int todoOk=-1;

    if(letra!=NULL && mensaje!=NULL)
    {
        printf("%s", mensaje);
        fflush(stdin);
        *letra=getchar();

        todoOk=1;
    }

    return todoOk;
}
int validarSoloLetras(char* cadena)
{
    int todoOk=-1;
    int i=0;

    if(cadena!=NULL)
    {
        while(cadena[i]!='\0')
        {
           if((cadena[i]!=' ') && (cadena[i]<'a' || cadena[i]>'z') && (cadena[i]<'A' || cadena[i]>'Z'))
           {
               todoOk=1;
           }
           i++;
        }
    }

    return todoOk;
}
int acomodarCadenaIngresada(char* cadena)
{
    int todoOk=-1;
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
        todoOk=1;
    }

    return todoOk;
}

int ingresoCadena(char* cadena, char* mensaje, char* mensajeError, int max , int min)
{
    int todoOk=-1;
    char buffer[256];
    int tam;

    if(cadena!=NULL && mensaje!=NULL && mensajeError!=NULL && max>0)
    {
        printf("%s", mensaje);
		fflush(stdin);
		scanf("%[^\n]", buffer);
		tam=strlen(buffer);

		while(tam>max || strlen(buffer)<min || validarSoloLetras(buffer)==1)
		{
			printf("%s", mensajeError);
			fflush(stdin);
			scanf("%[^\n]", buffer);
			tam=strlen(buffer);
		}

		strcpy(cadena, buffer);
		acomodarCadenaIngresada(cadena);
		todoOk=1;
    }

    return todoOk;
}
int ingresoLetrasNumeros(char* cadena, char* mensaje, char* mensajeError, int max, int min)
{
    int todoOk=-1;
    char buffer[256];
    int tam;


    if(cadena!=NULL && mensaje!=NULL && mensajeError!=NULL && max>0)
    {
        printf("%s", mensaje);
		fflush(stdin);
		scanf("%[^\n]", buffer);
		tam=strlen(buffer);

		while(strlen(buffer)<min || tam>max)
		{
			printf("%s", mensajeError);
			fflush(stdin);
			scanf("%[^\n]", buffer);
			tam=strlen(buffer);
		}

		strcpy(cadena, buffer);
		acomodarCadenaIngresada(cadena);
		todoOk=1;
    }

    return todoOk;
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
int ingresoEnteroPro(int* enteroValidado, char mensaje[], char mensajeError[], int min, int max)
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













































//Real Agustin 1°A, 11/5/2022



