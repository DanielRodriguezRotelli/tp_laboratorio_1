#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Arcade.h"
#include "utn_biblioteca.h"
#include "parser.h"
#include "Controller.h"





/** \brief Muestra el menu principar y pide que elija la opcion deseada .
 * \param int* optionMenu corresponde a la opcion elegida pasada por referencia
 * \param pArrayListEmployee LinkedList* puntero a la lista
 * \return void devuelve por referencia la opcion elegida
 */
void controller_menu(int* optionMenu)
{
	int option;

		do {
			getInt(&option, 1, 11, 3, "\n\n--MENU PRINCIPAL-- "
					"\n1) Cargar los datos de los Arcades desde el archivo Arcades.csv . "
					"\n2) Incorporar Arcade. "
					"\n3) Modificar Arcade. "
					"\n4) Eliminar Arcade. "
					"\n5) Imprimir Arcade, ordenados por nombre de juego. "
					"\n6) Generar archivo de juegos. "
					"\n7) Generar un archivo con arcades Multijugador (mas de 1). "
					"\n8) Actualizar la cantidad de fichas. "
					"\n9) Salir del Menu Principal"
					"\nIngrese la opcion deseada: ", "Error");
		} while (option != 1 && option != 2 && option != 3 && option != 4
				&& option != 5 && option != 6 && option != 7 && option != 8
				&& option != 9);
		*optionMenu = option;
}


/** \brief Carga los datos del arcade leidos desde el archivo .
 * \param path char* archivo
 * \param pArrayListEmployee LinkedList* puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la listas y el puntero a path es NULL
                        ( 0) Si ok
 */
int controller_loadFromText(char* path , LinkedList* pArrayListArcade)
{
	int retorno=-1;
	FILE* f;

	if(path!=NULL && pArrayListArcade!=NULL)
	{
		f= fopen(path, "r");
		if(f!=NULL)
		{
			if(parser_ArcadesFromText(f,pArrayListArcade)==0)
			{
				printf("\nLos datos se han cargado con exito");
				retorno=0;
			}
		}
	}
	return retorno;
}



/** \brief Carga los datos del arcade manualmente .
 * \param pArrayListEmployee LinkedList* puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
                        ( 0) Si ok
 */
int controller_addArcade(LinkedList* pArrayListArcade)
{
	int retorno=-1;
	int auxId=0;
	static int proximoId=1;

	int auxSonido;
	int auxCantJugadores;
	int auxCapcFichas;
	char auxNombreSalon[NAME_LEN];
	char auxNombreJuegos[NAME_LEN];
	char auxNacionalidad[NAME_LEN];

	if(pArrayListArcade!=NULL)
	{
		auxId=arcade_getIdMax("arcades.csv") + proximoId;
		proximoId++;
		//printf("\nId: %d\n",auxId);
		//printf("\nproximo Id: %d\n",proximoId);
		if(getInt(&auxSonido,0,1, 3, "Ingrese el tipo de Sonido: '0' si es MONO, '1' si es STEREO: ", "Error.")==0)
		{
			if(getInt(&auxCantJugadores, 1, 9999999, 3, "Ingrese la cantidad de Jugadores del arcade: ", "Error.")==0)
			{
				if(getInt(&auxCapcFichas, 1, 9999999, 3, "Ingrese la capacidad máxima de fichas del arcade: ", "Error.")==0)
				{
					if(getText(auxNacionalidad,NAME_LEN,"Ingrese la nacionalidad del arcade: ", "Error.", 3)==0)
					{
						if(getText(auxNombreSalon,NAME_LEN,"Ingrese el nombre del Salón donde se ubicará el arcade: ", "Error.", 3)==0)
						{
							if(getText(auxNombreJuegos,NAME_LEN,"Ingrese el nombre del juego que contiene el arcade: ", "Error.", 3)==0)
							{
								Arcade* auxArcade=arcade_new();
								if(auxArcade!=NULL)
								{
									if((arcade_setId(auxArcade,auxId)==0) &&
									   (arcade_setSonidoInt(auxArcade,auxSonido)==0) &&
									   (arcade_setCantidadJugadores(auxArcade,auxCantJugadores)==0) &&
									   (arcade_setCapacidadFichas(auxArcade,auxCapcFichas)==0) &&
									   (arcade_setNacionalidad(auxArcade,auxNacionalidad)==0) &&
									   (arcade_setNombreSalon(auxArcade,auxNombreSalon)==0) &&
									   (arcade_setNombreJuego(auxArcade,auxNombreJuegos)==0))
									{
										ll_add(pArrayListArcade,auxArcade);
										printf("\nSe genero el Id: %d", auxId);
										retorno=0;
									}
								}
							}
						}
					}
				}
			}
		}
	}
    return retorno;
}



