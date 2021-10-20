/*
 ============================================================================
 Name        : EXAMEN.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn_biblioteca.h"
#include "Salones.h"
#include "Arcades.h"
#include "Informes.h"


#define CHAR_LEN	64
#define CANT_ARCADE	1000
#define CANT_SALON	100
#define SHOPPING	1
#define SALON		2


int main(void)
{

	setbuf(stdin,NULL);

	Salon	listaSalones[CANT_SALON];
	Arcade 	listaArcades[CANT_ARCADE];
	//Arcade 	bufferJuegos[CANT_ARCADE];

	int opcion;
	int idAux;
	int idSalonAux;
	char informeAux;
	int flagAlta = 0;
	int flagArcade = 0;
	int flagJuegos = 0;

	initSalon(listaSalones, CANT_SALON);
	initArcade(listaArcades, CANT_ARCADE);

	Salon_altaForzada(listaSalones, CANT_SALON, 0, 2, 0, "Sacoa", "Lavalle");
	Salon_altaForzada(listaSalones, CANT_SALON, 4, 2, 0, "PlayCenter", "Avell");
	Salon_altaForzada(listaSalones, CANT_SALON, 7, 2, 0, "CotoJuegos", "Lanus");
	printf("\n");
	flagAlta = 1;


	Arcade_altaForzada(listaArcades, CANT_ARCADE,"EEUU", 1, 2, 100, "StreetFighter",1);
	Arcade_altaForzada(listaArcades, CANT_ARCADE,"EEUU", 2, 2, 200, "MortalKombat",2);
	Arcade_altaForzada(listaArcades, CANT_ARCADE,"EEUU", 2, 2, 200, "MortalKombat",2);
	Arcade_altaForzada(listaArcades, CANT_ARCADE,"EEUU", 2, 4, 150, "SunsetRiders",3);
	printf("\n");
	flagArcade = 1;
	flagJuegos = 1;

while(1)
{
	if(utn_getNumero(&opcion, 	"1. Alta de salon\n"
								"2. Eliminar Salon\n"
								"3. Imprimir Salones\n"
								"4. Incorporar arcade\n"
								"5. Modificar arcade\n"
								"6. Eliminar arcade\n"
								"7. Imprimir arcades\n"
								"8. Imprimir juegos\n"
								"9. Informes\n\n", "ERROR1\n")==0)
	{
		switch(opcion)
		{
			case 1:
				if(Salon_loadSalon(listaSalones, &idSalonAux)==0)
				{
					flagAlta = 1;
				}
			break;

			case 2:
				if(flagAlta==1)
				{
					printSalon(listaSalones, CANT_SALON);

					if(utn_getNumero(&idAux, "INGRESE ID DEL SALON A ELIMINAR: ", "ERROR\n")==0)
					{
						if(removeSalonById(listaSalones, CANT_SALON,idAux)==0)
						{
							if(removeArcadeByIdSalon(listaArcades, CANT_ARCADE, idAux)==0)
							{
								puts("DATOS ELIMINADOS EXITOSAMENTE\n");
							}
						}
						else
						{
							puts("ERROR\n");
						}
					}
				}
				else
				{
					puts("NO HAY DATOS PARA MOSTRAR\n");
				}
			break;

			case 3:
				if(flagAlta == 1)
				{
					printSalon(listaSalones, CANT_SALON);
				}
				else
				{
					puts("NO HAY DATOS PARA MOSTRAR\n");
				}
			break;

			case 4:
				if(flagAlta == 1)
				{
					if(Arcade_loadArcade(listaArcades, listaSalones, &idSalonAux)==0)
					{
						flagArcade = 1;
						flagJuegos = 1;

						puts("\nARCADE INGRESADO OK\n");

					}
				}
				else
				{
					puts("NO HAY SALONES ABIERTOS\n");
				}
			break;

			case 5:
				if(flagArcade == 1)
				{
					printArcade(listaArcades,CANT_ARCADE);
					if(utn_getNumero(&idAux, "INGRESE ID A MODIFICAR: ", "ERROR\n")==0)
					{
						if(modifyArcadeById(listaArcades, CANT_ARCADE, idAux)==0)
						{
							puts("DATOS MODIFICADOS EXITOSAMENTE\n");
						}
						else
						{
							puts("ERROR\n");
						}
					}
				}
				else
				{
					puts("NO HAY DATOS PARA MOSTRAR\n");
				}
			break;

			case 6:
				if(flagArcade == 1)
				{
					printArcade(listaArcades,CANT_ARCADE);
					if(utn_getNumero(&idAux, "INGRESE ID DEL ARCADE A ELIMINAR: ", "ERROR\n")==0)
					{
						if(removeArcadeById(listaArcades, CANT_ARCADE, idAux)==0)
						{
							puts("DATOS BORRADOS EXITOSAMENTE\n");
						}
						else
						{
							puts("ERROR\n");
						}
					}
				}
				else
				{
					puts("NO HAY DATOS PARA MOSTRAR\n");
				}
			break;

			case 7:
				if(flagArcade == 1)
				{
					printArcade(listaArcades, CANT_ARCADE);
				}
				else
				{
					puts("NO HAY DATOS PARA MOSTRAR\n");
				}
			break;

			case 8:
				if(flagJuegos == 1)
				{
					listaJuegos(listaArcades, CANT_ARCADE);
				}
				else
				{
					puts("NO HAY JUEGOS PARA MOSTRAR\n");
				}
			break;

			case 9:
				utn_getText(&informeAux, CHAR_LEN, 	"A) Listar los salones con mas de 4 arcades. Indicando ID de salón, nombre, direccion y tipo de salon.\n"
													"B) Listar los arcades para mas de 2 jugadores, indicando ID de arcade, cantidad de jugadores, nombre del juego y nombre del salon al que pertenece.\n"
													"C) Listar toda la informacion de un salon especifico ingresando su ID. Imprimir nombre, tipo y direccion y cantidad de arcades que posee.\n"
													"D) Listar todos los arcades de un salon determinado ingresando su ID. Informar nombre y tipo de salon, listar todods los arcades con sus datos junto con el nombre del juego que lo compone.\n"
													"E) Imprimir el salon con mas cantidad de arcades, indicando todos los datos del salon y la cantidad de arcades que posee.\n"
													"F) Ingresar el ID de un salon y ver el valor en pesos de una ficha e imprimir el monto maximo en pesos que puede recaudar el salon (sumar cantidad de fichas maximo de cada arcade del salon y multiplicarla por el valor en pesos ingresado).\n"
													"G) Ingresar el nombre de un juego e imprimir cuantos arcades lo contienen.\n"
													"H) Un salón se encuentra equipado por completo si posee al menos 8 arcades de mas de 2 jugadores. Listar los salones que cumplan con este mínimo de requisito.\n"
													"I) Imprimir el promedio de arcades por salón. (Cantidad de arcades totales / Cantidad de salones totales).\n", "ERROR\n");
				switch(informeAux)
				{
				case 'A':
					masDeCuatroArcades(listaArcades, CANT_ARCADE, listaSalones);
				break;

				case'B':
					masDeDosJugadores(listaArcades, CANT_ARCADE);
				break;

				case 'C':
					if(utn_getNumero(&idAux, "ID", "ERROR\n")==0)
					{
						listarSalonEspecifico(listaSalones,CANT_SALON,idAux,listaArcades);
					}
				break;

				case 'D':
					if(utn_getNumero(&idAux, "ID", "ERROR\n")==0)
					{
						listarArcadesSalon(listaSalones, CANT_SALON, idAux, listaArcades);
					}
				break;

				case 'E':
					salonMasArcades(listaArcades, CANT_ARCADE, listaSalones);
				break;

				case 'F':
					maximoPesos(listaArcades, CANT_ARCADE, listaSalones);
				break;

				case 'G':
					cuantosArcades(listaArcades, CANT_ARCADE);
				break;

				case 'H':
					salonCompleto(listaArcades, CANT_ARCADE, listaSalones);
				break;

				case 'I':
					promedioArcadeSalon(listaArcades, CANT_ARCADE, listaSalones, CANT_SALON);
				break;
				}

			break;
		}
	}
}

return 0;
}
