#include "master.h"
#include "structs.h"

void* Editar_Clientes(Clientes** clts, Contas** cnts, uint* clts_size, uint* cnts_size)
{
	char str[10];
	uint opcao;

	dialogo(7);
	dialogo(8);
	dialogo(9);
	dialogo(10);
	dialogo(11);
	dialogo(12);
	Security_Input_Int(str, &opcao);
	if (!Security_Validation_UInt(opcao, 4)) return NULL;

	char guess[50]; uint ID; Clientes* result;
	if (!Security_Login(clts, &result, guess, &ID)) return NULL;

	if (opcao == 1)
	{
		printf("Indique o novo Nome: ");
		scanf_s("%[^\n]%*c", guess, 50);
		fflush(stdin);

		if (Security_CheckForDigits_String(guess) || strlen(guess) <= 1)
		{
			system("cls");
			printf("Nome inv�lido! (Apenas s�o permitidas letras e espa�os)");
			int check = getchar();
			free(result);
			result = NULL;
			return NULL;
		}

		strcpy(result->nome, guess);
		printf("Opera��o conclu�da!");
	}
	else if (opcao == 2)
	{
		printf("Indique o novo PIN: ");
		scanf_s("%[^\n]%*c", guess, 50);
		fflush(stdin);

		if (strlen(guess) > 6 || strlen(guess) <= 0)
		{
			system("cls");
			printf("C�digo inv�lido! (Apenas s�o permitidos [0 -> 6] carateres)");
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
		printf("Indique a nova data de nascimento:\n");

		uint dia, mes, ano;
		printf("\n\nDia: "); Security_Input_Int(guess, &dia);
		printf("\nMes: ");	Security_Input_Int(guess, &mes);
		printf("\nAno: ");	Security_Input_Int(guess, &ano);
		if (!Time_CheckInputDate_Int(dia, mes, ano))
		{
			system("cls");
			printf("Data inv�lida!");
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
		printf("Indique a nova morada:\n");
		scanf_s("%[^\n]%*c", guess, 50);
		strcpy(result->morada, guess);
		fflush(stdin);
	}

	int check = getchar();
	return 0;
}
