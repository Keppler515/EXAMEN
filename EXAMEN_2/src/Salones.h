/*
 * Salones.h
 *
 *  Created on: 17 oct. 2021
 *      Author: maxis
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn_biblioteca.h"

#ifndef SALONES_H_
#define SALONES_H_

#define CHAR_LEN	64
#define CANT_ARCADE	1000
#define CANT_SALON	100

typedef struct
{
	char nombre[CHAR_LEN];
	char direccion[CHAR_LEN];
	int tipo;
	int isEmpty;
	int id;
	float precio;
}Salon;


int initSalon(Salon list[], int len);
int Salon_loadSalon(Salon* pList, int* idSalon);
int modifySalonById(Salon list[], int len, int id);
int removeSalonById(Salon list[], int len,int id);
int findSalonById(Salon list[], int len, int id);
int printSalon(Salon list[], int len);
int printSalonById(Salon list[], int len, int id);
int Salon_altaForzada(Salon* pList, int len,int indice, int tipo, float precio, char nombre[], char direccion[]);
int generadorSalonID(void);
int buscarSalonLibre(Salon list[], int len);


#endif /* SALONES_H_ */
