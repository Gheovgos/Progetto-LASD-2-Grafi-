#include <stdio.h>

//dato un grafo verificare se ci sono cicli

typedef struct list {
	int key;
	struct list *next;
}lista;

typedef struct grafo {
	int nv;
	lista **nodi;
}graph;
graph *creaGrafo(int grandezza); 
void inizializzaNull(graph G); 
int isEmpty(graph *G);
void stampaGrafo(graph *G);
void aggiungiArco(graph *G, int u, int v);
void rimuoviArco(graph *G, int u, int v);

graph *creaGrafo(int grandezza) {
	graph *G, int i;
	G = (graph*)malloc(sizeof(graph));
	if(G) {
		G->nodi = (lista**)malloc(grandezza*sizeof(lista*));
		if(G->nodi) {
			G->nv = grandezza;
			for(i = 0; i < n; i++) G->nodi[i] = NULL;
		}
		else {
			printf("\n\nOh no adios\n\n");
			free(G);
			G = NULL;
		}
	}
	else {
		printf("\n\nOh no adios\n\n");
	}
	
	return G;
}

int isEmpty(graph *G) {
	return G==NULL;
}

void stampaGrafo(graph *G) {
	
	int i = 0, ne = 0;
	lista *e;
	if(!isEmpty(G)) {
		printf("\nIl grafo ha %d vertici\n", G->nv);
		for(i = 0; i < G->nv; i++) {
			printf("nodi adiacenti al nodo %d - > ", i);
			e = G->nodi[i];
			while(e!=NULL) {
				printf("%d ", e->key);
				ne++;
				e = e->next;
			}
			printf("\n");
		}
		printf("Il grafo ha %d archi \n", ne);
	}
}

void aggiungiArco(graph *G, int u, int v) {
	if(G) {
		if(u >= 0 && u < G->nv && v >= 0 && v < G->nv) {
			lista *new, *e;
			//u e v vertici del grafo compresi fra 0 e G->nv -1, l'arco u v non è già presente nel grafo
			new = (lista*)malloc(sizeof(lista));
			if(new) {
				new->key = v;
				new->next = NULL;
			if(G->nodi[u] == NULL) G->nodi[u] = new;
			else {
				e = G->nodi[u];
				while(e->next!=NULL) e = e->next;
			
				e->next=new;
			}
	    	}	
    	}	
	}
}

void rimuoviArco(graph *G, int u, int v) {
	lista *prev, *e;
	e = G->nodi[u];
	if(e->key == v) G->nodi[u] = e->next;
	else {
		prev = e;
		while(prev->next->key != v) prev = prev->next;
		e = prev->next;
		prev->next = e->next;
	}
	free(e);
}




















