/*
 * funciones.h
 *
 *  Created on: 3 sep. 2021
 *      Author: Agustin
 */
#ifndef FUNCIONES_H_
#define FUNCIONES_H_

//Bibliotecas para realizar cada calculo.
/**
 * @fn float sumar(float, float)
 * @brief Permite ingresar 2 numeros y retorna la suma de los mismos.
 * @param El parametro a: Es 1ER numero ingresado por el usuario.
 * @param El parametro b: Es 2DO numero ingresado por el usuario.
 * @param La variable resultado: es la suma de a+b.
 * @return La suma de los numeros ingresados.
 */
float sumar(float a, float b);
/**
 * @fn float resta(float, float)
 * @brief Permite ingresar 2 numeros y retorna la resta de los mismos.
 * @param El parametro a: Es 1ER numero ingresado por el usuario.
 * @param El parametro b: Es 2DO numero ingresado por el usuario.
 * @param La variable resultado: es la resta de a+b.
 * @return La resta de los numeros ingresados.
 */
float resta(float a, float b);
/**
 * @fn float division(float, float)
 * @brief Permite ingresar 2 numeros y retorna la division de los mismos.
 * @param El parametro a: Es 1ER numero ingresado por el usuario.
 * @param El parametro a: Es 1ER numero ingresado por el usuario.
 * @param La variable resultado: es la multiplicacion de a/b.
 *  @param La condicion "if" nos indica si b no es igual a 0, entra
 *  y devuelve "la division realizada por el usuario".
 * @param La condicion "else" nos indica si el numero ingresado "b"
 * es igual a 0, entra y devuelve "no se puede dividir por 0".
 * @return La division de los numeros ingresados o un 0.
 */
float Multiplicacion(float a, float b);
/**
 * @fn int Multiplicacion(int, int)
 * @brief Permite ingresar 2 numeros y retorna la multiplicacion de los mismos.
 * @param El parametro a: Es 1ER numero ingresado por el usuario.
 * @param El parametro b: Es 2DO numero ingresado por el usuario.
 * @param La variable resultado: es la multiplicacion de a*b.
 * @return La multiplicacion de los numeros ingresados.
 */
float division(float a, float b);
/**
 * @fn int calcularFactorial(int)
 * @brief Permite ingresar un numero y retorna el factorial del mismo.
 * @param El parametro numero: Es el ingreso de un numero por el usuario.
 * @param La variable factorial: Esta igualada a 0 y es la que utilazaremos para
 * hacer el calculo de un factorial, Ejemplo: (!numero).
 * @param La condicion "if" nos indica si el numero ingresado es distinto a 0 y 1.
 * si se cumple la condicion entra y realiza el calculo.
 * @return Factorial calculado y pedido por el usuario.
 */
int calcularFactorialEnteros(float numero);
/**
 * @fn int verificarPositivo(float)
 * @brief Esta funcion verifica el numero es positivo.
 * @param El numero : lo usamos para verificar si el numero es mayor (POSITIVO).
 * @return Usamos el valor para devolver un 1 si el numero es positivo o
 * un 0 si el numero  es negativo.
 */
int verificarPositivo(float numero);
/**
 * @fn int verificarEntero(float)
 * @brief Este apartado verifica si el numero ingresado es entero.
 * @param if:Utilizamos el if para castear el numero ingresado "float" y quedarnos con la parte entera.
 * @param El parametro numero la usamos para varificar si el numero es enttero o no.
 * @return Usamos valor para retornar 1 si el numero es entero o valor 0 si el numero rea
 */
int verificarEntero(float numero);
/**
 * @fn int verificarSePuedeCalcularFactorial(float)
 * @brief Esta funcion verifica si se pudo calcular el factorial sabiendo que no puede ser negativo o numero real.
 * @param if:Usamos el if para usar las 2 funciones anteriores y meterla en uno ya que usamos == asignarle 1.
 * @param El parametro numero es el parametro de las anteriores funciones para igualar los casos verificados.
 * @return El retorna valor que es una variable auxiliar que le asignamos un 1 o un 0.
 * Si la variable devuelve 1 se pudo verificar "numero es positivo y entero" o devuelve un 0 "no es positivo o entero".
 */
int verificarSePuedeCalcularFactorial(float numero );
#endif
