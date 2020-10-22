/*
 * utn.h
 *
 *  Created on:
 *      Author:
 */

#ifndef UTN_H_
#define UTN_H_

int getString(char* msg, char* msgError, int min, int max, int* reintentos, char* resultado);

int getName(char* msg,char* msgError,int min,int max,int reintentos,char* resultado);
int isValidName(char* stringRecibido);

int getFloat(char* msg, char* msgError, int minSize, int maxSize, int min, int max, int reintentos, float* input);
int isValidFloatNumber(char* stringRecibido);

int myGets(char* cadena, int len);
int getInt(int* pResultado);
int esNumerica(char* cadena,int limite);
int getNumber(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos);
#endif /* UTN_H_ */
