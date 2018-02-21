#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "gestion.h"

#define MAX_LENGHT 50


int menuEmpleado(void)
{
	char str[MAX_LENGHT];
	int option;
	int len;
	do
	{
		printf("\n");
		printf("BIENVENIDO A LA BIBLIOTECA ONLINE DE LA UNIVERSIDAD DE DEUSTO!\n");
		printf("Indique su opcion: \n");
		
		printf("1. Lista de libros disponibles para alquilar\n");
		printf("2. Lista de clientes de la biblioteca de Deusto\n");
		printf("3. Nuevo cliente\n");
		printf("4. Nuevo libro \n");
		printf("5. \n");
		printf("6. EXIT\n");
		printf("\n");
		
		fgets(str, 50, stdin);
	
		len = sscanf(str, "%d", &option); 
		printf("\n");

	}while ((len == 0 && str[0] != '6') || (len > 0 && (option > 6 || option < 1)));
	
	return (str[0] == '6')?0:option;

}


int main(int argc, char **argv, char **vectorUsuarios)
{
	int option;
	int total = 0;
	  	
		do
		{
			option = menuEmpleado();
		
			switch (option)
			{
				case 1: 

					listaLibros();				
					break;

				case 2:

					listaClientes();
					break;

				case 3:

					nuevoCliente();
					break;

				case 4:

					nuevoLibro();
					break;

				

				default:
					return -1;
					break;
		
			}
		}while(option!=0);	

}




