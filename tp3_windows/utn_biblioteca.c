/*
 * pedirFloat.c
 *
 *  Created on: 12 sep. 2021
 *      Author: Aye
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn_biblioteca.h"

static int myGets(char pResultado[], int len);
static int esNumericaInt(char cadena[]);
static int esNumericaFloat(char cadena[]);

static int myGets(char pResultado[], int len)
{
	int retorno=-1;
	int indexFinal;

	fflush(stdin);

	if(fgets(pResultado,len,stdin)!=NULL)
	{
		indexFinal=strlen(pResultado)-1;
		if(pResultado[indexFinal] == '\n')
		{
			pResultado[indexFinal]='\0';
	    }
		retorno = 0; // OK
	}
	return retorno;
}



// esta funcion recibe una cadena, la analiza y me dice si es numerica.
// si es numerica... retorna 0.   si no es numerica retorna -1
static int esNumericaInt(char cadena[])
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


static int esNumericaFloat(char cadena[])
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

int esSoloLetras(char cadena[])
{
	int retorno = 1;
	int i=0;

	while(cadena[i] != '\0')
	{

		if((cadena[i]!=' ') && (cadena[i]<'a' || cadena[i]>'z') && (cadena[i]<'A' || cadena[i]>'Z') && (cadena[i]<'0' || cadena[i]>'9'))
		{
			retorno=0;
			break;
		}
		i++;
	}
	return retorno;
}


int esAlfaNumerico(char cadena[])
{
	int retorno = 1;
	int i=0;

	while(cadena[i] != '\0')
	{

		if((cadena[i]!=' ') && (cadena[i]<'a' || cadena[i]>'z') && (cadena[i]<'A' || cadena[i]>'Z'))
		{
			retorno=0;
			break;
		}
		i++;
	}
	return retorno;
}


int esTelefono(char cadena[])
{
	int i=0;
	int retorno=-1;
	int contadorGuiones=0;
	while(cadena[i] != '\0')
	{
		if((cadena[i]!=' ') && (cadena[i]!='-') && (cadena[i]!='z') && (cadena[i]<'0' || cadena[i]>'9'))
		{
			retorno=0;
		}
		if(cadena[i]==' ')
		{
			contadorGuiones++;
		}
		i++;
	}
	if(contadorGuiones==1)
	{
		retorno=1;
	}
	return retorno;
}

int getFloat(float* pResultado, float min, float max, int reintentos, char* variableTexto, char* textoError)
{
	float buffer;
	int retorno=-1;
	int i;
	char bufferCadenaAux[64];
	if(pResultado != NULL && min<max && reintentos >=0 && variableTexto != NULL && textoError != NULL)
	{
		for(i=0; i<=reintentos; i++)
		{
			printf("%s", variableTexto);
			fflush(stdin);
			if(myGets(bufferCadenaAux, sizeof(bufferCadenaAux))==0)
			{
				//el usuario ingreso algo
				//lo valido para ver si los simbolos ingresados son numericos
				if(esNumericaFloat(bufferCadenaAux)==0)
				{
					// si son numericos, convierto la cadena a INT
					buffer=atof(bufferCadenaAux);
					if(buffer>=min && buffer<=max)
					{
						retorno=0; //OK
						*pResultado=buffer;
						break;
					}
					else
					{
						retorno=-1;
						printf("%s\n",textoError);
					}
				}
				else
				{
					printf("%s\n",textoError);
				}
			}
		}
	}
	return retorno;
}

int getInt(int* pResultado, int min, int max, int reintentos, char* variableTexto, char* textoError)
{
	int buffer;
	int retorno=-1;
	int i;
	char bufferCadenaAux[16];
	if(pResultado != NULL && min<max && reintentos >=0 && variableTexto != NULL && textoError != NULL)
	{
		for(i=0; i<=reintentos; i++)
		{
			printf("%s", variableTexto);
			fflush(stdin);
			if(myGets(bufferCadenaAux, sizeof(bufferCadenaAux))==0)
			{
				//el usuario ingreso algo
				//lo valido para ver si los simbolos ingresados son numericos
				if(esNumericaInt(bufferCadenaAux)==0)
				{
					// si son numericos, convierto la cadena a INT
					buffer=atoi(bufferCadenaAux);
					if(buffer>=min && buffer<=max)
					{
						retorno=0; //OK
						*pResultado=buffer;
						break;
					}
					else
					{
						retorno=-1;
						printf("%s\n",textoError);
					}
				}
				else
				{
					printf("%s\n",textoError);
				}
			}
		}
	}
	return retorno;
}

int getChar(char* pResultado, int min, int max, int reintentos, char* variableTexto, char* textoError)
{
	char buffer;
	int retorno=-1;
	int i;
	int salidaScanf;
	if(pResultado != NULL && min<max && reintentos >=0 && variableTexto != NULL && textoError != NULL)
	{
		for (i=0; i<=reintentos; i++)
		{
			printf("%s",variableTexto);
			fflush(stdin);
			salidaScanf=scanf("%c", &buffer);

			//printf("\nLa salida del scanf es : %d\n\n",salidaScanf);
			if (salidaScanf>0 && buffer>=min && buffer<=max)
			{
				retorno = 0; // OK
				*pResultado=buffer;
				break;
			}
			else
			{
				retorno=-2;
				printf("%s\n",textoError);
			}
		}
	}
	return retorno;
}

int getText(char* pResultado, int len, char* variableTexto, char* textoError, int reintentos)
{
	int retorno=-1;
	int i;

	if(pResultado != NULL && reintentos >=0 && variableTexto != NULL && textoError != NULL)
	{
		for (i=0; i<=reintentos; i++)
		{
			printf("%s",variableTexto);
			if(myGets(pResultado, len)==0)
			{
				retorno = 0; // OK
				break;
			}
			else
			{
				retorno=-2;
				printf("%s\n",textoError);
			}
		}
	}
	return retorno;
}

void inicializarArray(int pArray[], int len, int valorInicial)
{
	int indice;

	for(indice=0; indice<len; indice++)
	{
		pArray[indice]=valorInicial;
	}
}


void imprimirArray(int arrayLista[], int len)
{
	int i;

	for(i=0; i<len; i++)
		{
			printf("%d\n", arrayLista[i]);
		}
}


int menorValorArray(int arrayInt[], int len)
{
	int i;
	int menor;
	menor=arrayInt[0];

	for(i=0; i<len; i++)
	{
		if(arrayInt[i]<menor)
		{
			menor=arrayInt[i];
		}
	}
	return menor;
}

int mayorValorArray(int arrayInt[], int len)
{
	int i;
	int mayor;
	mayor=arrayInt[0];

	for(i=0; i<len; i++)
	{
		if(arrayInt[i]>mayor)
		{
			mayor=arrayInt[i];
		}
	}
	return mayor;
}

float promedioArrayInt(int arrayInt[], int len)
{
	int i;
	float resultado;
	int acumArray = 0;

	for(i=0; i<len; i++)
	{
		acumArray = acumArray + arrayInt[i];
	}

	resultado = (float) acumArray / len;
	return resultado;
}


int borrarImparesArray(int arrayDeEnteros[], int tamanioArray)
{
	int retorno=-1;
	int i;
	if(arrayDeEnteros!=NULL && tamanioArray >=0)
	{
		for(i=0; i<tamanioArray; i++)
		{
			if(arrayDeEnteros[i]%2!=0)
			{
				arrayDeEnteros[i]=0;
			}
		}
		retorno=0;
	}
	return retorno;
}


void ordenarCrecienteArray(int arrayDeEnteros[], int tamanioArray)
{
	int i;
	int j;
	int buffer;

	for(i=1; i<tamanioArray; i++)
	{
		buffer=arrayDeEnteros[i];
		j=i-1;
		while(j>=0 && buffer<arrayDeEnteros[j])
		{
			arrayDeEnteros[j+1]=arrayDeEnteros[j];
			j--;
		}
		arrayDeEnteros[j+1]=buffer;
	}
}




