/*
 * Arcades.c
 *
 *  Created on: 17 oct. 2021
 *      Author: maxis
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn_biblioteca.h"
#include "Arcades.h"
#include "Salones.h"

#define CHAR_LEN	64
#define CANT_ARCADE	1000
#define CANT_SALON	100

/** \brief 	Inicializa todas las posiciones del array con un flag isEmpty=0 para indicar que las posiciones están libres.
 *
 * \param 	Arcade list[] es un puntero al array de arcades.
 * \param	int len recibe la longitud del array.
 * return	retorno = -1 ERROR. retorno = 0 OK.
 */

int initArcade(Arcade list[], int len)
{
	int retorno = -1;
	int i;

	if(list!=NULL && len>=0)
	{
		for(i=0;i<len;i++)
		{
			list[i].isEmpty = 0;
		}
	}

	return retorno;
}

//****************************

/** \brief 	Pide los datos para dar de alta un Arcade
 *
 * \param 	Arcade list[] es un puntero al array de arcades.
 * \param 	pListaSalon[] es un puntero al array de salones.
 * \param	int len recibe la longitud del array de salones.
 * return	retorno = -1 ERROR. retorno = 0 OK.
 */

int Arcade_loadArcade(Arcade pList[], Salon pListaSalon[], int* idSalon)
{
	char nacionAux[CHAR_LEN];
	int tipoAux;
	int jugadoresAux;
	int fichasMaxAux;
	char nombreJuegoAux[CHAR_LEN];
	int retorno = -1;
	int index;
	int idSalonAux;

	index = buscarArcadeLibre(pList, CANT_ARCADE);

	if(pList != NULL && pListaSalon != NULL)
	{
		if(utn_getNumero(&idSalonAux, "ID DEL SALON AL QUE PERTENECE: \n", "ERROR")==0)
		{
			if(findSalonById(pListaSalon, CANT_SALON, idSalonAux)>=0)
			{
				printSalonById(pListaSalon, CANT_SALON, idSalonAux);

				if(utn_getText(nacionAux, sizeof(nacionAux), "INGRESE UNA NACIONALIDAD: ", "ERROR")==0)
				{
					if(utn_getNumero(&tipoAux, "INGRESE TIPO:\n"
												"\t1. MONO\n"
												"\t2.ESTEREO\n"
												, "ERROR4")==0 && tipoAux>0&&tipoAux<3)
					{
						if(utn_getNumero(&jugadoresAux, "CANTIDAD DE JUGADORES: ", "ERROR")==0)
						{
							if(utn_getNumero(&fichasMaxAux, "CANTIDAD MAXIMA DE FICHAS: ", "ERROR")==0)
							{
								if(utn_getText(nombreJuegoAux, CHAR_LEN, "NOMBRE DEL JUEGO: ", "ERROR")==0)
								{
									pList[index].tipo = tipoAux;
									pList[index].idArcade = generadorArcadeID();
									pList[index].idSalon = idSalonAux;
									pList[index].jugadores = jugadoresAux;
									pList[index].fichasMax = fichasMaxAux;
									strncpy(pList[index].nacionalidad,nacionAux,sizeof(pList[index].nacionalidad));
									strncpy(pList[index].nombreJuego,nombreJuegoAux,sizeof(pList[index].nombreJuego));
									pList[index].isEmpty = 1;
									retorno = 0;
								}
							}
						}
					}
					else
					{
						puts("TIPO INCORRECTO\n");
					}
				}
			}
		}
	}
	return retorno;

}

//****************************

/** \brief 	Pide los datos para modificar un Arcade
 *
 * \param 	Arcade list[] es un puntero al array de arcades.
 * \param	int len recibe la longitud del array de arcades.
 * \param	int id recibe el id del arcade a modificar.
 * return	retorno = -1 ERROR. retorno = 0 OK.
 */

int modifyArcadeById(Arcade list[], int len, int id)
{
	int jugadoresAux;
	char nombreJuegoAux[CHAR_LEN];
	int opcionAux;
	int retorno = -1;
	char monoImp[16]="MONO";
	char estereoImp[16]="ESTEREO";
	char tipoImp[16];

	int index = findArcadeById(list, len, id);
	int bufferLibre = buscarArcadeLibre(list, len);

	if(list!=NULL && len>0)
	{
		if(index>=0 && list[index].isEmpty==1)
		{
			switch(list[index].tipo)
			{
				case 1:
					strcpy(tipoImp,monoImp);
				break;
				case 2:
					strcpy(tipoImp,estereoImp);
				break;
			}

			printf(	"ID ARCADE: %d\n"
					"JUEGO: %s\n"
					"NACIONALIDAD: %s\n"
					"TIPO: %s\n"
					"JUGADORES: %d\n"
					"FICHAS: %d\n"
					"ID SALON: %d\n"
					,list[index].idArcade,list[index].nombreJuego,list[index].nacionalidad,tipoImp,list[index].jugadores,list[index].fichasMax,list[index].idSalon);

			if(utn_getNumero(&opcionAux,"\n¿QUE DATO DESEA MODIFICAR?\n\n"
										"\t1. CANTIDAD JUGADORES\n"
										"\t2. JUEGO\n", "ERROR.\n")==0)
			{
				switch(opcionAux)
				{
				case 1:
					if(utn_getNumero(&jugadoresAux, "INGRESE CANTIDAD DE JUGADORES: ","ERROR\n")==0)
					{
						list[index].jugadores = jugadoresAux;
						puts("CAMBIO REALIZADO CON EXITO\n");
					}
				break;

				case 2:
					listaJuegos(list, len);
					if(utn_getText(nombreJuegoAux, len, "\nINGRESE NUEVO JUEGO: ", "ERROR\n")==0)
					{
						strncpy(list[index].nombreJuego,nombreJuegoAux,sizeof(list[index].nombreJuego));
						strncpy(list[bufferLibre].nombreJuego,nombreJuegoAux,sizeof(list[bufferLibre].nombreJuego));
						list[bufferLibre].isEmpty = 1;
						puts("CAMBIO REALIZADO CON EXITO\n");
					}
				break;

				default:
					puts("OPCION INCORRECTA\n");
				break;
				}
			}
		retorno = 0;
		}
		else
		{
			puts("\nERROR\n");
			//break;
		}
	}

	return retorno;
}

