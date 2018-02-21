#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LENGHT 50

void clear_if_needed(char *str)
{
	if (str[strlen(str) - 1] != '\n')
	{
		int c;    
    	while ( (c = getchar()) != EOF && c != '\n');
    }
}
void listaLibros()
{
	FILE *f;
	f = fopen("libros.txt", "r");

	if(f==NULL)
	{
		printf("Archivo no encontrado\n");
	}
	
	char str[70];
  	int d;

  	printf("LIBROS DISPONIBLES PARA ALQUILAR: \n");
  	while(fgets(str, 100, f)) 
  	{ 
  		//recorrer hasta que lea un 0
      
   		printf("%s", str);

    	clear_if_needed(str); //siempre antes del siguiente fgets
 	}

}

void listaClientes()
{
	FILE *f;
	f = fopen("clientes.txt", "r");

	if(f==NULL)
	{
		printf("Archivo no encontrado\n");
	}
	
	char str[70];
  	int d;

  	printf("Clientes de la biblioteca: \n");
  	while(fgets(str, 100, f)) 
  	{ 
  		//recorrer hasta que lea un 0
      
   		printf("%s", str);

    	clear_if_needed(str); //siempre antes del siguiente fgets
 	}


}

void nuevoCliente()
{
	char *str;
	int d;
	char p[30];
	FILE *f;

	f = fopen("clientes.txt", "a");

	if(f==NULL)
	{
		printf("Archivo no encontrado\n");
	}

	
  	printf("Introduzca nombre del cliente: \n");
 	gets(p);	
 	fprintf(f, "%s\n", p);

	printf("Introduzca el apellido del cliente:\n");
	gets(p);
	fprintf(f, "%s\n", p);

	printf("Introduzca la edad del cliente:\n");
	gets(p);
	fprintf(f, "%s\n", p);

	printf("Introduzca el grado que cursa el cliente:\n");
	gets(p);
	fprintf(f, "%s\n", p);

	

	printf("El cliente ya ha sido añadido al sistema, gracias!!\n");
	printf("\n");

	fclose(f);
  	
}

void nuevoLibro()
{
	char *str;
	int d;
	char p[30];
	FILE *f;

	f = fopen("libros.txt", "a");

	if(f==NULL)
	{
		printf("Archivo no encontrado\n");
	}

	
  	printf("Introduzca titulo del cliente: \n");
 	gets(p);	
 	fprintf(f, "%s\n", p);

	printf("Introduzca el autor del cliente:\n");
	gets(p);
	fprintf(f, "%s\n", p);

	printf("Introduzca el genero del cliente:\n");
	gets(p);
	fprintf(f, "%s\n", p);
	

	printf("El libro ya ha sido añadido al sistema, gracias!!\n");
	printf("\n");

	fclose(f);
  	
}