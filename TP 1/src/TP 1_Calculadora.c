/*
 ============================================================================
 Tp n°1: Calculadora.
 Año: 2021.
 Real Agustin Div 1D.
 ============================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include"funciones.h"
/**
 * @fn int main(void)
 * @brief Permite elegir la operacion que se desea utilizar.
 * @param 1er while: Su funcion es si el usuario desea ingresar otro calculo elige s(si)/n(no).
 * @param 2do while: Nos permite elgir la operacion entre 1 al 5.
 * @param switch: Nos permite guardar en cada caso los pautas realizadas del TP 1.
 * @return
 */
/* Errores comunenes de usar la calculadora:
 * 1ro:Division por cero.
 * 2do:Factorial de numeros negativos y numeros reales.
 * 3ero:Usted quiere seguir calculando no debe tocar 5 y si queire salir pulsa 5 y confirma con "s".
 */
int main(void)
{
	setbuf(stdout, NULL);
	float a;
	float b;
	int tipoDeCalculo;
	float resultado;
	float resultadoResta;
	float resultadoMultiplicacion;
	float resultadoDivision;
	float factorialA;
	float factorialB;
	char continuar;
	int flagIngresoPrimero=0;
	int flagIngresoSegundo=0;
	int flagIngresoTerceraOpcion=0;

	continuar='s';

	while(continuar=='s')
	{
		printf("|||||||||||||||||||||||||||||||||\n|||||| Calculadora Agustin ||||||\n|||||||||||||||||||||||||||||||||\n");
		if(flagIngresoPrimero==0)
		{
			printf("\nIngrese 1 para ingresar el primer numero: X");
		}
		else
		{
			printf("\nEl primer numero ingresado A es: %.2f", a);
		}
		if(flagIngresoSegundo==0)
		{
			printf("\nIngrese 2 para ingresar el segundo numero: Y");
		}
		else
		{
			printf("\nEl segundo numero ingresado B es: %.2f", b);
		}
		printf("\nIngrese 3 para realizar las operaciones");
		printf("\nIngrese 4 para mostrar las operaciones");
		printf("\nIngrese 5 para salir");
		printf("\nUsted eligio: ");
		fflush(stdin);
		scanf("%d", &tipoDeCalculo);

		while(tipoDeCalculo<1 || tipoDeCalculo>5)
		{
			printf("|||||||||||||||||||||||||||||||||\n|||||| Calculadora Agustin ||||||\n|||||||||||||||||||||||||||||||||\n");
			printf("\nError. Ingrese las opciones validas del 1 al 5.");
			if(flagIngresoPrimero==0)
			{
				printf("\nIngrese 1 para ingresar el primer numero: X");
			}
			else
			{
				printf("\nEl primer numero ingresado A es: %.2f", a);
			}
			if(flagIngresoSegundo==0)
			{
				printf("\nIngrese 2 para ingresar el segundo numero: Y");
			}
			else
			{
				printf("\nEl segundo numero ingresado B es: %.2f", b);
			}
			printf("\nIngrese 3 para realizar las operaciones");
			printf("\nIngrese 4 para mostrar las operaciones");
			printf("\nIngrese 5 para salir");
			printf("\nUsted eligio: ");
			fflush(stdin);
			scanf("%d", &tipoDeCalculo);
		}
		switch (tipoDeCalculo)
		{
			case 1:
				if(flagIngresoPrimero==0)
				{
					printf("\n");
					printf("Ingrese el primer numero: ");
					fflush(stdin);
					scanf("%f", &a);
					flagIngresoPrimero=1;
				}
				else
				{
					printf("\n");
					printf("\n#------------------------------------------------------#");
					printf("\n");
					printf("Ya ingreso el primer numero");
					printf("\n#------------------------------------------------------#");
					printf("\n");
					printf("\n");
				}
				break;
			case 2:
				if(flagIngresoPrimero==0)
				{
					printf("\n");
					printf("\n#------------------------------------------------------------#");
					printf("\n");
					printf("No puede ingresar el segundo operador si no ingreso el primero");
					printf("\n#------------------------------------------------------------#");
					printf("\n");
					printf("\n");

				}
				else
				{
					if(flagIngresoSegundo==0)
					{
						printf("\n");
						printf("Ingrese el segundo numero: ");
						fflush(stdin);
						scanf("%f", &b);
						flagIngresoSegundo=1;
					}
					else
					{
						printf("\n");
						printf("\n#------------------------------------------------------#");
						printf("\n");
						printf("Ya ingreso el segundo numero");
						printf("\n#------------------------------------------------------#");
						printf("\n");
						printf("\n");
					}
				}
				break;
			case 3:
				if(flagIngresoPrimero==0)
				{
					printf("\n");
					printf("\n#----------------------------------------------------------------------------------#");
					printf("\n");
					printf("No puede ingresar el tercera opcion si no ingreso el primero y el segundo ingreso");
					printf("\n#----------------------------------------------------------------------------------#");
					printf("\n");
					printf("\n");
				}
				else
				{
					if(flagIngresoSegundo==0)
					{
						printf("\n");
						printf("\n#---------------------------------------------------------#");
						printf("\n");
						printf("No puede ingresar el tercera opcion si no ingreso el segundo");
						printf("\n#---------------------------------------------------------#");
						printf("\n");
						printf("\n");
					}
					else
					{
						if(flagIngresoTerceraOpcion==0)
						{
							resultado=sumar(a, b);
							resultadoResta=resta(a, b);
							if(b!=0)
							{
								resultadoDivision=division(a, b);
							}
							resultadoMultiplicacion=Multiplicacion(a, b);
							if(verificarSePuedeCalcularFactorial(a)==1)
							{
								factorialA=calcularFactorialEnteros(a);
							}
							if(verificarSePuedeCalcularFactorial(b)==1)
							{
								factorialB=calcularFactorialEnteros(b);
							}
							printf("\n");
							printf("\n#------------------------------------------------------#");
							printf("\n");
							printf("Se realizaron las operarciones");
							printf("\n#------------------------------------------------------#");
							printf("\n");
							printf("\n");
							flagIngresoTerceraOpcion=1;
						}
						else
						{
							printf("\n");
							printf("\n#------------------------------------------------------#");
							printf("\n");
							printf("Ya ingreso la tercera opcion");
							printf("\n#------------------------------------------------------#");
							printf("\n");
							printf("\n");
						}
					}
				}
				break;
			case 4:
				if(flagIngresoTerceraOpcion==1)
				{
					printf("\n");
					printf("\n#------------------------------------------------------#");
					printf("\n");
					printf("Resultados de las operaciones");
					printf("\n#------------------------------------------------------#");
					printf("\n");
					printf("\n");
					printf("\nEl resultado de %.2f+%.2f es: %.2f", a, b, resultado);
					printf("\nEl resultado de %.2f-%.2f es: %.2f", a, b, resultadoResta);
					if(b==0)
					{
						printf("\n");
						printf("No es posible dividir por cero");
					}
					else
					{
						printf("\n");
						printf("El resultado de %.2f/%.2f es: %.2f", a, b, resultadoDivision);

					}
					printf("\n");
					printf("El resultado de %.2fx%.2f es: %.2f", a, b, resultadoMultiplicacion);
					printf("\n");
					if(verificarSePuedeCalcularFactorial(a)==0)
					{
						printf("No se pudo calcular el factorial A. ");
					}
					else
					{
						printf("El factorial de %.2f es %.2f y ", a, factorialA);
					}
					if(verificarSePuedeCalcularFactorial(b)==0)
					{
						printf("No se pudo calcular el factorial B. ");
					}
					else
					{
						printf("El factorial de %.2f es %.2f ", b, factorialB);
					}
					flagIngresoPrimero=0;
					flagIngresoSegundo=0;
					flagIngresoTerceraOpcion=0;
				}
				else
				{
					printf("\n");
					printf("\n#-------------------------------------------------------------------#");
					printf("\n");
					printf("No se puedo mostrar los resultados, sin antes realizar las operaciones");
					printf("\n#-------------------------------------------------------------------#");
					printf("\n");
					printf("\n");
				}
				break;
				case 5:
					printf("¿Desea salir de la calculadora s/n: ");
					fflush(stdin);
					scanf("%s", &continuar);
				break;
		}
		printf("\n");
	}
	return 0;
}
