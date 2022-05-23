/*
Autor: Ricardo Jafet Granados Chable 22/05/2022
Proyecto final de la materia de programacion estructurada que busca tener un control de extintores en la institucion de UVM mediante menu con las sig. opciones:

0. Salir
1. Agregar extintor
2. Lista de extintores
3. Listar extintores de un edificio especifico
4. Listar extintores de una fecha especifica 
5. Listar extintores de un tipo especifico 
6. Recargar extintor
7. Guardar archivo
8. Cargar archivo
*/
#include<stdio.h>
#include<stdlib.h>
#include "milibreria.h"
#include<string.h> 
#define MAX 20

struct extintor{
	char tipo[2];
	char edificio[2]; 
	char area[25];
	int mes;
	int fecha;
};

int n=0;
int menu(); 
void agregar(struct extintor x[]);
void imprimir(struct extintor x[], int selec); 
void buscaredificio(struct extintor x[]); 
void guardar(struct extintor x[]); 
void cargar(struct extintor x[]); 
int main(){
	int opcion;
	struct extintor grupo[MAX];
	do{
		opcion=menu();
		switch(opcion){
			case 0: printf("ADIOS!!!...\n");
					break;
			case 1: agregar(grupo);
					break;
			case 2: imprimir(grupo,0);
					break;
			case 3: buscaredificio(grupo);
					break;
			case 4: //Listar Extintores por fecha 
					break;
			case 5: //Listar Extintores por tipo 
					break;
			case 6: //Recargar 
					break;
			case 7: guardar(grupo);
					break;
			case 8: cargar(grupo);
					break;
		}
	}while(opcion!=0);
	return 0;
}

int menu(){
	int opcion;
	printf("-----------MENU PRINCIPAL-----------\n");
	printf("0. SALIR\n");
	printf("1. AGREGAR EXTINTOR\n");
	printf("2. LISTAR TODOS LOS EXTINTORES\n");
	printf("3. LISTAR EXTINTORES POR EDIFICIO\n");
	printf("4. LISTAR EXTINTORES POR FECHA\n");
	printf("5. LISTAR EXTINTORES POR TIPO\n");
	printf("6. RECARGAR EXTINTOR\n");
	printf("7. GUARDAR ARCHIVO\n");
	printf("8. CARGAR ARCHIVO\n");
	printf("------------------------------------\n");
	opcion=leerd("SELECCIONE UNA OPCION: ",0,8);
	return opcion;
}

void agregar(struct extintor x[]){
	int pregunta;
	while(n<MAX){
		leers("TIPO DE EXTINTOR: ",x[n].tipo,2);
		leers("EDIFICIO: ",x[n].edificio,2);
		leers("AREA: ",x[n].area,25);
		x[n].mes=leerd("MES: ",1,12);
		x[n].fecha=leerd("AÑO: ",2022,2030);
		pregunta=leerd("DESEA AGREGAR OTRO EXTINTOR? (1.SI, 0.NO): ",0,1);
		n++;
		if(pregunta==0){
			break;
		}
	}
	if(n==MAX){
		printf("ARREGLO SATURADO!!!\n");
		system("PAUSE");
	}
}

void imprimir(struct extintor x[], int selec){
	char mensaje[35];
	switch(selec){
		case 0: strcpy(mensaje,"TOTALES          ");
				break;
		case 1: strcpy(mensaje,"EDIFICIO DE LOS  ");
				break;
		case 2: strcpy(mensaje,"FECHA DE LOS     ");
				break;
		case 3: strcpy(mensaje,"TIPO DE LOS      ");
				break;
	}
	printf("EXTINTORES %S--------------------------------------------------------------\n",mensaje);
	printf("\nNo.\tTIPO\tEDIFICIO\tAREA   \t\t\tMES\tAÑO\n");
	printf("---------------------------------------------------------------------------\n");
	
	for(int i=0;i<n;i++){	
		printf("%2d\t%-2s\t%-2s\t\t%-25s%2d\t%4d\n",i+1,x[i].tipo,x[i].edificio,x[i].area, x[i].mes, x[i].fecha);	
		
	}
	printf("---------------------------------------------------------------------------\n");
	system("PAUSE");		
}
void buscaredificio(struct extintor x[]){
	int i=0;
	char edif[2];
	int buscar=0;
	leers("¿DE QUE EDIFICIO DESEA LISTAR LOS EXTINTORES, A,B,C,D,F,G,H? \n ",edif,2);
	for(int i=0;i<n;i++){
			do{
				if(strcmp(edif,x[i].edificio)==0){
					buscar=1;
					printf("%2d\t%-2s\t%-2s\t\t%-25s%2d\t%4d\n",i+1,x[i].tipo,x[i].edificio,x[i].area, x[i].mes, x[i].fecha);
				}		
			}while(i!=0);
			
		}
	
}
void guardar(struct extintor x[]){
	FILE*f;
	f=fopen("Extintores.txt","w");
	if(f==NULL){
		printf("ERRO AL CARGAR DATOS!!!\n");
	}
	else{
		for(int i=0;i<n;i++){
			fprintf(f,"%s\t%s\t%s\t%d\t%d\n",x[i].tipo,x[i].edificio,x[i].area, x[i].mes, x[i].fecha);
		}
		fclose(f);
		printf("---->SE GUARDARON %d REGISTRO\n",n);
	}
	system("PAUSE");
}
void cargar(struct extintor x[]){
	FILE*f;
	struct extintor a;
	f=fopen("Extintores.txt","r");
	n=0;
	if(f==NULL){
		printf("ERROR AL GUARDAR DATOS!!!\n");
	}
	else{
		printf("LEYENDO......\n");
		
		while(fscanf(f,"%2d\t%2s\t%2s\t\t%25s%2d\t%4d\n",a.tipo,&a.edificio,&a.area, &a.mes, &a.fecha)!=EOF){
			x[n]=a;
			n++;
			printf("%2d\t%2s\t%2s\t\t%25s%2d\t%4d\n",n,a.tipo,a.edificio,a.area, a.mes, a.fecha); 
		}
		fclose(f);
		printf("---->%d REGISTROS LEIDOS\n",n);
	}
	system("PAUSE");
}


