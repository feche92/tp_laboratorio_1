#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "funciones.h"




int main()

{
    char seguir='s';
    int opcion=0;
    float num1;
    float num2;
    float resp;
    int flagnum1=0;
    int flagnum2=0;

    while(seguir=='s')
    {
        if(flagnum1==0)
        {
            printf("1- Ingresar 1er operando (A=x)\n");
        }
        else
        {
            printf("1- Ingresar 1er operando (A=%f)\n",num1);
        }
        if(flagnum2==0)
        {
            printf("2- Ingresar 2do operando (B=y)\n");
        }
        else
        {
            printf("2- Ingresar 2do operando (B=%f)\n",num2);
        }
        printf("3- Calcular la suma (A+B)\n");
        printf("4- Calcular la resta (A-B)\n");
        printf("5- Calcular la division (A/B)\n");
        printf("6- Calcular la multiplicacion (A*B)\n");
        printf("7- Calcular el factorial (A!)\n");
        printf("8- Calcular todas las operaciones\n");
        printf("9- Salir\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
        case 1:
            printf("ingrese un numero:");
            scanf("%f",&num1);
            flagnum1=1;
            break;
        case 2:
            printf("ingrese un numero:");
            scanf("%f",&num2);
            flagnum2=1;
            break;
        case 3:
            if(flagnum1==0 || flagnum2==0)
            {
                printf("ERROR.datos insuficientes.\n");
            }
            else
            {
                resp=suma(num1, num2);
                printf("La suma es:%.2f\n",resp);
            }

            break;
        case 4:
            if(flagnum1==0 || flagnum2==0)
            {
                printf("ERROR.datos insuficientes.\n");
            }
            else
            {
                resp=resta(num1, num2);
                printf("La resta es:%.2f\n",resp);
            }
            break;
        case 5:
            if(flagnum1==0 || flagnum2==0)
            {
                printf("ERROR.datos insuficientes.\n");
            }
            else if(num2==0)
            {
                printf("MATH ERROR.reingrese dato.\n");
            }
            else
            {
                resp=division(num1, num2);
                printf("La division es:%.2f\n",resp);
            }
            break;
        case 6:
            if(flagnum1==0 || flagnum2==0)
            {
                printf("ERROR.datos insuficientes.\n");
            }
            else
            {
                resp=multiplicacion(num1, num2);
                printf("La multiplicacion es:%.2f\n",resp);
            }
            break;
        case 7:if(flagnum1==1)
        {
            resp=validarFactorial(num1);
            if(resp==0)
            {
                printf("ERROR.reingrese un dato valido\n");
            }
            else
            {
                printf("El factorial de %f es %.0f\n",num1,resp);
            }

        }
        else
        {
            printf("ERROR.datos insuficientes.\n");
        }
            break;
        case 8:if(flagnum1==1 && flagnum2==1)
        {
             operaciones(num1, num2);
        }
        else
        {
            printf("ERROR.datos insuficientes.\n");
        }
            break;
        case 9:
            seguir = 'n';
            break;
        }
        if(opcion!=9)
        {
            printf("Precione una tecla para continuar.");
            getch();
            system("cls");
        }


    }
    return 0;


}





