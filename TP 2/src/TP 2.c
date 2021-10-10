/*
 ============================================================================
 TP 2

 Real Agustin 1D
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ingresosAux.h"
#include "ArrayEmployees.h"

#define nombreTam 51
#define apellidoTam 51
#define salarioMax 80000
#define salarioMin 30000
#define sectorMax 5
#define sectorMin 0
#define longListaEmpleados 1000
int main(void)
{
	setbuf(stdout, NULL);



	Employee employeesAux;
	Employee listEmpleados[longListaEmpleados];


	int option;
	int listEmpleadosAux;
	int tamEmpleados;
	int employeesAuxPosicionVacia;
	char afirmacion;
	int contadorIdEmployees=0;
	int error=-1;
	int contadorId=1;
	int almacenarAuxIdModificar;
	int contadorEmployeesActivo=0;
	int minIdcontador=1;
	int maxIdcontador=32767;
	int auxBuscarIndice;
	int contadorSuperanSalarioEmpleados=0;
	float promedio;
	float acumuladorSalario=0;
	int contadorSueldos=0;

	initEmployees(listEmpleados, longListaEmpleados);

	do
	{
		pedirEntero(&option, "--------------------------------------------------------------------------\n"
							 "1.ALTAS employees\n"
							 "2.MODIFICAR employees\n"
				             "3.BAJA employees\n"
							 "4.Imformar\n"
							 "5.SALIR\n"
							 "--------------------------------------------------------------------------\n"
							 "Ingrese una opcion: ",

							 "1.ALTAS employees\n"
							 "2.MODIFICAR employees\n"
							 "3.BAJA employees\n"
							 "4.IMFORMAR\n"
							 "5. SALIR\n"
							 "--------------------------------------------------------------------------\n"
							 "Opcion invalida, reingrese: ",1, 5);

		switch(option)
		{
			case 1:
				employeesAuxPosicionVacia=seachEmployees(listEmpleados,  longListaEmpleados);
				if(employeesAuxPosicionVacia!=-1)
				{
					pedirCadena(employeesAux.name, "Ingrese el nombre del nuevo empleado: ","Error.Ingres el nombre del nuevo empleado: ", nombreTam);
					pedirCadena(employeesAux.lastName, "Ingrese el apellido del nuevo empleado: ","Error.Ingres el apellido del nuevo empleado: ", apellidoTam);
					pedirFlotante(&employeesAux.salary, "Ingrese el salario del nuevo empleado: ","Error.Ingres el salario del nuevo empleado: ", salarioMin, salarioMax);
					pedirEntero(&employeesAux.sector, "Ingrese el sector del empleado: ", "Error.Ingrese el sector del empleado: ", sectorMin, sectorMax);
					employeesAux.id=contadorId;

					printf("\n\n");
					showAnEmployee(employeesAux);
					pedirCaracter(&afirmacion,"\n\nPresione S para agregar al empleado ingresado");
					if(afirmacion=='s' || afirmacion=='S')
					{
						addEmployee(listEmpleados, longListaEmpleados, employeesAux.id, employeesAux.name, employeesAux.lastName, employeesAux.salary, employeesAux.sector);
						contadorId++;
						contadorEmployeesActivo++;
						printf("El nuevo empleado fue agregado....\n");
						getchar();
					}
					else
					{
						printf("Se ha producido un error...\n");
					}
		        }
				else
				{
					printf("El sistema esta lleno vuelva en otras instancias\n");
				}
				showAnEmployee(listEmpleados[0]);
				system("pause");
				break;
			case 2:
				if(contadorEmployeesActivo>0)
				{
					pedirEntero(&almacenarAuxIdModificar, "Cual es id que desea modifcar: ", "Error. Cual es id que desea modifcar: ", minIdcontador, maxIdcontador);
					auxBuscarIndice=findEmployeeById(listEmpleados, longListaEmpleados, almacenarAuxIdModificar);
					if(listEmpleados[auxBuscarIndice].isEmpty==0)
					{
						showAnEmployee(listEmpleados[auxBuscarIndice]);
						do
						{
							pedirEntero(&option,"--------------------------------------------------------------------------\n"
												"1-MODIFICAR nombre.\n"
												"2-MODIFICAR apelllido.\n"
												"3-MODIFICAR Salario.\n"
												"4-MODIFICAR sector.\n"
												"5-SALIR.\n"
									 	 	 	"--------------------------------------------------------------------------\n"
												"Ingrese una opcion: ",

												"1-MODIFICAR nombre.\n"
												"2-MODIFICAR apelllido.\n"
												"3-MODIFICAR Salario.\n"
												"4-MODIFICAR sector.\n"
												"5-SALIR.\n"
												"--------------------------------------------------------------------------\n"
												"Opcion invalida, reingrese: ", 1, 5);
							switch(option)
							{
								case 1:
									pedirCadena(listEmpleados[auxBuscarIndice].name, "Ingrese el nuevo nombre del empleado: ", "Ingrese el nuevo nombre del empleado: ", nombreTam);
									break;
								case 2:
									pedirCadena(listEmpleados[auxBuscarIndice].lastName, "Ingrese el nuevo apellido del empleado: ", "Error. Ingrese el nuevo apellido del empleado: ", apellidoTam);
									break;
								case 3:
									pedirFlotante(&listEmpleados[auxBuscarIndice].salary, "Ingrese el nuevo salario del empleado: ", "Error. Ingrese el nuevo salario del empleado: ", salarioMin, salarioMax);
									break;
								case 4:
									pedirEntero(&listEmpleados[auxBuscarIndice].sector, "Ingrese el nuevo sector del empleado: ", "Error. Ingrese el nuevo sector del empleado: ", sectorMin, sectorMax);
									break;
							}
							showAnEmployee(listEmpleados[auxBuscarIndice]);
						}while(option!=5);
					}
					else
					{
						printf("No se indentifico ese empleado\n");
					}
				}
				else
				{
					printf("No se ha ingresado ningun employees...");
				}
                option=0;
				break;
			case 3:
				if(contadorEmployeesActivo>0)
				{
					pedirEntero(&almacenarAuxIdModificar, "Ingrese el numero de Id del empleado que se dara de baja: ", "Error. Ingrese el numero de Id del empleado que se dara de baja: ", minIdcontador, maxIdcontador);
					auxBuscarIndice=findEmployeeById(listEmpleados, longListaEmpleados, almacenarAuxIdModificar);
					if(listEmpleados[auxBuscarIndice].isEmpty==0)
					{
						showAnEmployee(listEmpleados[auxBuscarIndice]);
						pedirCaracter(&afirmacion,"\n\nPresione S para agregar dar de baja al empleado");
						if(afirmacion=='s' || afirmacion=='S')
						{
							removeEmployee(listEmpleados,  longListaEmpleados, almacenarAuxIdModificar);
						}
						else
						{
							printf("Se ha producido un error...\n");
						}
					}
					else
					{
						printf("Se ha producido un error...");
					}
				}
				else
				{
					printf("No se ha ingresado ningun employees...");
				}
				break;
			case 4:
				if(contadorEmployeesActivo>0)
				{
					do
					{

						pedirEntero(&option, "Ingrese la opcion que desea IMFORMAR\n"
											 "1-Listado de los empleados ordenados alfab�ticamente por Apellido y Sector.\n"
											 "2-Total y promedio de los salarios, y cu�ntos empleados superan el salario promedio.\n"
											 "3.SALIR\n"
											 "--------------------------------------------------------------------------\n"
											 "Ingrese una opcion: ",

											 "Ingrese la opcion que desea IMFORMAR\n"
											 "1-Listado de los empleados ordenados alfab�ticamente por Apellido y Sector.\n"
											 "2-Total y promedio de los salarios, y cu�ntos empleados superan el salario promedio.\n"
											 "3.SALIR\n"
											 "--------------------------------------------------------------------------\n"
											 "Ingrese una opcion: "
											 "Opcion invalida, reingrese: ", 1, 3);

						switch(option)
						{
							case 1:
								printf("Entro en caso 1 ordenamiento");
								sortEmployees(listEmpleados, longListaEmpleados);
								break;
							case 2:

								walkActiveEmployees(listEmpleados, longListaEmpleados,  &acumuladorSalario,  &contadorSueldos);

								promedio=(float)acumuladorSalario/contadorSueldos;

							    averageAverageSalary(listEmpleados, longListaEmpleados, promedio , &contadorSuperanSalarioEmpleados);

							    printf("\nEl total de salario es: %.2f\n", acumuladorSalario);
							    printf("El promedio de los salarios es: %.2f\n ", promedio);
							    printf("La cantidad de peronas que superan el salario es: %d\n", contadorSuperanSalarioEmpleados);

								break;
						}
						option=0;
					}while(option!=3);
					option=0;
				}
				else
				{
					printf("No se ha ingresado ningun employees...");
				}
				break;
		}
	}while(option!=5);
}
