#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "gestion.h"

#define MAX_LENGHT 50


int menuUsuario(void)
{
	char str[MAX_LENGHT];
	int option;
	int len;
	do
	{
		
		printf("Usted ha entrado como USUARIO\n");
		printf("\n");
		
		
		printf("1. Lista de libros disponibles para alquilar\n");
		printf("2. Alquilar libro\n");
		printf("3. Eliminar libro\n");
		printf("4. EXIT\n");
		printf("\n");
		
		fgets(str, 50, stdin);
	
		len = sscanf(str, "%d", &option); 
		printf("\n");

	}while ((len == 0 && str[0] != '4') || (len > 0 && (option > 4 || option < 1)));
	
	return (str[0] == '1')?0:option;

}

int menuEmpleado(void)
{
	char str[MAX_LENGHT];
	int option;
	int len;
	do
	{
		
		printf("Usted ha entrado como EMPLEADO\n");
		printf("\n");
		printf("BIENVENIDO A LA BIBLIOTECA ONLINE DE LA UNIVERSIDAD DE DEUSTO!\n");
		printf("Indique su opcion: \n");
		
		printf("1. Lista de libros disponibles para alquilar\n");
		printf("2. Lista de clientes de la biblioteca de Deusto\n");
		printf("3. Introducir un nuevo cliente\n");
		printf("4. Introducir un nuevo libro \n");
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
	char n[30];
	char c[30]; 	

	 printf("Escriba el nombre de usuario por favor\n");
	 gets(n);
	 printf("Escriba su contrasena\n");
	 gets(c);
	 if(strcmp(n, "empleado")==0 && strcmp(c, "passempleado")==0)
	 {
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
		if(strcmp(n, "usuario")==0 && strcmp(c, "passusuario")==0)
		{
			do
			{
				option = menuUsuario();
			
				switch (option)
				{
					case 1: 

						listaLibros();				
						break;

					case 2:

						alquilarLibro();
						break;

					case 3:

						eliminarLibro();
						break;
						

					default:
					return -1;
					break;

				}
			}while(option!=0);
		}

}




