#include "master.h"
#include "structs.h"

void* Editar_Clientes(Clientes** clts, Contas** cnts, uint* clts_size, uint* cnts_size)
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

	char str[10];
	uint opcao;

	dialogo(EditarClientes);
	dialogo(Selecao);

	Security_Input_Int(str, &opcao);
	if (!Security_Validation_UInt(opcao, 4)) return NULL;

	char guess[50]; uint ID; Clientes* result;
	if (!Security_Login(clts, &result, guess, &ID)) return NULL;

	if (opcao == 1)
	{
		dialogo(IntroduzirNome);
		scanf_s("%[^\n]%*c", guess, 50);
		fflush(stdin);

		if (Security_CheckForDigits_String(guess) || strlen(guess) <= 1)
		{
			system("cls");

			dialogo(NomeInvalido);

			int check = getchar();
			free(result);
			result = NULL;
			return NULL;
		}

		strcpy(result->nome, guess);
	}
	else if (opcao == 2)
	{
		dialogo(CodigoDeAcesso);

		scanf_s("%[^\n]%*c", guess, 50);
		fflush(stdin);

		if (strlen(guess) > 6 || strlen(guess) <= 0)
		{
			system("cls");
			dialogo(CodigoInvalido);
			int check = getchar();
			free(result);
			result = NULL;
			return NULL;
		}
		Security_Encrypt_String(guess);
		strcpy(result->pin, guess);
	}
	else if (opcao == 3)
	{
		dialogo(DataDeNascimento);

		uint dia = 0, mes = 0, ano = 0;

		SetConsoleTextAttribute(h, 7);
		printf("\n\n-| Dia |- "); Security_Input_Int(guess, &dia);
		printf("-| Mes |- ");	Security_Input_Int(guess, &mes);
		printf("-| Ano |- ");	Security_Input_Int(guess, &ano);
		if (!Time_CheckInputDate_Int(dia, mes, ano))
		{
			system("cls");

			dialogo(DataInvalida);

			int check = getchar();
			free(result);
			result = NULL;
			return NULL;
		}
		sprintf(guess, "%u/%u/%u", dia, mes, ano);
		strcpy(result->data, guess);
	}
	else if (opcao == 4)
	{
		dialogo(Localidade);

		scanf_s("%[^\n]%*c", guess, 50);
		strcpy(result->morada, guess);
		fflush(stdin);
	}

	dialogo(OperacaoConcluida);

	int check = getchar();
	return 0;
}
