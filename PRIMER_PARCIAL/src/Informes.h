/*
 * Informes.h
 *
 *  Created on: 19 oct. 2021
 *      Author: Aye
 */

#ifndef INFORMES_H_
#define INFORMES_H_

typedef struct
{
	char Juegos[63];
	int isEmpty;
}Game;

void game_initList(Game* list, int len);
int game_estaJuegoEnLista(Game* list, int len,char juegos[]);
int game_imprimirJuegos(Arcade* listArcade, int lenArcade);
void salon_MenuInformes(int* opcionDeMenuInformes);
int inf_printSalonesCuatroArcade(Salon* listSalon, int lenSalon,Arcade* listArcade, int lenArcade);
void menuPrincipal(int* opcionDeMenu);
int inf_contDeArcade(Arcade* list, int len);
int inf_contDeSalon(Salon* list, int len);
float inf_promedioArcadePorSalon(int contArc, int contSalon);
int inf_printArcadeDosJugadores(Arcade* listArcade, int lenArcade, Salon* listSalon, int lenSalon);
int inf_printSalonInfo(Salon* listSalon, int lenSalon,Arcade* listArcade, int lenArcade);
void inf_printSalonPorId(Salon* listSalon, int lenSalon,int idSalon);
void inf_printArcadePorIdSalon(Arcade* listArcade, int lenArcade, int idSalon);
int inf_printSalonesMayorCantArcade(Salon* listSalon, int lenSalon,Arcade* listArcade, int lenArcade);
void inf_printCantMaximaFichaPorSalon(Arcade* listArcade, int lenArcade);
int inf_printSalonCompleto(Salon* listSalon, int lenSalon,Arcade* listArcade, int lenArcade);
int inf_imprimirArcadePorJuegos(Arcade* listArcade, int lenArcade);

#endif /* INFORMES_H_ */
