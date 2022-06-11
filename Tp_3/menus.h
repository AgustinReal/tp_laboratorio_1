/*
 * menus.h
 *
 *  Created on: 7 jun. 2022
 *      Author: Usuario
 */

#ifndef MENUS_H_
#define MENUS_H_





#endif /* MENUS_H_ */
/**
 * @fn int menuPrincipal()
 * @brief Esta funcion es el menu principal del main  utn travel.
 *
 * @return Retrona la opcion elegida por el usuario.
 */
int menuPrincipal();

/**
 * @fn int menuModificaciones()
 * @brief Esta funcion es el menu de modificaciones del controller_editPassenger utn travel.
 *
 * @return Retrona la opcion elegida por el usuario.
 */
int menuModificaciones();

/**
 * @fn int menuPrincipalOrdenamiento()
 * @brief Esta funcion es el menu de ordenamiento del controller_sortPassenger utn travel.
 *
 * @return Retrona la opcion elegida por el usuario.
 */
int menuPrincipalOrdenamiento();

/**
 * @fn int menuCriterioOrdenamiento(int*)
 * @brief Esta funcion es el tipo de ordenamiento del controller_sortPassenger utn travel.
 *
 * @param tipo es 1 0 2 segun lo q eliga el usuario.
 * @return Retrona la opcion elegida por el usuario.
 */
int menuCriterioOrdenamiento(int* tipo);
