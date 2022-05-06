#include "structs.h"
#include "master.h"

void* Criar_Contas(Clientes** clts, Contas** cnts, uint* clts_size, uint* cnts_size)
{
	/* login necessário para criar conta */
	char guess[40]; uint id; Clientes* result;
	if (!Security_Login(clts, &result, guess, &id)) return NULL;
	if (sizeof(result->contas_associadas) >= sizeof(char) * 69)
	{
		LOG_WARNING("Atingiu o numero máximo de contas associadas! Por favor diriga-se a um dos nossos balcões.");
		int check = getchar();
		return NULL;
	}

	Contas* tmp = LinkedList_New_Contas();

	printf("\n[1] - Criar conta a Prazo\n");
	printf("[2] - Criar conta à Ordem\n");

	char aux[20]; uint opcao;
	Security_Input_Int(aux, &opcao);

	if (!Security_Validation_UInt(opcao, 2))
	{
		printf("Opção inválida!");
		int check = getch();
		return -1;
	}
	if (opcao == 1)
	{
		tmp->tipo = 1;
	}
	else if (opcao == 2)
	{
		tmp->tipo = 0;
	}
	tmp->id = ++(*cnts_size);
	tmp->id_owner = result->id;
	tmp->livro_razao = "";
	tmp->saldo = 0;

	char* new_str = (char*)malloc(sizeof(char) * (70 + 1));

	if (result->contas_associadas == NULL || result->contas_associadas == "")
	{
		sprintf(new_str, "%d\0", tmp->id);
		result->contas_associadas = malloc(sizeof(char) * 70);
		if (result->contas_associadas == NULL)
			Security_Error("criar_conta.c//Criar_Contas//result->contas_associadas");
		strcpy(result->contas_associadas, new_str);
	}
	else
	{
		sprintf(new_str, "%s/%d\0", result->contas_associadas, tmp->id);
		strcpy(result->contas_associadas, new_str);
	}


	LinkedList_AppendHead_Contas(cnts, *tmp);

	printf("\nConta criada com sucesso!");
	free(new_str);

	return 0;
}