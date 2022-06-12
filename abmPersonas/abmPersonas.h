#ifndef ABMPERSONAS_H_INCLUDED
#define ABMPERSONAS_H_INCLUDED
typedef struct
{
    int id;
    char nombre [20];
    char sexo;
    int edad;
    float altura;
    int isEmpty; //INDICADOR DE SI LA ESTRUCCTURA ESTA VACIA O CON INFORMACION (1 vacio/0 lleno/-1 dado de baja).-
}ePersona;

#endif // ABMPERSONAS_H_INCLUDED
int menu ();
int menuModificar ();
int inicializarPersonas(ePersona lista[], int tam);
int buscarLibre (ePersona lista[], int tam);
int buscarPersonaId (ePersona lista[], int , int id);
int altaPersona (ePersona lista[], int tam, int* pId);
int bajaPersona (ePersona lista[], int tam);
int modificarPersona (ePersona lista[], int tam);
void mostrarPersona(ePersona p);
int mostrarPersonas (ePersona lista[], int tam);
int primerLetraMayus(char nombre[]);



