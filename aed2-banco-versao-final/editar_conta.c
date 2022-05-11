#include "structs.h"
#include "master.h"

void* Editar_Contas(Clientes** clts, Contas** cnts, uint* clts_size, uint* cnts_size)
{
	/* login necessário para editar conta */
	char guess[40]; uint id; Clientes* result;
	if (!Security_Login(clts, &result, guess, &id)) return NULL;

	if (!LinkedList_ShowContas_Clientes(result, cnts)) return NULL;

	char str[20]; uint opcao = 0;
	
	dialogo(SelecioneIDConta);

	Security_Input_Int(str, &opcao);

	Contas* tmp = LinkedList_BinarySearch_Contas(*cnts, opcao);
	if (tmp == NULL || result->id != tmp->id_owner)
	{
		dialogo(IDInvalido);

		int check = getchar();
		return NULL;
	}

	/* Opções do utilizador */
	if (tmp->tipo == 1)
	{
		printf("\n[1] - Mudar o tipo da conta [%s -> %s]\n", "Prazo", "Ordem");
	}
	else
	{
		printf("\n[1] - Mudar o tipo da conta [%s -> %s]\n", "Ordem", "Prazo");
	}

	printf("\n[2] - Limpar o livro-razão\n");

	dialogo(SelecioneOpcao);

	Security_Input_Int(str, &opcao);

	/* alterar o tipo da conta */
	if (opcao == 1)
	{
		if (tmp->tipo == 1)
		{
			tmp->tipo = 0;
		}
		else
		{
			tmp->tipo = 1;
		}
	}
	else if (opcao == 2)
	{
		Stack_Destroy_Movimentos(&(tmp->movimentos));
	}
	else
	{
		dialogo(OpcaoInvalida);

		int check = getchar();
		return NULL;
	}

	dialogo(OperacaoConcluida);

	int check = getchar();
	return NULL;
}