/** \brief Modifica datos del arcade
 * \param pArrayListEmployee LinkedList*
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
                        ( 0) Si ok
 */
int controller_editArcade(LinkedList* pArrayListArcade)
{
	int retorno=-1;
	int index;
	Arcade* auxArcade;
	int auxId;

	if(pArrayListArcade!= NULL)
	{
		controller_ListArcade(pArrayListArcade);
		if(getInt(&auxId,1,999999,3,"\nIngrese el Id del arcade a modificar: ","Error")==0)
		{
			index=arcade_findById(pArrayListArcade,auxId);
			if(index>=0)
			{
				auxArcade= ll_get(pArrayListArcade, index);
				if(auxArcade!=NULL)
				{
					if(controller_menuEditArcade(pArrayListArcade,auxArcade)==0)
					{
						printf("\nLa modificacion se ha realizado con exito.");
						printf("\nLos datos nuevos son:\n");
						printf("\nId,Nacionalidad,Tipo_sonido,Cant_jug,Fichas_max,Salon,Game\n");
						printf("%d,%s,%d,%d,%d,%s,%s\n",auxArcade->id,auxArcade->nacionalidad,auxArcade->tipoDeSonido,auxArcade->cantidadDeJugadores,auxArcade->capacidadDeFichas,auxArcade->nombreDeSalon,auxArcade->nombreDeJuego);
						//controller_printEmployee(pArrayListEmployee, auxId);
						retorno=0;
					}
				}
			}
		}
	}
    return retorno;
}



/** \brief Menu de Modificacion datos del arcade
 * \param pArrayListEmployee LinkedList*
 * \return int Retorna  (-1) Error: si los punteros a la listas son NULL
                        ( 0) Si ok
 */
int controller_menuEditArcade(LinkedList* pArrayListArcade, Arcade* auxArcade)
{
	int retorno=-1;
	int opcionMenu;
	char auxNombreJuego[128];
	int auxCantidadJugadores;
	if(pArrayListArcade!= NULL && auxArcade!=NULL)
	{
		do
		{
			do
			{
				printf("\n---Menu Modificacion---");
				printf("\n1) Cantidad de jugadores.");
				printf("\n2) Nombre del juego.");
				printf("\n3) Salir del menu modificacion.");
				getInt(&opcionMenu,1,3,3,"Ingrese la opcion que quiere modificar: ","Error");
			}while(opcionMenu!=1 && opcionMenu!=2 && opcionMenu!=3);
			retorno=0;

			switch(opcionMenu)
			{
				case 1:
				if(getInt(&auxCantidadJugadores,1,99999999,3,"\nIngrese la nueva cantidad de jugadores: ", "Error")==0)
				{
					if(arcade_setCantidadJugadores(auxArcade,auxCantidadJugadores)==0)
					{
						printf("\nLa nueva cantidad de jugadores es: %d\n",auxCantidadJugadores);
					}
				}
				else
				{
					printf("\nError. No se pudo modificar las horas trabajadas.");
				}
				break;

				case 2:
				if(controller_printListGames(pArrayListArcade)==0)
				{
					if(getText(auxNombreJuego,NAME_LEN,"\nIngrese el nuevo nombre del juego para su arcade: ","Error", 3)==0)
					{
						if(arcade_setNombreJuego(auxArcade,auxNombreJuego)==0)
						{
							printf("\nEl nuevo nombre del juego es: %s\n",auxNombreJuego);
						}
					}
					else
					{
						printf("\nError. No se pudo modificar el nombre.");
					}
				}
				break;


				case 3:
				//printf("Los datos nuevos son:");
				//controller_printEmployee(pArrayListEmployee, auxId);
				printf("\nUsted salió del menu de modificacion.\n");
				break;
			}
		}while(opcionMenu!=3);
		retorno=0;

	}
	return retorno;

}



