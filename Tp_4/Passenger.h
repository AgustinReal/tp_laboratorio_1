#ifndef PASSENGER_H_INCLUDED
typedef struct
{
	int id;
	char nombre[50];
	char apellido[50];
	float precio;
	char codigoVuelo[10];
	int tipoPasajero;
	int estadoVuelo;

}Passenger;
#define PASSENGER_H_INCLUDED



#endif // PASSENGER_H_INCLUDED

/**
 * @fn Passenger Passenger_new*()
 * @brief Esta funcion: Se encarga de agregar un nuevo pasajero y guardarlo en
 * la memoria dinamica, es un contructor sin parametros.
 *
 * @return Retorna el puntero del empleado asignado en la memoria.
 */
Passenger* Passenger_new();

/**
 * @fn Passenger Passenger_newParametros*(char*, char*, char*, char*, char*, char*, char*)
 * @brief Esta funcion: Se encarga de agregar un nuevo pasajero y guardarlo en
 * la memoria dinamica, es un contructor con parametros.
 *
 * @param idStr: En este apartado se le asigna la Id del pasajero en forma de array de chars
 * y la transformas mediante la funcion atoi.
 * @param nombreStr: En este apartado se le asigna el Nombre del pasajero.
 * @param apellidoStr: En este apartado se le asigna el Apellido del pasajero.
 * @param precioStrn: En este apartado se le asigna el precio del pasajero en forma de array de chars
 * y la tranformas mediante la funcion atoi.
 * @param codigoVueloStr: En este apartado se le asigna el codigo de vuelo del pasajero.
 * @param tipoPasajeroStr: En este apartado se le asigna el tipo de pasajero del pasajero.
 * @param estadoVueloStr: En este apartado se le asigna el estado de vuelo del pasajero.
 * @return Retorna el puntero del empleado asignado en la memoria.
 */
Passenger* Passenger_newParametros(char* idStr, char* nombreStr, char* apellidoStr, char* precioStr,  char* codigoVueloStr, char* tipoPasajeroStr, char* estadoVueloStr);

/**
 * @fn void Passenger_delete(Passenger*)
 * @brief Esta funcion: Se encarga de eliminar a un	pasajero de la lista y liberar la memoria dinamica que se uso para ese pasajero.
 *
 * @param this: Es el pasajero a eliminar.
 */
void Passenger_delete(Passenger* this);

/**
 * @fn int Passenger_setId(Passenger*, int)
 * @brief Esta funcion: Se encarga de obtener el Id del pasajero en la lista general.
 *
 * @param this: Este es un elemento a buscar en la lista.
 * @param id: El id a obtener en la lista.
 *
 * @return Retorna 1 o 0: 1 si se puedo cargar o 0 si no se pudo cargar.
 */
int Passenger_setId(Passenger* this, int id);

/**
 * @fn int Passenger_getId(Passenger*, int*)
 * @brief Esta funcion: Se encarga de colocar el nombre del pasajero en la lista general.
 *
 * @param this: Esta es la lista.
 * @param id: El id a obtener en la lista.
 *
 * @return Retorna 1 o 0: 1 si se puedo cargar o 0 si no se pudo cargar.
 */
int Passenger_getId(Passenger* this, int* id);

/**
 * @fn int Passenger_setNombre(Passenger*, char*)
 * @brief Esta funcion: Se encarga de colocar el nombre del pasajero en la lista general.
 *
 * @param this: Este es un elemento a buscar en la lista.
 * @param nombre: El nombre a colocar en la lista.
 * @return Retorna 1 o 0: 1 si se puedo cargar o 0 si no se pudo cargar.
 */
int Passenger_setNombre(Passenger* this, char* nombre);

/**
 * @fn int Passenger_getNombre(Passenger*, char*)
 * @brief Esta funcion: Se encarga de obtener el nombre del pasajero en la lista general.
 *
 * @param this: Este es un elemento a buscar en la lista.
 * @param nombre: El nombre a obtener en la lista.
 * @return Retorna 1 o 0: 1 si se puedo cargar o 0 si no se pudo cargar.
 */
