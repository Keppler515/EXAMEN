/*
 * Salones.c
 *
 *  Created on: 17 oct. 2021
 *      Author: maxis
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn_biblioteca.h"
#include "Salones.h"


int initSalon(Salon list[], int len)
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

int Salon_loadSalon(Salon pList[], int* idSalon)
{
	int retorno = -1;
	int tipoAux;
	char nombreAux[128];
	char direccionAux[128];
	int index;
	char shoppingImp[16]="SHOPPING";
	char localImp[16]="LOCAL";
	char tipoImp[16];

	index = buscarSalonLibre(pList, CANT_SALON);

	if(pList != NULL)
	{
			if(utn_getText(nombreAux, sizeof(nombreAux), "INGRESE UN NOMBRE: ", "ERROR\n")==0)
			{
				if(utn_getText(direccionAux, sizeof(direccionAux), "INGRESE UNA DIRECCION: ", "ERROR\n")==0)
				{
					if(utn_getNumero(&tipoAux, "INGRESE TIPO:\n"
												"\t1. SHOPPING\n"
												"\t2. LOCAL\n", "ERROR4\n")==0 && tipoAux>0&&tipoAux<3)
					{
						pList[index].tipo = tipoAux;
						pList[index].id = generadorSalonID();
						strncpy(pList[index].nombre,nombreAux,sizeof(pList[index].nombre));
						strncpy(pList[index].direccion,direccionAux,sizeof(pList[index].direccion));
						pList[index].isEmpty = 1;
						*idSalon = pList[index].id;
						retorno = 0;

						switch(tipoAux)
						{
						case 1:
							strcpy(tipoImp,shoppingImp);
						break;
						case 2:
							strcpy(tipoImp,localImp);
						break;
						}

						printf(	"SALON INGRESADO:\n\n"
								"TIPO: %s\n"
								"NOMBRE: %s\n"
								"DIRECCION: %s\n"
								"ID: %d\n\n"
								,tipoImp,pList[index].nombre,pList[index].direccion,pList[index].id);
					}
					else
					{
						puts("TIPO INCORRECTO\n");
					}

				}
			}
		}

	return retorno;

}

//****************************

int modifySalonById(Salon list[], int len, int id)
{
	int retorno = -1;
	int tipoAux;
	char nombreAux[128];
	char direccionAux[128];
	int opcionAux;

	int index = findSalonById(list, len, id);

	if(list!=NULL && len>0)
	{
		if(index>=0 && list[index].isEmpty==1)
		{
			printf("\nSalon ENCONTRADO\n\nTIPO: %d\n"
					"NOMBRE: %s\n"
					"DIRECCION: %s\n"
					,list[index].tipo,list[index].nombre,list[index].direccion);

			if(utn_getNumero(&opcionAux,"\n¿QUE DATO DESEA MODIFICAR?\n\n"
					"1- TIPO\n"
					"2- NOMBRE\n"
					"3- DIRECCION\n"
					, "ERROR.\n")==0)
			{
				switch(opcionAux)
				{
				case 1:
					if(utn_getNumero(&tipoAux, "INGRESE NUEVO TIPO: ", "ERROR")==0)
					{
						list[index].tipo = tipoAux;
					}
				break;

				case 2:
					if(utn_getText(nombreAux, sizeof(nombreAux), "INGRESE NUEVO NOMBRE: ", "ERROR")==0)
					{
						strncpy(list[index].nombre,nombreAux,sizeof(list[index].nombre));
					}
				break;

				case 3:
					if(utn_getText(direccionAux, sizeof(direccionAux), "INGRESE NUEVA DIRECCION: ", "ERROR")==0)
					{
						strncpy(list[index].direccion,direccionAux,sizeof(list[index].direccion));
					}
				break;

				default:
					puts("OPCION INCORRECTA\n");
				break;
				}//FIN SWITCH
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

int removeSalonById(Salon list[],int len,int id)
{
	int retorno = -1;
	int opcionAux;
	char shoppingImp[16]="SHOPPING";
	char localImp[16]="LOCAL";
	char tipoImp[16];

	int index = findSalonById(list, len, id);

	if(list!=NULL && len>0)
	{
		if(index>=0 && list[index].isEmpty==1)
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

			printf("\nESTA A PUNTO DE ELIMINAR EL SIGUIENTE SALON:\n\n"
					"TIPO: %s\n"
					"NOMBRE: %s\n"
					"DIRECCION: %s\n"
					,tipoImp,list[index].nombre,list[index].direccion);

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

int findSalonById(Salon list[], int len, int id)
{
	int i;
	int indice = -1;

	if(list!=NULL && len>0)
	{
	for(i=0; i<len; i++)
		{
			if(list[i].id == id && list[i].isEmpty==1)
			{
				indice = i;
				break;
			}

		}
	}
	return indice;
}

//****************************

int printSalon(Salon list[], int len)
{
	int retorno = -1;
	int i;
	char shoppingImp[16]="SHOPPING";
	char localImp[16]="LOCAL";
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
						"ID: %d\n\n"
						,tipoImp,list[i].nombre,list[i].direccion,list[i].id);
				retorno = 0;
			}
		}

	}

	return retorno;
}

//****************************

int printSalonById(Salon list[], int len, int id)
{
	int retorno = -1;
	int index;
	char shoppingImp[16]="SHOPPING";
	char localImp[16]="LOCAL";
	char tipoImp[16];

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
					"ID: %d\n\n"
					,tipoImp,list[index].nombre,list[index].direccion,list[index].id);
			retorno = 0;
		}

	}

	return retorno;
}


//****************************

int Salon_altaForzada(Salon* pList, int len,int indice, int tipo, float precio, char nombre[], char direccion[])
{
	int retorno = -1;

	if(pList != NULL)
	{

		pList[indice].tipo = tipo;
		pList[indice].precio = precio;
		pList[indice].id = generadorSalonID();
		strncpy(pList[indice].nombre,nombre,sizeof(pList->nombre));
		strncpy(pList[indice].direccion,direccion,sizeof(pList->direccion));
		pList[indice].isEmpty = 1;
	}

	return retorno;

}

//****************************


int buscarSalonLibre(Salon list[], int len)
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


int generadorSalonID(void)
{
	static int contador = 0;
	contador++;
	return contador;
}


