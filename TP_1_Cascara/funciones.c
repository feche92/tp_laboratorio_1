
float suma(float num1, float num2)
{
    float resp;
    resp=num1 + num2;
    return resp;
}

float resta(float num1, float num2)
{
    float resp;
    resp=num1 - num2;
    return resp;
}

float multiplicacion(float num1, float num2)
{
    float resp;
    resp=num1 * num2;
    return resp;
}

float division(float num1, float num2)
{
    float resp;
    resp=num1 / num2;
    return resp;
}

float factorial(float num1)
{
    float resp=1;
    float i;
    for(i=num1; i>0; i--)
    {
        resp=resp * i;
    }
    return resp;
}

float validarFactorial(float num1)
{
    int num;
    num=num1;
    float resp;
    if(num1-num==0 && num1>0)
    {
        resp=factorial(num1);
        return resp;
    }
    else
    {
        return 0;
    }

}

void operaciones(float num1, float num2)
{
    float resp;
    resp=suma(num1, num2);
    printf("La suma es %.2f\n", resp);
    resp=resta(num1,num2);
    printf("La resta es %.2f\n", resp);
    if(num2!=0)
    {
        resp=division(num1,num2);
        printf("La division es %.2f\n", resp);
    }
    else
    {
        printf("MATH ERROR.reingrese dato.\n");
    }

    resp=multiplicacion(num1,num2);
    printf("La multiplicacion es %.2f\n", resp);
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

