#ifndef CONTROLLER_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "parser.h"
#define CONTROLLER_H_INCLUDED



#endif // CONTROLLER_H_INCLUDED

/**
 * @fn int controller_loadFromText(char*, LinkedList*)
 * @brief Carga los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * @param path: Es el camino que esta asignado el archivo en este caso en modo texto.
 * @param pArrayListPassenger: Lista de los pasajeros.
 * @return Esta funcion retorna: 1 o -1: 1 si la funcion se pudo realizar o -1 si la funcion no se lo logro realizar.
 */
int controller_loadFromText(char* path , LinkedList* pArrayListPassenger);

/**
 * @fn int controller_loadFromBinary(char*, LinkedList*)
 * @brief Carga los datos de los pasajeros desde el archivo data.csv (modo binario).
 *
 * @param path: Es el camino que esta asignado el archivo en este caso en modo binaria.
 * @param pArrayListPassenger: Lista de los pasajeros.
 * @return Esta funcion retorna: 1 o -1: 1 si la funcion se pudo realizar o -1 si la funcion no se lo logro realizar.
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListPassenger);

/**
 * @fn int controller_addPassenger(LinkedList*)
 * @brief Esta funcion realiza un Alta de pasajero, es decir agrega un pasajero a la lista buscando el ultimo espacio libre
 * y lo guarga con sus datos.
 *
 * @param pArrayListPassenger: Lista de los empleados.
 * @return Esta funcion retorna: 1 o -1: 1 si la funcion se pudo realizar o -1 si la funcion no se lo logro realizar.
 */
int controller_addPassenger(LinkedList* pArrayListPassenger);

/**
 * @fn int controller_editPassenger(LinkedList*)
 * @brief Esta funcion permite modificar los datos de un pasajero agregado en la lista.
 * Se busca por el id del pasajero mediante la funcion controller_buscarIdPasajero y lo encuentra se le podra modificar o no.
 *
 * @param pArrayListPassenger: Lista de los empleados.
 * @return Esta funcion retorna: 1 o -1: 1 si la funcion se pudo realizar o -1 si la funcion no se lo logro realizar.
 */
int controller_editPassenger(LinkedList* pArrayListPassenger);

/**
 * @fn int controller_removePassenger(LinkedList*)
 * @brief Esta funcion permite eliminar los datos de un pasajero agregado en la lista.
 * Se busca por el id del pasajero mediante la funcion controller_buscarIdPasajero y lo encuentra se le podra eliminar o no.
 *
 * @param pArrayListPassenger: Lista de los empleados.
 * @return Esta funcion retorna: 1 o -1: 1 si la funcion se pudo realizar o -1 si la funcion no se lo logro realizar.
 */
int controller_removePassenger(LinkedList* pArrayListPassenger);

/**
 * @fn int controller_ListPassenger(LinkedList*)
 * @brief Esta funcion permite mostrar las lista de los pasajeros cargados.
 *
 * @param pArrayListPassenger: Lista de los empleados.
 * @return Esta funcion retorna: 1 o -1: 1 si la funcion se pudo realizar o -1 si la funcion no se lo logro realizar.
 */
int controller_ListPassenger(LinkedList* pArrayListPassenger);

/**
 * @fn int controller_sortPassenger(LinkedList*)
 * @brief Esta funcion permite ordenar los pasajeros de 7 formas mediante un sud menu, y de 2 tipos
 * de las siguientes formas ascedente o descendente el tipo de id o apellido o nombre o precio, etc.
 *
 * @param pArrayListPassenger: Lista de los empleados.
 * @return Esta funcion retorna: 1 o -1: 1 si la funcion se pudo realizar o -1 si la funcion no se lo logro realizar.
 */
int controller_sortPassenger(LinkedList* pArrayListPassenger);

