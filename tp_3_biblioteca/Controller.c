#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"
#include "utn_biblioteca.h"
#include "parser.h"
#include "Controller.h"



void controller_menu(int* optionMenu)
{
	int option;

		do {
			getInt(&option, 1, 11, 3, "\n\n--MENU PRINCIPAL-- "
					"\n1) Cargar los datos de los empleados desde el archivo data.csv (modo texto). "
					"\n2) Cargar los datos de los empleados desde el archivo data.csv (modo binario). "
					"\n3) Alta de empleado. "
					"\n4) Modificar datos de empleado. "
					"\n5) Baja de empleado. "
					"\n6) Listar empleados. "
					"\n7) Ordenar empleados. "
					"\n8) Guardar los datos de los empleados en el archivo data.csv (modo texto). "
					"\n9) Guardar los datos de los empleados en el archivo data.csv (modo binario). "
					"\n10) Salir del Menu Principal"
					"\nIngrese la opcion deseada: ", "Error");
		} while (option != 1 && option != 2 && option != 3 && option != 4
				&& option != 5 && option != 6 && option != 7 && option != 8
				&& option != 9 && option != 10);
		*optionMenu = option;
}


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
	int retorno=-1;
	FILE* f;

	if(path!=NULL && pArrayListEmployee!=NULL)
	{
		f= fopen(path, "r");
		if(f!=NULL)
		{
			if(parser_EmployeeFromText(f,pArrayListEmployee)==0)
			{
				printf("\nLos datos se han cargado con exito");
				retorno=0;
			}
		}
	}
	return retorno;
}


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
	int retorno=-1;
	FILE* f;

	if(path!=NULL && pArrayListEmployee!=NULL)
	{
		f= fopen(path, "rb");
		if(f!=NULL)
		{
			if(parser_EmployeeFromBinary(f,pArrayListEmployee)==0)
			{
				printf("\nLos datos se han cargado con exito");
				retorno=0;
			}
			else
			{
				printf("\nErrrrooooorrr. No se puede cargar Los datos");
			}
		}
	}
	return retorno;
}


/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
	int retorno=-1;
	int auxId=0;
	static int proximoId=1;
	char auxnombre[NAME_LEN];
	int auxHoras;
	int auxSueldo;

	if(pArrayListEmployee!=NULL)
	{
		auxId=employee_getNextId("data.csv") + proximoId;
		proximoId++;
		//printf("\nId: %d\n",auxId);
		//printf("\nproximo Id: %d\n",proximoId);
		if(getText(auxnombre,NAME_LEN,"Ingrese el nombre: ", "Error.", 3)==0)
		{
			if(getInt(&auxHoras, 0, 9999999, 3, "Ingrese las horas trabajadas: ", "Error.")==0)
			{
				if(getInt(&auxSueldo, 0, 9999999, 3, "Ingrese el sueldo: ", "Error.")==0)
				{
					Employee* auxEmployee=employee_new();
					if(auxEmployee!=NULL)
					{
						if((employee_setId(auxEmployee,auxId)==0) &&
						   (employee_setNombre(auxEmployee,auxnombre)==0) &&
						   (employee_setHorasTrabajadas(auxEmployee,auxHoras)==0) &&
					       (employee_setSueldo(auxEmployee,auxSueldo)==0))
						{
							ll_add(pArrayListEmployee,auxEmployee);
							printf("\nSe genero el Id: %d", auxId);
							retorno=0;
						}
					}
				}
			}
		}
	}
    return retorno;
}



/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
	int retorno=-1;
	int index;
	Employee* auxEmployee;
	int auxId;

	if(pArrayListEmployee!= NULL)
	{
		controller_ListEmployee(pArrayListEmployee);
		if(getInt(&auxId,1,999999,3,"Ingrese el Id del empleado a modificar: ","Error")==0)
		{
			index=employee_findById(pArrayListEmployee,auxId);
			if(index>=0)
			{
				auxEmployee= ll_get(pArrayListEmployee, index);
				if(auxEmployee!=NULL)
				{
					if(controller_menuEditEmployee(auxEmployee)==0)
					{
						printf("\nLa modificacion se ha realizado con exito.");
						printf("\nLos datos nuevos son:\n");
						printf("\nId,Nombre,HorasTrabajadas,Sueldo");
						printf("\n%d,%s,%d,%d\n",auxEmployee->id,auxEmployee->nombre,auxEmployee->horasTrabajadas,auxEmployee->sueldo);
						//controller_printEmployee(pArrayListEmployee, auxId);
						retorno=0;
					}
				}
			}
		}
	}
    return retorno;
}


