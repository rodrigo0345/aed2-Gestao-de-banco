#include "structs.h"
#include "master.h"

void* Consultar_Contas(Clientes** clts, Contas** cnts, uint* clts_size, uint* cnts_size)
{
	/* login necessário para consultar as contas do cliente */
	char guess[40]; uint id; Clientes* result;
	if (!Security_Login(clts, &result, guess, &id)) return NULL;

	if (!LinkedList_ShowContas_Clientes(result, cnts)) return NULL;

	char str[20] = ""; uint opcao = 0;

	dialogo(SelecioneIDConta);
	Security_Input_Int(str, &opcao);

	uint curr_id = opcao;
	Contas* curr = LinkedList_BinarySearch_Contas(*cnts, curr_id);

	if (curr == NULL || result->id != curr->id_owner)
	{
		dialogo(SemClientes);
		int check = getchar();
		return NULL;
	}

	dialogo(ConsultarConta);
	Security_Input_Int(str, &opcao);

	if (opcao == 1)
	{
		double saldo_ordem = 0;
		double saldo_prazo = 0;

		if (result->contas_associadas == NULL)
		{
			dialogo(ClienteSemContas);
			int check = getchar();
			return NULL;
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
		printf("-| POSIÇÃO GLOBAL DO CLIENTE |- ID[%d]\tSaldo à Ordem [%.2lf$]\tSaldo a Prazo[%.2lf$]", curr->id, saldo_ordem, saldo_prazo);
		int check = getchar();
	}
	else if (opcao == 2)
	{
		Stack_Show_Movimentos(curr->movimentos);
	}
	else
	{
		dialogo(OpcaoInvalida);
		int check = getchar();
		return NULL;
	}

	return NULL;
}