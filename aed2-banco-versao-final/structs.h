#pragma once

typedef unsigned int uint;

/* --- Principais structs do programa ---*/

/* stack */
typedef struct movimento
{
	uint id_conta;
	double montante;
	char* tipo;
	char* data;

	struct movimento* next;
} Movimentos;

/* São ambas listas-ligadas duplas pois são mais eficientes na altura de remover "nodes" */
typedef struct Cliente {
	uint id;

	char* pin;
	char* nome;
	char* data;
	char* morada;
	char* contas_associadas; /* 70 carateres */
	double saldo_global;

	struct Cliente* next;
	struct Cliente* prev;
} Clientes;

typedef struct Conta {
	uint id;
	uint id_owner;

	/* 0 = Ordem, 1 = Prazo */
	short tipo;
	double saldo;

	/* apontador para o topo da stack dos movimentos */
	Movimentos* movimentos;

	struct Conta* next;
	struct Conta* prev;
} Contas;