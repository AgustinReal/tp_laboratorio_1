/*
 * ArrayEmployees.h
 *
 *  Created on: 1 oct. 2021
 *      Author: Agustin
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ingresosAux.h"
#include <ctype.h>

#ifndef ARRAYEMPLOYEES_H_
#define ARRAYEMPLOYEES_H_
#include "ArrayEmployees.h"
//Tamaño de array
#define LEN 5

//estado
#define VACIO 0
struct
{
	int id;
	char name[51];
	char lastName[51];
	float salary;
	int sector;
	int isEmpty;


}typedef Employee;

/**
 * @fn int initEmployees(Employee*, int)
 * @brief This function goes through the "employee list" to search for the first free space in a for loop.
 *
 * @param list: Array Employee
 * @param len: size array
 *
 * @return returns 1 or -1: "1" if it could perform the function or "-1" if it could not perform the function.
 */
int initEmployees(Employee* list, int len);
/**
 * @fn int seachEmployees(Employee*, int)
 * @brief This function goes through the "employee list" to search for the first free space in a for loop.
 *
 * @param list: Array Employee
 * @param len: size array
 *
 * @return returns 1 or -1: "1" if it could perform the function or "-1" if it could not perform the function.
 */
int seachEmployees(Employee* list, int len);
/**
 * @fn int addEmployee(Employee*, int, int, char[], char[], float, int)
 * @brief This function adds an Employee: if the 1st free space in the list is occupied. All the data of the
 * the data of the employee
 *
 * @param list: Array Employee.
 * @param len: size array.
 * @param id: Employee Income Number.
 * @param name: Name of employee.
 * @param lastName: Last ame of employee.
 * @param salary: Employee salary.
 * @param sector: Sector where the Employee will work(1-6).
 *
 * @return returns -1 or 0 or 1: "1" if it could perform the function or "0" if it could not perform the function or "-1" if it could not find the index.
 */
int addEmployee(Employee* list, int len, int id, char name[], char lastName[], float salary, int sector);
/**
 * @fn int findEmployeeById(Employee*, int, int)
 * @brief This function: Searches for an id of an Employee by means of a for, which goes through the general list by id.
 *
 * @param list: Array Employee.
 * @param len: size array.
 * @param id: Employee Income Number.
 *
 * @return index i or -1: "i" if it could perform the function and found the id or "-1" if it could not perform the function to find the id.
 */
int findEmployeeById(Employee* list, int len,int id);
/**
 * @fn void showAnEmployee(Employee)
 * @brief This function: Displays the data of a customer id, name, race, etc...
 *
 * @param employee: estadia receives the data of this customer's income.
 */
void showAnEmployee(Employee empleado);
/**
 * @fn int confirmYesOrNoEmployee(char*)
 * @brief This function is used to confirm the yes or no of an Employee in this case.
 *
 * @param mensaje: What will be displayed on screen to the user "something to show"
 * @return returns 0 or -1: "0" if it could perform the function or "-1" if it could not perform the function.
 */
int confirmYesOrNoEmployee(char* mensaje);
/**
 * @fn int removeEmployee(Employee*, int, int)
 * @brief This function deletes an already entered employee, asks for the id to delete and deletes it,
 * deleting that employee.
 *
 * @param list: Array Employee.
 * @param len size array.
 * @param id: Employee's login number
 *
 * @return returns 1 or -1: "1" if it could perform the function or "-1" if it could not perform the function.
 */
int removeEmployee(Employee* list, int len, int id);
/**
 * @fn int sortEmployees(Employee*, int, int)
 * @brief This function sorts the Employee by surname and if the sectors are the same, it sorts by alphabetical name with a sector compare function.
 * by alphabetical name with a sector comparison function and can also be sorted in ascending or descending order.
 *
 * @param list: Array Employee.
 * @param len: size array.
 * @param order:  ascending or descending.
 *
 * @return returns 0 or -1: "0" if it could perform the function or "-1" if it could not perform the function.
 */
int sortEmployees(Employee* list, int len, int order);
/**
 * @fn int printEmployees(Employee*, int)
 * @brief   This function: Prints the list of all the clinetes entered with their data, id ,name, phone,
 * etc..
 * It runs it through a for and a function that shows a statistic.
 *
 * @param list: Array Employee;
 * @param length: the size of the Employee list.
 *
 * @return returns 1 or -1: "1" if it could perform the function or "-1" if it could not perform the function.
 */
int printEmployees(Employee* list, int length);
/**
 * @fn int walkActiveEmployees(Employee*, int, float*, int*)
 * @brief  This function scrolls through the active employees with a for, accumulates the active salaries and counts the amount of
 * salaries of the employees.
 *
 * @param list Array Employee.
 * @param len: size array.
 * @param acumuladorSalarioAux: Where we store the sum of all salaries of active employees.
 * @param contadorSueldosAux: Number of sessional periods of all active employees.
 *
 * @return returns 1 or -1: "1" if it could perform the function or "-1" if it could not perform the function.
 */
int walkActiveEmployees(Employee* list, int len, float* acumuladorSalarioAux, int* contadorSueldosAux);
/**
 * @fn int CalculateAverageOfEmployees(Employee*, int, float*, int*, float*)
 * @brief This section calculates the average, using the data of the total sum of salaries of the previous functions and divides it by the number of employees' salaries.
 * with the number of employees' salaries.
 *
 * @param list: Array Employee.
 * @param len: size array.
 * @param acumuladorSalarioAux: Where we store the sum of all salaries of active employees.
 * @param contadorSueldosAux: Number of sessional periods of all active employees.
 * @param promedioAux: Where we store the result of the averaging.
 *
 * @return returns 1 or -1: "1" if it could perform the function or "-1" if it could not perform the function.
 */
int CalculateAverageOfEmployees(Employee* list, int len, float* acumuladorSalarioAux, int* contadorSueldosAux, float* promedioAux);
/**
 * @fn int averageAverageSalary(Employee*, int, float*, int*)
 * @brief In this function we calculate the number of people who exceed the average wage.
 * using a for and a counter.
 *
 * @param list: Array Employee.
 * @param len: size array.
 * @param promedioAux: Where we store the result of the averaging.
 * @param contadorSuperanSalario: where we keep the number of people above the average wage.
 * @return returns 1 or -1: "1" if it could perform the function or "-1" if it could not perform the function.
 */
int averageAverageSalary(Employee* list, int len, float* promedioAux, int* contadorSuperanSalario);
#endif /* ARRAYEMPLOYEES_H_ */
