#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "funciones.h"


int agregarPelicula(EMovie movie)
{
    FILE* archivo;
    char aux[10];
    system("cls");
    printf("Ingrese el nombre de la pelicula:");
    fflush(stdin);
    gets(movie.titulo);
    validarCantCaracteres(movie.titulo,20);
    printf("Ingrese su genero:");
    fflush(stdin);
    gets(movie.genero);
    validarCantCaracteres(movie.genero,20);
    printf("Ingrese su duracion en minutos:");
    fflush(stdin);
    gets(aux);
    movie.duracion=validarDigitos(aux,60,300);
    printf("Ingrese la descripcion:");
    fflush(stdin);
    gets(movie.descripcion);
    validarCantCaracteres(movie.descripcion,120);
    printf("Ingrese un puntaje del 1 al 10:");
    fflush(stdin);
    gets(aux);
    movie.puntaje=validarDigitos(aux,1,10);
    printf("Ingrese un link de imagen:");
    fflush(stdin);
    gets(movie.linkImagen);
    validarCantCaracteres(movie.linkImagen,120);
    if((archivo=fopen("data.txt","ab+"))!=NULL)
    {
         fwrite(&movie,sizeof(movie),1,archivo);
         fclose(archivo);
         return 1;
    }
    else
    {
        printf("\nError al abrir el archivo!!");
        fclose(archivo);
        return 0;
    }


}

void validarCantCaracteres(char nombre[],int cant)
{
    while(strlen(nombre)>(cant-1))
    {
        printf("\nError.dato muy largo.reingrese:");
        fflush(stdin);
        gets(nombre);
    }
}

int validarDigitos(char aux[],int min,int max)
{
    int cant,i,flag;
    do
    {
        i=0;
        flag=0;
        while(aux[i]!='\0')
        {
            if(aux[i]<'0' || aux[i]>'9')
                flag=1;
            i++;
        }
        if(flag==0)
        {
            cant=atoi(aux);
            if(cant<min || cant>max)
                flag=1;
        }
        if(flag==1)
        {
            printf("Error.reingrese en el rango valido.%d-%d:",min,max);
            fflush(stdin);
            gets(aux);
        }

    }while(flag==1);

    return cant;
}

int borrarPelicula(EMovie movie)
{
    FILE* archivo;
    EMovie* pelicula;
    fflush(stdin);
    pelicula=(EMovie*)malloc(sizeof(EMovie));
    EMovie auxi;
    int j,i,lugar;
    char aux[30];
    system("cls");
    if((archivo=fopen("data.txt","rb"))!=NULL)
    {
        rewind(archivo);
        j=0;
        i=0;
        while((fread(&movie,sizeof(EMovie),1,archivo))!=0)
        {
            j++;
            pelicula=realloc(pelicula,sizeof(EMovie)*j);
            *(pelicula + i)=movie;
            i++;


        }
        fclose(archivo);
    }
    else
    {
        printf("El archivo no puede ser abierto..");
        return 0;
    }
    for(i=0;i<j;i++)
    {
        printf("%s\n",(pelicula + i)->titulo);
    }

    printf("Ingrese el nombre de la pelicula que desee eliminar:");
    fflush(stdin);
    gets(aux);
    strlwr(aux);
    lugar=buscarPelicula(pelicula,aux,j);
    if(lugar!=-1)
    {
        for(i=lugar;i<j;i++)
        {
            auxi=*(pelicula + i);
            *(pelicula + i)=*(pelicula + i +1);
            *(pelicula + i +1)=auxi;
        }
        j--;
        realloc(pelicula,sizeof(EMovie)*j);
    }
    else
    {
        printf("No se encontro la pelicula");
        return 0;
    }
    for(i=0;i<j;i++)
    {
        printf("%s\n",(pelicula + i)->titulo);
    }
    if((archivo=fopen("data.txt","wb"))!=NULL)
    {
        fwrite(pelicula,sizeof(EMovie),j,archivo);
        fclose(archivo);
        free(pelicula);
        return 1;
    }
    else
        return 0;
}

int buscarPelicula(EMovie* p,char aux[],int P)
{
    int i;
    int lugar=-1;
    for(i=0;i<P;i++)
    {
        strlwr((p+i)->titulo);
        if(strcmp(aux,(p+i)->titulo)==0)
        {
            lugar=i;
            break;
        }
    }
    return lugar;
}

