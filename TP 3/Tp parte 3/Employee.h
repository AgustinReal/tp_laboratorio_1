

#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "inputs.h"

typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
}Employee;

/**
 * @fn Employee employee_new*()
 * @brief Esta funcion: Se encarga de agregar un nuevo empleado y guardarlo en
 * la memoria dinamica, es un contructor sin parametros.
 *
 * @return Retorna el puntero del empleado asignado en la memoria.
 */
Employee* employee_new();
/**
 * @fn Employee employee_newParametros*(char*, char*, char*, char*)
 * @brief Esta funcion: Se encarga de agregar un nuevo empleado y guardarlo en
 * la memoria dinamica, es un contructor con parametros.
 *
 * @param idStr: En este apartado se le asigna la Id del empleado en forma de array de chars
 * y la transformas mediante la funcion atoi.
 * @param nombreStr: En este apartado se le asigna el Nombre del empleado en forma de array de chars
 * y la transformas mediante la funcion atoi.
 * @param horasTrabajadasStr: En este apartado se le asigna las horas trabajadas del empleado en forma de array de chars
 * y la tranformas mediante la funcion atoi.
 * @param sueldoStr: En este apartado se le asigna el sueldo del empleado en forma de array de chars
 * y la tranformas mediante la funcion atoi.
 *
 * @return Retorna el puntero del empleado asignado en la memoria.
 */
Employee* employee_newParametros(char* idStr, char* nombreStr, char* horasTrabajadasStr, char* sueldoStr);
/**
 * @fn void employee_delete(Employee*)
 * @brief Esta funcion: Se encarga de eliminar a un	empleado en la memoria dinamica.
 *
 *
 * @param this: Es el empleado a eliminar.
 */
void employee_delete();
/**
 * @fn int employee_setId(Employee*, int)
 * @brief Esta funcion: Se encarga de colocar el Id del empleado en la lista general.
 *
 * @param this: Esta es  la lista.
 * @param id: El id a colocar en la lista.
 * @return Retorna 1 o 0: 1 si se puedo cargar o 0 si no se pudo cargar.
 */
int employee_setId(Employee* this,int id);
/**
 * @fn int employee_getId(Employee*, int)
 * @brief Esta funcion: Se encarga de obtener el Id del empleado en la lista general.
 *
 * @param this: Esta es  la lista.
 * @param id: El id a obtener en la lista.
 * @return Retorna 1 o 0: 1 si se puedo cargar o 0 si no se pudo cargar.
 */
int employee_getId(Employee* this,int* id);
/**
 * @fn int employee_setNombre(Employee*, char*)
 * @brief Esta funcion: Se encarga de colocar el nombre del empleado en la lista general.
 *
 * @param this: Esta es la lista.
 * @param nombre: El nombre a colocar en la lista.
 * @return Retorna 1 o 0: 1 si se puedo cargar o 0 si no se pudo cargar.
 */
int employee_setNombre(Employee* this,char* nombre);
/**
 * @fn int employee_getNombre(Employee*, char*)
 * @brief Esta funcion: Se encarga de obtener el nombre del empleado en la lista general.
 *
 * @param this: Esta es la lista.
 * @param nombre: El nombre a obtener en la lista.
 * @return Retorna 1 o 0: 1 si se puedo cargar o 0 si no se pudo cargar.
 */
int employee_getNombre(Employee* this,char* nombre);
/**
 * @fn int employee_setHorasTrabajadas(Employee*, int)
 * @brief Esta funcion: Se encarga de colocar las horas trabajadas del empleado en la lista general.
 *
 * @param this: Esta es la lista.
 * @param horasTrabajadas: Las horas trabajadas a colocar en la lista.
 * @return Retorna 1 o -1: 1 si se puedo cargar o -1 si no se pudo cargar.
 */
