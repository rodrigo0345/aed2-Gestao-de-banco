#include "master.h"
#include "structs.h"

/* Carrega as listas ligadas usadas ao longo do programa recorrendo a ficheiros .csv */
void Files_LoadMemory(Clientes** clts, Contas** cnts, uint* clts_size, uint* cnts_size)
{
	/* abrir o ficheiro */
	FILE* ficheiro = fopen("clientes.csv", "r");
	if (ficheiro == NULL)
		Security_Error(__FILE__, __LINE__);

	char line[250] = "";
	int i = 0;
	char* key;
	Clientes* tmp = LinkedList_New_Clientes();

	/* recolher o cabecalho do ficheiro .csv */
	fgets(line, 250, ficheiro);

	/* guardar as informacoes do ficheiro clientes.csv na struct "tmp" */
	while (fgets(line, 200, ficheiro) != NULL && strcmp(line, "\n"))
	{
		key = strtok(line, ";");
		tmp->id = atoi(key);

		key = strtok(NULL, ";");
		tmp->pin = malloc(sizeof(char) * 8);
		if (tmp->pin == NULL)
			Security_Error(__FILE__, __LINE__);
		strcat(key, "\0");
		strcpy(tmp->pin, key);

		key = strtok(NULL, ";");
		tmp->nome = malloc(sizeof(char) * 60);
		if (tmp->nome == NULL)
			Security_Error(__FILE__, __LINE__);
		strcat(key, "\0");
		strcpy(tmp->nome, key);

		key = strtok(NULL, ";");
		tmp->data = malloc(sizeof(char) * 15);
		if (tmp->data == NULL)
			Security_Error(__FILE__, __LINE__);
		strcat(key, "\0");
		strcpy(tmp->data, key);

		key = strtok(NULL, ";");
		tmp->morada = malloc(sizeof(char) * 60);
		if (tmp->morada == NULL)
			Security_Error(__FILE__, __LINE__);
		strcat(key, "\0");
		strcpy(tmp->morada, key);

		key = strtok(NULL, ";");
		Security_Replace_Char(key, ',', '.');
		tmp->saldo_global = atof(key);

		key = strtok(NULL, ";");
		tmp->contas_associadas = malloc(sizeof(char) * 70);
		if (tmp->contas_associadas == NULL)
			Security_Error(__FILE__, __LINE__);
		if (atoi(key) == 0) tmp->contas_associadas = NULL;
		else
		{
			key[strlen(key) - 1] = '\0';  /* retira o \n do final da string para facilitar a manipulação de dados */
			strcpy(tmp->contas_associadas, key);
		}
			

		(*clts_size)++;
		LinkedList_AppendHead_Clientes(clts, *tmp);
	}

	fclose(ficheiro);

	/* abrir o ficheiro contas.csv */
	FILE* ficheiro2 = fopen("contas.csv", "r");
	if (ficheiro2 == NULL)
		Security_Error(__FILE__, __LINE__);

	Contas* tmp2 = LinkedList_New_Contas();
	uint prev_id = 0;

	fgets(line, 250, ficheiro2);

	/* guardar as informacoes do ficheiro contas.csv na struct "tmp" */
	while (fgets(line, 200, ficheiro2) != NULL && strcmp(line, "\n"))
	{
		key = strtok(line, ";");

		tmp2->movimentos = NULL;
		tmp2->id = atoi(key);

		key = strtok(NULL, ";");
		tmp2->id_owner = atoi(key);

		key = strtok(NULL, ";");
		tmp2->tipo = atoi(key);

		key = strtok(NULL, ";");
		/* troca a virgula por um ponto de forma a conseguir fazer a conversa~o de string para float */
		Security_Replace_Char(key, ',', '.');
		tmp2->saldo = atof(key);

		(*cnts_size)++;
		LinkedList_AppendHead_Contas(cnts, *tmp2);
	}

	fclose(ficheiro2);

	/* abrir o ficheiro contas.csv */
	FILE* ficheiro3 = fopen("Movimentos.csv", "r");
	if (ficheiro2 == NULL)
		Security_Error(__FILE__, __LINE__);

	/* recolher o cabecalho do Movimentos.csv */
	fgets(line, 250, ficheiro3);

	/* guardar as informacoes do ficheiro Movimentos.csv na struct das contas recorrendo à stack movimentos */
	/* sem duvida, o metodo mais lento do programa */
	while (fgets(line, 200, ficheiro3) != NULL && strcmp(line, "\n"))
	{
		/* id (pesquisa pela conta com o id fornecido)*/
		key = strtok(line, ";");
		uint id = atoi(key);

		Contas* aux = LinkedList_BinarySearch_Contas(*cnts, id);

		if (aux == NULL)
		{
			continue;
		}

		Movimentos* tmp = Stack_Create_Movimentos(id);
	
		/* tipo de movimento (credito ou debito)*/
		key = strtok(NULL, ";");
		tmp->tipo = (char*)malloc(sizeof(char) * 60);
		if (tmp->tipo == NULL)
			Security_Error(__FILE__, __LINE__);
		strcat(key, "\0");
		strcpy(tmp->tipo, key);

		/* montante */
		key = strtok(NULL, ";");
		Security_Replace_Char(key, ',', '.');
		tmp->montante = atof(key);

		/* data */
		key = strtok(NULL, ";");
		tmp->data = (char*)malloc(sizeof(char) * 60);
		if (tmp->data == NULL)
			Security_Error(__FILE__, __LINE__);
		key[strlen(key) - 1] = '\0';
		strcpy(tmp->data, key);

		Stack_Push_Movimentos(&(aux->movimentos), tmp);
	}

	fclose(ficheiro3);
}

void Files_SaveMemory(Clientes** clts, Contas** cnts)
{
	/* temos de trocar a ordem das listas ligadas antes de as guardar */
	LinkedList_Reverse_Cliente(clts);
	LinkedList_Reverse_Conta(cnts);

	FILE* clientes = fopen("clientes.csv", "w");
	if(clientes==NULL)
		Security_Error(__FILE__, __LINE__);

	//id,palavra-passe,nome,data de nascimento,morada,saldo global,contas
	Clientes* curr;

	fprintf(clientes, "%s\n", "id;palavra-passe;nome;data de nascimento;morada;saldo global;contas");

	for (curr = *clts; curr != NULL; curr = curr->next)
	{
		fprintf(clientes, "%d;%s;%s;%s;%s;%.2lf;%s\n", curr->id, curr->pin, curr->nome, 
												curr->data, curr->morada, curr->saldo_global, 
												curr->contas_associadas);
	}
	fclose(clientes);

	FILE* as_contas = fopen("contas.csv", "w");
	FILE* os_movimentos = fopen("movimentos.csv", "w");

	fprintf(as_contas, "%s\n", "ID;Id do proprietário;ordem ou prazo;saldo;livro-razão");

	Contas* tmp;
	for (tmp = *cnts; tmp != NULL; tmp = tmp->next)
	{

		fprintf(as_contas, "%d;%d;%d;%.2lf\n", tmp->id, tmp->id_owner, tmp->tipo, tmp->saldo);
	}
	fclose(as_contas);
	fclose(os_movimentos);
}

