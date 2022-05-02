#ifndef ARRAYPASSENGER_H_INCLUDED
#define ARRAYPASSENGER_H_INCLUDED

typedef struct
{

   int id;
   char name[51];
   char lastName[51];
   float price;
   char flyCode[10];
   int typePassenger;
   int statusFlight;
   int isEmpty;

} ePassenger;

#endif // ARRAYPASSENGER_H_INCLUDED
/**
 * @fn int idController(ePassenger*, int, int)
 * @brief This function find the max id in the list. Return the max id  plus 1.
 *
 * @param list: Array passenger.
 * @param len: size array.
 * @param id Passenger.
 * @return Return (-1) if Error or Id max+1.
 */
int idController(ePassenger* list, int len, int id);
/** \brief To indicate that all position in the array are empty, this function put the flag (isEmpty) in TRUE in all position of the array.
*
* \param list Passenger* Pointer to array of passenger.
* \param len int Array length.
* \return todoOk: Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int initPassengers(ePassenger* list, int len);
/** \brief find a Passenger by Id en returns the index position in array.
*
* \param list Passenger*: Array passenger.
* \param len: size array.
* \param id: Passenger Income Number.
* \return Return passenger index position or (-1) if [Invalid length or NULL pointer received or passenger not found]
*
*/
int findPassengerById(ePassenger* list, int len, int id);
/** \brief add in a existing list of passengers the values received as parameters in the first empty position.
*
* \param list passenger*: Array passenger.
* \param len: size array.
* \param id: Passenger Income Number.
* \param name: Name of employee.
* \param lastName: Last name of employee.
* \param price: fly price.
* \param typePassenger: (1-PRIMERA CLASE, 2-COMERCIAL, 3-TURISTA).
* \param flycode: code fly.
* \return todoOk: Return (-1) if Error [Invalid length or NULL pointer or without free space] - (0) if Ok.
*/
int addPassenger(ePassenger* list, int len, int id, char name[],char lastName[],float price, char flyCode[],int typePassenger, int statusFlight);
/**
 * @fn int seachPassenger(ePassenger*, int)
 * @brief This function goes through the "passenger list" to search for the first free space in a for loop.
 *
 * @param list: Array passenger.
 * @param len: size array.
 * @return todoOk:(-1) if Error [Invalid length or NULL pointer or without free space] - (0) if Ok.
 */
int seachPassenger(ePassenger* list, int len);
/**
 * @fn void printPassenger(ePassenger)
 * @brief This function: Displays the data of a passenger id, name, flycode, etc...
 *
 * @param auxPassenger: receives the data of this passenger´s income.
 */
void printPassenger(ePassenger auxPassenger);
/**
 * @fn int printListPassenger(ePassenger*, int)
 * @brief This function: Prints the list of all the passengers entered with their data, id ,name, flycode,
 * etc..
 *
 * @param list: Array passenger.
 * @param len: size array.
 * @return todoOk: 1 or -1: "1" if it could perform the function or "-1" if it could not perform the function.
 */
int printListPassenger(ePassenger* list, int len);
/** \brief Remove a Passenger by Id (put isEmpty Flag in 1).
* This function deletes an already entered Passenger, asks for the id to delete and deletes it,
* deleting that Passenger.
*
* \param list Passenger*: Array passenger.
* \param len: size array.
* \param id: Passenger's login number.
* \return todoOk: Return (-1) if Error [Invalid length or NULL pointer or if can't find a passenger] - (0) if Ok.
*
*/
int removePassenger(ePassenger* list, int len, int id);
/**
 * @fn int modifyPassenger(ePassenger*, int)
 * @brief This function allows you to modify the entered data of a passenger, allowing you to choose which field to modify with a sudmenu.
 *
 * @param list: Array passenger.
 * @param len: size array.
 * @return todoOk: Return (-1) if Error [Invalid length or NULL pointer or if can't find a passenger] - (0) if Ok.
 */
int modifyPassenger(ePassenger* list, int len);
/**
 * @fn int pedirListado(int*)
 * @brief this function allows you to choose a field for a menu.
 *
 * @param campo: field to choose.
 * @return todoOk: Return (-1) if Error [Invalid length or NULL pointer or if can't find a passenger] - (0) if Ok.
 */
int pedirListado(int* campo);
/**
 * @fn int mostrarListadoInforme(ePassenger*, int, int)
 * @brief This function in your reports menu equipped with the 4 options: list, averages, total collected, etc...
 *
 * @param list: Array passenger.
 * @param len: size array.
 * @param campo: field to choose.
 * @return todoOk: Return (-1) if Error [Invalid length or NULL pointer or if can't find a passenger] - (0) if Ok.
 */
int mostrarListadoInforme(ePassenger* list, int len, int campo);

//Informs
/**
 * @fn int ordenamientoPorApellidoTipoPasajero(ePassenger*, int)
 * @brief This function sorts the list of passengers by last name by double criteria, but if the last names coincide,
 * this will sort it by passenger type.
 *
 * @param list: Array passenger.
 * @param len: size array.
 * @return todoOk: Return (-1) if Error [Invalid length or NULL pointer or if can't find a passenger] - (0) if Ok.
 */
int ordenamientoPorApellidoTipoPasajero(ePassenger* list, int len);
/**
 * @fn int ordenamientoCodigoVueloEstadoActivo(ePassenger*, int)
 * @brief This function double-orders the list of passengers by "active" flight status and by flight code.
 *
 * @param list: Array passenger.
 * @param len: size array.
 * @return todoOk: Return (-1) if Error [Invalid length or NULL pointer or if can't find a passenger] - (0) if Ok.
 */
int ordenamientoCodigoVueloEstadoActivo(ePassenger* list, int len);
/**
 * @fn int totalYpromedioPrecioPasajes(ePassenger*, int, float*, int*, float*)
 * @brief This function calculates the average of the prices of the flights entered by the passengers.
 *
 * @param list: Array passenger.
 * @param len: size array.
 * @param acumuladorPrecioPasajes: It is the sum of the prices entered.
 * @param cantidadPasajes: It is the number of passengers who entered a price.
 * @param promedioPrecioPasajes: It is the average of the flights. That is, the amount of price entered,
 * I divide the number of people who enter a price.
 * @return todoOk: Return (-1) if Error [Invalid length or NULL pointer or if can't find a passenger] - (0) if Ok.
 */
int promedioPrecioPasajes(ePassenger* list, int len, float* acumuladorPrecioPasajes, int* cantidadPasajes, float* promedioPrecioPasajes);
/**
 * @fn int cantidadPasajerosConGastosSuperiorA(ePassenger*, int, int*, float)
 * @brief This function allows you to count the number of people who exceed a specific price in a list.
 *
 * @param list: Array passenger.
 * @param len: size array.
 * @param contadorPasajeros: Number of passengers who exceed a price set by parameter.
 * @param valor: The price that is set per parameter to calculate the quantity that exceeds it
 * @return todoOk: Return (-1) if Error [Invalid length or NULL pointer or if can't find a passenger] - (0) if Ok.
 */
int cantidadPasajerosConGastosSuperiorA(ePassenger* list, int len, int* contadorPasajeros, float valor);