int Passenger_getNombre(Passenger* this, char* nombre);

/**
 * @fn int Passenger_setApellido(Passenger*, char*)
 * @brief  Esta funcion: Se encarga de colocar el apellido del pasajero en la lista general.
 *
 * @param this: Este es un elemento a buscar en la lista.
 * @param apellido: El apellido a obtener en la lista.
 * @return Retorna 1 o 0: 1 si se puedo cargar o 0 si no se pudo cargar.
 */
int Passenger_setApellido(Passenger* this, char* apellido);

/**
 * @fn int Passenger_getApellido(Passenger*, char*)
 * @brief Esta funcion: Se encarga de obtener el apellido del pasajero en la lista general.
 *
 * @param this: Este es un elemento a buscar en la lista.
 * @param apellido: El apellido a obtener en la lista.
 * @return Retorna 1 o 0: 1 si se puedo cargar o 0 si no se pudo cargar.
 */
int Passenger_getApellido(Passenger* this, char* apellido);

/**
 * @fn int Passenger_setPrecio(Passenger*, float)
 * @brief Esta funcion: Se encarga de colocar el precio del pasajero en la lista general.
 *
 * @param this: Este es un elemento a buscar en la lista.
 * @param precio: El precio a colocar en la lista.
 * @return Retorna 1 o 0: 1 si se puedo cargar o 0 si no se pudo cargar.
 */
int Passenger_setPrecio(Passenger* this, float precio);

/**
 * @fn int Passenger_getPrecio(Passenger*, float*)
 * @brief Esta funcion: Se encarga de obtener el precio del pasajero en la lista general.
 *
 * @param this: Este es un elemento a buscar en la lista.
 * @param precio: El precio a obtener en la lista.
 * @return Retorna 1 o 0: 1 si se puedo cargar o 0 si no se pudo cargar.
 */
int Passenger_getPrecio(Passenger* this, float* precio);

/**
 * @fn int Passenger_setCodigoVuelo(Passenger*, char*)
 * @brief Esta funcion: Se encarga de colocar el codigo de vuelo del pasajero en la lista general.
 *
 * @param this: Este es un elemento a buscar en la lista.
 * @param codigoVuelo: El codigo de vuelo a colocar en la lista.
 * @return Retorna 1 o 0: 1 si se puedo cargar o 0 si no se pudo cargar.
 */
int Passenger_setCodigoVuelo(Passenger* this, char* codigoVuelo);

/**
 * @fn int Passenger_getCodigoVuelo(Passenger*, char*)
 * @brief Esta funcion: Se encarga de obtener el codigo de vuelo del pasajero en la lista general.
 *
 * @param this: Este es un elemento a buscar en la lista.
 * @param codigoVuelo: El codigo de vuelo a obtener en la lista.
 * @return Retorna 1 o 0: 1 si se puedo cargar o 0 si no se pudo cargar.
 */
int Passenger_getCodigoVuelo(Passenger* this, char* codigoVuelo);

/**
 * @fn int Passenger_setTipoPasajero(Passenger*, int)
 * @brief Esta funcion: Se encarga de colocar el tipo de pasajero del pasajero en la lista general.
 *
 * @param this: Este es un elemento a buscar en la lista.
 * @param tipoPasajero: El tipo de pasajero a colocar en la lista.
 * @return Retorna 1 o 0: 1 si se puedo cargar o 0 si no se pudo cargar.
 */
int Passenger_setTipoPasajero(Passenger* this, int tipoPasajero);

/**
 * @fn int Passenger_getTipoPasajero(Passenger*, int*)
 * @brief Esta funcion: Se encarga de obtener el tipo de pasajero del pasajero en la lista general.
 *
 * @param this: Este es un elemento a buscar en la lista.
 * @param tipoPasajero: El tipo de pasajero a obtener en la lista.
 * @return Retorna 1 o 0: 1 si se puedo cargar o 0 si no se pudo cargar.
 */
int Passenger_getTipoPasajero(Passenger* this, int* tipoPasajero);

