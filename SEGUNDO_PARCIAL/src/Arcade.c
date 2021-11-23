/*
 * Arcade.c
 *
 *  Created on: 20 nov. 2021
 *      Author: Aye
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn_biblioteca.h"
#include "LinkedList.h"
#include "Validation.h"
#include "Arcade.h"




/** \brief Crea un nuevo Arcade en memoria de manera dinamica
 *  \param void
 *  \return Arcade* Retorna el puntero al espacio reservado
 */
Arcade* arcade_new(void)
{
	Arcade* auxiliarArcade = (Arcade*) malloc(sizeof(Arcade));
	return auxiliarArcade;

}


/** \brief Ingresa datos a los campos del Arcade pasados por parametros
 *  \param char* idStr Id del arcade
 *  \param char* sonidoStr Tipo de sonido del arcade
 *  \param char* cantidadJugadoresStr  Cantidad de jugadores que tiene el juego del arcade
 *  \param char* capacidadFichasStr  Capacidad maxima de fichas del arcade
 *  \param char* nacionalidadStr Pais de origen del arcade
 *  \param char* nombreSalonStr Nombre del salon donde se ubica el arcade
 *  \param char* nombreJuegoStr nombre del juegos que contiene el arcade
 *  \return Arcade* Retorna el puntero del arcade donde fueron cargados los campos
 */
Arcade* arcade_newParametros(char* idStr,char* sonidoStr,char* cantidadJugadoresStr, char* capacidadFichasStr, char* nacionalidadStr, char* nombreSalonStr, char* nombreJuegoStr)
{
	Arcade* punteroArcade = arcade_new();
	int auxId;
	int auxCantidadJugadores;
	int auxCapacidadFichas;

	if(esNumericaInt(idStr)==0 && sonidoStr!=NULL && esNumericaInt(cantidadJugadoresStr)==0 && esNumericaInt(capacidadFichasStr)==0 && nacionalidadStr!=NULL && nombreSalonStr!=NULL && nombreJuegoStr!=NULL)
	{
		auxId=atoi(idStr);
		auxCantidadJugadores=atoi(cantidadJugadoresStr);
		auxCapacidadFichas=atoi(capacidadFichasStr);

		if(punteroArcade!=NULL)
		{
			arcade_setId(punteroArcade,auxId);
			arcade_setSonidoChar(punteroArcade,sonidoStr);
			arcade_setCantidadJugadores(punteroArcade,auxCantidadJugadores);
			arcade_setCapacidadFichas(punteroArcade,auxCapacidadFichas);
			arcade_setNacionalidad(punteroArcade,nacionalidadStr);
			arcade_setNombreSalon(punteroArcade,nombreSalonStr);
			arcade_setNombreJuego(punteroArcade,nombreJuegoStr);
		}
	}
	else
	{
		punteroArcade=NULL;
	}
	return punteroArcade;
}


/** \brief Elimina un nuevo Arcade en memoria de manera dinamica
 *  \param Arcade* this puntero al elemento
 *  \return void
 */
void arcade_delete(Arcade* this)
{
	if(this != NULL)
	{
		free(this);
	}
}



/** \brief Encuentra un Arcade por su Id en memoria de manera dinamica
 *  \param LinkedList* pArrayListArcade puntero linkedList
 *  \param int id Id del arcade que se busca.
 *  \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( i) Index: el indice del Id del arcade

 */
int arcade_findById(LinkedList* pArrayListArcade, int id)
{
	int retorno=-1;
	int i;
	int pLenList;
	if(pArrayListArcade!=NULL && id>=0)
	{
		pLenList=ll_len(pArrayListArcade);
		for(i=0;i<pLenList;i++)
		{
			Arcade* aux=ll_get(pArrayListArcade, i);
			if(aux->id==id)
			{
				retorno=i;
				break;
			}
		}
	}
	return retorno;
}



/** \brief Setea el Id un Arcade pasado por parametro
 *  \param Arcade* this puntero al elemento
 *  \param int id Id del arcade que se quiere setear
 *  \return int Retorna  (-1) Error: si el puntero a la lista es NULL o si el id es menor a 0
                        (0) si se pudo setar correctamente.

 */
