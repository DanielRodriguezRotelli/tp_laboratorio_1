/*
 * Arcade.h
 *
 *  Created on: 20 nov. 2021
 *      Author: Aye
 */

#ifndef ARCADE_H_INCLUDED
#define ARCADE_H_INCLUDED

#include "LinkedList.h"

#define NAME_LEN 63
#define MONO 0
#define STEREO 1


typedef struct
{
    int id;
    int tipoDeSonido;
    int cantidadDeJugadores;
    int capacidadDeFichas;
    char nacionalidad[NAME_LEN];
    char nombreDeSalon[NAME_LEN];
    char nombreDeJuego[NAME_LEN];
}Arcade;

Arcade* arcade_new(void);
Arcade* arcade_newParametros(char* idStr,char* sonidoStr,char* cantidadJugadoresStr, char* capacidadFichasStr, char* nacionalidadStr, char* nombreSalonStr, char* nombreJuegoStr);
void arcade_delete(Arcade* this);

int arcade_findById(LinkedList* pList, int id);

int arcade_setId(Arcade* this,int id);
int arcade_getId(Arcade* this,int* id);

int arcade_setSonidoChar(Arcade* this,char* sonido);
int arcade_getSonidoChar(Arcade* this,char* sonido);

int arcade_setSonidoInt(Arcade* this,int sonido);
int arcade_getSonidoInt(Arcade* this,int* sonido);

int arcade_setCantidadJugadores(Arcade* this,int cantidadJugadores);
int arcade_getCantidadJugadores(Arcade* this,int* cantidadJugadores);

int arcade_setCapacidadFichas(Arcade* this,int capacidadFichas);
int arcade_getCapacidadFichas(Arcade* this,int* capacidadFichas);

int arcade_setNacionalidad(Arcade* this,char* nacionalidad);
int arcade_getNacionalidad(Arcade* this,char* nacionalidad);

int arcade_setNombreSalon(Arcade* this,char* nombreSalon);
int arcade_getNombreSalon(Arcade* this,char* nombreSalon);

int arcade_setNombreJuego(Arcade* this,char* nombreJuego);
int arcade_getNombreJuego(Arcade* this,char* nombreJuego);

int arcade_compareName(void* a, void* b);
int arcade_compareId(void* a, void* b);

int arcade_getIdMax(char* path);

void arcade_printArcade(void* pAuxiliar);
void arcade_newCoinsArcade(void* pAuxiliar);
int arcade_isMultiplayer(void* pAuxiliar);
int arcade_printListGames(LinkedList* pArrayListArcade);

#endif
