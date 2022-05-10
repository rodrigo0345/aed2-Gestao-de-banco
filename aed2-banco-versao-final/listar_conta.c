#include "structs.h"
#include "master.h"

#define MAX_ITERATIONS 50

void* Listar_Contas(Clientes** clts, Contas** cnts, uint* clts_size, uint* cnts_size)
{
	Contas* curr = *cnts;
	if (curr == NULL)
	{
		dialogo(SemContas);

		int check = getchar();
		return NULL;
	}

	uint count = 0;
	for (curr = *cnts; curr != NULL && count < MAX_ITERATIONS; curr = curr->next, count++)
	{
		if (curr->tipo == 1)
		{
			printf("ID[%u]\tSaldo[%.2lf$]\tTipo[%s]\n", curr->id, curr->saldo, "Prazo");
		}
		else
		{
			printf("ID[%u]\tsaldo[%.2lf$]\ttipo[%s]\n", curr->id, curr->saldo, "Ordem");
		}
	}
	printf("\n");
	if (count == MAX_ITERATIONS)
	{
		printf("MÁXIMO DE CONTAS EXIBIDAS [%u]\n\n", count);
	}

	system("pause");
	return NULL;
}