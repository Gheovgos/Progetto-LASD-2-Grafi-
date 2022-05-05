#include <stdio.h>
#include <stdlib.h>

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
graph *inserisciNodo(graph *G);
void cancellaGrafo(graph *G); //da rivedere la stampa
//fare DFS1 E BFS

graph *creaGrafo(int grandezza) {
	graph *G;
	int i;
	G = (graph*)malloc(sizeof(graph));
	if(G) {
		G->nodi = (lista**)malloc(grandezza*sizeof(lista*));
		if(G->nodi) {
			G->nv = grandezza;
			for(i = 0; i < grandezza; i++) G->nodi[i] = NULL;
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
	if(G) {
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

graph *inserisciNodo(graph *G) {
	lista **e;
	if(G == NULL) {
		graph *g = creaGrafo(1);
		return g;	
	} 
	e = realloc(G->nodi, (G->nv+1)*sizeof(lista*));
	if(e == NULL) printf("\n\nOh no adios\n\n");
	else {
		G->nodi = e;
		G->nodi[G->nv] = NULL;
		G->nv = G->nv+1;
	}
	return G;
}

void cancellaGrafo(graph *G) {
	int i;
	lista *e, *next;
	if(G) {
		if(G->nv > 0) {
			for(i = 0; i < G->nv; i++) {
				e = G->nodi[i];
				while(e != NULL) {
					next = e->next;
					free(e);
					e = next;
				}
			}
			free(G->nodi);
		}
		free(G);
	}
}


int main() {
	graph *G;
	G = creaGrafo(5);
	aggiungiArco(G, 1, 2);
	stampaGrafo(G);
	G = inserisciNodo(G);
	aggiungiArco(G, 3, 5);
	aggiungiArco(G, 3, 4);
	aggiungiArco(G, 3, 2);
	stampaGrafo(G);
	printf("elimino");
	cancellaGrafo(G);
	stampaGrafo(G);
	
}

