int controller_menuEditEmployee(Employee* auxEmployee)
{
	int retorno=-1;
	int opcionMenu;
	char auxNombre[128];
	int auxHoras;
	int auxSueldo;


	do
	{
		do
		{
			printf("\n---Menu Modificacion---");
			printf("\n1) Nombre.");
			printf("\n2) Horas Trabajadas.");
			printf("\n3) Sueldo.");
			printf("\n4) Salir del menu modificacion.");
			getInt(&opcionMenu,1,4,3,"Ingrese la opcion que quiere modificar: ","Error");
		}while(opcionMenu!=1 && opcionMenu!=2 && opcionMenu!=3 && opcionMenu!=4);
		retorno=0;

		switch(opcionMenu)
		{
			case 1:
			if(getText(auxNombre,NAME_LEN,"Ingrese el nuevo nombre: ","Error", 3)==0)
			{
				if(employee_setNombre(auxEmployee,auxNombre)==0)
				{
					printf("\nEl nuevo nombre es: %s\n",auxNombre);
				}
			}
			else
			{
				printf("\nError. No se pudo modificar el nombre.");
			}
			break;

			case 2:
			if(getInt(&auxHoras,0,99999999,3,"Ingrese la nueva cantidad de horas trabajadas: ", "Error")==0)
			{
				if(employee_setHorasTrabajadas(auxEmployee,auxHoras)==0)
				{
					printf("\nLa nueva cantidad de horas trabajadas es: %d\n",auxHoras);
				}
			}
			else
			{
				printf("\nError. No se pudo modificar las horas trabajadas.");
			}
			break;

			case 3:
			if(getInt(&auxSueldo,0,99999999,3,"Ingrese el nuevo sueldo: ", "Error")==0)
			{
				if(employee_setSueldo(auxEmployee,auxSueldo)==0)
				{
					printf("\nEl nuevo sueldo: %d\n",auxSueldo);
				}
			}
			else
			{
				printf("\nError. No se pudo modificar el sueldo.");
			}
			break;

			case 4:
			//printf("Los datos nuevos son:");
			//controller_printEmployee(pArrayListEmployee, auxId);
			printf("\nUsted salió del menu de modificacion.\n");
			break;
		}
	}while(opcionMenu!=4);
	retorno=0;
	return retorno;
}



/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
	int retorno=-1;
	int auxId;
	int index;
	Employee* auxEmployee;

	if(pArrayListEmployee != NULL)
	{
		controller_ListEmployee(pArrayListEmployee);
		if(getInt(&auxId,1,999999,3,"Ingrese el Id del empleado que quiere eliminar: ","Error")==0)
		{
			index=employee_findById(pArrayListEmployee,auxId);
			if(index>=0)
			{
				auxEmployee=ll_get(pArrayListEmployee,index);
				if(employee_setId(auxEmployee,auxId)==0)
				{
					if(auxEmployee!=NULL)
					{
						employee_delete(auxEmployee);
						ll_remove(pArrayListEmployee,index);
						printf("\nSe ha eliminado el id: %d con exito.",auxId);
						//employee_delete(aux, pArrayListEmployee, index);
						retorno=0;
					}
				}
			}
		}
	}
    return retorno;
}



/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
	int i;
	int retorno = -1;
	Employee* auxEmployee;
	int pLenList=ll_len(pArrayListEmployee);

	if(pArrayListEmployee != NULL && pLenList > 0)
	{
		printf("\nId,Nombre,HorasTrabajadas,Sueldo\n");
		for(i=0; i<pLenList; i++)
		{
			auxEmployee = ll_get(pArrayListEmployee, i);
			if(auxEmployee != NULL)
			{
				printf("%d,%s,%d,%d\n",auxEmployee->id,auxEmployee->nombre,auxEmployee->horasTrabajadas,auxEmployee->sueldo);
			}
		}
		retorno = 0;
	}
    return retorno;
}


