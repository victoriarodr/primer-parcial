/*
 * eVehiculos.h
 *
 *  Created on: 21 oct. 2022
 *      Author: vicky
 */

#ifndef EVEHICULOS_H_
#define EVEHICULOS_H_


#include "funcionesUtn.h"

#define TAM 51
#define TAM_COLOR 10

typedef struct
{
	int idTipo;
	char descripcion[TAM];
}eTipoVehiculo;

typedef struct{
	int idVehiculo;
	char descripcionVeh[TAM];
	int modelo;
	char color[TAM_COLOR];
	int tipoId;
	int isEmpty;
}eVehiculos;

int inicializarEstructura(eVehiculos lista[], int tam);
int buscarIndiceLibre(eVehiculos lista[], int tam);
eVehiculos pedirDatosVehiculo();
int alta(eVehiculos lista[], int tam);
void mostrarUno(eVehiculos empleado);
int mostrarTodos(eVehiculos lista[], int tam);
eVehiculos modificarVehiculo(eVehiculos vehiculo);
int modificarGeneral (eVehiculos lista[], int tam);
int buscarPorID(eVehiculos lista[], int tam, int idPasajero);
int bajaVehiculo(eVehiculos lista[], int tam);
#endif /* EVEHICULOS_H_ */

