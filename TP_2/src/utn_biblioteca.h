/*
 * pedirFloat.h
 *
 *  Created on: 12 sep. 2021
 *      Author: Aye
 */

#ifndef UTN_BIBLIOTECA_H_
#define UTN_BIBLIOTECA_H_

int getFloat(float* pResultado, float min, float max, int reintentos, char* variableTexto, char* textoError);
int getInt(int* pResultado, int min, int max, int reintentos, char* variableTexto, char* textoError);
int getChar(char* pResultado, int min, int max, int reintentos, char* variableTexto, char* textoError);
int getText(char* pResultado, int len, char* variableTexto, char* textoError, int reintentos);
void inicializarArray(int pArray[], int len, int valorInicial);
void imprimirArray(int arrayLista[], int len);
float promedioArrayInt(int arrayInt[], int len);
int menorValorArray(int arrayInt[], int len);
int mayorValorArray(int arrayInt[], int len);
float promedioArrayInt(int arrayInt[], int len);
int borrarImparesArray(int arrayDeEnteros[], int tamanioArray);
void ordenarCrecienteArray(int arrayDeEnteros[], int tamanioArray);
int esTelefono(char cadena[]);
int esAlfaNumerico(char cadena[]);
int esSoloLetras(char cadena[]);






#endif /* UTN_BIBLIOTECA_H_ */
