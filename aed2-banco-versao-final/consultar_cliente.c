#include "master.h"
#include "structs.h"

void* Consultar_Clientes(Clientes** clts, Contas** cnts, uint* clts_size, uint* cnts_size)
{
	dialogo(ConsultarCliente);

	char str[50];
	int opcao = 0;
	Security_Input_Int(str, &opcao);
	if (!Security_Validation_UInt(opcao, 4)) return NULL;

	uint found = 0;
	Clientes* curr = *clts;
	Contas* guardado = *cnts;
	if (opcao == 1)
	{
		dialogo(Localidade);
		scanf_s("%[^\n]%*c", str, 50);
		fflush(stdin);
		if (Security_CheckForDigits_String(str) || strlen(str) <= 1)
		{
			dialogo(LocalidadeInvalida);
			int check = getchar();
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
		if (!found)
		{
			dialogo(SemClientes);
		}
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
		if (!found)
		{
			dialogo(SemContasComSNegativo);
		}
	}
	else if (opcao == 3)
	{
		double saldo_global_ordem = 0;
		double saldo_global_prazo = 0;

		char guess[20]; uint ID; Clientes* result;
		if (!Security_Login(clts, &result, guess, &ID)) return NULL;

		/* de forma a encontrarmos as contas associadas ao cliente
			temos que usar a variavel das contas
			(que mantem um resgisto das contas que o cliente tem)*/

		LinkedList_ShowContas_Clientes(result, cnts);
	}

	int check = getchar();
	return NULL;
}
