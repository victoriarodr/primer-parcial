/*
 * funcionesUTN.c
 *
 *  Created on: 21 oct. 2022
 *      Author: vicky
 */

#include "funcionesUTN.h"

int sumar(int numeroUno, int numeroDos)
{
	int suma;

	suma = numeroUno + numeroDos;
	return suma;
}

void formarApellidoYNombre(char *pNombre, char *pApellido, char *pCompleto)
{
	int largo;

	strcpy(pCompleto, pApellido);
	strcat(pCompleto, ", ");
	strcat(pCompleto, pNombre);

	largo = strlen(pCompleto);
	pCompleto[0] = toupper(pCompleto[0]);

	for(int i = 0; i< largo; i ++)
	{
		if(isspace(pCompleto[i]))
		{
			i++;
			pCompleto[i] = toupper(pCompleto[i]);
		}
	}
}

void pedirNombre(char *mensaje, char *nombre, int largoNombre)
{
	printf(mensaje);
	fflush(stdin);
	fgets(nombre, largoNombre, stdin);
	nombre[strlen(nombre) -1] = '\0';
}

//Que el numero este entre los parametros que quiera;
int pedirEnteroRango(char* mensaje, int min, int max)
{
	int numero;
	printf("%s (entre %d - %d)", mensaje, min,max);
	scanf("%d", &numero);
	while (numero < min || numero > max)
	{
		printf("ERROR!! %s (entre %d - %d)", mensaje, min, max);
		scanf("%d", &numero);
	}

	return numero;
}

float pedirFlotanteRango (char* mensaje, int min, int max)
{
	float numero;
	printf("%s (entre %d - %d)", mensaje, min,max);
	scanf("%f", &numero);
	while(numero < min || numero > max)
	{
		printf("ERROR!! %s (entre %d - %d)", mensaje, min, max);
		scanf("%f", &numero);
	}
	return numero;
}



