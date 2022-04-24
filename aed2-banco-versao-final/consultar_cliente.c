#include "master.h"
#include "structs.h"

void* Consultar_Clientes(Clientes** clts, Contas** cnts, uint* clts_size, uint* cnts_size)
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	dialogo(13);
	char str[50];
	int opcao = 0;
	Security_Input_Int(str, &opcao);
	if (!Security_Validation_UInt(opcao, 4)) return -1;

	uint found = 0;
	Clientes* curr = *clts;
	Contas* guardado = *cnts;
	if (opcao == 1)
	{
		SetConsoleTextAttribute(h, 3);
		printf("\n-|");
		SetConsoleTextAttribute(h, 7);
		printf("Indique uma localidade: ");
		SetConsoleTextAttribute(h, 3);
		printf("|- ");
		SetConsoleTextAttribute(h, 7);
		scanf_s("%[^\n]%*c", str, 50);
		fflush(stdin);
		if (Security_CheckForDigits_String(str) || strlen(str) <= 1)
		{
			SetConsoleTextAttribute(h, 6);
			printf("[Localidade inválida] - (Apenas são permitidas letras e espaços)");
			getchar();
			return -1;
		}
		for (curr; curr != NULL; curr = curr->next)
		{
			if (!strcmp(curr->morada, str))
			{
				printf("\nID - [%u]\tNOME - [%s]\tSALDO GLOBAL - [%.2lf$]\tLOCALIDADE - [%s]\n",
					curr->id, curr->nome, curr->saldo_global, curr->morada);
				found++;
			}
		}
		SetConsoleTextAttribute(h, 6);
		if (!found) printf("\n[NENHUMA CONTA FOI ENCONTRADA]");
	}
	else if (opcao == 2)
	{
		for (curr; curr != NULL; curr = curr->next)
		{
			if (curr->saldo_global < 0)
			{
				printf("ID[%u]\tNOME[%s]\tSALDO GLOBAL[%.2lf$]\tLOCALIDADE[%s]\n",
					curr->id, curr->nome, curr->saldo_global, curr->morada);
				found++;
			}
		}
		if (!found) printf("Não existem contas com saldo negativo...");
	}
	else if (opcao == 3)
	{
		double saldo_global_ordem = 0;
		double saldo_global_prazo = 0;

		char guess[20]; uint ID; Clientes* result;
		if (!Security_Login(clts, &result, guess, &ID)) return -1;

		/* de forma a encontrarmos as contas associadas ao cliente
			temos que usar a variavel das contas
			(que mantem um resgisto das contas que o cliente tem)*/

		LinkedList_ShowContas_Clientes(result, cnts);
	}

	getchar();
	return 0;
}
