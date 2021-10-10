/*
 * ingrsosAux.h
 *
 *  Created on: 1 oct. 2021
 *      Author: Agustin
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef INGRESOSAUX_H_
#define INGRESOSAUX_H_

int pedirEntero(int* entero, char* mensaje, char* mensajeError, int min, int max);
int pedirFlotante(float* flotante, char* mensaje, char* mensajeError, float min, float max);
int pedirCadena(char* cadena, char* mensaje, char* mensajeError, int max);
int pedirCaracter(char* caracter, char* mensaje);

#endif /* INGRESOSAUX_H_ */
