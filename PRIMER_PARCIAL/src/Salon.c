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
#include "Salon.h"



#define SHOPPING 0
#define LOCAL 1
#define NOMBRESALON_LEN 128
#define DIRECCIONSALON_LEN 128
#define NOMBREJUEGO_LEN 63
#define LIBRE 1
#define OCUPADO 0


static int getIdNuevoSalones(void);




/**
 * \brief Inicializa el Array Salon.
 * \param Salon* list correspondiente a la estructura del array.
 * \param len correspondiente al tamaño del array
 * \param la funcion coloca en 1 o 0 las banderas de isEmpty.
 * \return devuelve por retorno 1 si pudo incializar, 0 si nuo pudo.
 */
int salon_initList(Salon* list, int len)
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



int salon_loadArray(Salon* list)
{
	// pide lso datos al usuario y me los deja
	// cargados dentro de la struct que recibo
	int typeAux;
	char nameAux[NOMBRESALON_LEN];
	char direccionAux[DIRECCIONSALON_LEN];
	int retorno=-1;
	if(list!=NULL)
	{
		if(getText(nameAux, NOMBRESALON_LEN, "Ingrese el nombre del salon: ", "Error", 3)==0)
		{
			if(getText(direccionAux, DIRECCIONSALON_LEN, "Ingrese el domicilio del salon: ", "Error", 3)==0)
			{
				if(getInt(&typeAux, SHOPPING, LOCAL, 3, "Ingrese el tipo: 0-Shopping, 1-Local: 0/1 ", "Error")==0)
				{
					list->tipo=typeAux;
					list->idSalon=getIdNuevoSalones();
					strncpy(list->nombre,nameAux,sizeof(list->nombre));
					strncpy(list->direccion,direccionAux,sizeof(list->direccion));
					list->isEmpty=0;
					retorno=0;
				}
			}
		}
	}
	return retorno;
}



static int getIdNuevoSalones(void)
{
	static int contador=0;
	contador ++;
	return contador;
}



/**
 * \brief Imprime un campo del Array Salon
 * \param Salon* list correspondiente a la estructura del array.
 * \param la funcion imprime un campo del array
 * \return no devuelve nada
 */
void salon_printCompleto(Salon* list)
{
	if(list->isEmpty==OCUPADO)
	{
		printf("\n	%d		%s		%s		%d	",list->idSalon, list->nombre, list->direccion, list->tipo);
		//printf("\nEl id del Salon es: %d", list->idSalon);
		//printf("\nEl nombre es: %s", list->nombre);
		//printf("\nLa dirección es: %s\n", list->direccion);
		//printf("\nEl tipo de Salon es: %d", list->tipo);
	}
}


/**
 * \brief Imprime el Array Salon
 * \param Salon* list correspondiente a la estructura del array.
 * \param len correspondiente al tamaño del array
 * \param la funcion imprime el array completo
 * \return no devuelve nada
 */
void salon_printArrayCompleto(Salon* list, int len)
{
	int i;
	if(list!=NULL)
	{
		printf("\n	IdSalon		Nombre		Direccion		Tipo	");
		for(i=0; i<len; i++)
		{
			salon_printCompleto(&list[i]);
		}
	}
}



/**
 * \brief Imprime un campo del Array Salon
 * \param Salon* list correspondiente a la estructura del array.
 * \param la funcion imprime un campo del array
 * \return no devuelve nada
 */
void salon_printAEliminar(Salon* list)
{
	if(list->isEmpty==0)
	{
		printf("\n	%d		%s		%s	",list->idSalon, list->nombre, list->direccion);
	}
}



/**
 * \brief Imprime el Array Salon
 * \param Salon* list correspondiente a la estructura del array.
 * \param len correspondiente al tamaño del array
 * \param la funcion imprime el array completo
 * \return no devuelve nada
 */
void salon_printArrayAEliminar(Salon* list, int len)
{
	int i;
	if(list!=NULL)
	{
		printf("	Id		Nombre		Direccion	");
		for(i=0; i<len; i++)
		{
			salon_printAEliminar(&list[i]);
		}
	}
}


/**
 * \brief Busca una posicion que este vacia
 * \param Salon* list correspondiente a la estructura del array.
 * \param len correspondiente al tamaño del array
 * \param pPosicionLibre correspondiente al indice de la posicion libre encontrada
 * \param la funcion busca una posicion libre y la devuelve por puntero.
 * \return devuelve por retorno 0 si pudo incializar, -1 si nuo pudo.
 */
int salon_buscarPosicionLibre(Salon* list, int len, int* pPosicionLibre)
{
	int indice;
	int retorno=-1;

	if(list!=NULL && len>0)
	{
		*pPosicionLibre=-1;
		for(indice=0; indice<len; indice++)
		{
			if(list[indice].isEmpty==LIBRE)
			{
				*pPosicionLibre=indice;
				retorno=0;
				break;
			}
		}
	}
	return retorno;
}