/** \brief Pide el Id del arcade y lo Elimina
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si ok
 */
int controller_removeArcade(LinkedList* pArrayListArcade)
{
	int retorno=-1;
	int auxId;
	int index;
	Arcade* auxArcade;
	int optionRemove;

	if(pArrayListArcade != NULL)
	{
		controller_ListArcade(pArrayListArcade);
		if(getInt(&auxId,1,999999,3,"\nIngrese el Id del arcade que quiere eliminar: ","Error")==0)
		{
			index=arcade_findById(pArrayListArcade,auxId);
			if(index>=0)
			{
				auxArcade=ll_get(pArrayListArcade,index);
				if(arcade_setId(auxArcade,auxId)==0)
				{
					if(auxArcade!=NULL)
					{
						printf("\nUsted va a eliminar el arcade:\n");
						printf("\nId,Nacionalidad,Tipo_sonido,Cant_jug,Fichas_max,Salon,Game\n");
						printf("%d,%s,%d,%d,%d,%s,%s\n",auxArcade->id,auxArcade->nacionalidad,auxArcade->tipoDeSonido,auxArcade->cantidadDeJugadores,auxArcade->capacidadDeFichas,auxArcade->nombreDeSalon,auxArcade->nombreDeJuego);
						printf("\nEstá seguro que quiere eliminarlo?");
						getInt(&optionRemove,0,1,3,"\nIngrese el numero 0 para confirmar la eliminacion o "
												  "el numero 1 para continuar en el programa: ","Error.");
						if(optionRemove==0)
						{
							arcade_delete(auxArcade);
							ll_remove(pArrayListArcade,index);
							printf("\nSe ha eliminado el id: %d con exito.",auxId);
							retorno=0;
						}
						else
						{
							retorno=0;
						}
					}
				}
			}
		}
	}
    return retorno;
}



/** \brief Lista todos los arcades con sus datos
 * \param pArrayListEmployee LinkedList*
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL y el tamaño de la lista no es mayor a 0
                        ( 0) Si ok
 */

int controller_ListArcade(LinkedList* pArrayListArcade)
{
	int retorno = -1;
	int pLenList=ll_len(pArrayListArcade);

	if(pArrayListArcade != NULL && pLenList > 0)
	{
		printf("\nId,Nacionalidad,Tipo_sonido,Cant_jug,Fichas_max,Salon,Game\n");
		ll_map(pArrayListArcade,arcade_printArcade);
		retorno = 0;
	}
	return retorno;
}


/** \brief Ordenar la lista de arcades
 * \param pArrayListEmployee LinkedList*
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si ok
 */
int controller_sortPrintArcade(LinkedList* pArrayListArcade)
{
	int retorno=-1;
	if(pArrayListArcade!=NULL)
	{
		if(controller_menuSortArcade(pArrayListArcade)==0)
		{
			retorno=0;
		}
	}
	return retorno;
}



/** \brief Menu de opciones de como se quiere ordenar la lista de arcades
 * \param pArrayListEmployee LinkedList*
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si ok
 */
