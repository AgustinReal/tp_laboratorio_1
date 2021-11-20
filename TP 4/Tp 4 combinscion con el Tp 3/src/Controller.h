
#ifndef controller_H_INCLUDED
#define controller_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

#include <string.h>
#include <ctype.h>
#include "../src/LinkedList.h"
#include "Employee.h"

/**
 * @fn int controller_loadFromText(char*, LinkedList*)
 * @brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * @param path: Es el camino que esta asignado el archivo en este caso en modo texto.
 * @param pArrayListEmployee: Lista de los empleados.
 *
 * @return Esta funcion retorna: 1 o -1: 1 si la funcion se pudo relaizar o -1 si la funcion no se lo logro realizar.
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee);
/**
 * @fn int controller_loadFromBinary(char*, LinkedList*)
 * @brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * @param path: Es el camino que esta asignado el archivo en este caso en modo binaria.
 * @param pArrayListEmployee: Lista de los empleados..
 *
 * @return Esta funcion retorna: 1 o -1: 1 si la funcion se pudo relaizar o -1 si la funcion no se lo logro realizar.
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee);
/**
 * @fn int controller_addEmployee(LinkedList*)
 * @brief Alta de empleados, es decir agrega un empleado a la lista buscando el ultimo espacio libre
 * y lo guarga con sus datos.
 *
 * @param pArrayListEmployee: Lista de los empleados.
 *
 * @return Esta funcion retorna: 1 o -1: 1 si la funcion se pudo relaizar o -1 si la funcion no se lo logro realizar.
 */
int controller_addEmployee(LinkedList* pArrayListEmployee);
/**
 * @fn int controller_editEmployee(LinkedList*)
 * @brief Esta funcion permite modificar los datos de un empleado agregado en la lista
 * se busca por el id del empleado.
 *
 * @param pArrayListEmployee: Lista de los empleados.
 *
 * @return Esta funcion retorna: 1 o -1: 1 si la funcion se pudo relaizar o -1 si la funcion no se lo logro realizar.
 */
int controller_editEmployee(LinkedList* pArrayListEmployee);
/**
 * @fn int controller_removeEmployee(LinkedList*)
 * @brief Esta funcion permite eliminar a un empledo de la lista de empleados.
 * Se lo busca por id y si esta en la lista se elimina.
 *
 * @param pArrayListEmployee: Lista de los empleados.
 *
 * @return Esta funcion retorna: 1 o -1: 1 si la funcion se pudo relaizar o -1 si la funcion no se lo logro realizar.
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee);
/**
 * @fn int controller_ListEmployee(LinkedList*)
 * @brief Esta funcion permite mostrar las lista de los empleados cargados.
 *
 * @param pArrayListEmployee: Lista de los empleados.
 *
 * @return Esta funcion retorna: 1 o -1: 1 si la funcion se pudo relaizar o -1 si la funcion no se lo logro realizar.
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee);
/**
 * @fn int controller_sortEmployee(LinkedList*)
 * @brief Esta funcion permite ordenar los empleados de 8 formas mediante un sud menu,
 * de las siguientes formas ascedente o descendente el tipo de id o horas o nombre o sueldos.
 *
 * @param pArrayListEmployee: Lista de los empleados.
 *
 * @return Esta funcion retorna: 1 o -1: 1 si la funcion se pudo relaizar o -1 si la funcion no se lo logro realizar.
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee);
/**
 * @fn int controller_saveAsText(char*, LinkedList*)
 * @brief Esta funcion Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * @param path: Es el camino que esta asignado el archivo en este caso en modo texto.
 * @param pArrayListEmployee: Lista de los empleados.
 *
 * @return Esta funcion retorna: 1 o -1: 1 si la funcion se pudo relaizar o -1 si la funcion no se lo logro realizar.
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee);
/**
 * @fn int controller_saveAsText(char*, LinkedList*)
 * @brief Esta funcion Guarda los datos de los empleados en el archivo dataBinaria.bin (modo binario).
 *
 * @param path: Es el camino que esta asignado el archivo en este caso en modo binario.
 * @param pArrayListEmployee: Lista de los empleados.
 *
 * @return Esta funcion retorna: 1 o -1: 1 si la funcion se pudo relaizar o -1 si la funcion no se lo logro realizar.
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee);


#endif


