#include "structs.h"
#include "master.h"

void* Criar_Clientes(Clientes** clts, Contas** cnts, uint* clts_size, uint* cnts_size)
{
	dialogo(CriarNovoUtilizador);
	dialogo(IntroduzirNome);

	Clientes* novo = LinkedList_New_Clientes();
	novo->saldo_global = 0;

	char string[50] = { 0 };
	scanf_s("%[^\n]%*c", string, 50);
	fflush(stdin);

	if (Security_CheckForDigits_String(string) || strlen(string) <= 1)
	{
		system("cls");

		dialogo(NomeInvalido);

		int check = getchar();
		free(novo);
		novo = NULL;
		return NULL;
	}
	novo->nome = (char*)malloc(strlen(string) * sizeof(char));
	if (novo->nome == NULL)
		Security_Error(__FILE__, __LINE__);
	strcpy(novo->nome, string);


	dialogo(CodigoDeAcesso);
	scanf_s("%[^\n]%*c", string, 50);
	fflush(stdin);
	if (strlen(string) > 6 || strlen(string) <= 0)
	{
		system("cls");
		dialogo(CodigoInvalido);

		free(novo);
		novo = NULL;
		int check = getchar();
		return NULL;
	}
	Security_Encrypt_String(string);
	novo->pin = (char*)malloc(strlen(string) * sizeof(char));
	if (novo->pin == NULL)
		Security_Error(__FILE__, __LINE__);
	strcpy(novo->pin, string);


	dialogo(DataDeNascimento);
	uint dia = 0, mes = 0, ano = 0;
	printf("\n\n\   -|Dia|- "); Security_Input_Int(string, &dia);
	printf("   -|Mes|- "); Security_Input_Int(string, &mes);
	printf("   -|Ano|- "); Security_Input_Int(string, &ano);
	if (!Time_CheckInputDate_Int(dia, mes, ano))
	{
		system("cls");
		dialogo(DataInvalida);

		free(novo);
		novo = NULL;
		int check = getchar();
		return NULL;
	}
	sprintf(string, "%u/%u/%u", dia, mes, ano);
	novo->data = (char*)malloc(15 * sizeof(char));
	if (novo->data == NULL)
		Security_Error(__FILE__, __LINE__);
	strcpy(novo->data, string);
	fflush(stdin);

	dialogo(Localidade);
	scanf_s(" %[^\n]%*c", string, 50);
	novo->morada = (char*)malloc(strlen(string) * sizeof(char));
	if (novo->morada == NULL)
		Security_Error(__FILE__, __LINE__);
	strcpy(novo->morada, string);
	fflush(stdin);

	novo->id = (*clts_size)++;

	LinkedList_AppendHead_Clientes(clts, *novo);

	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(h, 6);
	printf("\n[CLIENTE CRIADO COM SUCESSO]");
	SetConsoleTextAttribute(h, 7);
	printf("\n\n|MEMORIZE O ID -> ");
	SetConsoleTextAttribute(h, 3);
	printf("[%u]", novo->id);
	SetConsoleTextAttribute(h, 7);
	printf("|\n");

	int check = getchar();

	return 0;
}
