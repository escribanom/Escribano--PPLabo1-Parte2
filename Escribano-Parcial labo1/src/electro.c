/*
 * electro.c
 *
 *  Created on: 14 oct. 2020
 *
 */
#define TAMR 4
#define TAMM 5
#define TAM 3
#define TAMS 4
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "electro.h"
#include "utn.h"


int initElectro(Electrodomestico* electro, int len)
{
	int retorno =-1;
	//retorna 0 if ok
	int i=0;
	if(electro!=NULL && TAM > 0)
	{
		for(i=0;i<TAM;i++){
			electro[i].isEmpty=1;
		}
		retorno=0;
	}
	return retorno;
}

int searchForSpace(Electrodomestico* electro, int len, int* position)
{
	int retorno=-1;
	int i =0;
	if(electro!=NULL && TAM >=0 && position!=NULL)
	{
		for(i=0;i<TAM;i++)
		{
			if(electro[i].isEmpty==1)
			{
				retorno=0;
				*position=i;
			}
		}
	}
	return retorno;
}
int descripcionMarca(char description[], int id, Marca* marcas, int tamM)
{
    int todoOk = 0;

    for(int i=0; i<TAMM; i++)
    {
        if(marcas[i].idMarca == id)
        {
            strcpy(description, marcas[i].descripcionMarca);
            todoOk = 1;
        }
    }
    return todoOk;
}

void printElectro(Electrodomestico electro, Marca* marcas, int lenM)
{


	char descripMarca[20];
	descripcionMarca(descripMarca, electro.idMarca, marcas, TAMM);
	printf("  %d\t  %d\t   %d\t\t   %d\t\t %20s\t\n", electro.id, electro.serie,electro.idMarca, electro.fFabricacion, descripMarca);


}