//****************************

/** \brief 	Pide los datos para eliminar un Arcade
 *
 * \param 	Arcade list[] es un puntero al array de arcades.
 * \param	int len recibe la longitud del array de arcades.
 * \param	int id recibe el id del arcade a eliminar.
 * return	retorno = -1 ERROR. retorno = 0 OK.
 */

int removeArcadeById(Arcade list[], int len, int id)
{
	int retorno = -1;
	int opcionAux;
	char monoImp[16]="MONO";
	char estereoImp[16]="ESTEREO";
	char tipoImp[16];

	printArcade(list, len);

	int index = findArcadeById(list, len, id);

	if(list!=NULL && len>0)
	{
		if(index>=0 && list[index].isEmpty==1)
		{
			switch(list[index].tipo)
						{
							case 1:
								strcpy(tipoImp,monoImp);
							break;
							case 2:
								strcpy(tipoImp,estereoImp);
							break;
						}

						printf(	"ESTA A PUNTO DE ELIMINAR EL SIGUIENTE ARCADE:\n\n"
								"ID ARCADE: %d\n"
								"JUEGO: %s\n"
								"NACIONALIDAD: %s\n"
								"TIPO: %s\n"
								"JUGADORES: %d\n"
								"FICHAS: %d\n"
								"ID SALON: %d\n"
								,list[index].idArcade,list[index].nombreJuego,list[index].nacionalidad,tipoImp,list[index].jugadores,list[index].fichasMax,list[index].idSalon);

			if(utn_getNumero(&opcionAux,"\nDESEA ELIMINAR LOS DATOS? 1-SI / 2-NO\n", "ERROR")==0)
			{
				switch(opcionAux)
				{
					case 1:
						list[index].isEmpty=-1;
						retorno = 0;
					break;

					case 2:
						puts("\nCANCELADO\n");
					break;
				}//FIN switch
			}//FIN if getNumero
		}
		else
		{
			puts("\nERROR\n");
		}
	}

	return retorno;
}

//****************************

/** \brief 	Pide los datos para eliminar un Arcade cuando se da de baja un salon
 *
 * \param 	Arcade list[] es un puntero al array de arcades.
 * \param	int len recibe la longitud del array de arcades.
 * \param	int id recibe el idSalon que concide como campo de las dos esdtructuras.
 * return	retorno = -1 ERROR. retorno = 0 OK.
 */

int removeArcadeByIdSalon(Arcade list[], int len, int id)
{
	int retorno = -1;
	int i;

	if(list!=NULL && len>0)
	{
		for(i=0;i<len;i++)
		{
			if(list[i].idSalon == id)
			{
				list[i].isEmpty=-1;
				retorno = 0;
			}
		}
	}


	return retorno;
}

//****************************

/** \brief 	Busca arcade por ID
 *
 * \param 	Arcade list[] es un puntero al array de arcades.
 * \param	int len recibe la longitud del array de arcades.
 * \param	int id recibe el id del arcade a buscar.
 * return	Retorna el indice
 */

int findArcadeById(Arcade list[], int len, int id)
{
	int i;
	int indice = -1;

	if(list!=NULL && len>0)
	{
	for(i=0; i<len; i++)
		{
			if(list[i].idArcade == id && list[i].isEmpty==1)
			{
				indice = i;
				break;
			}

		}
	}
	return indice;
}

//****************************

/** \brief 	Busca arcade por ID de salon
 *
 * \param 	Arcade list[] es un puntero al array de arcades.
 * \param	int len recibe la longitud del array de arcades.
 * \param	int id recibe el id del arcade a buscar.
 * return	Retorna el indice
 */


int findArcadeByIdSalon(Arcade list[], int len, int id)
{
	int i;
	int indice = -1;

	if(list!=NULL && len>0)
	{
	for(i=0; i<len; i++)
		{
			if(list[i].idSalon == id && list[i].isEmpty==1)
			{
				indice = i;
				break;
			}

		}
	}
	return indice;
}

