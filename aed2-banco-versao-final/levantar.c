#include "structs.h"
#include "master.h"

void* Operacoes_Levantar(Clientes** clts, Contas** cnts, uint* clts_size, uint* cnts_size)
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
		dialogo(IDInvalido);

		int check = getchar();
		return NULL;
	}

	double montante = 0.0;

	dialogo(Montante);

	fgets(str, sizeof(str) + 1, stdin);
	montante = atof(str);
	fflush(stdin);

	if (!Security_Validation_UInt((uint)montante, 100000000))
	{
		dialogo(MontanteInvalido);

		int check = getchar();
		return NULL;
	}

	tmp->saldo -= montante;
	result->saldo_global -= montante;

	/* guardar dep�sito no livro-raz�o */
	if (sizeof(tmp->livro_razao) >= sizeof(char) * 149)
	{
		LOG_WARNING("Ledger cheio, por favor v� a consultar cliente e esvazie o seu ledger atual");
		int check = getchar();
		return NULL;
	}

	char* new_str = (char*)malloc(sizeof(char) * 150);
	if (tmp->livro_razao == NULL || tmp->livro_razao == "")
	{
		sprintf(new_str, "w:[v:%.2lf$ data:(%s)]\0", montante, time_str());
		tmp->livro_razao = malloc(sizeof(char) * 150);
		if (tmp->livro_razao == NULL)
			Security_Error(__FILE__, __LINE__);
		strcpy(tmp->livro_razao, new_str);
	}
	else
	{
		sprintf(new_str, "%s,w:[v:%.2lf$ data:(%s)]\0", tmp->livro_razao, montante, time_str());
		strcpy(tmp->livro_razao, new_str);
	}

	dialogo(OperacaoConcluida);

	new_str = NULL;
	free(new_str);

	int check = getchar();
	return NULL;
}