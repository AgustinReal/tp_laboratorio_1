/*
 * ingrsosAux.h
 *
 *  Created on: 1 oct. 2021
 *      Author: Agustin
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#ifndef INGRESOSAUX_H_
#define INGRESOSAUX_H_
/**
 * @fn int requestInteger(int*, char*, char*, char*, int, int)
 * @brief This function: Allows you to request an integer "a number", give a message to the user with or without error and
 * also allows to give a range of number that can be entered from minimum or maximum.
 *
 * @param integer: Number that is entered and stored in this integer variable, to use it later.
 * @param message: We ask something to the user.
 * @param messageError: What we ask the user to do, we tell him to re-enter it.
 * @param min: Is the minimum integer the user can enter.
 * @param max This is the maximum integer the user can enter.
 * @return returns 0 or -1: "0" if it was able to perform the function or "-1" if it was not able to perform the function.
 */
int pedirEntero(int* entero, char* mensaje, char* mensajeError, int min, int max);
/**
 * @fn int requestFloat(float*, char*, char*, char*, float, float)
 * @brief This function: Allows you to request a float number "a real number", give a message to the user with or without error, and
 * also allows to give a range of real number that can be entered from minimum or maximum.
 *
 * @param float: Real number that is entered and stored in this float variable, to use it later.
 * @param message: We ask something to the user.
 * @param messageError: What we ask the user we tell him to re-enter.
 * @param min: Is the minimum float the user can enter.
 * @param max This is the floating maximum that the user can enter.
 * @return returns 0 or -1: "0" if it was able to perform the function or "-1" if it was not able to perform the function.
 */
int pedirFlotante(float* flotante, char* mensaje, char* mensajeError, float min, float max);
/**
 * @fn int requestString(char*, char*, char*, char*, int)
 * @brief This function: Allows to request a string from the user, i.e. a string of chars,
 * which can be names, etc...
 *
 * @param string: It is the string of chars that is entered and saved in this variable string, to use it later.
 * @param message: We ask the user to enter something:
 * @param messageError: We ask the user to re-enter something:
 * @param max: This is the maximum number of letters the user can input to the user.
 *
 * @return returns 0 or -1: "0" if it was able to perform the function or "-1" if it was not able to perform the function.
 */
int pedirCadena(char* cadena, char* mensaje, char* mensajeError, int max);
/**
 * @fn int requestCharacter(char*, char*)
 * @brief In this function we can request a character from the user.
 *
 * @param character: Is where the letter or character requested by the user is going to be saved.
 * @param message: This is the message we ask the user for.
 * @return returns 0 or -1: "0" if it was able to perform the function or "-1" if it was not able to perform the function.
 */
/**
 * @fn int LettersOnly(char*)
 * @brief This function: Allows us to verify that only letters can be entered.
 *
 * @param word: This is what the user enters and we use it to verify by means of an if.
 * @return returns 1 or -1: "-1" if it was able to perform the function or "1" if it was not able to perform the function.
 */
int pedirCaracter(char* caracter, char* mensaje);

/**
 * @fn int LettersOnly(char*)
 * @brief This function: Allows us to verify that only letters can be entered.
 *
 * @param word: This is what the user enters and we use it to verify by means of an if.
 * @return returns 1 or -1: "-1" if it was able to perform the function or "1" if it was not able to perform the function.
 */
int SoloLetras(char* palabra);
/**
 * @fn int setInputString(char[])
 * @brief This function: Allows the user when entering a name with uppercase and lowercase letters.
 * in an interleaved form, the function fixes it.
 *
 * @param string:This is the array of chars entered by the user.
 *
 * @return returns 1 or -1: "1" if it was able to perform the function or "-1" if it was not able to perform the function.
 */
int acomodarCadenaIngresada(char cadena[]);

#endif /* INGRESOSAUX_H_ */