int modificarPelicula(EMovie movie)
{
    FILE* archivo;
    EMovie* pelicula;
    int j,i,lugar;
    char aux[30];
    char opcion,resp;
    fflush(stdin);
    pelicula=(EMovie*)malloc(sizeof(EMovie));
    system("cls");
    if((archivo=fopen("data.txt","rb"))!=NULL)
    {
        rewind(archivo);
        j=0;
        i=0;
        while((fread(&movie,sizeof(EMovie),1,archivo))!=0)
        {
            j++;
            pelicula=realloc(pelicula,sizeof(EMovie)*j);
            *(pelicula + i)=movie;
            i++;


        }
        fclose(archivo);
    }
    else
    {
        printf("El archivo no puede ser abierto..");
        return 0;
    }
    for(i=0;i<j;i++)
    {
        printf("%s\n",(pelicula + i)->titulo);
    }

    printf("Ingrese el nombre de la pelicula que desee modificar:");
    fflush(stdin);
    gets(aux);
    strlwr(aux);
    lugar=buscarPelicula(pelicula,aux,j);
     if(lugar!=-1)
    {
        do
        {
            printf("1.Titulo\n2.Genero\n3.Duracion\n4.Descripcion\n5.Puntaje\n6.Link de imagen");
        printf("\nIndique cual de las siguentes opciones desea eliminar:");
        opcion=getch();
        switch(opcion)
        {
        case '1':
            printf("\nIngrese el nuevo titulo:");
            fflush(stdin);
            gets((pelicula+lugar)->titulo);
            validarCantCaracteres((pelicula+lugar)->titulo,20);
            printf("\nDesea seguir modificando?S/N");
            resp=tolower(getch());
            break;
        case '2':
            printf("\nIngrese el nuevo genero:");
            fflush(stdin);
            gets((pelicula+lugar)->genero);
            validarCantCaracteres((pelicula+lugar)->genero,20);
            printf("\nDesea seguir modificando?S/N");
            resp=tolower(getch());
            break;
        case '3':
            printf("\nIngrese la nueva duracion en minutos:");
            fflush(stdin);
            gets(aux);
            (pelicula+lugar)->duracion=validarDigitos(aux,60,300);
            printf("\nDesea seguir modificando?S/N");
            resp=tolower(getch());
            break;
        case '4':
            printf("\nIngrese la nueva descripcion:");
            fflush(stdin);
            gets((pelicula+lugar)->descripcion);
            validarCantCaracteres((pelicula+lugar)->descripcion,120);
            printf("\nDesea seguir modificando?S/N");
            resp=tolower(getch());
            break;
        case '5':
            printf("\nIngrese el nuevo puntaje del 1 al 10:");
            fflush(stdin);
            gets(aux);
            (pelicula+lugar)->puntaje=validarDigitos(aux,1,10);
            printf("\nDesea seguir modificando?S/N");
            resp=tolower(getch());
            break;
        case '6':
            printf("\nIngrese el nuevo link de imagen:");
            fflush(stdin);
            gets((pelicula+lugar)->linkImagen);
            validarCantCaracteres((pelicula+lugar)->linkImagen,120);
            printf("\nDesea seguir modificando?S/N");
            resp=tolower(getch());
            break;
        default:
            printf("\nError.Ingrese unas de las opciones validas.1-6:");
            opcion=getch();
        }
        }while(resp!='n');

    }
    else
    {
        printf("No se encontro la pelicula");
        return 0;
    }
    if((archivo=fopen("data.txt","wb"))!=NULL)
    {
        fwrite(pelicula,sizeof(EMovie),j,archivo);
        fclose(archivo);
        return 1;
    }
    else
        return 0;
}

void generarPaginaWeb(EMovie movie)
{
    FILE* archivo;
    FILE* web;
    if((archivo=fopen("data.txt","rb"))!=NULL)
    {
        if((web=fopen("index.html","wb"))!=NULL)
        {
             while((fread(&movie,sizeof(EMovie),1,archivo))!=0)
             {
                 fprintf(web,
                         "<article class='col-md-4 article-intro'>\n"
                    "<a href='#'>\n"
                    "<img class='img-responsive img-rounded' src='%s' alt=''>\n"
                    "</a>\n"
                    "<h3>\n"
                    "<a href='#'>%s</a>\n"
                    "</h3>\n"
                    "<ul>\n"
                    "<li>Genero :%s</li>\n"
                    "<li>Puntaje :%d</li>\n"
                    "<li>Duracion :%d minutos</li>\n"
                    "</ul>\n"
                    "<p>%s</p>\n"
                    " </article>\n",movie.linkImagen,movie.titulo,movie.genero,movie.puntaje,movie.duracion,movie.descripcion);

             }
        }
        else
        {
            printf("No se pudo abrir el html...");
            system("pause");
            system("cls");
        }
    }
    else
    {
        printf("No se pudo abrir el archivo");
        system("pause");
        system("cls");
    }
    printf("Pagina web creado exitosamente!!!!");
    system("pause");
    system("cls");
    fclose(archivo);
    fclose(web);
}
