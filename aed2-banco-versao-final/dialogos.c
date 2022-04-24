#include "master.h"

void introducao()
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

	SetConsoleTextAttribute(h, 6);
	printf("\n\n_______________________________________________________________________________________________________________________\n|\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t|");
	printf("\n|\t\t\t\tBANCO CENTRAL DE ENGENHARIA E GESTÃO DE SISTEMAS DA INFORMAÇÃO\t\t\t\t|\n| ");
	printf("_____________________________________________________________________________________________________________________|\n\n");
	SetConsoleTextAttribute(h, 7);
	printf("\t\t\t    ________________| PRESSIONE ENTER PARA PROSSEGUIR |________________\n");
	SetConsoleTextAttribute(h, 6);
	printf("\n\n\n\n |INSTITUIÇÃO| ");
	SetConsoleTextAttribute(h, 7);
	printf("\n\n [Universidade do Minho]");

	SetConsoleTextAttribute(h, 6);
	printf("\n\n\n |AUTORES| ");
	SetConsoleTextAttribute(h, 7);
	printf("\n\n [Ana Gomes] - [A100447]\n [Inês Marques] - [A100434]\n [Rodrigo Casanova] - [A101730]\n\n");
	getchar();
	fflush(stdin);
}

void dialogo(int id)
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	switch (id)
	{
	case 1:
	{
		SetConsoleTextAttribute(h, 6);
		printf("\n\n[GESTÃO DOS CLIENTES]\n");
		SetConsoleTextAttribute(h, 3);
		printf("\n[1] - ");
		SetConsoleTextAttribute(h, 7);
		printf("Criar novo cliente.\n");
		SetConsoleTextAttribute(h, 3);
		printf("[2] - ");
		SetConsoleTextAttribute(h, 7);
		printf("Editar informação de um cliente.\n");
		SetConsoleTextAttribute(h, 3);
		printf("[3] - ");
		SetConsoleTextAttribute(h, 7);
		printf("Consultar dados de clientes.\n");
		SetConsoleTextAttribute(h, 3);
		printf("[4] - ");
		SetConsoleTextAttribute(h, 7);
		printf("Remover determinado cliente.\n");
		SetConsoleTextAttribute(h, 3);
		printf("[5] - ");
		SetConsoleTextAttribute(h, 7);
		printf("Listar clientes.\n");

		SetConsoleTextAttribute(h, 6);
		printf("\n[CONTAS DOS CLIENTES]\n");
		SetConsoleTextAttribute(h, 3);
		printf("\n[6] - ");
		SetConsoleTextAttribute(h, 7);
		printf("Criar uma nova conta.\n");
		SetConsoleTextAttribute(h, 3);
		printf("[7] - ");
		SetConsoleTextAttribute(h, 7);
		printf("Editar informação de uma conta.\n");
		SetConsoleTextAttribute(h, 3);
		printf("[8] - ");
		SetConsoleTextAttribute(h, 7);
		printf("Consultar dados de contas.\n");
		SetConsoleTextAttribute(h, 3);
		printf("[9] - ");
		SetConsoleTextAttribute(h, 7);
		printf("Remover determinada conta.\n");
		SetConsoleTextAttribute(h, 3);
		printf("[10]- ");
		SetConsoleTextAttribute(h, 7);
		printf("Listar contas.\n");

		SetConsoleTextAttribute(h, 6);
		printf("\n[ÁREA DOS CLIENTES]\n");
		SetConsoleTextAttribute(h, 3);
		printf("\n[11]- ");
		SetConsoleTextAttribute(h, 7);
		printf("Depositar.\n");
		SetConsoleTextAttribute(h, 3);
		printf("[12]- ");
		SetConsoleTextAttribute(h, 7);
		printf("Levantar.\n");
		SetConsoleTextAttribute(h, 6);
		printf("[13]- ");
		SetConsoleTextAttribute(h, 7);
		printf("Exit and Save.\n");
		SetConsoleTextAttribute(h, 6);
		printf("\n[SELECIONE O ALGARISMO REFERENTE À SUA ESCOLHA] - ");
		SetConsoleTextAttribute(h, 3);
	}
	break;

	case 2:
	{
		SetConsoleTextAttribute(h, 6);
		printf("\n[CRIAR UM NOVO UTILIZADOR] {Utilize -1 para voltar}");
	}
	break;
	case 3:
	{
		SetConsoleTextAttribute(h, 3);
		printf("\n\n[1]");
		SetConsoleTextAttribute(h, 7);
		printf("-|NOME|-  ");
	}
	break;
	case 4:
	{
		SetConsoleTextAttribute(h, 3);
		printf("\n[2]");
		SetConsoleTextAttribute(h, 7);
		printf("-|CÓDIGO DE ACESSO [6 DÍGITOS] (NUNCA SE ESQUEÇA DESTE CÓDIGO)|-  ");
	}
	break;
	case 5:
	{
		SetConsoleTextAttribute(h, 3);
		printf("\n[3]");
		SetConsoleTextAttribute(h, 7);
		printf("-|DATA DE NASCIMENTO|  ");
	}
	break;
	case 6:
	{
		SetConsoleTextAttribute(h, 3);
		printf("\n[4]");
		SetConsoleTextAttribute(h, 7);
		printf("-|LOCALIDADE DE RESIDÊNCIA|-  ");
	}
	break;

	case 7:
	{
		SetConsoleTextAttribute(h, 6);
		printf("\n[EDITAR OS UTILIZADORES JÁ CRIADOS]");
	}
	break;
	case 8:
	{
		SetConsoleTextAttribute(h, 3);
		printf("\n\n\n[1] -");
		SetConsoleTextAttribute(h, 7);
		printf("-|Alterar o nome do utilizador|\n");
	}
	break;
	case 9:
	{
		SetConsoleTextAttribute(h, 3);
		printf("[2] -");
		SetConsoleTextAttribute(h, 7);
		printf("-|Alterar o código de acesso|\n");
	}
	break;
	case 10:
	{
		SetConsoleTextAttribute(h, 3);
		printf("[3] -");
		SetConsoleTextAttribute(h, 7);
		printf("-|Alterar a data de nascimento do utilizador|\n");
	}
	break;
	case 11:
	{
		SetConsoleTextAttribute(h, 3);
		printf("[4] -");
		SetConsoleTextAttribute(h, 7);
		printf("-|Alterar a localidade de residência do utilizador|\n\n");
	}
	break;
	case 12:
	{
		SetConsoleTextAttribute(h, 6);
		printf("\n[INTRODUZA O ALGARISMO REFERENTE À SUA ESCOLHA] - ");
	}
	break;

	case 13:
	{
		SetConsoleTextAttribute(h, 6);
		printf("\n[CONSULTAR DADOS EXISTENTES]\n");
		SetConsoleTextAttribute(h, 3);
		printf("\n[1] - ");
		SetConsoleTextAttribute(h, 7);
		printf("Mostrar clientes por localidade\n");
		SetConsoleTextAttribute(h, 3);
		printf("[2] - ");
		SetConsoleTextAttribute(h, 7);
		printf("Mostrar clientes com saldo negativo\n");
		SetConsoleTextAttribute(h, 3);
		printf("[3] - ");
		SetConsoleTextAttribute(h, 7);
		printf("Consultar contas pessoais\n");
		SetConsoleTextAttribute(h, 6);
		printf("\n[INTRODUZA O ALGARISMO REFERENTE À SUA ESCOLHA] - ");

	}
	break;
	case 14:
	{

	}
	break;
	case 15:
	{

	}
	break;
	default:
		printf("Erro, id dos diálogos inválido");
		break;
	}
	SetConsoleTextAttribute(h, 7);
}
