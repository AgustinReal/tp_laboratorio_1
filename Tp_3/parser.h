
/**
 * @fn int parser_PassengerFromText(FILE*, LinkedList*)
 * @brief Esta funcion parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * @param pFile: Es el archivo a parsear en este caso modo texto.
 * @param pArrayListEmployee: La lista de empleados.
 * @return Retorna 1 o 0: 1 si se puedo parsear o 0 si no se pudo parsear.
 */
int parser_PassengerFromText(FILE* pFile , LinkedList* pArrayListPassenger);

/**
 * @fn int parser_PassengerFromBinary(FILE*, LinkedList*)
 * @brief  Esta funcion parsea los datos de los pasajeros desde el archivo data.csv (modo binario).
 *
 * @param pFile: Es el archivo a parsear en este caso modo binario.
 * @param pArrayListEmployee: La lista de empleados.
 * @return Retorna 1 o 0: 1 si se puedo parsear o 0 si no se pudo parsear.
 */
int parser_PassengerFromBinary(FILE* pFile , LinkedList* pArrayListPassenger);
