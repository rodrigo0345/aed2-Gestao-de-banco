#include "master.h"
#include "structs.h"

/* Carrega as listas ligadas usadas ao longo do programa recorrendo a ficheiros .csv */
void Files_LoadMemory(Clientes** clts, Contas** cnts, uint* clts_size, uint* cnts_size)
{
	FILE* ficheiro = fopen("clientes.csv", "r");
	if (ficheiro == NULL)
		Security_Error("files.c//Files_LoadMemory//clientes");

	char line[150];
	int i = 0;
	char* key;
	Clientes* tmp = LinkedList_New_Clientes();

	fgets(line, 150, ficheiro);
	while (fgets(line, 150, ficheiro) != NULL && strcmp(line, "\n"))
	{
		key = strtok(line, ",");
		tmp->id = atoi(key);

		key = strtok(NULL, ",");
		tmp->pin = malloc(sizeof(char) * 8);
		if (tmp->pin == NULL)
			Security_Error("files.c//Files_LoadMemory//tmp->pin");
		strcat(key, "\0");
		strcpy(tmp->pin, key);

		key = strtok(NULL, ",");
		tmp->nome = malloc(sizeof(char) * 60);
		if (tmp->nome == NULL)
			Security_Error("files.c//Files_LoadMemory//tmp->nome");
		strcat(key, "\0");
		strcpy(tmp->nome, key);

		key = strtok(NULL, ",");
		tmp->data = malloc(sizeof(char) * 15);
		if (tmp->data == NULL)
			Security_Error("files.c//Files_LoadMemory//tmp->data");
		strcat(key, "\0");
		strcpy(tmp->data, key);

		key = strtok(NULL, ",");
		tmp->morada = malloc(sizeof(char) * 60);
		if (tmp->morada == NULL)
			Security_Error("files.c//Files_LoadMemory//tmp->morada");
		strcat(key, "\0");
		strcpy(tmp->morada, key);

		key = strtok(NULL, ",");
		tmp->saldo_global = atoi(key);

		key = strtok(NULL, ",");
		tmp->contas_associadas = malloc(sizeof(char) * 60);
		if (tmp->contas_associadas == NULL)
			Security_Error("files.c//Files_LoadMemory//tmp->contas_associadas");
		strcat(key, "\0");
		if (atoi(key) == 0) tmp->contas_associadas = NULL;
		else
			strcpy(tmp->contas_associadas, key);

		(*clts_size)++;
		LinkedList_AppendHead_Clientes(clts, *tmp);
	}
	free(tmp);

	FILE* ficheiro2 = fopen("contas.csv", "r");
	if (ficheiro2 == NULL)
		Security_Error("files.c//Files_LoadMemory//ficheiro");

	Contas* tmp2 = LinkedList_New_Contas();
	uint prev_id = 0;

	fgets(line, 150, ficheiro2);
	while (fgets(line, 150, ficheiro2) != NULL)
	{
		key = strtok(line, ",");
		tmp2->id = atoi(key);

		key = strtok(NULL, ",");
		tmp2->id_owner = atoi(key);

		key = strtok(NULL, ",");
		tmp2->tipo = atoi(key);

		key = strtok(NULL, ",");
		tmp2->saldo = atoi(key);

		key = strtok(NULL, ",");
		tmp2->livro_razao = malloc(sizeof(char) * 8);
		if (tmp2->livro_razao == NULL)
			Security_Error("files.c//Files_LoadMemory//tmp2->livro_razao");
		strcat(key, "\0");
		strcpy(tmp2->livro_razao, key);

		(*cnts_size)++;
		LinkedList_AppendHead_Contas(cnts, *tmp2);
	}
	free(tmp2);

	fclose(ficheiro2);
	fclose(ficheiro);
}

