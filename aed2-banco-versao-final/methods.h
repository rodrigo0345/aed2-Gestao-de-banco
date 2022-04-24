#pragma once
#include "structs.h"

/* clientes */
void* Criar_Clientes(Clientes** clts, Contas** cnts, uint* clts_size, uint* cnts_size);
void* Editar_Clientes(Clientes** clts, Contas** cnts, uint* clts_size, uint* cnts_size);
void* Listar_Clientes(Clientes** clts, Contas** cnts, uint* clts_size, uint* cnts_size);
void* Consultar_Clientes(Clientes** clts, Contas** cnts, uint* clts_size, uint* cnts_size);
void* Remover_Clientes(Clientes** clts, Contas** cnts, uint* clts_size, uint* cnts_size);

/* contas */
void* Criar_Contas(Clientes** clts, Contas** cnts, uint* clts_size, uint* cnts_size);
void* Editar_Contas(Clientes** clts, Contas** cnts, uint* clts_size, uint* cnts_size);
void* Listar_Contas(Clientes** clts, Contas** cnts, uint* clts_size, uint* cnts_size);
void* Remover_Contas(Clientes** clts, Contas** cnts, uint* clts_size, uint* cnts_size);
void* Consultar_Contas(Clientes** clts, Contas** cnts, uint* clts_size, uint* cnts_size);

/* operacoes */
void* Operacoes_Depositar(Clientes** clts, Contas** cnts, uint* clts_size, uint* cnts_size);
void* Operacoes_Levantar(Clientes** clts, Contas** cnts, uint* clts_size, uint* cnts_size);