#include "structs.h"
#include "master.h"

void* Consultar_Contas(Clientes** clts, Contas** cnts, uint* clts_size, uint* cnts_size)
{
	/* login necessário para consultar as contas */
	char guess[40]; uint id; Clientes* result;
	if (!Security_Login(clts, &result, guess, &id)) return -1;

	if (!LinkedList_ShowContas_Clientes(result, cnts)) return -1;

	char str[20]; uint opcao;
	printf("\nEscolha o ID da conta que pretende consultar: ");
	Security_Input_Int(str, &opcao);

	uint curr_id = opcao;
	Contas* curr = LinkedList_BinarySearch_Contas(*cnts, curr_id);
	if (curr == NULL || result->id != curr->id_owner)
	{
		printf("\nO id que escolheu não existe");
		getchar();
		return -1;
	}

	printf("\n[1] - Consultar a sua posição global\n");
	printf("[2] - Guardar o livro-razão da conta num ficheiro .txt\n");

	printf("\n[INTRODUZA O ALGARISMO REFERENTE À SUA ESCOLHA] - ");
	Security_Input_Int(str, &opcao);

	if (opcao == 1)
	{
		double saldo_ordem = 0;
		double saldo_prazo = 0;

		if (result->contas_associadas == NULL)
		{
			printf("Não existem contas associadas a este cliente!");
			getchar();
			return 0;
		}

		char* key = strtok(result->contas_associadas, "/");
		while (key != NULL)
		{
			uint id = atoi(key);

			/*  tmp pode ser NULL porque sempre que apagamos uma conta,
				não apagamos o seu registo do cliente					*/
			Contas* tmp = LinkedList_BinarySearch_Contas(*cnts, id);

			if (tmp == NULL)
			{
				key = strtok(NULL, "/");
				continue;
			}

			if (tmp->tipo == 1)
			{
				saldo_prazo += tmp->saldo;
			}
			else
			{
				saldo_ordem += tmp->saldo;
			}

			key = strtok(NULL, "/");
		}
		printf("Posição global do cliente: ID[%d]\tSaldo à Ordem [%.2lf$]\tSaldo a Prazo[%.2lf$]", curr->id, saldo_ordem, saldo_prazo);
		getchar();
	}
	else if (opcao == 2)
	{
		Security_FileLivroRazao(curr);
	}
	else
	{
		printf("\nOpção inválida!");
		getchar();
		return -1;
	}

	return 0;
}