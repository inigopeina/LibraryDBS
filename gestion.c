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

void listaLibrosAlquilados()
{
	FILE *f;
	f = fopen("librosalquilados.txt", "r");

	if(f==NULL)
	{
		printf("Archivo no encontrado\n");
	}
	
	char str[70];
  	int d;

  	printf("LIBROS QUE HA ALQUILADO: \n");
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
void comprobarCliente(char* d)
{
	FILE *f;
	f = fopen("clientes.txt", "r");

	if(f==NULL)
	{
		printf("Archivo no encontrado\n");
	}


	char str[70];
  	/*int a;*/
  	char cliente[90];
  	int i=0; int tmp1=0; int tmp2=0;
  	int contador=0;

  
	while (feof(f)==0)

      {
            fgets(cliente,100,f);

            for(i=0;i<strlen(cliente);i++)

            {

               if (d[0]==cliente[i])

               {

                  tmp1=0;

                  tmp2=i;

                  while ((d[tmp1]==cliente[tmp2])&&(tmp2<strlen(cliente))&&(tmp1!=strlen(d)))

                  {
                        tmp1++;

                        tmp2++;

                        if (tmp1==strlen(d))

                           contador++;
                  }
               }
            }
      }

     /* printf("La palabra se repite en el texto %d veces",konta);*/

      if(contador>0)
      {
      	printf("Este cliente ya esta registrado en la base de datos de la universidad\n");
      	printf("Por favor, vuelva a intentarlo e introdduzca el DNI del nuevo cliente""\n");
      	gets(d);
      	comprobarCliente(d);
      }

      getchar();


	fclose(f);


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
 	fprintf(f, "Nombre: %s \n", p);

	printf("Introduzca el apellido del cliente:\n");
	gets(p);
	fprintf(f, "Apellido: %s\n", p);

	printf("Introduzca la edad del cliente:\n");
	gets(p);
	fprintf(f, "Edad: %s\n", p);

	printf("Introduzca el numero de DNI del cliente\n");
	gets(p);
	comprobarCliente(p);
	fprintf(f, "DNI: %s\n", p);

	printf("Introduzca el grado que cursa el cliente:\n");
	gets(p);
	fprintf(f, "Curso: %s\n", p);

	

	printf("El cliente ya ha sido añadido al sistema, gracias!!\n");
	printf("\n");

	fclose(f);
  	
}
void compararLibro(char* c)
{

	FILE *f;
	f = fopen("libros.txt", "r");

	if(f==NULL)
	{
		printf("Archivo no encontrado\n");
	}


	char str[70];
  	int d;
  	char libro[90];
  	int i=0; int tmp1=0; int tmp2=0;
  	int contador=0;

  
	while (feof(f)==0)

      {
            fgets(libro,100,f);

            for(i=0;i<strlen(libro);i++)

            {

               if (c[0]==libro[i])

               {

                  tmp1=0;

                  tmp2=i;

                  while ((c[tmp1]==libro[tmp2])&&(tmp2<strlen(libro))&&(tmp1!=strlen(c)))

                  {
                        tmp1++;

                        tmp2++;

                        if (tmp1==strlen(c))

                           contador++;
                  }
               }
            }
      }


      	if(contador>0)
      	{
      		printf("Libro alquilado!!!\n");
      	}
      	else
      	{
      		printf("Vuelva a intentarlo \n");
	      	gets(c);
	      	compararLibro(c);
      	}
 }
void comprobarLibroExiste(char* c)
{
	FILE *f;
	f = fopen("libros.txt", "r");

	if(f==NULL)
	{
		printf("Archivo no encontrado\n");
	}


	char str[70];
  	int d;
  	char libro[90];
  	int i=0; int tmp1=0; int tmp2=0;
  	int contador=0;

  
	while (feof(f)==0)

      {
            fgets(libro,100,f);

            for(i=0;i<strlen(libro);i++)

            {

               if (c[0]==libro[i])

               {

                  tmp1=0;

                  tmp2=i;

                  while ((c[tmp1]==libro[tmp2])&&(tmp2<strlen(libro))&&(tmp1!=strlen(c)))

                  {
                        tmp1++;

                        tmp2++;

                        if (tmp1==strlen(c))

                           contador++;
                  }
               }
            }
      }

     /* printf("La palabra se repite en el texto %d veces",konta);*/

      if(contador>0)
      {
      	printf("Este Libro ya esta registrado en la base de datos de la universidad\n");
      	printf("Por favor, vuelva a intentarlo e introdduzca el titulo del nuevo libro""\n");
      	gets(c);
      	comprobarLibroExiste(c);
      }

      getchar();


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

	
  	printf("Introduzca titulo del nuevo libro: \n");
 	gets(p);	
 	fprintf(f, "Titulo: %s\n", p);

	printf("Introduzca el autor del libro:\n");
	gets(p);
	fprintf(f, "Autor: %s\n", p);

	printf("Introduzca el genero del libro:\n");
	gets(p);
	fprintf(f, "Genero: %s\n", p);
	
	printf("Introduzca el codigo del libro\n");
	gets(p);
	comprobarLibroExiste(p);
	fprintf(f, "Codigo: %s\n",p);

	printf("El libro ya ha sido añadido al sistema, gracias!!\n");
	printf("\n");

	fclose(f);
  	
}

void alquilarLibro()
{
		char str[MAX_LENGHT];
		char c[30];
		


		FILE *f;

		f = fopen("librosalquilados.txt", "a");

		if(f==NULL)
		{
			printf("Archivo no encontrado\n");
		}
		listaLibros();
		printf("Introduzca el codigo del libro que desea alquilar: \n");
		gets(c);

		compararLibro(str);
	 	fprintf(f, "Codigo del libro: %s\n", c);
	 	listaLibrosAlquilados();



}