int controller_menuSortArcade(LinkedList* pArrayListArcade)
{
	int retorno=-1;
	int opcionMenu;

	if(pArrayListArcade!=NULL)
	{
		do
		{
			printf("\n¿Como desea ordenar la lista?");
			printf("\n1) Por Nombre de forma ascendente?");
			printf("\n2) Por Nombre de forma descendente?");
			getInt(&opcionMenu,1,4,3,"\nIngrese el numero de la opcion deseada: ","Error");
		}while(opcionMenu!=1 && opcionMenu!=2);

		switch(opcionMenu)
		{
			case 1:
			if(ll_sort(pArrayListArcade,arcade_compareName,1)==0)
			{
				controller_ListArcade(pArrayListArcade);
				printf("\nLos datos se han ordenado con exito");
			}
			else
			{
				printf("\nError. Los datos no se han podido ordenadar.");
			}
			break;

			case 2:
			if(ll_sort(pArrayListArcade,arcade_compareName,0)==0)
			{
				controller_ListArcade(pArrayListArcade);
				printf("\nLos datos se han ordenado con exito");
			}
			else
			{
				printf("\nError. Los datos no se han podido ordenadar.");
			}
			break;
		}
		retorno=0;
	}
	return retorno;
}



/** \brief Guarda los datos de los arcades en archivo
 * \param path char* archivo
 * \param pArrayListEmployee LinkedList*
 * \return int Retorna  (-1) Error: si el puntero a la lista y si el puntero a path es NULL
                        ( 0) Si ok
 */
int controller_saveAsText(char* path , LinkedList* pArrayListArcade)
{
	int retorno=-1;
	int i;
	int auxId;
	char auxNacionalidad[NAME_LEN];
	char auxTipoSonido[NAME_LEN];
	int auxCantidadJugadores;
	int auxFichasMax;
	char auxNombreSalon[NAME_LEN];
	char auxNombreJuego[NAME_LEN];
	FILE* f= fopen(path, "w");
	int pLenList=ll_len(pArrayListArcade);


	if(path!=NULL && pArrayListArcade!=NULL)
	{
		if(f!=NULL)
		{
			fprintf(f,"Id,Nombre,HorasTrabajadas,Sueldo\n");
			for(i=0; i<pLenList; i++)
			{
				Arcade* auxArcade=ll_get(pArrayListArcade,i);
				arcade_getId(auxArcade,&auxId);
				arcade_getNacionalidad(auxArcade,auxNacionalidad);
				arcade_getSonidoChar(auxArcade,auxTipoSonido);
				arcade_getCantidadJugadores(auxArcade,&auxCantidadJugadores);
				arcade_getCapacidadFichas(auxArcade,&auxFichasMax);
				arcade_getNombreSalon(auxArcade,auxNombreSalon);
				arcade_getNombreJuego(auxArcade,auxNombreJuego);
				fprintf(f,"%d,%s,%s,%d,%d,%s,%s\n",auxId,auxNacionalidad,auxTipoSonido,auxCantidadJugadores,auxFichasMax,auxNombreSalon,auxNombreJuego);
			}
		}
		fclose(f);
		printf("\nLos datos se han guardado en el archivo con exito");
		retorno=0;
	}
    return retorno;
}



/** \brief Crea un archivo de texto con los arcades que tiene mas de 1 jugador
 * \param path char* archivo
 * \param pArrayListEmployee LinkedList*
 * \return int Retorna  (-1) Error: si el puntero a la lista y si el puntero a path es NULL
                        ( 0) Si ok
 */
