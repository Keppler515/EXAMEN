/*
 * Arcades.h
 *
 *  Created on: 17 oct. 2021
 *      Author: maxis
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn_biblioteca.h"
#include "Salones.h"

#ifndef ARCADES_H_
#define ARCADES_H_

#define CHAR_LEN	64
#define CANT_ARCADE	1000
#define CANT_SALON	100

typedef struct
{
	char nacionalidad[CHAR_LEN];
	int tipo;
	int jugadores;
	int fichasMax;
	char nombreJuego[CHAR_LEN];
	int idArcade;
	int isEmpty;
	int idSalon;
}Arcade;



int initArcade(Arcade list[], int len);
int Arcade_loadArcade(Arcade* pList, Salon pListaSalon[], int* idSalon);
int modifyArcadeById(Arcade list[], int len, int id);
int removeArcadeById(Arcade list[], int len, int id);
int removeArcadeByIdSalon(Arcade list[], int len, int id);
int findArcadeById(Arcade list[], int len, int id);
int findArcadeByIdSalon(Arcade list[], int len, int id);
int printArcade(Arcade list[], int len);
int Arcade_altaForzada(Arcade* pList, int len, char nacionalidad[], int tipo, int jugadores, int fichas,char juego[], int idSalon);
int generadorArcadeID(void);
int buscarArcadeLibre(Arcade list[], int len);
int listaJuegos(Arcade list[], int len);
int printJuegos(Arcade list[], int len);


#endif /* ARCADES_H_ */
