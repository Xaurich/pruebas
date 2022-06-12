#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "abmPersonas.h"
#define TAM 5

int main()
{
    char seguir = 's';
    int nextId = 20000;
    ePersona lista[TAM];

    inicializarPersonas(lista, TAM);

    do
    {
        switch (menu())
        {
        case 1:
            if (!altaPersona(lista, TAM, &nextId))
            {
                printf("No se ha podido realizar la carga\n\n");
            }
            else
            {
                printf("Alta exitosa\n\n");
            }
            break;
        case 2:
            if (!bajaPersona(lista, TAM))
            {
                printf("\n");
                printf("No se ha podido realizar la baja\n\n");
            }
            else
            {
                printf("Baja exitosa\n\n");
            }
            break;
        case 3:
            if (!modificarPersona(lista, TAM))
            {
                printf("No se ha podido realizar la modificacion\n\n");
            }
            break;
        case 4:
            printf("Ordenar Personas\n");
            break;
        case 5:
            mostrarPersonas(lista, TAM);
            break;
        case 6:
            system("cls");
            printf("Ha seleccionado salir\n\n");
            seguir='n';
            break;
        default:
            printf("\n");
            printf("Opcion Invalida!!!\n\n");
        }
        system("pause");
    }
    while(seguir == 's');

    return 0;
}



