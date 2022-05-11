#include "master.h"
#include "structs.h"

/* cada movimento precisa de estar associado a uma conta, dai passarmos o id_conta! */
Movimentos* Stack_Create_Movimentos(uint id_conta) 
{
	Movimentos* aux = (Movimentos*)malloc(sizeof(Movimentos));

	aux->data = NULL;
	aux->id_conta = id_conta;
	aux->montante = 0;
	aux->next = NULL;

	return aux;
}

void Stack_Push_Movimentos(Movimentos** s, Movimentos* d)
{
	Movimentos* elemento = (Movimentos*)malloc(sizeof(Movimentos));

	elemento = d;
	elemento->next = NULL;

	if (*s == NULL) {
		*s = elemento;
	}
	else {
		elemento->next = *s;
		*s = elemento;
	}
}

void Stack_Pop_Movimentos(Movimentos** s) 
{
	Movimentos* aux;
	aux = *s;
	if (*s != NULL) {
		*s = aux->next;

		free(aux->data);
		free(aux);
		aux = NULL;
	}
}

static Movimentos* Stack_Peek_Movimentos(Movimentos* s) 
{
	Movimentos* p = NULL;
	if (s != NULL) {
		p = (Movimentos*)malloc(sizeof(Movimentos));
		p = s;
	}
	return p;
}

static int Stack_Empty_Movimentos(Movimentos* s) 
{
	if (s == NULL)
		return 1;
	else
		return 0;
}

void Stack_Destroy_Movimentos(Movimentos** s) 
{
	while (!Stack_Empty_Movimentos(*s))
		Stack_Pop_Movimentos(s);
	free(*s);
	*s = NULL;
}

void Stack_Show_Movimentos(Movimentos* s)
{
	system("cls");

	if (s == NULL)
	{
		dialogo(SemMovimentos);
	}

	for (; s != NULL; s = s->next)
	{
		printf("\nTipo[%s]\tSaldo[%.2lf$]\tData da transação[%s]\n", s->tipo, s->montante, s->data);
	}

	int check = getchar();
}