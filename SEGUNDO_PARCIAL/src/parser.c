#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Arcade.h"
#include "utn_biblioteca.h"
#include "parser.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_ArcadesFromText(FILE* pFile , LinkedList* pArrayListArcade)
{
	int retorno=-1;
	//int i;
	//int pLenList=ll_len(pArrayListArcade);
	Arcade* auxArcade;
	char id[NAME_LEN];
	char sonido[NAME_LEN];
	char cantJugadores[NAME_LEN];
	char capcFichas[NAME_LEN];
	char nombreSalon[NAME_LEN];
	char nombreJuegos[NAME_LEN];
	char nacionalidad[NAME_LEN];

	if(pFile!=NULL && pArrayListArcade!=NULL)
	{
		fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",id,nacionalidad,sonido,cantJugadores,capcFichas,nombreSalon,nombreJuegos);//salto la primer linea
		do
		{
			if(fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",id,nacionalidad,sonido,cantJugadores,capcFichas,nombreSalon,nombreJuegos)==7)
			{
				//printf("Lei:%s  %s  %s  %s	%s	%s	%s\n",id,nacionalidad,sonido,cantJugadores,capcFichas,nombreSalon,nombreJuegos);
				auxArcade=arcade_newParametros(id,sonido,cantJugadores,capcFichas,nacionalidad,nombreSalon,nombreJuegos);
				if(auxArcade!=NULL)
				{
					ll_add(pArrayListArcade,auxArcade);
					retorno=0;
				}
			}
			else
			{
				arcade_delete(auxArcade);
				break;
			}
		}while(feof(pFile)==0);
	}/*
	for(i=0; i<ll_len(pArrayListArcade);i++)
	{
		auxArcade = ll_get(pArrayListArcade,i);
		printf("%d  %s  %s  %d	%d	%s	%s\n",auxArcade->id,
								  	  	  	  auxArcade->nacionalidad,
											  auxArcade->tipoDeSonido,
											  auxArcade->cantidadDeJugadores,
											  auxArcade->capacidadDeFichas,
											  auxArcade->nombreDeSalon,
											  auxArcade->nombreDeJuego);
	}*/
	return retorno;
}

