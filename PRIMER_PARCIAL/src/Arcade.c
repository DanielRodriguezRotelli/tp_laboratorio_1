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
#include "Arcade.h"


#define SHOPPING 0
#define LOCAL 1
#define NOMBREJUEGO_LEN 63
#define NACIONALIDAD_LEN 50
#define LIBRE 1
#define OCUPADO 0
#define MONO 0
#define STEREO 1

static int getIdNuevo(void);




/**
 * \brief Inicializa el Array Arcade.
 * \param Arcade* list correspondiente a la estructura del array.
 * \param len correspondiente al tamaño del array
 * \param la funcion coloca en 1 o 0 las banderas de isEmpty.
 * \return devuelve por retorno 1 si pudo incializar, 0 si nuo pudo.
 */
int arcade_initList(Arcade* list, int len)
{
	int indice;
	int retorno=0;

	if(list!=NULL && len>0)
	{

		for(indice=0; indice<len; indice++)
		{
			list[indice].isEmpty=LIBRE;
			retorno=1;
		}
	}
	return retorno;
}



/**
 * \brief Carga el array Arcade
 * \param Arcade* list correspondiente a la estructura del array.
 * \param IdSalon correspondiente al id del salon al que asocia la carga del arcade
 * \param la funcion pide datos al usuario y los carga en el array, recibe por parametro el id del salon
 * \return devuelve por retorno 1 si pudo incializar, 0 si nuo pudo.
 */
