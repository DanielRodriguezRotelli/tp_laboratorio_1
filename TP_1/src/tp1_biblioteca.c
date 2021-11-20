/*
 * tp1_biblioteca.c
 *
 *  Created on: 18 sep. 2021
 *      Author: Aye
 */

#include <stdio.h>
#include <stdlib.h>

/**
 * \brief Muestra el menu principal, recibe la opcion que desea realizar el usuario y ejecuta la operacion.
 * \param *pRespuesta correspondiente a la operacion que el usuario quiere realizar.
 * \param scanUno correspondiente al valor del scanf del operador Uno.
 * \param scanDos correspondiente al valor del scanf del operador Dos.
 * \param primerOper correspondiente al valor del primer operando.
 * \param segundoOper correspondiente al valor del segundo operador.
 * \return Devuelve por referencia la opcion del menu que el usuario desea realizar.
 */
void menuDeOpciones(int* pRespuesta, int scanUno, int scanDos, float primerOper, float segundoOper)
{
	int respuesta;
	int salidaScan;

	do
	{
		if(scanUno==1 && scanDos==1)
		{
			printf("\n ---MENU PRINCIPAL---");
			printf("\n1-El 1er operando es: %.2f",primerOper);
			printf("\n2-El 2do operando es: %.2f",segundoOper);
			printf("\n3-Calcular todas las operaciones: ");
			printf("\n4-Informar resultados: ");
			printf("\n5-Salir. \n");
			printf("Ingrese la opcion deseada: ");
			salidaScan=scanf("%d",&respuesta);
			if(salidaScan==1 && (respuesta==1 || respuesta==2 || respuesta==3 || respuesta==4 || respuesta==5))
			{
				*pRespuesta = respuesta;
				break;
			}
			else
			{
				printf("ERROR. OPCION NO VALIDA. INTENTE OTRA VEZ");
			}
			fflush(stdin);
		}

		if(scanUno==1 && scanDos==0)
		{
			printf("\n ---MENU PRINCIPAL---");
		    printf("\n1-El 1er operando es: %.2f",primerOper);
			printf("\n2-Ingresar 2do operando: ");
			printf("\n3-Calcular todas las operaciones: ");
			printf("\n4-Informar resultados: ");
			printf("\n5-Salir. \n");
			printf("Ingrese la opcion deseada: ");
			salidaScan=scanf("%d",&respuesta);
			if(salidaScan==1 && (respuesta==1 || respuesta==2 || respuesta==3 || respuesta==4 || respuesta==5))
			{
				*pRespuesta = respuesta;
				break;
			}
			else
			{
				printf("\nERROR. OPCION NO VALIDA. INTENTE OTRA VEZ");
			}
			fflush(stdin);
		}

		if(scanUno==0 && scanDos==1)
		{
			printf("\n ---MENU PRINCIPAL---");
			printf("\n1-Ingresar 1er operando: ");
			printf("\n2-El 2do operando es: %.2f",segundoOper);
			printf("\n3-Calcular todas las operaciones: ");
			printf("\n4-Informar resultados: ");
			printf("\n5-Salir. \n");
			printf("Ingrese la opcion deseada: ");
			salidaScan=scanf("%d",&respuesta);
			if(salidaScan==1 && (respuesta==1 || respuesta==2 || respuesta==3 || respuesta==4 || respuesta==5))
			{
				*pRespuesta = respuesta;
				break;
			}
			else
			{
				printf("\nERROR. OPCION NO VALIDA. INTENTE OTRA VEZ");
			}
			fflush(stdin);
		}

		if(scanUno==0 && scanDos==0)
		{
			printf("\n ---MENU PRINCIPAL---");
			printf("\n1-Ingresar 1er operando: ");
			printf("\n2-Ingresar 2do operando: ");
			printf("\n3-Calcular todas las operaciones: ");
			printf("\n4-Informar resultados: ");
			printf("\n5-Salir. \n");
			printf("Ingrese la opcion deseada: ");
			salidaScan=scanf("%d",&respuesta);
			if(salidaScan==1 && (respuesta==1 || respuesta==2 || respuesta==3 || respuesta==4 || respuesta==5))
			{
				*pRespuesta = respuesta;
				break;
			}
			else
			{
				printf("\nERROR. OPCION NO VALIDA. INTENTE OTRA VEZ");
			}
			fflush(stdin);
		}

	}while(salidaScan!=1 && (respuesta==1 || respuesta==2 || respuesta==3 || respuesta==4 || respuesta==5));

}

/**
 * \brief Pide y recibe un numero con decimales dentro de parametros determinados.
 * \param *pResultado correspondiente al numero que el usuario ingresa.
 * \param *pSalidaScanf correspondiente al valor que devuelde el scanf.
 * \param min correspondiente al parametro minimo que el usuario puede ingresar.
 * \param max correspondiente al parametro maximo que el usuario puede ingresar.
 * \param reintentos correspondiente a la cantidad de posibilidades para ingresar el numero que tiene el usuario si que hay un error.
 * \param variableTexto correspondiente al texto literal para pedir el numero al usuario.
 * \param textoError correspondiente al texto literal que aparece que hay un error en el ingreso del numnero.
 * \param La funcion le pide al usuario a traves de un mensaje, que ingrese un numero (con decimales si es necesario) dentro de los parametros de minimo y maximo.
 *        Si el numero no es un numero o no esta dentro del rango establecido, la funcion avisa con un mensaje de error.
 * \return devuelve 2 cosas: 1) Por referencia devuelve el numero ingresado por el usuario.
 *                           2) Por retorno si pudo realizar la funcion.
 */
