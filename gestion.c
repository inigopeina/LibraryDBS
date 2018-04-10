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

 	fclose(f);
}
void listaLibrosReplica()
{
	
	FILE *f;
	f = fopen("replica.txt", "r");

	if(f==NULL)
	{
		printf("Archivo no encontrado\n");
	}
	
	char str[70];
  	int d;

  	printf("LIBROS QUE QUEDAN: \n");
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

 	fclose(f);

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

 	fclose(f);

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
                        {
                           contador=contador+1;
                        }
                  }
               }
            }
      }

      	
      	if(contador>0)
      	{
      		printf("Codigo correcto!\n");
      		printf("El libro ha sido alquilado con exito\n\n");

      		FILE *f;

			f = fopen("librosalquilados.txt", "a");

			if(f==NULL)
			{
				printf("Archivo no encontrado\n");
			}

			fprintf(f, "Codigo del libro: %s\n", c);
	 		fclose(f);

	 		
	    }
      	else
      	{
      		printf("Vuelva a intentarlo \n");
	      	gets(c);
	      	compararLibro(c);
      	}

      fclose(f);
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

                           contador=contador++;
                  }
               }
            }
      }

     

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

	printf("Introduzca el stock del libro:\n");
	gets(p);
	fprintf(f, "Stock: %s\n", p);
	
	do
	{

		printf("Introduzca el codigo del libro\n");
		gets(p);
		
		if(strlen(p)==3)
		{
			comprobarLibroExiste(p);
			fprintf(f, "Codigo: %s\n",p);
		}
		else
		{
			printf("vuelva a intentarlo\n");
		}	
	}while(strlen(p)!=3);

	printf("El libro ya ha sido añadido al sistema, gracias!!\n");
	printf("\n");

	fclose(f);
  	
}
int lineofID(char* c)
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
  	int lineNo = 0;
  	int aux = 0;

  
	while (feof(f)==0)

      {
      	lineNo++;
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
                        {
                           contador=contador+1;
                           aux = lineNo;
                        }
                  }
               }
            }
      }


      	if(contador>0)
      	{
      		printf("Codigo correcto!\n");
      		fclose(f);
      		return aux;

	 		
	    }
      	else
      	{
      		printf("Vuelva a intentarlo \n");
	      	fclose(f);
	      	gets(c);
	      	lineofID(c);
      	}

 }
void modificarStock(int lineNo)
{
	FILE *f, *fa;
	int idl1, idl2, idl3, idl4, idLine, lineSt, lineN=0;
	char str[100];
	f = fopen("libros.txt", "r");

	if(f==NULL)
	{
		printf("Archivo no encontrado\n");
	}

	lineSt=lineNo-1; //Stock

	printf("El stock esta en la linea: %d\n",lineSt);

	idLine = lineNo; //Codigo
	idl1 = idLine-2; //Genero
	idl2 = idLine-3; //Autor
	idl3 = idLine-4; //Titulo

	fa = fopen("replica.txt", "w");

	while(fgets(str, 99, f) != NULL)
	{

		lineN++;
		printf("%d\n",lineN );
		//FALTA HACER ESTO!
		if(lineN != idLine && lineN != idl1 && lineN != idl2 && lineN != idl3 && lineN != idl4)
		{
			
			fputs(str, fa);
		}

		
	}

	fclose(f);
	fclose(fa);
}
void alquilarLibro()
{
		char str[MAX_LENGHT];
		char c[30];
		int lineNo;

		listaLibros();
		do
		{
		printf("Introduzca el codigo del libro que desea alquilar: \n");
		gets(c);

	
		if(strlen(c)==3)
		{
		
			lineNo=lineofID(c);
			modificarStock(lineNo);
			compararLibro(c);
			listaLibrosAlquilados();

	 
	 	}
	 	else
	 	{
	 		printf("Vuelva a intentarlo\n");
	 		
	 		
	 	}
		
	
	 }while(strlen(c)!=3);

}

//le tengo que pasar el numero
void eliminarLibro()
{


	int idl1, idl2, idl3, idl4, idLine;
	
	char dirLib[] = "libros.txt";
	char dirRep[] = "replica.txt";
	int lineN = 0;
	int ret = 0;
	char str[100];
	FILE *f, *fa;
		char c[30];
		
		listaLibros();
		do
		{
		printf("Introduzca el codigo del libro que desea ELIMINAR: \n");
		gets(c);

	
		if(strlen(c)==3)
		{
		
			idLine = lineofID(c);
	 
	 	}
	 	else
	 	{
	 		printf("Vuelva a intentarlo\n");
	 		
	 	}
		
	
	 }while(strlen(c)!=3);

	 

	idl1 = idLine-1;
	idl2 = idLine-2;
	idl3 = idLine-3;
	idl4 = idLine-4;
	
	
	
	f = fopen("libros.txt", "r");

	fa = fopen("replica.txt", "w");

	while(fgets(str, 99, f) != NULL)
	{

		lineN++;

		//aqui copio en replica solo las lineas que quiero
		//if(lineN != idLine || lineN != idl1 || lineN != idl2 || lineN != idl3 || lineN != idl4)
		//if(lineN != idLine)
		if(lineN != idLine && lineN != idl1 && lineN != idl2 && lineN != idl3 && lineN != idl4)
		{
			
			fputs(str, fa);
		}
	}

	fclose(f);
	fclose(fa);
	
	ret = remove(dirLib);

   if(ret == 0) {
      printf("Libro borrado con exito\n");
   } else {
   	  printf("%d\n",ret);
      printf("El libro no se ha podido borrar\n");
   }
	rename(dirRep, dirLib);

}






