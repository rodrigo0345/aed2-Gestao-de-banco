#include <math.h>
#include "master.h"
#define CONSTANTE 5

void DevTools_Generate(long number)
{
	FILE* clientes = fopen("clientes.csv", "w"); FILE* contas = fopen("contas.csv", "w");
	if (clientes == NULL) Security_Error(__FILE__, __LINE__);
	if (contas == NULL) Security_Error(__FILE__, __LINE__);

	char header_clientes[] = "id;palavra-passe;nome;data de nascimento;morada;saldo global;contas";
	char header_contas[] = "ID;Id do proprietário;ordem ou prazo;saldo;livro-razão";

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

	char livro_razao[13] = "d:[v:50000]";

	int i = 0;
	for (i = 0; i < number; i++)
	{
		if (i % 3 == 0) strcpy(morada, "Barcelos");
		else if (i % 2 == 0) strcpy(morada, "Guimarães");
		else strcpy(morada, "Braga");

		sprintf(contas_associadas, "%d", i);

		fprintf(clientes, "%d;%s;%s;%s;%s;%.2f;%s\n", i, name, pswd, date, morada, saldo, contas_associadas);

		fprintf(contas, "%d;%d;%s;%.2f;%s\n", i, i, "Ordem", saldo, "d:50000");
	}

	fclose(clientes);
	fclose(contas);
}

void DevTools_Options()
{
	dialogo(Dev);

	int opcao;
	scanf("%d", &opcao);
	fflush(stdin);
	
	(opcao > 6 || opcao < 0) ? 0: DevTools_Generate(CONSTANTE * (long)pow(10, opcao));
	
}
