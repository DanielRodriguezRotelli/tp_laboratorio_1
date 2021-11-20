#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"
#include "utn_biblioteca.h"
#include "parser.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
	int retorno=-1;
	//int i;
	//int pLenList=ll_len(pArrayListEmployee);
	Employee* auxEmployee;
	char id[NAME_LEN];
	char nombre[NAME_LEN];
	char horas[NAME_LEN];
	char sueldo[NAME_LEN];

	if(pFile!=NULL && pArrayListEmployee!=NULL)
	{
		fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",id,nombre,horas,sueldo);//salto la primer linea
		do
		{
			if(fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",id,nombre,horas,sueldo)==4)
			{
				//printf("Lei:%s  %s  %s  %s\n",id,nombre,horas,sueldo);
				auxEmployee=employee_newParametros(id,nombre,horas,sueldo);
				if(auxEmployee!=NULL)
				{
					ll_add(pArrayListEmployee,auxEmployee);
					retorno=0;
				}
			}
			else
			{
				employee_delete(auxEmployee);
				break;
			}
		}while(feof(pFile)==0);
	}/*
	for(i=0; i<ll_len(pArrayListEmployee);i++)
	{
		auxEmployee = ll_get(pArrayListEmployee,i);
		printf("%d  %s  %d  %d\n",auxEmployee->id,
								  auxEmployee->nombre,
								  auxEmployee->horasTrabajadas,
								  auxEmployee->sueldo);


	}*/
	return retorno;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
	int retorno=-1;
	//int i;
	//int pLenList=ll_len(pArrayListEmployee);
	Employee* auxEmployee;

	if(pFile!=NULL && pArrayListEmployee!=NULL)
	{
		do
		{
			auxEmployee=employee_new();
			if(fread(auxEmployee,sizeof(Employee),1,pFile)==1)
			{

				ll_add(pArrayListEmployee,auxEmployee);
				retorno=0;
			}
			else
			{
				employee_delete(auxEmployee);
				break;
			}
		}while(feof(pFile)==0);
	}/*
	for(i=0; i<ll_len(pArrayListEmployee);i++)
	{
		auxEmployee = ll_get(pArrayListEmployee,i);
		printf("%d  %s  %d  %d\n",auxEmployee->id,
								  auxEmployee->nombre,
								  auxEmployee->horasTrabajadas,
								  auxEmployee->sueldo);

	}*/
	return retorno;
}
