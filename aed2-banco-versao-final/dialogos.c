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
	int check = getchar();
	fflush(stdin);
}

void dialogo(int id)
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	switch (id)
	{
	case MenuInicial:
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
		SetConsoleTextAttribute(h, 4);
		printf("[13]- ");
		SetConsoleTextAttribute(h, 7);
		printf("Guardar e sair.\n");
		SetConsoleTextAttribute(h, 6);
		printf("\n[SELECIONE O ALGARISMO REFERENTE À SUA ESCOLHA] - ");
		SetConsoleTextAttribute(h, 3);
	}
	break;

	case CriarNovoUtilizador:
	{
		SetConsoleTextAttribute(h, 6);
		printf("\n[CRIAR UM NOVO UTILIZADOR] {Utilize -1 para voltar}");
	}
	break;
	case IntroduzirNome:
	{
		SetConsoleTextAttribute(h, 3);
		printf("\n\n[1]");
		SetConsoleTextAttribute(h, 7);
		printf("-|NOME|-  ");
	}
	break;
	case CodigoDeAcesso:
	{
		SetConsoleTextAttribute(h, 3);
		printf("\n[2]");
		SetConsoleTextAttribute(h, 7);
		printf("-|CÓDIGO DE ACESSO [6 DÍGITOS] (NUNCA SE ESQUEÇA DESTE CÓDIGO)|-  ");
	}
	break;
	case DataDeNascimento:
	{
		SetConsoleTextAttribute(h, 3);
		printf("\n[3]");
		SetConsoleTextAttribute(h, 7);
		printf("-|DATA DE NASCIMENTO|-  ");
	}
	break;
	case Localidade:
	{
		SetConsoleTextAttribute(h, 3);
		printf("\n[4]");
		SetConsoleTextAttribute(h, 7);
		printf("-|LOCALIDADE DE RESIDÊNCIA|-  ");
	}
	break;

	case EditarClientes:
	{
		SetConsoleTextAttribute(h, 6);
		printf("\n[EDITAR OS UTILIZADORES JÁ CRIADOS]");
		SetConsoleTextAttribute(h, 3);
		printf("\n\n\n[1] -");
		SetConsoleTextAttribute(h, 7);
		printf("-|Alterar o nome do utilizador|\n");
		SetConsoleTextAttribute(h, 3);
		printf("[2] -");
		SetConsoleTextAttribute(h, 7);
		printf("-|Alterar o código de acesso|\n");
		SetConsoleTextAttribute(h, 3);
		printf("[3] -");
		SetConsoleTextAttribute(h, 7);
		printf("-|Alterar a data de nascimento do utilizador|\n");
		SetConsoleTextAttribute(h, 3);
		printf("[4] -");
		SetConsoleTextAttribute(h, 7);
		printf("-|Alterar a localidade de residência do utilizador|\n\n");
	}
	break;
	case Selecao:
	{
		SetConsoleTextAttribute(h, 6);
		printf("\n[INTRODUZA O ALGARISMO REFERENTE À SUA ESCOLHA] - ");
	}
	break;
	case ConsultarCliente:
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
	case Dev:
	{
		SetConsoleTextAttribute(h, 6);
		printf(" ---| Gerar clientes e contas [Dev-Tools] |--- \n\n");
		SetConsoleTextAttribute(h, 3);
		printf("[0] ");
		SetConsoleTextAttribute(h, 7);
		printf("- reset clientes.csv e contas.csv \n");
		SetConsoleTextAttribute(h, 3);
		printf("[1] ");
		SetConsoleTextAttribute(h, 7);
		printf("- 50 clientes e 50 contas \n");
		SetConsoleTextAttribute(h, 3);
		printf("[2] ");
		SetConsoleTextAttribute(h, 7);
		printf("- 500 clientes e 500 contas \n");
		SetConsoleTextAttribute(h, 3);
		printf("[3] ");
		SetConsoleTextAttribute(h, 7);
		printf("- 5.000 clientes e 5.000 contas \n");
		SetConsoleTextAttribute(h, 3);
		printf("[4] ");
		SetConsoleTextAttribute(h, 7);
		printf("- 50.000 clientes e 50.000 contas \n");
		SetConsoleTextAttribute(h, 3);
		printf("[5] ");
		SetConsoleTextAttribute(h, 7);
		printf("- 500.000 clientes e 500.000 contas \n");
		SetConsoleTextAttribute(h, 3);
		printf("[6] ");
		SetConsoleTextAttribute(h, 7);
		printf("- 5.000.000 clientes e 5.000.000 contas \n\n");
		SetConsoleTextAttribute(h, 6);
		printf("\n[INTRODUZA O ALGARISMO REFERENTE À SUA ESCOLHA] - ");

	}
	break;
	case ClienteSemContas:
	{
		SetConsoleTextAttribute(h, 6);
		LOG_WARNING("[NÃO EXISTEM CONTAS ASSOCIADAS A ESTE CLIENTE] ");
	}
	break;
	case IndiqueLocalidade:
		SetConsoleTextAttribute(h, 3);
		printf("\n-|");
		SetConsoleTextAttribute(h, 7);
		printf("Indique uma localidade: ");
		SetConsoleTextAttribute(h, 3);
		printf("|- ");
		SetConsoleTextAttribute(h, 7);
	break;
	case ConsultarConta:
		SetConsoleTextAttribute(h, 6);
		printf("[DEFINIÇÕES DA CONTA]\n");
		SetConsoleTextAttribute(h, 3);
		printf("\n[1] - ");
		SetConsoleTextAttribute(h, 7);
		printf("Consultar a sua posição global do cliente\n");
		SetConsoleTextAttribute(h, 3);
		printf("[2] - ");
		SetConsoleTextAttribute(h, 7);
		printf("Listar Movimentos da conta\n");
		SetConsoleTextAttribute(h, 6);
		printf("\n[INTRODUZA O ALGARISMO REFERENTE À SUA ESCOLHA] - ");
	break;
	case TiposDeContas:
		SetConsoleTextAttribute(h, 6);
		printf("\n[TIPOS DE CONTA]");
		SetConsoleTextAttribute(h, 3);
		printf("\n[1] - ");
		SetConsoleTextAttribute(h, 7);
		printf("Criar conta a Prazo\n");
		SetConsoleTextAttribute(h, 3);
		printf("[2] - ");
		SetConsoleTextAttribute(h, 7);
		printf("Criar conta à Ordem\n");
		break;
	case LocalidadeInvalida:
		SetConsoleTextAttribute(h, 6);
		LOG_WARNING("[Localidade inválida] - (Apenas são permitidas letras e espaços)");
		break;
	case SemClientes:
		SetConsoleTextAttribute(h, 6);
		LOG_WARNING("[NENHUM CLIENTE FOI ENCONTRADO]");
		break;
	case SemContasComSNegativo:
		SetConsoleTextAttribute(h, 6);
		LOG_WARNING("[NÃO EXISTEM CONTAS COM SALDO NEGATIVO]");
		break;
	case SelecioneIDConta:
		SetConsoleTextAttribute(h, 6);
		printf("\n[SELECIONE O ID DA CONTA QUE PRETENDE] - ");
		break;
	case OpcaoInvalida:
		SetConsoleTextAttribute(h, 6);
		LOG_WARNING("[OPÇÃO INVÁLIDA]");
		break;
	case CodigoInvalido:
		SetConsoleTextAttribute(h, 6);
		LOG_WARNING("[CÓDIGO INVÁLIDO] - (Apenas são permitidos [0 -> 6] carateres)");
		break;
	case DataInvalida:
		SetConsoleTextAttribute(h, 6);
		LOG_WARNING("[DATA INVÁLIDA]");
		break;
	case ContaCriadaSucesso:
		SetConsoleTextAttribute(h, 6);
		printf("\n[CONTA CRIADA COM SUCESSO]");
		break;
	case NomeInvalido:
		SetConsoleTextAttribute(h, 6);
		LOG_WARNING("[OPÇÃO INVÁLIDA]");
		break;
	case OperacaoConcluida:
		SetConsoleTextAttribute(h, 6);
		printf("\n[OPERAÇÃO CONCLUÍDA]");
		break;
	case IDInvalido:
		SetConsoleTextAttribute(h, 6);
		printf("\n[O ID ESCOLHIDO NÃO EXISTE]");
		break;
	case SelecioneOpcao:
		printf("\n[SELECIONE UMA OPÇÃO] - ");
		break;
	case SemContas:
		SetConsoleTextAttribute(h, 6);
		LOG_WARNING("[NÃO EXISTEM CONTAS]");
		break;
	case RemoverCliente:
		SetConsoleTextAttribute(h, 6);
		printf("\n[REMOVER CLIENTE]\n");
		break;
	case ClienteRemovidoSucesso:
		SetConsoleTextAttribute(h, 6);
		printf("\n[CLIENTE ELIMINADA COM SUCESSO]\n\
				[PARA APLICAR AS ALTERAÇÕES, SELECIONE O NÚMERO [13] NO MENU INICIAL]");
		break;
	case Montante:
		printf("\n-| [INDIQUE O MONTANTE] - [UTILIZE VIRGULAS PARA DETERMINAS AS CASAS DECIMAIS] |- ");
		break;
	case MontanteInvalido:
		SetConsoleTextAttribute(h, 6);
		LOG_WARNING("[MONTANTE INVÁLIDO]");
		break;
	case SemMovimentos:
		SetConsoleTextAttribute(h, 6);
		LOG_WARNING("[NÃO EXISTEM TRANSAÇÕES ASSOCIADAS A ESTA CONTA]");
		break;
	default:
		SetConsoleTextAttribute(h, 6);
		LOG_WARNING("O ID SELECIONADO NÃO EXISTE");
		break;
	}
	SetConsoleTextAttribute(h, 7);
}
