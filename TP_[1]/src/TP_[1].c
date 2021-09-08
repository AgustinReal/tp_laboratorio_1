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
 * @param 2do while: Nos permite elgir la operacion entre 1 al 6.
 * @param switch: Nos permite guardar en cada caso resultado de la operacion elegida.
 * @return
 */
/* Errores comunenes de usar la calculadora:
 * 1ro:Division por cero.
 * 2do:Factorial de numeros negativos.
 * 3ero:Usted quiere seguir calculando y no pone 's', no podra seguir.
 */
int main(void)
{
	setbuf(stdout, NULL);
	float a;
	float b;
	int intParaA;
    int intParaB;
	int tipoDeCalculo;
	float resultado;
	float resultadoResta;
	float resultadoMultiplicacion;
	float resultadoDivision;
	float factorialA;
	float factorialB;
	char continuar;

	continuar='s';

	while(continuar=='s')
	{
			printf("|||||||||||||||||||||||||||||||||\n");
			printf("|||||| Calculadora Agustin ||||||\n");
			printf("|||||||||||||||||||||||||||||||||\n");
			printf("\n");
			printf("Ingrese el primer numero: ");
			fflush(stdin);
			scanf("%f", &a);

			printf("\n");
			printf("Ingrese el segundo numero: ");
			fflush(stdin);
			scanf("%f", &b);

			printf("\n");
			printf("Ingrese la operacion que desea utilizar");
			printf("\nSuma=(1)");
			printf("\nResta=(2)");
			printf("\nDiviion=(3)");
			printf("\nMultiplicacion=(4)");
			printf("\nFactorial=(5)");
			printf("\nUsted eligio: ");
			fflush(stdin);
			scanf("%d", &tipoDeCalculo);

			while(tipoDeCalculo<1 || tipoDeCalculo>6)
			{
				printf("Error.Ingrese la operacion que desea utilizar");
				printf("\nSuma=(1)");
				printf("\nResta=(2)");
				printf("\nDiviion=(3)");
				printf("\nMultiplicacion=(4)");
				printf("\nFactorial=(5)");
				printf("\nUsted eligio: ");
				fflush(stdin);
				scanf("%d", &tipoDeCalculo);
			}

			switch(tipoDeCalculo)
			{
			 case 1:

				resultado=sumar(a, b);

				printf("\n");
				printf("El resultado de %.2f+%.2f es: %.2f", a, b, resultado);
				break;
			 case 2:

				resultadoResta=resta(a, b);

				printf("\n");
				printf("El resultado de %.2f-%.2f es: %.2f", a, b, resultadoResta);
				break;
			 case 3:

				resultadoDivision=division(a, b);

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
				break;
			 case 4:

			 		resultadoMultiplicacion=Multiplicacion(a, b);

			 		printf("\n");
			 		printf("El resultado de %.2fx%.2f es: %.2f", a, b, resultadoMultiplicacion);
			 		break;
			 case 5:

				 intParaA=a;
				 intParaB=b;
				 printf("\n");

				 if((a<2)||(a-intParaA!=0))
				 {
					 printf("No se pudo calcular el factorial A. ");
				 }
				 else
				 {
					 factorialA=calcularFactorial(a);
					 printf("El factorial de %.2f es %.2f y ", a, factorialA);
				 }

				 if((b<2)||(b-intParaB!=0))
				 {
					 printf("No se pudo calcular el factorial B. ");
				 }
				 else
				 {
					 factorialB=calcularFactorial(b);
					 printf("El factorial de %.2f es %.2f ", b, factorialB);
				 }
			     break;
			}
		printf("\n");
		printf("\n");
		printf("¿Desea seguir calculando? s/n: ");
		fflush(stdin);
		scanf("%s", &continuar);
	}

}

