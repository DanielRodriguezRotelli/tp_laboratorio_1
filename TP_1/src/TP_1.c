/*
 ============================================================================
 Name        : TP_1.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 P1 Enunciado:
Hacer una calculadora. Para ello el programa iniciará y contará con un menú de opciones:
1. Ingresar 1er operando (A=x)
2. Ingresar 2do operando (B=y)
3. Calcular todas las operaciones
a) Calcular la suma (A+B)
b) Calcular la resta (A-B)
c) Calcular la division (A/B)
d) Calcular la multiplicacion (A*B)
e) Calcular el factorial (A!)
4. Informar resultados
a) “El resultado de A+B es: r”
b) “El resultado de A-B es: r”
c) “El resultado de A/B es: r” o “No es posible dividir por cero”
d) “El resultado de A*B es: r”
e) “El factorial de A es: r1 y El factorial de B es: r2”
5. Salir
• Todas las funciones matemáticas del menú se deberán realizar en una biblioteca aparte,
que contenga las funciones para realizar las cinco operaciones.
• En el menú deberán aparecer los valores actuales cargados en los operandos A y B
(donde dice “x” e “y” en el ejemplo, se debe mostrar el número cargado)
• Deberán contemplarse los casos de error (división por cero, etc)
• Documentar todas las funciones
 */

#include <stdio.h>
#include <stdlib.h>

#include "tp1_biblioteca.h"

#define REINT_LEN 3
#define MAX 20000
#define MIN -20000



int main(void)
{
	setbuf(stdout,NULL);

	int respuestaDeOpciones;
	float operadorUno;
	float operadorDos;
	int scanOperadorUno=0;
	int scanOperadorDos=0;
	float suma;
	float resta;
	float multiplicacion;
	float division;
	float factorial1;
	float factorial2;
	int estadoOperacionesMath=-1;
	int scanSuma;
	int scanResta=0;
	int scanMultiplicacion=0;
	int scanDivision;
	int scanFactorial1;
	int scanFactorial2;
	int respuestaFinal;



	do
	{
		do
		{
			menuDeOpciones(&respuestaDeOpciones, scanOperadorUno, scanOperadorDos, operadorUno, operadorDos);
		}while(respuestaDeOpciones!=1 && respuestaDeOpciones!=2 && respuestaDeOpciones!=3 && respuestaDeOpciones!=4 && respuestaDeOpciones!=5);


		switch(respuestaDeOpciones)
		{
			case 1:
			pedirFloatAlUsuario(&operadorUno,&scanOperadorUno, MIN, MAX, REINT_LEN, "Ingrese un numero", "Error");
			break;

			case 2:
			pedirFloatAlUsuario(&operadorDos,&scanOperadorDos, MIN, MAX, REINT_LEN, "Ingrese un numero", "Error");
			break;

			case 3:
			if(scanOperadorUno==1 && scanOperadorDos==1)
			{
				scanSuma=sumar(operadorUno, operadorDos, &suma);
				scanResta=restar(operadorUno, operadorDos, &resta);
				scanMultiplicacion=multiplicar(operadorUno, operadorDos, &multiplicacion);
				scanDivision=dividir(operadorUno, operadorDos, &division);
				scanFactorial1=factorial((int)operadorUno, &factorial1);
				scanFactorial2=factorial((int)operadorDos, &factorial2);


				printf("\n¡¡¡Se realizaron las operaciones satisfactoriamente!!!\n");
				estadoOperacionesMath=0;

			}
			else
				{
					printf("\n¡¡¡No se pueden realizar las operaciones!!!");

					if(scanOperadorUno==0 && scanOperadorDos==0)
					{
						printf("\n¡¡¡Faltan ingresar ambos operadores!!!\n");
					}
					else
					{
						if(scanOperadorUno==0)
						{
							printf("\n¡¡¡Falta ingresar el operador Uno!!!\n");
						}
						else
							{
								printf("\n¡¡¡Falta ingresar el operador Dos!!!\n");
							}
					}
				}
			break;

			case 4:
			if(estadoOperacionesMath==0)
			{
				if(scanSuma==0)
				{
					printf("\nEl resultado de %.2f + %.2f es: %.2f", operadorUno, operadorDos ,suma);
				}
					else
					{
						printf("\nAlgo fallo en la operacion. No se puede imprimir la Suma.");
					}

				if(scanResta==0)
				{
					printf("\nEl resultado de %.2f -  %.2f es:  %.2f", operadorUno, operadorDos ,resta);
				}
					else
					{
						printf("\nAlgo fallo en la operacion. No se puede imprimir la Resta.");
					}

				if(scanMultiplicacion==0)
				{
					printf("\nEl resultado de  %.2f *  %.2f es:  %.2f", operadorUno, operadorDos ,multiplicacion);
				}
					else
					{
						printf("\nAlgo fallo en la operacion. No se puede imprimir la Multiplicacion.");
					}


				if(scanDivision==0)
				{
					printf("\nEl resultado de  %.2f /  %.2f es: %.2f", operadorUno, operadorDos ,division);
				}
					else
					{
						printf("\nEl resultado de  %.2f /  %.2f es: No se puede dividir por 0", operadorUno, operadorDos);
					}


				if(scanFactorial1==0 && scanFactorial2==0)
				{
					printf("\nEl factorial de  %.2f es:  %.2f y el factorial de  %.2f es:  %.2f\n",operadorUno,factorial1,operadorDos,factorial2);
				}
				else
				{
					if(operadorUno<0 && operadorDos>=0)
					{
						printf("\nEl operador 1 es Negativo. Por ahora no sabemos usar la funcion Gamma y el factorial de  %.2f es:  %.2f\n",operadorDos,factorial2);
					}
					else if(operadorUno>=0 && operadorDos<0)
					{
						printf("\nEl factorial de  %.2f es:  %.2f y el operador 2 es Negativo. Por ahora no sabemos usar la funcion Gamma.\n",operadorUno,factorial1);
					}
				}

				if(operadorUno<0 && operadorDos<0)
				{
					printf("\nLos operadores son Negativos. Por ahora no sabemos usar la funcion Gamma.\n");
				}

				estadoOperacionesMath=-1;
				scanOperadorUno=0;
				scanOperadorDos=0;

			}
				else
			    {
					if(estadoOperacionesMath!=1)
					{
						printf("\n¡¡¡No se puede imprimir!!! \n¡¡¡Falta realizar las operaciones matemáticas!!!");
					}

					if(scanOperadorUno!=1 && scanOperadorDos!=1)
					{
						printf("\n¡¡¡Faltan ingresar ambos operadores!!!\n");
					}
						else
						{
							if(scanOperadorUno!=1 )
							{
								printf("\n¡¡¡Falta ingresar el operador Uno!!!\n");
							}
							else if(scanOperadorDos!=1 )
							{
								printf("\n¡¡¡Falta ingresar el operador Dos!!!\n");
							}
						}
				}
			break;

			case 5:
			printf("\n¿Esta seguro que quiere salir del menu?");
			printf("\nSi quiere salir del menu ingrese 0. \nSi quiere permanecer en el menu ingrese 1.");
			printf("\nIngrese la opcion deseada: ");
			scanf("%d",&respuestaFinal);
			if(respuestaFinal==0)
			{
				printf("Usted salió del menu.");
			}
			break;
		}//fin del switch

	}while(respuestaFinal!=0);

	return EXIT_SUCCESS;
}


