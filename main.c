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
		printf("3. Darse de baja de la aplicacion\n");
		printf("4. EXIT\n");
		printf("\n");
		
		fgets(str, 50, stdin);
	
		len = sscanf(str, "%d", &option); 
		printf("\n");

	}while ((len == 0 && str[0] != '4') || (len > 0 && (option > 4 || option < 1)));
	
	return (str[0] == '4')?0:option;

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
		printf("5. Eliminar un libro \n");
		printf("6. Lista de libros alquilados\n");
		printf("7. EXIT\n");
		printf("\n");
		
		fgets(str, 50, stdin);
	
		len = sscanf(str, "%d", &option); 
		printf("\n");

	}while ((len == 0 && str[0] != '7') || (len > 0 && (option > 7 || option < 1)));
	
	return (str[0] == '7')?0:option;

}


int main(int argc, char **argv, char **vectorUsuarios)
{
	int option;
	int total = 0;
	char n[30];
	char c[30]; 
	int log = 0;	
	do
	{
	 printf("\n\n\n\nBIENVENIDO A LA BIBLIOTECA DE DEUSTO\n");
	 printf("Escriba el nombre de usuario por favor (usuario - empleado)\n");
	 gets(n);
	 printf("Escriba su contrasena\n");
	 gets(c);
	
	
		if(strcmp(n, "empleado")==0 && strcmp(c, "empleado")==0)
		 {
		 	log = 1;
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

					case 5:

						eliminarLibro();
						break;

					case 6: 

						listaLibrosAlquilados();
						break;

					default:
						return -1;
						break;
			
				}

			}while(option!=0);	
		 }else
		 if(strcmp(n, "usuario")==0 && strcmp(c, "usuario")==0)
			{
				log = 1;
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

							eliminarCliente();
							break;					
							

						default:
						return -1;
						break;

					}
				}while(option!=0);
			}else
			{	 
			log = 0;	
			printf("usuario/contraseña incorrecta\n");
			}
	}while(log == 0);

}