int controller_makeFileMultiplayer(char* path , LinkedList* pArrayListArcade)
{
	int retorno=-1;
	int i;
	int auxId;
	char auxNacionalidad[NAME_LEN];
	char auxTipoSonido[NAME_LEN];
	int auxCantidadJugadores;
	int auxFichasMax;
	char auxNombreSalon[NAME_LEN];
	char auxNombreJuego[NAME_LEN];
	FILE* f= fopen(path, "w");
	int pLenList;
	LinkedList* newList;


	if(path!=NULL && pArrayListArcade!=NULL)
	{
		newList=ll_newLinkedList();
		if(newList!=NULL)
		{
			newList=ll_filter(pArrayListArcade,arcade_isMultiplayer);
			if(controller_ListArcade(newList)==0)
			{
			if(f!=NULL)
			{
				pLenList=ll_len(newList);
				fprintf(f,"Id,Nacionalidad,Tipo_sonido,Cant_jug,Fichas_max,Salon,Game\n");
				for(i=0; i<pLenList; i++)
				{
					Arcade* auxArcade=ll_get(newList,i);
					arcade_getId(auxArcade,&auxId);
					arcade_getNacionalidad(auxArcade,auxNacionalidad);
					arcade_getSonidoChar(auxArcade,auxTipoSonido);
					arcade_getCantidadJugadores(auxArcade,&auxCantidadJugadores);
					arcade_getCapacidadFichas(auxArcade,&auxFichasMax);
					arcade_getNombreSalon(auxArcade,auxNombreSalon);
					arcade_getNombreJuego(auxArcade,auxNombreJuego);
					fprintf(f,"%d,%s,%s,%d,%d,%s,%s\n",auxId,auxNacionalidad,auxTipoSonido,auxCantidadJugadores,auxFichasMax,auxNombreSalon,auxNombreJuego);
				}
			}
			fclose(f);
			printf("\nSe ha generado el archivo MULTIJUGADOR.CSV con exito");
			retorno=0;
			}
		}
	}
    return retorno;
}



/** \brief Verifica si quiere salir del programa

 * \param int *option
 * \return void Retorna  (int) devuelve el numero de opcion elegida.

 */
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




/** \brief Duplica la cantidad maxima de fichas de todos los arcades
 * \param pArrayListEmployee LinkedList*
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL y si el tamaño de la lista no es mayor a 0
                        ( 0) Si ok
 */
int controller_renewCoinsArcade(LinkedList* pArrayListArcade)
{
	int retorno = -1;
	int pLenList=ll_len(pArrayListArcade);

	if(pArrayListArcade != NULL && pLenList > 0)
	{
		printf("\nId,Nacionalidad,Tipo_sonido,Cant_jug,Fichas_max,Salon,Game\n");
		ll_map(pArrayListArcade,arcade_newCoinsArcade);
		retorno = 0;
	}
    return retorno;
}



/** \brief Imprime los nombres de los juegos de los arcades sin repetirse
 * \param pArrayListEmployee LinkedList*
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL y si el tamaño de la lista no es mayor a 0
                        ( 0) Si ok
 */
int controller_printListGames(LinkedList* pArrayListArcade)
{
    int returnAux =-1;
    int i;
    Arcade* auxA;
    Arcade* auxB;
    char auxNombreJuego[NAME_LEN];

    if(pArrayListArcade!=NULL && ll_len(pArrayListArcade)>0)
    {
    	ll_sort(pArrayListArcade,arcade_compareName,1);
    	printf("\n---Lista de Juegos ingresados---");
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



/** \brief Crea un archivo con los nombres de los juegos de los arcades sin repetirse
 * \param pArrayListEmployee LinkedList*
 * \return int Retorna  (-1) Error: si el puntero a la lista y el puntero a path es NULL,
 * 							 si el tamaño de la lista no es mayor a 0.
                        ( 0) Si ok
 */
int controller_makeFileGames(char* path, LinkedList* pArrayListArcade)
{
    int returnAux =-1;
    int i;
    Arcade* auxA;
    Arcade* auxB;
    char auxNombreJuego[NAME_LEN];
    FILE* f= fopen(path, "w");

    if(pArrayListArcade!=NULL && ll_len(pArrayListArcade)>0 && path!=NULL)
    {
    	ll_sort(pArrayListArcade,arcade_compareName,1);
    	fprintf(f,"--Games--\n");
		for(i=0; i<(ll_len(pArrayListArcade)-1); i++)
		{
			auxA=ll_get(pArrayListArcade,i);
			auxB=ll_get(pArrayListArcade,i+1);
			if(arcade_compareName(auxA,auxB)!=0)
			{
				arcade_getNombreJuego(auxA, auxNombreJuego);
				fprintf(f,"%s\n",auxNombreJuego);
			}
		}
    	returnAux=0;
    }
    fclose(f);
    printf("\nSe ha generado el archivo GAME.TXT con exito");
    return returnAux;
}


