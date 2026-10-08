#ifndef estruturas_h
#define estruturas_h

typedef struct {
    int x, y;
} Position;

typedef struct No {
    Position dados;
    struct No* pontproxno;
} No;

typedef struct {
    No* topo;
} Stack;

typedef struct {
    No* inicio;
    No* fim;
} Queue;

void initStack(Stack* s);
void push(Stack* s, Position p);
Position pop(Stack* s);
int isStackEmpty(Stack* s); 

void initQueue(Queue* q);
void enqueue(Queue* q, Position p);
Position dequeue(Queue* q);
int isQueueEmpty(Queue* q); 

#endif
