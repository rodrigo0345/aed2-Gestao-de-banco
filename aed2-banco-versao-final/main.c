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
	/* _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF); */

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

	/* loop principal do programa */
	Menu_MainLoop(&clts, &cnts, &clts_size, &cnts_size);

	system("cls");
	system("pause");

	Files_SaveMemory(&clts, &cnts);

	Security_ProgramExit_Global(clts, cnts);
}