void printElectros(Electrodomestico* electro, int len, Marca* marcas, int lenM)
{
	int flag=0;
	int i;
	printf("***** Lista de electrodomesticos *****\n");
	printf("   Id      Serie    ID de Marca     Fecha de fabricacion  Marca\n\n");
	if(electro!=NULL && TAM >=0)
	    {
		for(i=0; i<TAM; i++)
		    {
		        if(electro[i].isEmpty == 0)
		        {
		            printElectro(electro[i], marcas, TAMM);
		            flag=1;

		        }
		    }
		if(flag==0)
		{
			printf("No hay electrodomesticos para listar\n");
		}
	}



}
int findElectroById(Electrodomestico* electro, int len, int valor, int* position)
{
	int retorno = -1;
	int i;
	if(electro!= NULL && TAM >=0)
	    {
	        for(i=0;i<TAM;i++)
	        {
	            if(electro[i].isEmpty==1)
	                continue;
	            else if(electro[i].id==valor)
	            {
	                retorno=0;
	                *position=i;
	                break;
	            }
	        }
	    }
	    return retorno;
}
void printMarca(Marca marcas, int tamM)
{
    printf("  %d %20s  \n", marcas.idMarca, marcas.descripcionMarca);
}
void printMarcas(Marca* marcas, int tamM)
{
    printf("\n***** Lista de marcas *****\n");
    printf("   Id      Marcas\n\n");

    for(int i=0; i<TAMM; i++)
    {
        printMarca(marcas[i],TAMM);
    }
}
int addElectro(Electrodomestico* electro,int* nextId, int len)
{
	int retorno=-1;
	// o ok -1 error
	int position;

	int auxSerie;
	int auxMarca;
	int auxFecha;


	if(electro!= NULL && TAM > 0)
	{
		if(searchForSpace(electro,TAM,&position)==-1)
		{
			printf("No hay lugares disponibles\n");

		}
		else
		{
			//getNumber(, "Ingrese numero de id desde 0 a 99\n","Error, vuelva a ingresar el numero\n",0,99,1);
			(*nextId)++;
			electro[position].id= *nextId;
			//getNumber(&electro[position].serie, "Ingrese numero de serie desde 0 a 999\n","Error, vuelva a ingresar el numero\n",0,9999,1);
			printf("Ingrese numero de serie desde 1 a 999\n");
			scanf("%d",&auxSerie);
			if(auxSerie >0 && auxSerie<=999)
			{
			electro[position].serie=auxSerie;
			}
			//getNumber(&electro[position].idMarca, "Ingrese numero de marca correspondiente: \n1-Whirpool\n 2-Sony\n 3-Liliana\n 4-Gafa\n 5-Philips\n\n","Error, vuelva a ingresar el numero\n",1,5,1);
			printf("Ingrese numero de marca correspondiente: \n1000-Whirpool\n 1001-Sony\n 1002-Liliana\n 1003-Gafa\n 1004-Philips\n\n");
			scanf("%d",&auxMarca);
			if(auxMarca >=1000 && auxMarca <=1004)
			{
			electro[position].idMarca=auxMarca;
			}
		    //getNumber(&electro[position].fFabricacion.year, "Ingrese año de fabricacion desde 2000 a 2020 \n","Error, vuelva a ingresar el numero\n",2000,2020,1);
			printf("Ingrese anio de fabricacion desde 2000 a 2020\n");
			scanf("%d",&auxFecha);
			if(auxFecha >=2000 && auxFecha<=2020)
			{
			electro[position].fFabricacion=auxFecha;
			}
		    electro[position].isEmpty=0;

			retorno=0;
		}
	}
	return retorno;
}
int removeElectro(Electrodomestico* electro, int len,Marca* marcas)
{
	int retorno =-1;
	//-1 if error 0 if ok

	int position;
	int auxId;
    if(electro!=NULL && TAM>0)
	    {
	       printElectros(electro,TAM, marcas,TAMM);
	       printf("ID a dar de baja: \n");
	       scanf("%d",&auxId);
	        if(findElectroById(electro, TAM,auxId, &position)==-1)
	        {
	            printf("ID inexistente\n");
	        }
	        else
	        {
	            electro[position].isEmpty=1;
	            retorno=0;
	        }
	    }
	return retorno;
}
int modifyElectro(Electrodomestico* electro, int len,Marca* marcas)
{
	int retorno=-1;
	    int position;
	    int auxId;
	    int optionModify;
	    char continuar='s';
	    int auxSerie;

	    	int auxFecha;
	    if(electro!=NULL && TAM>0)
	    {
	    	printElectros(electro, TAM,marcas,TAMM);
	    	printf("ID a modificar: \n");
	    	scanf("%d",&auxId);
	    		        if(findElectroById(electro, TAM, auxId, &position)==-1)
	    		        {
	    		            printf("ID inexistente\n");
	    		        }
	    		        else
	    		        {

	            do
	            {
	            	 printf("ID: %d\n Id Marca: %5d\n Serie: %d\n Fecha de fabricacion: %4d\n ",electro[position].id, electro[position].idMarca,electro[position].serie,electro[position].fFabricacion);
	                printf("Elija opcion 1-Numero de serie  2-Anio de fabricacion 3-Salir\n");
	            	 scanf("%d",&optionModify);
	                switch(optionModify)
	                {
	                    case 1:
	                    	printf("Ingrese nuevo numero de serie 1 y 999\n");
	                    	scanf("%d",&auxSerie);
	                    	if(auxSerie>=1&& auxSerie <=999)
	                    	{
	                    		electro[position].serie=auxSerie;
	                    	}

	                        break;
	                    case 2:
	                    	printf("Ingrese nuevo año de fabricacion entre 2000 y 2020\n");
	                    	scanf("%d",&auxFecha);
	                    	if(auxFecha>=2000&& auxFecha <=2020)
	                    	{
	                    		electro[position].fFabricacion=auxFecha;
	                    	}

	                        break;
	                    case 3:
	                    	printf("Usted ha seleccionado salir del menu");
	                    	break;
	                    default:
	                        printf("Opcion no valida\n");
	                }
	            }while(continuar!='s');
	            retorno=0;
	        }

	    }
	    return retorno;
}
void sortElectro(Electrodomestico* electro, int len)
{


	//return -1 error 0 ok

	int i;
	int j;


	Electrodomestico auxElectro;

				if(TAM > 0 && electro != NULL)

					{
					for( i=0; i<TAM - 1; i++)
					{
				for( j=i+1; j<len; j++)
					{
				if(electro[j].fFabricacion< electro[i].fFabricacion)
					{
					auxElectro = electro[i];
					electro[i] = electro[j];
					electro[j] = auxElectro;
					}
					else if(electro[j].fFabricacion == electro[i].fFabricacion && electro[j].serie == electro[i].serie)
					{
					auxElectro = electro[i];
					electro[i] = electro[j];
					electro[j] = auxElectro;
					}
						 }
					 }

					}




}



