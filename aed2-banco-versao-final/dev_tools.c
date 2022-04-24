#include <math.h>
#include "master.h"
#define CONST 5

void DevTools_Generate(long number)
{
	FILE* clientes = fopen("clientes.csv", "w"); FILE* contas = fopen("contas.csv", "w");
	char header_clientes[] = "id,palavra-passe,nome,data de nascimento,morada,saldo global,contas";
	char header_contas[] = "ID,Id do proprietário,ordem ou prazo,saldo,livro-razão";

	fprintf(clientes, "%s\n", header_clientes);
	fprintf(contas, "%s\n", header_contas);

	if (number == 5)
	{
		fprintf(clientes, "%s", "");
		fprintf(contas, "%s", "");
		return;
	}
	
	char name[10] = "Carlos";
	char pswd[] = "0369<@";
	char date[] = "24/04/2022";
	char morada[10];
	char contas_associadas[10] = "";
	double saldo = 50000.34;

	char livro_razao[10] = "d:50000";

	int i = 0;
	for (i = 0; i < number; i++)
	{
		if (i % 3 == 0) strcpy(morada, "Barcelos");
		else if (i % 2 == 0) strcpy(morada, "Guimarães");
		else strcpy(morada, "Braga");

		sprintf(contas_associadas, "%d", i);

		fprintf(clientes, "%d,%s,%s,%s,%s,%.2f,%s\n", i, name, pswd, date, morada, saldo, contas_associadas);

		fprintf(contas, "%d,%d,%s,%.2f,%s\n", i, i, "Ordem", saldo, "d:50000");
	}

	fclose(clientes);
	fclose(contas);
}

void DevTools_Options()
{
	printf(" --- Gerar clientes e contas [Dev-Tools] --- \n");
	printf("[0] - reset clientes.csv e contas.csv \n");
	printf("[1] - 50 clientes e 50 contas \n");
	printf("[2] - 500 clientes e 500 contas \n");
	printf("[3] - 5.000 clientes e 5.000 contas \n");
	printf("[4] - 50.000 clientes e 50.000 contas \n");
	printf("[5] - 500.000 clientes e 500.000 contas \n");
	printf("[6] - 5.000.000 clientes e 5.000.000 contas \n");

	int opcao;
	scanf("%d", &opcao);
	fflush(stdin);

	DevTools_Generate(CONST * pow(10, opcao));
}