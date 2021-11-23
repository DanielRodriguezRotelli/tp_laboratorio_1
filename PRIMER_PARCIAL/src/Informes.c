/*
 * Informes.c
 *
 *  Created on: 19 oct. 2021
 *      Author: Aye
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn_biblioteca.h"
#include "Salon.h"
#include "Arcade.h"
#include "Informes.h"

#define LIBRE 1
#define OCUPADO 0

#define SALON_LEN 10
#define ARCADE_LEN 10
#define JUEGOS_LEN 10
#define CANTIDAD_ARCADE 1000

/**
 * \brief Realiza el menu principal del programa
 * \param opcionesDeMenu correspondiente a la opcion elegida por el usuario pasado por punter
 * \param la funcion muestra el menu y pide al usuario que ingrese la opcion elegida.
 * \return no devuelve nada.
 */
void menuPrincipal(int *opcionDeMenu)
{
	int opcion;

	do {
		getInt(&opcion, 1, 11, 3, "\n\n--MENU PRINCIPAL-- "
				"\n1) Alta de Salon. "
				"\n2) Eliminar Salon. "
				"\n3) Imprimir Salones. "
				"\n4) Incorporar Arcade. "
				"\n5) Modificar Arcade. "
				"\n6) Eliminar Arcade. "
				"\n7) Imprimir Arcades. "
				"\n8) Imprimir Juegos. "
				"\n9) Informes. "
				"\n10) Salir del Menu Principal"
				"\nIngrese la opcion deseada: ", "Error");
	} while (opcion != 1 && opcion != 2 && opcion != 3 && opcion != 4
			&& opcion != 5 && opcion != 6 && opcion != 7 && opcion != 8
			&& opcion != 9 && opcion != 10);
	*opcionDeMenu = opcion;
}

/**
 * \brief Inicializa el Array Juego.
 * \param Game* list correspondiente a la estructura del array.
 * \param len correspondiente al tamaño del array
 * \param la funcion coloca en 1 o 0 las banderas de isEmpty.
 * \return devuelve por retorno 1 si pudo incializar, 0 si nuo pudo.
 */
void game_initList(Game *list, int len)
{
	int indice;
	int retorno = 0;

	if (list != NULL && len > 0)
	{
		for (indice = 0; indice < len; indice++)
		{
			list[indice].isEmpty = 1;
			retorno = 1;
		}
	}
}

/**
 * \brief Busca un campo en un Array
 * \param Game* list correspondiente a la estructura del array.
 * \param len correspondiente al tamaño del array
 * \param juegos[] correspondiente a al array
 * \param la funcion recibe un array y busca si esta en la estructura
 * \return devuelve por retorno 1 si pudo incializar, 0 si nuo pudo.
 */
int game_estaJuegoEnLista(Game *list, int len, char juegos[])
{
	int i;
	int retorno = 0;
	if (list != NULL && len > 0 && juegos != NULL)
	{
		for (i = 0; i < len; i++)
		{
			if (list[i].isEmpty == 0)
			{
				//hay un cuit valido, lo comparo con "cuit"
				if (strncmp(list[i].Juegos, juegos, JUEGOS_LEN) == 0)
				{
					retorno = 1;
					break;
				}
			}
		}
	}
	return retorno;
}


/**
 * \brief Imprime la lista de Juegos sin repetir
 * \param Arcade* list correspondiente a la estructura del array.
 * \param len correspondiente al tamaño del array
 * \param la funcion compara el campo nombre de un array con otro.
 *        Si está en el 2do, lo deja, si no está lo copia.
 *        Luego imprime ese 2do array donde los nombre no se repiten.
 * \return devuelve por retorno 1 si pudo incializar, 0 si nuo pudo.
 */
int game_imprimirJuegos(Arcade* listArcade, int lenArcade)
{
	int retorno = -1;
	int i;
	int j;
	int flagExisteJuego = 0;
	int indiceJuegoLibre = 0;
	char listaJuegos[CANTIDAD_ARCADE][JUEGOS_LEN];

	if (listArcade != NULL && lenArcade > 0)
	{
		for (i = 0; i < lenArcade; i++)
		{
			flagExisteJuego = 0;
			if (listArcade[i].isEmpty == 0)
			{
				for (j = 0; j < indiceJuegoLibre; j++)
				{
					if (strncmp(listArcade[i].nombreDelJuego, listaJuegos[j],JUEGOS_LEN) == 0)
					{
						flagExisteJuego = 1;
						break;
					}
				}
				if (flagExisteJuego == 0)
				{
					strncpy(listaJuegos[indiceJuegoLibre],
							listArcade[i].nombreDelJuego, JUEGOS_LEN);
					indiceJuegoLibre++;
					retorno=0;
				}
			}
		}
		printf("\nLISTA DE JUEGOS");
		for (j = 0; j < indiceJuegoLibre; j++)
		{

			printf("\n- %s", listaJuegos[j]);
		}
	}
	return retorno;
}

