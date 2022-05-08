#include "master.h"
#include "structs.h"

void* Remover_Clientes(Clientes** clts, Contas** cnts, uint* clts_size, uint* cnts_size)
{
	char str[20] = "";
	char* guess = (char*)malloc(sizeof(char) * 20);
	if (guess == NULL)
		Security_Error(__FILE__, __LINE__);

	uint ID;
	
	dialogo(RemoverCliente);

	Clientes* result;
	if (!Security_Login(clts, &result, guess, &ID)) return NULL;

	LinkedList_RemoveNode_Clientes(clts, cnts, ID);

	dialogo(ClienteRemovidoSucesso);

	free(result);
	result = NULL;

	int check = getchar();
	return NULL;
}