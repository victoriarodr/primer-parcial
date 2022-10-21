/*
 * eVehiculos.c
 *
 *  Created on: 21 oct. 2022
 *      Author: vicky
 */

#include "eVehiculos.h"
#define OCUPADO 0
#define LIBRE 1
#define BAJA -1

int obtenerID(void)
{
	int idTipo;
	int retorno;

	idTipo = 1000;

	retorno = idTipo++;

	return retorno;
}

//Asegurar la estructura vacia
int inicializarEstructura(eVehiculos lista[], int tam)
{
	int retorno;
	retorno = -1;

	if(lista != NULL && tam > 0)
	{
		for (int i = 0; i < tam; i++)
		{
			lista[i].isEmpty = LIBRE;
		}
		retorno = 0;
	}
	return retorno;
}

//Donde guardar el dato en el indice libre
int buscarIndiceLibre(eVehiculos lista[], int tam)
{
	int retorno;
	retorno = -1;

	if(lista != NULL && tam > 0)
	{
		for (int i = 0; i < tam; i++)
		{
			if(lista[i].isEmpty == LIBRE)
			{
				retorno = i;
				break;
			}
		}
	}
	return retorno;
}
//Crear el vehiculo
eVehiculos pedirDatosVehiculo()
{
	eVehiculos aux;
	int opcionId;

	aux.idVehiculo = obtenerID();
	pedirNombre("Ingrese la descripcion: ", aux.descripcionVeh, TAM);
	aux.modelo = pedirEnteroRango("Ingrese el año del modelo: ", 0, 2022);
	pedirNombre("Ingrese el color: ", aux.color, 10);
	opcionId = pedirEnteroRango ("Ingrese tipo de vehiculo:(1-SEDAN 3PTAS, 2-SEDAN 5PTAS, 3-CAMIONETA)",1,3);

	switch(opcionId)
	{
	case 1:
		aux.tipoId = 1;
	break;
	case 2:
		aux.tipoId = 2;
	break;
	case 3:
		aux.tipoId = 3;
	break;
	}

	aux.isEmpty = OCUPADO;

	return aux;
}

//cargar el Empleado al Array
int alta(eVehiculos lista[], int tam)
{
	int retorno;
	int posicionLibre;
	eVehiculos vehiculo;

	retorno = -1;
	if(lista != NULL && tam > 0)
	{
		posicionLibre =  buscarIndiceLibre(lista, tam);
		vehiculo = pedirDatosVehiculo();
		if(posicionLibre != -1)
		{
			lista[posicionLibre]= vehiculo;
			retorno = 0;
		}
	}
	return retorno;
}

void mostrarUno(eVehiculos vehiculo)
{

	printf("%d - %s - %d - %s - %d \n", vehiculo.idVehiculo,vehiculo.descripcionVeh, vehiculo.modelo,vehiculo.color,vehiculo.tipoId);
}
int mostrarTodos(eVehiculos lista[], int tam)
{
	int retorno;
	retorno = -1;

	if(lista != NULL && tam > 0)
	{
		for(int i=0; i<tam; i++)
		{
			if(lista[i].isEmpty == OCUPADO)
			{
				mostrarUno(lista[i]);
			}
		}
			retorno = 0;
	}

	return retorno;
}

eVehiculos modificarVehiculo(eVehiculos vehiculo)
{
	int opcionModificar;
	//int precioServicio;
	eVehiculos aux;

	do
	{
		printf("\nSeleccione que desea modificar:");
		printf("\n1. Descripcion");
		printf("\n2. Precio servicio");
		printf("\n3. Guardar cambios\n");

		opcionModificar = pedirEnteroRango("Ingrese la opcion: ",1, 3);

		switch(opcionModificar)
		{
			case 1:
					pedirNombre("Ingrese la descripcion nuevamente: ", aux.descripcionVeh, TAM);
					printf("\nLa descripcion se modifico correctamente.");
			break;

			case 2:
				/*if( precioServicio = pedirEnteroRango("Ingrese el precio correcto:", 0, 1000))
				{
					puts("El precio se modificó.");
				}*/
			break;

			case 3:
				puts("\nSe modifico correctamente.");
			break;
		}
	}while(opcionModificar != 3);

	return vehiculo;
}


int buscarPorID(eVehiculos lista[], int tam, int idVehiculo)
{
	int retorno;
	int i;

	retorno = -1;

	if (lista != NULL && tam > 0)
	{
		for (i = 0; i < tam; i++)
		{
			if (lista[i].idVehiculo == idVehiculo && lista[i].isEmpty == OCUPADO)
			{
				retorno = i;
				break;
			}
		}
	}

	return retorno;
}


int modificarGeneral(eVehiculos lista[], int tam)
{
	int retorno;
	int idVehiculo;
	int auxiliarIndex;
	eVehiculos auxiliar;

	retorno=0;

	idVehiculo = pedirEnteroRango("\nIngrese el Id a modificar: ", 1000, 10000);

	while(buscarPorID(lista, tam, idVehiculo) == -1)
	{
		printf("\nNo se encontró el id.");
		idVehiculo = pedirEnteroRango("\nReingrese Id a modificar: ",1000, 10000);
	}

	auxiliarIndex = buscarPorID(lista, tam, idVehiculo);

	auxiliar = modificarVehiculo(lista[auxiliarIndex]);

	lista[auxiliarIndex] = auxiliar;

	retorno= 1;

	return retorno;
}
int bajaVehiculo(eVehiculos lista[], int tam)
{
	int retorno;
	int idVehiculo;
	int auxiliarIndex;

	retorno = 0;


	idVehiculo = pedirRangoEntero("\nIngrese el vehiculo a dar de baja: ",1000, 10000);

		while (buscarPorID(lista, tam, idVehiculo) == -1)
		{
			printf("\nNo se encontró el id.");
			idVehiculo = pedirEnteroRango("\nReingrese Id a modificar: ",1000, 10000);
		}

		auxiliarIndex = buscarPorID(lista, tam, idVehiculo);
		lista[auxiliarIndex].isEmpty = BAJA;
		puts("\nSe dio de baja.\n");
		retorno = 1;

	return retorno;
}




