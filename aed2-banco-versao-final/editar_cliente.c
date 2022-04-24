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
	if (!Security_Validation_UInt(opcao, 4)) return -1;

	char guess[50]; uint ID; Clientes* result;
	if (!Security_Login(clts, &result, guess, &ID)) return -1;

	if (opcao == 1)
	{
		printf("Indique o novo Nome: ");
		scanf_s("%[^\n]%*c", guess, 50);
		fflush(stdin);

		if (Security_CheckForDigits_String(guess) || strlen(guess) <= 1)
		{
			system("cls");
			printf("Nome inválido! (Apenas são permitidas letras e espaços)");
			getchar();
			free(result);
			result = NULL;
			return -1;
		}

		strcpy(result->nome, guess);
		printf("Operação concluída!");
	}
	else if (opcao == 2)
	{
		printf("Indique o novo PIN: ");
		scanf_s("%[^\n]%*c", guess, 50);
		fflush(stdin);

		if (strlen(guess) > 6 || strlen(guess) <= 0)
		{
			system("cls");
			printf("Código inválido! (Apenas são permitidos [0 -> 6] carateres)");
			getchar();
			free(result);
			result = NULL;
			return -1;
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
			printf("Data inválida!");
			getchar();
			free(result);
			result = NULL;
			return -1;
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

	getchar();
	return 0;
}
