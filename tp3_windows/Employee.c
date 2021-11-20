#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn_biblioteca.h"
#include "LinkedList.h"
#include "Employee.h"
#include "Validation.h"

Employee* employee_new(void)
{
	Employee* auxiliarEmp = (Employee*) malloc(sizeof(Employee));
	return auxiliarEmp;
}


Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr)
{
	Employee* punteroEmployee = employee_new();
	int auxid;
	int auxHorasTrabajadas;
	int auxSueldo;

	if(esNumericaInt(idStr)==0 && nombreStr!=NULL && esNumericaInt(horasTrabajadasStr)==0 && esNumericaInt(sueldoStr)==0)
	{
		auxid=atoi(idStr);
		auxHorasTrabajadas=atoi(horasTrabajadasStr);
		auxSueldo=atoi(sueldoStr);

		if(punteroEmployee!=NULL)
		{
			employee_setId(punteroEmployee,auxid);
			employee_setNombre(punteroEmployee,nombreStr);
			employee_setHorasTrabajadas(punteroEmployee,auxHorasTrabajadas);
			employee_setSueldo(punteroEmployee,auxSueldo);

		}
	}
	else
	{
		punteroEmployee=NULL;
	}
	return punteroEmployee;
}


void employee_delete(Employee* this)
{
	if(this != NULL)
	{
		free(this);
	}
}


int employee_findById(LinkedList* pList, int id)
{
	int retorno=-1;
	int i;
	int pLenList;
	if(pList!=NULL && id>=0)
	{
		pLenList=ll_len(pList);
		for(i=0;i<pLenList;i++)
		{
			Employee* aux=ll_get(pList, i);
			if(aux->id==id)
			{
				retorno=i;
				break;
			}
		}
	}
	return retorno;
}


int employee_setId(Employee* this,int id)
{
	int retorno = -1;
	if(this!=NULL && id>0)
	{
		this->id=id;
		retorno=0;
	}
	return retorno ;
}


int employee_getId(Employee* this,int* id)
{
	int retorno = -1;
	if(this!=NULL && id>0)
	{
		*id=this->id;
		retorno=0;
	}
	return retorno;
}



int employee_setNombre(Employee* this,char* nombre)
{

	int retorno = -1;
	if(this!=NULL && nombre!=NULL)
	{

		if(isValidName(nombre,NAME_LEN)==0)
		{
			strncpy(this->nombre,nombre,NAME_LEN);
			retorno=0;
		}
	}
	return retorno;
}


int employee_getNombre(Employee* this,char* nombre)
{
	int retorno = -1;
	if(this!=NULL && nombre!=NULL)
	{
		strncpy(nombre,this->nombre,NAME_LEN);
		retorno=0;
	}
	return retorno;

}

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
	int retorno = -1;
	if(this!=NULL && horasTrabajadas>=0)
	{
		this->horasTrabajadas=horasTrabajadas;
		retorno=0;
	}
	return retorno;
}

int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
	int retorno = -1;
	if(this!=NULL && horasTrabajadas>=0)
	{
		*horasTrabajadas=this->horasTrabajadas;
		retorno=0;
	}
	return retorno;
}


int employee_setSueldo(Employee* this,int sueldo)
{
	int retorno = -1;
	if(this!=NULL && sueldo>=0)
	{
		retorno=0;
		this->sueldo=sueldo;
	}
	return retorno;

}

int employee_getSueldo(Employee* this,int* sueldo)
{
	int retorno = -1;
	if(this!=NULL && sueldo>=0)
	{
		retorno=0;
		*sueldo=this->sueldo;
	}
	return retorno;
}



int employee_compareName(void* a, void* b)
{
	Employee* empleado1;
	Employee* empleado2;
	int retorno;

	empleado1=(Employee*) a;
	empleado2=(Employee*) b;

	retorno = stricmp(empleado1->nombre, empleado2->nombre);

	return retorno;

}

int employee_compareId(void* a, void* b)
{
	Employee* empleado1;
	Employee* empleado2;
	int retorno=0;

	empleado1=(Employee*) a;
	empleado2=(Employee*) b;

	if(empleado1->id > empleado2->id)
	{
		retorno=1;
	}
	else
	{
		if(empleado1->id < empleado2->id)
		{
			retorno=-1;
		}
	}
	return retorno;

}


int employee_getNextId(char* path)
{
	int retorno;
	FILE* f;
	char id[NAME_LEN];
	char nombre[NAME_LEN];
	char horas[NAME_LEN];
	char sueldo[NAME_LEN];
	int idMax=0;


	if(path!=NULL)
	{
		f= fopen(path, "r");
		if(f!=NULL)
		{
			fscanf(f,"%[^,],%[^,],%[^,],%[^\n]\n",id,nombre,horas,sueldo);
			do
			{
				if(fscanf(f,"%[^,],%[^,],%[^,],%[^\n]\n",id,nombre,horas,sueldo)==4)
				{
					if(atoi(id) > idMax)
					{
						idMax=atoi(id);
					}
				}	//printf("Lei:%s  %s  %s  %s\n",id,nombre,horas,sueldo);
			}while(feof(f)==0);
			retorno=idMax;
		}
	}
	return retorno;
}

