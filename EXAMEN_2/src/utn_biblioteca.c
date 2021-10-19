/*
 * utn_biblioteca.c
 *
 *  Created on: 7 sep. 2021
 *      Author: maxis
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn_biblioteca.h"

int suma(int a,int b)
{
	int total;
	total=a+b;
	return total;
}

int resta(int a,int b)
{
	int total;
	total = a-b;
	return total;
}

int multiplicacion(int a,int b)
{
	int total;
	total = a*b;
	return total;
}

int division(int a,int b, float* pDir)
{
	float total;
	int estado;

	if(b!=0)
	{
		estado = 0;
		total =(float) a/b;
	}
	else
	{
		estado = -1;
	}

	*pDir = total;

	return estado;
}

int factorial(int numero)
{
	int i;
	float aux=numero;

	for(i=1; i<numero; i++)
	{
		aux=aux*i;
	}
	return aux;
}

int utn_getNumero(int* pResultado, char* mensaje, char* mensajeError)
{

	int bufferInt;
	int retorno = -1;
	char bufferCadenaAux[32];

	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL)
	{
		while(1)
		{
			printf(mensaje);
			fflush(stdin);
			if(myGets(bufferCadenaAux,sizeof(bufferCadenaAux))==0)
			{
				//El usuario ingresó algo
				//Lo valido para saber si los símbolos son numéricos.
				//Si son numéricos convierto la cadena a INT.
				if(esNumerica(bufferCadenaAux)==0)
				{
					bufferInt = atoi(bufferCadenaAux);
					retorno = 0;
					break;
				}
				else
				{
					puts(mensajeError);
				}
			}
			else
			{
				puts(mensajeError);
			}
		}

		*pResultado = bufferInt;
	}

	return retorno;

}

int utn_getNumeroFlotante(float* pResultado, char* mensaje, char* mensajeError)
{

	float bufferInt;
	int retorno = -1;
	char bufferCadenaAux[32];
	int contadorPuntos = 0;
	int i;

	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL)
	{
		while(1)
		{
			printf(mensaje);
			fflush(stdin);
			if(myGets(bufferCadenaAux,sizeof(bufferCadenaAux))==0)
			{
				//El usuario ingresó algo
				//Lo valido para saber si los símbolos son numéricos.
				//Si son numéricos convierto la cadena a float.

				for(i=0; i<sizeof(bufferCadenaAux);i++)
				{
					if(bufferCadenaAux[i]=='.')
					{
						contadorPuntos++;
					}
				}

				if(esNumerica(bufferCadenaAux)==0 && contadorPuntos<=1)
				{
					bufferInt = atof(bufferCadenaAux);
					retorno = 0;
					break;
				}
				else
				{
					puts(mensajeError);
					contadorPuntos=0;
				}
			}
			else
			{
				puts(mensajeError);
			}
		}

		*pResultado = bufferInt;
	}

	return retorno;

}

int utn_getCaracter(char* pResultado, char* mensaje, char* mensajeError, char minimo, char maximo, int reintentos)
{

	char bufferChar;
	int retorno = -1;

	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo<=maximo && reintentos>=0)
	{
		do
		{
			printf("%s",mensaje);
			fflush(stdin);
			scanf("%c",&bufferChar);

			if(bufferChar>=minimo && bufferChar<=maximo)
			{
				*pResultado = bufferChar;
				retorno = 0;
				break;

			}
			else
			{
				printf("%s",mensajeError);
				reintentos--;
			}
		} while(reintentos>=0);
	}

	return retorno;

}


//-----myGets REEMPLAZA A scanf / gets / fgets y se incluye en otras funciones---


int myGets(char pResultado[], int len)
{
    int retorno=-1;
    int indexFinal;
    fflush(stdout);

    if(fgets(pResultado,len,stdin)!=NULL)
    {
        // borro el \n del final
        indexFinal = strlen(pResultado)-1;
        if(pResultado[indexFinal] == '\n')
        {
            pResultado[indexFinal] = '\0';
        }
        retorno = 0;
    }
    return retorno;
}

//-----utn_getText REEMPLAZA A scanf / gets / fgets---

int utn_getText(char pResultado[], int len, char* mensaje, char* mensajeError)
{
    int retorno = -1;

	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL)
    {
		while(1)
		{
			printf("%s",mensaje);

			if(myGets(pResultado,len)==0)
			{
				if(esTexto(pResultado)==0)
				{
					retorno = 0;
					break;
				}
				else
				{
					printf("%s", mensajeError);
				}
			}
			else
			{
				printf("%s", mensajeError);
			}

		}
    }
    return retorno;
}



int esNumerica(char cadena[])
{
	int retorno = -1;
	int i = 0;
	if(cadena!=NULL)
	{
		while(cadena[i]!='\0')
			{
				if(cadena[i]<'.' || (cadena[i]>'.' && cadena[i]<'0') || cadena[i]>'9')
				{
					retorno = -2;
					break;
				}
				else
				{
					retorno=0;
				}

				i++;
			}
	}

	return retorno;
}


int esTexto(char cadena[])
{
	int retorno = -1;
	int i = 0;
	if(cadena!=NULL)
	{
		while(cadena[i]!='\0')
		{
			if(cadena[i]< 'A' || (cadena[i]> 'Z' && cadena[i]< 'a') || cadena[i]> 'z' )
			{
				retorno = -2;
				break;
			}
			else
			{
				retorno = 0;
			}

			i++;
		}
	}

	return retorno;
}


int esAlfanumerica(char cadena[])
{
	int retorno = -1;
	int i = 0;
	if(cadena!=NULL)
	{
		while(cadena[i]!='\0')
		{
			if(cadena[i]<'0' || (cadena[i]>'9' && cadena[i]<'A') || (cadena[i]>'Z' && cadena[i]<'a') || cadena[i]>'z')
			{
				retorno = -2;
				break;
			}
			else
			{
				if(esTexto(cadena)==-2 && esNumerica(cadena)==-2)
				{
					retorno = 0;
				}
			}

			i++;
		}
	}

	return retorno;
}


int mySrtLen(char cadena[], int* contadorMayusculas)

{

	int i = 0;
	int contador = 0;

	while(cadena[i]!='\0')
	{
		if(cadena[i]>='A' && cadena[i]<='Z')
		{
			contador++;
		}

		i++;
	}

	*contadorMayusculas = contador;

	return i;
}


void menu(int a, int b)
{
	printf("\n");
	puts("MENU DE OPCIONES");
	printf("\n");
	printf("1- Ingresar 1er operando (A=%d)",a);
	printf("\n");
	printf("2- Ingresar 2do operando (B=%d)",b);
	printf("\n");
	puts("3- Calcular todas las operaciones. ");
	puts("4- Mostrar resultados.");
	puts("5- Salir.");
}


void imprimir(int s, int r, int m, int estadoD, float d, int fA, int fB, int num1, int num2)
{
	printf("RESULTADOS: \n");
	printf("El resultado de la suma es: %d",s);
	printf("\n");
	printf("El resultado de la resta es: %d",r);
	printf("\n");
	printf("El resultado de la multiplicación es: %d",m);
	printf("\n");
	if(estadoD==0)
	{
		printf("El resultado de la división es: %.2f",d);
		printf("\n");
	}
	else
	{
		printf("No se puede dividir por cero");
		printf("\n");
	}
	printf("El factorial de %d es: %d",num1,fA);
	printf("\n");
	printf("El factorial de %d es: %d",num2,fB);
	printf("\n");
}