int arcade_setId(Arcade* this,int id)
{
	int retorno = -1;
	if(this!=NULL && id>0)
	{
		this->id=id;
		retorno=0;
	}
	return retorno ;
}



/** \brief Pide el Id un Arcade pasado por referencia
 *  \param Arcade* this puntero al elemento
 *  \param int id Id del arcade que se quiere obtener
 *  \return int Retorna  (-1) Error: si el puntero a la lista es NULL o si el id es menor a 0
                        (0) si se pudo obtener correctamente.

 */
int arcade_getId(Arcade* this,int* id)
{
	int retorno = -1;
	if(this!=NULL && id>0)
	{
		*id=this->id;
		retorno=0;
	}
	return retorno;
}



/** \brief Setea el Id un Arcade pasado por parametro
 *  \param Arcade* this puntero al elemento
 *  \param char* id Id del arcade que se quiere setear
 *  \return int Retorna  (-1) Error: si el puntero a la lista o la cadena char* es NULL
                        (0) si se pudo setar correctamente.

 */
int arcade_setSonidoChar(Arcade* this,char* sonido)
{
	int retorno = -1;
	int auxSonido;
	if(this!=NULL && sonido!=NULL)
	{
		if(stricmp(sonido,"STEREO")==0)
		{
			auxSonido=1;
		}
		if(stricmp(sonido,"MONO")==0)
		{
			auxSonido=0;
		}
		this->tipoDeSonido=auxSonido;
		retorno=0;
	}
	return retorno ;
}



/** \brief Pide el Id un Arcade pasado por referencia
 *  \param Arcade* this puntero al elemento
 *  \param int id Id del arcade que se quiere obtener
 *  \return int Retorna  (-1) Error: si el puntero a la lista o la cadena char* es NULL
                        (0) si se pudo obtener correctamente.

 */
int arcade_getSonidoChar(Arcade* this,char* sonido)
{
	int retorno = -1;
	//char aux1[NAME_LEN]="STEREO";
	//char aux2[NAME_LEN]="MONO";
	if(this!=NULL && sonido!=NULL)
	{
		if(this->tipoDeSonido==0)
		{
			strncpy(sonido,"STEREO",NAME_LEN);
		}
		if(this->tipoDeSonido==1)
		{
			strncpy(sonido,"MONO",NAME_LEN);
		}
		retorno=0;
	}
	return retorno ;
}



/** \brief Setea el tipo de sonido un Arcade pasado por parametro
 *  \param Arcade* this puntero al elemento
 *  \param int sonido Tipo de Sonido del arcade que se quiere setear
 *  \return int Retorna  (-1) Error: si el puntero a la lista es NULL o si el int sonido no es 0 o 1
                        (0) si se pudo setar correctamente.

 */
int arcade_setSonidoInt(Arcade* this,int sonido)
{
	int retorno = -1;
	if(this!=NULL && (sonido==0 || sonido==1))
	{
		this->tipoDeSonido=sonido;
		retorno=0;
	}
	return retorno ;
}


/** \brief Pide el tipo de sonido un Arcade pasado por referencia
 *  \param Arcade* this puntero al elemento
 *  \param int sonido Tipo de sonido del arcade que se quiere obtener
 *  \return int Retorna  (-1) Error: si el puntero a la lista es NULL o si el int sonido no es 0 o 1
                        (0) si se pudo obtener correctamente.
 */
int arcade_getSonidoInt(Arcade* this,int* sonido)
{
	int retorno = -1;
	if(this!=NULL && (*sonido==0 || *sonido==1))
	{
		*sonido=this->tipoDeSonido;
		retorno=0;
	}
	return retorno;
}



/** \brief Setea el la cantidad de jugadores que tiene el juego dentro de un Arcade pasado por parametro
 *  \param Arcade* this puntero al elemento
 *  \param int cantidadJugadores Cantidad de jugadores del juego del arcade que se quiere setear
 *  \return int Retorna  (-1) Error: si el puntero a la lista es NULL o si la cantidad no es mayor a 0
                        (0) si se pudo setar correctamente.
 */
