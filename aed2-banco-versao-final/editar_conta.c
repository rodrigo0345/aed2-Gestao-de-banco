#include "structs.h"
#include "master.h"

void* Editar_Contas(Clientes** clts, Contas** cnts, uint* clts_size, uint* cnts_size)
{
	/* login necessário para editar conta */
	char guess[40]; uint id; Clientes* result;
	if (!Security_Login(clts, &result, guess, &id)) return -1;

	if (!LinkedList_ShowContas_Clientes(result, cnts)) return -1;

	char str[20]; uint opcao;
	printf("\nEscolha uma conta: ");
	Security_Input_Int(str, &opcao);

	Contas* tmp = LinkedList_BinarySearch_Contas(*cnts, opcao);
	if (tmp == NULL || result->id != tmp->id_owner)
	{
		printf("\nO id que escolheu não existe");
		int check = getchar();
		return -1;
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

	printf("[2] - Limpar o livro-razão\n");
	printf("\nEscolha uma conta: ");
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
		tmp->livro_razao = "";
	}
	else
	{
		printf("\nOpção inválida!");
		int check = getchar();
		return -1;
	}

	printf("\nOpções alteradas com sucesso!");
	int check = getchar();
	return 0;
}