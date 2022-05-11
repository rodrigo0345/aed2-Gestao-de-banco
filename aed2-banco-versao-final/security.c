#include "master.h"

/* Caso seja ativado o modo debug, ir� dar output ao ficheiro e � linha onde ocorreu o problema e ir� encerrar o programa */
void Security_Error(const char* file, const long line)
{
	char output[100] = "";
	char line_str[10] = "";

	sprintf(line_str, "%ld", line);
	strcat(output, file); 
	strcat(output, ": line("); strcat(output, line_str); strcat(output, ")");
	perror(output);
	exit(1);
}

/* Apaga todo o conte�do dentro das listas ligadas clts e cnts */
void Security_ProgramExit_Global(Clientes* clts, Contas* cnts)
{
	LinkedList_Delete_Clientes(&clts);
	LinkedList_Delete_Contas(&cnts);
	exit(0);
}

/* M�todo alternativo ao scanf, apenas funciona para numeros */
void Security_Input_Int(char variable[], int* store)
{
	fgets(variable, sizeof(variable) + 1, stdin);
	(*store) = atoi(variable);
	fflush(stdin);
}

/* Valida o n�mero introduzido pelo utilizador [0,Max] */
int Security_Validation_UInt(uint Input, uint Max)
{
	if (1 > Input || Max < Input)
	{
		return 0;
	}
	return 1;
}

/* encripta��o muito muito b�sica s� para parecer fixe :) */
void Security_Encrypt_String(char frase[])
{
	int i = 0;
	while (frase[i] != '\0')
	{
		if (frase[i] == 0) continue;
		else
			frase[i] += 3 * i;
		i++;
	}
}

/* verifica se a string do argumento tem ou n�o numeros e carateres especiais */
uint Security_CheckForDigits_String(char* string)
{
	size_t i = 0;
	for (i = 0; i < strlen(string); i++)
	{
		if (isdigit(string[i]))
		{
			return 1;
		}
		else if (string[i] == '!' || string[i] == '@' || string[i] == '#' || string[i] == '$'
			|| string[i] == '%' || string[i] == '^' || string[i] == '&' || string[i] == '*'
			|| string[i] == '(' || string[i] == ')' || string[i] == '-' || string[i] == '{'
			|| string[i] == '}' || string[i] == '[' || string[i] == ']' || string[i] == ':'
			|| string[i] == ';' || string[i] == '"' || string[i] == '\'' || string[i] == '<'
			|| string[i] == '>' || string[i] == '.' || string[i] == '/' || string[i] == '?'
			|| string[i] == '~' || string[i] == '`')
		{
			return 1;
		}
	}
	return 0;
}

/* pede automaticamente ao utilizador as credenciais de login e retorna um numero para indicar se foi bem sucedido ou n�o */
uint Security_Login(Clientes** clts, Clientes** result, char* guess, uint* id)
{
	char str[14];
	printf("\n-| ID DO CLIENTE |- ");
	Security_Input_Int(str, id);

	printf("\n-| PIN |- ");
	scanf_s("%[^\n]%*c", guess, 20);
	fflush(stdin);

	if (strlen(guess) > 6 || strlen(guess) <= 0)
	{
		system("cls");

		dialogo(CodigoInvalido);

		int check = getchar();
		return 0;
	}
	Security_Encrypt_String(guess);

	*result = LinkedList_BinarySearch_Clientes(*clts, *id);

	if (*result == NULL)
	{
		dialogo(SemClientes);

		int check = getchar();
		return 0;
	}

	/* ainda existe aqui um problema, ainda n�o sei porque */
	if (strcmp(guess, (*result)->pin))
	{
		dialogo(CodigoInvalido);

		int check = getchar();
		free(*result);
		*result = NULL;
		return 0;
	}
	return 1;
}

/* trata dos argumentos do cmd sendo o mais importante o comando --dev */
void Security_Flags(char* argv[])
{
	if (argv[1] == NULL) return;
	if (!strcmp(argv[1],"--dev"))
	{
		DevTools_Options();
	}
}

void Security_Replace_Char(char* s, char ch, char repl) {
	uint i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == ch)
		{
			s[i] = repl;
		}
		i++;
	}
}
