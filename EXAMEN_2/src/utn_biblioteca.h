/*
 * utn_biblioteca.h
 *
 *  Created on: 7 sep. 2021
 *      Author: maxis
 */

#ifndef UTN_BIBLIOTECA_H_
#define UTN_BIBLIOTECA_H_

void menu();
int suma(int a,int b);
int resta(int a,int b);
int multiplicacion(int a,int b);
int division(int a,int b, float* pDir);
int factorial(int numero);

void imprimir(int s, int r, int m, int estadoD, float d, int fA, int fB, int num1, int num2);

int utn_getNumero(int* pResultado, char* mensaje, char* mensajeError);
int utn_getNumeroFlotante(float* pResultado, char* mensaje, char* mensajeError);
int utn_getCaracter(char* pResultado, char* mensaje, char* mensajeError, char minimo, char maximo, int reintentos);
int myGets(char pResultado[], int len);
int utn_getText(char pResultado[], int len, char* mensaje, char* mensajeError);

int esNumerica(char cadena[]);
int esTexto(char cadena[]);
int esAlfanumerica(char cadena[]);

int mySrtLen(char cadena[], int* contadorMayusculas);

#endif /* UTN_BIBLIOTECA_H_ */
