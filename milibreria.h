/* Autor: Luis Gonzalo Guzman Sanchez, Realizado: 22/05/2022
Libreria para funciones comunes del programa C
*/
#ifndef _MILIBRERIA
#define _MILIBRERIA
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
//Prototipos
void leers(char *mensaje,char s[], int n);
float leerf(char *mensaje, float inferior, float superior);
int leerd(char *mensaje, int inferior, int superior);
int es_entero(char *cadena);
int es_decimal(char *cadena);
void leersd(char *mensaje, char s[], int inferior, int superior);
#include"milibreria.cpp"
#endif