/**
 * \brief Realiza el menu de informes del programa
 * \param opcionesDeMenuInformes correspondiente a la opcion elegida por el usuario pasado por punter
 * \param la funcion muestra el menu de informes y pide al usuario que ingrese la opcion elegida.
 * \return no devuelve nada.
 */
void salon_MenuInformes(int *opcionDeMenuInformes)
{
	int opcion;

	do {
		getInt(&opcion, 1, 11, 3,
				"\n\n--MENU DE INFORMES-- "
						"\n  1-Listar los salones con más de 4 arcades."
						"\n  2-Listar los arcades para más de 2 jugadores. "
						"\n  3-Listar toda la información de un salón en específico ingresando su ID. "
						"\n  4-Listar todos los arcades de un salón determinado ingresando su ID. "
						"\n  5-Imprimir el salón con más cantidad de arcades. "
						"\n  6-Ingresar el ID de un salón, y el valor en pesos de una ficha, e imprimir el monto máximo "
						"      en pesos que puede recaudar el salón. "
						"\n  7-Ingresar el nombre de un juego e imprimir cuantos arcades lo contienen. "
						"\n  8-Un salón se encuentra equipado por completo si posee al menos 8 arcades de mas de 2 jugadores. "
						"      Listar los salones que cumplan con este mínimo de requisito. "
						"\n  9-Imprimir el promedio de arcades por salón. "
						"\n 10- Salir del Menu Informes"
						"\nIngrese la opcion deseada: ", "Error");
	} while (opcion != 1 && opcion != 2 && opcion != 3 && opcion != 4
			&& opcion != 5 && opcion != 6 && opcion != 7 && opcion != 8
			&& opcion != 9 && opcion != 10);
	*opcionDeMenuInformes = opcion;
}



/**
 * \brief Imprime la lista de los salones con mas de 4 arcades
 * \param Salon* list correspondiente a la estructura del array.
 * \param lenSalon correspondiente al tamaño del array
 * \param Arcade* list correspondiente a la estructura del array.
 * \param len Arcade correspondiente al tamaño del array
 * \param la funcion busca en que salon tiene 4 o mas arcades
 *        Luego imprime la lista.
 *\return devuelve por retorno 1 si pudo incializar, 0 si nuo pudo.
 */
int inf_printSalonesCuatroArcade(Salon *listSalon, int lenSalon, Arcade *listArcade,int lenArcade)
{
	int retorno;
	int i;
	int j;
	int contArcade = 0;
	printf("\n	IdSalon		Nombre		Direccion		Tipo	");
	if (listSalon != NULL && lenSalon > 0 && listArcade != NULL&& listArcade > 0)
	{
		for (i = 0; i < lenSalon; i++)
		{
			contArcade = 0;
			if (listSalon[i].isEmpty == OCUPADO)
			{
				for (j = 0; j < lenArcade; j++)
				{
					if (listArcade[j].isEmpty == OCUPADO)
					{
						if (listSalon[i].idSalon == listArcade[j].idSalon)
						{
							contArcade++;
						}
					}
				}
				if (contArcade > 4)
				{
					printf("\n	%d		%s		%s		%d	", listSalon[i].idSalon,
															   listSalon[i].nombre,
															   listSalon[i].direccion,
															   listSalon[i].tipo);
					retorno = 0;
				}
			}
		}
	}
	return retorno;
}



/**
 * \brief Imprime la lista de arcades con mas de 2 jugadores.
 * \param Arcade* list correspondiente a la estructura del array.
 * \param len Arcade correspondiente al tamaño del array
 * \param Salon* list correspondiente a la estructura del array.
 * \param lenSalon correspondiente al tamaño del array
 * \param la funcion busca que arcade tiene mas de 2 jugadores
 *        Luego imprime la lista.
 *\return devuelve por retorno 1 si pudo incializar, 0 si nuo pudo.
 */
