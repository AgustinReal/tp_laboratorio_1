/*
 * funciones.c
 *
 *  Created on: 3 sep. 2021
 *      Author: Agustin
 */
#include <stdio.h>
#include <stdlib.h>

float sumar(float a, float b)
{
	float resultado;

	resultado=a+b;

	return resultado;
}
float resta(float a, float b)
{
	float resultado;

	resultado=a-b;

	return resultado;
}
float division(float a, float b)
{
	float resultado;
	float valor;

	if(b!=0)
	{
		resultado=a/b;
		valor=resultado;
	}
	else
	{
		valor=0;
	}

	return valor;
}
float Multiplicacion(float a, float b)
{
	float resultado;

	resultado=a*b;

	return resultado;
}
int calcularFactorialEnteros(float numero)
{
	int factorial=1;

	if( numero!=1 && numero!=0)
	{
		factorial=numero*calcularFactorialEnteros(numero-1);
	}
	return factorial;
}
int verificarPositivo(float numero)
{
	int valor=0;

	if(numero>0)
	{
		valor=1;
	}
	return valor;
}
int verificarEntero(float numero)
{
	int valor=0;

	if((int)numero-numero==0)
	{
		valor=1;
	}
	return valor;
}
int verificarSePuedeCalcularFactorial(float numero)
{
	int valor=0;

    if(verificarPositivo(numero)==1 && verificarEntero(numero)==1)
    {
    	valor=1;
    }

    return valor;
}