//****************************

/** \brief 	Imprime lista de Arcades
 *
 * \param 	Arcade list[] es un puntero al array de arcades.
 * \param	int len recibe la longitud del array de arcades.
 * return	retorno = -1 ERROR. retorno = 0 OK.
 */


int printArcade(Arcade list[], int len)
{
	int retorno = -1;
	int i;
	char monoImp[16]="MONO";
	char estereoImp[16]="ESTEREO";
	char tipoImp[16];

	if(list!=NULL && len>0)
	{
		for(i=0; i<len; i++)
		{
			if(list[i].isEmpty == 1)
			{
				switch(list[i].tipo)
				{
					case 1:
						strcpy(tipoImp,monoImp);
					break;
					case 2:
						strcpy(tipoImp,estereoImp);
					break;

				}

				printf(	"\nID ARCADE: %d\n"
						"JUEGO: %s\n"
						"NACIONALIDAD: %s\n"
						"TIPO: %s\n"
						"JUGADORES: %d\n"
						"FICHAS: %d\n"
						"ID SALON: %d\n\n"
						,list[i].idArcade,list[i].nombreJuego,list[i].nacionalidad,tipoImp,list[i].jugadores,list[i].fichasMax,list[i].idSalon);

				retorno = 0;
			}
		}

	}

	return retorno;
}

//****************************

/** \brief 	Inicializa lista de Arcades
 *
 * \param 	Pide todos los parametros que necesita un array de arcades.
 * return	retorno = -1 ERROR. retorno = 0 OK.
 */


int Arcade_altaForzada(Arcade* pList, int len, char nacionalidad[], int tipo, int jugadores, int fichas,char juego[], int idSalon)
{
	int retorno = -1;
	int idArcadeAux;
	//int idSalonAux;
	int indice = buscarArcadeLibre(pList, len);

	idArcadeAux = generadorArcadeID();
	//idSalonAux = generadorSalonID();

	if(pList != NULL && len>0)
	{
		pList[indice].tipo = tipo;
		pList[indice].idArcade = idArcadeAux;
		//pList[indice].idSalon = idSalonAux;
		pList[indice].idSalon = idSalon;
		pList[indice].jugadores = jugadores;
		pList[indice].fichasMax = fichas;
		strncpy(pList[indice].nacionalidad,nacionalidad,sizeof(pList[indice].nacionalidad));
		strncpy(pList[indice].nombreJuego,juego,sizeof(pList[indice].nombreJuego));
		pList[indice].isEmpty = 1;
		retorno = 0;
	}

	return retorno;

}

//****************************

/** \brief 	busca lugar libre en array Arcades
 *
 * \param 	Arcade list es un punter al array de arcades
 * \param	len es la longitud del array
 * return	retorno = -1 ERROR. retorno = 0 OK.
 */


int buscarArcadeLibre(Arcade list[], int len)
{
	int i;
	int indice = -1;

	if(list!=NULL && len>0)
	{
		for(i=0;i<len;i++)
		{
			if(list[i].isEmpty==0)
			{
				indice=i;
				break;
			}
		}
	}
	return indice;
}

//****************************

/** \brief 	Genera un ID consecutivo para array Arcades
 *
 */


int generadorArcadeID(void)
{
	static int contador = 0;
	contador++;
	return contador;
}

//****************************

/** \brief 	Imprime lista de Juegos sin repetir Arcades
 *
* \param 	Arcade list es un punter al array de arcades
 * \param	len es la longitud del array
 * return	retorno = -1 ERROR. retorno = 0 OK.
 */


int listaJuegos(Arcade list[], int len)
{
int retorno = -1;
	int i;
	Arcade buffer;
	int flagSwap;
	if(list!=NULL && len>0)
	{
		do
		{
			flagSwap = 0;
			for(i=0; i<len-1; i++)
			{
				if(strcmp(list[i].nombreJuego,list[i+1].nombreJuego)>0)
				{
					flagSwap = 1;
					buffer=list[i];
					list[i]=list[i+1];
					list[i+1]=buffer;
				}
			}//FIN for
		}while(flagSwap);

		for(i=0;i<len;i++)
		{
		    if(strcmp(list[i].nombreJuego,list[i+1].nombreJuego)!=0)
    		{
    		    printf("%s\n",list[i].nombreJuego);
    		}
		}

		retorno = 0;
	}
	return retorno;
}
//****************************

/** \brief 	Imprime lista de Juegos sin repetir Arcades (ALTERNATIVO)
 *
* \param 	Arcade list es un punter al array de arcades
 * \param	len es la longitud del array
 * return	retorno = -1 ERROR. retorno = 0 OK.
 */


int printJuegos(Arcade buffer[], int len)
{
	int retorno = -1;
	int i;

	if(buffer!=NULL && len<0)
	{
		for(i=0;i<len;i++)
		{
			if(buffer[i].isEmpty == 1)
			{
				printf("%s\n",buffer[i].nombreJuego);
			}
		}
	}
	return retorno;
}


//************************************************************************