int arcade_setCantidadJugadores(Arcade* this,int cantidadJugadores)
{
	int retorno = -1;
	if(this!=NULL && cantidadJugadores>0)
	{
		this->cantidadDeJugadores=cantidadJugadores;
		retorno=0;
	}
	return retorno;
}



/** \brief Pide la cantidad de jugadores del juego dentro un Arcade pasado por referencia
 *  \param Arcade* this puntero al elemento
 *  \param int cantidadJugadores Cantidad de jugadores del juego del arcade que se quiere obtener
 *  \return int Retorna  (-1) Error: si el puntero a la lista es NULL o si la cantidad no es mayor a 0
                        (0) si se pudo obtener correctamente.
 */
int arcade_getCantidadJugadores(Arcade* this,int* cantidadJugadores)
{
	int retorno = -1;
	if(this!=NULL && cantidadJugadores>0)
	{
		*cantidadJugadores=this->cantidadDeJugadores;
		retorno=0;
	}
	return retorno;
}


/** \brief Setea la capacidad maxima de fichas que tiene un Arcade pasado por parametro
 *  \param Arcade* this puntero al elemento
 *  \param int capacidadFichas Capacidad maxima de fichas del arcade que se quiere setear
 *  \return int Retorna  (-1) Error: si el puntero a la lista es NULL o si la cantidad no es mayor a 0
                        (0) si se pudo setar correctamente.
 */
int arcade_setCapacidadFichas(Arcade* this,int capacidadFichas)
{
	int retorno = -1;
	if(this!=NULL && capacidadFichas>0)
	{
		this->capacidadDeFichas=capacidadFichas;
		retorno=0;
	}
	return retorno;
}



/** \brief Pide la capacidad maxima de fichas del Arcade pasado por referencia
 *  \param Arcade* this puntero al elemento
 *  \param int capacidadFichas Canpacidad maxima de fichas del arcade que se quiere obtener
 *  \return int Retorna  (-1) Error: si el puntero a la lista es NULL o si la cantidad no es mayor a 0
                        (0) si se pudo obtener correctamente.
 */
int arcade_getCapacidadFichas(Arcade* this,int* capacidadFichas)
{
	int retorno = -1;
	if(this!=NULL && capacidadFichas>0)
	{
		*capacidadFichas=this->capacidadDeFichas;
		retorno=0;
	}
	return retorno;
}



/** \brief Setea la nacionalidad del Arcade pasado por parametro
 *  \param Arcade* this puntero al elemento
 *  \param int nacionalidad Pais de origen del arcade que se quiere setear
 *  \return int Retorna  (-1) Error: si el puntero a la lista y el char* nacionalidad es NULL
                        (0) si se pudo setar correctamente.
 */
int arcade_setNacionalidad(Arcade* this,char* nacionalidad)
{

	int retorno = -1;
	if(this!=NULL && nacionalidad!=NULL)
	{
		if(isValidName(nacionalidad,NAME_LEN)==0)
		{
			strncpy(this->nacionalidad,nacionalidad,NAME_LEN);
			retorno=0;
		}
	}
	return retorno;
}



/** \brief Pide la nacionalidad del Arcade pasado por referencia
 *  \param Arcade* this puntero al elemento
 *  \param int nacionalidad Pais de origen del arcade que se quiere obtener
 *  \return int Retorna  (-1) Error: si el puntero a la lista y el char* nacionalidad es NULL
                        (0) si se pudo obtener correctamente.
 */
int arcade_getNacionalidad(Arcade* this,char* nacionalidad)
{
	int retorno = -1;
	if(this!=NULL && nacionalidad!=NULL)
	{
		strncpy(nacionalidad,this->nacionalidad,NAME_LEN);
		retorno=0;
	}
	return retorno;
}



/** \brief Setea el nombre del salon donde se encuentra el Arcade pasado por parametro
 *  \param Arcade* this puntero al elemento
 *  \param int nombreSalon Nombre del Salon donde se ubica el arcade que se quiere setear
 *  \return int Retorna  (-1) Error: si el puntero a la lista y el char* nombreSalon es NULL
                        (0) si se pudo setar correctamente.
 */