int pedirFloatAlUsuario(float* pResultado,int* pSalidaScanf, float min, float max, int reintentos, char* variableTexto, char* textoError)
{
	float num;
	int retorno=-1;
	int i;
	if(pResultado != NULL && min<max && reintentos >=0 && variableTexto != NULL && textoError != NULL)
	{
		for(i=0; i<=reintentos; i++)
		{
			printf("%s", variableTexto);
			*pSalidaScanf=scanf("%f", &num);
			if(*pSalidaScanf==1) //CONDICION PARA SABER SI EL SCAN PUDO GUARDAR UN NUMERO EN LA VARIABLE
			{
				if(num>=min && num<=max)
				{
				//printf("La salida de scanf es: %d\n\n",salidaScanf);
				retorno=0; //OK
				*pResultado=num;
				break;
				}
			}
			else
			{
				retorno=-2;
				printf("%s\n",textoError);
			}
			fflush(stdin);
		}
	}
	return retorno;
}


/**
 * \brief Suma los operandos.
 * \param operador1 correspondiente al primer numero operador.
 * \param operador2 correspondiente al segundo numero operador.
 * \param pSuma correspondiente al valor de la suma de los dos operadores.
 * \return devuelve 2 cosas: 1) Por referencia devuelve el resultado de la Suma de los 2 operadores.
 *                           2) Por retorno si pudo o no realizar la suma.

 */
int sumar(float operador1, float operador2, float* pSuma)
{
	int retorno=-1;

	if(pSuma!=NULL)
	{
		*pSuma= operador1+operador2;
		retorno=0;
	}
	return retorno;
}


/**
 * \brief Resta los operandos.
 * \param operador1 correspondiente al primer numero operador.
 * \param operador2 correspondiente al segundo numero operador.
 * \param pResta correspondiente al valor de la resta de los dos operadores.
 * \return devuelve 2 cosas: 1) Por referencia devuelve el resultado de la Resta de los 2 operadores.
 *                           2) Por retorno si pudo o no realizar la resta.
 */
int restar(float operador1, float operador2, float* pResta)
{
	int retorno=-1;

	if(pResta!=NULL)
	{
		*pResta= operador1-operador2;
		retorno=0;
	}
	return retorno;
}

/**
 * \brief Multiplica los operandos.
 * \param operador1 correspondiente al primer numero operador.
 * \param operador2 correspondiente al segundo numero operador.
 * \param pMultiplicacion correspondiente al valor de la multiplicacion de los dos operadores.
 * \return devuelve 2 cosas: 1) Por referencia devuelve el resultado de la multiplicacion de los 2 operadores
 *                           2) Por retorno si pudo o no realizar la multiplicacion .
 */
int multiplicar(float operador1, float operador2, float* pMultiplicacion)
{
	int retorno=-1;

	if(pMultiplicacion!=NULL)
	{
		*pMultiplicacion= operador1*operador2;
		retorno=0;
	}
	return retorno;
}

/**
 * \brief Divide el operando 1 con el operando 2.
 * \param operador1 correspondiente al primer numero operador.
 * \param operador2 correspondiente al segundo numero operador.
 * \param pResta correspondiente al valor de la division de los dos operadores.
 * \param La funcion chequea que el operador2 no sea 0, para poder dividir. Si es 0, el retorno devuelve que no pudo realizar la division.
 * \return devuelve 2 cosas: 1) Por referencia devuelve el resultado de la division de los 2 operadores.
 *                           2) Por retorno si pudo o no realizar la division .
 */
int dividir(float operador1, float operador2, float* pDivision)
{
	int retorno=-1;

	if(operador2!=0)
	{
		*pDivision = (float) operador1 / operador2;//DEVOLVER POR REFERENCIA
		retorno=0; //No hubo error
	}
	else
	{
		retorno=-1; //Hubo error
	}
	return retorno;
}

/**
 * \brief Realiza el factorial (es el producto de todos los numeros naturales anteriores o iguales a él) de un operando.
 * \param operador correspondiente a un numero ingresado.
 * \param pResultFactorial correspondiente al valor del factorial del operador.
 * \param la funcion tiene tres partes: 1)Si el operador es mayor a 0, realiza el factorial.
 *                                      2)Si el operador es igual a 0, el factorial es =1.
 *                                      3)Si el operador es menor a 0, la funcion no puede realizar el factorial, por lo tanto el retorno informará que no se pudo realizar la operacion.
 * \return devuelve 2 cosas: 1) Por referencia devuelve el resultado del factorial del operador.
 *                           2) Por retorno si pudo realizar el factorial o no.
 */
int factorial(int operador, float* pResultFactorial)
{
	int i;
	float resultado=1;
	int retorno=-1;

	if(operador>=0)
	{
		for(i=1; i<=operador; i++)
		{
			resultado=resultado*i;

		}
		*pResultFactorial=resultado;
		retorno=0;
	}
	else
	{
		if(operador==0)
		{
			*pResultFactorial=1;
			retorno=0;
		}

	}
	return retorno;
}