int inf_printArcadeDosJugadores(Arcade *listArcade, int lenArcade, Salon *listSalon,int lenSalon)
{
	int retorno = -1;
	int i;
	int j;

	if (listArcade != NULL && lenArcade > 0)
	{
		printf("\n****Arcades con mas de 2 jugadores****");
		printf("\nId Arcade  Cant.deJugadores  NombreDelJuego  NombreDelSalon");
		for (i = 0; i < lenArcade; i++)
		{
			if (listArcade[i].isEmpty == 0)
			{
				for (j = 0; j < lenSalon; j++)
				{
					if (listSalon[j].idSalon == listArcade[i].idSalon)
					{
						if (listArcade[i].cantidadJugadores > 2)
						{
							printf("\n%d		%d		%s		%s", listArcade[i].idArcade,
																     listArcade[i].cantidadJugadores,
																	 listArcade[i].nombreDelJuego,
																	 listSalon[j].nombre);
							retorno = 0;
						}
					}
				}
			}
		}
	}
	return retorno;
}


/**
 * \brief Imprime la lista de un salon
 * \param Salon* list correspondiente a la estructura del array.
 * \param lenSalon correspondiente al tamaño del array
 * \param Arcade* list correspondiente a la estructura del array.
 * \param len Arcade correspondiente al tamaño del array
 * \param la funcion pide un Id de Salon al usuario
 *        Luego imprime la informacion de ese Salon.
 *\return devuelve por retorno 1 si pudo incializar, 0 si nuo pudo.
 */
int inf_printSalonInfo(Salon *listSalon, int lenSalon, Arcade *listArcade,int lenArcade)
{
	int retorno;
	int i;
	int j;
	int contArcade = 0;
	int idSalon;

	getInt(&idSalon, 1, 99999999, 3, "Ingrese el Id del Salon", "Error");
	printf("\n	Nombre		Tipo		Direccion		CantDeArcades");
	if (listSalon != NULL && lenSalon > 0 && listArcade != NULL&& listArcade > 0)
	{
		for (i = 0; i < lenSalon; i++)
		{
			contArcade = 0;
			if (listSalon[i].isEmpty == OCUPADO)
			{
				for (j = 0; j < lenArcade; j++)
				{
					if (listArcade[j].isEmpty == OCUPADO)
					{
						if (listSalon[i].idSalon == listArcade[j].idSalon)
						{
							contArcade++;
						}
					}
				}
				if (listSalon[i].idSalon == idSalon)
				{
					printf("\n	%s		%d		%s			%d", listSalon[i].nombre,
																 listSalon[i].tipo,
															     listSalon[i].direccion,
							contArcade);
					retorno = 0;
				}
			}
		}
	}
	return retorno;
}


/**
 * \brief Cuenta la cantidad de Arcades.
 * \param Arcade* list correspondiente a la estructura del array.
 * \param len Arcade correspondiente al tamaño del array
 * \param la cuenta la totalidad de los arcades.
 *\return devuelve por retorno la cantidad total de arcades.
 */
int inf_contDeArcade(Arcade *list, int len)
{
	int i;
	int contArcade = 0;
	for (i = 0; i < len; i++)
	{
		if (list->isEmpty == 0)
		{
			contArcade++;
		}
	}
	return contArcade;
}



/**
 * \brief Cuenta la cantidad de Salones.
 * \param Salon* list correspondiente a la estructura del array.
 * \param len correspondiente al tamaño del array
 * \param la cuenta la totalidad de los salones.
 *\return devuelve por retorno la cantidad total de salones.
 */
int inf_contDeSalon(Salon *list, int len)
{
	int i;
	int contSalon = 0;
	for (i = 0; i < len; i++)
	{
		if (list->isEmpty == 0)
		{
			contSalon++;
		}
	}
	return contSalon;
}


/**
 * \brief Realizar el promedio de los arcades por salon.
 * \param contArc correspondiente a la cantidad de arcades.
 * \param contSalon correspondiente a la cantidad de Salones
 * \param divide la cantidad de arcades por la de salones
 *\return devuelve por retorno el promedio.
 */
float inf_promedioArcadePorSalon(int contArc, int contSalon)
{
	float resultado;
	resultado = (float) contArc / contSalon;
	return resultado;
}



/**
 * \brief Imprime la informacion de un arcade.
 * \param Arcade* list correspondiente a la estructura del array.
 * \param lenArcade correspondiente al tamaño del array
 * \param id Salon correspondiente al valor del Id de Salon pasado por parametro.
 * \param A la funcion le pasan por parametro in Id de Salon.
 *        Imprime todos los arcades que hay en ese salon
 *\return no devuelve nada.
 */
