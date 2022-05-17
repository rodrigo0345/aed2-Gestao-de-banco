#include "master.h"
#include "structs.h"
#include "methods.h"

void Menu_MainLoop(Clientes** clts, Contas** cnts, uint* clts_size, uint* cnts_size)
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