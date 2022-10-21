/*
Victoria Rodriguez Rosas DIV D
 */

#include <stdio.h>
#include <stdlib.h>
#include "eVehiculos.h"
#define MAX_LISTA 100


int main(void)
{
	setbuf(stdout,NULL);
		eVehiculos lista[MAX_LISTA];
		int salir;
		int opciones;
		int banderaAlta;

		salir = 0;
		banderaAlta = 0;


		inicializarEstructura(lista, MAX_LISTA);

		do{
			printf("\nMENU DE OPCIONES\n\n"
						   "1. Alta Vehiculo\n"
						   "2. Modificar Vehiculo\n"
						   "3. Baja Vehiculo\n"
						   "4. Listar vehiculos\n"
						   "5. Listar Tipos\n"
						   "6. Alta hoja de servicio\n"
						   "7. Listar hojas de servicio\n"
						   "8. Informes\n"
						   "9. Salir \n\n");
			opciones = pedirEnteroRango("\nSeleccione una opcion",1,9);
			switch(opciones)
			{
				case 1:
					printf("\t\t***** Alta Vehiculo ****\n");
					alta(lista, MAX_LISTA);
					banderaAlta = 1;
				break;
				case 2:
					printf("\t\t***** Modificar Vehiculo ****\n");
					if(banderaAlta == 1)
					{
						modificarGeneral (lista, MAX_LISTA);
					}
					else
					{
						printf("\nDebe ingresar por lo menos un alta");
					}
				break;
				case 3:
					printf("\t\t***** Baja Vehiculo ****\n");
					if(banderaAlta == 1)
					{
						bajaVehiculo(lista, MAX_LISTA);
					}
					else
					{
						printf("\nDebe ingresar por lo menos un alta");
					}
				break;
				case 4:
					printf("\t\t***** Listar Vehiculos ****\n");
					if(banderaAlta == 1)
					{
						mostrarTodos(lista,MAX_LISTA);
					}
					else
					{
						printf("\nDebe ingresar por lo menos un alta");
					}
				break;
				case 5:
					printf("\t\t***** Listar Tipos ****\n");
					if(banderaAlta == 1)
					{

					}
					else
					{
						printf("\nDebe ingresar por lo menos un alta");
					}

				break;
				case 6:
					printf("\t\t***** Alta hoja de servicio ****\n");
					if(banderaAlta == 1)
					{

					}
					else
					{
						printf("\nDebe ingresar por lo menos un alta");
					}
				break;
				case 7:
					printf("\t\t***** Listar hojas de servicio ****\n");
					if(banderaAlta == 1)
					{

					}
					else
					{
						printf("\nDebe ingresar por lo menos un alta");
					}
				break;
				case 8:
					printf("\t\t***** Informes ****\n");
					if(banderaAlta == 1)
					{

					}
					else
					{
						printf("\nDebe ingresar por lo menos un alta");
					}
				break;
				case 9:
					printf("\t\t***** Salir ****\n");
					salir = pedirEnteroRango("Ingrese 1 para salir, 0 para continuar", 0, 1);
				break;
			}

		}while(salir != 1);

	return EXIT_SUCCESS;
}
