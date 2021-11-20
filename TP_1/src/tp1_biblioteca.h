/*
 * tp1_biblioteca.h
 *
 *  Created on: 18 sep. 2021
 *      Author: Aye
 */

#ifndef TP1_BIBLIOTECA_H_
#define TP1_BIBLIOTECA_H_

void menuDeOpciones(int* pRespuesta, int scanUno, int scanDos, float primerOper, float segundoOper);
int pedirFloatAlUsuario(float* pResultado,int* pSalidaScanf, float min, float max, int reintentos, char* variableTexto, char* textoError);
int sumar(float operador1, float operador2, float* pSuma);
int restar(float operador1, float operador2, float* pResta);
int multiplicar(float operador1, float operador2, float* pMultiplicacion);
int dividir(float operador1, float operador2, float* pDivision);
int factorial(int operador, float* pResultFactorial);


#endif /* TP1_BIBLIOTECA_H_ */
