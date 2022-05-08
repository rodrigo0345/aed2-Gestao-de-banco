#include "structs.h"
#include "master.h"

void* Operacoes_Depositar(Clientes** clts, Contas** cnts, uint* clts_size, uint* cnts_size)
{
	/* login necessário para editar conta */
	char guess[40]; uint id; Clientes* result;
	if (!Security_Login(clts, &result, guess, &id)) return NULL;

	if (!LinkedList_ShowContas_Clientes(result, cnts)) return NULL;

	char str[20]; uint opcao = 0;
	printf("\nEscolha uma conta: ");
	Security_Input_Int(str, &opcao);

	Contas* tmp = LinkedList_BinarySearch_Contas(*cnts, opcao);
	if (tmp == NULL || result->id != tmp->id_owner)
	{
		printf("\nO id que escolheu não existe");
		int check = getchar();
		return NULL;
	}

	double montante = 0;
	printf("\nIndique o montante (use vírgula para casas decimais): ");
	fgets(str, sizeof(str) + 1, stdin);
	montante = atof(str);
	fflush(stdin);

	if (!Security_Validation_UInt((uint)montante, 100000000))
	{
		printf("\nMontante inválido!");
		int check = getchar();
		return NULL;
	}

	tmp->saldo += montante;
	result->saldo_global += montante;

	/* guardar depósito no livro-razão */
	if (sizeof(tmp->livro_razao) >= sizeof(char) * 150)
	{
		LOG_WARNING("Ledger cheio, por favor vá a consultar cliente e esvazie o seu ledger atual");
		return NULL;
	}

	const uint tam = strlen(tmp->livro_razao) + 40;

	char* new_str = (char*)malloc(sizeof(char) * tam);
	if (tmp->livro_razao == NULL || tmp->livro_razao == "")
	{
		sprintf(new_str, "d:[v:%.2lf$ data:(%s)]\0", montante, time_str());
		tmp->livro_razao = malloc(sizeof(char) * 60);
		if (tmp->livro_razao == NULL)
			Security_Error(__FILE__, __LINE__);
		strcpy(tmp->livro_razao, new_str);
	}
	else
	{
		sprintf(new_str, "%s,d:[v:%.2lf$ data:(%s)]\0", tmp->livro_razao, montante, time_str());
		strcpy(tmp->livro_razao, new_str);
	}
	printf("\nDepósito concluído!\n");

	new_str = NULL;
	free(new_str);

	int check = getchar();
	return NULL;
}