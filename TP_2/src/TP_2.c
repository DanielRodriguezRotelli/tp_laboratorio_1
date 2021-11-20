/*
 ============================================================================
 Name        : TRABAJO_2.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn_biblioteca.h"
#include "ArrayEmployees.h"

#define EMPLOYEE_LEN 10

int main(void)
{
	setbuf(stdout,NULL);

	Employee Empleados[EMPLOYEE_LEN];

	int opcionMenuPrincipal;
	int indicePosicionLibre;
	int indicePosicionOcupada;
	int idAux;
	char nombreAux[51];
	char apellidoAux[51];
	int sectorAux;
	float salarioAux;
	int idABuscar;
	int indiceAModificar;
	int indiceABajar;
	int menuInformes;
	int opcionListado;
	float totalSalarios;
	int cantidadSalarios;
	float promedioDeSalarios;
	int cantSalarioSuperiorAlPromedio;
	char respuesta;


	initEmployees(Empleados,EMPLOYEE_LEN);

	do
	{
		menuPrincipal(&opcionMenuPrincipal);

			switch(opcionMenuPrincipal)
			{
				case 1:
				if(buscarPosicionLibre(Empleados, EMPLOYEE_LEN, &indicePosicionLibre)==0)
				{
					if(pedirDatosEmpleado(Empleados, EMPLOYEE_LEN,&idAux,nombreAux,apellidoAux,&salarioAux,&sectorAux)==0)
					{
						if(addEmployees(Empleados, EMPLOYEE_LEN, idAux, nombreAux, apellidoAux, salarioAux, sectorAux)==0)
						{
							printf("Id creado: %d",idAux);
						}
					}
					else
					{
						printf("No se pudo dar alta");
					}
				}
				else
				{
					printf("No hay espacio disponible para dar alta.\n");
				}
				break;

				case 2:
				if(buscarPosicionOcupado(Empleados, EMPLOYEE_LEN,&indicePosicionOcupada)==0)
				{
					if(getInt(&idABuscar, 1, 9999999, 3, "Ingrese el Id que quiere modificar", "Error.")==0)
					{
						indiceAModificar=findEmployeeById(Empleados,EMPLOYEE_LEN,idABuscar);
						if(modificarArray(Empleados,EMPLOYEE_LEN, indiceAModificar)==0)
						{
							printf("el id %d se ha modificado con exito.",idABuscar);
						}
					}
				}
				else
				{
					printf("No se puede modificar. No hay altas ingresadas.");
				}
				break;

				case 3:
				if(buscarPosicionOcupado(Empleados, EMPLOYEE_LEN,&indicePosicionOcupada)==0)
				{
					if(getInt(&idABuscar, 1, 9999999, 3, "Ingrese el Id que quiere dar de baja.", "Error.")==0)
					{
						indiceABajar=findEmployeeById(Empleados,EMPLOYEE_LEN,idABuscar);
						if(removeEmployee(Empleados,EMPLOYEE_LEN,indiceABajar)==0)
						{
							printf("el id %d se ha dado de baja con exito.",idABuscar);
						}
					}
				}
				else
				{
					printf("No se puede dar de Baja. No hay altas ingresadas.");
				}
				break;

				case 4:
				if(buscarPosicionOcupado(Empleados, EMPLOYEE_LEN,&indicePosicionOcupada)==0)
				{
					menuInforme(&menuInformes);
					if(menuInformes==1)
					{
						getInt(&opcionListado,1,2,3,"\nComo desea ver el listado? \n1- De forma creciente. \n2- De forma decreciente. \nIngrese la opcion deseada: ", "Error");
						if(sortEmployees(Empleados,EMPLOYEE_LEN,opcionListado)==0)
						{
							printEmployees(&Empleados[indicePosicionOcupada],EMPLOYEE_LEN);
						}
					}
					else
					{
						totalSalarios=SumaSalarios(Empleados,EMPLOYEE_LEN);
						cantidadSalarios=contarCantidadSalarios(Empleados, EMPLOYEE_LEN);
						promedioDeSalarios=promedioSalario(totalSalarios, cantidadSalarios);
						cantSalarioSuperiorAlPromedio=buscarSalarioMayorAlPromedio(Empleados, EMPLOYEE_LEN, promedioDeSalarios);

						printf("\nTotal de los Salarios: %.2f",totalSalarios);
						printf("\nPromedio de los Salarios: %.2f",promedioDeSalarios);
						printf("\nCantidad de Empleados que superan el salario promedio: %d",cantSalarioSuperiorAlPromedio);

					}
				}
				else
				{
					printf("No se puede listar informes. No hay altas ingresadas.");
				}

				break;

				case 5:

				printf("Usted desea salir del menu? s/n: ");
				fflush(stdin);
				scanf("%c",&respuesta);
				break;
			}

	}while(respuesta!='s');


		return EXIT_SUCCESS;
	}