int arcade_setNombreSalon(Arcade* this,char* nombreSalon)
{
	int retorno = -1;
	if(this!=NULL && nombreSalon!=NULL)
	{

		if(isValidName(nombreSalon,NAME_LEN)==0)
		{
			strncpy(this->nombreDeSalon,nombreSalon,NAME_LEN);
			retorno=0;
		}
	}
	return retorno;
}



/** \brief Pide el nombre del salon donde se encuentra el Arcade pasado por referencia
 *  \param Arcade* this puntero al elemento
 *  \param int nombreSalon Nombre del salon donde se ubica del arcade que se quiere obtener
 *  \return int Retorna  (-1) Error: si el puntero a la lista y el char* nombreSalon es NULL
                        (0) si se pudo obtener correctamente.
 */
int arcade_getNombreSalon(Arcade* this,char* nombreSalon)
{
	int retorno = -1;
	if(this!=NULL && nombreSalon!=NULL)
	{
		strncpy(nombreSalon,this->nombreDeSalon,NAME_LEN);
		retorno=0;
	}
	return retorno;
}



/** \brief Setea el nombre del juego que contiene el Arcade pasado por parametro
 *  \param Arcade* this puntero al elemento
 *  \param int nombreJuego Nombre del juegos que contiene el arcade que se quiere setear
 *  \return int Retorna  (-1) Error: si el puntero a la lista y el char* nombreJuego es NULL
                        (0) si se pudo setar correctamente.
 */
int arcade_setNombreJuego(Arcade* this,char* nombreJuego)
{

	int retorno = -1;
	if(this!=NULL && nombreJuego!=NULL)
	{

		if(isValidName(nombreJuego,NAME_LEN)==0)
		{
			strncpy(this->nombreDeJuego,nombreJuego,NAME_LEN);
			retorno=0;
		}
	}
	return retorno;
}



/** \brief Pide el nombre del juego que contiene el Arcade pasado por referencia
 *  \param Arcade* this puntero al elemento
 *  \param int nombreJuego Nombre del juegos que contiene el arcade que se quiere obtener
 *  \return int Retorna  (-1) Error: si el puntero a la lista y el char* nombreJuego es NULL
                        (0) si se pudo obtener correctamente.
 */
int arcade_getNombreJuego(Arcade* this,char* nombreJuego)
{
	int retorno = -1;
	if(this!=NULL && nombreJuego!=NULL)
	{
		strncpy(nombreJuego,this->nombreDeJuego,NAME_LEN);
		retorno=0;
	}
	return retorno;
}



/** \brief Compara 2 campos nombre del Arcade pasado por referencia
 *  \param Arcade* this puntero al elemento
 *  \param void*a campo a
 *  \param void*b campo b
 *  \return int Retorna (0) si los dos campos son iguales.
 */
int arcade_compareName(void* a, void* b)
{
	Arcade* arcade1;
	Arcade* arcade2;
	int retorno;

	arcade1=(Arcade*) a;
	arcade2=(Arcade*) b;

	retorno = stricmp(arcade1->nombreDeJuego, arcade2->nombreDeJuego);
	return retorno;
}



/** \brief Compara 2 Id del Arcade pasado por referencia
 *  \param Arcade* this puntero al elemento
 *  \param void*a campo a
 *  \param void*b campo b
 *  \return int Retorna (0) si los dos campos son iguales.
 *  					(1) si campo a es mayor a campo b
 *  					(-1) si campo a es menor a campo b
 */
int arcade_compareId(void* a, void* b)
{
	Arcade* arcade1;
	Arcade* arcade2;
	int retorno=0;

	arcade1=(Arcade*) a;
	arcade2=(Arcade*) b;

	if(arcade1->id > arcade2->id)
	{
		retorno=1;
	}
	else
	{
		if(arcade1->id < arcade2->id)
		{
			retorno=-1;
		}
	}
	return retorno;
}



/** \brief Encuentra el id maximo del archivo
 *  \param char* path Archivo
 *  \return int Retorna (-1) si path es NULL
 *  					(int) devuelve el id maximo encontrado
 */
