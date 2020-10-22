/*
 * servicio.c
 *
 *  Created on: 15 oct. 2020
 *
 */
#define TAMR 4
#define TAMM 5
#define TAM 6
#define TAMS 4
#define TAMC 10
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "servicio.h"
#include "electro.h"
#include "utn.h"

int initRepa(Reparacion* fix, int len)
{
	int retorno =-1;
	//retorna 0 if ok
	int i=0;
	if(fix!=NULL && TAM > 0)
	{
		for(i=0;i<TAM;i++){
			fix[i].isEmpty=1;
		}
		retorno=0;
	}
	return retorno;
}
int searchForSpaceRep(Reparacion* fix, int len, int* position)
{
	int retorno=-1;
	int i =0;
	if(fix!=NULL && TAMR >=0 && position!=NULL)
	{
		for(i=0;i<TAM;i++)
		{
			if(fix[i].isEmpty==1)
			{
				retorno=0;
				*position=i;
			}
		}
	}
	return retorno;
}
int addRep(Reparacion* fix,int* nextIdRep,Electrodomestico* electro, int tam,Marca* marcas, int lenM, Servicio* lista, int lenS,Cliente* users, int tamC)
{
	int retorno=-1;
	// o ok -1 error
	int position;
	int auxSer=0;
	int auxId=0;
	int auxRep=0;
	int auxDay=0;
	int auxMonth=0;
	int auxYear=0;
	int auxIdCliente=0;
	if(fix!= NULL && TAM > 0 && nextIdRep!= NULL)
	{
		if(searchForSpaceRep(fix,TAM,&position)==-1)
		{
			printf("No hay lugares disponibles\n");

		}
		else
		{
			(*nextIdRep)++;
			fix[position].id = *nextIdRep;
			printElectros(electro,TAM, marcas, TAMM);

			printf("Ingrese ID de electrodomestico a reparar: \n");
									scanf("%d",&auxId);
									if(auxId >0 && auxId<999){
										if(findElectroById(electro, TAM,auxId, &position)==-1){
											printf("ID inexistente\n");}
										else
										{
											fix[position].idElectro=auxId;
										}

								printf("Ingrese numero de servicio correspondiente: \n 20001-Garantia\n 20002-Mantenimiento\n 20003-Repuestos\n");
								scanf("%d",&auxRep);
								if(auxRep >20000 && auxRep<20004)
								{
									fix[position].idServicio=auxRep;
								}

								printf("ingrese numero de serie de reparacion entre 1 y 999\n");
								scanf("%d",&auxSer);
								if(auxSer>1 && auxSer<=999)
								{
									fix[position].serieR=auxSer;
								}

								printf("Ingrese dia de reparacion entre 1 y 31\n");
								scanf("%d",&auxDay);
								if(auxDay >=1 && auxDay<=31)
								{
									fix[position].day=auxDay;
								}

								printf("Ingrese mes de reparacion entre 1 y 12\n");
								scanf("%d",&auxMonth);
								if(auxMonth>=1 && auxMonth<=12)
								{
									fix[position].month=auxMonth;
								}

								printf("Ingrese anio de reparacion entre 2000 y 2020\n");
								scanf("%d",&auxYear);
								if(auxYear>=2000 && auxYear<=2020)
								{
									fix[position].year=auxYear;
								}
								fix[position].isEmpty=0;
									printClients(users, TAMC);
									printf("Ingrese Id de cliente elegido entre 1 y 10\n");
									scanf("%d",&auxIdCliente);
									if(auxIdCliente >0 && auxIdCliente <11)
											{

													fix[position].idUser=auxIdCliente;

											}
									else
									{
										printf("Error. Ingrese valor valido");
										scanf("%d",&auxIdCliente);
									}
							}
						}








			retorno=0;
		}

	return retorno;
}
int descripcionServicio(char description[], int id, Servicio* lista, int tamS)
{
    int todoOk = 0;

    for(int i=0; i<TAMS; i++)
    {
        if(lista[i].idServicio == id)
        {
            strcpy(description, lista[i].descripcionServ);
            todoOk = 1;
        }
    }
    return todoOk;
}
int nameUser(char description[], int id, Cliente* users, int tamC)
{
    int todoOk = 0;

    for(int i=0; i<TAMC; i++)
    {
        if(users[i].idCliente == id)
        {
            strcpy(description, users[i].nombre);
            todoOk = 1;
        }
    }
    return todoOk;
}
int lastNameUser(char description[], int id, Cliente* users, int tamC)
{
    int todoOk = 0;

    for(int i=0; i<TAMC; i++)
    {
        if(users[i].idCliente == id)
        {
            strcpy(description, users[i].apellido);
            todoOk = 1;
        }
    }
    return todoOk;
}
void printServ(Servicio lista, int tamS)
{
    printf("  %d %20s  \n", lista.idServicio, lista.descripcionServ);
}
void printServs(Servicio* lista, int tamS)
{
    printf("\n***** Lista de Servicios *****\n");
    printf("   Id      Servicios\n\n");

    for(int i=0; i<TAMS; i++)
    {
        printServ(lista[i],TAMS);
    }
}
void printClient(Cliente users, int tamC)
{
    printf("  %d %51s  %51s\n", users.idCliente, users.nombre, users.apellido);
}
void printClients(Cliente* users, int tamC)
{
    printf("\n***** Lista de Usuarios *****\n");
    printf("   Id      Nombre     Apellido\n\n");

    for(int i=0; i<TAMC; i++)
    {
        printClient(users[i],TAMC);
    }
}
int findRepById(Reparacion* fix, int len, int valor, int* position)
{
	int retorno = -1;
	int i;
	if(fix!= NULL && TAM >=0)
	    {
	        for(i=0;i<TAM;i++)
	        {
	            if(fix[i].isEmpty==1)
	                continue;
	            else if(fix[i].id==valor)
	            {
	                retorno=0;
	                *position=i;
	                break;
	            }
	        }
	    }
	    return retorno;
}
int removeRep(Reparacion* fix, int len,Servicio* lista,Cliente* users)
{
	int retorno =-1;
	//-1 if error 0 if ok

	int position;
	int auxId;
    if(fix!=NULL && TAMR>0)
	    {
	       printReps(fix,TAMR,lista,users);
	    	getNumber( &auxId, "ID a dar de baja: \n","Error. Vuelva a ingresar ID\n",1,999,1);
	        if(findRepById(fix, TAMR,auxId, &position)==-1)
	        {
	            printf("ID inexistente\n");
	        }
	        else
	        {
	            fix[position].isEmpty=1;
	            retorno=0;
	        }
	    }
	return retorno;
}
/*int informes(Reparacion* fix, int len)
{
	int retorno=-1;
	    int position;
	    int auxId;
	    int optionModify;
	    char continuar='s';

	    if(fix!=NULL && TAMR>0)
	    {


	            do
	            {
	            	 //printf("ID: %d\n Id Servicio: %5d\n Serie: %d\n Fecha de fabricacion %2d/%2d/%4d\n ",fix[position].id, fix[position].idServicio,fix[position].serie, fix[position].fRepar.day, fix[position].fRepar.month, fix[position].fRepar.year);
	                getNumber(&optionModify, "Modificar: 1 2 3 4 5 6 7 8 9 10 11 12 13-(Salir)\n","Error.Ingrese opcion entre 1 y 13\n",1, 13, 1);
	                switch(optionModify)
	                {
	                    case 1:
	                    	void printElectro2020(Electrodomestico* electro, int len, Marca* marcas, int tamm)
	                    	{
	                    		int i;
	                    		int cont=0;
	                    		if(TAM > 0 && electro != NULL&& marcas!= NULL && TAMM>0)
	                    		{
	                    			for(i=0;i<TAM;i++)
	                    			{
	                    				if(electro[i].fFabricacion==2020)
	                    				{
	                    					printElectro(electro[i],TAM,marca[i],TAMM);
	                    				}
	                    			}

	                    		}

	                    	}
	                        break;
	                    case 2:
	                    	void printElectroDeMarca(Electrodomestico* electro, int len, Marca* marcas, int tamm)
	                    	{
	                    		//hacer menu
	                    		int i;
	                    		int cont1=0;
	                    		int cont2=0;
	                    		int cont3=0;
	                    		int cont4=0;
	                    		int cont5=0;
	                    		if(TAM > 0 && electro != NULL&& marcas!= NULL && TAMM>0)
	                    		{
	                    			for(i=0;i<TAM;i++)
	                    			{
	                    				if(electro[i].idMarca==1000)
	                    				{
	                    					cont1++;
	                    				}
	                    				if(electro[i].idMarca==1001)
	                    				{
	                    					cont2++;
	                    				}
	                    				if(electro[i].idMarca==1002)
	                    				{
	                    					cont3++;
	                    				}
	                    				if(electro[i].idMarca==1003)
	                    				{
	                    					cont4++;
	                    				}
	                    				if(electro[i].idMarca==1004)
	                    				{
	                    					cont5++;
	                    				}
	                    			}

	                    		}

	                    	}
	                        break;
	                    case 3:
	                    	//getFloat("Ingrese nuevo salario: \n","Error. Ingrese nuevo salario\n", 1, 6, 1,999999, 1, &list[position].salary);
	                        break;
	                    case 4:
	                    	//getSignedInt("ingrese nuevo sector\n","Error, ingrese sector entre 1 y 3\n",1, 1,1, 3, 1, &list[position].sector);
	                        break;
	                    case 5://

	                    	break;
	                    case 6:
	                    	void servMasPedido(Servicio *lista, int tams, Reparacion *fix, int tamr) {
	                    		int i;
	                    		int cont1=0;
	                    		int cont2 = 0;
	                    		int cont3 = 0;
	                    		int cont4 = 0;

	                    		if (TAMS > 0 && lista != NULL && fix != NULL && TAMR > 0) {
	                    			for (i = 0; i < TAMR; i++) {
	                    				if (fix[i].idServicio == 20001)
	                    				{
	                    					cont1++;
	                    				}
	                    				if (fix[i].idServicio == 20002)
	                    				{
	                    					cont2++;
	                    				}
	                    				if (fix[i].idServicio == 20003)
	                    				{
	                    					cont3++;
	                    				}
	                    				if (fix[i].idServicio == 20004)
	                    				{
	                    					cont4++;
	                    				}

	                    			}
	                    			if(cont1>cont2 &&cont1>cont3 &&cont1>cont4)
	                    			{
	                    				printf("El servicio mas usado es");
	                    			}
	                    			if(cont2>cont1 &&cont2>cont3 &&cont2>cont4)
	                    			{
	                    				printf("El servicio mas usado es");
	                    			}
	                    			if(cont3>cont1 &&cont3>cont2 &&cont3>cont4)
	                    			{
	                    				printf("El servicio mas usado es");
	                    			}
	                    			if(cont4>cont1 &&cont4>cont2 &&cont4>cont3)
	                    			{
	                    				printf("El servicio mas usado es");
	                    			}

	                    		}
	                    	}
	                    	break;
	                    case 7://recaudaci en fecha particular
	                    	break;
	                    case 8://electro c garantia y fecha
	                    	break;
	                    case 9://trabajos en 2018
	                    	break;
	                    case 10://facturacion total reps
	                    	break;
	                    case 11://marxa con mas reps
	                    	break;
	                    case 12://repair en fcha
	                    	break;
	                    case 13://salir

	                    	break;
	                    default:
	                        printf("Opcion no valida\n");
	                }
	            }while(continuar!='s');
	            retorno=0;
	        }

	    }
	    return retorno;
}*/
int findClientById(Cliente* users, int len, int valor, int* position)
{
	int retorno = -1;
	int i;
	if(users!= NULL && TAMC >=0)
	    {
	        for(i=0;i<TAMC;i++)
	        {
	            if(users[i].isEmpty==1)
	                continue;
	            else if(users[i].idCliente==valor)
	            {
	                retorno=0;
	                *position=i;
	                break;
	            }
	        }
	    }
	    return retorno;
}
void printRep(Reparacion fix, Servicio* lista, int tamS, Cliente* users,int tamC)
{
    char descripServicio[20];
    char nombre[21];
    char apellido[21];

    descripcionServicio(descripServicio, fix.idServicio, lista, TAMS);
    nameUser(nombre, fix.idUser, users, TAMC);
    lastNameUser(apellido,fix.idUser, users,TAMC);

    printf("%d\t %d\t %d\t %d\t\t %2d/%2d/%4d\t %20s \t\t %d %51s  %-51s\t\n", fix.id,fix.serieR,fix.idElectro, fix.idServicio, fix.day,fix.month,fix.year, descripServicio,fix.idUser, nombre,apellido);
}

void printReps(Reparacion* fix, int len, Servicio* lista,Cliente* users)
{
    int flag = 0;
    printf("***** Lista de reparaciones *****\n");
    printf("   Id de reparacion     Serie    ID de electrodomestico   ID de Servicio     Fecha de reparacion    Servicio   ID de Cliente   Nombre   Apellido\n\n");

    for(int i=0; i<TAMR; i++)
    {
        if(fix[i].isEmpty == 0)
        {
            printRep(fix[i], lista, TAMR, users, TAMC);
            flag = 1;
        }
    }

    if(flag == 0)
    {
        printf("*** No hay reparaciones que listar ***\n");
    }
}