/**
 * @fn int Passenger_getdescripcionTipoPasajero(int, char*)
 * @brief Esta funcion: Se encarga de leer un tipo de dato entero y se transforma en un array de char.
 *
 * @param tipoPasajero: El numero o valor que se va a transformar a cadena.
 * @param descripcionTipo: Es donde se va poner la cadena dependiendo del int que leyo en lista.
 * @return Retorna 1 o 0: 1 si se puedo cargar o 0 si no se pudo cargar.
 */
int Passenger_getdescripcionTipoPasajero(int tipoPasajero , char* descripcionTipo);

/**
 * @fn int Passenger_setEstadoVuelo(Passenger*, int)
 * @brief Esta funcion: Se encarga de colocar el estado de vuelo  del pasajero en la lista general.
 *
 * @param this: El estado de vuelo a colocar en la lista.
 * @param estadoVuelo: El estado de vuelo a colocar en la lista.
 * @return Retorna 1 o 0: 1 si se puedo cargar o 0 si no se pudo cargar.
 */
int Passenger_setEstadoVuelo(Passenger* this, int estadoVuelo);

/**
 * @fn int Passenger_getEstadoVuelo(Passenger*, int*)
 * @brief Esta funcion: Se encarga de obtener el estado de vuelo  del pasajero en la lista general.
 *
 * @param this: El estado de vuelo a obtener en la lista.
 * @param estadoVuelo: El estado de vuelo a colocar en la lista.
 * @return Retorna 1 o 0: 1 si se puedo cargar o 0 si no se pudo cargar.
 */
int Passenger_getEstadoVuelo(Passenger* this, int* estadoVuelo);

/**
 * @fn int Passenger_getdescripcionEstadoVuelo(int, char*)
 * @brief Esta funcion: Se encarga de leer un tipo de dato entero y se transforma en un array de char.
 *
 * @param estadoVuelo: El numero o valor que se va a transformar a cadena.
 * @param descripcionEstadoVuelo: Es donde se va poner la cadena dependiendo del int que leyo en lista.
 * @return Retorna 1 o 0: 1 si se puedo cargar o 0 si no se pudo cargar.
 */
int Passenger_getdescripcionEstadoVuelo(int estadoVuelo , char* descripcionEstadoVuelo);

/**
 * @fn void Passenger_mostrarUnPasajero(Passenger*)
 * @brief Esta funcio: Se encarga de moestrar un pasajero pasado por parametro.
 *
 * @param pasajero: El pasajero a mostrar.
 */
void Passenger_mostrarUnPasajero(Passenger* pasajero);

/**
 * @fn Passenger Passenger_altaPasajero*()
 * @brief Esta funcion carga los datos de un pasajero nombre, apellido, etc...
 *
 * @return Esto retorna un pasajero con datos cargados.
 */
Passenger* Passenger_altaPasajero();

//ordenamientos
/**
 * @fn int Passenger_ordenarPorId(void*, void*)
 * @brief Esta funciones obtiene 2 direcciones de memoria y los compara
 * devuelve 2 tipos de ordenamiento por id.
 *
 * @param punteroUno: El puntero que apunta a la direccion de memomoria del 1er direccion.
 * @param punteroDos: El puntero que apunta a la direccion de memomoria del 2da direccion.
 * @return Esta funcion retorna 1 si la la variable que fue asiganada "IdUno" es mayor a "IdDos" o -1 si la la variable que fue asiganada "IdUno" es menor a "IdDos"
 */
int Passenger_ordenarPorId(void* punteroUno, void* punteroDos);

/**
 * @fn int Passenger_ordenarPorNombre(void*, void*)
 * @brief Esta funciones obtiene 2 direcciones de memoria y los compara
 * devuelve 2 tipos de ordenamiento por nombre.
 *
 * @param punteroUno: El puntero que apunta a la direccion de memomoria del 1er direccion.
 * @param punteroDos: El puntero que apunta a la direccion de memomoria del 2da direccion.
 * @return retorna: -2 si algun puntero es NULL, 0 si son iguales los nombres, -1 si el el segundo es mayor. 1 si el primero es mayor
 */