int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);
/**
 * @fn int employee_getHorasTrabajadas(Employee*, int*)
 * @brief Esta funcion: Se encarga de obtener las horas trabajadas del empleado en la lista general.
 *
 * @param this: Esta es la lista.
 * @param horasTrabajadas: Las horas trabajadas a obtener en la lista.
 * @return Retorna 1 o -1: 1 si se puedo cargar o -1 si no se pudo cargar.
 */
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);
/**
 * @fn int employee_setSueldo(Employee*, int)
 * @brief Esta funcion: Se encarga de colocar el sueldo del empleado en la lista general.
 *
 * @param this: Esta es la lista.
 * @param sueldo: El sueldo a colocar en la lista.
 * @return Retorna 1 o 0: 1 si se puedo cargar o 0 si no se pudo cargar.
 */
int employee_setSueldo(Employee* this,int sueldo);
/**
 * @fn int employee_getSueldo(Employee*, int*)
 * @brief Esta funcion: Se encarga de obtener el sueldo del empleado en la lista general.
 *
 * @param this: Esta es la lista.
 * @param sueldo: El sueldo a obtener en la lista.
 * @return Retorna 1 o 0: 1 si se puedo cargar o 0 si no se pudo cargar.
 */
int employee_getSueldo(Employee* this,int* sueldo);
/**
 * @fn void employee_printData(Employee*)
 * @brief Esta funcion: Se encarga de mostrar los datos de un empleado.
 *
 * @param this: El empleado a mostrar los datos.
 */
void employee_printData(Employee* this);
/**
 * @fn int employee_ordenarPorNombre(void*, void*)
 * @brief Esta funciones obtiene 2 direcciones de memoria y los compara
 * devuelve 2 tipos de ordenamiento por nombre.
 *
 * @param punteroUno: El puntero que apunta a la direccion de memomoria del 1er direccion.
 * @param punteroDos: El puntero que apunta a la direccion de memomoria del 2da direccion.
 *
 * @return retorna: -2 si algun puntero es NULL, 0 si son iguales los nombres, -1 si el el segundo es mayor. 1 si el primero es mayor
 */
int employee_ordenarPorNombre(void* punteroUno, void* punteroDos);
/**
 * @fn int employee_ordenarPorHoras(void*, void*)
 * @brief Esta funciones obtiene 2 direcciones de memoria y los compara
 * devuelve 2 tipos de ordenamiento por horas trabajadas.
 *
 * @param punteroUno: El puntero que apunta a la direccion de memomoria del 1er direccion.
 * @param punteroDos: El puntero que apunta a la direccion de memomoria del 2da direccion.
 *
 * @return Esta funcion retorna 1 si la la variable que fue asiganada "horasUno" es mayor a "horasDos" o -1 si la la variable que fue asiganada "horasUno" es menor a "horasDos"
 */
int employee_ordenarPorHoras(void* punteroUno, void* punteroDos);
/**
 * @fn int employee_ordenarPorId(void*, void*)
 * @brief Esta funciones obtiene 2 direcciones de memoria y los compara
 * devuelve 2 tipos de ordenamiento por id.
 *
 * @param punteroUno: El puntero que apunta a la direccion de memomoria del 1er direccion.
 * @param punteroDos: El puntero que apunta a la direccion de memomoria del 2da direccion.
 *
 * @return Esta funcion retorna 1 si la la variable que fue asiganada "IdUno" es mayor a "IdDos" o -1 si la la variable que fue asiganada "IdUno" es menor a "IdDos"
 */
int employee_ordenarPorId(void* punteroUno, void* punteroDos);
/**
 * @fn int employee_ordenarSueldo(void*, void*)
 * @brief Esta funciones obtiene 2 direcciones de memoria y los compara
 * devuelve 2 tipos de ordenamiento por Sueldo.
 *
 * @param punteroUno: El puntero que apunta a la direccion de memomoria del 1er direccion.
 * @param punteroDos: El puntero que apunta a la direccion de memomoria del 2da direccion.
 *
 * @return Esta funcion retorna 1 si la la variable que fue asiganada "ueldoUno" es mayor a "sueldoDos" o -1 si la la variable que fue asiganada "sueldoUno" es menor a "sueldoDos"
 */
int employee_ordenarSueldo(void* punteroUno, void* punteroDos);
#endif // employee_H_INCLUDED