int arcade_getIdMax(char* path)
{
	int retorno=-1;
	FILE* f;
	char id[NAME_LEN];
	char sonido[NAME_LEN];
	char cantJugadores[NAME_LEN];
	char capcFichas[NAME_LEN];
	char nombreSalon[NAME_LEN];
	char nombreJuegos[NAME_LEN];
	char nacionalidad[NAME_LEN];
	int idMax=0;


	if(path!=NULL)
	{
		f= fopen(path, "r");
		if(f!=NULL)
		{
			fscanf(f,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",id,nacionalidad,sonido,cantJugadores,capcFichas,nombreSalon,nombreJuegos);
			do
			{
				if(fscanf(f,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",id,nacionalidad,sonido,cantJugadores,capcFichas,nombreSalon,nombreJuegos)==7)
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



/** \brief Imprime todos los campos de un elemente tipo Arcade
 *  \param void* pAuxiliar
 *  \return void
 */
void arcade_printArcade(void* pAuxiliar)
{
	if(pAuxiliar!=NULL)
	{
		Arcade* auxArcade = (Arcade*) pAuxiliar;
		printf("%d,%s,%d,%d,%d,%s,%s\n",auxArcade->id,auxArcade->nacionalidad,auxArcade->tipoDeSonido,auxArcade->cantidadDeJugadores,auxArcade->capacidadDeFichas,auxArcade->nombreDeSalon,auxArcade->nombreDeJuego);
	}
}




/** \brief Duplica la cantidad de capacidad maxima de fichas del arcade
 *  \param void* pAuxiliar
 *  \return void
 */
void arcade_newCoinsArcade(void* pAuxiliar)
{
	if(pAuxiliar!=NULL)
	{
		Arcade* auxArcade = (Arcade*) pAuxiliar;
		if(auxArcade->capacidadDeFichas>0)
		{
			auxArcade->capacidadDeFichas = (auxArcade->capacidadDeFichas*2);
			//printf("%d,%s,%d,%d,%d,%s,%s\n",auxArcade->id,auxArcade->nacionalidad,auxArcade->tipoDeSonido,auxArcade->cantidadDeJugadores,auxArcade->capacidadDeFichas,auxArcade->nombreDeSalon,auxArcade->nombreDeJuego);
		}

	}
}



/** \brief Chequea si la cantidad de jugadores del arcades es mayor a 1
 *  \param void* pAuxiliar
 *  \return int Retorna (0) si es mayor a 1
 *  					(1) si no es mayor a 1
 *  					(-1) si pAuxiliar es NULL
 */
int arcade_isMultiplayer(void* pAuxiliar)
{
	int retorno=-1;

	if(pAuxiliar!=NULL)
	{
		Arcade* auxArcade = (Arcade*) pAuxiliar;
		if(auxArcade->cantidadDeJugadores>1)
		{
			retorno=0;
		}
		else
		{
			retorno=1;
		}
	}
	return retorno;
}



/** \brief Imprime solo los nombres de los juegos en arcades sin repetir
 *  \param LinkedList* pArrayListArcade puntero linkedList
 *  \return int Retorna (0) si pudo imprimir la lista.
 *  					(-1) si LinkedList* pArrayListArcade es NULL y si el tamaño de la lista no es mayor a0
 */
int arcade_printListGames(LinkedList* pArrayListArcade)
{
    int returnAux =-1;
    int i;
    Arcade* auxA;
    Arcade* auxB;
    char auxNombreJuego[NAME_LEN];

    if(pArrayListArcade!=NULL && ll_len(pArrayListArcade)>0)
    {
		for(i=0; i<(ll_len(pArrayListArcade)-1); i++)
		{
			auxA=ll_get(pArrayListArcade,i);
			auxB=ll_get(pArrayListArcade,i+1);
			if(arcade_compareName(auxA,auxB)!=0)
			{
				arcade_getNombreJuego(auxA, auxNombreJuego);
				printf("\n Juego: %s",auxNombreJuego);
			}
		}
    	returnAux=0;
    }
    return returnAux;
}




