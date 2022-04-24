#pragma once

typedef unsigned int uint;

/* --- Principais structs do programa ---*/

/* S�o ambas listas-ligadas duplas pois s�o mais eficientes na altura de remover "nodes" */
typedef struct Cliente {
	uint id;

	char* pin;
	char* nome;
	char* data;
	char* morada;
	char* contas_associadas;
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
	char* livro_razao;

	struct Conta* next;
	struct Conta* prev;
} Contas;