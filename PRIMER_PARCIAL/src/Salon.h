/*
 * Pantalal.h
 *
 *  Created on: 30 sep. 2021
 *      Author: Aye
 */

#ifndef SALON_H_
#define SALON_H_

#define NAME_LEN 128
#define ADDRES_LEN 128
#define LIBRE 1
#define Ocupado 0

typedef struct
{
	int tipo;
	int idSalon;
	char nombre[128];
	char direccion[128];
	int isEmpty; // 0:ocupado    1:vacio/libre
}Salon;



int salon_initList(Salon* list, int len);
int salon_loadArray(Salon* list);
void salon_printArrayCompleto(Salon* list, int len);
void salon_printCompleto(Salon* list);
void salon_printAEliminar(Salon* list);
void salon_printArrayAEliminar(Salon* list, int len);
void salon_MostrarPorReferencia(Salon* list, int len);
int salon_buscarPosicionLibre(Salon* list, int len, int* pPosicionLibre);
int salon_buscarPosicionOcupado(Salon* list, int len, int* pPosicionOcupado);
int salon_buscarId(Salon* list, int len, int* pIdBuscado);
int salon_buscarPosicionId(Salon* list, int len, int* pPosicionIdBuscado);
int salon_modificarArray(Salon* list, int len, int posicionIdPantalla);
int salon_bajaArray(Salon* list, int len, int posicionId);
void salon_altaForzada(Salon* list,int len, int indice,int idSalon, char* nombre, char* direccion, int tipo);

#endif /* SALON_H_ */
