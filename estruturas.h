#ifndef estruturas.h
#define estruturas.h

typedef struct {
    int x, y;
} Position;

typedef struct No {
    Position dados
    struct Node* pontproxno;
} Node;

typedef struct {
    Node* topo;
} Stack;

typedef struct {
    Node* inicio;
    Node* fim;
} Queue;

void initStack(Stack* s);
void push(Stack* s, Position p);
Position pop(Stack* s);

void initQueue(Queue* q);
void enqueue(Queue* q, Position p);
Position dequeue(Queue* q);

#endif
