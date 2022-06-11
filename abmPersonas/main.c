#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define TAM 3

typedef struct
{
    int id;
    char nombre [20];
    char sexo;
    int edad;
    float altura;
    int isEmpty; //INDICADOR DE SI LA ESTRUCCTURA ESTA VACIA O CON INFORMACION (1 vacio/0 lleno).-
}ePersona;


int menu ();
int menuModificar ();
int primerLetraMayus(char nombre[]);
int inicializarPersonas(ePersona lista[], int tam);
int buscarLibre (ePersona lista[], int tam);
int buscarPersonaId (ePersona lista[], int , int id);
int altaPersona (ePersona lista[], int tam, int* pId);
int bajaPersona (ePersona lista[], int tam);
int modificarPersona (ePersona lista[], int tam);
void mostrarPersona(ePersona p);
int mostrarPersonas (ePersona lista[], int tam);

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

    system("pause");

    return 0;
}

int menu ()
{
    int opcion;
    system("cls");

    printf("       ****ABM Persona****\n\n");
    printf("1- Alta Persona\n");
    printf("2- Baja Persona\n");
    printf("3- Modificar Persona\n");
    printf("4- Ordenar Personas\n");
    printf("5- Listar Personas\n");
    printf("6- Salir\n\n");
    printf("Ingrese una opcion: ");
    scanf("%d", &opcion);

    return opcion;
}

int inicializarPersonas(ePersona lista[], int tam)
{
    int todoOk=0;

    if(lista!=NULL && tam>0)
    {
        for(int i=0; i<tam; i++)
        {
            lista[i].isEmpty=1;
        }
        todoOk=1;
    }
    return todoOk;
}

int buscarLibre (ePersona lista[], int tam)
{
    int todoOk=-1;

    if (lista!=NULL && tam>0)
    {
        for(int i=0; i<tam ; i++)
        {
            if (lista[i].isEmpty==1)
            {
                todoOk=i;
                break;
            }
        }
    }
    return todoOk;
}

int altaPersona (ePersona lista[], int tam, int* pId)
{
    int todoOk=0;
    int indice;
    ePersona auxP;

    if (lista!=NULL && tam>0)
    {
        system("cls");
        printf("      ****Alta de personas****\n\n");

        indice=buscarLibre(lista, tam);
        if (indice==-1)
        {
            printf("No hay lugares disponibles para su carga\n\n");
        }
        else
        {
            auxP.id=*pId;
            (*pId)++;

            printf("Ingrese su nombre: ");
            fflush(stdin);
            gets(auxP.nombre);
            strlwr(auxP.nombre);
            primerLetraMayus(auxP.nombre);

            printf("Ingrese su sexo (f/m): ");
            fflush(stdin);
            scanf("%c", &auxP.sexo);

            printf("Ingrese su edad: ");
            scanf("%d", &auxP.edad);

            printf("Ingrese su altura: ");
            scanf("%f", &auxP.altura);

            printf("\n");

            auxP.isEmpty=0;

            lista[indice]=auxP;

            todoOk=1;
        }
    }
    return todoOk;
}

void mostrarPersona(ePersona p)
{
    printf("%d     %-10s       %c          %d      %.2f\n", p.id
                                                          , p.nombre
                                                          , p.sexo
                                                          , p.edad
                                                          , p.altura);
}
int mostrarPersonas (ePersona lista[], int tam)
{
    int todoOk=0;
    int flagLista=0;

    if(lista!=NULL && tam>0)
    {
        system("cls");
        todoOk = 1;

        printf("             ***** LISTADO DE PERSONAS *****\n");
        printf("-----------------------------------------------------\n");
        printf("  ID       NOMBRES        SEXO       EDAD    ALTURA\n");
        printf("-----------------------------------------------------\n");

        for(int i=0; i<tam; i++)
        {
            if (!lista[i].isEmpty)
            {
                mostrarPersona(lista[i]);
                flagLista=1;
            }
        }
        printf("\n");
        if (flagLista==0)
        {
            printf("No hay personas para mostrar\n\n");
        }
    }
    return todoOk;
}

int buscarPersonaId (ePersona lista[], int tam, int id)
{
    int todoOk=-1;

    if (lista!=NULL && tam>0)
    {
        for(int i=0; i<tam ; i++)
        {
            if (lista[i].id==id && !lista[i].isEmpty)
            {
                todoOk=i;
                break;
            }
        }
    }
    return todoOk;
}

