#include "funciones.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


int obtenerEspacioLibre(EPersona lista[], int P)
{
    int lugar=-1;
    int i;
    for(i=0;i<P;i++)
    {
        if(lista[i].estado==0)
        {
            lugar=i;
            break;
        }
    }
    return lugar;

}

void imprimir(EPersona lista[], int P)
{
    int i, j;
    EPersona aux;
    for(i=0;i<P-1;i++)
    {
        for(j=i+1;j<P;j++)
        {
            if(strcmp(lista[i].nombre,lista[j].nombre)>0)
            {
                aux=lista[i];
                lista[i]=lista[j];
                lista[j]=aux;
            }
        }
    }

}

void grafico(int A, int B, int C)
{
    int valor[3]={A,B,C};
    int i,j;
    int max=0;
    for(i=0;i<3;i++)
    {
        if(valor[i]>max)
        {
            max=valor[i];
        }
    }
    for(i=max;i>0;i--)
    {
        for(j=0;j<3;j++)
        {
            if(valor[j]>=i)
            {
                printf("*\t");
            }
            else
            {
                printf("\t");
            }
        }
        printf("\n");
    }
    printf("<18   19-35   >35\n");
}


int buscarPorDni(EPersona lista[], int dni, int P)
{
    int i;
    int posicion=-1;
    for(i=0;i<P;i++)
    {
        if(lista[i].dni==dni)
        {
            posicion=i;
            break;
        }
    }
    return posicion;
}


void validarNombre(char nombre[])
{
    char buffer[200];
    printf("\nIngrese nombre:");
    fflush(stdin);
    gets(buffer);
    while(strlen(buffer)>29)
    {
        printf("Reingrese un nombre mas corto: ");
        fflush(stdin);
        gets(buffer);

    }
    strcpy(nombre,buffer);
}


int validarEdad(int min, int max)
{
    int edad;
    printf("Ingrese edad:");
    scanf("%d", &edad);
    while(edad<min || edad>max)
    {
        printf("Edad incorrecta.reingrese:");
        scanf("%d", &edad);
    }
    return edad;
}


int validaS_N(void)
{
    int continuar;
    char seguir;
    printf("Esta seguro.S/N:");
    seguir=toupper(getche());
    while(seguir!='S' && seguir!='N')
    {
        printf("\nError.presione.S/N:");
        seguir=toupper(getche());

    }

    if(seguir=='S')
    {
        continuar=1;
    }
    else
    {
        continuar=0;
    }
    return continuar;

}

void mostrarLista(EPersona lista[],int P)
{
    int i;
    for(i=0;i<P;i++)
    {
        if(lista[i].estado==1)
        {
             printf("DNI:%d\t Nombre:%10s\t Edad:%d\n",lista[i].dni,lista[i].nombre,lista[i].edad);
        }

    }
}
