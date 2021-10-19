/*
 * Informes.c
 *
 *  Created on: 18 oct. 2021
 *      Author: maxis
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn_biblioteca.h"
#include "Salones.h"
#include "Arcades.h"

int masDeCuatroArcades(Arcade list[], int len, Salon listaSalones[])
{
	int i;
	int retorno = -1;
	int contador = 0;
	int j;
	int idRepetido;

	for(i=0;i<len;i++)
	{
		for(j=1;j<len;j++)
		{
			if(list[i].isEmpty==1)
			{
				if(list[i].idSalon==list[j].idSalon)
				{
					idRepetido = list[i].idSalon;
					contador++;
					break;
				}
			}

		}
		if(contador>4)
		{
			printSalonById(listaSalones, len, idRepetido);
			break;
		}
	}
	return retorno;
}

//******************************************

int masDeDosJugadores(Arcade list[], int len)
{
	int i;
	int retorno = -1;

	for(i=0;i<len;i++)
	{
		if(list[i].isEmpty==1)
		{
			if(list[i].jugadores>2)
			{
				printf(	"\nID ARCADE: %d\n"
						"JUEGO: %s\n"
						"NACIONALIDAD: %s\n"
						"TIPO: %d\n"
						"JUGADORES: %d\n"
						"FICHAS: %d\n"
						"ID SALON: %d\n\n"
						,list[i].idArcade,list[i].nombreJuego,list[i].nacionalidad,list[i].tipo,list[i].jugadores,list[i].fichasMax,list[i].idSalon);

			}

		}

	}
	return retorno;
}

//******************************************


int listarSalonEspecifico(Salon list[], int len, int id, Arcade listaArcades[])
{
	int retorno = -1;
	int index;
	char shoppingImp[16]="SHOPPING";
	char localImp[16]="LOCAL";
	char tipoImp[16];
	int i;
	int contador = 0;

	index = findSalonById(list, len, id);

	if(list!=NULL && len>0)
	{
		if(list[index].isEmpty == 1)
		{
			switch(list[index].tipo)
			{
				case 1:
					strcpy(tipoImp,shoppingImp);
				break;
				case 2:
					strcpy(tipoImp,localImp);
				break;
			}

			for(i=0;i<CANT_ARCADE;i++)
			{
				if(listaArcades[i].idSalon==id)
				{
					contador++;
				}
			}

			printf(	"\n"
					"TIPO: %s\n"
					"NOMBRE: %s\n"
					"DIRECCION: %s\n"
					"ID: %d\n"
					"CANTIDAD DE ARCADES: %d\n\n"
					,tipoImp,list[index].nombre,list[index].direccion,list[index].id,contador);
			retorno = 0;
		}

	}

	return retorno;
}

//******************************************


int listarArcadesSalon(Salon list[], int len, int id, Arcade listaArcades[])
{
	int retorno = -1;
	int index;
	char shoppingImp[16]="SHOPPING";
	char localImp[16]="LOCAL";
	char tipoImp[16];
	char monoImp[16]="MONO";
	char estereoImp[16]="ESTEREO";
	char tipoImpA[16];
	int i;

	index = findSalonById(list, len, id);

	if(list!=NULL && len>0)
	{
		if(list[index].isEmpty == 1)
		{
			switch(list[index].tipo)
			{
				case 1:
					strcpy(tipoImp,shoppingImp);
				break;
				case 2:
					strcpy(tipoImp,localImp);
				break;
			}

			printf(	"\n"
					"TIPO: %s\n"
					"NOMBRE: %s\n"
					"DIRECCION: %s\n"
					"ID: %d\n"
					,tipoImp,list[index].nombre,list[index].direccion,list[index].id);

			for(i=0;i<CANT_ARCADE;i++)
			{
				if(listaArcades[i].idSalon==id)
				{
					switch(listaArcades[i].tipo)
					{
						case 1:
							strcpy(tipoImpA,monoImp);
						break;
						case 2:
							strcpy(tipoImpA,estereoImp);
						break;
					}
					printf(	"\nID ARCADE: %d\n"
							"JUEGO: %s\n"
							"NACIONALIDAD: %s\n"
							"TIPO: %s\n"
							"JUGADORES: %d\n"
							"FICHAS MAX: %d\n"
							,listaArcades[i].idArcade,listaArcades[i].nombreJuego,listaArcades[i].nacionalidad,tipoImpA,listaArcades[i].jugadores,listaArcades[i].fichasMax);

				}
			}

			retorno = 0;
		}

	}

	return retorno;
}

//******************************************

int salonMasArcades(Arcade list[], int len, Salon listaSalones[])
{
	int i;
	int retorno = -1;
	int contador = 0;
	int maximo;
	int j;
	int idSalonMaximo;

	for(i=0;i<len;i++)
	{
		for(j=1;j<len;j++)
		{
			if(list[i].isEmpty==1)
			{
				if(list[i].idSalon==list[j].idSalon)
				{
					contador++;
					idSalonMaximo = list[i].idSalon;
					break;
				}
			}
		}
		maximo = contador;
		if(contador>maximo)
		{
			maximo = contador;
			idSalonMaximo = list[i].idSalon;
		}
	}

	listarSalonEspecifico(listaSalones, CANT_SALON, idSalonMaximo, list);
	return retorno;
}

//******************************************

int maximoPesos(Arcade list[], int lenA, Salon listaSalon[])
{
	int i;
	int retorno = -1;
	int contador = 0;
	int acumuladorF = 0;
	int valorFicha;
	int idGuardado;
	int pesosMaximo;


	utn_getNumero(&idGuardado, "\nID: ", "ERROR\n");
	utn_getNumero(&valorFicha, "\nVALOR FICHA: ", "ERROR\n");
	findSalonById(listaSalon, CANT_SALON, idGuardado);


	for(i=0;i<lenA;i++)
	{
		if(list[i].isEmpty==1)
		{
			if(list[i].idSalon==idGuardado)
			{
				acumuladorF+=list[i].fichasMax;
				contador++;
			}
		}
	}

	pesosMaximo = acumuladorF*valorFicha;

	printf("\nLA CANTIDAD MAXIMA DE PESOS ES: %d\n",pesosMaximo);

	return retorno;
}

//******************************************

int cuantosArcades(Arcade list[], int lenA)
{
	int i;
	int retorno = -1;
	int contador = 0;
	char juego[CHAR_LEN];
	utn_getText(juego, CHAR_LEN, "JUEGO: ", "ERROR\n");

	for(i=0;i<lenA;i++)
	{
		if(strcmp(juego,list[i].nombreJuego)==0)
		{
			contador++;
		}
	}

	printf("\n%s SE ENCUENTRA EN %d ARCADES.\n\n",juego,contador);
	return retorno;
}
