#include "master.h"
#include "structs.h"
#include <stdlib.h>

/* Inicializa e Retorna uma struct do tipo Clientes* */
Clientes* LinkedList_New_Clientes()
{
	Clientes* tmp = malloc(sizeof(Clientes));
	if (tmp == NULL) Security_Error(__FILE__, __LINE__);

	/* informacoes padrao que precisam de ser NULL */
	tmp->next = NULL;
	tmp->prev = NULL;
	tmp->contas_associadas = NULL;

	return tmp;
}

/* Inicializa e Retorna uma struct do tipo Contas* */
Contas* LinkedList_New_Contas()
{
	Contas* tmp = (Contas*)malloc(sizeof(Contas));
	if (tmp == NULL) Security_Error(__FILE__, __LINE__);

	/* informacoes padrao que precisam de ser NULL */
	tmp->next = NULL;
	tmp->prev = NULL;

	return tmp;
}

/* Adiciona uma struct à "head" da lista-ligada (tipo: Clientes) */
void LinkedList_AppendHead_Clientes(Clientes** lista, Clientes elemento)
{
	Clientes* new_node = (Clientes*)malloc(sizeof(Clientes));
	if (new_node == NULL) Security_Error(__FILE__, __LINE__);

	if (*lista == NULL)
	{
		*new_node = elemento;
	}
	else
	{
		*new_node = elemento;
		new_node->next = *lista;

		(*lista)->prev = new_node;
	}
	(*lista) = new_node;
}

/* Adiciona uma struct à "head" da lista-ligada (tipo: Contas) */
void LinkedList_AppendHead_Contas(Contas** lista, Contas elemento)
{
	Contas* new_node = (Contas*)malloc(sizeof(Contas));
	if (new_node == NULL) Security_Error(__FILE__, __LINE__);

	if (*lista == NULL)
	{
		*new_node = elemento;
	}
	else
	{
		*new_node = elemento;
		new_node->next = *lista;

		(*lista)->prev = new_node;
	}
	(*lista) = new_node;
}

/* Retira uma "node" de uma dada lista-ligada (tipo: Clientes) */
uint LinkedList_RemoveNode_Clientes(Clientes** lista, Contas** cnts, uint id)
{
	Clientes* aux = LinkedList_BinarySearch_Clientes(*lista, id);

	if (aux == NULL) return 0;

	if (aux->prev != NULL)
	{
		aux->prev->next = aux->next;
	}
	else /* estamos a tratar da cabeça da linked list */
	{
		*lista = aux->next;
	}

	if (aux->next != NULL)
	{
		aux->next->prev = aux->prev;
	}
	
	/* apaga todas as contas associadas ao cliente */
	LinkedList_RemCAC_Clientes(aux, cnts);
	
	free(aux);

	return 1;
}

/* Retira uma "node" de uma dada lista-ligada (tipo: Contas) */
uint LinkedList_RemoveNode_Contas(Contas** lista, uint id)
{
	Contas* aux = LinkedList_BinarySearch_Contas(*lista, id);

	if (aux == NULL) return 0;

	if (aux->prev != NULL)
	{
		aux->prev->next = aux->next;
	}
	else /* estamos a tratar da cabeça da linked list */
	{
		*lista = aux->next;
	}

	if (aux->next != NULL)
	{
		aux->next->prev = aux->prev;
	}
	
	free(aux);
	return 1;
}

/* Função apenas acessada pela LinkedList_BinarySearch_Clientes(...) */
static Clientes* LinkedList_FindMiddleNode_Clientes(Clientes* start, Clientes* end)
{

	if (start == NULL)
		return NULL;

	/*define two pointers: slow and fast*/
	Clientes* slow = start;
	Clientes* fast = start->next;

	while (fast != end)
	{
		fast = fast->next;
		if (fast != end)
		{
			slow = slow->next;
			fast = fast->next;
		}
	}

	return slow;
}

/* Função apenas acessada pela LinkedList_BinarySearch_Contas(...) */
static Contas* LinkedList_FindMiddleNode_Contas(Contas* start, Contas* end)
{
	if (start == NULL)
		return NULL;

	/*define two pointers: slow and fast*/
	Contas* slow = start;
	Contas* fast = start->next;

	while (fast != end)
	{
		fast = fast->next;
		if (fast != end)
		{
			slow = slow->next;
			fast = fast->next;
		}
	}

	return slow;
}

/* Retorna a "node" com id igual ao argumento passado recorrendo a pesquisa bina´ria (tipo: Clientes) */
Clientes* LinkedList_BinarySearch_Clientes(Clientes* listHead, uint id)
{
	Clientes* start = listHead;
	Clientes* end = NULL;

	do
	{
		Clientes* mid = LinkedList_FindMiddleNode_Clientes(start, end);

		if (mid == NULL)
			return NULL;

		if (mid->id == id)
			return mid;

		else if (mid->id > id)
			start = mid->next;

		else
			end = mid;

	} while (end == NULL ||
		end != start);

	return NULL;
}

