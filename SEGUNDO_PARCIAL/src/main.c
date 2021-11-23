/*
 ============================================================================
 Name        : SEGUNDO_PARCIAL.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Controller.h"
#include "LinkedList.h"
#include "Arcade.h"

#define TRUE 0
#define FALSE 1

int main(void)
{
	setbuf(stdout,NULL);
	int option = 0;
	int loadTextData=FALSE;
	int optionExit;


	LinkedList* listArcades = ll_newLinkedList();

	do{
		controller_menu(&option);
		switch(option)
		{
			case 1://terminado
			if(controller_loadFromText("arcades.csv",listArcades)==TRUE)
			{
				loadTextData=TRUE;
			}
			else
			{
				printf("\nError. No se puede cargar lista de archivo.");
			}
			break;


			case 2:// terminado
			if(loadTextData == TRUE)
			{
				if(controller_addArcade(listArcades)==TRUE)
				{
					controller_saveAsText("arcades.csv" ,listArcades);
				}
				else
				{
					printf("\nError. No se pueden ingresar datos.");
				}
			}
			else
			{
				printf("\nNo puede ingresar datos si no ha cargado los datos del archivo.");
			}
			break;


			case 3:// terminado
			if(loadTextData == TRUE)
			{
				if(controller_editArcade(listArcades)==TRUE)
				{
					controller_saveAsText("arcades.csv" ,listArcades);
				}
				else
				{
					printf("\nError. No se pueden realizar modificaciones.");
				}
			}
			else
			{
				printf("\nNo puede editar datos si no ha cargado los datos del archivo.");
			}
			break;


			case 4: //terminado
			if(loadTextData == TRUE)
			{
				if(controller_removeArcade(listArcades)==TRUE)
				{
					controller_saveAsText("arcades.csv" ,listArcades);
				}
				else
				{
					printf("\nError. No se puede eliminar empleados.");
				}
			}
			else
			{
				printf("\nNo puede eliminar datos si no ha cargado los datos del archivo.");
			}
			break;


			case 5://termniado
			if(loadTextData == TRUE)
			{
				if(controller_sortPrintArcade(listArcades)!=TRUE)
				{
					printf("\nError. No se puede imprimir lista.");
				}
			}
			else
			{
				printf("\nNo puede impimir datos si no ha cargado los datos del archivo.");
			}
			break;


			case 6://terminado
			if(loadTextData == TRUE)
			{
				if(controller_makeFileGames("Game.txt",listArcades)!=TRUE)
				{
					printf("\nError. No se puede generar el archivo.");
				}
			}
			else
			{
				printf("\nNo puede generar archivo si no ha cargado los datos del archivo.");
			}
			break;


			case 7: //terminado
			if(loadTextData == TRUE)
			{
				if(controller_makeFileMultiplayer("multijugador.csv",listArcades)!=TRUE)
				{
					printf("\nError. No se puede generar el archivo.");
				}
			}
			else
			{
				printf("\nNo puede generar nuevo archivo si no ha cargado los datos del archivo.");
			}
			break;


			case 8://terminado
			if(loadTextData == TRUE)
			{
				if(controller_renewCoinsArcade(listArcades)!=TRUE)
				{
					printf("\nError. No se pudo maximizar la cantidad de fichas.");
				}
			}
			else
			{
				printf("\nNo puede maximizar la cantidad de fichas si no ha cargado los datos del archivo.");
			}

			break;


			case 9://terminado
			if(loadTextData == TRUE)
			{
				controller_saveAsText("arcades.csv" ,listArcades);
			}
			controller_exitProgram(&optionExit);
			break;
		}
	}while(optionExit != 0);

	return 0;
}

