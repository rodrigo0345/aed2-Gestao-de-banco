#include "structs.h"
#include "master.h"

void* Operacoes_Depositar(Clientes** clts, Contas** cnts, uint* clts_size, uint* cnts_size)
{
	/* login necess�rio para editar conta */
	char guess[40]; uint id; Clientes* result;
	if (!Security_Login(clts, &result, guess, &id)) return NULL;

	if (!LinkedList_ShowContas_Clientes(result, cnts)) return NULL;

	char str[20]; uint opcao = 0;

	dialogo(SelecioneIDConta);

	Security_Input_Int(str, &opcao);

	Contas* tmp = LinkedList_BinarySearch_Contas(*cnts, opcao);
	if (tmp == NULL || result->id != tmp->id_owner)
	{
		dialogo(SemClientes);

		int check = getchar();
		return NULL;
	}

	double montante = 0;

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

	tmp->saldo += montante;
	result->saldo_global += montante;

	/* guardar dep�sito no livro-raz�o */
	if (strlen(tmp->livro_razao) >= 180)
	{
		LOG_WARNING("Ledger cheio, por favor v� a consultar cliente e esvazie o seu ledger atual");
		int check = getchar();

		return NULL;
	}

	if (tmp->livro_razao == NULL || !strcmp(tmp->livro_razao, ""))
	{
		tmp->livro_razao = malloc(sizeof(char) * 230);
		if (tmp->livro_razao == NULL)
			Security_Error(__FILE__, __LINE__);

		/* ocupa					 28 chars				 + 	8 chars  + 24 chars 	= 60 chars (no pior caso) */
		sprintf(tmp->livro_razao, "D�bito:[montante:%.2lf� data:(%s)]\0", montante, time_str());
	}
	else
	{
		if (tmp->livro_razao == NULL)
		{
			tmp->livro_razao = malloc(sizeof(char) * 230);
			if (tmp->livro_razao == NULL)
				Security_Error(__FILE__, __LINE__);
		}

		/* max: ~215 char */
		sprintf(tmp->livro_razao, "%s_D�bito:[montante:%.2lf� data:(%s)]\0", tmp->livro_razao, montante, time_str());
	}

	dialogo(OperacaoConcluida);

	int check = getchar();
	return NULL;
}