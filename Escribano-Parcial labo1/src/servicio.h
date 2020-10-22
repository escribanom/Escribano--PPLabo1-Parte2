/*
 * servicio.h
 *
 *  Created on: 15 oct. 2020
 *
*/
#include "electro.h"
#ifndef SERVICIO_H_
#define SERVICIO_H_
typedef struct{
	int idCliente;
	char nombre[51];
	char apellido[51];
	int isEmpty;
}Cliente;
typedef struct{
	int id;//autoincremental
	int serieR;
	int idServicio;
	int day;
	int month;
	int year;
	int isEmpty;
	int idUser;
	int idElectro;
}Reparacion;
typedef struct{
	int idServicio;//arranca 20k
	char descripcionServ[25];
	int precio;
	int isEmpty;
}Servicio;


#endif /* SERVICIO_H_ */
int initRepa(Reparacion* fix, int len);
int searchForSpaceRep(Reparacion* fix, int len, int* position);
int addRep(Reparacion* fix,int* nextIdRep,Electrodomestico* electro, int tam,Marca* marcas, int lenM, Servicio* lista, int lenS,Cliente* users, int tamC);
int descripcionServicio(char description[], int id, Servicio* lista, int tamS);
void printServ(Servicio lista, int tamS);
void printServs(Servicio* lista, int tamS);
int findRepById(Reparacion* fix, int len, int valor, int* position);
int removeRep(Reparacion* fix, int len,Servicio* lista,Cliente* users);
int modifyRep(Reparacion* fix, int len);
void printRep(Reparacion fix, Servicio* lista, int tamS, Cliente* users,int tamC);
void printReps(Reparacion* fix, int len, Servicio* lista,Cliente* users);
void printClient(Cliente users, int tamC);
void printClients(Cliente* users, int tamC);
int nameUser(char description[], int id, Cliente* users, int tamC);
int lastNameUser(char description[], int id, Cliente* users, int tamC);
int findClientById(Cliente* users, int len, int valor, int* position);
