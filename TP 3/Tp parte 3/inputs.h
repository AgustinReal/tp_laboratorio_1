/*
 * inputs.h
 *
 *  Created on: 10 oct. 2021
 *      Author: Agustin
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#ifndef INPUTS_H_
#define INPUTS_H_

/**
 * @fn int pedirEntero(int*, char*, char*, int, int)
 * @brief Esta funcion: Permite pedir un entero "un numero", darle un msj al usuario con error o sin el y
 * tambien permite darle un rango de numero que puede ingresar desde minimo o maximo.
 *
 * @param entero: Numero que se ingresa lo y guarda en esta variable entero, para usarlo dsp.
 * @param mensaje: Le pedimos algo al usuario.
 * @param mensajeError Lo que le pedimos al usuario le decimos que lo reingrese.
 * @param min: Es el minimo entero que puede ingresar el usuario.
 * @param max Es el maximo entero que puede ingresar el usuario.
 * @return retorna 0 o -1: "0" si pudo realizar la funcion o "-1" si no pudo realizar la funccion.
 */
int pedirEntero(int* entero, char* mensaje, char* mensajeError, int min, int max);
/**
 * @fn int SoloLetras(char*)
 * @brief Esta funcion: Nos permite verificar que solo se puedan ingresar letras.
 *
 * @param palabra: Es lo que ingresa el usaurio y lo usamos para verifica mediante un if.
 * @return retorna 1 o -1: "-1" si pudo realizar la funcion o "1" si no pudo realizar la funccion.
 */
int pedirFlotante(float* flotante, char* mensaje, char* mensajeError, float min, float max);
/**
 * @fn int pedirFlotante(float*, char*, char*, float, float)
 * @brief Esta funcion: Permite pedir un numero flotante "un numero real", darle un msj al usuario con error o sin el y
 * tambien permite darle un rango de numero real  que puede ingresar desde minimo o maximo.
 *
 * @param flotante: Numero real que se ingresa y lo guarda en esta variable flotante, para usarlo dsp.
 * @param mensaje: Le pedimos algo al usuario.
 * @param mensajeError Lo que le pedimos al usuario le decimos que lo reingrese.
 * @param min: Es el minimo flotante que puede ingresar el usuario.
 * @param max Es el maximo flotante que puede ingresar el usuario.
 * @return retorna 0 o -1: "0" si pudo realizar la funcion o "-1" si no pudo realizar la funccion.
 */
int pedirCadena(char* cadena, char* mensaje, char* mensajeError, int max);
/**
 * @fn int pedirCadena(char*, char*, char*, int)
 * @brief Esta funcion: Permite solicitar una cadena al usuario, es decir una cadena de chars,
 * la cual pueden ser nombres, etc...
 *
 * @param cadena: Es la cadena de chars que se ingresa y lo guarda en esta variable cadena, para usarlo dsp.
 * @param mensaje: Le pedimos el ingreso de algo al usuario:
 * @param mensajeError: Le pedimos el reingreso de algo al usuario:
 * @param max: Es la cantidad maxima de letras que puede ingresar el usuario al usuario.
 *
 * @return retorna 0 o -1: "0" si pudo realizar la funcion o "-1" si no pudo realizar la funccion.
 */
int pedirCaracter(char* caracter, char* mensaje);
/**
 * @fn int pedirCaracter(char*, char*)
 * @brief En esta funcion le podemos solicitar un caracter al usuario.
 *
 * @param caracter: ES donde se va a gurdar la letra o caracter pedida por el usuario.
 * @param mensaje: Es msj que le pedimos al usuario.
 * @return retorna 0 o -1: "0" si pudo realizar la funcion o "-1" si no pudo realizar la funccion.
 */
int SoloLetras(char* palabra);
/**
 * @fn int acomodarCadenaIngresada(char[])
 * @brief Esta funcion: Permite que el usuario cuando ingresa un nombre con mayusculas y minusculas
 * de forma intercalada, la funcion lo arregla
 *
 * @param cadena:Es el array de chars que ingresa el usuario.
 *
 * @return retorna 1 o -1: "1" si pudo realizar la funcion o "-1" si no pudo realizar la funccion.
 */
int acomodarCadenaIngresada(char cadena[]);
/**
 * @fn int ingresoEntero(int*, char[], char[], int, int)
 * @brief Esta funcion: Permite pedir un entero "un numero", darle un msj al usuario con error o sin el y
 * tambien permite darle un rango de numero que puede ingresar desde minimo o maximo.
 *
 * @param enteroValidado: Numero que se ingresa lo y guarda en esta variable entero, para usarlo dsp.
 * @param mensaje: Le pedimos algo al usuario.
 * @param mensajeError: Lo que le pedimos al usuario le decimos que lo reingrese.
 * @param min: Es el minimo entero que puede ingresar el usuario.
 * @param max: Es el maximo entero que puede ingresar el usuario.
 * @return retorna 1 o 0: "1" si pudo realizar la funcion o "0" si no pudo realizar la funccion.
 */
int ingresoEntero(int* enteroValidado, char mensaje[], char mensajeError[], int min, int max);
/**
 * @fn int validarEntero(char[])
 * @brief Esta funcion valida si el numero o el entero ingresado sea un numero, si ingresa un letra o otro tipo de caracter
 * no lo dejara ingresar.
 *
 * @param pEnteroAValidar: Es el parametro que usaremos para verificar que sea un numero.
 * @return retorna 1 o 0: "1" si pudo realizar la funcion o "0" si no pudo realizar la funccion.
 */
int validarEntero(char pEnteroAValidar[]);
#endif /* INPUTS_H_ */
