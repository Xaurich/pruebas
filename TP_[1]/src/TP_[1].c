/*
 ============================================================================
 Name        : TP_[1].c
 Author      : Emiliano Daniel Barrios Maurich
 Version     :
 Copyright   : Your copyright notice
 Description : Trabajo Practico N°1
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main ()
{
	int opcion;
	char salir = 'n';
	int flagKm = 0;
	int kM;
	int aerolineas = 162965;
	int latam = 159339;
	float debito;
	float credito;
	float bitCoin;
	float unitario;
	int diferencia;

	do {
		system("cls");
		printf("Menu de opciones\n\n");
		printf("1. Ingrese kilometros\n");
		printf("2. Ingrese precio\n");
		printf("_Precio Aerolineas: $%d\n", aerolineas);
		printf("_Precio Latam: $%d\n", latam);
		printf("3. Salir\n\n");

		printf("Elija una opcion\n");
		fflush(stdin);
		scanf("%d", &opcion);
		system("cls");

		switch (opcion)
		{
		case 1:
		flagKm = 1;
		printf("Ingrese la cantidad de kilometros: ");
		scanf("%d", &kM);
		break;

		case 2:
			if(flagKm == 0)
			{
				printf("Primero debe ingresar los Kilometros\n");
			}
			else
			{
				printf("Ingrese el precio de Aerolineas: ");
				scanf("%d", &aerolineas);

				printf("Ingrese el precio de Latam: ");
				scanf("%d", &latam);
				salir = 's';
			}
		break;

		case 3:
		return EXIT_SUCCESS;

		default:
			printf("Opcion invalida\n");
			break;
		}

		system("pause");

	}
	while (salir == 'n');

	system("cls");

	debito = aerolineas-(aerolineas/100*10);
	credito = aerolineas+(aerolineas/100*25);
	bitCoin = aerolineas/4606954.55;
	unitario = aerolineas/kM;


	printf("KMs Ingresados: %d km\n\n", kM);
	printf("Precio Aerolineas: $%d\n", aerolineas);
	printf("a) Precio con tarjeta de debito: $%.2f\n", debito);
	printf("b) Precio con tarjeta de credito: $%.2f\n", credito);
	printf("c) Precio pagado con bitcoin: $%.4f\n", bitCoin);
	printf("d) Mostrar precio unitario: $%.2f\n\n", unitario);

	debito = latam-(latam/100*10);
	credito = latam+(latam/100*25);
	bitCoin = latam/4606954.55;
	unitario = latam/kM;

	printf("Precio Latam: $%d\n", latam);
	printf("a) Precio con tarjeta de debito: $%.2f\n", debito);
	printf("b) Precio con tarjeta de credito: $%.2f\n", credito);
	printf("c) Precio pagado con bitcoin: $%.2f\n", bitCoin);
	printf("d) Mostrar precio unitario: $%.2f\n\n", unitario);

	diferencia = aerolineas - latam;

	printf("La diferencia de precio es: $%.d\n", diferencia);



	system("pause");

	return 0;

}