int bajaPersona (ePersona lista[], int tam)
{
    int todoOk=0;
    int indice;
    int id;
    char respuesta;

    if (lista!=NULL && tam>0)
    {
        system("cls");

        printf("      ****Baja de personas****\n\n");
        printf("Ingrese Id: ");
        scanf("%d", &id);
        printf("\n");

        indice=buscarPersonaId(lista, tam, id);

        if (indice==-1)
        {
            printf("El Id %d no se haya registrado\n", id);
        }
        else
        {
            printf("El Id pertenece a esta persona: \n\n");
            printf("Nombre: %s\n", lista[indice].nombre);
            printf("Sexo: %c\n", lista[indice].sexo);
            printf("Edad: %d\n", lista[indice].edad);
            printf("Altura: %.2f\n\n", lista[indice].altura);
            printf("Desea confirmar baja?(s/n): ");
            fflush(stdin);
            scanf("%c", &respuesta);
            printf("\n");

            if (respuesta=='s')
            {
                lista[indice].isEmpty=1;
                todoOk=1;
            }
            else
            {
                printf("Baja cancelada\n");
            }
        }
    }
    return todoOk;
}

int modificarPersona (ePersona lista[], int tam)
{
    int todoOk=0;
    int indice;
    int id;
    char respuesta;

    if (lista!=NULL && tam>0)
    {
        system("cls");

        printf("      ****Modificar persona****\n\n");
        printf("Ingrese Id: ");
        scanf("%d", &id);
        printf("\n");

        indice=buscarPersonaId(lista, tam, id);

        if (indice==-1)
        {
            printf("El Id %d no se haya registrado\n\n", id);
        }
        else
        {
            printf("El Id pertenece a esta persona: \n\n");
            printf("Nombre: %s\n", lista[indice].nombre);
            printf("Sexo: %c\n", lista[indice].sexo);
            printf("Edad: %d\n", lista[indice].edad);
            printf("Altura: %.2f\n\n", lista[indice].altura);
            printf("Desea confirmar la modificacion?(s/n): ");
            fflush(stdin);
            scanf("%c", &respuesta);
            printf("\n");

            if (respuesta=='s')
            {
                do
                {
                    switch (menuModificar())
                    {
                        case 1:
                            printf("Ingrese nuevo nombre: ");
                            fflush(stdin);
                            gets(lista[indice].nombre);
                            strlwr(lista[indice].nombre);
                            primerLetraMayus(lista[indice].nombre);

                            break;
                        case 2:
                            printf("Ingrese nuevo sexo: ");
                            scanf("%c", &lista[indice].sexo);
                            break;
                        case 3:
                            printf("Ingrese nueva edad: ");
                            scanf("%d", &lista[indice].edad);
                            break;
                        case 4:
                            printf("Ingrese nueva altura: ");
                            scanf("%f", &lista[indice].altura);
                            break;
                        case 5:
                            printf("Modificacion terminada\n\n");
                            respuesta='n';
                            break;
                        default:
                            printf("\n");
                            printf("Opcion Invalida!!!\n\n");
                    }
                }
                while (respuesta=='s');
                todoOk=1;
            }
            else
            {
                printf("Se ha cancelado la modificacion\n\n");
            }
        }

    }
    return todoOk;
}

int menuModificar ()
{
    int opcion;
    system("cls");

    printf("      ****Modificar persona****\n\n");
    printf("Que dato desea modificar? \n\n");
    printf("1- Nombre\n");
    printf("2- Sexo\n");
    printf("3- Edad\n");
    printf("4- Altura\n");
    printf("5- Terminar\n\n");
    printf("Ingrese una opcion: ");
    scanf("%d", &opcion);
    printf("\n");

    return opcion;
}

int primerLetraMayus(char nombre[])
{
    int todoOk = 0;

    if (nombre != NULL)
    {
        todoOk = 1;
        nombre[0]=toupper(nombre[0]);
        for (int i = 0; i < strlen(nombre); i ++)
        {
            if (nombre[i] == ' ')
            {
                nombre[i+1]=toupper(nombre[i+1]);
            }
        }
    }
    return todoOk;
}
