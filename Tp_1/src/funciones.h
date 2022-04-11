/*
 * funciones.h
 *
 *  Created on: 3 abr. 2022
 *      Author: Usuario
 */

#ifndef FUNCIONES_H_
#define FUNCIONES_H_





#endif /* FUNCIONES_H_ */

/**
 * @fn float aplicarDescuentoDiezPorciento(float)
 * @brief Esta funcion permite calcular un descuento del 10%.
 *
 * @param precio es el valor que se le aplica el descuento de 10%.
 *
 * @return devuele el descuento aplicado.
 */
float aplicarDescuentoDiezPorciento(float precio);
/**
 * @fn float aplicarInteresVeiticincoPorciento(float)
 * @brief Esta funcion aplica un aumento del 25%
 *
 * @param precio es el valor que se le aplica el aumento de 25%.

 * @return devuele el aumento aplicado.
 */
float aplicarInteresVeiticincoPorciento(float precio);
/**
 * @fn float aplicarValorBitcoin(float)
 * @brief Esta fumcion transforma el valor en pesos a bitcoin.
 *
 *
 * @param precio es el valor que se le aplica el cambio de moneda.
 *
 * @return devuelve el cambio de pesos a bitcoin.
 */
float aplicarValorBitcoin(float precio);
/**
 * @fn float aplicarValorUniforme(float, int)
 * @brief Esta funcion divide el precio ingresado por los kilometros ingresados(p*k).
 *
 * @param precio es el valor ingresado por el usuario "Precio del viaje"
 * @param kilometros es el valor ingresado por el usuario "Kilometros del viaje"
 *
 * @return devuelve la multiplicacion de precio por kilometros.
 */
float aplicarValorUniforme(float precio, int kilometros);
/**
 * @fn float aplicarDiferenciaPrecio(float, float)
 * @brief Esta funcion resta el precio Aerolineas con el precio Latam.
 *
 * @param precioAerolineas es el valor ingresado por el usuario "precio de viaje Aerolineas".
 * @param precioLatam es el valor ingresado por el usuario "precio de viaje Latam".
 *
 * @return devuelve la resta de los 2 volores ingresados.
 */
float aplicarDiferenciaPrecio(float precioAerolineas, float precioLatam);
/**
 * @fn void imprimirCartel(char*)
 * @brief Esta funcion impreme encabezados.
 *
 * @param mensaje es el encabezado que se muestra en pantalla.
 */
void imprimirCartel(char* mensaje);
/**
 * @fn void imprimirMenu(int*, int*, int, float, float)
 * @brief Esta funcion imprime el menu principal de lo aerolinea de viaje.
 *
 * @param pFlagUno se encarga de saber si se ingreso los kilometros. si esta en 1 se ingreso el km pero si esta en 0 no se ingreso los km.
 * @param pFlagDos se encarga de saber si se ingreso los precios. si esta en 1 se ingreso los precios pero si esta en 0 no se ingreso los precios.
 * @param kilometros km ingresados
 * @param precioLatam precio latam ingresado
 * @param precioAerolinea precio aerolinea ingresado
 */
void imprimirMenu(int* pFlagUno, int* pFlagDos, int kilometros, float precioLatam, float precioAerolinea);
/**
 * @fn void pedirUnCaracter(char*, char*)
 * @brief Esta funcion permite el ingreso de un caracter.
 *
 * @param caracter caracter ingresado.
 * @param mensaje printf mensaje en pantalla.
 */
void pedirUnCaracter(char* caracter, char* mensaje);
/**
 * @fn void ingresoFlotante(float*, char*)
 * @brief Esta funcion permite el ingreso de un numero flotante.
 *
 * @param floatante flotante ingresado (numero real).
 * @param mensaje printf mensaje en pantalla
 */
void ingresoFlotante(float* floatante, char* mensaje);
/**
 * @fn void ingresoEntero(int*, char*)
 * @brief Esta funcion permite el ingreso de un numero entero.
 *
 * @param entero numero ingresado (numero entero).
 * @param mensaje printf mensaje en pantalla.
 */
void ingresoEntero(int* entero, char* mensaje);
/**
 * @fn void calcularCalculosDeCostos(float, float)
 * @brief Esta funcion permite calcular todas las funciones invocandolas en la misma funcion.
 *
 * @param precioUno en esta parte ingresas cualquiera de los 2 precios pedidos y esta funcion calculara todos con es precio ingresado.
 * @param kilometros km ingresados.
 */
void calcularCalculosDeCostos(float precioUno, float kilometros);
/**
 * @fn void mostarResultados(float, float, int)
 * @brief Esta funcion imprime los valores todos los calculos realizados.
 *
 * @param precioUno precio latam ingresado.
 * @param precioDos precio aerolinea ingresado.
 * @param kilometros km ingresados.
 */
void mostarResultados(float precioUno, float precioDos, int kilometros);
/**
 * @fn void mostrarOpcionCuatro(int*, int*, int*, float, float, int)
 * @brief Esta funcion se encarga de mostrar la opcion 4 con su debidos resultados o con error de ingreso.
 *
 * @param pFlagUno se encarga de saber si se ingreso los kilometros. si esta en 1 se ingreso el km pero si esta en 0 no se ingreso los km.
 * @param pFlagDos se encarga de saber si se ingreso los precios. si esta en 1 se ingreso los precios pero si esta en 0 no se ingreso los precios.
 * @param pFlagTres se encarga de saber si se realizaron los calculos. si esta en 1 se realizaron los calculos pero si esta en 0 no se realizaron los calculos.
 * @param precioUno precio latam ingresado.
 * @param precioDos precio aerolinea ingresado.
 * @param kilometros kilometros km ingresados.
 */
void mostrarOpcionCuatro(int* pFlagUno, int* pFlagDos, int* pFlagTres, float precioUno, float precioDos, int kilometros);

