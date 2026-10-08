#include "estruturas.h"
#include <stdlib.h>

void initStack(Stack* s) { 
    s->topo = NULL; 
}

void push(Stack* s, Position p) {
    No* NovoNo = (No*)malloc(sizeof(No)); 
    NovoNo->dados = p;
    NovoNo->pontproxno = s->topo;
    s->topo = NovoNo;
}

Position pop(Stack* s) {
    Position p = s->topo->dados;
    No* NoTemp = s->topo; 
    s->topo = s->topo->pontproxno;
    free(NoTemp);
    return p;
}

int isStackEmpty(Stack* s) { 
    return s->topo == NULL; 
}

void initQueue(Queue* q) { 
    q->inicio = NULL; 
    q->fim = NULL; 
}

void enqueue(Queue* q, Position p) {
    No* NovoNo = (No*)malloc(sizeof(No));
    NovoNo->dados = p;
    NovoNo->pontproxno = NULL;
    if (q->fim) {
        q->fim->pontproxno = NovoNo;
        q->fim = NovoNo;
    } else {
        q->inicio = q->fim = NovoNo;
    }
}

Position dequeue(Queue* q) {
    Position p = q->inicio->dados;
    No* NoTemp = q->inicio;
    q->inicio = q->inicio->pontproxno;
    if (!q->inicio) q->fim = NULL;
    free(NoTemp);
    return p;
}

int isQueueEmpty(Queue* q) { 
    return q->inicio == NULL; 
}