/**
 * \brief Busca una posicion que ocupada
 * \param Salon* list correspondiente a la estructura del array.
 * \param len correspondiente al tamaño del array
 * \param pPosicionOcupado correspondiente al indice de la posicion ocupada encontrada
 * \param la funcion busca una posicion ocupada y la devuelve por puntero.
 * \return devuelve por retorno 0 si pudo incializar, -1 si nuo pudo.
 */
int salon_buscarPosicionOcupado(Salon* list, int len, int* pPosicionOcupado)
{
	int indice;
	int retorno=-1;

	if(list!=NULL && len>0)
	{
		*pPosicionOcupado=-1;
		for(indice=0; indice<len; indice++)
		{
			if(list[indice].isEmpty==OCUPADO)
			{
				*pPosicionOcupado=indice;
				retorno=0;
				break;
			}
		}
	}
	return retorno;
}

/**
 * \brief Busca un Id que lo ingresa el usuario
 * \param Salon* list correspondiente a la estructura del array.
 * \param len correspondiente al tamaño del array
 * \param pIdBuscado correspondiente al id encontrado
 * \param la funcion busca un Id ingresado por el usuario y lo pasa por puntero
 * \return devuelve por retorno 0 si pudo incializar, -1 si nuo pudo.
 */
int salon_buscarId(Salon* list, int len, int* pIdBuscado)
{
	int indice;
	int idABuscar;
	int retorno=-1;


	if(list!=NULL && len>0)
	{
		*pIdBuscado=-1;
		for(indice=0; indice<len; indice++)
		{
			getInt(&idABuscar, 0, 8000, 3, "\nIngrese el Id de salon: ", "Error.");
			if(list[indice].isEmpty!=LIBRE)
			{
				if(list[indice].idSalon==idABuscar)
				{
					*pIdBuscado=idABuscar;
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
	return retorno;
}

/**
 * \brief Busca la posicion de Id que le pasan por parametro
 * \param Salon* list correspondiente a la estructura del array.
 * \param len correspondiente al tamaño del array
 * \param pIdBuscado correspondiente al id encontrado
 * \param pPosicionIdBuscado correspondiente a la posicion del Id encontrado
 * \param la funcion busca un Id pasado por parametro, lo encuntra y devuelve por puntero la posicion del Id
 * \return devuelve por retorno 0 si pudo incializar, -1 si nuo pudo.
 */
int salon_buscarPosicionId(Salon* list, int len, int* pPosicionIdBuscado)
{
	int indice;
	int idABuscar;
	int retorno=-1;


	if(list!=NULL && len>0)
	{
		*pPosicionIdBuscado=-1;
		for(indice=0; indice<len; indice++)
		{
			getInt(&idABuscar, 0, 8000, 3, "\nIngrese el Id: ", "Error.");
			if(list[indice].isEmpty!=LIBRE)
			{
				if(list[indice].idSalon==idABuscar)
				{
					*pPosicionIdBuscado=indice;
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
	return retorno;
}




/**
 * \brief Da de baja el array.
 * \param Salon* list correspondiente a la estructura del array.
 * \param len correspondiente al tamaño del array
 * \param idEncontrado correspondiente al id pasado por parametro
 * \param pPosicionId correspondiente a la posicion del Id pasado por parametro
 * \param la funcion recibe la un Id pasado por parametro, le pregunta al ususario que si esta seguro de querer borrar el id,
 *        ingrese de nuevo el id, compara los Id, si son iguales, da de baja el array.
 * \return devuelve por retorno 0 si pudo incializar, -1 si nuo pudo.
 */
int salon_bajaArray(Salon* list, int len, int posicionId)
{
	int indice;
	int retorno=-1;

	if(list!=NULL && len>0)
	{
		for(indice=0; indice<len; indice++)
		{
			list[posicionId].isEmpty=LIBRE;
			retorno=0;
			break;

		}
	}
	return retorno;
}




/**
 * \brief Realiza un alta
 * \param Salon* list correspondiente a la estructura del array.
 * \param len correspondiente al tamaño del array
 * \param indice correspondiente al indice del array pasado por parametro
 * \param idSalon correspondiente al Id del Salon pasado por parametro
 * \param nombre correspondiente al nombre del Salon pasado por parametro
 * \param direccion correspondiente a la direccion del salon pasado por parametro
 * \param tipo correspondiente al tipo de Salon pasado por parametro
 * \param la funcion recibe distintos parametros que se cargaran en el array.
 * \return no devuelve nada.
 */
void salon_altaForzada(Salon* list,int len, int indice,int idSalon, char* nombre, char* direccion, int tipo)
{
	if(list!=NULL && len>0 && indice<len && indice>=0)
	{
		list[indice].tipo=tipo;
		list[indice].idSalon=idSalon;
		strncpy(list[indice].nombre,nombre,sizeof(list[indice].nombre));
		strncpy(list[indice].direccion,direccion,sizeof(list[indice].direccion));
		list[indice].isEmpty=0;
	}
}






