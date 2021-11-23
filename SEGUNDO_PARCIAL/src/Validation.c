/*
 * Validacion.c
 *
 *  Created on: 9 nov. 2021
 *      Author: Aye
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Validation.h"
#include "utn_biblioteca.h"



int isValidName(char* cadena, int lenCadena)
{
	int retorno = 0;
	int i=0;

	if(cadena != NULL && lenCadena > 0)
	{
		for(i=0; i<lenCadena; i++)
		{
			if(cadena[i]!='\0')
			{
				break;
			}
			if(!((cadena[i]!=' ') && (cadena[i]<'0' || cadena[i]>'9') && (cadena[i]<'a' || cadena[i]>'z') &&
			   (cadena[i]<'A' || cadena[i]>'Z')))
			{
				retorno=1;
				break;
			}
		}
	}
	return retorno;
}

int isValidId(char* cadena, int lenCadena)
{
	int retorno = -1;
	int i=0;

	if(cadena!=NULL && lenCadena<0)
	{
		retorno=0; //VERDADERO
		for(i=0; cadena[i]!='\0' && i<lenCadena; i++)
		{
			if(cadena[i]<'0' || cadena[i]>'9')
			{
				retorno=-1; //NO ES NUMERICA
				break;
			}
		}
	}
	return retorno;
}

int isValidHorasTrabajadas(char* cadena, int lenCadena)
{
	int retorno = -1;
	int i=0;

	if(cadena!=NULL && lenCadena<0)
	{
		retorno=0; //VERDADERO
		for(i=0; cadena[i]!='\0' && i<lenCadena; i++)
		{
			if(cadena[i]<'0' || cadena[i]>'9')
			{
				retorno=-1; //NO ES NUMERICA
				break;
			}
		}
	}
	return retorno;
}


int isValidSueldo(char* cadena, int lenCadena)
{
	int retorno = -1;
	int i=0;

	if(cadena!=NULL && lenCadena<0)
	{
		retorno=0; //VERDADERO
		for(i=0; cadena[i]!='\0' && i<lenCadena; i++)
		{
			if(cadena[i]<'0' || cadena[i]>'9')
			{
				retorno=-1; //NO ES NUMERICA
				break;
			}
		}
	}
	return retorno;
}

int esNumericaInt(char cadena[])
{
	int retorno = 1;
	int i=0;

	if(cadena!=NULL)
	{
		if(cadena[0]=='-')
		{
			i=1;
		}
		retorno = 0;
		while(cadena[i] != '\0')
		{
			if(cadena[i]<'0' || cadena[i]>'9')
			{
				retorno=-1; //NO ES NUMERICA
				break;
			}
			i++;
		}
	}
	return retorno;
}

int esNumericaFloat(char cadena[])
{
	int retorno = 1;
	int i=0;
	int contPunto=0;

	if(cadena!=NULL)
	{
		if(cadena[0]=='-')
		{
			i=1;
		}
		retorno = 0;
		while(cadena[i] != '\0')
		{

			if(cadena[i]<'0' || cadena[i]>'9')
			{
				if(cadena[i]=='.')
				{
					contPunto++;
				}
				else
				{
					retorno=-1; //NO ES NUMERICA
					break;
				}
				if(contPunto>=2)
				{
					retorno=-1; //NO ES NUMERICA
					break;
				}
			}
			i++;
		}
	}
	return retorno;
}