void inf_printArcadePorIdSalon(Arcade* listArcade, int lenArcade, int idSalon)
{
	int i;

	if (listArcade != NULL && lenArcade > 0)
	{
		printf("\nIdArcade	NombreDeJuego		Nacionalidad	CantidadJugadores	CapacidadFichas	  TipoSonido");
		for (i = 0; i < lenArcade; i++)
		{
			if (listArcade[i].isEmpty == 0)
			{
				if (listArcade[i].idSalon == idSalon)
				{
					printf("\n%d		%s			%s		%d		%d		%d	", listArcade[i].idArcade,
																				   listArcade[i].nombreDelJuego,
																				   listArcade[i].nacionalidad,
																				   listArcade[i].cantidadJugadores,
																				   listArcade[i].capacidadMaximaFichas,
																				   listArcade[i].tipoDeSonido);
				}
			}
		}
	}
}


/**
 * \brief Imprime la informacion de un Salon.
 * \param Salon* list correspondiente a la estructura del array.
 * \param lenSalon correspondiente al tamaño del array
 * \param id Salon correspondiente al valor del Id de Salon pasado por parametro.
 * \param A la funcion le pasan por parametro in Id de Salon.
 *        Imprime los datos deese salon
 *\return no devuelve nada.
 */
void inf_printSalonPorId(Salon *listSalon, int lenSalon, int idSalon)
{
	int i;

	if (listSalon != NULL && lenSalon > 0 && idSalon > 0)
	{
		for (i = 0; i < lenSalon; i++)
		{
			if (listSalon[i].isEmpty == 0)
			{
				if (listSalon[i].idSalon == idSalon)
				{
					printf("\nNombreSalon		TipoSalon");
					printf("\n %s		%d", listSalon->nombre, listSalon->tipo);
				}
			}
		}
	}
}



/**
 * \brief Imprime la informacion del salon con mas arcades.
 * \param Salon* list correspondiente a la estructura del array.
 * \param lenSalon correspondiente al tamaño del array
 * \param Arcade* list correspondiente a la estructura del array.
 * \param lenArcade correspondiente al tamaño del array
 * \param la funcion busca que salon tiene mas arcades
 *        Luego imprime la informacion de ese Salon.
 *\return devuelve por retorno 1 si pudo incializar, 0 si nuo pudo.
 */
int inf_printSalonesMayorCantArcade(Salon *listSalon, int lenSalon, Arcade *listArcade,int lenArcade)
{
	int retorno;
	int i;
	int j;
	int contArcade = 0;
	int maximoArcades;
	int indiceMaximoArcades;
	int primerMaximo = 0;

	printf("\n	IdSalon		Nombre		Direccion		Tipo		CantArcades	");
	if (listSalon != NULL && lenSalon > 0 && listArcade != NULL
			&& listArcade > 0)
	{
		for (i = 0; i < lenSalon; i++)
		{
			contArcade = 0;
			if (listSalon[i].isEmpty == OCUPADO)
			{
				for (j = 0; j < lenArcade; j++)
				{
					if (listArcade[j].isEmpty == OCUPADO)
					{
						if (listSalon[i].idSalon == listArcade[j].idSalon)
						{
							contArcade++;
							retorno = 0;
						}
					}
				}
				//for (j = 0; j < lenArcade; j++)
				if (primerMaximo == 0 || contArcade > maximoArcades)
				{
					maximoArcades = contArcade;
					indiceMaximoArcades = i;
					primerMaximo = 1;
				}
			}
		}
	}
	printf("\n	%d		%s		%s		%d		%d", listSalon[indiceMaximoArcades].idSalon,
											      listSalon[indiceMaximoArcades].nombre,
											      listSalon[indiceMaximoArcades].direccion,
											      listSalon[indiceMaximoArcades].tipo,
												  maximoArcades);

	return retorno;
}




/**
 * \brief Imprime la cantidad total de fichas por salon
 * \param Arcade* list correspondiente a la estructura del array.
 * \param lenArcade correspondiente al tamaño del array
 * \param la funcion pide al usaurio el id de un Salon
 *        luego pide al usuario el valor de la ficha
 *        luego calcula la cantidad de arcades y la cantidad total de fichas.
 *        Luego imprime el monto total que puede llegar a recaudar.
 *\return no devuelve nada.
 */
