#include "structs.h"
#include "master.h"

void* Operacoes_Levantar(Clientes** clts, Contas** cnts, uint* clts_size, uint* cnts_size)
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

	double montante = 0.0;

	dialogo(Montante);

	fgets(str, sizeof(str) + 1, stdin);
	montante = atof(str);
	fflush(stdin);

	if (!Security_Validation_UInt((uint)montante, 1000000))
	{
		dialogo(MontanteInvalido);

		int check = getchar();
		return NULL;
	}

	tmp->saldo -= montante;
	result->saldo_global -= montante;

	/* guarda a transação */
	Movimentos* aux = Stack_Create_Movimentos(tmp->id);

	aux->data = time_str();
	aux->montante = montante;
	strcpy(aux->tipo, "Crédito");

	Stack_Push_Movimentos(&tmp->movimentos, aux);

	dialogo(OperacaoConcluida);

	int check = getchar();
	return NULL;
}