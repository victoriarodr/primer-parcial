/*
 * funcionesUTN.h
 *
 *  Created on: 21 oct. 2022
 *      Author: vicky
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#ifndef FUNCIONESUTN_H_
#define FUNCIONESUTN_H_

int sumar(int numeroUno, int numeroDos);
void formarApellidoYNombre(char *pNombre, char *pApellido, char *pCompleto);
void pedirNombre(char *mensaje, char *nombre, int largoNombre);
int pedirEnteroRango(char* mensaje, int min, int max);
float pedirFlotanteRango (char* mensaje, int min, int max);