void inf_printCantMaximaFichaPorSalon(Arcade *listArcade, int lenArcade)
{
	int i;
	int acumFichas = 0;
	int contArcade = 0;
	float valorFicha;
	int idSalon;
	float recaudacion;

	if (listArcade != NULL && lenArcade > 0)
	{
		getInt(&idSalon, 1, 999999, 3, "Ingrese el Id del Salon:", "Error");
		getFloat(&valorFicha, 0.10, 10, 3, "Ingrese el valor de la ficha",
				"Error.");
		contArcade = 0;
		for (i = 0; i < lenArcade; i++)
		{
			if (listArcade[i].isEmpty == 0)
			{
				if (listArcade[i].idSalon == idSalon)
				{
					contArcade++;
					acumFichas = acumFichas+ listArcade[i].capacidadMaximaFichas;
				}
			}
		}
	}
	recaudacion = acumFichas * valorFicha;
	printf("\nLa cantidad de arcades es: %d", contArcade);
	printf("\nLa cantidad de la maxima de fichas es: %d", acumFichas);
	printf("\nLa El monto maximo del salon es: %.2f", recaudacion);
}


/**
 * \brief Imprime la cantidad de arcades que contienen un juego especifico
 * \param Arcade* list correspondiente a la estructura del array.
 * \param lenArcade correspondiente al tamaño del array
 * \param la funcion pide al ausuario el nombre de un Juego.
 *        luego compara y cuenta si el nombre del juego ingresado en un arcade
 *        Luego dice que cantidad de arcades contienen ese jeugo.
 *\return devuelve por retorno 1 si pudo incializar, 0 si nuo pudo.
 */
int inf_imprimirArcadePorJuegos(Arcade *listArcade, int lenArcade)
{
	int retorno = -1;
	int i;
	int contArcade = 0;
	char nombreJuego[CANTIDAD_ARCADE][NOMBREJUEGO_LEN];

	if (listArcade != NULL && lenArcade > 0)
	{
		getText(nombreJuego, NOMBREJUEGO_LEN, "Ingrese el nombre del Juego: ","Error", 3);
		contArcade = 0;
		for (i = 0; i < lenArcade; i++)
		{
			if (listArcade[i].isEmpty == 0)
			{
				if (strncmp(listArcade[i].nombreDelJuego, nombreJuego,JUEGOS_LEN) == 0)
				{
					contArcade++;
					retorno = 0;
				}
			}
		}
		printf("\nEl Juego %s lo contienen %d Arcades", nombreJuego, contArcade);

	}
	return retorno;
}



/**
 * \brief Imprime la informacion del salon con mas de 8 arcades y cada arcades con mas de 2 jugadores.
 * \param Salon* list correspondiente a la estructura del array.
 * \param lenSalon correspondiente al tamaño del array
 * \param Arcade* list correspondiente a la estructura del array.
 * \param lenArcade correspondiente al tamaño del array
 * \param la funcion busca que salon tiene arcades con mas de 2 jugadores
 *        Luego busca que salon tiene mas de 8 arcades con la condicion anterior.
 *        luego imprime la lista de salon que encuentra con esas dos condiciones.
 *\return devuelve por retorno 0 si pudo encontrar algun salon, -1 si nuo pudo.
 */
int inf_printSalonCompleto(Salon *listSalon, int lenSalon, Arcade *listArcade,int lenArcade)
{
	int retorno=-1;;
	int i;
	int j;
	int contArcade = 0;
	printf("\n**** Salonescon mas de 8 Arcades con mas de 2 jugadores ****");
	printf("\n	IdSalon		Nombre		Direccion	Tipo	");
	if (listSalon != NULL && lenSalon > 0 && listArcade != NULL&& listArcade > 0)
	{
		for (i = 0; i < lenSalon; i++)
		{
			contArcade = 0;
			if (listSalon[i].isEmpty == OCUPADO)
			{
				for (j = 0; j < lenArcade; j++)
				{
					if (listArcade[j].isEmpty == OCUPADO)
					{
						if (listSalon[i].idSalon == listArcade[j].idSalon)
						{
							if (listArcade[j].cantidadJugadores > 2)
							{
								contArcade++;
							}

						}
					}
				}
			}
			if (contArcade >= 8)
			{
				printf("\n	%d		%s		%s		%d	", listSalon[i].idSalon,
						listSalon[i].nombre, listSalon[i].direccion,
						listSalon[i].tipo);
				retorno = 0;
			}
		}
	}
	return retorno;
}




