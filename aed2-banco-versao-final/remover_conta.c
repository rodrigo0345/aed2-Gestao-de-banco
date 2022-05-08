#include "structs.h"
#include "master.h"

void* Remover_Contas(Clientes** clts, Contas** cnts, uint* clts_size, uint* cnts_size)
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

	Clientes* result; char guess[30]; uint id;
	if (!Security_Login(clts, &result, guess, &id)) return NULL;

	if (!LinkedList_ShowContas_Clientes(result, cnts)) return NULL;

	char str[20]; uint opcao = 0;
	SetConsoleTextAttribute(h, 6);

	dialogo(SelecioneIDConta);

	Security_Input_Int(str, &opcao);

	Contas* aux = LinkedList_BinarySearch_Contas(*cnts, opcao);

	if (aux == NULL)
	{
		dialogo(SemContas);

		int check = getchar();
		return NULL;
	}

	LinkedList_RemoveAlreadyKnownNode_Contas(cnts, &aux);

	SetConsoleTextAttribute(h, 6);
	printf("\n[CONTA REMOVIDA COM SUCESSO]");

	return NULL;
}