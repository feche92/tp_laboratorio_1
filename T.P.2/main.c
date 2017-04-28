#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"
#define P 20

int main()
{
    char seguir='s';
    char opcion;
    EPersona persona[P];
    int libre, i, aux, resp;
    int cont,cont1,cont2;
    int flag=0;
    for(i=0; i<P; i++)
    {
        persona[i].estado=0;
    }

    while(seguir=='s')
    {
        printf("1- Agregar persona\n");
        printf("2- Borrar persona\n");
        printf("3- Imprimir lista ordenada por  nombre\n");
        printf("4- Imprimir grafico de edades\n\n");
        printf("5- Salir\n");
        printf("\nIngrese una opcion:");

        opcion=getche();
        printf("\n");
        switch(opcion)
        {
        case '1':
            libre=obtenerEspacioLibre(persona, P);
            if(libre!=-1)
            {
                validarNombre(persona[libre].nombre);
                persona[libre].edad=validarEdad(1,100);
                printf("Ingrese DNI:");
                scanf("%d", &persona[libre].dni);
                persona[libre].estado=1;
                flag=1;
                system("cls");
            }
            else
            {
                printf("Espacio insuficiente!!!\n\n");
                printf("\n\nPresione una tecla para continuar");
                getch();
                system("cls");
            }

            break;
        case '2':
            if(flag==0)
                printf("Primero agregue una persona!");
            else
            {
                mostrarLista(persona,P);
                printf("Indique el DNI de la persona que quiera borrar:\n");
                scanf("%d", &aux);
                libre=buscarPorDni(persona,aux,P);
                if(libre!=-1)
                {
                    resp=validaS_N();
                    if(resp==1)
                    {
                        printf("\nPersona eliminada!!");
                        persona[libre].estado=0;
                    }
                    else
                    {
                        printf("\nAccion cancelada!!");
                    }
                }
                else
                {
                    printf("\nPersona inexistente!!\n");
                }

            }

            printf("\n\nPresione una tecla para continuar");
            getch();
            system("cls");
            break;
        case '3':
            if(flag==1)
            {
                imprimir(persona, P);
                mostrarLista(persona, P);
            }
            else
                printf("Primero agregue una persona!");
            printf("\n\nPresione una tecla para continuar");
            getch();
            system("cls");

            break;
        case '4':
            if(flag==1)
            {
                cont=0;
                cont1=0;
                cont2=0;
                for(i=0; i<P; i++)
                {
                    if(persona[i].edad<18 && persona[i].estado==1)
                    {
                        cont++;
                    }
                    else if(persona[i].edad>=18 && persona[i].edad<=35 && persona[i].estado==1)
                    {
                        cont1++;
                    }
                    else if(persona[i].estado==1 && persona[i].edad>35)
                    {
                        cont2++;
                    }
                }
                grafico(cont,cont1,cont2);
            }
            else
                printf("Primero agregue una persona!");
            printf("\n\nPresione una tecla para continuar");
            getch();
            system("cls");
            break;
        case '5':
            seguir = 'n';
            break;
        default:


            printf("Error.Ingrese una opcion valida.");
            break;
        }


    }

    return 0;
}
