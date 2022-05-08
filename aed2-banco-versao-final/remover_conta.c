#include "structs.h"
#include "master.h"

void* Remover_Contas(Clientes** clts, Contas** cnts, uint* clts_size, uint* cnts_size)
{
	Clientes* result; char guess[30]; uint id;
	if (!Security_Login(clts, &result, guess, &id)) return NULL;

	if (!LinkedList_ShowContas_Clientes(result, cnts)) return NULL;

	char str[20]; uint opcao = 0;
	printf("\nEscolha o ID da conta que pretende eliminar: ");
	Security_Input_Int(str, &opcao);

	Contas* aux = LinkedList_BinarySearch_Contas(*cnts, opcao);

	if (aux == NULL)
	{
		printf("\nA conta que escolheu não existe!");
		int check = getchar();
		return NULL;
	}

	LinkedList_RemoveAlreadyKnownNode_Contas(cnts, &aux);

	printf("\nConta removida com sucesso!");

	return NULL;
}