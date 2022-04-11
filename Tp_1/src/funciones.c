#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

void pedirUnCaracter(char* caracter, char* mensaje)
{
    printf("%s", mensaje);
    fflush(stdin);
    *caracter=getchar();
}
void ingresoEntero(int* entero, char* mensaje)
{
    int auxNumero;

    printf("%s", mensaje);
    scanf("%d", &auxNumero);

    *entero=auxNumero;
}
void ingresoFlotante(float* floatante, char* mensaje)
{
    float auxNumero;

    printf("%s", mensaje);
    scanf("%f", &auxNumero);

    *floatante=auxNumero;
}
float aplicarDescuentoDiezPorciento(float precio)
{
    float descuento;
    float precioConDescuento;

    descuento=precio*0.10;

    precioConDescuento=precio-descuento;

    return precioConDescuento;
}
float aplicarInteresVeiticincoPorciento(float precio)
{
    float aumento;
    float precioConAumento;

    aumento=precio*0.25;

    precioConAumento=precio+aumento;

    return precioConAumento;
}
float aplicarValorBitcoin(float precio)
{
    float valorBitcoin=4606954.55;
    float precioAplicadoBitcoin;

    precioAplicadoBitcoin=precio/valorBitcoin;

    return precioAplicadoBitcoin;
}
float aplicarValorUniforme(float precio, int kilometros)
{
    float resultado;

    resultado=precio/(float)kilometros;

    return resultado;
}
float aplicarDiferenciaPrecio(float precioAerolineas, float precioLatam)
{
    float diferencia;

    diferencia=precioLatam-precioAerolineas;

    return diferencia;
}
void imprimirMenu(int* pFlagUno, int* pFlagDos, int kilometros, float precioLatam, float precioAerolinea)
{
    if(*pFlagUno==0)
    {
        printf("\nIngrese 1 para los kilometros de su destino: X");
    }
    else
    {
        printf("\nLos kilometros ingresados: %d km", kilometros);
    }

    if(*pFlagDos==0)
    {
        printf("\nIngrese 2 para el ingreso de los precio de vuelo: Y, Z");
        printf("\nPrecio vuelvo Arolineas: Y");
        printf("\nPrecio vuelo Latam: Z");
    }
    else
    {
        printf("\nEl precio de vuelo Arolineas ingresado: $%.2f", precioAerolinea);
        printf("\nEl precio de vuelo Latam ingresado: $%.2f", precioLatam);
    }

    printf("\nIngrese 3 para calcular todos los costos");
    printf("\nIngrese 4 para informar resultados");
    printf("\nIngrese 5 para la carga forzada de datos");
    printf("\nIngrese 6 para Salir\n");
}
void imprimirCartel(char* mensaje)
{
    printf("\n");
    printf(" _________________________________________________________\n");
    printf("|                                                         |\n");
    printf(mensaje);
    printf("|_________________________________________________________|\n");
    printf("\n");

}
void calcularCalculosDeCostos(float precioUno, float kilometros)
{
    aplicarDescuentoDiezPorciento(precioUno);
    aplicarInteresVeiticincoPorciento(precioUno);
    aplicarValorBitcoin(precioUno);
    aplicarValorUniforme(precioUno, kilometros);
}
void mostarResultados(float precioUno, float precioDos, int kilometros)
{
    float operacionDescuentoLatam;
    float operacionDescuentoAerolineas;
    float operacionAumentoLatam;
    float operacionAumentoAerolineas;
    float operacionCambioMonedaBitcoinLatam;
    float operacionCambioMonedaBitcoinAerolineas;
    float operacionPrecioUniformeLatam;
    float operacionPrecioUniformeAerolineas;
    float operacionDiferenciaLatamAerolineas;

    operacionDescuentoLatam=aplicarDescuentoDiezPorciento(precioUno);
    operacionDescuentoAerolineas=aplicarDescuentoDiezPorciento(precioDos);
    operacionAumentoLatam=aplicarInteresVeiticincoPorciento(precioUno);
    operacionAumentoAerolineas=aplicarInteresVeiticincoPorciento(precioDos);
    operacionCambioMonedaBitcoinLatam=aplicarValorBitcoin(precioUno);
    operacionCambioMonedaBitcoinAerolineas=aplicarValorBitcoin(precioDos);
    operacionPrecioUniformeLatam=aplicarValorUniforme(precioUno,kilometros);
    operacionPrecioUniformeAerolineas=aplicarValorUniforme(precioDos,kilometros);
    operacionDiferenciaLatamAerolineas=aplicarDiferenciaPrecio(precioDos, precioUno);

    printf("KMs Ingresados: %d km\n", kilometros);
    printf("\nPrecio Aerolineas: $%.2f", precioDos);
    printf("\nPrecio con tarjeta de debito: $%.2f", operacionDescuentoAerolineas);
    printf("\nPrecio con tarjeta de credito: $%.2f", operacionAumentoAerolineas);
    printf("\nPrecio pagando con bitcoin: $%f", operacionCambioMonedaBitcoinAerolineas);
    printf("\nPrecio unitario: $%.2f\n", operacionPrecioUniformeAerolineas);
    printf("\nPrecio Latam: $%.2f", precioUno);
    printf("\nPrecio con tarjeta de debito: $%.2f", operacionDescuentoLatam);
    printf("\nPrecio con tarjeta de credito: $%.2f", operacionAumentoLatam);
    printf("\nPrecio pagando con bitcoin: $%f", operacionCambioMonedaBitcoinLatam);
    printf("\nPrecio unitario: $%.2f\n", operacionPrecioUniformeLatam);
    printf("\nLa diferencia de precio es: $%.2f\n\n", operacionDiferenciaLatamAerolineas);
}
void mostrarOpcionCuatro(int* pFlagUno, int* pFlagDos, int* pFlagTres, float precioUno, float precioDos, int kilometros)
{
    if(*pFlagUno==0 || *pFlagDos==0 || *pFlagTres==0)
    {
        printf("\n _________________________________________________________\n");
        printf("|                                                         |\n");
        if(*pFlagUno==0)
        {
            printf("|             No se ingresaron los KM                     |\n");
        }
        if(*pFlagDos==0)
        {
            printf("|             No se ingresaron los vuelos                 |\n");
        }
        if(*pFlagTres==0)
        {
            printf("|             No se hicieron los calculos                 |\n");
        }
        printf("|_________________________________________________________|\n\n");
    }
    else
    {
        imprimirCartel("|                 Resultados aplicados                    |\n");
        mostarResultados(precioUno, precioDos, kilometros);
    }
}
