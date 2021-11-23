/*
 * Pantalal.h
 *
 *  Created on: 30 sep. 2021
 *      Author: Aye
 */

#ifndef ARCADE_H_
#define ARCADE_H_

#define NOMBREJUEGO_LEN 63
#define NACIONALIDAD_LEN 50
#define LIBRE 1
#define Ocupado 0

typedef struct
{
	int tipoDeSonido;
	int cantidadJugadores;
	int capacidadMaximaFichas;
	int idArcade;
	int idSalon;
	char nombreDelJuego[NOMBREJUEGO_LEN];
	char nacionalidad[NACIONALIDAD_LEN];
	int isEmpty; // 0:ocupado    1:vacio/libre
}Arcade;


int arcade_initList(Arcade* list, int len);
int arcade_loadArray(Arcade* list, int idSalon);
void arcade_printArrayCompleto(Arcade* list, int len);
void arcade_printCompleto(Arcade* list);
int arcade_buscarPosicionLibre(Arcade* list, int len, int* pPosicionLibre);
int arcade_buscarPosicionOcupado(Arcade* list, int len, int* pPosicionOcupado);
int arcade_buscarId(Arcade* list, int len, int* pIdBuscado);
int arcade_buscarPosicionId(Arcade* list, int len, int IdEncontrado, int* pPosicionIdBuscado);
int arcade_modificarArray(Arcade* list, int len, int posicionId);
int arcade_bajaArray(Arcade* list, int len,int idEncontrado, int posicionId);
void arcade_altaForzada(Arcade* list,int len, int indice,int idArcade, char* nombreDelJuego, char* nacionalidad, int tipoDeSonido, int capacMaximaFichas,int cantidadJugadores ,int idSalon);

#endif /* ARCADE_H_ */
