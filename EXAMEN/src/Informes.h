/*
 * Informes.h
 *
 *  Created on: 18 oct. 2021
 *      Author: maxis
 */

#ifndef INFORMES_H_
#define INFORMES_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn_biblioteca.h"
#include "Salones.h"
#include "Arcades.h"

int masDeCuatroArcades(Arcade list[], int len, Salon listaSalones[]);
int masDeDosJugadores(Arcade list[], int len);
int listarSalonEspecifico(Salon list[], int len, int id, Arcade listaArcades[]);
int listarArcadesSalon(Salon list[], int len, int id, Arcade listaArcades[]);
int salonMasArcades(Arcade list[], int len, Salon listaSalones[]);
int cuantosArcades(Arcade list[], int lenA);
int maximoPesos(Arcade list[], int lenA, Salon listaSalon[]);
int salonCompleto(Arcade list[], int len, Salon listaSalones[]);
int promedioArcadeSalon(Arcade list[], int lenA, Salon listaSalon[], int lenS);

#endif /* INFORMES_H_ */