/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
	int retorno=-1;
	if(pArrayListEmployee!=NULL)
	{
		if(controller_menuSortEmployee(pArrayListEmployee)==0)
		{
			retorno=0;
		}
	}
	return retorno;
}

int controller_menuSortEmployee(LinkedList* pArrayListEmployee)
{
	int retorno=-1;
	int opcionMenu;

		do
		{
			printf("\n¿Como desea ordenar la lista?");
			printf("\n1) Por Nombre de forma ascendente?");
			printf("\n2) Por Nombre de forma descendente?");
			printf("\n3) Por Id de forma ascendente?");
			printf("\n4) Por Id de forma descendente?");
			printf("\nIngrese el numero de la opcion deseada:");
			getInt(&opcionMenu,1,4,3,"Ingrese la opcion que quiere modificar: ","Error");
		}while(opcionMenu!=1 && opcionMenu!=2 && opcionMenu!=3 && opcionMenu!=4);
		retorno=0;

		switch(opcionMenu)
		{
			case 1:
			if(ll_sort(pArrayListEmployee,employee_compareName,1)==0)
			{
				printf("\nLos datos se han ordenado con exito");
			}
			else
			{
				printf("\nError. Los datos no se han podido ordenadar.");
			}
			break;

			case 2:
			if(ll_sort(pArrayListEmployee,employee_compareName,0)==0)
			{
				printf("\nLos datos se han ordenado con exito");
			}
			else
			{
				printf("\nError. Los datos no se han podido ordenadar.");
			}
			break;

			case 3:
			if(ll_sort(pArrayListEmployee,employee_compareId,1)==0)
			{
				printf("\nLos datos se han ordenado con exito");
			}
			else
			{
				printf("\nError. Los datos no se han podido ordenadar.");
			}
			break;

			case 4:
			if(ll_sort(pArrayListEmployee,employee_compareId,0)==0)
			{
				printf("\nLos datos se han ordenado con exito");
			}
			else
			{
				printf("\nError. Los datos no se han podido ordenadar.");
			}
			break;
		}

	retorno=0;
	return retorno;
}



/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
	int retorno=-1;
	int i;
	int auxId;
	char auxNombre[NAME_LEN];
	int auxHorasTrabajadas;
	int auxSuledo;
	FILE* f= fopen(path, "w");
	int pLenList=ll_len(pArrayListEmployee);


	if(path!=NULL && pArrayListEmployee!=NULL)
	{
		if(f!=NULL)
		{
			fprintf(f,"Id,Nombre,HorasTrabajadas,Sueldo\n");
			for(i=0; i<pLenList; i++)
			{
				Employee* auxEmployee=ll_get(pArrayListEmployee,i);
				employee_getId(auxEmployee,&auxId);
				employee_getNombre(auxEmployee,auxNombre);
				employee_getHorasTrabajadas(auxEmployee,&auxHorasTrabajadas);
				employee_getSueldo(auxEmployee,&auxSuledo);
				fprintf(f,"%d,%s,%d,%d\n",auxId,auxNombre,auxHorasTrabajadas,auxSuledo);
			}
		}
		fclose(f);
		printf("\nLos datos se han guardado en el archivo (texto) con exito");
		retorno=0;
	}
    return retorno;
}


/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
	int retorno=-1;
	int i;
	Employee* auxEmployee=employee_new();

	if(path!=NULL && pArrayListEmployee!=NULL)
	{
		FILE* f= fopen(path, "wb");
		if(f!=NULL)
		{
			for(i=0;i<ll_len(pArrayListEmployee);i++)
			{
				auxEmployee=ll_get(pArrayListEmployee,i);
				if(auxEmployee!=NULL)
				{
					fwrite(auxEmployee,sizeof(Employee),1,f);
					//printf("Se guardo con exito");
				}
			}
			fclose(f);
			retorno=0;
			printf("\nLos datos se han guardado en el archivo (binario) con exito");


		}
	}
    return retorno;
}

void controller_exitProgram(int *option)
{
	int optionMenu;
		printf("\nUsted quiere salir del programa?");
		getInt(&optionMenu,0,1,3,"\nIngrese el numero 0 para confirmar la salida o "
								  "el numero 1 para continuar en el programa: ","Error.");

		if(optionMenu==0)
		{
			printf("Usted salió del programa.");

		}
		*option=optionMenu;

}

