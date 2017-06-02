#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"



int main()
{
    EMovie movie;
    char seguir='s';
    char opcion;
    int flag;
    while(seguir=='s')
    {
        fflush(stdin);
        printf("1- Agregar pelicula\n");
        printf("2- Borrar pelicula\n");
        printf("3- Modificar pelicula\n");
        printf("4- Generar pagina web\n");
        printf("5- Salir\n");
        printf("Ingrese una opcion:");

        scanf("%c",&opcion);

        switch(opcion)
        {
            case '1':
                flag=agregarPelicula(movie);
                if(flag==1)
                {
                    printf("\nPelicula agregada correctamente");
                    printf("\n\npresione una tecla para continuar...");
                    getch();
                    system("cls");
                }

                else
                {
                    printf("\nError al cargar la pelicula");
                    printf("\n\npresione una tecla para continuar...");
                    getch();
                    system("cls");
                }

                break;
            case '2':
                flag=borrarPelicula(movie);
                if(flag==1)
                {
                    printf("\nPelicula borrada correctamente");
                    printf("\n\npresione una tecla para continuar...");
                    getch();
                    system("cls");
                }

                else
                {
                    printf("\nError al borrar la pelicula");
                    printf("\n\npresione una tecla para continuar...");
                    getch();
                    system("cls");
                }

                break;
            case '3':
                flag=modificarPelicula(movie);
                if(flag==1)
                {
                    printf("Pelicula modificada...");
                    system("pause");
                    system("cls");
                }
                else
                {
                    printf("Error al modificar la pelicula...");
                    system("pause");
                    system("cls");
                }
                break;
            case '4':
                generarPaginaWeb(movie);
               break;
            case '5':
                seguir = 'n';
                break;
            default:
                printf("\nIngrese una opcion valida.1-4:");
                opcion=getch();
                break;
        }
    }

    return 0;
}
