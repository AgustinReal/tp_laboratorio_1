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
 * @brief
 *
 * @param list
 * @param len
 * @return
 */
int initEmployees(Employee* list, int len);
int seachEmployees(Employee* list, int len);
int addEmployee(Employee* list, int len, int id, char name[], char lastName[], float salary, int sector);
int findEmployeeById(Employee* list, int len,int id);
void showAnEmployee(Employee empleado);
int confirmYesOrNoEmployee(char* mensaje);
int removeEmployee(Employee* list, int len, int id);
int sortEmployees(Employee* list, int len);
int printEmployees(Employee* list, int length);
int walkActiveEmployees(Employee* list, int len, float* acumuladorSalarioAux, int* contadorSueldosAux);
int averageAverageSalary(Employee* list, int len, float promedioAux , int* contadorSuperanSalario);
#endif /* ARRAYEMPLOYEES_H_ */
