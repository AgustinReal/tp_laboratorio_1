/*
 * parser.h
 *
 *  Created on: 4 nov. 2021
 *      Author: Usuario
 */
#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"

#ifndef PARSER_H_
#define PARSER_H_

/**
 * @fn int parser_EmployeeFromText(FILE*, LinkedList*)
 * @brief Esta funcion parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * @param pFile: Es el archivo a parsear en este caso modo texto.
 * @param pArrayListEmployee: La lista de empleados.
 *
 * @return Retorna 1 o 0: 1 si se puedo parsear o 0 si no se pudo parsear.
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee);
/**
 * @fn int parser_EmployeeFromBinary(FILE*, LinkedList*)
 * @brief Esta funcion parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * @param pFile: Es el archivo a parsear en este caso modo binario.
 * @param pArrayListEmployee: La lista de empleados.
 *
 * @return Retorna 1 o 0: 1 si se puedo parsear o 0 si no se pudo parsear.
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee);

#endif /* PARSER_H_ */
