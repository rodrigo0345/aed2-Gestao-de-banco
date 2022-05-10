/****************************************************************************
*	Título : AED2 - app - banco®											*
*	Autores : Rodrigo Ralha, Ana Gomes, Inês Marques						*
*																			*
*	Desenvolvido em Windows 10 e Windows 11 na Plataforma : x64				*
*	Notas : Programa escrito principalmente em Português					*
*	O código pode ter problemas de compatibilidade com outros OS			*
*																			*
*	Data : 31 / 03 / 2022  Disciplina : Algoritmos e Estruturas de dados 2	*
*****************************************************************************/

#include "master.h"
#include "structs.h"
#include "methods.h"

/*
	Convencao usada para os metodos:
	Filename_Job_Type(...);
*/
void Main_MainLoop(Clientes**, Contas**, uint*, uint*);

int main(int argc, char* argv[])
{
	/* mostra as mensagens de leaks de memo´ria enquanto o programa esta´ em execucao */
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	/* comandos opcionais acessíveis através do terminal */
	Security_Flags(argv);

	/* clts é a nossa abreviação de clientes */
	Clientes* clts = NULL;

	/* cnts é a nossa abreviação de contas */
	Contas* cnts = NULL;

	/* guarda o numero de elementos em clts */
	uint clts_size = 0;

	/* guarda o numero de elementos em cnts */
	uint cnts_size = 0;

	Files_LoadMemory(&clts, &cnts, &clts_size, &cnts_size);

	/* main loop do programa */
	Main_MainLoop(&clts, &cnts, &clts_size, &cnts_size);

	system("cls");
	system("pause");

	Files_SaveMemory(&clts, &cnts);

	Security_ProgramExit_Global(clts, cnts);
}
void Main_MainLoop(Clientes** clts, Contas** cnts, uint* clts_size, uint* cnts_size)
{
	setlocale(LC_ALL, "portuguese");
	
	uint opcao = 0;
	introducao();
	do
	{
		system("cls");

		/* menu principal */
		dialogo(MenuInicial);

		/* string auxiliar */
		char str[50];

		Security_Input_Int(str, &opcao);

		/* melhor técnica que encontramos para poupar if statements */
		void (*menu[13])(Clientes**, Contas**, uint*, uint*) = {
				Criar_Clientes, Editar_Clientes,
				Consultar_Clientes ,Remover_Clientes,
				Listar_Clientes, Criar_Contas,
				Editar_Contas, Consultar_Contas ,
				Remover_Contas, Listar_Contas,
				Operacoes_Depositar, Operacoes_Levantar };

		if (Security_Validation_UInt(opcao, 12))
		{
			system("cls");
			menu[opcao - 1](clts, cnts, clts_size, cnts_size);
		}
	} while (opcao != 13);
}