int arcade_loadArray(Arcade* list, int idSalon)
{
	int tipoDeSonidoAux;
	int cantidadJugadoresAux;
	int capacidadMaximaFichasAux;
	char nombreDelJuegoAux[NOMBREJUEGO_LEN];
	char nacionalidadAux[NACIONALIDAD_LEN];
	int retorno=-1;
	if(list!=NULL)
	{
		if(getText(nombreDelJuegoAux, NOMBREJUEGO_LEN, "Ingrese el nombre del juego: ", "Error", 3)==0)
		{
			if(getText(nacionalidadAux, NACIONALIDAD_LEN, "Ingrese la nacionalidad: ", "Error", 3)==0)
			{
				if(getInt(&cantidadJugadoresAux, 1, 9999999, 3, "Ingrese la cantidad de jugadores: ", "Error")==0)
				{
					if(getInt(&capacidadMaximaFichasAux, 1, 999999999, 3, "Ingrese la capacidad maxima de fichas: ", "Error")==0)
					{
						if(getInt(&tipoDeSonidoAux,MONO,STEREO,3, "Ingrese el tipo de sonido: 0-Mono, 1-Stereo: 0/1 ", "Error")==0)
						{
							list->cantidadJugadores=cantidadJugadoresAux;
							list->capacidadMaximaFichas=capacidadMaximaFichasAux;
							list->idArcade=getIdNuevo();
							list->idSalon=idSalon;
							list->tipoDeSonido=tipoDeSonidoAux;
							strncpy(list->nombreDelJuego,nombreDelJuegoAux,NOMBREJUEGO_LEN);
							strncpy(list->nacionalidad,nacionalidadAux,NACIONALIDAD_LEN);
							list->isEmpty=0;
							retorno=0;
						}
					}
				}
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



/**
 * \brief Imprime un campo del Array Arcade
 * \param Arcade* list correspondiente a la estructura del array.
 * \param la funcion imprime un campo del array
 * \return no devuelve nada
 */
void arcade_printCompleto(Arcade* list)
{
	if(list->isEmpty==OCUPADO)
	{
		printf("\n	%d		%s		%s		%d		%d		%d		%d	",list->idArcade, list->nombreDelJuego, list->nacionalidad, list->cantidadJugadores, list->capacidadMaximaFichas, list->tipoDeSonido, list->idSalon);
		//printf("\nEl id del Salon es: %d", list->idSalon);
		//printf("\nEl nombre es: %s", list->nombre);
		//printf("\nLa dirección es: %s\n", list->direccion);
		//printf("\nEl tipo de Salon es: %d", list->tipo);
	}
}


/**
 * \brief Imprime el Array Arcade
 * \param Arcade* list correspondiente a la estructura del array.
 * \param len correspondiente al tamaño del array
 * \param la funcion imprime el array completo
 * \return no devuelve nada
 */
void arcade_printArrayCompleto(Arcade* list, int len)
{
	int i;
	if(list!=NULL)
	{
		printf("\n	Id Arcade		Nombre de Juego		Nacionalidad		Cant.Jugadores		Capacidad Fichas		Tipo de Sonido		IdSalon	");
		for(i=0; i<len; i++)
		{
			arcade_printCompleto(&list[i]);
		}
	}
}


/**
 * \brief Busca una posicion que este vacia
 * \param Arcade* list correspondiente a la estructura del array.
 * \param len correspondiente al tamaño del array
 * \param pPosicionLibre correspondiente al indice de la posicion libre encontrada
 * \param la funcion busca una posicion libre y la devuelve por puntero.
 * \return devuelve por retorno 0 si pudo incializar, -1 si nuo pudo.
 */
int arcade_buscarPosicionLibre(Arcade* list, int len, int* pPosicionLibre)
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
 * \param Arcade* list correspondiente a la estructura del array.
 * \param len correspondiente al tamaño del array
 * \param pPosicionOcupado correspondiente al indice de la posicion ocupada encontrada
 * \param la funcion busca una posicion ocupada y la devuelve por puntero.
 * \return devuelve por retorno 0 si pudo incializar, -1 si nuo pudo.
 */
int arcade_buscarPosicionOcupado(Arcade* list, int len, int* pPosicionOcupado)
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
 * \param Arcade* list correspondiente a la estructura del array.
 * \param len correspondiente al tamaño del array
 * \param pIdBuscado correspondiente al id encontrado
 * \param la funcion busca un Id ingresado por el usuario y lo pasa por puntero
 * \return devuelve por retorno 0 si pudo incializar, -1 si nuo pudo.
 */
int arcade_buscarId(Arcade* list, int len, int* pIdBuscado)
{
	int indice;
	int idABuscar;
	int retorno=-1;


	if(list!=NULL && len>0)
	{
		*pIdBuscado=-1;
		for(indice=0; indice<len; indice++)
		{
			getInt(&idABuscar, 0, 8000, 3, "\nIngrese el Id de Arcade: ", "Error.");
			if(list[indice].isEmpty!=LIBRE)
			{
				if(list[indice].idArcade==idABuscar)
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
 * \param Arcade* list correspondiente a la estructura del array.
 * \param len correspondiente al tamaño del array
 * \param pIdBuscado correspondiente al id encontrado
 * \param pPosicionIdBuscado correspondiente a la posicion del Id encontrado
 * \param la funcion busca un Id pasado por parametro, lo encuntra y devuelve por puntero la posicion del Id
 * \return devuelve por retorno 0 si pudo incializar, -1 si nuo pudo.
 */
int arcade_buscarPosicionId(Arcade* list, int len, int IdEncontrado, int* pPosicionIdBuscado)
{
	int indice;
	int retorno=-1;


	if(list!=NULL && len>0)
	{
		*pPosicionIdBuscado=-1;
		for(indice=0; indice<len; indice++)
		{
			if(list[indice].isEmpty!=LIBRE)
			{
				if(list[indice].idArcade==IdEncontrado)
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
 * \brief Modifica los campos del array
 * \param Arcade* list correspondiente a la estructura del array.
 * \param len correspondiente al tamaño del array
 * \param pPosicionId correspondiente a la posicion del Id pasado por parametro
 * \param la funcion recibe la posicion de un Id pasado por parametro, lo encuentra y modifica los otros campos del array.
 * \return devuelve por retorno 0 si pudo incializar, -1 si nuo pudo.
 */
int arcade_modificarArray(Arcade* list, int len, int posicionId)
{
	char nombreJuegoAux[NOMBREJUEGO_LEN];
	int cantJugadoresAux;
	int retorno=-1;
	int opcionesDeMenu;

	if(list!=NULL && len>0)
	{
		do
		{
			do
			{
				getInt(&opcionesDeMenu,1,5, 3, "Que desea realizar? \n1)Modificar Cantidad de Jugadores, \n2)Modificar Nombre del Juego, \n3)Volver al Menu Principal. \nIngrese la opcion que desea modificar: ", "Error");
			}while(opcionesDeMenu!=1 && opcionesDeMenu!=2 && opcionesDeMenu!=3);

				switch(opcionesDeMenu)
				{
					case 1:
					getInt(&cantJugadoresAux, 0, 99999999, 3, "\nIngrese la cantidad de Jugadores: ", "Error");
					list[posicionId].cantidadJugadores=cantJugadoresAux;
					break;

					case 2:
					if(game_imprimirJuegos(list,len)==0)
					{
						getText(nombreJuegoAux, NOMBREJUEGO_LEN, "\nIngrese el nombre del juego: ", "Error", 3);
						strncpy(list[posicionId].nombreDelJuego,nombreJuegoAux,sizeof(list[posicionId].nombreDelJuego));
					}
					break;

					case 3:
					puts("Usted salio del menu de modificar.");
					break;
				}
				retorno=0;

		}while(opcionesDeMenu!=3);
	}
	return retorno;
}




/**
 * \brief Da de baja el array.
 * \param Arcade* list correspondiente a la estructura del array.
 * \param len correspondiente al tamaño del array
 * \param idEncontrado correspondiente al id pasado por parametro
 * \param pPosicionId correspondiente a la posicion del Id pasado por parametro
 * \param la funcion recibe la un Id pasado por parametro, le pregunta al ususario que si esta seguro de querer borrar el id,
 *        ingrese de nuevo el id, compara los Id, si son iguales, da de baja el array.
 * \return devuelve por retorno 0 si pudo incializar, -1 si nuo pudo.
 */
int arcade_bajaArray(Arcade* list, int len,int idEncontrado, int posicionId)
{
	int indice;
	int idReconfirmado;
	int retorno=-1;

	if(list!=NULL && len>0)
	{
		getInt(&idReconfirmado, 1, 999999999, 3, "\nReconfirmacionde baja. \nEsta seguro que quierede dar de baja el id? Reingrese el id: ", "Error");
		for(indice=0; indice<len; indice++)
		{
			if(idEncontrado==idReconfirmado)
			{
				list[posicionId].isEmpty=LIBRE;
				retorno=0;
				break;
			}
		}
	}
	return retorno;
}



/**
 * \brief Realiza un alta
 * \param Arcade* list correspondiente a la estructura del array.
 * \param len correspondiente al tamaño del array
 * \param indice correspondiente al indice del array pasado por parametro
 * \param idArcade correspondiente al Id del Arcade pasado por parametro
 * \param nombreDelJuego correspondiente al nombre del Juego del Arcade pasado por parametro
 * \param Nacionalidad correspondiente a la nacionalidad del Arcade pasado por parametro
 * \param tipoDeSonido correspondiente al tipo de Sonido del Arcade pasado por parametro
 * \param capacidadMaximaFichas correspondiente a la capacidad Maxima de Fichas del Arcade pasado por parametro
 * \param cantidadJugadores correspondiente a la cantidad de jugadores del Arcade pasado por parametro
 * \param la funcion recibe distintos parametros que se cargaran en el array.
 * \return no devuelve nada.
 */
void arcade_altaForzada(Arcade* list,int len, int indice,int idArcade, char* nombreDelJuego, char* nacionalidad, int tipoDeSonido, int capacMaximaFichas,int cantidadJugadores ,int idSalon)
{
	if(list!=NULL && len>0 && indice<len && indice>=0)
	{
		list[indice].idArcade=idArcade;
		list[indice].idSalon=idSalon;
		list[indice].cantidadJugadores=cantidadJugadores;
		list[indice].capacidadMaximaFichas=capacMaximaFichas;
		list[indice].tipoDeSonido=tipoDeSonido;
		strncpy(list[indice].nombreDelJuego,nombreDelJuego,sizeof(list[indice].nombreDelJuego));
		strncpy(list[indice].nacionalidad,nacionalidad,sizeof(list[indice].nacionalidad));
		list[indice].isEmpty=0;
	}
}






