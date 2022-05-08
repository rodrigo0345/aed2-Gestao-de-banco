#include "master.h"
#include "structs.h"

#define MAX_ITERATIONS 50

void* Listar_Clientes(Clientes** clts, Contas** cnts, uint* clts_size, uint* cnts_size)
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

	Clientes* curr = *clts;
	if (curr == NULL)
	{
		dialogo(SemClientes);

		int check = getchar();
		return NULL;
	}

	uint count = 0;
	for (curr; curr != NULL && count < MAX_ITERATIONS; curr = curr->next, count++)
	{
		printf("ID[%u]\tNOME[%s]\tSALDO GLOBAL[%.2lf$]\tLOCALIDADE[%s]\n",
			curr->id, curr->nome, curr->saldo_global, curr->morada);
	}
	printf("\n");
	if (count == MAX_ITERATIONS)
	{
		SetConsoleTextAttribute(h, 6);
		printf("[MÁXIMO DE CLIENTES EXIBIDOS] - [%u clientes]\n\n", count);
	}

	system("pause");
	return NULL;
}