/* Retorna a "node" com id igual ao argumento passado recorrendo a pesquisa bina´ria (tipo: Contas) */
Contas* LinkedList_BinarySearch_Contas(Contas* listHead, uint id)
{
	Contas* start = listHead;
	Contas* end = NULL;

	do
	{
		Contas* mid = LinkedList_FindMiddleNode_Contas(start, end);

		if (mid == NULL)
			return NULL;

		if (mid->id == id)
			return mid;

		else if (mid->id > id)
			start = mid->next;

		else
			end = mid;

	} while (end == NULL ||
		end != start);

	return NULL;
}

/* Liberta completamente a memória alocada para uma lista ligada (tipo: Clientes) */
void LinkedList_Delete_Clientes(Clientes** head_ref)
{
	Clientes* current = *head_ref;
	Clientes* next;

	while (current != NULL)
	{
		next = current->next;

		if (current->contas_associadas) /* contas_associadas tanto pode ter espaço alocado como não */
			free(current->contas_associadas);

		free(current->data); /* temos aqui um erro */
		free(current->morada);
		free(current->nome);
		free(current->pin);

		free(current);
		current = next;
	}

	*head_ref = NULL;
}

/* Apaga completamente a memória alocada para uma lista ligada (tipo: Contas) */
void LinkedList_Delete_Contas(Contas** head_ref)
{
	/* deref head_ref to get the real head */
	Contas* current = *head_ref;
	Contas* next;

	while (current != NULL)
	{
		next = current->next;

		if (current->livro_razao)  /* livro_razao tanto pode ter espaço alocado como não */
			free((char*)current->livro_razao);
		
		free(current);
		current = next;
	}

	/* deref head_ref to affect the real head back
	   in the caller. */
	*head_ref = NULL;
}

/* usado antes de guardar as listas ligadas nos ficheiros .csv */
void LinkedList_Reverse_Cliente(Clientes** head_ref)
{
	Clientes* prev = NULL;
	Clientes* current = *head_ref;
	Clientes* next = NULL;
	while (current != NULL) {
		// Store next
		next = current->next;

		// Reverse current node's pointer
		current->next = prev;

		// Move pointers one position ahead.
		prev = current;
		current = next;
	}
	*head_ref = prev;
}

/* usado antes de guardar as listas ligadas nos ficheiros .csv */
void LinkedList_Reverse_Conta(Contas** head_ref)
{
	Contas* prev = NULL;
	Contas* current = *head_ref;
	Contas* next = NULL;
	while (current != NULL) {
		// Store next
		next = current->next;

		// Reverse current node's pointer
		current->next = prev;

		// Move pointers one position ahead.
		prev = current;
		current = next;
	}
	*head_ref = prev;
}

/* Apaga todas as contas associadas a um certo cliente (CAC = Contas Associadas ao Cliente)*/
void LinkedList_RemCAC_Clientes(Clientes* cliente_removido, Contas** cnts)
{
	if (cliente_removido->contas_associadas == NULL)
	{
		return;
	}

	char* key = strtok(cliente_removido->contas_associadas, "/");
	while (key != NULL)
	{
		int id = atoi(key);
		LinkedList_RemoveNode_Contas(cnts, id);

		key = strtok(NULL, "/");
	}
}

/* Mostra todas as contas associadas a um dado cliente */
uint LinkedList_ShowContas_Clientes(Clientes* cliente, Contas** cnts)
{
	if (cliente->contas_associadas == NULL)
	{
		dialogo(15);
		int check = getchar();
		return 0;
	}

	/* temos de fazer isto senão as contas associadas tem um bug a depositar,
		mais especificamente, as contas_associadas resetam sempre que criarmos mais uma conta
		(no mesmo cliente) ao depositarmos.													*/
	char* aux = malloc(sizeof(cliente->contas_associadas));
	strcpy(aux, cliente->contas_associadas);

	char* key = strtok(aux, "/");
	while (key != NULL)
	{
		uint id = atoi(key);

		/*  tmp pode ser NULL porque sempre que apagamos uma conta,
			não apagamos o seu registo do cliente					*/
		Contas* tmp = LinkedList_BinarySearch_Contas(*cnts, id);

		if (tmp == NULL)
		{
			key = strtok(NULL, "/");
			continue;
		}

		if (tmp->tipo == 1)
		{
			printf("ID[%u]\tSaldo[%.2lf]\tTipo[%s]\n", id, tmp->saldo, "Prazo");
		}
		else
		{
			printf("ID[%u]\tsaldo[%.2lf]\ttipo[%s]\n", id, tmp->saldo, "Ordem");
		}

		key = strtok(NULL, "/");
	}
	return 1;
}

uint LinkedList_RemoveAlreadyKnownNode_Contas(Contas** lista, Contas** known_node)
{
	Contas* aux = *known_node;

	if (aux == NULL) return 0;

	if (aux->prev != NULL)
	{
		aux->prev->next = aux->next;
	}
	else /* estamos a tratar da cabeça da linked list */
	{
		*lista = aux->next;
	}

	if (aux->next != NULL)
	{
		aux->next->prev = aux->prev;
	}
	return 1;
}
