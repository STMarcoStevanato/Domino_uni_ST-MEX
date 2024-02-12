#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdio.h>
#include <time.h>
#include "tessera.h"
#include "lista.h"

void inizializza(Lista_doppia* ptr) {
    Nodo* nuovoNodo = malloc(sizeof(Nodo));
    if (nuovoNodo == NULL) {
        fprintf(stderr, "ERROR MEMORY ALLOCATION");
        exit(EXIT_FAILURE);
    }
    nuovoNodo->valore = malloc(sizeof(Tessera));
    if (nuovoNodo->valore == NULL) {
        fprintf(stderr, "ERROR MEMORY ALLOCATION");
        exit(EXIT_FAILURE);
    }
    set_tessera_random(nuovoNodo->valore);
    nuovoNodo->prossimo = NULL;
    nuovoNodo->previo = NULL;
    ptr->testa = nuovoNodo;
    ptr->coda = nuovoNodo;
}

void stampa_lista(Lista_doppia* ptr) {
    if (ptr == NULL || ptr->testa == NULL) {
        fprintf(stderr, "CANNOT PRINT, BECAUSE LIST IS EMPTY");
        exit(EXIT_FAILURE);
    }
    Nodo* corrente = ptr->testa;
    while (corrente != NULL) {
        stampa_tessera(corrente->valore);
        corrente = corrente->prossimo;
    }
}

void push_front(Lista_doppia* ptr) {
    if (ptr->testa == NULL) {
        inizializza(ptr);
    }
    else {
        Nodo* nuovoNodo = malloc(sizeof(Nodo));
        if (nuovoNodo == NULL) {
            fprintf(stderr, "ERROR MEMORY ALLOCATION");
            exit(EXIT_FAILURE);
        }
        nuovoNodo->valore = malloc(sizeof(Tessera));
        if (nuovoNodo->valore == NULL) {
            fprintf(stderr, "ERROR MEMORY ALLOCATION");
            exit(EXIT_FAILURE);
        }
        set_tessera_random(nuovoNodo->valore);
        nuovoNodo->prossimo = ptr->testa;
        nuovoNodo->previo = NULL;
        ptr->testa->previo = nuovoNodo;
        ptr->testa = nuovoNodo;
    }
}

void push_back(Lista_doppia* ptr) {
    if (ptr->testa == NULL) {
        inizializza(ptr);
    }
    else {
        Nodo* nuovoNodo = malloc(sizeof(Nodo));
        if (nuovoNodo == NULL) {
            fprintf(stderr, "ERROR MEMORY ALLOCATION");
            exit(EXIT_FAILURE);
        }
        nuovoNodo->valore = malloc(sizeof(Tessera));
        if (nuovoNodo->valore == NULL) {
            fprintf(stderr, "ERROR MEMORY ALLOCATION");
            exit(EXIT_FAILURE);
        }
        set_tessera_random(nuovoNodo->valore);
        nuovoNodo->prossimo = NULL;
        nuovoNodo->previo = ptr->coda;
        ptr->coda->prossimo = nuovoNodo;
        ptr->coda = nuovoNodo;
    }
}

void free_lista(Lista_doppia* ptr) {
    if (ptr == NULL || ptr->testa == NULL) {
        fprintf(stderr, "CANNOT FREE, BECAUSE LIST IS ALREADY EMPTY");
        exit(EXIT_FAILURE);
    }
    Nodo* a = ptr->testa;
    Nodo* b = NULL;

    while (a) {
        b = a;
        a = a->prossimo;
        free(b->valore);
        free(b);
    }
    ptr->testa = NULL;
    ptr->coda = NULL;
}


// cancellazione di tessera tramite indice e poi return di nodo in indice cancellato
Nodo* pop_casuale(Lista_doppia* ptr, int i) {
    Nodo* a = ptr->testa->prossimo;
    Nodo* corrente = ptr->testa;
    Nodo* b = NULL;

    while(i -1) {
        b = corrente;
        corrente = corrente->prossimo;
        a = corrente->prossimo;
        i--;
    }
    b->prossimo = a;
    a->previo = b;
    return corrente;
}

void crea_lista(int n, Lista_doppia* a) {
    a->testa = NULL;
    a->coda = NULL;
    inizializza(a);
    for (int i = 1; i<n; i++) push_back(a);
}