/**
 * @fn int controller_saveAsText(char*, LinkedList*)
 * @brief Esta funcion Guarda los datos de los pasajeros en el archivo data.csv (modo texto).
 *
 * @param path: Es el camino que esta asignado el archivo en este caso en modo texto.
 * @param pArrayListEmployee: Lista de los pasajeros.
 * @return Esta funcion retorna: 1 o -1: 1 si la funcion se pudo realizar o -1 si la funcion no se lo logro realizar.
 */
int controller_saveAsText(char* path , LinkedList* pArrayListPassenger);

/**
 * @fn int controller_saveAsBinary(char*, LinkedList*)
 * @brief Esta funcion Guarda los datos de los empleados en el archivo dataBinaria.bin (modo binario).
 *
 * @param path: Es el camino que esta asignado el archivo en este caso en modo binario.
 * @param pArrayListEmployee: Lista de los pasajeros.
 * @return Esta funcion retorna: 1 o -1: 1 si la funcion se pudo realizar o -1 si la funcion no se lo logro realizar.
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListPassenger);

/**
 * @fn int controller_getUltimoId()
 * @brief Esta funcion crea un archivo de texto y guarda el ultimo id encontrado en la lista de pasajeros.
 *
 * @return  retorna el ultimo id encontrado el lista de pasajeros.
 */
int controller_getUltimoId();

/**
 * @fn int controller_buscarIdPasajero(LinkedList*, int)
 * @brief Esta funcion se encarga de encontrar la index de donde se encuentra un Id pasado por parametro.
 *
 * @param pArrayListPassenger: Lista de los pasajeros.
 * @param idPasajero: Es el id a comparar mediante la funcion ll_get().
 * @return retorna el index de la posicion encontrada pasada por parametro o si no la encontro un -1.
 */
int controller_buscarIdPasajero(LinkedList* pArrayListPassenger, int idPasajero);

//Nota: mil disculpas por los comentarios.
//informes
/** \brief Esta funcion crea una sud lista, le da la opcion al usuario de donde empieza y donde terminara la lista.
 *
 * \param pArrayListPassenger LinkedList*: Lista de los pasajeros.
 * \return Esta funcion retorna: 0 o -1: 0 si la funcion se pudo realizar o -1 si la funcion no se lo logro realizar.
 *
 */
int controller_InformeSudListadoPorRangoSelecionado(LinkedList* pArrayListPassenger);

/** \brief Esta funcion Imprime una lista de pasajeros pero para un informe para ponerle un titulo diferente hace lo mismo
 *  que la funcion controller_ListPassenger.
 *
 * \param pArrayListPassenger LinkedList*: Lista de los pasajeros.
 * \return int: Esta funcion retorna: 0 o -1: 0 si la funcion se pudo realizar o -1 si la funcion no se lo logro realizar.
 *
 */
int controller_ListPassengerInforme(LinkedList* pArrayListPassenger);

/** \brief Esta funcion busca el menor precio de los vuelos y elimina el pasajero con menor precio de la lista.
 *
 * \param pArrayListPassenger LinkedList*: Lista de los pasajeros.
 * \return int: Esta funcion retorna: 0 o -1: 0 si la funcion se pudo realizar o -1 si la funcion no se lo logro realizar.
 *
 */
int controller_InformeEliminarPasajeroMenorPrecio(LinkedList* pArrayListPassenger);

/** \brief Esta funcion da de alta un pasajero pero en una posicion selecionada por el usuario.
 *
 * \param pArrayListPassenger LinkedList*: Lista de los pasajeros.
 * \return int: Esta funcion retorna: 0 o -1: 0 si la funcion se pudo realizar o -1 si la funcion no se lo logro realizar.
 *
 */
int controller_InformeAltaEnPosicionSelecionada(LinkedList* pArrayListPassenger);

/** \brief Esta funcion es un switch con todos los informes creados para el likedList
 *
 * \param pArrayListPassenger LinkedList*: Lista de los pasajeros.
 * \return int: Esta funcion retorna: 0 o -1: 0 si la funcion se pudo realizar o -1 si la funcion no se lo logro realizar.
 *
 */
int controller_Informes(LinkedList* pArrayListPassenger);