int Passenger_ordenarPorNombre(void* punteroUno, void* punteroDos);

/**
 * @fn int Passenger_ordenarPorApellido(void*, void*)
 * @brief Esta funciones obtiene 2 direcciones de memoria y los compara
 * devuelve 2 tipos de ordenamiento por apellido.
 *
 * @param punteroUno: El puntero que apunta a la direccion de memomoria del 1er direccion.
 * @param punteroDos: El puntero que apunta a la direccion de memomoria del 2da direccion.
 * @return retorna: -2 si algun puntero es NULL, 0 si son iguales los apellidos, -1 si el el segundo es mayor. 1 si el primero es mayor
 */
int Passenger_ordenarPorApellido(void* punteroUno, void* punteroDos);

/**
 * @fn int Passenger_ordenarPorPrecio(void*, void*)
 * @brief Esta funciones obtiene 2 direcciones de memoria y los compara
 * devuelve 2 tipos de ordenamiento por preio.
 *
 * @param punteroUno: El puntero que apunta a la direccion de memomoria del 1er direccion.
 * @param punteroDos: El puntero que apunta a la direccion de memomoria del 2da direccion.
 * @return Esta funcion retorna 1 si la la variable que fue asiganada "precioUno" es mayor a "precioDos" o -1 si la la variable que fue asiganada "precioUno" es menor a "precioDos"
 */
int Passenger_ordenarPorPrecio(void* punteroUno, void* punteroDos);

/**
 * @fn int Passenger_ordenarPorCodigoDeVuelo(void*, void*)
 * @brief Esta funciones obtiene 2 direcciones de memoria y los compara
 * devuelve 2 tipos de ordenamiento por codigos de vuelos.
 *
 * @param punteroUno: El puntero que apunta a la direccion de memomoria del 1er direccion.
 * @param punteroDos: El puntero que apunta a la direccion de memomoria del 2da direccion.
 * @return retorna: -2 si algun puntero es NULL, 0 si son iguales los codigos de vuelos, -1 si el el segundo es mayor. 1 si el primero es mayor
 */
int Passenger_ordenarPorCodigoDeVuelo(void* punteroUno, void* punteroDos);

/**
 * @fn int Passenger_ordenarPorTipoPasajero(void*, void*)
 * @brief Esta funciones obtiene 2 direcciones de memoria y los compara
 * devuelve 2 tipos de ordenamiento por tipo pasajero.
 *
 * @param punteroUno: El puntero que apunta a la direccion de memomoria del 1er direccion.
 * @param punteroDos: El puntero que apunta a la direccion de memomoria del 2da direccion.
 * @return retorna: -2 si algun puntero es NULL, 0 si son iguales los tipos pasajeros, -1 si el el segundo es mayor. 1 si el primero es mayor
 */
int Passenger_ordenarPorTipoPasajero(void* punteroUno, void* punteroDos);

/**
 * @fn int Passenger_ordenarPorEstadoVuelo(void*, void*)
 * @brief Esta funciones obtiene 2 direcciones de memoria y los compara
 * devuelve 2 tipos de ordenamiento por estados de vuelos.
 *
 * @param punteroUno: El puntero que apunta a la direccion de memomoria del 1er direccion.
 * @param punteroDos: El puntero que apunta a la direccion de memomoria del 2da direccion.
 * @return retorna: -2 si algun puntero es NULL, 0 si son iguales los estados de vuelos, -1 si el el segundo es mayor. 1 si el primero es mayor
 */
int Passenger_ordenarPorEstadoVuelo(void* punteroUno, void* punteroDos);
//Ids
/**
 * @fn int Passenger_actualizarUltimoId(int)
 * @brief Esta funcion guarda el ultimo id ingresado en la lista en un archivo texto.
 *
 * @param idViejo: ultimo id.
 * @return Retorna 1 o 0: 1 si se puedo cargar o 0 si no se pudo cargar.
 */
int Passenger_actualizarUltimoId(int idViejo);
