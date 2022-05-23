#include"milibreria.h"
void leers(char *mensaje,char s[], int n) {
	char text[20];
	printf(mensaje);
	fflush(stdin);
	fgets(s,n, stdin);
	//sprintf(text,"%%%d[^\\n]",n);
	//printf("\n[%s]\n", text);
	//fscanf(stdin,text,s);
	fflush(stdin);
		if (s[strlen(s)-1]== '\n'){
			s[strlen(s)-1]=0;
		} 
}
void leersd(char *mensaje, char s[], int inferior, int superior) {
	int tipo=superior+1;
	char h[10];
	do{
		printf(mensaje);
		fflush(stdin);
		fgets(s,10, stdin);
		fflush(stdin);
		if (s[strlen(s)-1]== '\n'){
			s[strlen(s)-1]=0;
		} 
		if(es_entero(s)){
			tipo=atoi(s);	
			if (tipo==1){	
			strcpy(s,"A");
			}
			else if(tipo==2){
			strcpy(s,"B");
			}
			else if(tipo==3){
			strcpy(s,"C");
			}
			else if(tipo==4){
			strcpy(s,"D");
			}
			else if(tipo==5){
			strcpy(s,"K");
			}
			if (tipo<inferior || tipo>superior){
			printf("¡¡¡Dato invalido!!! Debe estar entre (%d-%d). Vuelva introducirlo: \n",inferior, superior);
			}
		}	
			else {
				printf("\n ¡¡¡Dato invalido!!! Debe ser un numero entero. Vuelva introducirlo: \n");
			}
		
	}while(tipo<inferior || tipo>superior);
	
}
float leerf(char *mensaje, float inferior, float superior){
	float valor=superior+1;
	char s[10];
	do{
		printf(mensaje);
		//scanf("%f",&valor);
		fflush(stdin);
		fgets(s,10, stdin);
		fflush(stdin);
		if (s[strlen(s)-1]== '\n'){
			s[strlen(s)-1]=0;
		} 
		if(es_decimal(s)){
			valor=atof(s);
			if (valor<inferior || valor>superior){
				printf("\n Dato invalido!!! Debe estar entre (%.2f-%.2f). Vuelva introducirlo: \n",inferior, superior);
			}	
		}
		else{
			printf("\n Dato invalido!!! Debe ser un numero decimal. Vuelva introducirlo: \n");
		}
		
	}while(valor<inferior || valor>superior);
	return valor;
}
int leerd(char *mensaje, int inferior, int superior){
	int valor=superior+1;
	char s[10];
	do{
		printf(mensaje);
		//scanf("%d",&valor);
		fflush(stdin);
		fgets(s,10, stdin);
		fflush(stdin);
		if (s[strlen(s)-1]== '\n'){
			s[strlen(s)-1]=0;
		} 
		if(es_entero(s)){
			valor=atoi(s);
			if (valor<inferior || valor>superior){
			printf("Dato invalido!!! Debe estar entre (%d-%d). Vuelva introducirlo: \n",inferior, superior);
			}
		}
		else {
			printf("\n Dato invalido!!! Debe ser un numero entero. Vuelva introducirlo: \n");
		}

	}while(valor<inferior || valor>superior);
	return valor;
}
//Funciones de validacion de enteros y flotantes
//Tomado de http://www.programacionenc.net/index.php?option=com_content&view=article&id=125:verificar-si-el-ingreso-de-teclado-es-un-entero-o-decimal&catid=31:general&Itemid=41
int es_entero(char *cadena){
   int i, valor;


   for(i=0; i < strlen(cadena); i++)
   {
      valor = cadena[ i ] - '0';

      if(valor < 0 || valor > 9)
      {
          if(i==0 && valor==-3) continue;

          return 0;
      }
   }
   return 1;
}
int es_decimal(char *cadena){
   int i, valor;
   int tiene_punto = 0;


   for(i=0; i < strlen(cadena); i++)
   {
      valor = cadena[ i ] - '0';

      if(valor < 0 || valor > 9)
      {
          /* El primer caracter es: - */
         if(i==0 && valor==-3) continue;

         /* Verifica que solo tenga un: . */
         if(valor==-2 && !tiene_punto)
         { 
            tiene_punto=1;
            continue;
         }

         return 0;
      }
   }
   return 1;
}
