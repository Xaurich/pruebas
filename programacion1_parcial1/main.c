#include <stdio.h>
#include <stdlib.h>

float aplicarAumento(int num);
int reemplazarCaracteres (char vector[], char l1, char l2);


int main()
{
    int precio = 134;
    char cadena [] = {'d', 'f', 'f', 'r', 'f'};
    char caracter1 = 'f';
    char caracter2 = 'z';

    printf("%.2f", aplicarAumento(precio));
    printf("\n\n");

    reemplazarCaracteres(cadena, caracter1, caracter2);

    for(int i = 0; i < 5; i ++)
    {
        printf("%c ", cadena[i]);
    }

    return 0;
}

float aplicarAumento(int num)
{
    return (float)num+(num*0.05);
}

int reemplazarCaracteres (char vector[], char l1, char l2)
{
    int todoOk = 0;

    if (vector != NULL)
    {
        for(int i = 0; i < strlen(vector); i ++)
        {
            if(vector[i]==l1)
            {
                vector[i]=l2;
            }
        }
        todoOk = 1;
    }
    return todoOk;
}


