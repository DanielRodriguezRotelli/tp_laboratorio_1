/*
 * Pantalla.c
 *
 *  Created on: 30 sep. 2021
 *      Author: Aye
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn_biblioteca.h"
#include "ArrayEmployees.h"




static int getIdNuevo(void);


int initEmployees(Employee* list, int len)
{
	int indice;
	int retorno=0;

	if(list!=NULL && len>0)
	{

		for(indice=0; indice<len; indice++)
		{
			list[indice].isEmpty=1;
			retorno=1;
		}
	}
	return retorno;
}


void menuPrincipal(int* opcionDeMenu)
{
	int opcion;

	do
	{
		getInt(&opcion,1,5,3,"\n--MENU PRINCIPAL-- \n1)Altas. \n2)Modificar. \n3)Baja \n4)Informar: \n  1-Listado de los empleados ordenados alfabéticamente por Apellido y Sector. \n  2-Total y promedio de los salarios, y cuántos empleados superan el salario promedio. \n5)Salir. \nIngrese la opcion deseada: ", "Error");
	}while(opcion!=1 && opcion!=2 && opcion!=3 && opcion!=4 && opcion!=5);
	*opcionDeMenu=opcion;
}

void crearIdNuevo(int* idCreado)
{
	int id;
	id=getIdNuevo();
	*idCreado=id;
}

int pedirDatosEmpleado(Employee* list, int len, int* idAux, char* nameAux, char* lastNameAux, float* salaryAux, int* sectorAux)
{

	int i;
	int retorno=-1;
	int indiceLibre;
	//int nombre[51];
	//int apellido[51];
	float salario;
	int sector;

	if(list!=NULL &&len>0 && idAux!=NULL &&nameAux!=NULL && lastNameAux!=NULL && salaryAux!=NULL && sectorAux!=NULL)
	{
		for(i=0;len>0;i++)
		{
			if(buscarPosicionLibre(list,len,&indiceLibre)==0)
			{
				getText(nameAux, 128, "Ingrese el nombre: ", "Error", 3);
				getText(lastNameAux, 128, "Ingrese el apellido: ", "Error", 3);
				getFloat(&salario, 0, 100000, 2, "Ingrese el salario: ", "Error");
				getInt(&sector, 0, 9889898, 3, "Ingrese el numero de sector: ", "Error");
				*idAux=getIdNuevo();
				*salaryAux=salario;
				*sectorAux=sector;
				retorno=0;
				break;
			 }
		 }
	}
	return retorno;
}




int addEmployees(Employee* list, int len, int id, char name[], char lastName[], float salary, int sector)
{
	int i;
	int retorno=-1;
	int indiceLibre;

	if(list!=NULL && len>0 && id>=0 && name!=NULL && lastName!=NULL && salary>=0 && sector>=0)
	{
		for(i=0;len>0;i++)
		{
			if(buscarPosicionLibre(list,len,&indiceLibre)==0)
			{
				list[indiceLibre].id=id;
				strncpy(list[indiceLibre].name,name,sizeof(list[indiceLibre].name));
				strncpy(list[indiceLibre].lastName,lastName,sizeof(list[indiceLibre].lastName));
				list[indiceLibre].salary=salary;
				list[indiceLibre].sector=sector;
				list[indiceLibre].isEmpty=0;
				retorno=0;
				break;
			}
		}
	}
	return retorno;
}




static int getIdNuevo(void)
{
	static int contador=0;
	contador ++;
	return contador;
}

void printEmp(Employee* list)
{
	if(list!=NULL)
	{
		if(list->isEmpty==0)
		{
			printf("\n	%d		%s		%s		%.2f		%d",list->id, list->name, list->lastName, list->salary, list->sector);
			//printf("\nId: %d", list->id);
			//printf("\nNombre: %s", list->name);
			//printf("\nApellido: %s", list->lastName);
			//printf("\nSalario: %.2f", list->salary);
			//printf("\nSector: %d", list->sector);
			//printf("\nEsta Libre?: %d\n", list->isEmpty);
		}
	}
}



int printEmployees(Employee* list, int len)
{
	int i;
	int retorno=-1;
	if(list!=NULL && len>0)
	{
		printf("	Id		Nombre		Apellido	Salario		Sector ");
		for(i=0; i<len; i++)
		{
			printEmp(&list[i]);
			retorno=0;
		}
	}
	return retorno;
}


int buscarPosicionLibre(Employee* list, int len, int* pPosicionLibre)
{
	int indice;
	int retorno=-1;

	if(list!=NULL && len>0 && pPosicionLibre!=NULL)
	{
		*pPosicionLibre=-1;
		for(indice=0; indice<len; indice++)
		{
			if(list[indice].isEmpty==1)
			{
				*pPosicionLibre=indice;
				retorno=0;
				break;
			}
		}
	}
	return retorno;
}


int buscarPosicionOcupado(Employee* list, int len, int* pPosicionOcupado)
{
	int indice;
	int retorno=-1;

	if(list!=NULL && len>0 && pPosicionOcupado!=NULL)
	{
		*pPosicionOcupado=-1;
		for(indice=0; indice<len; indice++)
		{
			if(list[indice].isEmpty==0)
			{
				*pPosicionOcupado=indice;
				retorno=0;
				break;
			}
		}
	}
	return retorno;
}



int findEmployeeById(Employee* list, int len, int id)
{
	int indice;
	int indiceIdABuscar;
	int retorno=-1;


	if(list!=NULL && len>0 && id>=0)
	{
		for(indice=0; indice<len; indice++)
		{
			if(list[indice].isEmpty!=1)
			{
				if(list[indice].id==id)
				{
					indiceIdABuscar=indice;
					retorno=0;
					break;
				}
			}
			else
			{
				printf("El id está vacio.");
			}
		}
	}
	return indiceIdABuscar;
}



int modificarArray(Employee* list, int len, int posicionId)
{
	int sectorAux;
	float salarioAux;
	char nameAux[128];
	char apellidoAux[128];
	int retorno=-1;
	int opcionesDeMenu;

	if(list!=NULL && len>0 && posicionId>=0)
	{
		do
		{
			do
			{
				getInt(&opcionesDeMenu,1,5, 3, "Ingrese la opcion que desea modificar: 1)Sector, 2)Salario, 3)Nombre, 4)Apellido, 5)salir ", "Error");
			}while(opcionesDeMenu!=1 && opcionesDeMenu!=2 && opcionesDeMenu!=3 && opcionesDeMenu!=4 && opcionesDeMenu!=5);

				switch(opcionesDeMenu)
				{
					case 1:
					getInt(&sectorAux, 0, 987456, 3, "Ingrese el sector: ", "Error");
					list[posicionId].sector=sectorAux;
					break;

					case 2:
					getFloat(&salarioAux, 0, 100000, 2, "Ingrese el salario: ", "Error");
					list[posicionId].salary=salarioAux;
					break;

					case 3:
					getText(nameAux, 128, "Ingrese el nombre: ", "Error", 3);
					strncpy(list[posicionId].name,nameAux,sizeof(list[posicionId].name));
					break;

					case 4:
					getText(apellidoAux, 128, "Ingrese el apellido: ", "Error", 3);
					strncpy(list[posicionId].lastName,apellidoAux,sizeof(list[posicionId].lastName));
					break;

					case 5:
					puts("Usted salio del menu de modificar.");
					break;
				}
				retorno=0;

		}while(opcionesDeMenu!=5);
	}
	return retorno;
}



int removeEmployee(Employee* list, int len, int id)
{
	int indice;
	int retorno=-1;

	if(list!=NULL && len>0 && id>=0)
	{
		for(indice=0; indice<len; indice++)
		{
			list[id].isEmpty=1;
			retorno=0;
			break;
		}
	}
	return retorno;
}


void menuInforme(int* opcionDeMenuInforme)
{
	int opcion;

	do
	{
		getInt(&opcion,1,5,3,"\n--MENU INFORMES-- \n1-Listado de los empleados. \n2-Total y promedio de los salarios, y cuántos empleados superan el salario promedio. \n3)Salir. \nIngrese la opcion deseada: ", "Error");
	}while(opcion!=1 && opcion!=2 && opcion!=3);
	*opcionDeMenuInforme=opcion;
}



int sortEmployees(Employee* list, int len, int order)
{
	int retorno=-1;
	int flagSwap;
	int i;

	Employee buffer;
	if(list!=NULL && len>0 && order>0)
	{
		if(order==1)
		{
			do
			{
				flagSwap=0;
				for(i=0; i<len-1; i++)
				{
					// esta Tercera opcion es para ordenar de forma CRECIENTE por Apellido y Sector (MEJOR ESCRITA)
					if((strncmp(list[i].lastName,list[i+1].lastName, APELLIDO_LEN) > 0) ||
						(strncmp(list[i].lastName,list[i+1].lastName, APELLIDO_LEN) == 0 && list[i].sector > list[i+1].sector))
					{
						buffer=list[i];
						list[i]=list[i+1];
						list[i+1]=buffer;
						flagSwap=1;
						retorno=0;
					}
				}
				len--;
			}while(flagSwap);
		}
		else
		{
			do
			{
				flagSwap=0;
				for(i=0; i<len-1; i++)
				{
					// esta Tercera opcion es para ordenar de forma DECRECIENTE por Apellido y Sector (MEJOR ESCRITA)
					if((strncmp(list[i].lastName,list[i+1].lastName, APELLIDO_LEN) < 0) ||
						(strncmp(list[i].lastName,list[i+1].lastName, APELLIDO_LEN) == 0 && list[i].sector < list[i+1].sector))
					{
						buffer=list[i];
						list[i]=list[i+1];
						list[i+1]=buffer;
						flagSwap=1;
						retorno=0;
					}
				}
				len--;
			}while(flagSwap);
		}
	}
	return retorno;
}

float SumaSalarios(Employee* list, int len)
{
	int i;
	float acumSalario=0;
	if(list!=NULL && len>0)
	{
		for(i=0;i<len;i++)
		{
			if(list[i].isEmpty==0)
			{
				acumSalario=acumSalario+list[i].salary;
			}
		}
	}
	return acumSalario;
}

int contarCantidadSalarios(Employee* list, int len)
{
	int i;
	int contSalario=0;
	if(list!=NULL && len>0)
	{
		for(i=0;i<len;i++)
		{
			if(list[i].isEmpty==0)
			{
				if(list[i].salary>=0)
				{
					contSalario++;
				}
			}
		}
	}
	return contSalario;
}

float promedioSalario(float sumaSalarios, int cantSalarios)
{
	float promedio;
	if(sumaSalarios>=0 && cantSalarios>0)
	{
		promedio = (float) sumaSalarios / cantSalarios;
	}
	return promedio;
}

int buscarSalarioMayorAlPromedio(Employee* list, int len, float promedio)
{
	int i;
	int contSalarioMayorAlPromedio=0;
	if(list!=NULL && len>0 && promedio>0)
	{
		for(i=0; i<len; i++)
		{
			if(list[i].isEmpty==0)
			{
				if(list[i].salary>=promedio)
				{
					contSalarioMayorAlPromedio++;
				}
			}
		}
	}
	return contSalarioMayorAlPromedio;
}




//FUNCION DE PRUEBA PARA NOSOTROS
void altaForzada(Employee* list, int idEmpleado,char* nombre, char* apellido,  float salario, int sector, int indice)
{
	if(list!=NULL && indice>=0)
	{
		list[indice].sector=sector;
		list[indice].salary=salario;
		list[indice].id=idEmpleado;
		strncpy(list[indice].name,nombre,sizeof(list[indice].name));
		strncpy(list[indice].lastName,apellido,sizeof(list[indice].lastName));
		list[indice].isEmpty=0;
	}
}












