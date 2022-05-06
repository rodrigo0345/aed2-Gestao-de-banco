#include "master.h"
#include "structs.h"

void* Remover_Clientes(Clientes** clts, Contas** cnts, uint* clts_size, uint* cnts_size)
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	char str[20] = "";
	char* guess = (char*)malloc(sizeof(char) * 20);
	if (guess == NULL)
		Security_Error("remover_clientes.c//Remover_Clientes//char* guess");

	uint ID;
	SetConsoleTextAttribute(h, 6);
	printf("\n[REMOVER CLIENTE]");
	Clientes* result;
	if (!Security_Login(clts, &result, guess, &ID)) return NULL;

	LinkedList_RemoveNode_Clientes(clts, cnts, ID);

	SetConsoleTextAttribute(h, 6);
	printf("\n[CONTA ELIMINADA COM SUCESSO] (não se esqueça de SAIR E GUARDAR para aplicar as alterações)");

	free(result);
	result = NULL;

	int check = getchar();
	return NULL;
}